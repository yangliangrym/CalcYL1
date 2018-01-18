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
		ui.label->setText(QString::fromLocal8Bit("正确"));
		ui.TrueAnsLab->setText(QString::fromLocal8Bit("正确答案是：")+Ath.gRightAns);
	}
	else
	{
		/*qDebug() << qussave.Test;
		qDebug() << qussave.TruAns;
		qDebug() << qussave.MAns;*/
		ui.label->setText(QString::fromLocal8Bit("错误"));
		ui.TrueAnsLab->setText(QString::fromLocal8Bit("正确答案是：") + Ath.gRightAns);
		Scoe -= perScoe;
	}
	
}
///定时刷新槽函数
void CalcYL::on_TimerOut()
{
	if (TimerInt == -1)
		return;//考试未开始
	if (TimerInt > 0)
	{
		TimerInt--;
		ui.TimeOutLab->setText(QString::number(TimerInt));
	}
	else
	{
		//考试时间结束

		Scoe -= perScoe*(TestN + 1 - TestId);
		if (Scoe < perScoe)
			Scoe = 0;//防止约等于1；

					 //*****************保存本次答题***************************
		qussave.PastTime = AllTime - TimerInt;
		qussave.Scoe = Scoe;
		qussaveList.append(qussave);			//加入列表

		QMessageBox::warning(this, QString::fromLocal8Bit("考试时间结束"), QString::fromLocal8Bit("考试时间结束，您的成绩为%1").arg(Scoe));
		Scoe = 100;
		TestTimerOut.stop();
		TimerInt = -1;
		ui.AnsOkBtn->setDisabled(true);
		ui.PushTestBtn->setDisabled(false);
	}

}
void CalcYL::on_pushButton_clicked()
{
	ui.TrueAnsLab->setText(QString::fromLocal8Bit("正确答案是："));

	qussave.Test.append(Ath.pTest);		    //记录试题
	qussave.TruAns.append(Ath.gRightAns);	//记录正确答案
	qussave.MAns.append(ui.AnsEdt->text()); //记录答案
	
											//xmlsave.writeXml(qussaveList);
	if (TestId < TestN)
	{
		TestId++;
		ui.groupBox->setTitle(QString::fromLocal8Bit("第") + QString::number(TestId) + QString::fromLocal8Bit("题"));
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
			Scoe = 0;//防止约等于1；

					 //*****************保存本次答题***************************
		qussave.PastTime = AllTime - TimerInt;
		qussave.Scoe = Scoe;
		qussaveList.append(qussave);			//加入列表
		//xmlsave.writeXml(qussaveList);



		QMessageBox::warning(this, QString::fromLocal8Bit("考试结束"), QString::fromLocal8Bit("考试结束，您的成绩为%1").arg(Scoe));
		ui.AnsOkBtn->setDisabled(true);
		ui.pushButton->setDisabled(true);
		ui.PushTestBtn->setDisabled(false);
		TestTimerOut.stop();
		Scoe = 100;
	}
	ui.AnsEdt->clear();




}
///确定题目个数按钮槽函数
void CalcYL::on_PushTestBtn_clicked()
{
	TestN= ui.TestNInEdt->text().toInt();

	if (TestN > 0)
	{
		TestId = 0;
		perScoe = 100 / TestN;				//采用减分制
		TimerInt = 15 * TestN;				//计算考试时间
		AllTime = TimerInt;					//记录该次
		Ath.TestN = TestN;
		Ath.m();
		ui.TestLab->setText(Ath.pTest);
		ui.PushTestBtn->setDisabled(true);	//答题过程中不允许生成题目
		TestId++;
		ui.groupBox->setTitle(QString::fromLocal8Bit("第") + QString::number(TestId) + QString::fromLocal8Bit("题"));
		TestTimerOut.start(1000);
		ui.AnsOkBtn->setDisabled(false);

	}
	else
	{
		ui.TestNInEdt->clear();
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的题目个数"));
	}
	

}
void CalcYL::on_ErtestBtn_clicked()
{
	xmlsave.readXml(qussaveListTemp);
	MyTestView.show();
}