/********************************************************************************
** Form generated from reading UI file 'setmactool.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMACTOOL_H
#define UI_SETMACTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetMACTool
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *com_LocalIP;
    QLabel *label_2;
    QLineEdit *lin_NetMac;
    QLabel *label_3;
    QLineEdit *lin_SeNetMac;
    QPushButton *btn_Macapply;

    void setupUi(QDialog *SetMACTool)
    {
        if (SetMACTool->objectName().isEmpty())
            SetMACTool->setObjectName(QStringLiteral("SetMACTool"));
        SetMACTool->resize(320, 240);
        gridLayout = new QGridLayout(SetMACTool);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(SetMACTool);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        com_LocalIP = new QComboBox(groupBox);
        com_LocalIP->setObjectName(QStringLiteral("com_LocalIP"));

        gridLayout_2->addWidget(com_LocalIP, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lin_NetMac = new QLineEdit(groupBox);
        lin_NetMac->setObjectName(QStringLiteral("lin_NetMac"));
        lin_NetMac->setEnabled(true);
        lin_NetMac->setReadOnly(true);

        gridLayout_2->addWidget(lin_NetMac, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        lin_SeNetMac = new QLineEdit(groupBox);
        lin_SeNetMac->setObjectName(QStringLiteral("lin_SeNetMac"));

        gridLayout_2->addWidget(lin_SeNetMac, 2, 1, 1, 1);

        btn_Macapply = new QPushButton(groupBox);
        btn_Macapply->setObjectName(QStringLiteral("btn_Macapply"));

        gridLayout_2->addWidget(btn_Macapply, 3, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(SetMACTool);

        QMetaObject::connectSlotsByName(SetMACTool);
    } // setupUi

    void retranslateUi(QDialog *SetMACTool)
    {
        SetMACTool->setWindowTitle(QApplication::translate("SetMACTool", "MACTOOL", nullptr));
        groupBox->setTitle(QApplication::translate("SetMACTool", "SetMAC:", nullptr));
        label->setText(QApplication::translate("SetMACTool", "LocalIP:", nullptr));
        label_2->setText(QApplication::translate("SetMACTool", "Display Netmac:", nullptr));
        lin_NetMac->setPlaceholderText(QApplication::translate("SetMACTool", "00:22:ab:00:00:00", nullptr));
        label_3->setText(QApplication::translate("SetMACTool", "Set Netmac:", nullptr));
        lin_SeNetMac->setPlaceholderText(QApplication::translate("SetMACTool", "00:22:ab:00:00:00", nullptr));
        btn_Macapply->setText(QApplication::translate("SetMACTool", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetMACTool: public Ui_SetMACTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMACTOOL_H
