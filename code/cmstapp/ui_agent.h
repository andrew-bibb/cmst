/********************************************************************************
** Form generated from reading UI file 'agent.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENT_H
#define UI_AGENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Agent
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_01;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_passphrase;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_old_passphrase;
    QLineEdit *lineEdit_passphrase;
    QCheckBox *checkBox_hide_passphrase;
    QLabel *label_old_passphrase;
    QLabel *label_passphrase;
    QGroupBox *groupBox_hidden_network;
    QGridLayout *gridLayout_4;
    QLabel *label_hidden_name;
    QLineEdit *lineEdit_hidden_name;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QLabel *label_ssid;
    QLineEdit *lineEdit_ssid;
    QGroupBox *groupBox_wispr;
    QGridLayout *gridLayout_6;
    QLabel *label_wispr_username;
    QLineEdit *lineEdit_wispr_username;
    QLabel *label_wispr_password;
    QLineEdit *lineEdit_wispr_password;
    QGroupBox *groupBox_eap;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_eap_identity;
    QLabel *label_eap_identity;
    QGroupBox *groupBox_wps;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_wps_no_pin;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_wps_pin;
    QLineEdit *lineEdit_wps_pin;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_browser;
    QGridLayout *gridLayout_7;
    QLabel *label_browser_url;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_url;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_firefox;
    QRadioButton *radioButton_opera;
    QRadioButton *radioButton_luakit;
    QRadioButton *radioButton_lynx;
    QRadioButton *radioButton_other;
    QLineEdit *lineEdit_other_browser;
    QPushButton *pushButton_launch_browser;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_whatsthis;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Agent)
    {
        if (Agent->objectName().isEmpty())
            Agent->setObjectName(QStringLiteral("Agent"));
        Agent->resize(386, 587);
        gridLayout = new QGridLayout(Agent);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(Agent);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_01 = new QWidget();
        page_01->setObjectName(QStringLiteral("page_01"));
        verticalLayout_2 = new QVBoxLayout(page_01);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_passphrase = new QGroupBox(page_01);
        groupBox_passphrase->setObjectName(QStringLiteral("groupBox_passphrase"));
        gridLayout_2 = new QGridLayout(groupBox_passphrase);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        lineEdit_old_passphrase = new QLineEdit(groupBox_passphrase);
        lineEdit_old_passphrase->setObjectName(QStringLiteral("lineEdit_old_passphrase"));

        gridLayout_2->addWidget(lineEdit_old_passphrase, 1, 1, 1, 2);

        lineEdit_passphrase = new QLineEdit(groupBox_passphrase);
        lineEdit_passphrase->setObjectName(QStringLiteral("lineEdit_passphrase"));

        gridLayout_2->addWidget(lineEdit_passphrase, 0, 1, 1, 2);

        checkBox_hide_passphrase = new QCheckBox(groupBox_passphrase);
        checkBox_hide_passphrase->setObjectName(QStringLiteral("checkBox_hide_passphrase"));

        gridLayout_2->addWidget(checkBox_hide_passphrase, 2, 0, 1, 2);

        label_old_passphrase = new QLabel(groupBox_passphrase);
        label_old_passphrase->setObjectName(QStringLiteral("label_old_passphrase"));

        gridLayout_2->addWidget(label_old_passphrase, 1, 0, 1, 1);

        label_passphrase = new QLabel(groupBox_passphrase);
        label_passphrase->setObjectName(QStringLiteral("label_passphrase"));

        gridLayout_2->addWidget(label_passphrase, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_passphrase);

        groupBox_hidden_network = new QGroupBox(page_01);
        groupBox_hidden_network->setObjectName(QStringLiteral("groupBox_hidden_network"));
        gridLayout_4 = new QGridLayout(groupBox_hidden_network);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_hidden_name = new QLabel(groupBox_hidden_network);
        label_hidden_name->setObjectName(QStringLiteral("label_hidden_name"));

        gridLayout_4->addWidget(label_hidden_name, 0, 0, 1, 1);

        lineEdit_hidden_name = new QLineEdit(groupBox_hidden_network);
        lineEdit_hidden_name->setObjectName(QStringLiteral("lineEdit_hidden_name"));

        gridLayout_4->addWidget(lineEdit_hidden_name, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_hidden_network);

        groupBox = new QGroupBox(page_01);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_ssid = new QLabel(groupBox);
        label_ssid->setObjectName(QStringLiteral("label_ssid"));

        gridLayout_8->addWidget(label_ssid, 0, 0, 1, 1);

        lineEdit_ssid = new QLineEdit(groupBox);
        lineEdit_ssid->setObjectName(QStringLiteral("lineEdit_ssid"));

        gridLayout_8->addWidget(lineEdit_ssid, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_wispr = new QGroupBox(page_01);
        groupBox_wispr->setObjectName(QStringLiteral("groupBox_wispr"));
        gridLayout_6 = new QGridLayout(groupBox_wispr);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_wispr_username = new QLabel(groupBox_wispr);
        label_wispr_username->setObjectName(QStringLiteral("label_wispr_username"));

        gridLayout_6->addWidget(label_wispr_username, 0, 0, 1, 1);

        lineEdit_wispr_username = new QLineEdit(groupBox_wispr);
        lineEdit_wispr_username->setObjectName(QStringLiteral("lineEdit_wispr_username"));

        gridLayout_6->addWidget(lineEdit_wispr_username, 0, 1, 1, 1);

        label_wispr_password = new QLabel(groupBox_wispr);
        label_wispr_password->setObjectName(QStringLiteral("label_wispr_password"));

        gridLayout_6->addWidget(label_wispr_password, 1, 0, 1, 1);

        lineEdit_wispr_password = new QLineEdit(groupBox_wispr);
        lineEdit_wispr_password->setObjectName(QStringLiteral("lineEdit_wispr_password"));

        gridLayout_6->addWidget(lineEdit_wispr_password, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_wispr);

        groupBox_eap = new QGroupBox(page_01);
        groupBox_eap->setObjectName(QStringLiteral("groupBox_eap"));
        gridLayout_5 = new QGridLayout(groupBox_eap);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lineEdit_eap_identity = new QLineEdit(groupBox_eap);
        lineEdit_eap_identity->setObjectName(QStringLiteral("lineEdit_eap_identity"));

        gridLayout_5->addWidget(lineEdit_eap_identity, 1, 1, 1, 1);

        label_eap_identity = new QLabel(groupBox_eap);
        label_eap_identity->setObjectName(QStringLiteral("label_eap_identity"));

        gridLayout_5->addWidget(label_eap_identity, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_eap);

        groupBox_wps = new QGroupBox(page_01);
        groupBox_wps->setObjectName(QStringLiteral("groupBox_wps"));
        verticalLayout = new QVBoxLayout(groupBox_wps);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_wps_no_pin = new QCheckBox(groupBox_wps);
        checkBox_wps_no_pin->setObjectName(QStringLiteral("checkBox_wps_no_pin"));

        horizontalLayout->addWidget(checkBox_wps_no_pin);

        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_wps_pin = new QLabel(groupBox_wps);
        label_wps_pin->setObjectName(QStringLiteral("label_wps_pin"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_wps_pin->sizePolicy().hasHeightForWidth());
        label_wps_pin->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_wps_pin);

        lineEdit_wps_pin = new QLineEdit(groupBox_wps);
        lineEdit_wps_pin->setObjectName(QStringLiteral("lineEdit_wps_pin"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_wps_pin->sizePolicy().hasHeightForWidth());
        lineEdit_wps_pin->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_wps_pin);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_wps);

        stackedWidget->addWidget(page_01);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_browser = new QGroupBox(page_2);
        groupBox_browser->setObjectName(QStringLiteral("groupBox_browser"));
        gridLayout_7 = new QGridLayout(groupBox_browser);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_browser_url = new QLabel(groupBox_browser);
        label_browser_url->setObjectName(QStringLiteral("label_browser_url"));
        label_browser_url->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_browser_url->setWordWrap(true);

        gridLayout_7->addWidget(label_browser_url, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(groupBox_browser);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        lineEdit_url = new QLineEdit(groupBox_browser);
        lineEdit_url->setObjectName(QStringLiteral("lineEdit_url"));
        lineEdit_url->setReadOnly(true);

        verticalLayout_4->addWidget(lineEdit_url);


        gridLayout_7->addLayout(verticalLayout_4, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        radioButton_firefox = new QRadioButton(groupBox_browser);
        radioButton_firefox->setObjectName(QStringLiteral("radioButton_firefox"));

        gridLayout_3->addWidget(radioButton_firefox, 0, 0, 1, 1);

        radioButton_opera = new QRadioButton(groupBox_browser);
        radioButton_opera->setObjectName(QStringLiteral("radioButton_opera"));

        gridLayout_3->addWidget(radioButton_opera, 0, 1, 1, 1);

        radioButton_luakit = new QRadioButton(groupBox_browser);
        radioButton_luakit->setObjectName(QStringLiteral("radioButton_luakit"));

        gridLayout_3->addWidget(radioButton_luakit, 1, 0, 1, 1);

        radioButton_lynx = new QRadioButton(groupBox_browser);
        radioButton_lynx->setObjectName(QStringLiteral("radioButton_lynx"));

        gridLayout_3->addWidget(radioButton_lynx, 1, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 2, 0, 1, 1);

        radioButton_other = new QRadioButton(groupBox_browser);
        radioButton_other->setObjectName(QStringLiteral("radioButton_other"));

        gridLayout_7->addWidget(radioButton_other, 3, 0, 1, 1);

        lineEdit_other_browser = new QLineEdit(groupBox_browser);
        lineEdit_other_browser->setObjectName(QStringLiteral("lineEdit_other_browser"));

        gridLayout_7->addWidget(lineEdit_other_browser, 4, 0, 1, 1);

        pushButton_launch_browser = new QPushButton(groupBox_browser);
        pushButton_launch_browser->setObjectName(QStringLiteral("pushButton_launch_browser"));

        gridLayout_7->addWidget(pushButton_launch_browser, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 6, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_browser);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        toolButton_whatsthis = new QToolButton(Agent);
        toolButton_whatsthis->setObjectName(QStringLiteral("toolButton_whatsthis"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons16x16/images/16x16/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_whatsthis->setIcon(icon);

        horizontalLayout_3->addWidget(toolButton_whatsthis);

        horizontalSpacer_3 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_accept = new QPushButton(Agent);
        pushButton_accept->setObjectName(QStringLiteral("pushButton_accept"));

        horizontalLayout_3->addWidget(pushButton_accept);

        pushButton_cancel = new QPushButton(Agent);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_old_passphrase->setBuddy(lineEdit_old_passphrase);
        label_passphrase->setBuddy(lineEdit_passphrase);
        label_hidden_name->setBuddy(lineEdit_hidden_name);
        label_ssid->setBuddy(lineEdit_ssid);
        label_wispr_username->setBuddy(lineEdit_wispr_username);
        label_wispr_password->setBuddy(lineEdit_wispr_password);
        label_eap_identity->setBuddy(lineEdit_eap_identity);
        label_wps_pin->setBuddy(lineEdit_wps_pin);
#endif // QT_NO_SHORTCUT

        retranslateUi(Agent);
        QObject::connect(pushButton_accept, SIGNAL(clicked()), Agent, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), Agent, SLOT(reject()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Agent);
    } // setupUi

    void retranslateUi(QDialog *Agent)
    {
        Agent->setWindowTitle(QApplication::translate("Agent", "Agent Input", 0));
        groupBox_passphrase->setTitle(QApplication::translate("Agent", "Passphrase", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_old_passphrase->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>If an old passphrase is avaliable it will be shown here for reference.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        lineEdit_passphrase->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Type the passphrase here.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        lineEdit_passphrase->setText(QString());
#ifndef QT_NO_WHATSTHIS
        checkBox_hide_passphrase->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Check this box to obscure the password characters.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_hide_passphrase->setText(QApplication::translate("Agent", "&Hide Passphrase", 0));
        label_old_passphrase->setText(QApplication::translate("Agent", "&Old Passphrase", 0));
        label_passphrase->setText(QApplication::translate("Agent", "&Passphrase", 0));
        groupBox_hidden_network->setTitle(QApplication::translate("Agent", "Hidden Network", 0));
        label_hidden_name->setText(QApplication::translate("Agent", "&Name", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_hidden_name->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Type the name of the hidden network you wish to connect to.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("Agent", "Service Set Identifier", 0));
        label_ssid->setText(QApplication::translate("Agent", "&SDID", 0));
        groupBox_wispr->setTitle(QApplication::translate("Agent", "Wireless Internet Service Provider roaming (WISPr)", 0));
        label_wispr_username->setText(QApplication::translate("Agent", "&Username", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_wispr_username->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>WISPr username.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_wispr_password->setText(QApplication::translate("Agent", "Passwor&d", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_wispr_password->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>WISPr password.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_eap->setTitle(QApplication::translate("Agent", "Extensible Authentication Protocol (EAP)", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_eap_identity->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Type your Identity for the Extensible Authentication Protocol</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_eap_identity->setText(QApplication::translate("Agent", "&Identity", 0));
        groupBox_wps->setTitle(QApplication::translate("Agent", "WiFi Protected Setup (WPS)", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_wps_no_pin->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>When checked use WPS push button authentication.  </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_wps_no_pin->setText(QApplication::translate("Agent", "Use Push &Button Authentication", 0));
        label_wps_pin->setText(QApplication::translate("Agent", "&WPS Pin", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_wps_pin->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Enter a WPS pin.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_browser->setTitle(QApplication::translate("Agent", "Browser Login Requested", 0));
        label_browser_url->setText(QApplication::translate("Agent", "<html><head/><body><p>Connman is requesting that you open a web browser to complete the login process.</p><p>We have scanned your PATH for browsers and any browsers we found are shown below as active. You may select any one browser to use it for the login. If your web browser is not shown active, or is not listed at all, select <span style=\" font-weight:600;\">Other</span> and type the command you would use to start your browser from a command line in the text box. To launch the browser click the <span style=\" font-weight:600;\">Launch Browser</span> button. </p><p>If you wish to login manually close this dialog, start your web browser and proceed to the URL shown below:</p></body></html>", 0));
        label->setText(QApplication::translate("Agent", "Login URL:", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_url->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Connman is requesting you continue login with a web browser. This box shows the URL that contains the login page.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        radioButton_firefox->setToolTip(QApplication::translate("Agent", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_firefox->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Use  the Firefox browser.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        radioButton_firefox->setText(QApplication::translate("Agent", "&Firefox", 0));
#ifndef QT_NO_WHATSTHIS
        radioButton_opera->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Use the Opera browser.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        radioButton_opera->setText(QApplication::translate("Agent", "&Opera", 0));
#ifndef QT_NO_WHATSTHIS
        radioButton_luakit->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Use the Luakit browser.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        radioButton_luakit->setText(QApplication::translate("Agent", "&Luakit", 0));
#ifndef QT_NO_WHATSTHIS
        radioButton_lynx->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Use the Lynx (console mode) browser.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        radioButton_lynx->setText(QApplication::translate("Agent", "Lyn&x", 0));
#ifndef QT_NO_WHATSTHIS
        radioButton_other->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Login using a browser that is not listed.  Type the browser start command in the box below.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        radioButton_other->setText(QApplication::translate("Agent", "Othe&r", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_other_browser->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Type the browser start command here.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        pushButton_launch_browser->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Use this button to launch the selected browser. The browser will open at the page shown in the Login URL box.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_launch_browser->setText(QApplication::translate("Agent", "Launch &Browser", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_whatsthis->setToolTip(QApplication::translate("Agent", "<html><head/><body><p>What's This</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        toolButton_whatsthis->setText(QApplication::translate("Agent", "...", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_accept->setToolTip(QApplication::translate("Agent", "<html><head/><body><p>Continue the connection process.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_accept->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Accept and use the answers you have provided in this dialog. </p><p>This will send your input to the connman daemon to continue the connection process.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_accept->setText(QApplication::translate("Agent", "O&K", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_cancel->setToolTip(QApplication::translate("Agent", "<html><head/><body><p>Cancel the connection process.<br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_cancel->setWhatsThis(QApplication::translate("Agent", "<html><head/><body><p>Cancel the dialog. </p><p>This will send a message to the connman daemon that you have cancelled the connection request.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_cancel->setText(QApplication::translate("Agent", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Agent: public Ui_Agent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENT_H
