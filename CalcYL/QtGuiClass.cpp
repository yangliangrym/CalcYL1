#include "QtGuiClass.h"

QtGuiClass::QtGuiClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	xmlsave.readXml(qussaveList);


	connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked(const QModelIndex &)));

	int con=0;
	for (int i = 0;i < qussaveList.count();i++)
	{
		qDebug() << "TestCount:" << qussaveList.at(i).Test.count() << endl;//�������

		for (int j = 0;j <qussaveList.at(i).Test.count();j++)
		{
			qDebug() << "Test:" << qussaveList.at(i).Test.at(j) << endl;	//������Ŀ
			qDebug() << "TruAns:" << qussaveList.at(i).TruAns.at(j) << endl;//������ȷ��
			qDebug() << "MAns:" << qussaveList.at(i).MAns.at(j) << endl;	//�����ҵĴ�
		}
		qDebug() << "PastTime:" << qussaveList.at(i).PastTime << endl;		//����ʱ��
		qDebug() << "Scoe:" << qussaveList.at(i).Scoe << endl;				//�������
	}
	model = new QStandardItemModel(qussaveList.count(), 3,this);
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("���"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("�ɼ�"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��ʱ"));

	mode2 = new QStandardItemModel(100, 4, this);
	mode2->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"));
	mode2->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("��Ĵ�"));
	mode2->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��ȷ��"));
	mode2->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("���"));
	int coni = 0;

	for (int i = 0;i < qussaveList.count();i++)
	{
		QStandardItem *item1 = new QStandardItem(QString::number(i));
		model->setItem(i, 0, item1);
		QStandardItem *item2 = new QStandardItem(QString::number(qussaveList.at(i).Scoe)+QString::fromLocal8Bit("��"));
		model->setItem(i, 1, item2);
		QStandardItem *item3 = new QStandardItem(QString::number(qussaveList.at(i).PastTime)+QString::fromLocal8Bit("��"));
		model->setItem(i, 2, item3);
	


	}
	ui.tableView->setModel(model);

}

QtGuiClass::~QtGuiClass()
{

}

void QtGuiClass::slotRowDoubleClicked(const QModelIndex &)
{
	QString TempJg = QString::fromLocal8Bit("��ȷ");
	QString TempJg2 = QString::fromLocal8Bit("����");
	int i= ui.tableView->currentIndex().row();
	mode2->removeRows(0,mode2->rowCount());
	qDebug() << "kkkkkkkkkkkkkkkkkkkk" << qussaveList.at(i).Test.count();
	for (int j = 0;j <qussaveList.at(i).Test.count();j++)
	{
		qDebug() << "****************"<<i;
		QStandardItem *item1 = new QStandardItem(qussaveList.at(i).Test.at(j));
		mode2->setItem(j, 0, item1);
		QStandardItem *item2 = new QStandardItem(qussaveList.at(i).MAns.at(j));
		mode2->setItem(j, 1, item2);
		QStandardItem *item3 = new QStandardItem(qussaveList.at(i).TruAns.at(j));
		mode2->setItem(j, 2, item3);
		if (qussaveList.at(i).MAns.at(j) == qussaveList.at(i).TruAns.at(j))
		{
			QStandardItem *item4 = new QStandardItem(TempJg);
			mode2->setItem(j, 3, item4);
		}
		else
		{
			QStandardItem *item4 = new QStandardItem(TempJg2);
			mode2->setItem(j, 3, item4);
		}
	



		qDebug() << "Test:" << qussaveList.at(i).Test.at(j) << endl;	//������Ŀ
		qDebug() << "TruAns:" << qussaveList.at(i).TruAns.at(j) << endl;//������ȷ��
		qDebug() << "MAns:" << qussaveList.at(i).MAns.at(j) << endl;	//�����ҵĴ�
	}
	ui.tableView_2->setModel(mode2);

}
