#include "KVTranslator.h"
#include "KVUtil.h"

KVTranslator::KVTranslator(QObject *parent):
	QObject(parent)
{
	
}

KVTranslator::~KVTranslator()
{
	
}

void KVTranslator::addTranslation(const QString &from, const QString &to)
{
	QByteArray fromBytes = from.toUtf8();
	this->addTranslation(crc32(0, fromBytes.data(), fromBytes.size()), to);
}

void KVTranslator::addTranslation(quint32 from, const QString &to)
{
	dictionary.insert(from, to);
}

QString KVTranslator::translate(const QString &phrase) const
{
	if (!this->isTranslatable(phrase)) {
		return phrase;
	}
	
	QString real = unescape(phrase);
	QByteArray realBytes = real.toUtf8();
	quint32 crc = crc32(0, realBytes.data(), realBytes.size());
	
	const QString &translation = dictionary.value(crc);
	return !translation.isEmpty() ? translation : phrase;
}

bool KVTranslator::isTranslatable(const QString &phrase) const
{
	// Some special exceptions...
	static QList<QString> exceptions { "", "-" };
	if(exceptions.contains(phrase)) {
		return false;
	}
	
	// Numeric strings aren't translatable
	bool isNumeric;
	phrase.toFloat(&isNumeric);
	if(isNumeric) {
		return false;
	}
	
	return true;
}
