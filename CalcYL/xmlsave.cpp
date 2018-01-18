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
		stream <<"SaveCount:" << Save.count() << endl;					//�������
			for (int i = 0;i < Save.count();i++)
		{
				stream <<"TestCount:"<< Save.at(i).Test.count() << endl;//�������
			for (int j = 0;j <Save.at(i).Test.count();j++)
			{
				stream <<"Test:"	<< Save.at(i).Test.at(j) << endl;	//������Ŀ
				stream <<"TruAns:"	<< Save.at(i).TruAns.at(j) << endl;	//������ȷ��
				stream <<"MAns:"	<< Save.at(i).MAns.at(j) << endl;	//�����ҵĴ�
			}
			stream << "PastTime:" << Save.at(i).PastTime << endl;		//����ʱ��
			stream << "Scoe:"		<< Save.at(i).Scoe << endl;			//�������
		}
	}
	return 0;
}

int XmlSave::readXml(QList <QusSave> &x)
{
	QXmlStreamWriter *stream;
	QusSave xTemp;
	QTextCodec *code;
	code = QTextCodec::codecForName("GBK");	//�ֿ��ʼ��
	QString str;//��Ŀ
	QByteArray line;//�м���Ŀ������
	int iL = 0;
	int jL = 0;
	//	data->remove();
	QFile* data = new QFile("./PointTestSave.txt");					//�洢�ļ�·��
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
