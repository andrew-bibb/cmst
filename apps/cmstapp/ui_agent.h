/********************************************************************************
** Form generated from reading UI file 'agent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENT_H
#define UI_AGENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
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
    QLineEdit *lineEdit_browser;
    QLabel *label_browser;
    QLabel *label_browser_url;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_url;
    QPushButton *pushButton_launch_browser;
    QSpacerItem *verticalSpacer;
    QListView *listView_browsers;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_whatsthis;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Agent)
    {
        if (Agent->objectName().isEmpty())
            Agent->setObjectName(QString::fromUtf8("Agent"));
        Agent->resize(450, 587);
        gridLayout = new QGridLayout(Agent);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(Agent);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_01 = new QWidget();
        page_01->setObjectName(QString::fromUtf8("page_01"));
        verticalLayout_2 = new QVBoxLayout(page_01);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_passphrase = new QGroupBox(page_01);
        groupBox_passphrase->setObjectName(QString::fromUtf8("groupBox_passphrase"));
        gridLayout_2 = new QGridLayout(groupBox_passphrase);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        lineEdit_old_passphrase = new QLineEdit(groupBox_passphrase);
        lineEdit_old_passphrase->setObjectName(QString::fromUtf8("lineEdit_old_passphrase"));
        lineEdit_old_passphrase->setClearButtonEnabled(true);

        gridLayout_2->addWidget(lineEdit_old_passphrase, 1, 1, 1, 2);

        lineEdit_passphrase = new QLineEdit(groupBox_passphrase);
        lineEdit_passphrase->setObjectName(QString::fromUtf8("lineEdit_passphrase"));
        lineEdit_passphrase->setClearButtonEnabled(true);

        gridLayout_2->addWidget(lineEdit_passphrase, 0, 1, 1, 2);

        checkBox_hide_passphrase = new QCheckBox(groupBox_passphrase);
        checkBox_hide_passphrase->setObjectName(QString::fromUtf8("checkBox_hide_passphrase"));

        gridLayout_2->addWidget(checkBox_hide_passphrase, 2, 0, 1, 2);

        label_old_passphrase = new QLabel(groupBox_passphrase);
        label_old_passphrase->setObjectName(QString::fromUtf8("label_old_passphrase"));

        gridLayout_2->addWidget(label_old_passphrase, 1, 0, 1, 1);

        label_passphrase = new QLabel(groupBox_passphrase);
        label_passphrase->setObjectName(QString::fromUtf8("label_passphrase"));

        gridLayout_2->addWidget(label_passphrase, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_passphrase);

        groupBox_hidden_network = new QGroupBox(page_01);
        groupBox_hidden_network->setObjectName(QString::fromUtf8("groupBox_hidden_network"));
        gridLayout_4 = new QGridLayout(groupBox_hidden_network);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_hidden_name = new QLabel(groupBox_hidden_network);
        label_hidden_name->setObjectName(QString::fromUtf8("label_hidden_name"));

        gridLayout_4->addWidget(label_hidden_name, 0, 0, 1, 1);

        lineEdit_hidden_name = new QLineEdit(groupBox_hidden_network);
        lineEdit_hidden_name->setObjectName(QString::fromUtf8("lineEdit_hidden_name"));
        lineEdit_hidden_name->setClearButtonEnabled(true);

        gridLayout_4->addWidget(lineEdit_hidden_name, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_hidden_network);

        groupBox = new QGroupBox(page_01);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_ssid = new QLabel(groupBox);
        label_ssid->setObjectName(QString::fromUtf8("label_ssid"));

        gridLayout_8->addWidget(label_ssid, 0, 0, 1, 1);

        lineEdit_ssid = new QLineEdit(groupBox);
        lineEdit_ssid->setObjectName(QString::fromUtf8("lineEdit_ssid"));
        lineEdit_ssid->setClearButtonEnabled(true);

        gridLayout_8->addWidget(lineEdit_ssid, 0, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_wispr = new QGroupBox(page_01);
        groupBox_wispr->setObjectName(QString::fromUtf8("groupBox_wispr"));
        gridLayout_6 = new QGridLayout(groupBox_wispr);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_wispr_username = new QLabel(groupBox_wispr);
        label_wispr_username->setObjectName(QString::fromUtf8("label_wispr_username"));

        gridLayout_6->addWidget(label_wispr_username, 0, 0, 1, 1);

        lineEdit_wispr_username = new QLineEdit(groupBox_wispr);
        lineEdit_wispr_username->setObjectName(QString::fromUtf8("lineEdit_wispr_username"));
        lineEdit_wispr_username->setClearButtonEnabled(true);

        gridLayout_6->addWidget(lineEdit_wispr_username, 0, 1, 1, 1);

        label_wispr_password = new QLabel(groupBox_wispr);
        label_wispr_password->setObjectName(QString::fromUtf8("label_wispr_password"));

        gridLayout_6->addWidget(label_wispr_password, 1, 0, 1, 1);

        lineEdit_wispr_password = new QLineEdit(groupBox_wispr);
        lineEdit_wispr_password->setObjectName(QString::fromUtf8("lineEdit_wispr_password"));
        lineEdit_wispr_password->setClearButtonEnabled(true);

        gridLayout_6->addWidget(lineEdit_wispr_password, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_wispr);

        groupBox_eap = new QGroupBox(page_01);
        groupBox_eap->setObjectName(QString::fromUtf8("groupBox_eap"));
        gridLayout_5 = new QGridLayout(groupBox_eap);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_eap_identity = new QLineEdit(groupBox_eap);
        lineEdit_eap_identity->setObjectName(QString::fromUtf8("lineEdit_eap_identity"));
        lineEdit_eap_identity->setClearButtonEnabled(true);

        gridLayout_5->addWidget(lineEdit_eap_identity, 1, 1, 1, 1);

        label_eap_identity = new QLabel(groupBox_eap);
        label_eap_identity->setObjectName(QString::fromUtf8("label_eap_identity"));

        gridLayout_5->addWidget(label_eap_identity, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_eap);

        groupBox_wps = new QGroupBox(page_01);
        groupBox_wps->setObjectName(QString::fromUtf8("groupBox_wps"));
        verticalLayout = new QVBoxLayout(groupBox_wps);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_wps_no_pin = new QCheckBox(groupBox_wps);
        checkBox_wps_no_pin->setObjectName(QString::fromUtf8("checkBox_wps_no_pin"));

        horizontalLayout->addWidget(checkBox_wps_no_pin);

        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_wps_pin = new QLabel(groupBox_wps);
        label_wps_pin->setObjectName(QString::fromUtf8("label_wps_pin"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_wps_pin->sizePolicy().hasHeightForWidth());
        label_wps_pin->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_wps_pin);

        lineEdit_wps_pin = new QLineEdit(groupBox_wps);
        lineEdit_wps_pin->setObjectName(QString::fromUtf8("lineEdit_wps_pin"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_wps_pin->sizePolicy().hasHeightForWidth());
        lineEdit_wps_pin->setSizePolicy(sizePolicy1);
        lineEdit_wps_pin->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(lineEdit_wps_pin);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_wps);

        stackedWidget->addWidget(page_01);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_browser = new QGroupBox(page_2);
        groupBox_browser->setObjectName(QString::fromUtf8("groupBox_browser"));
        gridLayout_7 = new QGridLayout(groupBox_browser);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEdit_browser = new QLineEdit(groupBox_browser);
        lineEdit_browser->setObjectName(QString::fromUtf8("lineEdit_browser"));

        gridLayout_7->addWidget(lineEdit_browser, 3, 0, 1, 1);

        label_browser = new QLabel(groupBox_browser);
        label_browser->setObjectName(QString::fromUtf8("label_browser"));

        gridLayout_7->addWidget(label_browser, 2, 0, 1, 1);

        label_browser_url = new QLabel(groupBox_browser);
        label_browser_url->setObjectName(QString::fromUtf8("label_browser_url"));
        label_browser_url->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_browser_url->setWordWrap(true);

        gridLayout_7->addWidget(label_browser_url, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(groupBox_browser);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        lineEdit_url = new QLineEdit(groupBox_browser);
        lineEdit_url->setObjectName(QString::fromUtf8("lineEdit_url"));
        lineEdit_url->setReadOnly(true);

        verticalLayout_4->addWidget(lineEdit_url);


        gridLayout_7->addLayout(verticalLayout_4, 1, 0, 1, 1);

        pushButton_launch_browser = new QPushButton(groupBox_browser);
        pushButton_launch_browser->setObjectName(QString::fromUtf8("pushButton_launch_browser"));

        gridLayout_7->addWidget(pushButton_launch_browser, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 8, 0, 1, 1);

        listView_browsers = new QListView(groupBox_browser);
        listView_browsers->setObjectName(QString::fromUtf8("listView_browsers"));

        gridLayout_7->addWidget(listView_browsers, 4, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_browser);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButton_whatsthis = new QToolButton(Agent);
        toolButton_whatsthis->setObjectName(QString::fromUtf8("toolButton_whatsthis"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons16x16/images/16x16/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_whatsthis->setIcon(icon);

        horizontalLayout_3->addWidget(toolButton_whatsthis);

        horizontalSpacer_3 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_accept = new QPushButton(Agent);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));

        horizontalLayout_3->addWidget(pushButton_accept);

        pushButton_cancel = new QPushButton(Agent);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_old_passphrase->setBuddy(lineEdit_old_passphrase);
        label_passphrase->setBuddy(lineEdit_passphrase);
        label_hidden_name->setBuddy(lineEdit_hidden_name);
        label_ssid->setBuddy(lineEdit_ssid);
        label_wispr_username->setBuddy(lineEdit_wispr_username);
        label_wispr_password->setBuddy(lineEdit_wispr_password);
        label_eap_identity->setBuddy(lineEdit_eap_identity);
        label_wps_pin->setBuddy(lineEdit_wps_pin);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Agent);
        QObject::connect(pushButton_accept, SIGNAL(clicked()), Agent, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), Agent, SLOT(reject()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Agent);
    } // setupUi

    void retranslateUi(QDialog *Agent)
    {
        Agent->setWindowTitle(QCoreApplication::translate("Agent", "Agent Input", nullptr));
        groupBox_passphrase->setTitle(QCoreApplication::translate("Agent", "Passphrase", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_old_passphrase->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>If an old passphrase is available it will be shown here for reference.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        lineEdit_passphrase->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Type the passphrase here.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_passphrase->setText(QString());
#if QT_CONFIG(whatsthis)
        checkBox_hide_passphrase->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Check this box to obscure the password characters.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_hide_passphrase->setText(QCoreApplication::translate("Agent", "&Hide Passphrase", nullptr));
        label_old_passphrase->setText(QCoreApplication::translate("Agent", "O&ld Passphrase", nullptr));
        label_passphrase->setText(QCoreApplication::translate("Agent", "&Passphrase", nullptr));
        groupBox_hidden_network->setTitle(QCoreApplication::translate("Agent", "Hidden Network", nullptr));
        label_hidden_name->setText(QCoreApplication::translate("Agent", "&Name", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_hidden_name->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Type the name of the hidden network you wish to connect to.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QCoreApplication::translate("Agent", "Service Set Identifier", nullptr));
        label_ssid->setText(QCoreApplication::translate("Agent", "&SSID", nullptr));
        groupBox_wispr->setTitle(QCoreApplication::translate("Agent", "Wireless Internet Service Provider roaming (WISPr)", nullptr));
        label_wispr_username->setText(QCoreApplication::translate("Agent", "&Username", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_wispr_username->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>WISPr username.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_wispr_password->setText(QCoreApplication::translate("Agent", "Passwor&d", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_wispr_password->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>WISPr password.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_eap->setTitle(QCoreApplication::translate("Agent", "Extensible Authentication Protocol (EAP)", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_eap_identity->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Type your Identity for the Extensible Authentication Protocol</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_eap_identity->setText(QCoreApplication::translate("Agent", "&Identity", nullptr));
        groupBox_wps->setTitle(QCoreApplication::translate("Agent", "WiFi Protected Setup (WPS)", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_wps_no_pin->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>When checked use WPS push button authentication.  </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox_wps_no_pin->setText(QCoreApplication::translate("Agent", "Use Push &Button Authentication", nullptr));
        label_wps_pin->setText(QCoreApplication::translate("Agent", "&WPS Pin", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_wps_pin->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Enter a WPS pin.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_browser->setTitle(QCoreApplication::translate("Agent", "Browser Login Requested", nullptr));
        label_browser->setText(QCoreApplication::translate("Agent", "Choose or enter a browser:", nullptr));
        label_browser_url->setText(QCoreApplication::translate("Agent", "<html><head/><body><p>ConnMan is requesting that you open a web browser to complete the login process.</p><p>We have scanned your PATH for browsers and any browsers found are shown in the list below. You may select any one browser to use it for the login. If your web browser is not shown in the list you may enter it directly in the<span style=\" font-weight:600;\"> Choose or enter a browser box</span>.</p><p>To launch the browser click the <span style=\" font-weight:600;\">Launch Browser</span> button. </p><p>If you wish to login manually close this dialog, start your web browser and proceed to the URL shown in the <span style=\" font-weight:600;\">Login URL</span> box.</p><p><span style=\" font-weight:600;\">Brave Browser Users:</span> Note that Brave does not seem to accept a URL to start with. After the browser starts you will need to enter the URL manually. </p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Agent", "Login URL:", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_url->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Connman is requesting you continue login with a web browser. This box shows the URL that contains the login page.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        pushButton_launch_browser->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Use this button to launch the selected browser. The browser will open at the page shown in the Login URL box.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_launch_browser->setText(QCoreApplication::translate("Agent", "Launch &Browser", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_whatsthis->setToolTip(QCoreApplication::translate("Agent", "<html><head/><body><p>What's This</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_whatsthis->setText(QCoreApplication::translate("Agent", "...", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_accept->setToolTip(QCoreApplication::translate("Agent", "<html><head/><body><p>Continue the connection process.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_accept->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Accept and use the answers you have provided in this dialog. </p><p>This will send your input to the connman daemon to continue the connection process.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_accept->setText(QCoreApplication::translate("Agent", "O&K", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_cancel->setToolTip(QCoreApplication::translate("Agent", "<html><head/><body><p>Cancel the connection process.<br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_cancel->setWhatsThis(QCoreApplication::translate("Agent", "<html><head/><body><p>Cancel the dialog. </p><p>This will send a message to the connman daemon that you have cancelled the connection request.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_cancel->setText(QCoreApplication::translate("Agent", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Agent: public Ui_Agent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENT_H
