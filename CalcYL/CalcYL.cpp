#include "calcyl.h"

CalcYL::CalcYL(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	xmlsave.readXml(qussaveList);
	connect(&TestTimerOut,SIGNAL(timeout()),this,SLOT(on_TimerOut()));
	ui.pushButton->setDisabled(true);
	ui.AnsOkBtn->setDisabled(true);

}

CalcYL::~CalcYL()
{
	xmlsave.writeXml(qussaveList);
}

void CalcYL::on_AnsOkBtn_clicked()
{
	ui.AnsOkBtn->setDisabled(true);
	ui.pushButton->setDisabled(false);

	if (Ath.Jug(ui.AnsEdt->text()))
	{
		ui.label->setText(QString::fromLocal8Bit("��ȷ"));
		ui.TrueAnsLab->setText(QString::fromLocal8Bit("��ȷ���ǣ�")+Ath.gRightAns);
	}
	else
	{
		/*qDebug() << qussave.Test;
		qDebug() << qussave.TruAns;
		qDebug() << qussave.MAns;*/
		ui.label->setText(QString::fromLocal8Bit("����"));
		ui.TrueAnsLab->setText(QString::fromLocal8Bit("��ȷ���ǣ�") + Ath.gRightAns);
		Scoe -= perScoe;
	}
	
}
///��ʱˢ�²ۺ���
void CalcYL::on_TimerOut()
{
	if (TimerInt == -1)
		return;//����δ��ʼ
	if (TimerInt > 0)
	{
		TimerInt--;
		ui.TimeOutLab->setText(QString::number(TimerInt));
	}
	else
	{
		//����ʱ�����

		Scoe -= perScoe*(TestN + 1 - TestId);
		if (Scoe < perScoe)
			Scoe = 0;//��ֹԼ����1��

					 //*****************���汾�δ���***************************
		qussave.PastTime = AllTime - TimerInt;
		qussave.Scoe = Scoe;
		qussaveList.append(qussave);			//�����б�

		QMessageBox::warning(this, QString::fromLocal8Bit("����ʱ�����"), QString::fromLocal8Bit("����ʱ����������ĳɼ�Ϊ%1").arg(Scoe));
		Scoe = 100;
		TestTimerOut.stop();
		TimerInt = -1;
		ui.AnsOkBtn->setDisabled(true);
		ui.PushTestBtn->setDisabled(false);
	}

}
void CalcYL::on_pushButton_clicked()
{
	ui.TrueAnsLab->setText(QString::fromLocal8Bit("��ȷ���ǣ�"));

	qussave.Test.append(Ath.pTest);		    //��¼����
	qussave.TruAns.append(Ath.gRightAns);	//��¼��ȷ��
	qussave.MAns.append(ui.AnsEdt->text()); //��¼��
	
											//xmlsave.writeXml(qussaveList);
	if (TestId < TestN)
	{
		TestId++;
		ui.groupBox->setTitle(QString::fromLocal8Bit("��") + QString::number(TestId) + QString::fromLocal8Bit("��"));
		Ath.m();
		ui.TestLab->setText(Ath.pTest);
		ui.pushButton->setDisabled(true);
		ui.AnsOkBtn->setDisabled(false);

	}
	else
	{
		TimerInt = -1;
		ui.TimeOutLab->setText(QString::number(0));
		if (Scoe < perScoe)
			Scoe = 0;//��ֹԼ����1��

					 //*****************���汾�δ���***************************
		qussave.PastTime = AllTime - TimerInt;
		qussave.Scoe = Scoe;
		qussaveList.append(qussave);			//�����б�
		//xmlsave.writeXml(qussaveList);



		QMessageBox::warning(this, QString::fromLocal8Bit("���Խ���"), QString::fromLocal8Bit("���Խ��������ĳɼ�Ϊ%1").arg(Scoe));
		ui.AnsOkBtn->setDisabled(true);
		ui.pushButton->setDisabled(true);
		ui.PushTestBtn->setDisabled(false);
		TestTimerOut.stop();
		Scoe = 100;
	}
	ui.AnsEdt->clear();




}
///ȷ����Ŀ������ť�ۺ���
void CalcYL::on_PushTestBtn_clicked()
{
	TestN= ui.TestNInEdt->text().toInt();

	if (TestN > 0)
	{
		TestId = 0;
		perScoe = 100 / TestN;				//���ü�����
		TimerInt = 15 * TestN;				//���㿼��ʱ��
		AllTime = TimerInt;					//��¼�ô�
		Ath.TestN = TestN;
		Ath.m();
		ui.TestLab->setText(Ath.pTest);
		ui.PushTestBtn->setDisabled(true);	//��������в�����������Ŀ
		TestId++;
		ui.groupBox->setTitle(QString::fromLocal8Bit("��") + QString::number(TestId) + QString::fromLocal8Bit("��"));
		TestTimerOut.start(1000);
		ui.AnsOkBtn->setDisabled(false);

	}
	else
	{
		ui.TestNInEdt->clear();
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��������ȷ����Ŀ����"));
	}
	

}
void CalcYL::on_ErtestBtn_clicked()
{
	xmlsave.readXml(qussaveListTemp);
	MyTestView.show();
}