/********************************************************************************
** Form generated from reading UI file 'provisioning_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROVISIONING_EDITOR_H
#define UI_PROVISIONING_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Provisioning
{
public:
    QAction *actionGlobal;
    QAction *actionGlobalName;
    QAction *actionGlobalDescription;
    QAction *actionService;
    QAction *actionServiceType;
    QAction *actionServiceMAC;
    QAction *actionServiceNameServers;
    QAction *actionServiceTimeServers;
    QAction *actionServiceSearchDomains;
    QAction *actionServiceDomain;
    QAction *actionWifiName;
    QAction *actionWifiSSID;
    QAction *actionWifiEAP;
    QAction *actionWifiCACertFile;
    QAction *actionWifiClientCertFile;
    QAction *actionWifiPrivateKeyFile;
    QAction *actionWifiPrivateKeyPassphrase;
    QAction *actionWifiPrivateKeyPassphraseType;
    QAction *actionWifiIdentity;
    QAction *actionWifiPhase2;
    QAction *actionWifiPassphrase;
    QAction *actionWifiSecurity;
    QAction *actionWifiHidden;
    QAction *actionTemplateEduroamLong;
    QAction *actionTemplateEduroamShort;
    QAction *actionServiceIPv4;
    QAction *actionServiceIPv6;
    QAction *actionServiceIPv6Privacy;
    QAction *actionTemplateeap_peap;
    QAction *actionTemplateeap_tls;
    QAction *actionTemplateeap_ttls;
    QAction *actionServiceDeviceName;
    QAction *actionServicemDNS;
    QAction *actionWifiAnonymousIdentity;
    QAction *actionWifiSubjectMatch;
    QAction *actionWifiAltSubjectMatch;
    QAction *actionWifiDomainSuffixMatch;
    QAction *actionWifiDomainMatch;
    QVBoxLayout *verticalLayout01;
    QPlainTextEdit *plainTextEdit_main;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_open;
    QPushButton *pushButton_save;
    QFrame *line;
    QPushButton *pushButton_delete;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_resetpage;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_whatsthis;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_exit;

    void setupUi(QDialog *Provisioning)
    {
        if (Provisioning->objectName().isEmpty())
            Provisioning->setObjectName(QString::fromUtf8("Provisioning"));
        Provisioning->resize(374, 484);
        Provisioning->setSizeGripEnabled(true);
        actionGlobal = new QAction(Provisioning);
        actionGlobal->setObjectName(QString::fromUtf8("actionGlobal"));
        actionGlobalName = new QAction(Provisioning);
        actionGlobalName->setObjectName(QString::fromUtf8("actionGlobalName"));
        actionGlobalDescription = new QAction(Provisioning);
        actionGlobalDescription->setObjectName(QString::fromUtf8("actionGlobalDescription"));
        actionService = new QAction(Provisioning);
        actionService->setObjectName(QString::fromUtf8("actionService"));
        actionServiceType = new QAction(Provisioning);
        actionServiceType->setObjectName(QString::fromUtf8("actionServiceType"));
        actionServiceType->setEnabled(true);
        actionServiceMAC = new QAction(Provisioning);
        actionServiceMAC->setObjectName(QString::fromUtf8("actionServiceMAC"));
        actionServiceMAC->setEnabled(true);
        actionServiceNameServers = new QAction(Provisioning);
        actionServiceNameServers->setObjectName(QString::fromUtf8("actionServiceNameServers"));
        actionServiceNameServers->setEnabled(true);
        actionServiceTimeServers = new QAction(Provisioning);
        actionServiceTimeServers->setObjectName(QString::fromUtf8("actionServiceTimeServers"));
        actionServiceTimeServers->setEnabled(true);
        actionServiceSearchDomains = new QAction(Provisioning);
        actionServiceSearchDomains->setObjectName(QString::fromUtf8("actionServiceSearchDomains"));
        actionServiceSearchDomains->setEnabled(true);
        actionServiceDomain = new QAction(Provisioning);
        actionServiceDomain->setObjectName(QString::fromUtf8("actionServiceDomain"));
        actionServiceDomain->setEnabled(true);
        actionWifiName = new QAction(Provisioning);
        actionWifiName->setObjectName(QString::fromUtf8("actionWifiName"));
        actionWifiSSID = new QAction(Provisioning);
        actionWifiSSID->setObjectName(QString::fromUtf8("actionWifiSSID"));
        actionWifiSSID->setEnabled(true);
        actionWifiEAP = new QAction(Provisioning);
        actionWifiEAP->setObjectName(QString::fromUtf8("actionWifiEAP"));
        actionWifiEAP->setEnabled(true);
        actionWifiCACertFile = new QAction(Provisioning);
        actionWifiCACertFile->setObjectName(QString::fromUtf8("actionWifiCACertFile"));
        actionWifiCACertFile->setEnabled(true);
        actionWifiClientCertFile = new QAction(Provisioning);
        actionWifiClientCertFile->setObjectName(QString::fromUtf8("actionWifiClientCertFile"));
        actionWifiClientCertFile->setEnabled(true);
        actionWifiPrivateKeyFile = new QAction(Provisioning);
        actionWifiPrivateKeyFile->setObjectName(QString::fromUtf8("actionWifiPrivateKeyFile"));
        actionWifiPrivateKeyFile->setEnabled(true);
        actionWifiPrivateKeyPassphrase = new QAction(Provisioning);
        actionWifiPrivateKeyPassphrase->setObjectName(QString::fromUtf8("actionWifiPrivateKeyPassphrase"));
        actionWifiPrivateKeyPassphraseType = new QAction(Provisioning);
        actionWifiPrivateKeyPassphraseType->setObjectName(QString::fromUtf8("actionWifiPrivateKeyPassphraseType"));
        actionWifiPrivateKeyPassphraseType->setEnabled(true);
        actionWifiIdentity = new QAction(Provisioning);
        actionWifiIdentity->setObjectName(QString::fromUtf8("actionWifiIdentity"));
        actionWifiPhase2 = new QAction(Provisioning);
        actionWifiPhase2->setObjectName(QString::fromUtf8("actionWifiPhase2"));
        actionWifiPhase2->setEnabled(true);
        actionWifiPassphrase = new QAction(Provisioning);
        actionWifiPassphrase->setObjectName(QString::fromUtf8("actionWifiPassphrase"));
        actionWifiSecurity = new QAction(Provisioning);
        actionWifiSecurity->setObjectName(QString::fromUtf8("actionWifiSecurity"));
        actionWifiSecurity->setEnabled(true);
        actionWifiHidden = new QAction(Provisioning);
        actionWifiHidden->setObjectName(QString::fromUtf8("actionWifiHidden"));
        actionWifiHidden->setEnabled(true);
        actionTemplateEduroamLong = new QAction(Provisioning);
        actionTemplateEduroamLong->setObjectName(QString::fromUtf8("actionTemplateEduroamLong"));
        actionTemplateEduroamShort = new QAction(Provisioning);
        actionTemplateEduroamShort->setObjectName(QString::fromUtf8("actionTemplateEduroamShort"));
        actionServiceIPv4 = new QAction(Provisioning);
        actionServiceIPv4->setObjectName(QString::fromUtf8("actionServiceIPv4"));
        actionServiceIPv6 = new QAction(Provisioning);
        actionServiceIPv6->setObjectName(QString::fromUtf8("actionServiceIPv6"));
        actionServiceIPv6Privacy = new QAction(Provisioning);
        actionServiceIPv6Privacy->setObjectName(QString::fromUtf8("actionServiceIPv6Privacy"));
        actionTemplateeap_peap = new QAction(Provisioning);
        actionTemplateeap_peap->setObjectName(QString::fromUtf8("actionTemplateeap_peap"));
        actionTemplateeap_tls = new QAction(Provisioning);
        actionTemplateeap_tls->setObjectName(QString::fromUtf8("actionTemplateeap_tls"));
        actionTemplateeap_ttls = new QAction(Provisioning);
        actionTemplateeap_ttls->setObjectName(QString::fromUtf8("actionTemplateeap_ttls"));
        actionServiceDeviceName = new QAction(Provisioning);
        actionServiceDeviceName->setObjectName(QString::fromUtf8("actionServiceDeviceName"));
        actionServicemDNS = new QAction(Provisioning);
        actionServicemDNS->setObjectName(QString::fromUtf8("actionServicemDNS"));
        actionWifiAnonymousIdentity = new QAction(Provisioning);
        actionWifiAnonymousIdentity->setObjectName(QString::fromUtf8("actionWifiAnonymousIdentity"));
        actionWifiSubjectMatch = new QAction(Provisioning);
        actionWifiSubjectMatch->setObjectName(QString::fromUtf8("actionWifiSubjectMatch"));
        actionWifiAltSubjectMatch = new QAction(Provisioning);
        actionWifiAltSubjectMatch->setObjectName(QString::fromUtf8("actionWifiAltSubjectMatch"));
        actionWifiDomainSuffixMatch = new QAction(Provisioning);
        actionWifiDomainSuffixMatch->setObjectName(QString::fromUtf8("actionWifiDomainSuffixMatch"));
        actionWifiDomainMatch = new QAction(Provisioning);
        actionWifiDomainMatch->setObjectName(QString::fromUtf8("actionWifiDomainMatch"));
        verticalLayout01 = new QVBoxLayout(Provisioning);
        verticalLayout01->setObjectName(QString::fromUtf8("verticalLayout01"));
        plainTextEdit_main = new QPlainTextEdit(Provisioning);
        plainTextEdit_main->setObjectName(QString::fromUtf8("plainTextEdit_main"));

        verticalLayout01->addWidget(plainTextEdit_main);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_open = new QPushButton(Provisioning);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_open);

        pushButton_save = new QPushButton(Provisioning);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setEnabled(true);
        pushButton_save->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_save);

        line = new QFrame(Provisioning);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        pushButton_delete = new QPushButton(Provisioning);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_delete);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_resetpage = new QPushButton(Provisioning);
        pushButton_resetpage->setObjectName(QString::fromUtf8("pushButton_resetpage"));
        pushButton_resetpage->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_resetpage);


        verticalLayout01->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_whatsthis = new QToolButton(Provisioning);
        toolButton_whatsthis->setObjectName(QString::fromUtf8("toolButton_whatsthis"));

        horizontalLayout_2->addWidget(toolButton_whatsthis);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_exit = new QPushButton(Provisioning);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setAutoDefault(false);

        horizontalLayout_2->addWidget(pushButton_exit);


        verticalLayout01->addLayout(horizontalLayout_2);


        retranslateUi(Provisioning);
        QObject::connect(pushButton_exit, SIGNAL(clicked()), Provisioning, SLOT(reject()));

        QMetaObject::connectSlotsByName(Provisioning);
    } // setupUi

    void retranslateUi(QDialog *Provisioning)
    {
        Provisioning->setWindowTitle(QCoreApplication::translate("Provisioning", "Provisioning Editor", nullptr));
        actionGlobal->setText(QCoreApplication::translate("Provisioning", "[global]", nullptr));
        actionGlobalName->setText(QCoreApplication::translate("Provisioning", "Name", nullptr));
        actionGlobalDescription->setText(QCoreApplication::translate("Provisioning", "Description", nullptr));
        actionService->setText(QCoreApplication::translate("Provisioning", "[service_*]", nullptr));
        actionServiceType->setText(QCoreApplication::translate("Provisioning", "Type", nullptr));
        actionServiceMAC->setText(QCoreApplication::translate("Provisioning", "MAC", nullptr));
        actionServiceNameServers->setText(QCoreApplication::translate("Provisioning", "Nameservers", nullptr));
        actionServiceTimeServers->setText(QCoreApplication::translate("Provisioning", "Timeservers", nullptr));
        actionServiceSearchDomains->setText(QCoreApplication::translate("Provisioning", "SearchDomains", nullptr));
        actionServiceDomain->setText(QCoreApplication::translate("Provisioning", "Domain", nullptr));
        actionWifiName->setText(QCoreApplication::translate("Provisioning", "Name", nullptr));
        actionWifiSSID->setText(QCoreApplication::translate("Provisioning", "SSID", nullptr));
        actionWifiEAP->setText(QCoreApplication::translate("Provisioning", "EAP", nullptr));
        actionWifiCACertFile->setText(QCoreApplication::translate("Provisioning", "CACertFile", nullptr));
        actionWifiClientCertFile->setText(QCoreApplication::translate("Provisioning", "ClientCertFile", nullptr));
        actionWifiPrivateKeyFile->setText(QCoreApplication::translate("Provisioning", "PrivateKeyFile", nullptr));
        actionWifiPrivateKeyPassphrase->setText(QCoreApplication::translate("Provisioning", "PrivateKeyPassphrase", nullptr));
        actionWifiPrivateKeyPassphraseType->setText(QCoreApplication::translate("Provisioning", "PrivateKeyPassphraseType", nullptr));
        actionWifiIdentity->setText(QCoreApplication::translate("Provisioning", "Identity", nullptr));
        actionWifiPhase2->setText(QCoreApplication::translate("Provisioning", "Phase2", nullptr));
        actionWifiPassphrase->setText(QCoreApplication::translate("Provisioning", "Passphrase", nullptr));
        actionWifiSecurity->setText(QCoreApplication::translate("Provisioning", "Security", nullptr));
        actionWifiHidden->setText(QCoreApplication::translate("Provisioning", "Hidden", nullptr));
        actionTemplateEduroamLong->setText(QCoreApplication::translate("Provisioning", "Eduroam (long)", nullptr));
        actionTemplateEduroamShort->setText(QCoreApplication::translate("Provisioning", "Eduroam (short)", nullptr));
        actionServiceIPv4->setText(QCoreApplication::translate("Provisioning", "IPv4", nullptr));
#if QT_CONFIG(tooltip)
        actionServiceIPv4->setToolTip(QCoreApplication::translate("Provisioning", "Set IPv4 to \"off\", \"dhcp\", or enter IPV4 address information", nullptr));
#endif // QT_CONFIG(tooltip)
        actionServiceIPv6->setText(QCoreApplication::translate("Provisioning", "IPv6", nullptr));
#if QT_CONFIG(tooltip)
        actionServiceIPv6->setToolTip(QCoreApplication::translate("Provisioning", "Set IPv6 to \"off, \"auto\", or enter IPv6 address information", nullptr));
#endif // QT_CONFIG(tooltip)
        actionServiceIPv6Privacy->setText(QCoreApplication::translate("Provisioning", "IPv6.Privacy", nullptr));
        actionTemplateeap_peap->setText(QCoreApplication::translate("Provisioning", "EAP-PEAP", nullptr));
#if QT_CONFIG(tooltip)
        actionTemplateeap_peap->setToolTip(QCoreApplication::translate("Provisioning", "EAP-PEAP", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTemplateeap_tls->setText(QCoreApplication::translate("Provisioning", "EAP-TLS", nullptr));
#if QT_CONFIG(tooltip)
        actionTemplateeap_tls->setToolTip(QCoreApplication::translate("Provisioning", "EAP-TLS", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTemplateeap_ttls->setText(QCoreApplication::translate("Provisioning", "EAP-TTLS", nullptr));
#if QT_CONFIG(tooltip)
        actionTemplateeap_ttls->setToolTip(QCoreApplication::translate("Provisioning", "EAP-TTLS", nullptr));
#endif // QT_CONFIG(tooltip)
        actionServiceDeviceName->setText(QCoreApplication::translate("Provisioning", "DeviceName", nullptr));
#if QT_CONFIG(tooltip)
        actionServiceDeviceName->setToolTip(QCoreApplication::translate("Provisioning", "Interface name where this provisioning applies (ex: eth0)", nullptr));
#endif // QT_CONFIG(tooltip)
        actionServicemDNS->setText(QCoreApplication::translate("Provisioning", "mDNS", nullptr));
#if QT_CONFIG(tooltip)
        actionServicemDNS->setToolTip(QCoreApplication::translate("Provisioning", "Set to true if mDNS domains can be resolved and the hostname registered.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWifiAnonymousIdentity->setText(QCoreApplication::translate("Provisioning", "AnonymousIdentity", nullptr));
#if QT_CONFIG(tooltip)
        actionWifiAnonymousIdentity->setToolTip(QCoreApplication::translate("Provisioning", "Anonymous identity string for EAP", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWifiSubjectMatch->setText(QCoreApplication::translate("Provisioning", "SubjectMatch", nullptr));
#if QT_CONFIG(tooltip)
        actionWifiSubjectMatch->setToolTip(QCoreApplication::translate("Provisioning", "Substring to be matched against the subject of the authentication server certificate for EAP", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWifiAltSubjectMatch->setText(QCoreApplication::translate("Provisioning", "AltSubjectMatch", nullptr));
#if QT_CONFIG(tooltip)
        actionWifiAltSubjectMatch->setToolTip(QCoreApplication::translate("Provisioning", "Semicolon separated string of entries to be matched against the alternative subject name of the authentication server certificate for EAP", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWifiDomainSuffixMatch->setText(QCoreApplication::translate("Provisioning", "DomainSuffixMatch", nullptr));
#if QT_CONFIG(tooltip)
        actionWifiDomainSuffixMatch->setToolTip(QCoreApplication::translate("Provisioning", "A FQDN used as a suffix match requirement for the authentication server.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWifiDomainMatch->setText(QCoreApplication::translate("Provisioning", "DomainMatch", nullptr));
#if QT_CONFIG(tooltip)
        actionWifiDomainMatch->setToolTip(QCoreApplication::translate("Provisioning", "A FQDN used as a full match requirement for the authentication server.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        plainTextEdit_main->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Text edit window.</p><p>You may type or cut and paste into this window. You may also use menus above to insert text fields.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        pushButton_open->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Open an existing config file.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_open->setText(QCoreApplication::translate("Provisioning", "&Open", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_save->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Write the displayed data to a config file.</p><p>The combo box is seeded with a list of CMST created config files to provide an easy way to overwrite one. You may also type a name in the ComboBox.</p><p>It is not necessary to provide a path nor a file extension as both will be stripped out and replaced allowed values. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_save->setText(QCoreApplication::translate("Provisioning", "&Save", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_delete->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Delete a config file.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_delete->setText(QCoreApplication::translate("Provisioning", "&Delete", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_resetpage->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Clear all text from the editor window.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_resetpage->setText(QCoreApplication::translate("Provisioning", "&Clear Page", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_whatsthis->setToolTip(QCoreApplication::translate("Provisioning", "<html><head/><body><p>What's This</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        toolButton_whatsthis->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Enter &quot;Whats This&quot; mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolButton_whatsthis->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_exit->setWhatsThis(QCoreApplication::translate("Provisioning", "<html><head/><body><p>Exit the dialog.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_exit->setText(QCoreApplication::translate("Provisioning", "E&xit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Provisioning: public Ui_Provisioning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROVISIONING_EDITOR_H
