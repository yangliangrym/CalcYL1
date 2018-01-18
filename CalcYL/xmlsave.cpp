#include "xmlsave.h"

XmlSave::XmlSave()
{

}

XmlSave::~XmlSave()
{
	
}

int XmlSave::writeXml(QList <QusSave> Save)
{
	QFile File("./PointTestSave.txt");
	if (File.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate)) {
		QTextStream stream(&File);
		stream <<"SaveCount:" << Save.count() << endl;					//输入次数
			for (int i = 0;i < Save.count();i++)
		{
				stream <<"TestCount:"<< Save.at(i).Test.count() << endl;//输入个数
			for (int j = 0;j <Save.at(i).Test.count();j++)
			{
				stream <<"Test:"	<< Save.at(i).Test.at(j) << endl;	//输入题目
				stream <<"TruAns:"	<< Save.at(i).TruAns.at(j) << endl;	//输入正确答案
				stream <<"MAns:"	<< Save.at(i).MAns.at(j) << endl;	//输入我的答案
			}
			stream << "PastTime:" << Save.at(i).PastTime << endl;		//输入时间
			stream << "Scoe:"		<< Save.at(i).Scoe << endl;			//输入分数
		}
	}
	return 0;
}

int XmlSave::readXml(QList <QusSave> &x)
{
	QXmlStreamWriter *stream;
	QusSave xTemp;
	QTextCodec *code;
	code = QTextCodec::codecForName("GBK");	//字库初始化
	QString str;//题目
	QByteArray line;//中间题目缓存区
	int iL = 0;
	int jL = 0;
	//	data->remove();
	QFile* data = new QFile("./PointTestSave.txt");					//存储文件路径
	if (!data->open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Can't open the file!" << endl;
	}
	data->seek(0);
	while (true)
	{
		if (data->atEnd())
			break;
		line = data->readLine();
		str = code->toUnicode(line);
		str.remove('\n');
		iL = str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1).toInt();
	//	qDebug() << "SaveCount:" << iL;

		for (int i = 0;i < iL;i++)
		{
			line = data->readLine();
			str = code->toUnicode(line);
			str.remove('\n');
			jL = str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1).toInt();
			qDebug() << "++++TestCount:" << jL;
			for (int j = 0;j < jL;j++) {
				line = data->readLine();
				str = code->toUnicode(line);
				str.remove('\n');
				xTemp.Test.append(str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1));
				
				line = data->readLine();
				str = code->toUnicode(line);
				str.remove('\n');
				xTemp.TruAns.append(str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1));

				line = data->readLine();
				str = code->toUnicode(line);
				str.remove('\n');
				xTemp.MAns.append(str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1));
				}
		line = data->readLine();
		str = code->toUnicode(line);
		str.remove('\n');
		xTemp.PastTime=str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1).toInt();

		line = data->readLine();
		str = code->toUnicode(line);
		str.remove('\n');
		xTemp.Scoe = str.mid(str.indexOf(':') + 1, str.length() - str.indexOf(':') - 1).toInt();
		x.append(xTemp);
		xTemp.MAns.clear();
		xTemp.Test.clear();
		xTemp.TruAns.clear();
		}
		
	}
	return 0;
}

void XmlSave::parseUserInformation()
{

}

QString XmlSave::getValue(const QString & name)
{
	return QString();
}

QString XmlSave::getAttribute(const QString & name)
{
	return QString();
}
