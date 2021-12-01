/********************************************************************************
** Form generated from reading UI file 'controlbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLBOX_H
#define UI_CONTROLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlBox
{
public:
    QAction *actionMove_Before;
    QAction *actionMove_After;
    QAction *actionRescan;
    QAction *actionOffline_Mode;
    QAction *actionIDPass;
    QVBoxLayout *verticalLayout_11;
    QTabWidget *tabWidget;
    QWidget *Status;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_7;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_global_properties;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_18;
    QLabel *label_offlinemode;
    QLabel *label_state;
    QCheckBox *checkBox_devicesoff;
    QLabel *label_state_pix;
    QToolButton *toolButton_offlinemode;
    QSplitter *splitter01;
    QGroupBox *groupBox_technologies;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_technologies;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_rescanwifi01;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_IDPass;
    QCheckBox *checkBox_hidetethering;
    QGroupBox *groupBox_services;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_services;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_movebefore;
    QPushButton *pushButton_moveafter;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBox_hidecnxn;
    QWidget *Details;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_service;
    QComboBox *comboBox_service;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *_2;
    QLabel *label_details_connection;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_details_left;
    QLabel *label_details_right;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_configuration;
    QWidget *Wireless;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget_wifi;
    QGroupBox *groupBox_wireless_utils;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_rescanwifi02;
    QLabel *label_wifi_state;
    QSpacerItem *horizontalSpacer_6;
    QWidget *VPN;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_vpn_utils;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_vpn_connect;
    QPushButton *pushButton_vpn_disconnect;
    QSpacerItem *horizontalSpacer_10;
    QTableWidget *tableWidget_vpn;
    QWidget *Counters;
    QGridLayout *gridLayout_15;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_6;
    QGridLayout *gridLayout_7;
    QLabel *label_counter_service_name;
    QGroupBox *groupBox_home_counter;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea_home_counter;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_home_counter;
    QGroupBox *groupBox_roaming_counter;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea_roaming_counter;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_roam_counter;
    QLabel *label_counter_settings;
    QWidget *Preferences;
    QGridLayout *gridLayout_14;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_programcontrol;
    QGridLayout *gridLayout_10;
    QCheckBox *checkBox_retryfailed;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *checkBox_runonstartup;
    QCheckBox *checkBox_killswitch;
    QGroupBox *groupBox_notifications;
    QGridLayout *gridLayout_17;
    QLabel *label_serverstatus;
    QCheckBox *checkBox_notifydaemon;
    QGroupBox *groupBox_preferencesinterface;
    QGridLayout *gridLayout_12;
    QCheckBox *checkBox_resetcounters;
    QCheckBox *checkBox_advanced;
    QCheckBox *checkBox_usestartoptions;
    QCheckBox *checkBox_retainstate;
    QCheckBox *checkBox_enableinterfacetooltips;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_colorize;
    QToolButton *toolButton_colorize;
    QLabel *label_2;
    QGroupBox *groupBox_systemtray;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_enablesystemtraytooltips;
    QCheckBox *checkBox_hideIcon;
    QCheckBox *checkBox_systemtraynotifications;
    QGroupBox *groupBox_startoptions;
    QGridLayout *gridLayout_9;
    QSpinBox *spinBox_faketransparency;
    QLineEdit *lineEdit_icontheme;
    QCheckBox *checkBox_enablecounters;
    QCheckBox *checkBox_disabletrayicon;
    QSpinBox *spinBox_counterkb;
    QCheckBox *checkBox_startminimized;
    QCheckBox *checkBox_faketranparency;
    QCheckBox *checkBox_waittime;
    QCheckBox *checkBox_systemicontheme;
    QSpinBox *spinBox_counterrate;
    QCheckBox *checkBox_counterkb;
    QCheckBox *checkBox_disableminimized;
    QCheckBox *checkBox_disablevpn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QRadioButton *radioButton_desktopnone;
    QRadioButton *radioButton_desktopxfce;
    QRadioButton *radioButton_desktopmate;
    QSpinBox *spinBox_waittime;
    QCheckBox *checkBox_counterseconds;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_process;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_beforeconnect;
    QLabel *label_4;
    QComboBox *comboBox_beforeconnectserviceslist;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_13;
    QCheckBox *checkBox_modifyservicefile;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QComboBox *comboBox_beforeconnectservicefile;
    QLabel *label;
    QLineEdit *lineEdit_afterconnect;
    QSpacerItem *verticalSpacer;
    QWidget *Help;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_about;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_aboutCMST;
    QPushButton *pushButton_aboutIconSet;
    QPushButton *pushButton_aboutOtherArt;
    QPushButton *pushButton_aboutQT;
    QPushButton *pushButton_license;
    QPushButton *pushButton_change_log;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_help;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_whatsthis;
    QPushButton *pushButton_provisioning_editor;
    QPushButton *pushButton_vpn_editor;
    QPushButton *pushButton_exit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_minimize;

    void setupUi(QDialog *ControlBox)
    {
        if (ControlBox->objectName().isEmpty())
            ControlBox->setObjectName(QString::fromUtf8("ControlBox"));
        ControlBox->resize(749, 644);
        ControlBox->setMinimumSize(QSize(530, 475));
        ControlBox->setSizeGripEnabled(true);
        actionMove_Before = new QAction(ControlBox);
        actionMove_Before->setObjectName(QString::fromUtf8("actionMove_Before"));
        actionMove_After = new QAction(ControlBox);
        actionMove_After->setObjectName(QString::fromUtf8("actionMove_After"));
        actionRescan = new QAction(ControlBox);
        actionRescan->setObjectName(QString::fromUtf8("actionRescan"));
        actionOffline_Mode = new QAction(ControlBox);
        actionOffline_Mode->setObjectName(QString::fromUtf8("actionOffline_Mode"));
        actionOffline_Mode->setCheckable(true);
        actionIDPass = new QAction(ControlBox);
        actionIDPass->setObjectName(QString::fromUtf8("actionIDPass"));
        verticalLayout_11 = new QVBoxLayout(ControlBox);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        tabWidget = new QTabWidget(ControlBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMovable(true);
        Status = new QWidget();
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(Status);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea_5 = new QScrollArea(Status);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 707, 466));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_7);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_global_properties = new QGroupBox(scrollAreaWidgetContents_7);
        groupBox_global_properties->setObjectName(QString::fromUtf8("groupBox_global_properties"));
        gridLayout_16 = new QGridLayout(groupBox_global_properties);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        label_offlinemode = new QLabel(groupBox_global_properties);
        label_offlinemode->setObjectName(QString::fromUtf8("label_offlinemode"));

        gridLayout_18->addWidget(label_offlinemode, 1, 1, 1, 1);

        label_state = new QLabel(groupBox_global_properties);
        label_state->setObjectName(QString::fromUtf8("label_state"));

        gridLayout_18->addWidget(label_state, 0, 1, 1, 1);

        checkBox_devicesoff = new QCheckBox(groupBox_global_properties);
        checkBox_devicesoff->setObjectName(QString::fromUtf8("checkBox_devicesoff"));

        gridLayout_18->addWidget(checkBox_devicesoff, 0, 2, 1, 1, Qt::AlignRight);

        label_state_pix = new QLabel(groupBox_global_properties);
        label_state_pix->setObjectName(QString::fromUtf8("label_state_pix"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_state_pix->sizePolicy().hasHeightForWidth());
        label_state_pix->setSizePolicy(sizePolicy1);
        label_state_pix->setMaximumSize(QSize(16, 16));
        label_state_pix->setScaledContents(true);

        gridLayout_18->addWidget(label_state_pix, 0, 0, 1, 1);

        toolButton_offlinemode = new QToolButton(groupBox_global_properties);
        toolButton_offlinemode->setObjectName(QString::fromUtf8("toolButton_offlinemode"));
        toolButton_offlinemode->setCheckable(true);

        gridLayout_18->addWidget(toolButton_offlinemode, 1, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_18, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_global_properties, 0, 0, 1, 1);

        splitter01 = new QSplitter(scrollAreaWidgetContents_7);
        splitter01->setObjectName(QString::fromUtf8("splitter01"));
        splitter01->setOrientation(Qt::Vertical);
        splitter01->setHandleWidth(5);
        groupBox_technologies = new QGroupBox(splitter01);
        groupBox_technologies->setObjectName(QString::fromUtf8("groupBox_technologies"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_technologies->sizePolicy().hasHeightForWidth());
        groupBox_technologies->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(groupBox_technologies);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_technologies = new QTableWidget(groupBox_technologies);
        if (tableWidget_technologies->columnCount() < 6)
            tableWidget_technologies->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_technologies->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_technologies->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_technologies->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_technologies->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_technologies->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_technologies->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_technologies->setObjectName(QString::fromUtf8("tableWidget_technologies"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget_technologies->sizePolicy().hasHeightForWidth());
        tableWidget_technologies->setSizePolicy(sizePolicy3);
        tableWidget_technologies->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_technologies->setProperty("showDropIndicator", QVariant(false));
        tableWidget_technologies->setDragDropOverwriteMode(false);
        tableWidget_technologies->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_technologies->setShowGrid(false);
        tableWidget_technologies->setCornerButtonEnabled(false);
        tableWidget_technologies->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_technologies->horizontalHeader()->setMinimumSectionSize(75);
        tableWidget_technologies->horizontalHeader()->setHighlightSections(false);
        tableWidget_technologies->horizontalHeader()->setStretchLastSection(true);
        tableWidget_technologies->verticalHeader()->setVisible(false);
        tableWidget_technologies->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(tableWidget_technologies);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_rescanwifi01 = new QPushButton(groupBox_technologies);
        pushButton_rescanwifi01->setObjectName(QString::fromUtf8("pushButton_rescanwifi01"));

        horizontalLayout_5->addWidget(pushButton_rescanwifi01);

        horizontalSpacer = new QSpacerItem(293, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_IDPass = new QPushButton(groupBox_technologies);
        pushButton_IDPass->setObjectName(QString::fromUtf8("pushButton_IDPass"));

        horizontalLayout_5->addWidget(pushButton_IDPass);

        checkBox_hidetethering = new QCheckBox(groupBox_technologies);
        checkBox_hidetethering->setObjectName(QString::fromUtf8("checkBox_hidetethering"));

        horizontalLayout_5->addWidget(checkBox_hidetethering);


        verticalLayout_3->addLayout(horizontalLayout_5);

        splitter01->addWidget(groupBox_technologies);
        groupBox_services = new QGroupBox(splitter01);
        groupBox_services->setObjectName(QString::fromUtf8("groupBox_services"));
        sizePolicy2.setHeightForWidth(groupBox_services->sizePolicy().hasHeightForWidth());
        groupBox_services->setSizePolicy(sizePolicy2);
        verticalLayout_6 = new QVBoxLayout(groupBox_services);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tableWidget_services = new QTableWidget(groupBox_services);
        if (tableWidget_services->columnCount() < 4)
            tableWidget_services->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        tableWidget_services->setObjectName(QString::fromUtf8("tableWidget_services"));
        sizePolicy3.setHeightForWidth(tableWidget_services->sizePolicy().hasHeightForWidth());
        tableWidget_services->setSizePolicy(sizePolicy3);
        tableWidget_services->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_services->setProperty("showDropIndicator", QVariant(false));
        tableWidget_services->setDragDropOverwriteMode(false);
        tableWidget_services->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_services->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_services->setShowGrid(false);
        tableWidget_services->setCornerButtonEnabled(false);
        tableWidget_services->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_services->horizontalHeader()->setMinimumSectionSize(75);
        tableWidget_services->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_services->horizontalHeader()->setStretchLastSection(true);
        tableWidget_services->verticalHeader()->setVisible(false);
        tableWidget_services->verticalHeader()->setHighlightSections(false);

        verticalLayout_6->addWidget(tableWidget_services);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_movebefore = new QPushButton(groupBox_services);
        pushButton_movebefore->setObjectName(QString::fromUtf8("pushButton_movebefore"));
        pushButton_movebefore->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_movebefore);

        pushButton_moveafter = new QPushButton(groupBox_services);
        pushButton_moveafter->setObjectName(QString::fromUtf8("pushButton_moveafter"));
        pushButton_moveafter->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_moveafter);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        checkBox_hidecnxn = new QCheckBox(groupBox_services);
        checkBox_hidecnxn->setObjectName(QString::fromUtf8("checkBox_hidecnxn"));
        checkBox_hidecnxn->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_hidecnxn);


        verticalLayout_6->addLayout(horizontalLayout_3);

        splitter01->addWidget(groupBox_services);

        gridLayout_2->addWidget(splitter01, 1, 0, 1, 1);

        scrollArea_5->setWidget(scrollAreaWidgetContents_7);

        gridLayout_3->addWidget(scrollArea_5, 2, 0, 1, 1);

        tabWidget->addTab(Status, QString());
        Details = new QWidget();
        Details->setObjectName(QString::fromUtf8("Details"));
        verticalLayout_2 = new QVBoxLayout(Details);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_service = new QLabel(Details);
        label_service->setObjectName(QString::fromUtf8("label_service"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_service->setFont(font);

        verticalLayout_2->addWidget(label_service);

        comboBox_service = new QComboBox(Details);
        comboBox_service->setObjectName(QString::fromUtf8("comboBox_service"));

        verticalLayout_2->addWidget(comboBox_service);

        scrollArea_2 = new QScrollArea(Details);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 707, 385));
        _2 = new QVBoxLayout(scrollAreaWidgetContents_5);
        _2->setObjectName(QString::fromUtf8("_2"));
        label_details_connection = new QLabel(scrollAreaWidgetContents_5);
        label_details_connection->setObjectName(QString::fromUtf8("label_details_connection"));
        sizePolicy.setHeightForWidth(label_details_connection->sizePolicy().hasHeightForWidth());
        label_details_connection->setSizePolicy(sizePolicy);
        label_details_connection->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        _2->addWidget(label_details_connection);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_details_left = new QLabel(scrollAreaWidgetContents_5);
        label_details_left->setObjectName(QString::fromUtf8("label_details_left"));
        label_details_left->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_details_left);

        label_details_right = new QLabel(scrollAreaWidgetContents_5);
        label_details_right->setObjectName(QString::fromUtf8("label_details_right"));
        label_details_right->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_details_right);


        _2->addLayout(horizontalLayout_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _2->addItem(verticalSpacer_6);

        scrollArea_2->setWidget(scrollAreaWidgetContents_5);

        verticalLayout_2->addWidget(scrollArea_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        pushButton_configuration = new QPushButton(Details);
        pushButton_configuration->setObjectName(QString::fromUtf8("pushButton_configuration"));

        horizontalLayout_6->addWidget(pushButton_configuration);


        verticalLayout_2->addLayout(horizontalLayout_6);

        tabWidget->addTab(Details, QString());
        Wireless = new QWidget();
        Wireless->setObjectName(QString::fromUtf8("Wireless"));
        gridLayout_5 = new QGridLayout(Wireless);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidget_wifi = new QTableWidget(Wireless);
        if (tableWidget_wifi->columnCount() < 5)
            tableWidget_wifi->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        tableWidget_wifi->setObjectName(QString::fromUtf8("tableWidget_wifi"));
        tableWidget_wifi->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_wifi->setProperty("showDropIndicator", QVariant(false));
        tableWidget_wifi->setDragDropOverwriteMode(false);
        tableWidget_wifi->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_wifi->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_wifi->setShowGrid(false);
        tableWidget_wifi->setCornerButtonEnabled(false);
        tableWidget_wifi->setColumnCount(5);
        tableWidget_wifi->horizontalHeader()->setMinimumSectionSize(80);
        tableWidget_wifi->horizontalHeader()->setStretchLastSection(true);
        tableWidget_wifi->verticalHeader()->setVisible(false);
        tableWidget_wifi->verticalHeader()->setHighlightSections(false);

        gridLayout_5->addWidget(tableWidget_wifi, 2, 0, 1, 1);

        groupBox_wireless_utils = new QGroupBox(Wireless);
        groupBox_wireless_utils->setObjectName(QString::fromUtf8("groupBox_wireless_utils"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_wireless_utils);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_connect = new QPushButton(groupBox_wireless_utils);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout_2->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(groupBox_wireless_utils);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));

        horizontalLayout_2->addWidget(pushButton_disconnect);

        pushButton_remove = new QPushButton(groupBox_wireless_utils);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));

        horizontalLayout_2->addWidget(pushButton_remove);

        pushButton_rescanwifi02 = new QPushButton(groupBox_wireless_utils);
        pushButton_rescanwifi02->setObjectName(QString::fromUtf8("pushButton_rescanwifi02"));

        horizontalLayout_2->addWidget(pushButton_rescanwifi02);

        label_wifi_state = new QLabel(groupBox_wireless_utils);
        label_wifi_state->setObjectName(QString::fromUtf8("label_wifi_state"));
        sizePolicy.setHeightForWidth(label_wifi_state->sizePolicy().hasHeightForWidth());
        label_wifi_state->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_wifi_state);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout_5->addWidget(groupBox_wireless_utils, 1, 0, 1, 1);

        tabWidget->addTab(Wireless, QString());
        VPN = new QWidget();
        VPN->setObjectName(QString::fromUtf8("VPN"));
        gridLayout_13 = new QGridLayout(VPN);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        groupBox_vpn_utils = new QGroupBox(VPN);
        groupBox_vpn_utils->setObjectName(QString::fromUtf8("groupBox_vpn_utils"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_vpn_utils);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_vpn_connect = new QPushButton(groupBox_vpn_utils);
        pushButton_vpn_connect->setObjectName(QString::fromUtf8("pushButton_vpn_connect"));
        pushButton_vpn_connect->setEnabled(true);

        horizontalLayout_9->addWidget(pushButton_vpn_connect);

        pushButton_vpn_disconnect = new QPushButton(groupBox_vpn_utils);
        pushButton_vpn_disconnect->setObjectName(QString::fromUtf8("pushButton_vpn_disconnect"));
        pushButton_vpn_disconnect->setEnabled(true);

        horizontalLayout_9->addWidget(pushButton_vpn_disconnect);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);


        gridLayout_13->addWidget(groupBox_vpn_utils, 0, 0, 1, 1);

        tableWidget_vpn = new QTableWidget(VPN);
        if (tableWidget_vpn->columnCount() < 5)
            tableWidget_vpn->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_vpn->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_vpn->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_vpn->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_vpn->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_vpn->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        tableWidget_vpn->setObjectName(QString::fromUtf8("tableWidget_vpn"));
        tableWidget_vpn->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_vpn->setProperty("showDropIndicator", QVariant(false));
        tableWidget_vpn->setDragDropOverwriteMode(false);
        tableWidget_vpn->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_vpn->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_vpn->setShowGrid(false);
        tableWidget_vpn->setCornerButtonEnabled(false);
        tableWidget_vpn->setColumnCount(5);
        tableWidget_vpn->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_vpn->horizontalHeader()->setMinimumSectionSize(80);
        tableWidget_vpn->horizontalHeader()->setStretchLastSection(true);
        tableWidget_vpn->verticalHeader()->setVisible(false);
        tableWidget_vpn->verticalHeader()->setHighlightSections(false);

        gridLayout_13->addWidget(tableWidget_vpn, 3, 0, 1, 1);

        tabWidget->addTab(VPN, QString());
        Counters = new QWidget();
        Counters->setObjectName(QString::fromUtf8("Counters"));
        gridLayout_15 = new QGridLayout(Counters);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        scrollArea_4 = new QScrollArea(Counters);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 707, 466));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_counter_service_name = new QLabel(scrollAreaWidgetContents_6);
        label_counter_service_name->setObjectName(QString::fromUtf8("label_counter_service_name"));

        gridLayout_7->addWidget(label_counter_service_name, 0, 0, 1, 1);

        groupBox_home_counter = new QGroupBox(scrollAreaWidgetContents_6);
        groupBox_home_counter->setObjectName(QString::fromUtf8("groupBox_home_counter"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(groupBox_home_counter->sizePolicy().hasHeightForWidth());
        groupBox_home_counter->setSizePolicy(sizePolicy4);
        verticalLayout_4 = new QVBoxLayout(groupBox_home_counter);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea_home_counter = new QScrollArea(groupBox_home_counter);
        scrollArea_home_counter->setObjectName(QString::fromUtf8("scrollArea_home_counter"));
        scrollArea_home_counter->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 663, 156));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_home_counter = new QLabel(scrollAreaWidgetContents_2);
        label_home_counter->setObjectName(QString::fromUtf8("label_home_counter"));
        sizePolicy.setHeightForWidth(label_home_counter->sizePolicy().hasHeightForWidth());
        label_home_counter->setSizePolicy(sizePolicy);
        label_home_counter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_home_counter->setWordWrap(true);

        verticalLayout_9->addWidget(label_home_counter);

        scrollArea_home_counter->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(scrollArea_home_counter);


        gridLayout_7->addWidget(groupBox_home_counter, 1, 0, 1, 1);

        groupBox_roaming_counter = new QGroupBox(scrollAreaWidgetContents_6);
        groupBox_roaming_counter->setObjectName(QString::fromUtf8("groupBox_roaming_counter"));
        sizePolicy4.setHeightForWidth(groupBox_roaming_counter->sizePolicy().hasHeightForWidth());
        groupBox_roaming_counter->setSizePolicy(sizePolicy4);
        verticalLayout_5 = new QVBoxLayout(groupBox_roaming_counter);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        scrollArea_roaming_counter = new QScrollArea(groupBox_roaming_counter);
        scrollArea_roaming_counter->setObjectName(QString::fromUtf8("scrollArea_roaming_counter"));
        scrollArea_roaming_counter->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 663, 156));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_roam_counter = new QLabel(scrollAreaWidgetContents_3);
        label_roam_counter->setObjectName(QString::fromUtf8("label_roam_counter"));
        sizePolicy.setHeightForWidth(label_roam_counter->sizePolicy().hasHeightForWidth());
        label_roam_counter->setSizePolicy(sizePolicy);
        label_roam_counter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_roam_counter->setWordWrap(true);

        verticalLayout_10->addWidget(label_roam_counter);

        scrollArea_roaming_counter->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_5->addWidget(scrollArea_roaming_counter);


        gridLayout_7->addWidget(groupBox_roaming_counter, 2, 0, 1, 1);

        label_counter_settings = new QLabel(scrollAreaWidgetContents_6);
        label_counter_settings->setObjectName(QString::fromUtf8("label_counter_settings"));
        label_counter_settings->setWordWrap(true);

        gridLayout_7->addWidget(label_counter_settings, 3, 0, 1, 1);

        scrollArea_4->setWidget(scrollAreaWidgetContents_6);

        gridLayout_15->addWidget(scrollArea_4, 0, 0, 1, 1);

        tabWidget->addTab(Counters, QString());
        Preferences = new QWidget();
        Preferences->setObjectName(QString::fromUtf8("Preferences"));
        gridLayout_14 = new QGridLayout(Preferences);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        scrollArea_3 = new QScrollArea(Preferences);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 693, 740));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_programcontrol = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_programcontrol->setObjectName(QString::fromUtf8("groupBox_programcontrol"));
        gridLayout_10 = new QGridLayout(groupBox_programcontrol);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        checkBox_retryfailed = new QCheckBox(groupBox_programcontrol);
        checkBox_retryfailed->setObjectName(QString::fromUtf8("checkBox_retryfailed"));

        gridLayout_10->addWidget(checkBox_retryfailed, 0, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_3, 3, 0, 1, 2);

        checkBox_runonstartup = new QCheckBox(groupBox_programcontrol);
        checkBox_runonstartup->setObjectName(QString::fromUtf8("checkBox_runonstartup"));

        gridLayout_10->addWidget(checkBox_runonstartup, 1, 0, 1, 2);

        checkBox_killswitch = new QCheckBox(groupBox_programcontrol);
        checkBox_killswitch->setObjectName(QString::fromUtf8("checkBox_killswitch"));

        gridLayout_10->addWidget(checkBox_killswitch, 2, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_programcontrol, 3, 0, 1, 1);

        groupBox_notifications = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_notifications->setObjectName(QString::fromUtf8("groupBox_notifications"));
        groupBox_notifications->setEnabled(true);
        gridLayout_17 = new QGridLayout(groupBox_notifications);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_serverstatus = new QLabel(groupBox_notifications);
        label_serverstatus->setObjectName(QString::fromUtf8("label_serverstatus"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_serverstatus->sizePolicy().hasHeightForWidth());
        label_serverstatus->setSizePolicy(sizePolicy5);
        label_serverstatus->setWordWrap(true);

        gridLayout_17->addWidget(label_serverstatus, 0, 1, 1, 1);

        checkBox_notifydaemon = new QCheckBox(groupBox_notifications);
        checkBox_notifydaemon->setObjectName(QString::fromUtf8("checkBox_notifydaemon"));
        checkBox_notifydaemon->setEnabled(true);

        gridLayout_17->addWidget(checkBox_notifydaemon, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_notifications, 2, 0, 1, 1);

        groupBox_preferencesinterface = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_preferencesinterface->setObjectName(QString::fromUtf8("groupBox_preferencesinterface"));
        gridLayout_12 = new QGridLayout(groupBox_preferencesinterface);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        checkBox_resetcounters = new QCheckBox(groupBox_preferencesinterface);
        checkBox_resetcounters->setObjectName(QString::fromUtf8("checkBox_resetcounters"));
        checkBox_resetcounters->setEnabled(true);

        gridLayout_12->addWidget(checkBox_resetcounters, 3, 0, 1, 2);

        checkBox_advanced = new QCheckBox(groupBox_preferencesinterface);
        checkBox_advanced->setObjectName(QString::fromUtf8("checkBox_advanced"));
        checkBox_advanced->setChecked(false);

        gridLayout_12->addWidget(checkBox_advanced, 4, 0, 1, 2);

        checkBox_usestartoptions = new QCheckBox(groupBox_preferencesinterface);
        checkBox_usestartoptions->setObjectName(QString::fromUtf8("checkBox_usestartoptions"));
        checkBox_usestartoptions->setEnabled(true);
        checkBox_usestartoptions->setChecked(true);

        gridLayout_12->addWidget(checkBox_usestartoptions, 0, 0, 1, 2);

        checkBox_retainstate = new QCheckBox(groupBox_preferencesinterface);
        checkBox_retainstate->setObjectName(QString::fromUtf8("checkBox_retainstate"));

        gridLayout_12->addWidget(checkBox_retainstate, 1, 0, 1, 2);

        checkBox_enableinterfacetooltips = new QCheckBox(groupBox_preferencesinterface);
        checkBox_enableinterfacetooltips->setObjectName(QString::fromUtf8("checkBox_enableinterfacetooltips"));

        gridLayout_12->addWidget(checkBox_enableinterfacetooltips, 2, 0, 1, 2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit_colorize = new QLineEdit(groupBox_preferencesinterface);
        lineEdit_colorize->setObjectName(QString::fromUtf8("lineEdit_colorize"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lineEdit_colorize->sizePolicy().hasHeightForWidth());
        lineEdit_colorize->setSizePolicy(sizePolicy6);
        lineEdit_colorize->setClearButtonEnabled(true);

        horizontalLayout_8->addWidget(lineEdit_colorize);

        toolButton_colorize = new QToolButton(groupBox_preferencesinterface);
        toolButton_colorize->setObjectName(QString::fromUtf8("toolButton_colorize"));
        toolButton_colorize->setArrowType(Qt::UpArrow);

        horizontalLayout_8->addWidget(toolButton_colorize);

        label_2 = new QLabel(groupBox_preferencesinterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);


        gridLayout_12->addLayout(horizontalLayout_8, 5, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_preferencesinterface, 0, 0, 1, 1);

        groupBox_systemtray = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_systemtray->setObjectName(QString::fromUtf8("groupBox_systemtray"));
        gridLayout = new QGridLayout(groupBox_systemtray);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_enablesystemtraytooltips = new QCheckBox(groupBox_systemtray);
        checkBox_enablesystemtraytooltips->setObjectName(QString::fromUtf8("checkBox_enablesystemtraytooltips"));
        checkBox_enablesystemtraytooltips->setChecked(true);

        gridLayout->addWidget(checkBox_enablesystemtraytooltips, 1, 0, 1, 1);

        checkBox_hideIcon = new QCheckBox(groupBox_systemtray);
        checkBox_hideIcon->setObjectName(QString::fromUtf8("checkBox_hideIcon"));

        gridLayout->addWidget(checkBox_hideIcon, 0, 0, 1, 1);

        checkBox_systemtraynotifications = new QCheckBox(groupBox_systemtray);
        checkBox_systemtraynotifications->setObjectName(QString::fromUtf8("checkBox_systemtraynotifications"));
        checkBox_systemtraynotifications->setEnabled(true);

        gridLayout->addWidget(checkBox_systemtraynotifications, 2, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_systemtray, 1, 0, 1, 1);

        groupBox_startoptions = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_startoptions->setObjectName(QString::fromUtf8("groupBox_startoptions"));
        groupBox_startoptions->setEnabled(true);
        gridLayout_9 = new QGridLayout(groupBox_startoptions);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        spinBox_faketransparency = new QSpinBox(groupBox_startoptions);
        spinBox_faketransparency->setObjectName(QString::fromUtf8("spinBox_faketransparency"));
        spinBox_faketransparency->setEnabled(false);
        spinBox_faketransparency->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_faketransparency->setAccelerated(true);
        spinBox_faketransparency->setMaximum(16777215);
        spinBox_faketransparency->setDisplayIntegerBase(16);

        gridLayout_9->addWidget(spinBox_faketransparency, 10, 1, 1, 1);

        lineEdit_icontheme = new QLineEdit(groupBox_startoptions);
        lineEdit_icontheme->setObjectName(QString::fromUtf8("lineEdit_icontheme"));
        lineEdit_icontheme->setEnabled(false);
        lineEdit_icontheme->setClearButtonEnabled(true);

        gridLayout_9->addWidget(lineEdit_icontheme, 3, 1, 1, 1);

        checkBox_enablecounters = new QCheckBox(groupBox_startoptions);
        checkBox_enablecounters->setObjectName(QString::fromUtf8("checkBox_enablecounters"));

        gridLayout_9->addWidget(checkBox_enablecounters, 0, 0, 1, 1);

        checkBox_disabletrayicon = new QCheckBox(groupBox_startoptions);
        checkBox_disabletrayicon->setObjectName(QString::fromUtf8("checkBox_disabletrayicon"));

        gridLayout_9->addWidget(checkBox_disabletrayicon, 1, 0, 1, 1);

        spinBox_counterkb = new QSpinBox(groupBox_startoptions);
        spinBox_counterkb->setObjectName(QString::fromUtf8("spinBox_counterkb"));
        spinBox_counterkb->setEnabled(false);
        spinBox_counterkb->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_counterkb->setMinimum(256);
        spinBox_counterkb->setMaximum(32768);
        spinBox_counterkb->setSingleStep(64);
        spinBox_counterkb->setValue(1024);

        gridLayout_9->addWidget(spinBox_counterkb, 8, 1, 1, 1);

        checkBox_startminimized = new QCheckBox(groupBox_startoptions);
        checkBox_startminimized->setObjectName(QString::fromUtf8("checkBox_startminimized"));

        gridLayout_9->addWidget(checkBox_startminimized, 4, 0, 1, 1);

        checkBox_faketranparency = new QCheckBox(groupBox_startoptions);
        checkBox_faketranparency->setObjectName(QString::fromUtf8("checkBox_faketranparency"));

        gridLayout_9->addWidget(checkBox_faketranparency, 10, 0, 1, 1);

        checkBox_waittime = new QCheckBox(groupBox_startoptions);
        checkBox_waittime->setObjectName(QString::fromUtf8("checkBox_waittime"));

        gridLayout_9->addWidget(checkBox_waittime, 7, 0, 1, 1);

        checkBox_systemicontheme = new QCheckBox(groupBox_startoptions);
        checkBox_systemicontheme->setObjectName(QString::fromUtf8("checkBox_systemicontheme"));

        gridLayout_9->addWidget(checkBox_systemicontheme, 3, 0, 1, 1);

        spinBox_counterrate = new QSpinBox(groupBox_startoptions);
        spinBox_counterrate->setObjectName(QString::fromUtf8("spinBox_counterrate"));
        spinBox_counterrate->setEnabled(false);
        spinBox_counterrate->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_counterrate->setMinimum(5);
        spinBox_counterrate->setMaximum(86400);
        spinBox_counterrate->setSingleStep(10);
        spinBox_counterrate->setValue(10);

        gridLayout_9->addWidget(spinBox_counterrate, 9, 1, 1, 1);

        checkBox_counterkb = new QCheckBox(groupBox_startoptions);
        checkBox_counterkb->setObjectName(QString::fromUtf8("checkBox_counterkb"));
        checkBox_counterkb->setEnabled(false);

        gridLayout_9->addWidget(checkBox_counterkb, 8, 0, 1, 1);

        checkBox_disableminimized = new QCheckBox(groupBox_startoptions);
        checkBox_disableminimized->setObjectName(QString::fromUtf8("checkBox_disableminimized"));

        gridLayout_9->addWidget(checkBox_disableminimized, 5, 0, 1, 1);

        checkBox_disablevpn = new QCheckBox(groupBox_startoptions);
        checkBox_disablevpn->setObjectName(QString::fromUtf8("checkBox_disablevpn"));

        gridLayout_9->addWidget(checkBox_disablevpn, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_startoptions);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        radioButton_desktopnone = new QRadioButton(groupBox_2);
        radioButton_desktopnone->setObjectName(QString::fromUtf8("radioButton_desktopnone"));
        radioButton_desktopnone->setChecked(true);

        verticalLayout_12->addWidget(radioButton_desktopnone);

        radioButton_desktopxfce = new QRadioButton(groupBox_2);
        radioButton_desktopxfce->setObjectName(QString::fromUtf8("radioButton_desktopxfce"));

        verticalLayout_12->addWidget(radioButton_desktopxfce);

        radioButton_desktopmate = new QRadioButton(groupBox_2);
        radioButton_desktopmate->setObjectName(QString::fromUtf8("radioButton_desktopmate"));

        verticalLayout_12->addWidget(radioButton_desktopmate);


        gridLayout_9->addWidget(groupBox_2, 11, 0, 1, 2);

        spinBox_waittime = new QSpinBox(groupBox_startoptions);
        spinBox_waittime->setObjectName(QString::fromUtf8("spinBox_waittime"));
        spinBox_waittime->setEnabled(false);
        spinBox_waittime->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_waittime->setMinimum(1);
        spinBox_waittime->setMaximum(60);

        gridLayout_9->addWidget(spinBox_waittime, 7, 1, 1, 1);

        checkBox_counterseconds = new QCheckBox(groupBox_startoptions);
        checkBox_counterseconds->setObjectName(QString::fromUtf8("checkBox_counterseconds"));

        gridLayout_9->addWidget(checkBox_counterseconds, 9, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_startoptions, 0, 1, 3, 1);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        groupBox_process = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_process->setObjectName(QString::fromUtf8("groupBox_process"));
        gridLayout_11 = new QGridLayout(groupBox_process);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox = new QGroupBox(groupBox_process);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_beforeconnect = new QLineEdit(groupBox);
        lineEdit_beforeconnect->setObjectName(QString::fromUtf8("lineEdit_beforeconnect"));
        sizePolicy6.setHeightForWidth(lineEdit_beforeconnect->sizePolicy().hasHeightForWidth());
        lineEdit_beforeconnect->setSizePolicy(sizePolicy6);

        gridLayout_4->addWidget(lineEdit_beforeconnect, 1, 1, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        comboBox_beforeconnectserviceslist = new QComboBox(groupBox);
        comboBox_beforeconnectserviceslist->setObjectName(QString::fromUtf8("comboBox_beforeconnectserviceslist"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(comboBox_beforeconnectserviceslist->sizePolicy().hasHeightForWidth());
        comboBox_beforeconnectserviceslist->setSizePolicy(sizePolicy7);

        gridLayout_4->addWidget(comboBox_beforeconnectserviceslist, 0, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        checkBox_modifyservicefile = new QCheckBox(groupBox);
        checkBox_modifyservicefile->setObjectName(QString::fromUtf8("checkBox_modifyservicefile"));

        verticalLayout_13->addWidget(checkBox_modifyservicefile);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        comboBox_beforeconnectservicefile = new QComboBox(groupBox);
        comboBox_beforeconnectservicefile->setObjectName(QString::fromUtf8("comboBox_beforeconnectservicefile"));
        comboBox_beforeconnectservicefile->setEnabled(false);
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(comboBox_beforeconnectservicefile->sizePolicy().hasHeightForWidth());
        comboBox_beforeconnectservicefile->setSizePolicy(sizePolicy8);

        horizontalLayout_10->addWidget(comboBox_beforeconnectservicefile);


        verticalLayout_13->addLayout(horizontalLayout_10);


        gridLayout_4->addLayout(verticalLayout_13, 2, 0, 1, 3);


        gridLayout_11->addWidget(groupBox, 0, 0, 1, 2);

        label = new QLabel(groupBox_process);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_11->addWidget(label, 1, 0, 1, 1);

        lineEdit_afterconnect = new QLineEdit(groupBox_process);
        lineEdit_afterconnect->setObjectName(QString::fromUtf8("lineEdit_afterconnect"));
        lineEdit_afterconnect->setClearButtonEnabled(true);

        gridLayout_11->addWidget(lineEdit_afterconnect, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer, 2, 0, 1, 2);


        verticalLayout_14->addWidget(groupBox_process);


        gridLayout_8->addLayout(verticalLayout_14, 3, 1, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_4);

        gridLayout_14->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(Preferences, QString());
        Help = new QWidget();
        Help->setObjectName(QString::fromUtf8("Help"));
        gridLayout_6 = new QGridLayout(Help);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_about = new QGroupBox(Help);
        groupBox_about->setObjectName(QString::fromUtf8("groupBox_about"));
        verticalLayout = new QVBoxLayout(groupBox_about);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_aboutCMST = new QPushButton(groupBox_about);
        pushButton_aboutCMST->setObjectName(QString::fromUtf8("pushButton_aboutCMST"));

        verticalLayout->addWidget(pushButton_aboutCMST);

        pushButton_aboutIconSet = new QPushButton(groupBox_about);
        pushButton_aboutIconSet->setObjectName(QString::fromUtf8("pushButton_aboutIconSet"));

        verticalLayout->addWidget(pushButton_aboutIconSet);

        pushButton_aboutOtherArt = new QPushButton(groupBox_about);
        pushButton_aboutOtherArt->setObjectName(QString::fromUtf8("pushButton_aboutOtherArt"));

        verticalLayout->addWidget(pushButton_aboutOtherArt);

        pushButton_aboutQT = new QPushButton(groupBox_about);
        pushButton_aboutQT->setObjectName(QString::fromUtf8("pushButton_aboutQT"));

        verticalLayout->addWidget(pushButton_aboutQT);

        pushButton_license = new QPushButton(groupBox_about);
        pushButton_license->setObjectName(QString::fromUtf8("pushButton_license"));

        verticalLayout->addWidget(pushButton_license);

        pushButton_change_log = new QPushButton(groupBox_about);
        pushButton_change_log->setObjectName(QString::fromUtf8("pushButton_change_log"));

        verticalLayout->addWidget(pushButton_change_log);

        verticalSpacer_2 = new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout_6->addWidget(groupBox_about, 0, 0, 1, 1);

        scrollArea = new QScrollArea(Help);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 597, 466));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_help = new QLabel(scrollAreaWidgetContents);
        label_help->setObjectName(QString::fromUtf8("label_help"));
        label_help->setWordWrap(true);
        label_help->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout_8->addWidget(label_help);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_6->addWidget(scrollArea, 0, 1, 1, 1);

        tabWidget->addTab(Help, QString());

        verticalLayout_11->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_whatsthis = new QToolButton(ControlBox);
        toolButton_whatsthis->setObjectName(QString::fromUtf8("toolButton_whatsthis"));

        horizontalLayout->addWidget(toolButton_whatsthis);

        pushButton_provisioning_editor = new QPushButton(ControlBox);
        pushButton_provisioning_editor->setObjectName(QString::fromUtf8("pushButton_provisioning_editor"));

        horizontalLayout->addWidget(pushButton_provisioning_editor);

        pushButton_vpn_editor = new QPushButton(ControlBox);
        pushButton_vpn_editor->setObjectName(QString::fromUtf8("pushButton_vpn_editor"));

        horizontalLayout->addWidget(pushButton_vpn_editor);

        pushButton_exit = new QPushButton(ControlBox);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        horizontalLayout->addWidget(pushButton_exit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_minimize = new QPushButton(ControlBox);
        pushButton_minimize->setObjectName(QString::fromUtf8("pushButton_minimize"));

        horizontalLayout->addWidget(pushButton_minimize);


        verticalLayout_11->addLayout(horizontalLayout);

#if QT_CONFIG(shortcut)
        label_service->setBuddy(comboBox_service);
        label_4->setBuddy(lineEdit_beforeconnect);
        label_3->setBuddy(comboBox_beforeconnectserviceslist);
        label_5->setBuddy(comboBox_beforeconnectservicefile);
        label->setBuddy(lineEdit_afterconnect);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(tabWidget, comboBox_service);
        QWidget::setTabOrder(comboBox_service, pushButton_connect);
        QWidget::setTabOrder(pushButton_connect, pushButton_disconnect);
        QWidget::setTabOrder(pushButton_disconnect, pushButton_remove);
        QWidget::setTabOrder(pushButton_remove, tableWidget_wifi);
        QWidget::setTabOrder(tableWidget_wifi, scrollArea_home_counter);
        QWidget::setTabOrder(scrollArea_home_counter, scrollArea_roaming_counter);
        QWidget::setTabOrder(scrollArea_roaming_counter, pushButton_aboutCMST);
        QWidget::setTabOrder(pushButton_aboutCMST, pushButton_aboutIconSet);
        QWidget::setTabOrder(pushButton_aboutIconSet, pushButton_aboutQT);
        QWidget::setTabOrder(pushButton_aboutQT, pushButton_license);
        QWidget::setTabOrder(pushButton_license, pushButton_change_log);
        QWidget::setTabOrder(pushButton_change_log, scrollArea);
        QWidget::setTabOrder(scrollArea, toolButton_whatsthis);
        QWidget::setTabOrder(toolButton_whatsthis, pushButton_exit);
        QWidget::setTabOrder(pushButton_exit, pushButton_minimize);

        retranslateUi(ControlBox);
        QObject::connect(checkBox_advanced, SIGNAL(clicked(bool)), pushButton_vpn_editor, SLOT(setVisible(bool)));
        QObject::connect(checkBox_advanced, SIGNAL(clicked(bool)), pushButton_provisioning_editor, SLOT(setVisible(bool)));
        QObject::connect(pushButton_rescanwifi01, SIGNAL(clicked()), actionRescan, SLOT(trigger()));
        QObject::connect(pushButton_movebefore, SIGNAL(clicked()), actionMove_Before, SLOT(trigger()));
        QObject::connect(pushButton_moveafter, SIGNAL(clicked()), actionMove_After, SLOT(trigger()));
        QObject::connect(checkBox_waittime, SIGNAL(toggled(bool)), spinBox_waittime, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_usestartoptions, SIGNAL(toggled(bool)), groupBox_startoptions, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_systemicontheme, SIGNAL(toggled(bool)), lineEdit_icontheme, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_faketranparency, SIGNAL(toggled(bool)), spinBox_faketransparency, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_counterkb, SIGNAL(clicked(bool)), spinBox_counterkb, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_counterseconds, SIGNAL(clicked(bool)), spinBox_counterrate, SLOT(setEnabled(bool)));
        QObject::connect(actionOffline_Mode, SIGNAL(triggered(bool)), checkBox_devicesoff, SLOT(setChecked(bool)));
        QObject::connect(pushButton_rescanwifi02, SIGNAL(clicked()), actionRescan, SLOT(trigger()));
        QObject::connect(actionOffline_Mode, SIGNAL(triggered(bool)), toolButton_offlinemode, SLOT(setChecked(bool)));
        QObject::connect(checkBox_devicesoff, SIGNAL(clicked(bool)), actionOffline_Mode, SLOT(trigger()));
        QObject::connect(toolButton_offlinemode, SIGNAL(clicked(bool)), actionOffline_Mode, SLOT(trigger()));
        QObject::connect(checkBox_modifyservicefile, SIGNAL(clicked(bool)), comboBox_beforeconnectservicefile, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_advanced, SIGNAL(clicked(bool)), groupBox_process, SLOT(setVisible(bool)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ControlBox);
    } // setupUi

    void retranslateUi(QDialog *ControlBox)
    {
        ControlBox->setWindowTitle(QCoreApplication::translate("ControlBox", "Dialog", nullptr));
        actionMove_Before->setText(QCoreApplication::translate("ControlBox", "Move Before", nullptr));
        actionMove_After->setText(QCoreApplication::translate("ControlBox", "Move After", nullptr));
        actionRescan->setText(QCoreApplication::translate("ControlBox", "Rescan", nullptr));
        actionOffline_Mode->setText(QCoreApplication::translate("ControlBox", "Offline Mode", nullptr));
        actionIDPass->setText(QCoreApplication::translate("ControlBox", "IDPass", nullptr));
#if QT_CONFIG(tooltip)
        actionIDPass->setToolTip(QCoreApplication::translate("ControlBox", "Set ID and Password for tethered wifi", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        groupBox_global_properties->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p><span style=\" font-weight:600;\">OfflineMode</span></p><p>The offline mode indicates the global setting for switching all radios on or off. Changing offline mode to true results in powering down all devices. When leaving offline mode the individual policy of each device decides to switch the radio back on or not. </p><p>During offline mode, it is still possible to switch certain technologies manually back on. For example the limited usage of WiFi or Bluetooth devices might be allowed in some situations.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_global_properties->setTitle(QCoreApplication::translate("ControlBox", "Global Properties", nullptr));
#if QT_CONFIG(whatsthis)
        label_offlinemode->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>The global setting for switching all radios on or off. When offline mode is engaged all radios are powered down.</p><p>While in offline mode it is possible to turn individual devices back on. When leaving offline mode the individual policy of each device determines if the radio is turned back on or not.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_offlinemode->setText(QCoreApplication::translate("ControlBox", "OfflineMode: Unavailable", nullptr));
#if QT_CONFIG(whatsthis)
        label_state->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>The global connection state of the system.  Possible values are &quot;offline&quot;, &quot;idle&quot;, &quot;ready&quot;, and &quot;online&quot;.  </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_state->setText(QCoreApplication::translate("ControlBox", "State: Unavailable", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_devicesoff->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This checkbox controls the global setting for switching all radios on or off. When checked all radios are powered down.</p><p>When the system is In offline mode it is possible to turn individual devices back on. When leaving offline mode the individual policy of each device determines if the radio is turned back on or not.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_devicesoff->setText(QCoreApplication::translate("ControlBox", "All Devices &Off", nullptr));
        label_state_pix->setText(QString());
#if QT_CONFIG(whatsthis)
        toolButton_offlinemode->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>The global setting for switching all radios on or off. When offline mode is engaged all radios are powered down.</p><p>While in offline mode it is possible to turn individual devices back on. When leaving offline mode the individual policy of each device determines if the radio is turned back on or not.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolButton_offlinemode->setText(QCoreApplication::translate("ControlBox", "...", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_technologies->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Connman refers to hardware devices as technologies. This box will display information about all known technologies.</p><p>To turn a technology on or off click on the button that shows in the <span style=\" font-weight:600;\">Powered</span> column for the technology.</p><p>To tether a technology click the button in the <span style=\" font-weight:600;\">Tethering</span> column to on. When tethering is enabled the default service is bridged to all clients connected through the tethered technology. If the <span style=\" font-weight:600;\">Tethering</span> columns are not shown clear the check in <span style=\" font-weight:600;\">Less</span> checkbox below this window.</p><p>Note that by default wired connections cannot be tethered. This behavior can be overwritten in the connman.conf file. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_technologies->setTitle(QCoreApplication::translate("ControlBox", "Technologies", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_technologies->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ControlBox", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_technologies->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ControlBox", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_technologies->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ControlBox", "Powered", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_technologies->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ControlBox", "Connected", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_technologies->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ControlBox", "Tethering", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_technologies->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ControlBox", "ID:Password", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_rescanwifi01->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Force a rescan of all WiFi technologies. This is similar to issuing the command <span style=\" font-weight:600;\">connmanctl scan wifi</span> from the command line.</p><p>The button will become inactive while the scan is occuring.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_rescanwifi01->setText(QCoreApplication::translate("ControlBox", "Resc&an", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_IDPass->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>To edit the ID and Password of a tethered WiFi device click this button.</p><p>The ID and Password are what clients will have to enter to connect to the ad-hoc network. This is only valid for WiFi connections</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_IDPass->setText(QCoreApplication::translate("ControlBox", "ID:Pass", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_hidetethering->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>When checked the tethering columns will be hidden.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_hidetethering->setText(QCoreApplication::translate("ControlBox", "Less", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_services->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This box lists all services that connman can connect to.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_services->setTitle(QCoreApplication::translate("ControlBox", "Services", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_services->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ControlBox", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_services->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ControlBox", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_services->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ControlBox", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_services->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ControlBox", "Connection", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_movebefore->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Move the selected service before another in the list.</p><p>The button will only become active if the selected service can be moved and if there is another valid service which it can be used as a target.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_movebefore->setText(QCoreApplication::translate("ControlBox", "Move Before", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_moveafter->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Move the selected service after another in the list.</p><p>The button will only become active if the selected service can be moved and if there is another valid service which it can be used as a target.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_moveafter->setText(QCoreApplication::translate("ControlBox", "Move After", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_hidecnxn->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>When checked hide the connection name in the Services box.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_hidecnxn->setText(QCoreApplication::translate("ControlBox", "&Less", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Status), QCoreApplication::translate("ControlBox", "&Status", nullptr));
#if QT_CONFIG(whatsthis)
        Details->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This page will show the details of the service selected in the box at the top. If the selected service is not in the READY or ONLINE state then most of the details will be blank. </p><p>You may override service details by using the <span style=\" font-weight:600;\">Configuration</span> button at the bottom right. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_service->setText(QCoreApplication::translate("ControlBox", "Ser&vice", nullptr));
#if QT_CONFIG(whatsthis)
        comboBox_service->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Use this Combobox to select the service for which you wish to view the detailed information.<br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        scrollArea_2->setToolTip(QCoreApplication::translate("ControlBox", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_details_connection->setText(QString());
        label_details_left->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_configuration->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>The default configuration method for all services is automatic or something like DHCP. This should be good enough for most typical usage, but if it is not this button will allow manual configuration of Ethernet and IP settings for the selected Service.</p><p>This button will be disabled if the service is provisioned via an external config file or if the service is of type VPN. It is not possible to modify the properties of these services.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_configuration->setText(QCoreApplication::translate("ControlBox", "Configuration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Details), QCoreApplication::translate("ControlBox", "&Details", nullptr));
#if QT_CONFIG(whatsthis)
        Wireless->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_wifi->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ControlBox", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_wifi->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ControlBox", "Favorite", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_wifi->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ControlBox", "Connected", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_wifi->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ControlBox", "Security", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_wifi->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ControlBox", "Signal Strength", nullptr));
#if QT_CONFIG(whatsthis)
        tableWidget_wifi->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This page shows the known WiFi services. </p><p><span style=\" font-weight:600;\">Name:</span> The SSID of the network.</p><p><span style=\" font-weight:600;\">Favorite:</span> A heart symbol in this column indicates that this computer has previously made a connection to the network using this service.</p><p><span style=\" font-weight:600;\">Connected:</span> Shows the connection state of this service. Hover the mouse over the icon to popup a text description. Online signals that an Internet connectionis available and has been verified. Ready signals a successfully connected device. </p><p><span style=\" font-weight:600;\">Security: </span>Describes the type of security used for this service. Possible values are &quot;none&quot;, &quot;wep&quot;, &quot;psk&quot;, &quot;ieee8021x&quot;, and &quot;wps&quot;.</p><p><span style=\" font-weight:600;\">Signal Strength:</span> The strength of the WiFi signal, normalized to a scale of 0 to 100.</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_wireless_utils->setTitle(QCoreApplication::translate("ControlBox", "Wireless Services", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_connect->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Select a wifi service in the table below and press this button to connect the service. </p><p>If there is only one wifi service listed in the table pressing this button will automatically select that service and attempt to connect. </p><p>If information about the service is needed, a passphrase for instance, you will be prompted for it. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_connect->setText(QCoreApplication::translate("ControlBox", "Connect", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_disconnect->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Select a wifi service in the table below and press this button to disconnect it. </p><p>If there is only one wifi service in the &quot;ready&quot; or &quot;online&quot; state pressing this button will automatically select that service and disconnect it. </p><p>This may also be used to abort a previous connection attempt.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_disconnect->setText(QCoreApplication::translate("ControlBox", "Disconnect", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_remove->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Select a wifi service in the table below and press this button to remove the service. </p><p>If a service has previously been successfully connected (Favorite is true) this button will remove the Favorite property. The service will also be disconnected if it is currently connected. If the service required a passphrase then the passphrase it will be cleared and forgotten.</p><p>If a connection attempt failed this can slso be used to reset the service.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_remove->setText(QCoreApplication::translate("ControlBox", "Remove", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_rescanwifi02->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Force a rescan of all WiFi technologies. This is similar to issuing the command <span style=\" font-weight:600;\">connmanctl scan wifi</span> from the command line.</p><p>The button will become inactive while the scan is occuring.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_rescanwifi02->setText(QCoreApplication::translate("ControlBox", "Resc&an", nullptr));
#if QT_CONFIG(whatsthis)
        label_wifi_state->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This label shows the number of WiFi technologies (devices) that were found, and the number that are powered on. There must be at least one WiFi technology found and powered in order for the box below to show services.</p><p>To turn a technology on or off go to the <span style=\" font-weight:600;\">Technologies</span> box in the <span style=\" font-weight:600;\">Status</span> tab and double click on the text that shows in the <span style=\" font-weight:600;\">Powered</span> column for the technology.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_wifi_state->setText(QCoreApplication::translate("ControlBox", "Wifi State", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Wireless), QCoreApplication::translate("ControlBox", "&Wireless", nullptr));
#if QT_CONFIG(whatsthis)
        VPN->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_vpn_utils->setTitle(QCoreApplication::translate("ControlBox", "VPN Services", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_vpn_connect->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Select a vpn service in the table below and press this button to connect the service. </p><p>If there is only one vpn service listed in the table pressing this button will automatically select that service and attempt to connect. </p><p>If information about the service is needed, a passphrase for instance, you will be prompted for it. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_vpn_connect->setText(QCoreApplication::translate("ControlBox", "Connect", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_vpn_disconnect->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Select a vpn service in the table below and press this button to disconnect it. </p><p>If there is only one vpn service in the &quot;ready&quot; or &quot;online&quot; state pressing this button will automatically select that service and disconnect it. </p><p>This may also be used to abort a previous connection attempt.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_vpn_disconnect->setText(QCoreApplication::translate("ControlBox", "Disconnect", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_vpn->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ControlBox", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_vpn->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("ControlBox", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_vpn->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("ControlBox", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_vpn->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("ControlBox", "Host", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_vpn->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("ControlBox", "Connection", nullptr));
#if QT_CONFIG(whatsthis)
        tableWidget_vpn->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This page shows the provisioned VPN services. Some cells in the table may only be available once a connection is estlablished. </p><p><span style=\" font-weight:600;\">Name:</span> The name given in the provisioning file.</p><p><span style=\" font-weight:600;\">Type:</span> The VPN type (OpenConnect, OpenVPN, PPTP, etc)</p><p><span style=\" font-weight:600;\">State:</span> Shows the connection state of this service. Hover the mouse over the icon to popup a text description. </p><p><span style=\" font-weight:600;\">Host: </span>VPN Host IP.</p><p><span style=\" font-weight:600;\">Domain:</span> The VPN Domain.<br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(VPN), QCoreApplication::translate("ControlBox", "&VPN", nullptr));
#if QT_CONFIG(whatsthis)
        Counters->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        label_counter_service_name->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>The service being monitored by the counters.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_counter_service_name->setText(QCoreApplication::translate("ControlBox", "Service:", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_home_counter->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_home_counter->setTitle(QCoreApplication::translate("ControlBox", "Home", nullptr));
#if QT_CONFIG(whatsthis)
        label_home_counter->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Counters for the &quot;online&quot; service connection that is not marked roaming. </p><p>Counters may not always be available. The counters could have been disabled at the command line (-c or --disable-counters) or occasionally the connection will register &quot;ready&quot; instead of &quot;online&quot;. Online is a &quot;ready&quot; connection that has verified internet connectivity. It is possible to be online with only a &quot;ready&quot; connection, however the counters only work for they &quot;online&quot; connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_home_counter->setText(QCoreApplication::translate("ControlBox", "Counter not available.", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_roaming_counter->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Counters for the &quot;online&quot; service connection marked &quot;roaming&quot;.</p><p>In the case of cellular services this normally indicates connections to a foreign provider.</p><p>Counters may not always be available. The counters could have been disabled at the command line (-c or --disable-counters) or occasionally the connection will register &quot;ready&quot; instead of &quot;online&quot;. Online is a &quot;ready&quot; connection that has verified internet connectivity. It is possible to be online with only a &quot;ready&quot; connection, however the counters only work for they &quot;online&quot; connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_roaming_counter->setTitle(QCoreApplication::translate("ControlBox", "Roaming", nullptr));
        label_roam_counter->setText(QCoreApplication::translate("ControlBox", "Counter not available.", nullptr));
#if QT_CONFIG(tooltip)
        label_counter_settings->setToolTip(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Counter Settings</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label_counter_settings->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>The threshold values for counter updates (counter resolution).  Data and time work together to define how often the fields are updated.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_counter_settings->setText(QCoreApplication::translate("ControlBox", "Settings:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Counters), QCoreApplication::translate("ControlBox", "&Counters", nullptr));
        groupBox_programcontrol->setTitle(QCoreApplication::translate("ControlBox", "Program Control", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_retryfailed->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If a Connman service falls into the &quot;Failed&quot; state it will normally remain in that state.</p><p>If this box is checked CMST will try to automatically reconnect a WiFi service that enters the &quot;Failed&quot; state. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_retryfailed->setText(QCoreApplication::translate("ControlBox", "Retry Failed Connection", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_runonstartup->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked CMST will place an entry in the autostart directory for the current user, unchecking will remove said entry. This directory is typically: <span style=\" font-weight:600;\">${HOME}/.config/autostart</span>. </p><p>CMST only add or remove the .desktop file from the autostart directory. Autostarting is typically dependent upon your Desktop Environment and must be enabled from there.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_runonstartup->setText(QCoreApplication::translate("ControlBox", "Enable Autostart", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_killswitch->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked CMST will implement an internet kill switch for VPN connections. If a VPN connection drops while the kill switch is enabled all technologies will be powered off.</p><p>The way this works is the service order is monitored. If the topmost service is of type VPN and then if it changes to something other than VPN and if the change was not initiated by the user (for instance by using the <span style=\" font-weight:600;\">Disconnect</span> button in the VPN tab), then CMST will cycle through all technologies powering each one down in turn. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_killswitch->setText(QCoreApplication::translate("ControlBox", "Enable VPN Internet Kill Switch", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_notifications->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the system notification daemon will popup a notify message when a significant connman related event is received.</p><p>Notifications can be handled by the System Tray Icon, or by a Notify daemon if one is installed. Both can not be active at the same time.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_notifications->setTitle(QCoreApplication::translate("ControlBox", "Notifications", nullptr));
        label_serverstatus->setText(QCoreApplication::translate("ControlBox", "Server Status", nullptr));
        checkBox_notifydaemon->setText(QCoreApplication::translate("ControlBox", "Notification Daemon", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_preferencesinterface->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Preferences for the interface are in this box.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_preferencesinterface->setTitle(QCoreApplication::translate("ControlBox", "Interface", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_resetcounters->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Normally counters are cumulative and will retain the connect time and the TX and RX counts between boots. </p><p>When this box is checked the counters will reset to zero every time CMST is started, and if CMST is running everytime a Connman service is started. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_resetcounters->setText(QCoreApplication::translate("ControlBox", "Reset Counters", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_advanced->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>When checked additional controls for advanced users are displayed.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_advanced->setText(QCoreApplication::translate("ControlBox", "Advanced Controls", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_usestartoptions->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the Start Up Options in the right hand pane will be enabled. Start up options set in this pane will be read and used next time the program starts. Start up options are also available as command line switches and an option provided on the command line will take precedence over an option set in the right hand pane. The options in this pane are provided as a convienence to avoid the necessity of editing a systemd service or other start up file. </p><p>Settings are stored in<span style=\" font-family:'Courier New,courier';\">: ~</span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">/.config/cmst/cmst.conf </span><span style=\" font-family:'Courier New,courier';\"><br/>This is a standard ini type text file.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_usestartoptions->setText(QCoreApplication::translate("ControlBox", "Enable Start Options from GUI (right hand pane)", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_retainstate->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the state of the GUI will be restored from settings saved on disk. Settings include the geometry and position of the dialog and the current tab. </p><p>These settings will be used at next boot to restore the user interface to the way it was at shutdown.</p><p>The settings file is: ~<span style=\" font-weight:600;\">/.config/cmst/cmst.conf </span><br/>This is a standard ini type text file.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_retainstate->setText(QCoreApplication::translate("ControlBox", "Retain State", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_enableinterfacetooltips->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the display of tooltips will be enabled for the interface widgets.</p><p>Tooltips are the small popups that appear when you hover the mouse pointer over an area of the interface. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_enableinterfacetooltips->setText(QCoreApplication::translate("ControlBox", "Enable ToolTips (Interface)", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_colorize->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Color in #RGB format to colorize the internal icons with.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        toolButton_colorize->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Open the color selection dialog. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolButton_colorize->setText(QCoreApplication::translate("ControlBox", "...", nullptr));
#if QT_CONFIG(whatsthis)
        label_2->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Internal icons can be colorized. You may select a color using the button to the left, or you may type in the #RGB color yourself.</p><p>If you type the entry it must have leading # sign. Example: #22aa44 </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_2->setText(QCoreApplication::translate("ControlBox", "Colorize", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_systemtray->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Preferences for the system tray are in this box.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_systemtray->setTitle(QCoreApplication::translate("ControlBox", "System Tray", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_enablesystemtraytooltips->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the system tray icon will popup a status message when you hover the mouse over it.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_enablesystemtraytooltips->setText(QCoreApplication::translate("ControlBox", "Enable System Tray Popups", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_hideIcon->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked an icon will not be displayed in the system tray.  </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_hideIcon->setText(QCoreApplication::translate("ControlBox", "Hide Tray Icon", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_systemtraynotifications->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the system tray will popup a notify message when a significant connman related event is received.</p><p>Notifications can be handled by the System Tray Icon, or by a Notify daemon if one is installed.  Both can not be active at the same time.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_systemtraynotifications->setText(QCoreApplication::translate("ControlBox", "System Tray Notifications", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_startoptions->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>These entries control various options for CMST at program start. Changing or setting these will only take effect at the next program start. </p><p>All of these options are available from the command line, and if a command line option is provided it will take precedence over these settings.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_startoptions->setTitle(QCoreApplication::translate("ControlBox", "Start Up Options", nullptr));
#if QT_CONFIG(whatsthis)
        spinBox_faketransparency->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Specify the background color as a hex number in the format: RRGGBB.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        lineEdit_icontheme->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Icon theme to use. For this theme to be used it must be installed on your system. If the theme is not installed, or if you spell the name wrong CMST will fall back to using its internal icon set.</p><p>If this box is blank CMST will try and use the system wide icon theme (if one is defined).</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        checkBox_enablecounters->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'monospace';\">Command Line Option: </span><span style=\" font-family:'monospace'; font-weight:600;\">-c</span><span style=\" font-family:'monospace';\"> or </span><span style=\" font-family:'monospace'; font-weight:600;\">--enable-counters</span></pre><p>Enable Connman RX and TX counters.  Counters are experimental in Connman and enabling them will write a large amount of data to the system logs.</p><p>Counters are turned off by default, and is a change from the way it was originally.  Up to and including version 2017.09.19 counters were enabled by default.  All versions subsequent to that counters are disabled by default.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_enablecounters->setText(QCoreApplication::translate("ControlBox", "Enable Counters", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_disabletrayicon->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">-d</span><span style=\" font-family:'Courier New,courier';\"> or </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--disable-tray-icon</span></pre></body></html>\n"
"<html><head/><body><p>Disable the system tray icon.</p><p>May be needed for system trays not compliant with the Freedesktop.org system tray specification.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_disabletrayicon->setText(QCoreApplication::translate("ControlBox", "Disable Tray Icon", nullptr));
#if QT_CONFIG(whatsthis)
        spinBox_counterkb->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Specify the amount of data in KB that must be transmitted before the counters update (default is 1024 KB).</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        checkBox_startminimized->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        checkBox_startminimized->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">-m</span><span style=\" font-family:'Courier New,courier';\"> or </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--minimized</span></pre></body></html>\n"
"<html><head/><body><p>Start the GUI minimized in the system tray.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_startminimized->setText(QCoreApplication::translate("ControlBox", "Start Minimized", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_faketranparency->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        checkBox_faketranparency->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--fake-transparency</span></pre></body></html>\n"
"<html><head/><body><p>Used to work around a QT bug where system tray icons display with white or black backgrounds instead of being transparent.</p><p>You can specify the icon background color here. Format is a hex number in the form RRGGBB.  If the spedified color matches the tray background we've effectively created fake transparency. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_faketranparency->setText(QCoreApplication::translate("ControlBox", "Fake Transparency", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_waittime->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">-w</span><span style=\" font-family:'Courier New,courier';\"> or </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--wait-time</span></pre></body></html>\n"
"<html><head/><body><p>Specify the wait time in seconds before starting the system tray icon (default is 0 seconds).</p><p>If CMST is started and tries to create a tray icon before the system tray itself is created a dialog will be displayed explaining that. This sometimes happens when the program is started automatically. If you know the tray will exist once the system is up you may specify a wait time and CMST will wait that number of seconds before trying to create the tray icon. This is to give the window manager or panel time to create th"
                        "e tray before we try to place the icon there.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_waittime->setText(QCoreApplication::translate("ControlBox", "Wait Time", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_systemicontheme->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        checkBox_systemicontheme->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">-i</span><span style=\" font-family:'Courier New,courier';\"> or </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--icon-theme</span></pre><p>Use an icon theme from your system. You may specify the theme in the box at the right, or if the box is left blank CMST will try and use the system wide icon theme (if one is defined).</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_systemicontheme->setText(QCoreApplication::translate("ControlBox", "Use Icon Theme", nullptr));
#if QT_CONFIG(whatsthis)
        spinBox_counterrate->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Specify the frequency in seconds between counter updates (default is 10 seconds). </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        checkBox_counterkb->setToolTip(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Disabled because currently Connman will accept this option but will do nothing with it.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        checkBox_counterkb->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Specify the amount of data in KB that must be transmitted before the counters update (default is 1024 KB).</p><p>Connman will accept this entry, but according to a comment in the Connman code the actual feature still needs to be implemented and the selection is therefore disabled.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_counterkb->setText(QCoreApplication::translate("ControlBox", "Counter Update KB", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_disableminimized->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">-M</span><span style=\" font-family:'Courier New,courier';\"> or </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--disable-minimized</span></pre><p>Disable the minimize button. Use when you want to have the window manager have sole control of minimizing the interface.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_disableminimized->setText(QCoreApplication::translate("ControlBox", "Disable Minimized", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_disablevpn->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">-n</span><span style=\" font-family:'Courier New,courier';\"> or </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--disable-vpn</span></pre><p>Disable VPN. This will hide the VPN tab and will also skip trying to make a connection to connman-vpn. The later is useful if your Connman was built with the --disable-vpn feature.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_disablevpn->setText(QCoreApplication::translate("ControlBox", "Disable VPN", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_2->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Use code specific for the selected desktop environment.</p><p>As of 2014.11.24 there seems to be a problem with QT5.3 and some system trays. There is code in the program to try and work around this issue, and selecting one of these buttons will invoke the code specific to the desktop.</p><p>If the bug gets fixed these options will remain so that start up scripts do not break, but the options will do nothing.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_2->setTitle(QCoreApplication::translate("ControlBox", "Desktop Specific", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_desktopnone->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        radioButton_desktopnone->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Default is no desktop specific code.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        radioButton_desktopnone->setText(QCoreApplication::translate("ControlBox", "None", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_desktopxfce->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        radioButton_desktopxfce->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--use-xfce</span></pre></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        radioButton_desktopxfce->setText(QCoreApplication::translate("ControlBox", "XFCE", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_desktopmate->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        radioButton_desktopmate->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--use-mate</span></pre></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        radioButton_desktopmate->setText(QCoreApplication::translate("ControlBox", "MATE", nullptr));
#if QT_CONFIG(whatsthis)
        spinBox_waittime->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Specify the wait time in seconds before starting the system tray icon (default is 0 seconds).</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        checkBox_counterseconds->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        checkBox_counterseconds->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><pre style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">Command Line Option: </span><span style=\" font-family:'Courier New,courier'; font-weight:600;\">--counter-update-rate</span></pre></body></html>\n"
"<html><head/><body><p>Specify the frequency in seconds between counter updates (default is 10 seconds). </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_counterseconds->setText(QCoreApplication::translate("ControlBox", "Counter Update Rate ", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox_process->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Programs or processes to execute after various events occur.</p><p>If the program or process requires command line arguments provide them here just as if you were typing at a command line. Example:</p><p><span style=\" font-weight:600;\">/path/to/program arg1 arg2 arg3</span></p><p>Two events are checked. <span style=\" font-weight:600;\">Before Connecting</span> events are called after the Connect button is pressed in either the Wireless or VPN tabs. The program or process in the Execute box will only be executed prior to making a connection for the service shown in the Service box.  It will not be called when connecting to any other service.</p><p>The program or process in the <span style=\" font-weight:600;\">After Connecting</span> box will be called after Connman enters the ready or online state.</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_process->setTitle(QCoreApplication::translate("ControlBox", "External Programs", nullptr));
#if QT_CONFIG(whatsthis)
        groupBox->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>This area is to specify a program or process to run after a wifi or vpn service button is pressed, but before the connect method is sent to ConnMan. This is mainly used to modify a .cmst.config file which seems useful to modify certain short lived entries for openConnect vpn connections.</p><p>The program or process in the <span style=\" font-weight:600;\">Execute</span> box will only be executed prior to making a connection for the single service shown in the <span style=\" font-weight:600;\">Service</span> box. It will not be called when connecting to any other service. If a .cmst.config file is to be modified a check must in the <span style=\" font-weight:600;\">Modify Service File</span> box and the path and name of the file to be modified must be provided.</p><p>To modify a .cmst.config file CMST will read stdout of the program or process being called. Program output should be individual lines in KEY=VALUE format. If KEY exists in the .cmst.config file it will be replaced by the new "
                        "VALUE. If KEY does not exist it will be appended. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QCoreApplication::translate("ControlBox", "Before Connecting", nullptr));
#if QT_CONFIG(whatsthis)
        label_4->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Enter the program or process to be executed before Connman initiates a connection to the service listed in the box above. If left blank no program or process will be executed.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_4->setText(QCoreApplication::translate("ControlBox", "Execute:", nullptr));
#if QT_CONFIG(whatsthis)
        label_3->setWhatsThis(QCoreApplication::translate("ControlBox", "Specify the service you are connecting to where you want a program or process to execute prior to initiating the connection.", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_3->setText(QCoreApplication::translate("ControlBox", "Service:", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_modifyservicefile->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>If checked the configuration file shown below will be modified by whatever output the program provides.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_modifyservicefile->setText(QCoreApplication::translate("ControlBox", "Modify Service File", nullptr));
#if QT_CONFIG(whatsthis)
        label_5->setWhatsThis(QCoreApplication::translate("ControlBox", "Service configuration file to be modified by the program.", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_5->setText(QCoreApplication::translate("ControlBox", "FIle: ", nullptr));
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("ControlBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter the program or process to be executed after Connman enters the <span style=\" font-weight:600;\">Ready</span> or <span style=\" font-weight:600;\">Online</span> state.  If left blank no program or process will be executed.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("ControlBox", "After Connecting", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Preferences), QCoreApplication::translate("ControlBox", "&Preferences", nullptr));
        groupBox_about->setTitle(QCoreApplication::translate("ControlBox", "&About", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_aboutCMST->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Display a dialog box containing information about this program. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_aboutCMST->setText(QCoreApplication::translate("ControlBox", "C&MST", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_aboutIconSet->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Display a dialog box containing information about the Icon set used in this program. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_aboutIconSet->setText(QCoreApplication::translate("ControlBox", "Aw&Oken", nullptr));
        pushButton_aboutOtherArt->setText(QCoreApplication::translate("ControlBox", "A&rtwork", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_aboutQT->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Display a dialog box containing information about the QT toolkit used to develop this program. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_aboutQT->setText(QCoreApplication::translate("ControlBox", "&QT", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_license->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Use this button to view the program license.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_license->setText(QCoreApplication::translate("ControlBox", "&License", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_change_log->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Use this button to view the change log of the program.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_change_log->setText(QCoreApplication::translate("ControlBox", "ChangeLo&g", nullptr));
        label_help->setText(QCoreApplication::translate("ControlBox", "<html><head/><body><p><span style=\" font-weight:600;\">Help</span></p><p>Program help is mainly provided by the &quot;What's This&quot; button in the lower left corner. Press the button and then click on an item you are interested in. &quot;What's This&quot; is also available via context menu by right clicking on a button, box or text area.</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Help), QCoreApplication::translate("ControlBox", "&Help", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_whatsthis->setToolTip(QCoreApplication::translate("ControlBox", "<html><head/><body><p>What's This</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        toolButton_whatsthis->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Use this button to find information about an element in the GUI by entering &quot;What's This&quot; mode. </p><p>You may also right click on an element to show the &quot;What's This&quot; text for it.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolButton_whatsthis->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_provisioning_editor->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Open the provisioning editor to create or edit Connman configuration (provisioning) files.</p><p>These config files reside in /var/lib/connman which is owned by root:root. CMST will register a roothelper to allow reading and writing files in this directory. </p><p>To avoid abusing the root privileges the editor will only operate on files with names ending in <span style=\" font-style:italic;\">.cmst.config</span>. This file name ending will be added automatically during a file save and cannot be altered. </p><p>Using this editor it is not possible to edit or delete config files created by other means.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_provisioning_editor->setText(QCoreApplication::translate("ControlBox", "Provisioning Editor", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_vpn_editor->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Open the VPN provisioning editor to create or edit Connman configuration (provisioning) files for VPN connections.</p><p>These config files reside in /var/lib/connman-vpn which is owned by root:root. CMST will register a roothelper to allow reading and writing files in this directory. </p><p>To avoid abusing the root privileges the editor will only operate on files with names ending in <span style=\" font-style:italic;\">.cmst.config</span>. This file name ending will be added automatically during a file save and cannot be altered. </p><p>Using this editor it is not possible to edit or delete config files created by other means.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_vpn_editor->setText(QCoreApplication::translate("ControlBox", "VPN Editor", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_exit->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Exit the program and remove the system tray icon. Connman will still be running as a daemon but will not be managed by this program.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_exit->setText(QCoreApplication::translate("ControlBox", "E&xit", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_minimize->setWhatsThis(QCoreApplication::translate("ControlBox", "<html><head/><body><p>Minimize the dialog. If you have the system tray Icon shown this dialog may be restored by right clicking on the tray icon. If the tray icon is hidden minimize will not be active.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_minimize->setText(QCoreApplication::translate("ControlBox", "Mi&nimize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlBox: public Ui_ControlBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLBOX_H
