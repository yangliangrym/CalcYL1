#ifndef CALCYL_H
#define CALCYL_H
#include"AthmeticYl.h"
#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include <qtimer.h>
#include <qdebug.h>
#include "ui_calcyl.h"
#include <xmlsave.h>
#include <QtGuiClass.h>


class CalcYL : public QMainWindow
{
	Q_OBJECT
public:
	CalcYL(QWidget *parent = 0);
	~CalcYL();

private:
	QtGuiClass MyTestView;
	XmlSave xmlsave;
	QusSave qussave;
	QList <QusSave> qussaveList;
	QList <QusSave> qussaveListTemp;
	Ui::CalcYLClass ui;
	AthmeticYl Ath;
	QTimer TestTimerOut;
	int AllTime = 0;
	int TestId = 0;
	int Scoe =0;			//	用于记录分数
	int perScoe = 0;
	int TestN = 0;
	int TimerInt = -1;
private slots:
	void on_ErtestBtn_clicked();
	void on_pushButton_clicked();
	void on_PushTestBtn_clicked();
	void on_AnsOkBtn_clicked();
	void on_TimerOut();
};

#endif // CALCYL_H
