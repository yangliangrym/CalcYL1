#pragma once
#include <QWidget>
#include "ui_QtGuiClass.h"
#include <xmlsave.h>
#include <qdebug.h>
#include <qstandarditemmodel.h>
class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();
	QStandardItemModel *model;
	QStandardItemModel *mode2;
public slots:
	void slotRowDoubleClicked(const QModelIndex &);
private:
	XmlSave xmlsave;
	QusSave qussave;
	QList <QusSave> qussaveList;
	Ui::QtGuiClass ui;
};
