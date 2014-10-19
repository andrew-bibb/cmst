/********************************************************************************
** Form generated from reading UI file 'provisioning_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROVISIONING_EDITOR_H
#define UI_PROVISIONING_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Provisioning
{
public:
    QAction *actionFile_CA_Cert;
    QAction *actionFile_Client_Cert;
    QAction *actionFile_Private_Key;
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox_prov_ed;
    QWidget *general;
    QGridLayout *gridLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_description;
    QPlainTextEdit *plainTextEdit_description;
    QSpacerItem *verticalSpacer;
    QWidget *service;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout_5;
    QComboBox *comboBox_type;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_ipv4;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QComboBox *comboBox_ipv4method;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QLineEdit *lineEdit_ipv4address;
    QLabel *label_2;
    QLineEdit *lineEdit_ipv4netmask;
    QLabel *label_3;
    QLineEdit *lineEdit_ipv4gateway;
    QGroupBox *groupBox_ipv6;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QComboBox *comboBox_ipv6method;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_7;
    QSpinBox *spinBox_ipv6prefixlength;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_5;
    QLineEdit *lineEdit_ipv6address;
    QLabel *label_4;
    QLineEdit *lineEdit_ipv6gateway;
    QLabel *label_6;
    QComboBox *comboBox_ipv6privacy;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox_addresses;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLineEdit *lineEdit_macaddress;
    QLabel *label_14;
    QLineEdit *lineEdit_domain;
    QLabel *label_11;
    QLineEdit *lineEdit_nameservers;
    QLabel *label_12;
    QLineEdit *lineEdit_timeservers;
    QLabel *label_13;
    QLineEdit *lineEdit_searchdomains;
    QSpacerItem *verticalSpacer_2;
    QWidget *wifi;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_15;
    QLineEdit *lineEdit_wifiname;
    QLabel *label_16;
    QLineEdit *lineEdit_wifissid;
    QCheckBox *checkBox_wifihidden;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_eap;
    QGridLayout *gridLayout_7;
    QLabel *label_17;
    QComboBox *comboBox_eaptype;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_22;
    QLineEdit *lineEdit_eaptype;
    QGroupBox *groupBox_certificates;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_cacertfile;
    QLineEdit *lineEdit_cacertfile;
    QLineEdit *lineEdit_clientcertfile;
    QToolButton *toolButton_clientcertfile;
    QGroupBox *groupBox_security;
    QGridLayout *gridLayout_6;
    QLabel *label_25;
    QComboBox *comboBox_securitytype;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_23;
    QLineEdit *lineEdit_passphrase;
    QLabel *label_24;
    QLineEdit *lineEdit_phase2;
    QGroupBox *groupBox_privatekey;
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_privatekeyfile;
    QLineEdit *lineEdit_privatekeyfile;
    QLabel *label_26;
    QLineEdit *lineEdit_privatekeypassphrase;
    QLabel *label_27;
    QComboBox *comboBox_privatekeypassphrasetype;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_open;
    QPushButton *pushButton_save;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_resetpage;
    QPushButton *pushButton_resetall;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_whatsthis;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Provisioning)
    {
        if (Provisioning->objectName().isEmpty())
            Provisioning->setObjectName(QStringLiteral("Provisioning"));
        Provisioning->resize(482, 760);
        Provisioning->setSizeGripEnabled(true);
        actionFile_CA_Cert = new QAction(Provisioning);
        actionFile_CA_Cert->setObjectName(QStringLiteral("actionFile_CA_Cert"));
        actionFile_Client_Cert = new QAction(Provisioning);
        actionFile_Client_Cert->setObjectName(QStringLiteral("actionFile_Client_Cert"));
        actionFile_Private_Key = new QAction(Provisioning);
        actionFile_Private_Key->setObjectName(QStringLiteral("actionFile_Private_Key"));
        verticalLayout = new QVBoxLayout(Provisioning);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolBox_prov_ed = new QToolBox(Provisioning);
        toolBox_prov_ed->setObjectName(QStringLiteral("toolBox_prov_ed"));
        general = new QWidget();
        general->setObjectName(QStringLiteral("general"));
        general->setGeometry(QRect(0, 0, 464, 588));
        gridLayout = new QGridLayout(general);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_name = new QLabel(general);
        label_name->setObjectName(QStringLiteral("label_name"));

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(general);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        label_description = new QLabel(general);
        label_description->setObjectName(QStringLiteral("label_description"));
        label_description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_description, 1, 0, 1, 1);

        plainTextEdit_description = new QPlainTextEdit(general);
        plainTextEdit_description->setObjectName(QStringLiteral("plainTextEdit_description"));

        gridLayout->addWidget(plainTextEdit_description, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        toolBox_prov_ed->addItem(general, QStringLiteral("&General"));
        service = new QWidget();
        service->setObjectName(QStringLiteral("service"));
        service->setGeometry(QRect(0, 0, 450, 603));
        verticalLayout_2 = new QVBoxLayout(service);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(service);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout_5 = new QFormLayout(groupBox);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        comboBox_type = new QComboBox(groupBox);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, comboBox_type);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_5->setItem(0, QFormLayout::FieldRole, horizontalSpacer);


        verticalLayout_2->addWidget(groupBox);

        groupBox_ipv4 = new QGroupBox(service);
        groupBox_ipv4->setObjectName(QStringLiteral("groupBox_ipv4"));
        gridLayout_8 = new QGridLayout(groupBox_ipv4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_8 = new QLabel(groupBox_ipv4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        comboBox_ipv4method = new QComboBox(groupBox_ipv4);
        comboBox_ipv4method->setObjectName(QStringLiteral("comboBox_ipv4method"));

        gridLayout_8->addWidget(comboBox_ipv4method, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(265, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        label = new QLabel(groupBox_ipv4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_8->addWidget(label, 1, 0, 1, 1);

        lineEdit_ipv4address = new QLineEdit(groupBox_ipv4);
        lineEdit_ipv4address->setObjectName(QStringLiteral("lineEdit_ipv4address"));

        gridLayout_8->addWidget(lineEdit_ipv4address, 1, 1, 1, 2);

        label_2 = new QLabel(groupBox_ipv4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_8->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_ipv4netmask = new QLineEdit(groupBox_ipv4);
        lineEdit_ipv4netmask->setObjectName(QStringLiteral("lineEdit_ipv4netmask"));

        gridLayout_8->addWidget(lineEdit_ipv4netmask, 2, 1, 1, 2);

        label_3 = new QLabel(groupBox_ipv4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_8->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_ipv4gateway = new QLineEdit(groupBox_ipv4);
        lineEdit_ipv4gateway->setObjectName(QStringLiteral("lineEdit_ipv4gateway"));

        gridLayout_8->addWidget(lineEdit_ipv4gateway, 3, 1, 1, 2);


        verticalLayout_2->addWidget(groupBox_ipv4);

        groupBox_ipv6 = new QGroupBox(service);
        groupBox_ipv6->setObjectName(QStringLiteral("groupBox_ipv6"));
        gridLayout_9 = new QGridLayout(groupBox_ipv6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_9 = new QLabel(groupBox_ipv6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);

        comboBox_ipv6method = new QComboBox(groupBox_ipv6);
        comboBox_ipv6method->setObjectName(QStringLiteral("comboBox_ipv6method"));

        gridLayout_9->addWidget(comboBox_ipv6method, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        label_7 = new QLabel(groupBox_ipv6);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_9->addWidget(label_7, 1, 0, 1, 1);

        spinBox_ipv6prefixlength = new QSpinBox(groupBox_ipv6);
        spinBox_ipv6prefixlength->setObjectName(QStringLiteral("spinBox_ipv6prefixlength"));
        spinBox_ipv6prefixlength->setMaximum(255);

        gridLayout_9->addWidget(spinBox_ipv6prefixlength, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(237, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_8, 1, 2, 1, 2);

        label_5 = new QLabel(groupBox_ipv6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_9->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_ipv6address = new QLineEdit(groupBox_ipv6);
        lineEdit_ipv6address->setObjectName(QStringLiteral("lineEdit_ipv6address"));

        gridLayout_9->addWidget(lineEdit_ipv6address, 2, 1, 1, 3);

        label_4 = new QLabel(groupBox_ipv6);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_9->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_ipv6gateway = new QLineEdit(groupBox_ipv6);
        lineEdit_ipv6gateway->setObjectName(QStringLiteral("lineEdit_ipv6gateway"));

        gridLayout_9->addWidget(lineEdit_ipv6gateway, 3, 1, 1, 3);

        label_6 = new QLabel(groupBox_ipv6);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_9->addWidget(label_6, 4, 0, 1, 1);

        comboBox_ipv6privacy = new QComboBox(groupBox_ipv6);
        comboBox_ipv6privacy->setObjectName(QStringLiteral("comboBox_ipv6privacy"));
        comboBox_ipv6privacy->setMinimumSize(QSize(100, 0));

        gridLayout_9->addWidget(comboBox_ipv6privacy, 4, 1, 1, 2);

        horizontalSpacer_9 = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_9, 4, 3, 1, 1);


        verticalLayout_2->addWidget(groupBox_ipv6);

        groupBox_addresses = new QGroupBox(service);
        groupBox_addresses->setObjectName(QStringLiteral("groupBox_addresses"));
        formLayout = new QFormLayout(groupBox_addresses);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_10 = new QLabel(groupBox_addresses);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEdit_macaddress = new QLineEdit(groupBox_addresses);
        lineEdit_macaddress->setObjectName(QStringLiteral("lineEdit_macaddress"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_macaddress);

        label_14 = new QLabel(groupBox_addresses);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_14);

        lineEdit_domain = new QLineEdit(groupBox_addresses);
        lineEdit_domain->setObjectName(QStringLiteral("lineEdit_domain"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_domain);

        label_11 = new QLabel(groupBox_addresses);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        lineEdit_nameservers = new QLineEdit(groupBox_addresses);
        lineEdit_nameservers->setObjectName(QStringLiteral("lineEdit_nameservers"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_nameservers);

        label_12 = new QLabel(groupBox_addresses);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_12);

        lineEdit_timeservers = new QLineEdit(groupBox_addresses);
        lineEdit_timeservers->setObjectName(QStringLiteral("lineEdit_timeservers"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_timeservers);

        label_13 = new QLabel(groupBox_addresses);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_13);

        lineEdit_searchdomains = new QLineEdit(groupBox_addresses);
        lineEdit_searchdomains->setObjectName(QStringLiteral("lineEdit_searchdomains"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_searchdomains);


        verticalLayout_2->addWidget(groupBox_addresses);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        toolBox_prov_ed->addItem(service, QStringLiteral("&Service"));
        wifi = new QWidget();
        wifi->setObjectName(QStringLiteral("wifi"));
        wifi->setGeometry(QRect(0, 0, 464, 588));
        gridLayout_5 = new QGridLayout(wifi);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_4 = new QGroupBox(wifi);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 0, 0, 1, 1);

        lineEdit_wifiname = new QLineEdit(groupBox_4);
        lineEdit_wifiname->setObjectName(QStringLiteral("lineEdit_wifiname"));

        gridLayout_4->addWidget(lineEdit_wifiname, 0, 1, 1, 2);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_4->addWidget(label_16, 1, 0, 1, 1);

        lineEdit_wifissid = new QLineEdit(groupBox_4);
        lineEdit_wifissid->setObjectName(QStringLiteral("lineEdit_wifissid"));

        gridLayout_4->addWidget(lineEdit_wifissid, 1, 1, 1, 2);

        checkBox_wifihidden = new QCheckBox(groupBox_4);
        checkBox_wifihidden->setObjectName(QStringLiteral("checkBox_wifihidden"));

        gridLayout_4->addWidget(checkBox_wifihidden, 2, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 2, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_eap = new QGroupBox(wifi);
        groupBox_eap->setObjectName(QStringLiteral("groupBox_eap"));
        gridLayout_7 = new QGridLayout(groupBox_eap);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_17 = new QLabel(groupBox_eap);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_7->addWidget(label_17, 0, 0, 1, 1);

        comboBox_eaptype = new QComboBox(groupBox_eap);
        comboBox_eaptype->setObjectName(QStringLiteral("comboBox_eaptype"));

        gridLayout_7->addWidget(comboBox_eaptype, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(290, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        label_22 = new QLabel(groupBox_eap);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_7->addWidget(label_22, 1, 0, 1, 1);

        lineEdit_eaptype = new QLineEdit(groupBox_eap);
        lineEdit_eaptype->setObjectName(QStringLiteral("lineEdit_eaptype"));

        gridLayout_7->addWidget(lineEdit_eaptype, 1, 1, 1, 2);


        gridLayout_5->addWidget(groupBox_eap, 1, 0, 1, 1);

        groupBox_certificates = new QGroupBox(wifi);
        groupBox_certificates->setObjectName(QStringLiteral("groupBox_certificates"));
        gridLayout_2 = new QGridLayout(groupBox_certificates);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        toolButton_cacertfile = new QToolButton(groupBox_certificates);
        toolButton_cacertfile->setObjectName(QStringLiteral("toolButton_cacertfile"));

        gridLayout_2->addWidget(toolButton_cacertfile, 0, 0, 1, 1);

        lineEdit_cacertfile = new QLineEdit(groupBox_certificates);
        lineEdit_cacertfile->setObjectName(QStringLiteral("lineEdit_cacertfile"));

        gridLayout_2->addWidget(lineEdit_cacertfile, 0, 1, 1, 1);

        lineEdit_clientcertfile = new QLineEdit(groupBox_certificates);
        lineEdit_clientcertfile->setObjectName(QStringLiteral("lineEdit_clientcertfile"));

        gridLayout_2->addWidget(lineEdit_clientcertfile, 1, 1, 1, 1);

        toolButton_clientcertfile = new QToolButton(groupBox_certificates);
        toolButton_clientcertfile->setObjectName(QStringLiteral("toolButton_clientcertfile"));

        gridLayout_2->addWidget(toolButton_clientcertfile, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_certificates, 2, 0, 1, 1);

        groupBox_security = new QGroupBox(wifi);
        groupBox_security->setObjectName(QStringLiteral("groupBox_security"));
        gridLayout_6 = new QGridLayout(groupBox_security);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_25 = new QLabel(groupBox_security);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_6->addWidget(label_25, 0, 0, 1, 1);

        comboBox_securitytype = new QComboBox(groupBox_security);
        comboBox_securitytype->setObjectName(QStringLiteral("comboBox_securitytype"));

        gridLayout_6->addWidget(comboBox_securitytype, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(230, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        label_23 = new QLabel(groupBox_security);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_6->addWidget(label_23, 1, 0, 1, 1);

        lineEdit_passphrase = new QLineEdit(groupBox_security);
        lineEdit_passphrase->setObjectName(QStringLiteral("lineEdit_passphrase"));

        gridLayout_6->addWidget(lineEdit_passphrase, 1, 1, 1, 2);

        label_24 = new QLabel(groupBox_security);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_6->addWidget(label_24, 2, 0, 1, 1);

        lineEdit_phase2 = new QLineEdit(groupBox_security);
        lineEdit_phase2->setObjectName(QStringLiteral("lineEdit_phase2"));

        gridLayout_6->addWidget(lineEdit_phase2, 2, 1, 1, 2);


        gridLayout_5->addWidget(groupBox_security, 4, 0, 1, 1);

        groupBox_privatekey = new QGroupBox(wifi);
        groupBox_privatekey->setObjectName(QStringLiteral("groupBox_privatekey"));
        gridLayout_3 = new QGridLayout(groupBox_privatekey);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        toolButton_privatekeyfile = new QToolButton(groupBox_privatekey);
        toolButton_privatekeyfile->setObjectName(QStringLiteral("toolButton_privatekeyfile"));

        gridLayout_3->addWidget(toolButton_privatekeyfile, 0, 0, 1, 1);

        lineEdit_privatekeyfile = new QLineEdit(groupBox_privatekey);
        lineEdit_privatekeyfile->setObjectName(QStringLiteral("lineEdit_privatekeyfile"));

        gridLayout_3->addWidget(lineEdit_privatekeyfile, 0, 1, 1, 2);

        label_26 = new QLabel(groupBox_privatekey);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_3->addWidget(label_26, 1, 0, 1, 1);

        lineEdit_privatekeypassphrase = new QLineEdit(groupBox_privatekey);
        lineEdit_privatekeypassphrase->setObjectName(QStringLiteral("lineEdit_privatekeypassphrase"));

        gridLayout_3->addWidget(lineEdit_privatekeypassphrase, 1, 1, 1, 2);

        label_27 = new QLabel(groupBox_privatekey);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_3->addWidget(label_27, 2, 0, 1, 1);

        comboBox_privatekeypassphrasetype = new QComboBox(groupBox_privatekey);
        comboBox_privatekeypassphrasetype->setObjectName(QStringLiteral("comboBox_privatekeypassphrasetype"));

        gridLayout_3->addWidget(comboBox_privatekeypassphrasetype, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_privatekey, 3, 0, 1, 1);

        toolBox_prov_ed->addItem(wifi, QStringLiteral("&Wifi"));

        verticalLayout->addWidget(toolBox_prov_ed);

        line = new QFrame(Provisioning);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_open = new QPushButton(Provisioning);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));

        horizontalLayout->addWidget(pushButton_open);

        pushButton_save = new QPushButton(Provisioning);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setEnabled(true);

        horizontalLayout->addWidget(pushButton_save);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_resetpage = new QPushButton(Provisioning);
        pushButton_resetpage->setObjectName(QStringLiteral("pushButton_resetpage"));

        horizontalLayout->addWidget(pushButton_resetpage);

        pushButton_resetall = new QPushButton(Provisioning);
        pushButton_resetall->setObjectName(QStringLiteral("pushButton_resetall"));

        horizontalLayout->addWidget(pushButton_resetall);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton_whatsthis = new QToolButton(Provisioning);
        toolButton_whatsthis->setObjectName(QStringLiteral("toolButton_whatsthis"));

        horizontalLayout_2->addWidget(toolButton_whatsthis);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_cancel = new QPushButton(Provisioning);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Provisioning);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), Provisioning, SLOT(reject()));

        toolBox_prov_ed->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Provisioning);
    } // setupUi

    void retranslateUi(QDialog *Provisioning)
    {
        Provisioning->setWindowTitle(QApplication::translate("Provisioning", "Provisioning Editor", 0));
        actionFile_CA_Cert->setText(QApplication::translate("Provisioning", "CA Certificate", 0));
#ifndef QT_NO_TOOLTIP
        actionFile_CA_Cert->setToolTip(QApplication::translate("Provisioning", "Select File", 0));
#endif // QT_NO_TOOLTIP
        actionFile_Client_Cert->setText(QApplication::translate("Provisioning", "Client Certificate", 0));
#ifndef QT_NO_TOOLTIP
        actionFile_Client_Cert->setToolTip(QApplication::translate("Provisioning", "Select File", 0));
#endif // QT_NO_TOOLTIP
        actionFile_Private_Key->setText(QApplication::translate("Provisioning", "Private Key File", 0));
#ifndef QT_NO_TOOLTIP
        actionFile_Private_Key->setToolTip(QApplication::translate("Provisioning", "Select File", 0));
#endif // QT_NO_TOOLTIP
        label_name->setText(QApplication::translate("Provisioning", "Name", 0));
        label_description->setText(QApplication::translate("Provisioning", "Description", 0));
        toolBox_prov_ed->setItemText(toolBox_prov_ed->indexOf(general), QApplication::translate("Provisioning", "&General", 0));
        groupBox->setTitle(QApplication::translate("Provisioning", "Type", 0));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("Provisioning", "ethernet", 0)
         << QApplication::translate("Provisioning", "wifi", 0)
        );
        groupBox_ipv4->setTitle(QApplication::translate("Provisioning", "IPV4", 0));
        label_8->setText(QApplication::translate("Provisioning", "Method", 0));
        comboBox_ipv4method->clear();
        comboBox_ipv4method->insertItems(0, QStringList()
         << QApplication::translate("Provisioning", "DHCP", 0)
         << QApplication::translate("Provisioning", "Manual", 0)
         << QApplication::translate("Provisioning", "Off", 0)
        );
        label->setText(QApplication::translate("Provisioning", "Address", 0));
        label_2->setText(QApplication::translate("Provisioning", "Netmask", 0));
        label_3->setText(QApplication::translate("Provisioning", "Gateway", 0));
        groupBox_ipv6->setTitle(QApplication::translate("Provisioning", "IPV6", 0));
        label_9->setText(QApplication::translate("Provisioning", "Method", 0));
        comboBox_ipv6method->clear();
        comboBox_ipv6method->insertItems(0, QStringList()
         << QApplication::translate("Provisioning", "Auto", 0)
         << QApplication::translate("Provisioning", "Manual", 0)
         << QApplication::translate("Provisioning", "Off", 0)
        );
        label_7->setText(QApplication::translate("Provisioning", "Prefix Length", 0));
        label_5->setText(QApplication::translate("Provisioning", "Address", 0));
        label_4->setText(QApplication::translate("Provisioning", "Gateway", 0));
        label_6->setText(QApplication::translate("Provisioning", "Privacy", 0));
        comboBox_ipv6privacy->clear();
        comboBox_ipv6privacy->insertItems(0, QStringList()
         << QApplication::translate("Provisioning", "Disabled", 0)
         << QApplication::translate("Provisioning", "Preferred", 0)
         << QApplication::translate("Provisioning", "Enabled", 0)
        );
        groupBox_addresses->setTitle(QApplication::translate("Provisioning", "Addresses", 0));
        label_10->setText(QApplication::translate("Provisioning", "MAC Address", 0));
        label_14->setText(QApplication::translate("Provisioning", "Domain", 0));
        label_11->setText(QApplication::translate("Provisioning", "Name Servers", 0));
        label_12->setText(QApplication::translate("Provisioning", "Time Servers", 0));
        label_13->setText(QApplication::translate("Provisioning", "Search Domains", 0));
        toolBox_prov_ed->setItemText(toolBox_prov_ed->indexOf(service), QApplication::translate("Provisioning", "&Service", 0));
        groupBox_4->setTitle(QApplication::translate("Provisioning", "Need some good name", 0));
        label_15->setText(QApplication::translate("Provisioning", "Name", 0));
        label_16->setText(QApplication::translate("Provisioning", "SSID", 0));
        checkBox_wifihidden->setText(QApplication::translate("Provisioning", "Hidden", 0));
        groupBox_eap->setTitle(QApplication::translate("Provisioning", "Extensible Authentication Protocol", 0));
        label_17->setText(QApplication::translate("Provisioning", "EAP Type", 0));
        comboBox_eaptype->clear();
        comboBox_eaptype->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Provisioning", "tls", 0)
         << QApplication::translate("Provisioning", "ttls", 0)
         << QApplication::translate("Provisioning", "peap", 0)
        );
        label_22->setText(QApplication::translate("Provisioning", "Identity", 0));
        groupBox_certificates->setTitle(QApplication::translate("Provisioning", "Certificates", 0));
        toolButton_cacertfile->setText(QApplication::translate("Provisioning", "...", 0));
        toolButton_clientcertfile->setText(QApplication::translate("Provisioning", "...", 0));
        groupBox_security->setTitle(QApplication::translate("Provisioning", "Security", 0));
        label_25->setText(QApplication::translate("Provisioning", "Security Type", 0));
        comboBox_securitytype->clear();
        comboBox_securitytype->insertItems(0, QStringList()
         << QApplication::translate("Provisioning", "none", 0)
         << QApplication::translate("Provisioning", "psk", 0)
         << QApplication::translate("Provisioning", "ieee8021x", 0)
         << QApplication::translate("Provisioning", "wep", 0)
        );
        label_23->setText(QApplication::translate("Provisioning", "Passphrase", 0));
        label_24->setText(QApplication::translate("Provisioning", "Phase 2", 0));
        groupBox_privatekey->setTitle(QApplication::translate("Provisioning", "Private Key", 0));
        toolButton_privatekeyfile->setText(QApplication::translate("Provisioning", "...", 0));
        label_26->setText(QApplication::translate("Provisioning", "Private Key<br>Passphrase", 0));
        label_27->setText(QApplication::translate("Provisioning", "Passphrase Type", 0));
        comboBox_privatekeypassphrasetype->clear();
        comboBox_privatekeypassphrasetype->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Provisioning", "fsid", 0)
        );
        toolBox_prov_ed->setItemText(toolBox_prov_ed->indexOf(wifi), QApplication::translate("Provisioning", "&Wifi", 0));
        pushButton_open->setText(QApplication::translate("Provisioning", "&Open", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_save->setWhatsThis(QApplication::translate("Provisioning", "<html><head/><body><p>Accept the entries, send them to Connman, and close the dialog.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_save->setText(QApplication::translate("Provisioning", "Sa&ve", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_resetpage->setWhatsThis(QApplication::translate("Provisioning", "<html><head/><body><p>Clear all entries on the current page.</p><p>This button will reset every field on the current page to the default value, which generally means nothing in the field.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_resetpage->setText(QApplication::translate("Provisioning", "Reset &Page", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_resetall->setWhatsThis(QApplication::translate("Provisioning", "<html><head/><body><p>Clear all fields on every page of the dialog.</p><p>This will reset every field on every page to the default value for the field. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_resetall->setText(QApplication::translate("Provisioning", "Reset &All", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_whatsthis->setToolTip(QApplication::translate("Provisioning", "<html><head/><body><p>What's This</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        toolButton_whatsthis->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_cancel->setWhatsThis(QApplication::translate("Provisioning", "<html><head/><body><p>Close the dialog without sending any entries to Connman.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_cancel->setText(QApplication::translate("Provisioning", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Provisioning: public Ui_Provisioning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROVISIONING_EDITOR_H
