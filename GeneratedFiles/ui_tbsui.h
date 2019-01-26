/********************************************************************************
** Form generated from reading UI file 'tbsui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TBSUI_H
#define UI_TBSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tbsui
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page2;
    QGridLayout *gridLayout_4;
    QSlider *sli_H;
    QWidget *UpdateWdiget;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout;
    QCheckBox *che_Mip;
    QComboBox *com_IP;
    QToolButton *too_Refresh;
    QToolButton *too_Apply;
    QToolButton *too_Reboot;
    QTabWidget *tw_Set;
    QWidget *tab_IPSetting;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLineEdit *lin_Lport;
    QLineEdit *lin_LIP;
    QCheckBox *che_dhcp;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Lin_Netmask;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lin_Gateway;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_KidSetting;
    QGridLayout *gridLayout_5;
    QCheckBox *che_t0;
    QCheckBox *che_t1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lin_prate;
    QLabel *label_7;
    QLabel *label_15;
    QLineEdit *lin_Sym;
    QComboBox *com_Protocol_1;
    QComboBox *com_Modulation;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_17;
    QLabel *label_9;
    QLineEdit *lin_TSPort_1;
    QLineEdit *lin_TSPort_3;
    QLineEdit *lin_TSPort_2;
    QLineEdit *lin_Lev_0;
    QLineEdit *lin_Lev_1;
    QLineEdit *lin_TSPort_0;
    QComboBox *com_Protocol_2;
    QComboBox *com_Protocol_3;
    QLineEdit *lin_CastIP_3;
    QLineEdit *lin_CastIP_1;
    QCheckBox *che_sw_0;
    QLineEdit *lin_Lev_2;
    QComboBox *com_Protocol_0;
    QLineEdit *lin_CastIP_2;
    QLabel *label_16;
    QLabel *label_8;
    QLineEdit *lin_CastIP_0;
    QLineEdit *lin_Lev_3;
    QCheckBox *che_sw_1;
    QLineEdit *lin_Fre_2;
    QCheckBox *che_sw_3;
    QLineEdit *lin_Fre_1;
    QLineEdit *lin_Fre_0;
    QCheckBox *che_sw_2;
    QCheckBox *che_Rst;
    QLabel *label_10;
    QLineEdit *lin_Fre_3;

    void setupUi(QDialog *tbsui)
    {
        if (tbsui->objectName().isEmpty())
            tbsui->setObjectName(QStringLiteral("tbsui"));
        tbsui->resize(714, 512);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbsui->sizePolicy().hasHeightForWidth());
        tbsui->setSizePolicy(sizePolicy);
        tbsui->setLayoutDirection(Qt::LeftToRight);
        tbsui->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(tbsui);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(tbsui);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));
        labIco->setStyleSheet(QStringLiteral(""));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        stackedWidget = new QStackedWidget(tbsui);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        gridLayout_4 = new QGridLayout(page2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        sli_H = new QSlider(page2);
        sli_H->setObjectName(QStringLiteral("sli_H"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sli_H->sizePolicy().hasHeightForWidth());
        sli_H->setSizePolicy(sizePolicy3);
        sli_H->setMinimum(6);
        sli_H->setMaximum(72);
        sli_H->setValue(10);
        sli_H->setSliderPosition(10);
        sli_H->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(sli_H, 0, 0, 1, 1);

        UpdateWdiget = new QWidget(page2);
        UpdateWdiget->setObjectName(QStringLiteral("UpdateWdiget"));
        UpdateWdiget->setEnabled(true);
        sizePolicy.setHeightForWidth(UpdateWdiget->sizePolicy().hasHeightForWidth());
        UpdateWdiget->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(UpdateWdiget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        che_Mip = new QCheckBox(UpdateWdiget);
        che_Mip->setObjectName(QStringLiteral("che_Mip"));
        che_Mip->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(che_Mip);

        com_IP = new QComboBox(UpdateWdiget);
        com_IP->setObjectName(QStringLiteral("com_IP"));
        com_IP->setEditable(false);

        horizontalLayout->addWidget(com_IP);

        too_Refresh = new QToolButton(UpdateWdiget);
        too_Refresh->setObjectName(QStringLiteral("too_Refresh"));
        sizePolicy1.setHeightForWidth(too_Refresh->sizePolicy().hasHeightForWidth());
        too_Refresh->setSizePolicy(sizePolicy1);
        too_Refresh->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        horizontalLayout->addWidget(too_Refresh);

        too_Apply = new QToolButton(UpdateWdiget);
        too_Apply->setObjectName(QStringLiteral("too_Apply"));
        sizePolicy1.setHeightForWidth(too_Apply->sizePolicy().hasHeightForWidth());
        too_Apply->setSizePolicy(sizePolicy1);
        too_Apply->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        horizontalLayout->addWidget(too_Apply);

        too_Reboot = new QToolButton(UpdateWdiget);
        too_Reboot->setObjectName(QStringLiteral("too_Reboot"));
        sizePolicy1.setHeightForWidth(too_Reboot->sizePolicy().hasHeightForWidth());
        too_Reboot->setSizePolicy(sizePolicy1);
        too_Reboot->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        horizontalLayout->addWidget(too_Reboot);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        gridLayout_6->addLayout(horizontalLayout, 0, 0, 1, 1);

        tw_Set = new QTabWidget(UpdateWdiget);
        tw_Set->setObjectName(QStringLiteral("tw_Set"));
        tab_IPSetting = new QWidget();
        tab_IPSetting->setObjectName(QStringLiteral("tab_IPSetting"));
        gridLayout_7 = new QGridLayout(tab_IPSetting);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_3 = new QGroupBox(tab_IPSetting);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lin_Lport = new QLineEdit(groupBox_3);
        lin_Lport->setObjectName(QStringLiteral("lin_Lport"));

        gridLayout->addWidget(lin_Lport, 2, 1, 1, 1);

        lin_LIP = new QLineEdit(groupBox_3);
        lin_LIP->setObjectName(QStringLiteral("lin_LIP"));

        gridLayout->addWidget(lin_LIP, 1, 1, 1, 1);

        che_dhcp = new QCheckBox(groupBox_3);
        che_dhcp->setObjectName(QStringLiteral("che_dhcp"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(che_dhcp->sizePolicy().hasHeightForWidth());
        che_dhcp->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(che_dhcp, 0, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        Lin_Netmask = new QLineEdit(groupBox_3);
        Lin_Netmask->setObjectName(QStringLiteral("Lin_Netmask"));

        gridLayout->addWidget(Lin_Netmask, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lin_Gateway = new QLineEdit(groupBox_3);
        lin_Gateway->setObjectName(QStringLiteral("lin_Gateway"));

        gridLayout->addWidget(lin_Gateway, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 2, 0, 1, 2);

        tw_Set->addTab(tab_IPSetting, QString());
        tab_KidSetting = new QWidget();
        tab_KidSetting->setObjectName(QStringLiteral("tab_KidSetting"));
        gridLayout_5 = new QGridLayout(tab_KidSetting);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        che_t0 = new QCheckBox(tab_KidSetting);
        che_t0->setObjectName(QStringLiteral("che_t0"));
        che_t0->setEnabled(true);
        sizePolicy1.setHeightForWidth(che_t0->sizePolicy().hasHeightForWidth());
        che_t0->setSizePolicy(sizePolicy1);
        che_t0->setChecked(true);

        gridLayout_5->addWidget(che_t0, 0, 0, 1, 1);

        che_t1 = new QCheckBox(tab_KidSetting);
        che_t1->setObjectName(QStringLiteral("che_t1"));
        sizePolicy1.setHeightForWidth(che_t1->sizePolicy().hasHeightForWidth());
        che_t1->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(che_t1, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(tab_KidSetting);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lin_prate = new QLineEdit(groupBox_2);
        lin_prate->setObjectName(QStringLiteral("lin_prate"));
        lin_prate->setReadOnly(true);

        gridLayout_3->addWidget(lin_prate, 12, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 12, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 7, 0, 1, 1);

        lin_Sym = new QLineEdit(groupBox_2);
        lin_Sym->setObjectName(QStringLiteral("lin_Sym"));

        gridLayout_3->addWidget(lin_Sym, 11, 1, 1, 1);

        com_Protocol_1 = new QComboBox(groupBox_2);
        com_Protocol_1->addItem(QString());
        com_Protocol_1->addItem(QString());
        com_Protocol_1->setObjectName(QStringLiteral("com_Protocol_1"));

        gridLayout_3->addWidget(com_Protocol_1, 8, 2, 1, 1);

        com_Modulation = new QComboBox(groupBox_2);
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->setObjectName(QStringLiteral("com_Modulation"));

        gridLayout_3->addWidget(com_Modulation, 10, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_5, 10, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_6, 11, 0, 1, 1);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 6, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        lin_TSPort_1 = new QLineEdit(groupBox_2);
        lin_TSPort_1->setObjectName(QStringLiteral("lin_TSPort_1"));

        gridLayout_3->addWidget(lin_TSPort_1, 7, 2, 1, 1);

        lin_TSPort_3 = new QLineEdit(groupBox_2);
        lin_TSPort_3->setObjectName(QStringLiteral("lin_TSPort_3"));

        gridLayout_3->addWidget(lin_TSPort_3, 7, 4, 1, 1);

        lin_TSPort_2 = new QLineEdit(groupBox_2);
        lin_TSPort_2->setObjectName(QStringLiteral("lin_TSPort_2"));

        gridLayout_3->addWidget(lin_TSPort_2, 7, 3, 1, 1);

        lin_Lev_0 = new QLineEdit(groupBox_2);
        lin_Lev_0->setObjectName(QStringLiteral("lin_Lev_0"));
        lin_Lev_0->setClearButtonEnabled(false);

        gridLayout_3->addWidget(lin_Lev_0, 2, 1, 1, 1);

        lin_Lev_1 = new QLineEdit(groupBox_2);
        lin_Lev_1->setObjectName(QStringLiteral("lin_Lev_1"));

        gridLayout_3->addWidget(lin_Lev_1, 2, 2, 1, 1);

        lin_TSPort_0 = new QLineEdit(groupBox_2);
        lin_TSPort_0->setObjectName(QStringLiteral("lin_TSPort_0"));

        gridLayout_3->addWidget(lin_TSPort_0, 7, 1, 1, 1);

        com_Protocol_2 = new QComboBox(groupBox_2);
        com_Protocol_2->addItem(QString());
        com_Protocol_2->addItem(QString());
        com_Protocol_2->setObjectName(QStringLiteral("com_Protocol_2"));

        gridLayout_3->addWidget(com_Protocol_2, 8, 3, 1, 1);

        com_Protocol_3 = new QComboBox(groupBox_2);
        com_Protocol_3->addItem(QString());
        com_Protocol_3->addItem(QString());
        com_Protocol_3->setObjectName(QStringLiteral("com_Protocol_3"));

        gridLayout_3->addWidget(com_Protocol_3, 8, 4, 1, 1);

        lin_CastIP_3 = new QLineEdit(groupBox_2);
        lin_CastIP_3->setObjectName(QStringLiteral("lin_CastIP_3"));

        gridLayout_3->addWidget(lin_CastIP_3, 6, 4, 1, 1);

        lin_CastIP_1 = new QLineEdit(groupBox_2);
        lin_CastIP_1->setObjectName(QStringLiteral("lin_CastIP_1"));

        gridLayout_3->addWidget(lin_CastIP_1, 6, 2, 1, 1);

        che_sw_0 = new QCheckBox(groupBox_2);
        che_sw_0->setObjectName(QStringLiteral("che_sw_0"));

        gridLayout_3->addWidget(che_sw_0, 0, 1, 1, 1);

        lin_Lev_2 = new QLineEdit(groupBox_2);
        lin_Lev_2->setObjectName(QStringLiteral("lin_Lev_2"));

        gridLayout_3->addWidget(lin_Lev_2, 2, 3, 1, 1);

        com_Protocol_0 = new QComboBox(groupBox_2);
        com_Protocol_0->addItem(QString());
        com_Protocol_0->addItem(QString());
        com_Protocol_0->setObjectName(QStringLiteral("com_Protocol_0"));

        gridLayout_3->addWidget(com_Protocol_0, 8, 1, 1, 1);

        lin_CastIP_2 = new QLineEdit(groupBox_2);
        lin_CastIP_2->setObjectName(QStringLiteral("lin_CastIP_2"));

        gridLayout_3->addWidget(lin_CastIP_2, 6, 3, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_16, 8, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        lin_CastIP_0 = new QLineEdit(groupBox_2);
        lin_CastIP_0->setObjectName(QStringLiteral("lin_CastIP_0"));

        gridLayout_3->addWidget(lin_CastIP_0, 6, 1, 1, 1);

        lin_Lev_3 = new QLineEdit(groupBox_2);
        lin_Lev_3->setObjectName(QStringLiteral("lin_Lev_3"));

        gridLayout_3->addWidget(lin_Lev_3, 2, 4, 1, 1);

        che_sw_1 = new QCheckBox(groupBox_2);
        che_sw_1->setObjectName(QStringLiteral("che_sw_1"));

        gridLayout_3->addWidget(che_sw_1, 0, 2, 1, 1);

        lin_Fre_2 = new QLineEdit(groupBox_2);
        lin_Fre_2->setObjectName(QStringLiteral("lin_Fre_2"));
        lin_Fre_2->setReadOnly(true);

        gridLayout_3->addWidget(lin_Fre_2, 1, 3, 1, 1);

        che_sw_3 = new QCheckBox(groupBox_2);
        che_sw_3->setObjectName(QStringLiteral("che_sw_3"));

        gridLayout_3->addWidget(che_sw_3, 0, 4, 1, 1);

        lin_Fre_1 = new QLineEdit(groupBox_2);
        lin_Fre_1->setObjectName(QStringLiteral("lin_Fre_1"));
        lin_Fre_1->setReadOnly(true);

        gridLayout_3->addWidget(lin_Fre_1, 1, 2, 1, 1);

        lin_Fre_0 = new QLineEdit(groupBox_2);
        lin_Fre_0->setObjectName(QStringLiteral("lin_Fre_0"));

        gridLayout_3->addWidget(lin_Fre_0, 1, 1, 1, 1);

        che_sw_2 = new QCheckBox(groupBox_2);
        che_sw_2->setObjectName(QStringLiteral("che_sw_2"));

        gridLayout_3->addWidget(che_sw_2, 0, 3, 1, 1);

        che_Rst = new QCheckBox(groupBox_2);
        che_Rst->setObjectName(QStringLiteral("che_Rst"));

        gridLayout_3->addWidget(che_Rst, 13, 0, 1, 3);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        lin_Fre_3 = new QLineEdit(groupBox_2);
        lin_Fre_3->setObjectName(QStringLiteral("lin_Fre_3"));
        lin_Fre_3->setReadOnly(true);

        gridLayout_3->addWidget(lin_Fre_3, 1, 4, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 3, 0, 1, 2);

        tw_Set->addTab(tab_KidSetting, QString());

        gridLayout_6->addWidget(tw_Set, 1, 0, 1, 1);


        gridLayout_4->addWidget(UpdateWdiget, 1, 0, 1, 1);

        stackedWidget->addWidget(page2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(tbsui);

        stackedWidget->setCurrentIndex(0);
        tw_Set->setCurrentIndex(1);
        com_Modulation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(tbsui);
    } // setupUi

    void retranslateUi(QDialog *tbsui)
    {
        tbsui->setWindowTitle(QApplication::translate("tbsui", "Form", nullptr));
        labIco->setText(QString());
        labTitle->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("tbsui", "\345\205\263\351\227\255", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("tbsui", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
        btnMenu_Max->setText(QString());
        che_Mip->setText(QApplication::translate("tbsui", "Manual add ip", nullptr));
        too_Refresh->setText(QApplication::translate("tbsui", "Refresh", nullptr));
        too_Apply->setText(QApplication::translate("tbsui", "Apply", nullptr));
        too_Reboot->setText(QApplication::translate("tbsui", "All restart", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        tab_IPSetting->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        groupBox_3->setTitle(QString());
#ifndef QT_NO_ACCESSIBILITY
        lin_LIP->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        che_dhcp->setText(QApplication::translate("tbsui", "DHCP", nullptr));
        label->setText(QApplication::translate("tbsui", "Local IP:", nullptr));
        label_2->setText(QApplication::translate("tbsui", "Local port:", nullptr));
        label_3->setText(QApplication::translate("tbsui", "Netmask:", nullptr));
        label_4->setText(QApplication::translate("tbsui", "Gateway:", nullptr));
        tw_Set->setTabText(tw_Set->indexOf(tab_IPSetting), QApplication::translate("tbsui", "IP Setting", nullptr));
        che_t0->setText(QApplication::translate("tbsui", "Modulator 0", nullptr));
        che_t1->setText(QApplication::translate("tbsui", "Modulator 1", nullptr));
        groupBox_2->setTitle(QString());
        label_7->setText(QApplication::translate("tbsui", "Playrate\357\274\210bps\357\274\211:", nullptr));
        label_15->setText(QApplication::translate("tbsui", "TS Port:", nullptr));
        lin_Sym->setText(QString());
        com_Protocol_1->setItemText(0, QApplication::translate("tbsui", "UDP", nullptr));
        com_Protocol_1->setItemText(1, QApplication::translate("tbsui", "RTP", nullptr));

        com_Modulation->setItemText(0, QApplication::translate("tbsui", "16QAM", nullptr));
        com_Modulation->setItemText(1, QApplication::translate("tbsui", "32QAM", nullptr));
        com_Modulation->setItemText(2, QApplication::translate("tbsui", "64QAM", nullptr));
        com_Modulation->setItemText(3, QApplication::translate("tbsui", "128QAM", nullptr));
        com_Modulation->setItemText(4, QApplication::translate("tbsui", "256QAM", nullptr));

        label_5->setText(QApplication::translate("tbsui", "Modulation:", nullptr));
        label_6->setText(QApplication::translate("tbsui", "Symbolrate (2000-7200\n"
"kbps):", nullptr));
        label_17->setText(QApplication::translate("tbsui", "Multicast/unicast ip:", nullptr));
        label_9->setText(QApplication::translate("tbsui", "Frequence (100~1000MHZ):", nullptr));
        lin_Lev_0->setText(QString());
        lin_TSPort_0->setText(QString());
        com_Protocol_2->setItemText(0, QApplication::translate("tbsui", "UDP", nullptr));
        com_Protocol_2->setItemText(1, QApplication::translate("tbsui", "RTP", nullptr));

        com_Protocol_3->setItemText(0, QApplication::translate("tbsui", "UDP", nullptr));
        com_Protocol_3->setItemText(1, QApplication::translate("tbsui", "RTP", nullptr));

        che_sw_0->setText(QApplication::translate("tbsui", "Channel 0", nullptr));
        com_Protocol_0->setItemText(0, QApplication::translate("tbsui", "UDP", nullptr));
        com_Protocol_0->setItemText(1, QApplication::translate("tbsui", "RTP", nullptr));

        label_16->setText(QApplication::translate("tbsui", "Net protocol:", nullptr));
        label_8->setText(QApplication::translate("tbsui", "Gain (5~120):", nullptr));
        lin_CastIP_0->setText(QString());
        che_sw_1->setText(QApplication::translate("tbsui", "Channel 1", nullptr));
        che_sw_3->setText(QApplication::translate("tbsui", "Channel 3", nullptr));
        che_sw_2->setText(QApplication::translate("tbsui", "Channel 2", nullptr));
        che_Rst->setText(QApplication::translate("tbsui", "DVBC sub-module software restart", nullptr));
        label_10->setText(QApplication::translate("tbsui", "Channel switch:", nullptr));
        tw_Set->setTabText(tw_Set->indexOf(tab_KidSetting), QApplication::translate("tbsui", "Modulator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tbsui: public Ui_tbsui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TBSUI_H
