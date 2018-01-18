/********************************************************************************
** Form generated from reading UI file 'QtGuiClass.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASS_H
#define UI_QTGUICLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiClass
{
public:
    QTableView *tableView;
    QTableView *tableView_2;

    void setupUi(QWidget *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QStringLiteral("QtGuiClass"));
        QtGuiClass->resize(1067, 606);
        tableView = new QTableView(QtGuiClass);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(50, 80, 411, 391));
        tableView_2 = new QTableView(QtGuiClass);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(470, 80, 571, 391));

        retranslateUi(QtGuiClass);

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QWidget *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QApplication::translate("QtGuiClass", "QtGuiClass", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASS_H
