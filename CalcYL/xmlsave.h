#ifndef XMLSAVE_H
#define XMLSAVE_H
#include <QXmlStreamWriter>  
#include <QXmlStreamReader>  
#include<qtextcodec.h>
#include <QFile>  
#include <QMessageBox>  
#include <QObject>
#include <qdebug.h>
#include <qfile.h>
typedef struct QusSave {
	QStringList Test;	//试题
	QStringList TruAns;	//正确答案
	QStringList MAns;	//我的答案
	int PastTime;		//用时
	int Scoe;			//得分
}QusSave;
class XmlSave : public QObject
{
	Q_OBJECT
public:
	XmlSave();
	~XmlSave();
	int writeXml(QList <QusSave> );
	int readXml(QList <QusSave> &x);
private:
	void parseUserInformation();
	QString getValue(const QString &name);
	QString getAttribute(const QString &name);
	QString Temp;
	
};

#endif // XMLSAVE_H
