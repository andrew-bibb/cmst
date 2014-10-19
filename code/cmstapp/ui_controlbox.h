/********************************************************************************
** Form generated from reading UI file 'controlbox.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLBOX_H
#define UI_CONTROLBOX_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_11;
    QTabWidget *tabWidget;
    QWidget *Status;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_devicesoff;
    QGroupBox *groupBox_global_properties;
    QGridLayout *gridLayout_4;
    QLabel *label_offlinemode;
    QLabel *label_state_pix;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_offlinemode_pix;
    QLabel *label_state;
    QGroupBox *groupBox_technologies;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_technologies;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_rescan;
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
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_details_left;
    QLabel *label_details_right;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_configuration;
    QWidget *Wireless;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_wireless_utils;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_remove;
    QLabel *label_wifi_state;
    QSpacerItem *horizontalSpacer_6;
    QTableWidget *tableWidget_wifi;
    QWidget *Counters;
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
    QSpacerItem *verticalSpacer_3;
    QLabel *label_counter_settings;
    QWidget *Preferences;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_preferencesinterface;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *checkBox_retainsettings;
    QCheckBox *checkBox_enableinterfacetooltips;
    QCheckBox *checkBox_resetcounters;
    QCheckBox *checkBox_advanced;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_systemtray;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_hideIcon;
    QCheckBox *checkBox_enablesystemtraytooltips;
    QCheckBox *checkBox_systemtraynotifications;
    QGroupBox *groupBox_notfications;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_notifydaemon;
    QLabel *label_serverstatus;
    QWidget *Help;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_about;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_aboutCMST;
    QPushButton *pushButton_aboutIconSet;
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
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_minimize;

    void setupUi(QDialog *ControlBox)
    {
        if (ControlBox->objectName().isEmpty())
            ControlBox->setObjectName(QStringLiteral("ControlBox"));
        ControlBox->resize(702, 546);
        ControlBox->setMinimumSize(QSize(530, 475));
        ControlBox->setSizeGripEnabled(true);
        actionMove_Before = new QAction(ControlBox);
        actionMove_Before->setObjectName(QStringLiteral("actionMove_Before"));
        actionMove_After = new QAction(ControlBox);
        actionMove_After->setObjectName(QStringLiteral("actionMove_After"));
        verticalLayout_11 = new QVBoxLayout(ControlBox);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        tabWidget = new QTabWidget(ControlBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Status = new QWidget();
        Status->setObjectName(QStringLiteral("Status"));
        Status->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(Status);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        checkBox_devicesoff = new QCheckBox(Status);
        checkBox_devicesoff->setObjectName(QStringLiteral("checkBox_devicesoff"));

        gridLayout_2->addWidget(checkBox_devicesoff, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        groupBox_global_properties = new QGroupBox(Status);
        groupBox_global_properties->setObjectName(QStringLiteral("groupBox_global_properties"));
        gridLayout_4 = new QGridLayout(groupBox_global_properties);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_offlinemode = new QLabel(groupBox_global_properties);
        label_offlinemode->setObjectName(QStringLiteral("label_offlinemode"));

        gridLayout_4->addWidget(label_offlinemode, 2, 1, 1, 2);

        label_state_pix = new QLabel(groupBox_global_properties);
        label_state_pix->setObjectName(QStringLiteral("label_state_pix"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_state_pix->sizePolicy().hasHeightForWidth());
        label_state_pix->setSizePolicy(sizePolicy);
        label_state_pix->setMaximumSize(QSize(16, 16));
        label_state_pix->setScaledContents(true);

        gridLayout_4->addWidget(label_state_pix, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(506, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 2, 2, 4);

        horizontalSpacer_5 = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 5, 2, 1);

        label_offlinemode_pix = new QLabel(groupBox_global_properties);
        label_offlinemode_pix->setObjectName(QStringLiteral("label_offlinemode_pix"));
        sizePolicy.setHeightForWidth(label_offlinemode_pix->sizePolicy().hasHeightForWidth());
        label_offlinemode_pix->setSizePolicy(sizePolicy);
        label_offlinemode_pix->setMaximumSize(QSize(16, 16));
        label_offlinemode_pix->setScaledContents(true);

        gridLayout_4->addWidget(label_offlinemode_pix, 2, 0, 1, 1);

        label_state = new QLabel(groupBox_global_properties);
        label_state->setObjectName(QStringLiteral("label_state"));

        gridLayout_4->addWidget(label_state, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_global_properties, 1, 0, 1, 1);

        groupBox_technologies = new QGroupBox(Status);
        groupBox_technologies->setObjectName(QStringLiteral("groupBox_technologies"));
        verticalLayout_3 = new QVBoxLayout(groupBox_technologies);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableWidget_technologies = new QTableWidget(groupBox_technologies);
        if (tableWidget_technologies->columnCount() < 5)
            tableWidget_technologies->setColumnCount(5);
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
        tableWidget_technologies->setObjectName(QStringLiteral("tableWidget_technologies"));
        tableWidget_technologies->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_technologies->setProperty("showDropIndicator", QVariant(false));
        tableWidget_technologies->setDragDropOverwriteMode(false);
        tableWidget_technologies->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_technologies->setShowGrid(false);
        tableWidget_technologies->setCornerButtonEnabled(false);
        tableWidget_technologies->horizontalHeader()->setHighlightSections(false);
        tableWidget_technologies->horizontalHeader()->setStretchLastSection(true);
        tableWidget_technologies->verticalHeader()->setVisible(false);
        tableWidget_technologies->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(tableWidget_technologies);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(293, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_rescan = new QPushButton(groupBox_technologies);
        pushButton_rescan->setObjectName(QStringLiteral("pushButton_rescan"));

        horizontalLayout_5->addWidget(pushButton_rescan);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout_3->addWidget(groupBox_technologies, 2, 0, 1, 1);

        groupBox_services = new QGroupBox(Status);
        groupBox_services->setObjectName(QStringLiteral("groupBox_services"));
        verticalLayout_6 = new QVBoxLayout(groupBox_services);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tableWidget_services = new QTableWidget(groupBox_services);
        if (tableWidget_services->columnCount() < 3)
            tableWidget_services->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_services->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tableWidget_services->setObjectName(QStringLiteral("tableWidget_services"));
        tableWidget_services->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_services->setProperty("showDropIndicator", QVariant(false));
        tableWidget_services->setDragDropOverwriteMode(false);
        tableWidget_services->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_services->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_services->setShowGrid(false);
        tableWidget_services->setCornerButtonEnabled(false);
        tableWidget_services->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_services->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_services->horizontalHeader()->setStretchLastSection(true);
        tableWidget_services->verticalHeader()->setVisible(false);
        tableWidget_services->verticalHeader()->setHighlightSections(false);

        verticalLayout_6->addWidget(tableWidget_services);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_movebefore = new QPushButton(groupBox_services);
        pushButton_movebefore->setObjectName(QStringLiteral("pushButton_movebefore"));
        pushButton_movebefore->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_movebefore);

        pushButton_moveafter = new QPushButton(groupBox_services);
        pushButton_moveafter->setObjectName(QStringLiteral("pushButton_moveafter"));
        pushButton_moveafter->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_moveafter);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        checkBox_hidecnxn = new QCheckBox(groupBox_services);
        checkBox_hidecnxn->setObjectName(QStringLiteral("checkBox_hidecnxn"));
        checkBox_hidecnxn->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_hidecnxn);


        verticalLayout_6->addLayout(horizontalLayout_3);


        gridLayout_3->addWidget(groupBox_services, 4, 0, 1, 1);

        tabWidget->addTab(Status, QString());
        Details = new QWidget();
        Details->setObjectName(QStringLiteral("Details"));
        verticalLayout_2 = new QVBoxLayout(Details);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_service = new QLabel(Details);
        label_service->setObjectName(QStringLiteral("label_service"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_service->setFont(font);

        verticalLayout_2->addWidget(label_service);

        comboBox_service = new QComboBox(Details);
        comboBox_service->setObjectName(QStringLiteral("comboBox_service"));

        verticalLayout_2->addWidget(comboBox_service);

        scrollArea_2 = new QScrollArea(Details);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QStringLiteral("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 660, 371));
        horizontalLayout_7 = new QHBoxLayout(scrollAreaWidgetContents_5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_details_left = new QLabel(scrollAreaWidgetContents_5);
        label_details_left->setObjectName(QStringLiteral("label_details_left"));
        label_details_left->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_details_left);

        label_details_right = new QLabel(scrollAreaWidgetContents_5);
        label_details_right->setObjectName(QStringLiteral("label_details_right"));
        label_details_right->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_details_right);

        scrollArea_2->setWidget(scrollAreaWidgetContents_5);

        verticalLayout_2->addWidget(scrollArea_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        pushButton_configuration = new QPushButton(Details);
        pushButton_configuration->setObjectName(QStringLiteral("pushButton_configuration"));

        horizontalLayout_6->addWidget(pushButton_configuration);


        verticalLayout_2->addLayout(horizontalLayout_6);

        tabWidget->addTab(Details, QString());
        Wireless = new QWidget();
        Wireless->setObjectName(QStringLiteral("Wireless"));
        gridLayout_5 = new QGridLayout(Wireless);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_wireless_utils = new QGroupBox(Wireless);
        groupBox_wireless_utils->setObjectName(QStringLiteral("groupBox_wireless_utils"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_wireless_utils);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_connect = new QPushButton(groupBox_wireless_utils);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout_2->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(groupBox_wireless_utils);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_2->addWidget(pushButton_disconnect);

        pushButton_remove = new QPushButton(groupBox_wireless_utils);
        pushButton_remove->setObjectName(QStringLiteral("pushButton_remove"));

        horizontalLayout_2->addWidget(pushButton_remove);

        label_wifi_state = new QLabel(groupBox_wireless_utils);
        label_wifi_state->setObjectName(QStringLiteral("label_wifi_state"));

        horizontalLayout_2->addWidget(label_wifi_state);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout_5->addWidget(groupBox_wireless_utils, 0, 0, 1, 1);

        tableWidget_wifi = new QTableWidget(Wireless);
        if (tableWidget_wifi->columnCount() < 5)
            tableWidget_wifi->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_wifi->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        tableWidget_wifi->setObjectName(QStringLiteral("tableWidget_wifi"));
        tableWidget_wifi->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_wifi->setProperty("showDropIndicator", QVariant(false));
        tableWidget_wifi->setDragDropOverwriteMode(false);
        tableWidget_wifi->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_wifi->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_wifi->setShowGrid(false);
        tableWidget_wifi->setCornerButtonEnabled(false);
        tableWidget_wifi->setColumnCount(5);
        tableWidget_wifi->horizontalHeader()->setStretchLastSection(true);
        tableWidget_wifi->verticalHeader()->setVisible(false);
        tableWidget_wifi->verticalHeader()->setHighlightSections(false);

        gridLayout_5->addWidget(tableWidget_wifi, 1, 0, 1, 1);

        tabWidget->addTab(Wireless, QString());
        Counters = new QWidget();
        Counters->setObjectName(QStringLiteral("Counters"));
        gridLayout_7 = new QGridLayout(Counters);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_counter_service_name = new QLabel(Counters);
        label_counter_service_name->setObjectName(QStringLiteral("label_counter_service_name"));

        gridLayout_7->addWidget(label_counter_service_name, 1, 0, 1, 1);

        groupBox_home_counter = new QGroupBox(Counters);
        groupBox_home_counter->setObjectName(QStringLiteral("groupBox_home_counter"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_home_counter->sizePolicy().hasHeightForWidth());
        groupBox_home_counter->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_home_counter);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        scrollArea_home_counter = new QScrollArea(groupBox_home_counter);
        scrollArea_home_counter->setObjectName(QStringLiteral("scrollArea_home_counter"));
        scrollArea_home_counter->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 636, 137));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_home_counter = new QLabel(scrollAreaWidgetContents_2);
        label_home_counter->setObjectName(QStringLiteral("label_home_counter"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_home_counter->sizePolicy().hasHeightForWidth());
        label_home_counter->setSizePolicy(sizePolicy2);
        label_home_counter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_home_counter->setWordWrap(true);

        verticalLayout_9->addWidget(label_home_counter);

        scrollArea_home_counter->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(scrollArea_home_counter);


        gridLayout_7->addWidget(groupBox_home_counter, 2, 0, 1, 1);

        groupBox_roaming_counter = new QGroupBox(Counters);
        groupBox_roaming_counter->setObjectName(QStringLiteral("groupBox_roaming_counter"));
        sizePolicy1.setHeightForWidth(groupBox_roaming_counter->sizePolicy().hasHeightForWidth());
        groupBox_roaming_counter->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox_roaming_counter);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        scrollArea_roaming_counter = new QScrollArea(groupBox_roaming_counter);
        scrollArea_roaming_counter->setObjectName(QStringLiteral("scrollArea_roaming_counter"));
        scrollArea_roaming_counter->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 636, 136));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_roam_counter = new QLabel(scrollAreaWidgetContents_3);
        label_roam_counter->setObjectName(QStringLiteral("label_roam_counter"));
        sizePolicy2.setHeightForWidth(label_roam_counter->sizePolicy().hasHeightForWidth());
        label_roam_counter->setSizePolicy(sizePolicy2);
        label_roam_counter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_roam_counter->setWordWrap(true);

        verticalLayout_10->addWidget(label_roam_counter);

        scrollArea_roaming_counter->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_5->addWidget(scrollArea_roaming_counter);


        gridLayout_7->addWidget(groupBox_roaming_counter, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 5, 0, 1, 1);

        label_counter_settings = new QLabel(Counters);
        label_counter_settings->setObjectName(QStringLiteral("label_counter_settings"));
        label_counter_settings->setWordWrap(true);

        gridLayout_7->addWidget(label_counter_settings, 4, 0, 1, 1);

        tabWidget->addTab(Counters, QString());
        Preferences = new QWidget();
        Preferences->setObjectName(QStringLiteral("Preferences"));
        gridLayout_8 = new QGridLayout(Preferences);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        groupBox_preferencesinterface = new QGroupBox(Preferences);
        groupBox_preferencesinterface->setObjectName(QStringLiteral("groupBox_preferencesinterface"));
        verticalLayout_7 = new QVBoxLayout(groupBox_preferencesinterface);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        checkBox_retainsettings = new QCheckBox(groupBox_preferencesinterface);
        checkBox_retainsettings->setObjectName(QStringLiteral("checkBox_retainsettings"));
        checkBox_retainsettings->setEnabled(true);

        verticalLayout_7->addWidget(checkBox_retainsettings);

        checkBox_enableinterfacetooltips = new QCheckBox(groupBox_preferencesinterface);
        checkBox_enableinterfacetooltips->setObjectName(QStringLiteral("checkBox_enableinterfacetooltips"));

        verticalLayout_7->addWidget(checkBox_enableinterfacetooltips);

        checkBox_resetcounters = new QCheckBox(groupBox_preferencesinterface);
        checkBox_resetcounters->setObjectName(QStringLiteral("checkBox_resetcounters"));
        checkBox_resetcounters->setEnabled(true);

        verticalLayout_7->addWidget(checkBox_resetcounters);

        checkBox_advanced = new QCheckBox(groupBox_preferencesinterface);
        checkBox_advanced->setObjectName(QStringLiteral("checkBox_advanced"));
        checkBox_advanced->setChecked(false);

        verticalLayout_7->addWidget(checkBox_advanced);


        gridLayout_8->addWidget(groupBox_preferencesinterface, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_4, 5, 0, 1, 1);

        groupBox_systemtray = new QGroupBox(Preferences);
        groupBox_systemtray->setObjectName(QStringLiteral("groupBox_systemtray"));
        gridLayout = new QGridLayout(groupBox_systemtray);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox_hideIcon = new QCheckBox(groupBox_systemtray);
        checkBox_hideIcon->setObjectName(QStringLiteral("checkBox_hideIcon"));

        gridLayout->addWidget(checkBox_hideIcon, 0, 0, 1, 1);

        checkBox_enablesystemtraytooltips = new QCheckBox(groupBox_systemtray);
        checkBox_enablesystemtraytooltips->setObjectName(QStringLiteral("checkBox_enablesystemtraytooltips"));
        checkBox_enablesystemtraytooltips->setChecked(true);

        gridLayout->addWidget(checkBox_enablesystemtraytooltips, 1, 0, 1, 1);

        checkBox_systemtraynotifications = new QCheckBox(groupBox_systemtray);
        checkBox_systemtraynotifications->setObjectName(QStringLiteral("checkBox_systemtraynotifications"));
        checkBox_systemtraynotifications->setEnabled(true);

        gridLayout->addWidget(checkBox_systemtraynotifications, 2, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_systemtray, 3, 0, 1, 1);

        groupBox_notfications = new QGroupBox(Preferences);
        groupBox_notfications->setObjectName(QStringLiteral("groupBox_notfications"));
        groupBox_notfications->setEnabled(true);
        horizontalLayout_4 = new QHBoxLayout(groupBox_notfications);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_notifydaemon = new QCheckBox(groupBox_notfications);
        checkBox_notifydaemon->setObjectName(QStringLiteral("checkBox_notifydaemon"));
        checkBox_notifydaemon->setEnabled(true);

        horizontalLayout_4->addWidget(checkBox_notifydaemon);

        label_serverstatus = new QLabel(groupBox_notfications);
        label_serverstatus->setObjectName(QStringLiteral("label_serverstatus"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_serverstatus->sizePolicy().hasHeightForWidth());
        label_serverstatus->setSizePolicy(sizePolicy3);
        label_serverstatus->setWordWrap(true);

        horizontalLayout_4->addWidget(label_serverstatus);


        gridLayout_8->addWidget(groupBox_notfications, 4, 0, 1, 1);

        tabWidget->addTab(Preferences, QString());
        Help = new QWidget();
        Help->setObjectName(QStringLiteral("Help"));
        gridLayout_6 = new QGridLayout(Help);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_about = new QGroupBox(Help);
        groupBox_about->setObjectName(QStringLiteral("groupBox_about"));
        verticalLayout = new QVBoxLayout(groupBox_about);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_aboutCMST = new QPushButton(groupBox_about);
        pushButton_aboutCMST->setObjectName(QStringLiteral("pushButton_aboutCMST"));

        verticalLayout->addWidget(pushButton_aboutCMST);

        pushButton_aboutIconSet = new QPushButton(groupBox_about);
        pushButton_aboutIconSet->setObjectName(QStringLiteral("pushButton_aboutIconSet"));

        verticalLayout->addWidget(pushButton_aboutIconSet);

        pushButton_aboutQT = new QPushButton(groupBox_about);
        pushButton_aboutQT->setObjectName(QStringLiteral("pushButton_aboutQT"));

        verticalLayout->addWidget(pushButton_aboutQT);

        pushButton_license = new QPushButton(groupBox_about);
        pushButton_license->setObjectName(QStringLiteral("pushButton_license"));

        verticalLayout->addWidget(pushButton_license);

        pushButton_change_log = new QPushButton(groupBox_about);
        pushButton_change_log->setObjectName(QStringLiteral("pushButton_change_log"));

        verticalLayout->addWidget(pushButton_change_log);

        verticalSpacer_2 = new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout_6->addWidget(groupBox_about, 0, 0, 1, 1);

        scrollArea = new QScrollArea(Help);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 550, 449));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_help = new QLabel(scrollAreaWidgetContents);
        label_help->setObjectName(QStringLiteral("label_help"));
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
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_whatsthis = new QToolButton(ControlBox);
        toolButton_whatsthis->setObjectName(QStringLiteral("toolButton_whatsthis"));

        horizontalLayout->addWidget(toolButton_whatsthis);

        pushButton_provisioning_editor = new QPushButton(ControlBox);
        pushButton_provisioning_editor->setObjectName(QStringLiteral("pushButton_provisioning_editor"));

        horizontalLayout->addWidget(pushButton_provisioning_editor);

        horizontalSpacer_3 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_exit = new QPushButton(ControlBox);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        horizontalLayout->addWidget(pushButton_exit);

        pushButton_minimize = new QPushButton(ControlBox);
        pushButton_minimize->setObjectName(QStringLiteral("pushButton_minimize"));

        horizontalLayout->addWidget(pushButton_minimize);


        verticalLayout_11->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label_service->setBuddy(comboBox_service);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tabWidget, checkBox_devicesoff);
        QWidget::setTabOrder(checkBox_devicesoff, tableWidget_technologies);
        QWidget::setTabOrder(tableWidget_technologies, pushButton_rescan);
        QWidget::setTabOrder(pushButton_rescan, tableWidget_services);
        QWidget::setTabOrder(tableWidget_services, pushButton_movebefore);
        QWidget::setTabOrder(pushButton_movebefore, pushButton_moveafter);
        QWidget::setTabOrder(pushButton_moveafter, checkBox_hidecnxn);
        QWidget::setTabOrder(checkBox_hidecnxn, comboBox_service);
        QWidget::setTabOrder(comboBox_service, pushButton_connect);
        QWidget::setTabOrder(pushButton_connect, pushButton_disconnect);
        QWidget::setTabOrder(pushButton_disconnect, pushButton_remove);
        QWidget::setTabOrder(pushButton_remove, tableWidget_wifi);
        QWidget::setTabOrder(tableWidget_wifi, scrollArea_home_counter);
        QWidget::setTabOrder(scrollArea_home_counter, scrollArea_roaming_counter);
        QWidget::setTabOrder(scrollArea_roaming_counter, checkBox_retainsettings);
        QWidget::setTabOrder(checkBox_retainsettings, checkBox_enableinterfacetooltips);
        QWidget::setTabOrder(checkBox_enableinterfacetooltips, checkBox_resetcounters);
        QWidget::setTabOrder(checkBox_resetcounters, checkBox_hideIcon);
        QWidget::setTabOrder(checkBox_hideIcon, checkBox_enablesystemtraytooltips);
        QWidget::setTabOrder(checkBox_enablesystemtraytooltips, checkBox_systemtraynotifications);
        QWidget::setTabOrder(checkBox_systemtraynotifications, checkBox_notifydaemon);
        QWidget::setTabOrder(checkBox_notifydaemon, pushButton_aboutCMST);
        QWidget::setTabOrder(pushButton_aboutCMST, pushButton_aboutIconSet);
        QWidget::setTabOrder(pushButton_aboutIconSet, pushButton_aboutQT);
        QWidget::setTabOrder(pushButton_aboutQT, pushButton_license);
        QWidget::setTabOrder(pushButton_license, pushButton_change_log);
        QWidget::setTabOrder(pushButton_change_log, scrollArea);
        QWidget::setTabOrder(scrollArea, toolButton_whatsthis);
        QWidget::setTabOrder(toolButton_whatsthis, pushButton_exit);
        QWidget::setTabOrder(pushButton_exit, pushButton_minimize);

        retranslateUi(ControlBox);
        QObject::connect(checkBox_advanced, SIGNAL(clicked(bool)), pushButton_provisioning_editor, SLOT(setVisible(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ControlBox);
    } // setupUi

    void retranslateUi(QDialog *ControlBox)
    {
        ControlBox->setWindowTitle(QApplication::translate("ControlBox", "Dialog", 0));
        actionMove_Before->setText(QApplication::translate("ControlBox", "Move Before", 0));
        actionMove_After->setText(QApplication::translate("ControlBox", "Move After", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_devicesoff->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>This checkbox controls the global setting for switching all radios on or off. When checked all radios are powered down.</p><p>When the system is In offline mode it is possible to turn individual devices back on. When leaving offline mode the individual policy of each device determines if the radio is turned back on or not.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_devicesoff->setText(QApplication::translate("ControlBox", "All Devices &Off", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_global_properties->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p><span style=\" font-weight:600;\">OfflineMode</span></p><p>The offline mode indicates the global setting for switching all radios on or off. Changing offline mode to true results in powering down all devices. When leaving offline mode the individual policy of each device decides to switch the radio back on or not. </p><p>During offline mode, it is still possible to switch certain technologies manually back on. For example the limited usage of WiFi or Bluetooth devices might be allowed in some situations.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_global_properties->setTitle(QApplication::translate("ControlBox", "Global Properties", 0));
#ifndef QT_NO_TOOLTIP
        label_offlinemode->setToolTip(QApplication::translate("ControlBox", "<html><head/><body><p>Global setting for the offline property</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_offlinemode->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>The global setting for switching all radios on or off. When offline mode is engaged all radios are powered down.</p><p>While in offline mode it is possible to turn individual devices back on. When leaving offline mode the individual policy of each device determines if the radio is turned back on or not.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_offlinemode->setText(QApplication::translate("ControlBox", "OfflineMode: Unavailable", 0));
        label_state_pix->setText(QString());
        label_offlinemode_pix->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_state->setToolTip(QApplication::translate("ControlBox", "<html><head/><body><p>Global connection state</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_state->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>The global connection state of the system.  Possible values are &quot;offline&quot;, &quot;idle&quot;, &quot;ready&quot;, and &quot;online&quot;.  </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_state->setText(QApplication::translate("ControlBox", "State: Unavailable", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_technologies->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Connman refers to hardware devices as technologies. This box will display information about all known technologies.</p><p>To turn a technology on or off click on the button that shows in the <span style=\" font-weight:600;\">Powered</span> column for the technology.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_technologies->setTitle(QApplication::translate("ControlBox", "Technologies", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_technologies->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ControlBox", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_technologies->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ControlBox", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_technologies->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ControlBox", "Powered", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_technologies->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ControlBox", "Connected", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_technologies->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ControlBox", "Tethering", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_rescan->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Force a rescan of all technologies to look for services associated with each. Technologies are automatically scanned periodically, this button will force a scan to occur immediately.</p><p>This is similar to issuing the command <span style=\" font-weight:600;\">connmanctl scan wif</span>i from the command line, except all technologies will be scanned, not just WiFi.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_rescan->setText(QApplication::translate("ControlBox", "Resc&an", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_services->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>This box lists all services that connman can connect to.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_services->setTitle(QApplication::translate("ControlBox", "Services", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_services->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("ControlBox", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_services->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("ControlBox", "State", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_services->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("ControlBox", "Connection", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_movebefore->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Move the selected service before another in the list.</p><p>The button will only become active once a service is selected.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_movebefore->setText(QApplication::translate("ControlBox", "Move Before", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_moveafter->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Move the selected service after another in the list.</p><p>The button will only become active once a service is selected.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_moveafter->setText(QApplication::translate("ControlBox", "Move After", 0));
#ifndef QT_NO_TOOLTIP
        checkBox_hidecnxn->setToolTip(QApplication::translate("ControlBox", "<html><head/><body><p>Hide the connection field</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_hidecnxn->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>When checked hide the connection name in the Services box.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_hidecnxn->setText(QApplication::translate("ControlBox", "&Less", 0));
        tabWidget->setTabText(tabWidget->indexOf(Status), QApplication::translate("ControlBox", "&Status", 0));
        label_service->setText(QApplication::translate("ControlBox", "Ser&vice", 0));
#ifndef QT_NO_WHATSTHIS
        comboBox_service->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Use this Combobox to select the service for which you wish to view the detailed information.<br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_details_left->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_configuration->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>The default configuration method for all services is automatic or something like DHCP. This should be good enough for most typical usage, but if it is not this button will allow manual configuration of Ethernet and IP settings for the selected Service.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_configuration->setText(QApplication::translate("ControlBox", "Configuration", 0));
        tabWidget->setTabText(tabWidget->indexOf(Details), QApplication::translate("ControlBox", "&Details", 0));
        groupBox_wireless_utils->setTitle(QApplication::translate("ControlBox", "Wireless Services", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_connect->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Select a wifi service in the table below and press this button to connect the service. </p><p>If there is only one wifi service listed in the table pressing this button will automatically select that service and attempt to connect. </p><p>If information about the service is needed, a passphrase for instance, you will be prompted for it. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_connect->setText(QApplication::translate("ControlBox", "Connect", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_disconnect->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Select a wifi service in the table below and press this button to disconnect it. </p><p>If there is only one wifi service in the &quot;ready&quot; or &quot;online&quot; state pressing this button will automatically select that service and disconnect it. </p><p>This may also be used to abort a previous connection attempt.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_disconnect->setText(QApplication::translate("ControlBox", "Disconnect", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_remove->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Select a wifi service in the table below and press this button to remove the service. </p><p>If a service has previously been sussessfully connected (Favorite is true) this button will remove the Favorite property. The service will also be disconnected if it is currently connected. If the service required a passphrase then the passphrase it will be cleared and forgotten.</p><p>If a connection attempt failed this can slso be used to reset the service.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_remove->setText(QApplication::translate("ControlBox", "Remove", 0));
#ifndef QT_NO_WHATSTHIS
        label_wifi_state->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>This label shows the number of WiFi technologies (devices) that were found, and the number that are powered on. There must be at least one WiFi technology found and powered in order for the box below to show services.</p><p>To turn a technology on or off go to the <span style=\" font-weight:600;\">Technologies</span> box in the <span style=\" font-weight:600;\">Status</span> tab and double click on the text that shows in the <span style=\" font-weight:600;\">Powered</span> column for the technology.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_wifi_state->setText(QApplication::translate("ControlBox", "Wifi State", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_wifi->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("ControlBox", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_wifi->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("ControlBox", "Favorite", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_wifi->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("ControlBox", "Connected", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_wifi->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("ControlBox", "Security", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_wifi->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("ControlBox", "Signal Strength", 0));
#ifndef QT_NO_WHATSTHIS
        tableWidget_wifi->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>This page shows the known WiFi services. </p><p><span style=\" font-weight:600;\">Name:</span> The SSID of the network.</p><p><span style=\" font-weight:600;\">Favorite:</span> A heart symbol in this column indicates that this computer has previously made a connection to the network using this service.</p><p><span style=\" font-weight:600;\">Connected:</span> Shows the connection state of this service. Hover the mouse over the icon to popup a text description.  Online signals that an Internet connectionis available and has been verified.  Ready signals a successfully connected device. </p><p><span style=\" font-weight:600;\">Security: </span>Describes the type of security used for this service. Possible values are &quot;none&quot;, &quot;wep&quot;, &quot;psk&quot;, &quot;ieee8021x&quot;, and &quot;wps&quot;.</p><p><span style=\" font-weight:600;\">SIgnal Strength:</span> The strength of the WiFi signal, normalized to a scale of 0 to 100.</p><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tabWidget->setTabText(tabWidget->indexOf(Wireless), QApplication::translate("ControlBox", "&Wireless", 0));
#ifndef QT_NO_WHATSTHIS
        label_counter_service_name->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>The service being monitored by the counters.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_counter_service_name->setText(QApplication::translate("ControlBox", "Service:", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_home_counter->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Counters for the &quot;online&quot; service connection that is not marked roaming. </p><p>Counters may not always be available. The counters could have been disabled at the command line (-c or --disable-counters) or occasionally the connection will register &quot;ready&quot; instead of &quot;online&quot;. Online is a &quot;ready&quot; connection that has verified internet connectivity. It is possible to be online with only a &quot;ready&quot; connection, however the counters only work for they &quot;online&quot; connection.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_home_counter->setTitle(QApplication::translate("ControlBox", "Home", 0));
        label_home_counter->setText(QApplication::translate("ControlBox", "Counter not available.", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_roaming_counter->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Counters for the &quot;online&quot; service connection marked &quot;roaming&quot;.</p><p>In the case of cellular services this normally indicates connections to a foreign provider.</p><p>Counters may not always be available. The counters could have been disabled at the command line (-c or --disable-counters) or occasionally the connection will register &quot;ready&quot; instead of &quot;online&quot;. Online is a &quot;ready&quot; connection that has verified internet connectivity. It is possible to be online with only a &quot;ready&quot; connection, however the counters only work for they &quot;online&quot; connection.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_roaming_counter->setTitle(QApplication::translate("ControlBox", "Roaming", 0));
        label_roam_counter->setText(QApplication::translate("ControlBox", "Counter not available.", 0));
#ifndef QT_NO_TOOLTIP
        label_counter_settings->setToolTip(QApplication::translate("ControlBox", "<html><head/><body><p>Counter Settings</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_counter_settings->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>The threshold values for counter updates (counter resolution).  Data and time work together to define how often the fields are updated.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_counter_settings->setText(QApplication::translate("ControlBox", "Settings:", 0));
        tabWidget->setTabText(tabWidget->indexOf(Counters), QApplication::translate("ControlBox", "&Counters", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_preferencesinterface->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Preferences for the interface are in this box.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_preferencesinterface->setTitle(QApplication::translate("ControlBox", "Interface", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_retainsettings->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>If checked the GUI will be restored from settings saved on disk. Settings include the geometry of the dialog and the state of various check boxes, such as this one. </p><p>These settings will be used at next boot to restore the user interface to the way it was at shutdown.</p><p style='white-space:pre'>The settings file is: <span style=\" font-weight:600;\">${HOME}/.config/cmst/cmst.conf  </span><br>This is a standard ini type text file.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_retainsettings->setText(QApplication::translate("ControlBox", "Retain Settings", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_enableinterfacetooltips->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>If checked the display of tooltips will be enabled for the interface widgets.</p><p>Tooltips are the small popups that appear when you hover the mouse pointer over an area of the interface. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_enableinterfacetooltips->setText(QApplication::translate("ControlBox", "Enable ToolTips (Interface)", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_resetcounters->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Normally counters are cummulative and will retain the connect time and the TX and RX counts between boots. </p><p>When this box is checked the counters will reset to zero every time CMST is started, and if CMST is running everytime a Connman service is started. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_resetcounters->setText(QApplication::translate("ControlBox", "Reset Counters", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_advanced->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>When checked additional controls for advanced users are displayed.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_advanced->setText(QApplication::translate("ControlBox", "Advanced Controls", 0));
#ifndef QT_NO_WHATSTHIS
        groupBox_systemtray->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Preferences for the system tray are in this box.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_systemtray->setTitle(QApplication::translate("ControlBox", "System Tray", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_hideIcon->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>If checked an icon will not be displayed in the system tray.  </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_hideIcon->setText(QApplication::translate("ControlBox", "Hide Tray Icon", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_enablesystemtraytooltips->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>If checked the system tray icon will popup a status message when you hover the mouse over it.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_enablesystemtraytooltips->setText(QApplication::translate("ControlBox", "Enable System Tray Popups", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_systemtraynotifications->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>If checked the system tray will popup a notify message when a significant connman related event is received.</p><p>Notifications can be handled by the System Tray Icon, or by a Notify daemon if one is installed.  Both can not be active at the same time.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_systemtraynotifications->setText(QApplication::translate("ControlBox", "System Tray Notifications", 0));
        groupBox_notfications->setTitle(QApplication::translate("ControlBox", "Notifications", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_notifydaemon->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>If checked the system desktop notification daemon will popup a notify message when a significant connman related event is received.</p><p>Notifications can be handled by the System Tray Icon, or by a Notification daemon if one is installed. Both can not be active at the same time.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_notifydaemon->setText(QApplication::translate("ControlBox", "Notification Daemon", 0));
        label_serverstatus->setText(QApplication::translate("ControlBox", "Server Status", 0));
        tabWidget->setTabText(tabWidget->indexOf(Preferences), QApplication::translate("ControlBox", "&Preferences", 0));
        groupBox_about->setTitle(QApplication::translate("ControlBox", "&About", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_aboutCMST->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Display a dialog box containing information about this program. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_aboutCMST->setText(QApplication::translate("ControlBox", "C&MST", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_aboutIconSet->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Display a dialog box containing information about the Icon set used in this program. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_aboutIconSet->setText(QApplication::translate("ControlBox", "&AwOken", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_aboutQT->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Display a dialog box containing information about the QT toolkit used to develop this program. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_aboutQT->setText(QApplication::translate("ControlBox", "&QT", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_license->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Use this button to view the program license.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_license->setText(QApplication::translate("ControlBox", "&License", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_change_log->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Use this button to view the change log of the program.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_change_log->setText(QApplication::translate("ControlBox", "ChangeLo&g", 0));
        label_help->setText(QApplication::translate("ControlBox", "<html><head/><body><p><span style=\" font-weight:600;\">Help</span></p><p>Program help is mainly provided by the &quot;What's This&quot; button in the lower left corner. Press the button and then click on an item you are interested in. &quot;What's This&quot; is also available via context menu by right clicking on a button, box or text area.</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(Help), QApplication::translate("ControlBox", "&Help", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_whatsthis->setToolTip(QApplication::translate("ControlBox", "<html><head/><body><p>What's This</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toolButton_whatsthis->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Use this button to find information about an element in the GUI by entering &quot;What's This&quot; mode. </p><p>You may also right click on an element to show the &quot;What's This&quot; text for it.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        toolButton_whatsthis->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_provisioning_editor->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Open the provisioning editor to create or edit Connman configuration (provisioning) files.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_provisioning_editor->setText(QApplication::translate("ControlBox", "Provisioning Editor", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_exit->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Exit the program and remove the system tray icon. Connman will still be running as a daemon but will not be managed by this program.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_exit->setText(QApplication::translate("ControlBox", "E&xit", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_minimize->setWhatsThis(QApplication::translate("ControlBox", "<html><head/><body><p>Minimize the dialog. If you have the system tray Icon shown this dialog may be restored by right clicking on the tray icon. If the tray icon is hidden minimize will not be active.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_minimize->setText(QApplication::translate("ControlBox", "Mi&nimize", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlBox: public Ui_ControlBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLBOX_H
