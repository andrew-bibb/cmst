/********************************************************************************
** Form generated from reading UI file 'vpn_prov_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VPN_PROV_EDITOR_H
#define UI_VPN_PROV_EDITOR_H

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

class Ui_VPN_Prov
{
public:
    QAction *actionGlobal;
    QAction *actionGlobalName;
    QAction *actionGlobalDescription;
    QAction *actionProviderPPTP;
    QAction *actionProviderL2TP;
    QAction *actionProviderVPNC;
    QAction *actionProviderOpenVPN;
    QAction *actionProviderOpenConnect;
    QAction *actionPPTP_User;
    QAction *actionPPTP_Password;
    QAction *actionPPPD_EchoFailure;
    QAction *actionPPPD_EchoInterval;
    QAction *actionPPPD_Debug;
    QAction *actionPPPD_RefuseEAP;
    QAction *actionPPPD_RefusePAP;
    QAction *actionPPPD_RefuseCHAP;
    QAction *actionPPPD_RefuseMSCHAP;
    QAction *actionPPPD_RefuseMSCHAP2;
    QAction *actionPPPD_NoBSDComp;
    QAction *actionPPPD_NoDeflate;
    QAction *actionPPPD_RequirMPPE;
    QAction *actionPPPD_RequirMPPE40;
    QAction *actionPPPD_RequirMPPE128;
    QAction *actionPPPD_RequirMPPEStateful;
    QAction *actionPPPD_NoVJ;
    QAction *actionL2TP_User;
    QAction *actionL2TP_Password;
    QAction *actionL2TP_BPS;
    QAction *actionL2TP_TXBPS;
    QAction *actionL2TP_RXBPS;
    QAction *actionL2TP_LengthBit;
    QAction *actionL2TP_Challenge;
    QAction *actionL2TP_DefaultRoute;
    QAction *actionL2TP_FlowBit;
    QAction *actionL2TP_TunnelRWS;
    QAction *actionL2TP_Exclusive;
    QAction *actionL2TP_Redial;
    QAction *actionL2TP_RedialTImeout;
    QAction *actionL2TP_MaxRedials;
    QAction *actionL2TP_RequirePAP;
    QAction *actionL2TP_RequireCHAP;
    QAction *actionL2TP_ReqAuth;
    QAction *actionL2TP_AccessControl;
    QAction *actionL2TP_AuthFile;
    QAction *actionL2TP_ListenAddr;
    QAction *actionL2TP_IPsecSaref;
    QAction *actionL2TP_Port;
    QAction *actionPPPD_NoPcomp;
    QAction *actionPPPD_UseAccomp;
    QAction *actionPPPD_ReqMPPE;
    QAction *actionPPPD_ReqMPPE40;
    QAction *actionPPPD_ReqMPPE128;
    QAction *actionPPPD_ReqMPPEStateful;
    QAction *actionVPNC_IPSec_ID;
    QAction *actionVPNC_IPSec_Secret;
    QAction *actionVPNC_Xauth_Username;
    QAction *actionVPNC_Xauth_Password;
    QAction *actionVPNC_IKE_Authmode;
    QAction *actionVPNC_IKE_DHGroup;
    QAction *actionVPNC_PFS;
    QAction *actionVPNC_Domain;
    QAction *actionVPNC_Vendor;
    QAction *actionVPNC_LocalPort;
    QAction *actionVPNC_CiscoPort;
    QAction *actionVPNC_AppVersion;
    QAction *actionVPNC_NATTMode;
    QAction *actionVPNC_DPDTimeout;
    QAction *actionVPNC_SingleDES;
    QAction *actionVPNC_NoEncryption;
    QAction *actionOpenVPN_CACert;
    QAction *actionOpenVPN_Cert;
    QAction *actionOpenVPN_Key;
    QAction *actionOpenVPN_MTU;
    QAction *actionOpenVPN_NSCertType;
    QAction *actionOpenVPN_Proto;
    QAction *actionOpenVPN_Port;
    QAction *actionOpenVPN_AuthUserPass;
    QAction *actionOpenVPN_AskPass;
    QAction *actionOpenVPN_AuthNoCache;
    QAction *actionOpenVPN_Cipher;
    QAction *actionOpenVPN_Auth;
    QAction *actionOpenVPN_CompLZO;
    QAction *actionOpenVPN_RemoteCertTls;
    QAction *actionOpenVPN_ConfigFile;
    QAction *actionOpenConnect_ServerCert;
    QAction *actionOpenConnect_CACert;
    QAction *actionOpenConnect_ClientCert;
    QAction *actionOpenConnect_MTU;
    QAction *actionOpenConnect_Cookie;
    QAction *actionOpenConnect_VPNHost;
    QAction *actionOpenVPN_Import;
    QAction *actionProviderWireGuard;
    QAction *actionVPNC_DeviceType;
    QAction *actionWireGuard_Address;
    QAction *actionWireGuard_ListPort;
    QAction *actionWireGuard_DNS;
    QAction *actionWireGuard_PrivateKey;
    QAction *actionWireGuard_PublicKey;
    QAction *actionWireGuard_PresharedKey;
    QAction *actionWireGuard_AllowedIPs;
    QAction *actionWireGuard_EndpointPort;
    QAction *actionWireGuard_PersistentKeepalive;
    QAction *actionOpenVPN_DeviceType;
    QAction *actionOpenConnect_AllowSelfSignedCert;
    QAction *actionOpenConnect_AuthType;
    QAction *actionOpenConnect_DisableIPv6;
    QAction *actionOpenConnect_NoDTLS;
    QAction *actionOpenConnect_NoHTTPKeepalive;
    QAction *actionOpenConnect_PKCSClientCert;
    QAction *actionOpenConnect_Usergroup;
    QAction *actionOpenConnect_UserPrivateKey;
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

    void setupUi(QDialog *VPN_Prov)
    {
        if (VPN_Prov->objectName().isEmpty())
            VPN_Prov->setObjectName(QString::fromUtf8("VPN_Prov"));
        VPN_Prov->resize(434, 574);
        VPN_Prov->setSizeGripEnabled(true);
        actionGlobal = new QAction(VPN_Prov);
        actionGlobal->setObjectName(QString::fromUtf8("actionGlobal"));
        actionGlobal->setText(QString::fromUtf8("[global]"));
        actionGlobalName = new QAction(VPN_Prov);
        actionGlobalName->setObjectName(QString::fromUtf8("actionGlobalName"));
        actionGlobalName->setText(QString::fromUtf8("Name"));
        actionGlobalDescription = new QAction(VPN_Prov);
        actionGlobalDescription->setObjectName(QString::fromUtf8("actionGlobalDescription"));
        actionGlobalDescription->setText(QString::fromUtf8("Description"));
        actionProviderPPTP = new QAction(VPN_Prov);
        actionProviderPPTP->setObjectName(QString::fromUtf8("actionProviderPPTP"));
        actionProviderPPTP->setText(QString::fromUtf8("Provider PPTP"));
        actionProviderL2TP = new QAction(VPN_Prov);
        actionProviderL2TP->setObjectName(QString::fromUtf8("actionProviderL2TP"));
        actionProviderL2TP->setText(QString::fromUtf8("Provider L2TP"));
        actionProviderVPNC = new QAction(VPN_Prov);
        actionProviderVPNC->setObjectName(QString::fromUtf8("actionProviderVPNC"));
        actionProviderVPNC->setText(QString::fromUtf8("Provider VPNC"));
        actionProviderOpenVPN = new QAction(VPN_Prov);
        actionProviderOpenVPN->setObjectName(QString::fromUtf8("actionProviderOpenVPN"));
        actionProviderOpenVPN->setText(QString::fromUtf8("Provider OpenVPN"));
        actionProviderOpenConnect = new QAction(VPN_Prov);
        actionProviderOpenConnect->setObjectName(QString::fromUtf8("actionProviderOpenConnect"));
        actionProviderOpenConnect->setText(QString::fromUtf8("Provider OpenConnect"));
        actionPPTP_User = new QAction(VPN_Prov);
        actionPPTP_User->setObjectName(QString::fromUtf8("actionPPTP_User"));
        actionPPTP_User->setText(QString::fromUtf8("PPTP.User"));
        actionPPTP_Password = new QAction(VPN_Prov);
        actionPPTP_Password->setObjectName(QString::fromUtf8("actionPPTP_Password"));
        actionPPTP_Password->setText(QString::fromUtf8("PPTP.Password"));
        actionPPPD_EchoFailure = new QAction(VPN_Prov);
        actionPPPD_EchoFailure->setObjectName(QString::fromUtf8("actionPPPD_EchoFailure"));
        actionPPPD_EchoFailure->setText(QString::fromUtf8("PPPD.EchoFailure"));
        actionPPPD_EchoInterval = new QAction(VPN_Prov);
        actionPPPD_EchoInterval->setObjectName(QString::fromUtf8("actionPPPD_EchoInterval"));
        actionPPPD_EchoInterval->setText(QString::fromUtf8("PPPD.EchoInterval"));
        actionPPPD_Debug = new QAction(VPN_Prov);
        actionPPPD_Debug->setObjectName(QString::fromUtf8("actionPPPD_Debug"));
        actionPPPD_Debug->setText(QString::fromUtf8("PPPD.Debug"));
        actionPPPD_RefuseEAP = new QAction(VPN_Prov);
        actionPPPD_RefuseEAP->setObjectName(QString::fromUtf8("actionPPPD_RefuseEAP"));
        actionPPPD_RefuseEAP->setText(QString::fromUtf8("PPPD.RefuseEAP"));
        actionPPPD_RefusePAP = new QAction(VPN_Prov);
        actionPPPD_RefusePAP->setObjectName(QString::fromUtf8("actionPPPD_RefusePAP"));
        actionPPPD_RefusePAP->setText(QString::fromUtf8("PPPD.RefusePAP"));
        actionPPPD_RefuseCHAP = new QAction(VPN_Prov);
        actionPPPD_RefuseCHAP->setObjectName(QString::fromUtf8("actionPPPD_RefuseCHAP"));
        actionPPPD_RefuseCHAP->setText(QString::fromUtf8("PPPD.RefuseCHAP"));
        actionPPPD_RefuseMSCHAP = new QAction(VPN_Prov);
        actionPPPD_RefuseMSCHAP->setObjectName(QString::fromUtf8("actionPPPD_RefuseMSCHAP"));
        actionPPPD_RefuseMSCHAP->setText(QString::fromUtf8("PPPD.RefuseMSCHAP"));
        actionPPPD_RefuseMSCHAP2 = new QAction(VPN_Prov);
        actionPPPD_RefuseMSCHAP2->setObjectName(QString::fromUtf8("actionPPPD_RefuseMSCHAP2"));
        actionPPPD_RefuseMSCHAP2->setText(QString::fromUtf8("PPPD.RefuseMSCHAP2"));
        actionPPPD_NoBSDComp = new QAction(VPN_Prov);
        actionPPPD_NoBSDComp->setObjectName(QString::fromUtf8("actionPPPD_NoBSDComp"));
        actionPPPD_NoBSDComp->setText(QString::fromUtf8("PPPD.NoBSDComp"));
        actionPPPD_NoDeflate = new QAction(VPN_Prov);
        actionPPPD_NoDeflate->setObjectName(QString::fromUtf8("actionPPPD_NoDeflate"));
        actionPPPD_NoDeflate->setText(QString::fromUtf8("PPPD.NoDeflate"));
        actionPPPD_RequirMPPE = new QAction(VPN_Prov);
        actionPPPD_RequirMPPE->setObjectName(QString::fromUtf8("actionPPPD_RequirMPPE"));
        actionPPPD_RequirMPPE->setText(QString::fromUtf8("PPPD.RequirMPPE"));
        actionPPPD_RequirMPPE40 = new QAction(VPN_Prov);
        actionPPPD_RequirMPPE40->setObjectName(QString::fromUtf8("actionPPPD_RequirMPPE40"));
        actionPPPD_RequirMPPE40->setText(QString::fromUtf8("PPPD.RequirMPPE40"));
        actionPPPD_RequirMPPE128 = new QAction(VPN_Prov);
        actionPPPD_RequirMPPE128->setObjectName(QString::fromUtf8("actionPPPD_RequirMPPE128"));
        actionPPPD_RequirMPPE128->setText(QString::fromUtf8("PPPD.RequirMPPE128"));
        actionPPPD_RequirMPPEStateful = new QAction(VPN_Prov);
        actionPPPD_RequirMPPEStateful->setObjectName(QString::fromUtf8("actionPPPD_RequirMPPEStateful"));
        actionPPPD_RequirMPPEStateful->setText(QString::fromUtf8("PPPD.RequireMPPEStateful"));
        actionPPPD_NoVJ = new QAction(VPN_Prov);
        actionPPPD_NoVJ->setObjectName(QString::fromUtf8("actionPPPD_NoVJ"));
        actionPPPD_NoVJ->setText(QString::fromUtf8("PPPD.NoVJ"));
        actionL2TP_User = new QAction(VPN_Prov);
        actionL2TP_User->setObjectName(QString::fromUtf8("actionL2TP_User"));
        actionL2TP_User->setText(QString::fromUtf8("L2TP.User"));
        actionL2TP_Password = new QAction(VPN_Prov);
        actionL2TP_Password->setObjectName(QString::fromUtf8("actionL2TP_Password"));
        actionL2TP_Password->setText(QString::fromUtf8("L2TP.Password"));
        actionL2TP_BPS = new QAction(VPN_Prov);
        actionL2TP_BPS->setObjectName(QString::fromUtf8("actionL2TP_BPS"));
        actionL2TP_BPS->setText(QString::fromUtf8("L2TP.BPS"));
        actionL2TP_TXBPS = new QAction(VPN_Prov);
        actionL2TP_TXBPS->setObjectName(QString::fromUtf8("actionL2TP_TXBPS"));
        actionL2TP_TXBPS->setText(QString::fromUtf8("L2TP.TXBPS"));
        actionL2TP_RXBPS = new QAction(VPN_Prov);
        actionL2TP_RXBPS->setObjectName(QString::fromUtf8("actionL2TP_RXBPS"));
        actionL2TP_RXBPS->setText(QString::fromUtf8("L2TP.RXBPS"));
        actionL2TP_LengthBit = new QAction(VPN_Prov);
        actionL2TP_LengthBit->setObjectName(QString::fromUtf8("actionL2TP_LengthBit"));
        actionL2TP_LengthBit->setText(QString::fromUtf8("L2TP.LengthBit"));
        actionL2TP_Challenge = new QAction(VPN_Prov);
        actionL2TP_Challenge->setObjectName(QString::fromUtf8("actionL2TP_Challenge"));
        actionL2TP_Challenge->setText(QString::fromUtf8("L2TP.Challenge"));
        actionL2TP_DefaultRoute = new QAction(VPN_Prov);
        actionL2TP_DefaultRoute->setObjectName(QString::fromUtf8("actionL2TP_DefaultRoute"));
        actionL2TP_DefaultRoute->setText(QString::fromUtf8("L2TP.DefaultRoute"));
        actionL2TP_FlowBit = new QAction(VPN_Prov);
        actionL2TP_FlowBit->setObjectName(QString::fromUtf8("actionL2TP_FlowBit"));
        actionL2TP_FlowBit->setText(QString::fromUtf8("L2TP.FlowBit"));
        actionL2TP_TunnelRWS = new QAction(VPN_Prov);
        actionL2TP_TunnelRWS->setObjectName(QString::fromUtf8("actionL2TP_TunnelRWS"));
        actionL2TP_TunnelRWS->setText(QString::fromUtf8("L2TP.TunnelRWS"));
        actionL2TP_Exclusive = new QAction(VPN_Prov);
        actionL2TP_Exclusive->setObjectName(QString::fromUtf8("actionL2TP_Exclusive"));
        actionL2TP_Exclusive->setText(QString::fromUtf8("L2TP.Exclusive"));
        actionL2TP_Redial = new QAction(VPN_Prov);
        actionL2TP_Redial->setObjectName(QString::fromUtf8("actionL2TP_Redial"));
        actionL2TP_Redial->setText(QString::fromUtf8("L2TP.Redial"));
        actionL2TP_RedialTImeout = new QAction(VPN_Prov);
        actionL2TP_RedialTImeout->setObjectName(QString::fromUtf8("actionL2TP_RedialTImeout"));
        actionL2TP_RedialTImeout->setText(QString::fromUtf8("L2TP.RedialTImeout"));
        actionL2TP_MaxRedials = new QAction(VPN_Prov);
        actionL2TP_MaxRedials->setObjectName(QString::fromUtf8("actionL2TP_MaxRedials"));
        actionL2TP_MaxRedials->setText(QString::fromUtf8("L2TP.MaxRedials"));
        actionL2TP_RequirePAP = new QAction(VPN_Prov);
        actionL2TP_RequirePAP->setObjectName(QString::fromUtf8("actionL2TP_RequirePAP"));
        actionL2TP_RequirePAP->setText(QString::fromUtf8("L2TP.RequirePAP"));
        actionL2TP_RequireCHAP = new QAction(VPN_Prov);
        actionL2TP_RequireCHAP->setObjectName(QString::fromUtf8("actionL2TP_RequireCHAP"));
        actionL2TP_RequireCHAP->setText(QString::fromUtf8("L2TP.RequireCHAP"));
        actionL2TP_ReqAuth = new QAction(VPN_Prov);
        actionL2TP_ReqAuth->setObjectName(QString::fromUtf8("actionL2TP_ReqAuth"));
        actionL2TP_ReqAuth->setText(QString::fromUtf8("L2TP.ReqAuth"));
        actionL2TP_AccessControl = new QAction(VPN_Prov);
        actionL2TP_AccessControl->setObjectName(QString::fromUtf8("actionL2TP_AccessControl"));
        actionL2TP_AccessControl->setText(QString::fromUtf8("L2TP.AccessControl"));
        actionL2TP_AuthFile = new QAction(VPN_Prov);
        actionL2TP_AuthFile->setObjectName(QString::fromUtf8("actionL2TP_AuthFile"));
        actionL2TP_AuthFile->setText(QString::fromUtf8("L2TP.AuthFile"));
        actionL2TP_ListenAddr = new QAction(VPN_Prov);
        actionL2TP_ListenAddr->setObjectName(QString::fromUtf8("actionL2TP_ListenAddr"));
        actionL2TP_ListenAddr->setText(QString::fromUtf8("L2TP.ListenAddr"));
        actionL2TP_IPsecSaref = new QAction(VPN_Prov);
        actionL2TP_IPsecSaref->setObjectName(QString::fromUtf8("actionL2TP_IPsecSaref"));
        actionL2TP_IPsecSaref->setText(QString::fromUtf8("L2TP.IPsecSaref"));
        actionL2TP_Port = new QAction(VPN_Prov);
        actionL2TP_Port->setObjectName(QString::fromUtf8("actionL2TP_Port"));
        actionL2TP_Port->setText(QString::fromUtf8("L2TP.Port"));
        actionPPPD_NoPcomp = new QAction(VPN_Prov);
        actionPPPD_NoPcomp->setObjectName(QString::fromUtf8("actionPPPD_NoPcomp"));
        actionPPPD_NoPcomp->setText(QString::fromUtf8("PPPD.NoPcomp"));
        actionPPPD_UseAccomp = new QAction(VPN_Prov);
        actionPPPD_UseAccomp->setObjectName(QString::fromUtf8("actionPPPD_UseAccomp"));
        actionPPPD_UseAccomp->setText(QString::fromUtf8("PPPD.UseAccomp"));
        actionPPPD_ReqMPPE = new QAction(VPN_Prov);
        actionPPPD_ReqMPPE->setObjectName(QString::fromUtf8("actionPPPD_ReqMPPE"));
        actionPPPD_ReqMPPE->setText(QString::fromUtf8("PPPD.ReqMPPE"));
        actionPPPD_ReqMPPE40 = new QAction(VPN_Prov);
        actionPPPD_ReqMPPE40->setObjectName(QString::fromUtf8("actionPPPD_ReqMPPE40"));
        actionPPPD_ReqMPPE40->setText(QString::fromUtf8("PPPD.ReqMPPE40"));
        actionPPPD_ReqMPPE128 = new QAction(VPN_Prov);
        actionPPPD_ReqMPPE128->setObjectName(QString::fromUtf8("actionPPPD_ReqMPPE128"));
        actionPPPD_ReqMPPE128->setText(QString::fromUtf8("PPPD.ReqMPPE128"));
        actionPPPD_ReqMPPEStateful = new QAction(VPN_Prov);
        actionPPPD_ReqMPPEStateful->setObjectName(QString::fromUtf8("actionPPPD_ReqMPPEStateful"));
        actionPPPD_ReqMPPEStateful->setText(QString::fromUtf8("PPPD.ReqMPPEStateful"));
        actionVPNC_IPSec_ID = new QAction(VPN_Prov);
        actionVPNC_IPSec_ID->setObjectName(QString::fromUtf8("actionVPNC_IPSec_ID"));
        actionVPNC_IPSec_ID->setText(QString::fromUtf8("VPNC.IPSec.ID"));
        actionVPNC_IPSec_Secret = new QAction(VPN_Prov);
        actionVPNC_IPSec_Secret->setObjectName(QString::fromUtf8("actionVPNC_IPSec_Secret"));
        actionVPNC_IPSec_Secret->setText(QString::fromUtf8("VPNC.IPSec.Secret"));
        actionVPNC_Xauth_Username = new QAction(VPN_Prov);
        actionVPNC_Xauth_Username->setObjectName(QString::fromUtf8("actionVPNC_Xauth_Username"));
        actionVPNC_Xauth_Username->setText(QString::fromUtf8("VPNC.Xauth.Username"));
        actionVPNC_Xauth_Password = new QAction(VPN_Prov);
        actionVPNC_Xauth_Password->setObjectName(QString::fromUtf8("actionVPNC_Xauth_Password"));
        actionVPNC_Xauth_Password->setText(QString::fromUtf8("VPNC.Xauth.Password"));
        actionVPNC_IKE_Authmode = new QAction(VPN_Prov);
        actionVPNC_IKE_Authmode->setObjectName(QString::fromUtf8("actionVPNC_IKE_Authmode"));
        actionVPNC_IKE_Authmode->setText(QString::fromUtf8("VPNC.IKE.Authmode"));
        actionVPNC_IKE_DHGroup = new QAction(VPN_Prov);
        actionVPNC_IKE_DHGroup->setObjectName(QString::fromUtf8("actionVPNC_IKE_DHGroup"));
        actionVPNC_IKE_DHGroup->setText(QString::fromUtf8("VPNC.IKE.DHGroup"));
        actionVPNC_PFS = new QAction(VPN_Prov);
        actionVPNC_PFS->setObjectName(QString::fromUtf8("actionVPNC_PFS"));
        actionVPNC_PFS->setText(QString::fromUtf8("VPNC.PFS"));
        actionVPNC_Domain = new QAction(VPN_Prov);
        actionVPNC_Domain->setObjectName(QString::fromUtf8("actionVPNC_Domain"));
        actionVPNC_Domain->setText(QString::fromUtf8("VPNC.Domain"));
        actionVPNC_Vendor = new QAction(VPN_Prov);
        actionVPNC_Vendor->setObjectName(QString::fromUtf8("actionVPNC_Vendor"));
        actionVPNC_Vendor->setText(QString::fromUtf8("VPNC.Vendor"));
        actionVPNC_LocalPort = new QAction(VPN_Prov);
        actionVPNC_LocalPort->setObjectName(QString::fromUtf8("actionVPNC_LocalPort"));
        actionVPNC_LocalPort->setText(QString::fromUtf8("VPNC.LocalPort"));
        actionVPNC_CiscoPort = new QAction(VPN_Prov);
        actionVPNC_CiscoPort->setObjectName(QString::fromUtf8("actionVPNC_CiscoPort"));
        actionVPNC_CiscoPort->setText(QString::fromUtf8("VPNC.CiscoPort"));
        actionVPNC_AppVersion = new QAction(VPN_Prov);
        actionVPNC_AppVersion->setObjectName(QString::fromUtf8("actionVPNC_AppVersion"));
        actionVPNC_AppVersion->setText(QString::fromUtf8("VPNC.AppVersion"));
        actionVPNC_NATTMode = new QAction(VPN_Prov);
        actionVPNC_NATTMode->setObjectName(QString::fromUtf8("actionVPNC_NATTMode"));
        actionVPNC_NATTMode->setText(QString::fromUtf8("VPNC.NATTMode"));
        actionVPNC_DPDTimeout = new QAction(VPN_Prov);
        actionVPNC_DPDTimeout->setObjectName(QString::fromUtf8("actionVPNC_DPDTimeout"));
        actionVPNC_DPDTimeout->setText(QString::fromUtf8("VPNC.DPDTimeout"));
        actionVPNC_SingleDES = new QAction(VPN_Prov);
        actionVPNC_SingleDES->setObjectName(QString::fromUtf8("actionVPNC_SingleDES"));
        actionVPNC_SingleDES->setText(QString::fromUtf8("VPNC.SingleDES"));
        actionVPNC_NoEncryption = new QAction(VPN_Prov);
        actionVPNC_NoEncryption->setObjectName(QString::fromUtf8("actionVPNC_NoEncryption"));
        actionVPNC_NoEncryption->setText(QString::fromUtf8("VPNC.NoEncryption"));
        actionOpenVPN_CACert = new QAction(VPN_Prov);
        actionOpenVPN_CACert->setObjectName(QString::fromUtf8("actionOpenVPN_CACert"));
        actionOpenVPN_CACert->setText(QString::fromUtf8("OpenVPN.CACert"));
        actionOpenVPN_Cert = new QAction(VPN_Prov);
        actionOpenVPN_Cert->setObjectName(QString::fromUtf8("actionOpenVPN_Cert"));
        actionOpenVPN_Cert->setText(QString::fromUtf8("OpenVPN.Cert"));
        actionOpenVPN_Key = new QAction(VPN_Prov);
        actionOpenVPN_Key->setObjectName(QString::fromUtf8("actionOpenVPN_Key"));
        actionOpenVPN_Key->setText(QString::fromUtf8("OpenVPN.Key"));
        actionOpenVPN_MTU = new QAction(VPN_Prov);
        actionOpenVPN_MTU->setObjectName(QString::fromUtf8("actionOpenVPN_MTU"));
        actionOpenVPN_MTU->setText(QString::fromUtf8("OpenVPN.MTU"));
        actionOpenVPN_NSCertType = new QAction(VPN_Prov);
        actionOpenVPN_NSCertType->setObjectName(QString::fromUtf8("actionOpenVPN_NSCertType"));
        actionOpenVPN_NSCertType->setText(QString::fromUtf8("OpenVPN.NSCertType"));
        actionOpenVPN_Proto = new QAction(VPN_Prov);
        actionOpenVPN_Proto->setObjectName(QString::fromUtf8("actionOpenVPN_Proto"));
        actionOpenVPN_Proto->setText(QString::fromUtf8("OpenVPN.Proto"));
        actionOpenVPN_Port = new QAction(VPN_Prov);
        actionOpenVPN_Port->setObjectName(QString::fromUtf8("actionOpenVPN_Port"));
        actionOpenVPN_Port->setText(QString::fromUtf8("OpenVPN.Port"));
        actionOpenVPN_AuthUserPass = new QAction(VPN_Prov);
        actionOpenVPN_AuthUserPass->setObjectName(QString::fromUtf8("actionOpenVPN_AuthUserPass"));
        actionOpenVPN_AuthUserPass->setText(QString::fromUtf8("OpenVPN.AuthUserPass"));
        actionOpenVPN_AskPass = new QAction(VPN_Prov);
        actionOpenVPN_AskPass->setObjectName(QString::fromUtf8("actionOpenVPN_AskPass"));
        actionOpenVPN_AskPass->setText(QString::fromUtf8("OpenVPN.AskPass"));
        actionOpenVPN_AuthNoCache = new QAction(VPN_Prov);
        actionOpenVPN_AuthNoCache->setObjectName(QString::fromUtf8("actionOpenVPN_AuthNoCache"));
        actionOpenVPN_AuthNoCache->setText(QString::fromUtf8("OpenVPN.AuthNoCache"));
        actionOpenVPN_Cipher = new QAction(VPN_Prov);
        actionOpenVPN_Cipher->setObjectName(QString::fromUtf8("actionOpenVPN_Cipher"));
        actionOpenVPN_Cipher->setText(QString::fromUtf8("OpenVPN.Cipher"));
        actionOpenVPN_Auth = new QAction(VPN_Prov);
        actionOpenVPN_Auth->setObjectName(QString::fromUtf8("actionOpenVPN_Auth"));
        actionOpenVPN_Auth->setText(QString::fromUtf8("OpenVPN.Auth"));
        actionOpenVPN_CompLZO = new QAction(VPN_Prov);
        actionOpenVPN_CompLZO->setObjectName(QString::fromUtf8("actionOpenVPN_CompLZO"));
        actionOpenVPN_CompLZO->setText(QString::fromUtf8("OpenVPN.CompLZO"));
        actionOpenVPN_RemoteCertTls = new QAction(VPN_Prov);
        actionOpenVPN_RemoteCertTls->setObjectName(QString::fromUtf8("actionOpenVPN_RemoteCertTls"));
        actionOpenVPN_RemoteCertTls->setText(QString::fromUtf8("OpenVPN.RemoteCertTls"));
        actionOpenVPN_ConfigFile = new QAction(VPN_Prov);
        actionOpenVPN_ConfigFile->setObjectName(QString::fromUtf8("actionOpenVPN_ConfigFile"));
        actionOpenVPN_ConfigFile->setText(QString::fromUtf8("OpenVPN.ConfigFile"));
        actionOpenConnect_ServerCert = new QAction(VPN_Prov);
        actionOpenConnect_ServerCert->setObjectName(QString::fromUtf8("actionOpenConnect_ServerCert"));
        actionOpenConnect_ServerCert->setText(QString::fromUtf8("OpenConnect.ServerCert"));
        actionOpenConnect_CACert = new QAction(VPN_Prov);
        actionOpenConnect_CACert->setObjectName(QString::fromUtf8("actionOpenConnect_CACert"));
        actionOpenConnect_CACert->setText(QString::fromUtf8("OpenConnect.CACert"));
        actionOpenConnect_ClientCert = new QAction(VPN_Prov);
        actionOpenConnect_ClientCert->setObjectName(QString::fromUtf8("actionOpenConnect_ClientCert"));
        actionOpenConnect_ClientCert->setText(QString::fromUtf8("OpenConnect.ClientCert"));
        actionOpenConnect_MTU = new QAction(VPN_Prov);
        actionOpenConnect_MTU->setObjectName(QString::fromUtf8("actionOpenConnect_MTU"));
        actionOpenConnect_MTU->setText(QString::fromUtf8("OpenConnect.MTU"));
        actionOpenConnect_Cookie = new QAction(VPN_Prov);
        actionOpenConnect_Cookie->setObjectName(QString::fromUtf8("actionOpenConnect_Cookie"));
        actionOpenConnect_Cookie->setText(QString::fromUtf8("OpenConnect.Cookie"));
        actionOpenConnect_VPNHost = new QAction(VPN_Prov);
        actionOpenConnect_VPNHost->setObjectName(QString::fromUtf8("actionOpenConnect_VPNHost"));
        actionOpenConnect_VPNHost->setText(QString::fromUtf8("OpenConnect.VPNHost"));
        actionOpenVPN_Import = new QAction(VPN_Prov);
        actionOpenVPN_Import->setObjectName(QString::fromUtf8("actionOpenVPN_Import"));
        actionOpenVPN_Import->setText(QString::fromUtf8("Import Configuration"));
        actionProviderWireGuard = new QAction(VPN_Prov);
        actionProviderWireGuard->setObjectName(QString::fromUtf8("actionProviderWireGuard"));
        actionVPNC_DeviceType = new QAction(VPN_Prov);
        actionVPNC_DeviceType->setObjectName(QString::fromUtf8("actionVPNC_DeviceType"));
        actionWireGuard_Address = new QAction(VPN_Prov);
        actionWireGuard_Address->setObjectName(QString::fromUtf8("actionWireGuard_Address"));
        actionWireGuard_ListPort = new QAction(VPN_Prov);
        actionWireGuard_ListPort->setObjectName(QString::fromUtf8("actionWireGuard_ListPort"));
        actionWireGuard_DNS = new QAction(VPN_Prov);
        actionWireGuard_DNS->setObjectName(QString::fromUtf8("actionWireGuard_DNS"));
        actionWireGuard_PrivateKey = new QAction(VPN_Prov);
        actionWireGuard_PrivateKey->setObjectName(QString::fromUtf8("actionWireGuard_PrivateKey"));
        actionWireGuard_PublicKey = new QAction(VPN_Prov);
        actionWireGuard_PublicKey->setObjectName(QString::fromUtf8("actionWireGuard_PublicKey"));
        actionWireGuard_PresharedKey = new QAction(VPN_Prov);
        actionWireGuard_PresharedKey->setObjectName(QString::fromUtf8("actionWireGuard_PresharedKey"));
        actionWireGuard_AllowedIPs = new QAction(VPN_Prov);
        actionWireGuard_AllowedIPs->setObjectName(QString::fromUtf8("actionWireGuard_AllowedIPs"));
        actionWireGuard_EndpointPort = new QAction(VPN_Prov);
        actionWireGuard_EndpointPort->setObjectName(QString::fromUtf8("actionWireGuard_EndpointPort"));
        actionWireGuard_PersistentKeepalive = new QAction(VPN_Prov);
        actionWireGuard_PersistentKeepalive->setObjectName(QString::fromUtf8("actionWireGuard_PersistentKeepalive"));
        actionOpenVPN_DeviceType = new QAction(VPN_Prov);
        actionOpenVPN_DeviceType->setObjectName(QString::fromUtf8("actionOpenVPN_DeviceType"));
        actionOpenConnect_AllowSelfSignedCert = new QAction(VPN_Prov);
        actionOpenConnect_AllowSelfSignedCert->setObjectName(QString::fromUtf8("actionOpenConnect_AllowSelfSignedCert"));
        actionOpenConnect_AuthType = new QAction(VPN_Prov);
        actionOpenConnect_AuthType->setObjectName(QString::fromUtf8("actionOpenConnect_AuthType"));
        actionOpenConnect_DisableIPv6 = new QAction(VPN_Prov);
        actionOpenConnect_DisableIPv6->setObjectName(QString::fromUtf8("actionOpenConnect_DisableIPv6"));
        actionOpenConnect_NoDTLS = new QAction(VPN_Prov);
        actionOpenConnect_NoDTLS->setObjectName(QString::fromUtf8("actionOpenConnect_NoDTLS"));
        actionOpenConnect_NoHTTPKeepalive = new QAction(VPN_Prov);
        actionOpenConnect_NoHTTPKeepalive->setObjectName(QString::fromUtf8("actionOpenConnect_NoHTTPKeepalive"));
        actionOpenConnect_PKCSClientCert = new QAction(VPN_Prov);
        actionOpenConnect_PKCSClientCert->setObjectName(QString::fromUtf8("actionOpenConnect_PKCSClientCert"));
        actionOpenConnect_Usergroup = new QAction(VPN_Prov);
        actionOpenConnect_Usergroup->setObjectName(QString::fromUtf8("actionOpenConnect_Usergroup"));
        actionOpenConnect_UserPrivateKey = new QAction(VPN_Prov);
        actionOpenConnect_UserPrivateKey->setObjectName(QString::fromUtf8("actionOpenConnect_UserPrivateKey"));
        verticalLayout01 = new QVBoxLayout(VPN_Prov);
        verticalLayout01->setObjectName(QString::fromUtf8("verticalLayout01"));
        plainTextEdit_main = new QPlainTextEdit(VPN_Prov);
        plainTextEdit_main->setObjectName(QString::fromUtf8("plainTextEdit_main"));

        verticalLayout01->addWidget(plainTextEdit_main);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_open = new QPushButton(VPN_Prov);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_open);

        pushButton_save = new QPushButton(VPN_Prov);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setEnabled(true);
        pushButton_save->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_save);

        line = new QFrame(VPN_Prov);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        pushButton_delete = new QPushButton(VPN_Prov);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_delete);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_resetpage = new QPushButton(VPN_Prov);
        pushButton_resetpage->setObjectName(QString::fromUtf8("pushButton_resetpage"));
        pushButton_resetpage->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_resetpage);


        verticalLayout01->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_whatsthis = new QToolButton(VPN_Prov);
        toolButton_whatsthis->setObjectName(QString::fromUtf8("toolButton_whatsthis"));

        horizontalLayout_2->addWidget(toolButton_whatsthis);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_exit = new QPushButton(VPN_Prov);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setAutoDefault(false);

        horizontalLayout_2->addWidget(pushButton_exit);


        verticalLayout01->addLayout(horizontalLayout_2);


        retranslateUi(VPN_Prov);
        QObject::connect(pushButton_exit, SIGNAL(clicked()), VPN_Prov, SLOT(reject()));

        QMetaObject::connectSlotsByName(VPN_Prov);
    } // setupUi

    void retranslateUi(QDialog *VPN_Prov)
    {
        VPN_Prov->setWindowTitle(QCoreApplication::translate("VPN_Prov", "VPN Provisioning Editor", nullptr));
#if QT_CONFIG(tooltip)
        actionGlobalName->setToolTip(QCoreApplication::translate("VPN_Prov", "Name of the network.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionGlobalDescription->setToolTip(QCoreApplication::translate("VPN_Prov", "Description of the network.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPTP_User->setToolTip(QCoreApplication::translate("VPN_Prov", "PPTP User Name.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPTP_Password->setToolTip(QCoreApplication::translate("VPN_Prov", "PPTP Password.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_EchoFailure->setToolTip(QCoreApplication::translate("VPN_Prov", "Set the maximum number of LCP configure-NAKs returned\n"
"before starting to send configure-Rejects (default is 10).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_EchoInterval->setToolTip(QCoreApplication::translate("VPN_Prov", "Send an LCP echo-request frame to the peer every n seconds.\n"
" This option can be used with the lcp-echo-failure option to detect\n"
"that the peer is no longer connected.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_Debug->setToolTip(QCoreApplication::translate("VPN_Prov", "Debug level.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RefuseEAP->setToolTip(QCoreApplication::translate("VPN_Prov", "Deny EAP authorization?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RefusePAP->setToolTip(QCoreApplication::translate("VPN_Prov", "Deny PAP authorization?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RefuseCHAP->setToolTip(QCoreApplication::translate("VPN_Prov", "Deny CHAP authorization?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RefuseMSCHAP->setToolTip(QCoreApplication::translate("VPN_Prov", "Deny MSCHAP authorization?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RefuseMSCHAP2->setToolTip(QCoreApplication::translate("VPN_Prov", "Deny MSCHAPV2 authorization?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_NoBSDComp->setToolTip(QCoreApplication::translate("VPN_Prov", "Disables BSD compression?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_NoDeflate->setToolTip(QCoreApplication::translate("VPN_Prov", "Disable deflate compression?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RequirMPPE->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the use of MPPE?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RequirMPPE40->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the use of MPPE 40 bit?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RequirMPPE128->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the use of MPPE 128 bit?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_RequirMPPEStateful->setToolTip(QCoreApplication::translate("VPN_Prov", "Allow MPPE to use stateful mode?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_NoVJ->setToolTip(QCoreApplication::translate("VPN_Prov", "Disable Van Jacobson compression?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_User->setToolTip(QCoreApplication::translate("VPN_Prov", "L2TP User Name.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_Password->setToolTip(QCoreApplication::translate("VPN_Prov", "L2TP Password.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_BPS->setToolTip(QCoreApplication::translate("VPN_Prov", "Maximum bandwidth to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_TXBPS->setToolTip(QCoreApplication::translate("VPN_Prov", "Maximum transmit bandwidth to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_RXBPS->setToolTip(QCoreApplication::translate("VPN_Prov", "Maximum receive bandwidth to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_LengthBit->setToolTip(QCoreApplication::translate("VPN_Prov", "Use length bit?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_Challenge->setToolTip(QCoreApplication::translate("VPN_Prov", "Use challenge authentication?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_DefaultRoute->setToolTip(QCoreApplication::translate("VPN_Prov", "Add a default route to the system routing tables, using the peer as the gatewa?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_FlowBit->setToolTip(QCoreApplication::translate("VPN_Prov", "Sequence numbers included in the communication?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_TunnelRWS->setToolTip(QCoreApplication::translate("VPN_Prov", "The window size of the control channel (number of unacknowledged packets, not bytes)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_Exclusive->setToolTip(QCoreApplication::translate("VPN_Prov", "Use only one control channel?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_Redial->setToolTip(QCoreApplication::translate("VPN_Prov", "Redial if disconnected?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_RedialTImeout->setToolTip(QCoreApplication::translate("VPN_Prov", "Wait n seconds before redial.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_MaxRedials->setToolTip(QCoreApplication::translate("VPN_Prov", "Give up redial tries after X attempts.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_RequirePAP->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the remote peer to get authenticated via PAP?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_RequireCHAP->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the remote peer to get authenticated via CHAP?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_ReqAuth->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the remote peer to authenticate itself?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_AccessControl->setToolTip(QCoreApplication::translate("VPN_Prov", "Only accept connections from specified peer addresses?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_AuthFile->setToolTip(QCoreApplication::translate("VPN_Prov", "Authentication file location.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_ListenAddr->setToolTip(QCoreApplication::translate("VPN_Prov", "The IP address of the interface on which the daemon listens.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_IPsecSaref->setToolTip(QCoreApplication::translate("VPN_Prov", "Use IPsec Security Association tracking?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionL2TP_Port->setToolTip(QCoreApplication::translate("VPN_Prov", "Specify which UDP port should be used.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_NoPcomp->setToolTip(QCoreApplication::translate("VPN_Prov", "Disable protocol compression?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_UseAccomp->setToolTip(QCoreApplication::translate("VPN_Prov", "Disable address/control compression?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_ReqMPPE->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the use of MPPE?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_ReqMPPE40->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the use of MPPE 40 bit?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_ReqMPPE128->setToolTip(QCoreApplication::translate("VPN_Prov", "Require the use of MPPE 128 bit?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionPPPD_ReqMPPEStateful->setToolTip(QCoreApplication::translate("VPN_Prov", "Allow MPPE to use stateful mode?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_IPSec_ID->setToolTip(QCoreApplication::translate("VPN_Prov", "Your Group username.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_IPSec_Secret->setToolTip(QCoreApplication::translate("VPN_Prov", "Your group password (cleartext).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_Xauth_Username->setToolTip(QCoreApplication::translate("VPN_Prov", "Your username.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_Xauth_Password->setToolTip(QCoreApplication::translate("VPN_Prov", "Your password (cleartext).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_IKE_Authmode->setToolTip(QCoreApplication::translate("VPN_Prov", "IKE authentication mode.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_IKE_DHGroup->setToolTip(QCoreApplication::translate("VPN_Prov", "Name of the IKE DH Group.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_PFS->setToolTip(QCoreApplication::translate("VPN_Prov", "DH gropup to use for perfect forward secrecy. ", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_Domain->setToolTip(QCoreApplication::translate("VPN_Prov", "Domain name for authentication.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_Vendor->setToolTip(QCoreApplication::translate("VPN_Prov", "Vendor of your IPSec gateway.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_LocalPort->setToolTip(QCoreApplication::translate("VPN_Prov", "Local ISAKMP port to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_CiscoPort->setToolTip(QCoreApplication::translate("VPN_Prov", "Local UDP port number to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_AppVersion->setToolTip(QCoreApplication::translate("VPN_Prov", "Application version to report.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_NATTMode->setToolTip(QCoreApplication::translate("VPN_Prov", "NAT-Traversal method to employ.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_DPDTimeout->setToolTip(QCoreApplication::translate("VPN_Prov", "Send DPD packet after not receiving anything for n seconds", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_SingleDES->setToolTip(QCoreApplication::translate("VPN_Prov", "Enable single DES encryption.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionVPNC_NoEncryption->setToolTip(QCoreApplication::translate("VPN_Prov", "Enables using no encryption for data traffic.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_CACert->setToolTip(QCoreApplication::translate("VPN_Prov", "Certificate authority file.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_Cert->setToolTip(QCoreApplication::translate("VPN_Prov", "File containing peer's signed certificate.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_Key->setToolTip(QCoreApplication::translate("VPN_Prov", "File containing local peer's private key.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_MTU->setToolTip(QCoreApplication::translate("VPN_Prov", "MTU of the tunnel.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_NSCertType->setToolTip(QCoreApplication::translate("VPN_Prov", "Peer certificate type (server/client).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_Proto->setToolTip(QCoreApplication::translate("VPN_Prov", "Protocol type (udp/tcp-client/tcp-server).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_Port->setToolTip(QCoreApplication::translate("VPN_Prov", "TCP/UDP port number.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_AuthUserPass->setToolTip(QCoreApplication::translate("VPN_Prov", "File containing the user:password credentials.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_AskPass->setToolTip(QCoreApplication::translate("VPN_Prov", "Get certificate password from console or file?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_AuthNoCache->setToolTip(QCoreApplication::translate("VPN_Prov", "Don't cache --askpass or --auth-user-pass values?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_Cipher->setToolTip(QCoreApplication::translate("VPN_Prov", "Encrypt packets with cipher algorithm:", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_Auth->setToolTip(QCoreApplication::translate("VPN_Prov", "Authenticate packets using algorithm:", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_CompLZO->setToolTip(QCoreApplication::translate("VPN_Prov", "Use fast LZO compression (yes/no/adaptive).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_RemoteCertTls->setToolTip(QCoreApplication::translate("VPN_Prov", "Require peer certificate signed (client/server).", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenVPN_ConfigFile->setToolTip(QCoreApplication::translate("VPN_Prov", "OpenVPN config file that can contain extra options.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenConnect_ServerCert->setToolTip(QCoreApplication::translate("VPN_Prov", "SHA1 certificate fingerprint of the final VPN server.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenConnect_CACert->setToolTip(QCoreApplication::translate("VPN_Prov", "File containing other certificate authorities.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenConnect_ClientCert->setToolTip(QCoreApplication::translate("VPN_Prov", "Client certificate file, if needed for web authentication. ", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenConnect_MTU->setToolTip(QCoreApplication::translate("VPN_Prov", "Request MTU from server to use as MTU of tunnel?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenConnect_Cookie->setToolTip(QCoreApplication::translate("VPN_Prov", "Read cookie from standard input?", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        actionOpenConnect_VPNHost->setToolTip(QCoreApplication::translate("VPN_Prov", "The final VPN server to use after completing web authentication.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionProviderWireGuard->setText(QCoreApplication::translate("VPN_Prov", "Provider WireGuard", nullptr));
#if QT_CONFIG(tooltip)
        actionProviderWireGuard->setToolTip(QCoreApplication::translate("VPN_Prov", "Provider Wire Guard", nullptr));
#endif // QT_CONFIG(tooltip)
        actionVPNC_DeviceType->setText(QCoreApplication::translate("VPN_Prov", "VPNC.DeviceType", nullptr));
#if QT_CONFIG(tooltip)
        actionVPNC_DeviceType->setToolTip(QCoreApplication::translate("VPN_Prov", "Wheher the VPN should use tun or tap.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_Address->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.Address", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_Address->setToolTip(QCoreApplication::translate("VPN_Prov", "Internal IP Address", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_ListPort->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.ListPort", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_ListPort->setToolTip(QCoreApplication::translate("VPN_Prov", "Local listen port (optional).", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_DNS->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.DNS", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_DNS->setToolTip(QCoreApplication::translate("VPN_Prov", "List of name servers (optional).", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_PrivateKey->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.PrivateKey", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_PrivateKey->setToolTip(QCoreApplication::translate("VPN_Prov", "Private key of the interface.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_PublicKey->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.PublicKey", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_PublicKey->setToolTip(QCoreApplication::translate("VPN_Prov", "Public key of peer.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_PresharedKey->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.PresharedKey", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_PresharedKey->setToolTip(QCoreApplication::translate("VPN_Prov", "Preshared key of peer (optional).", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_AllowedIPs->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.AllowedIPs", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_AllowedIPs->setToolTip(QCoreApplication::translate("VPN_Prov", "See cryptokey routing.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_EndpointPort->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.EndpointPort", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_EndpointPort->setToolTip(QCoreApplication::translate("VPN_Prov", "Endpoint listen port (optional).", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWireGuard_PersistentKeepalive->setText(QCoreApplication::translate("VPN_Prov", "WireGuard.PersistentKeepalive", nullptr));
#if QT_CONFIG(tooltip)
        actionWireGuard_PersistentKeepalive->setToolTip(QCoreApplication::translate("VPN_Prov", "Keep alive in seconds (optional).", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenVPN_DeviceType->setText(QCoreApplication::translate("VPN_Prov", "OpenVPN.DeviceType", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenVPN_DeviceType->setToolTip(QCoreApplication::translate("VPN_Prov", "Whether the VPN should use tun or tap.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_AllowSelfSignedCert->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.AllowSelfSignedCert", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_AllowSelfSignedCert->setToolTip(QCoreApplication::translate("VPN_Prov", "Define if self signed server certificates are allowed.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_AuthType->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.AuthType", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_AuthType->setToolTip(QCoreApplication::translate("VPN_Prov", "Type of authentication used.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_DisableIPv6->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.DisableIPv6", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_DisableIPv6->setToolTip(QCoreApplication::translate("VPN_Prov", "Do not ask for IPv6 connectivity.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_NoDTLS->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.NoDTLS", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_NoDTLS->setToolTip(QCoreApplication::translate("VPN_Prov", "Disable DTLS and ESP.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_NoHTTPKeepalive->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.NoHTTPKeepalive", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_NoHTTPKeepalive->setToolTip(QCoreApplication::translate("VPN_Prov", "Disable HTTP connection re-use.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_PKCSClientCert->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.PKCSClientCert", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_PKCSClientCert->setToolTip(QCoreApplication::translate("VPN_Prov", "Certificate and privatekey in a PKCS#1/PKCS#8/PKCS#12 structure.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_Usergroup->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.Usergroup", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_Usergroup->setToolTip(QCoreApplication::translate("VPN_Prov", "Set login usergroup on remote server.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenConnect_UserPrivateKey->setText(QCoreApplication::translate("VPN_Prov", "OpenConnect.UserPrivateKey", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenConnect_UserPrivateKey->setToolTip(QCoreApplication::translate("VPN_Prov", "SSL private key file needed by web authentication.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        plainTextEdit_main->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Text edit window.</p><p>You may type or cut and paste into this window. You may also use menus above to insert text fields.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        pushButton_open->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Open an existing config file.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_open->setText(QCoreApplication::translate("VPN_Prov", "&Open", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_save->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Write the displayed data to a config file.</p><p>The combo box is seeded with a list of CMST created config files to provide an easy way to overwrite one. You may also type a name in the ComboBox.</p><p>It is not necessary to provide a path nor a file extension as both will be stripped out and replaced allowed values. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_save->setText(QCoreApplication::translate("VPN_Prov", "&Save", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_delete->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Delete a config file.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_delete->setText(QCoreApplication::translate("VPN_Prov", "&Delete", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_resetpage->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Clear all text from the editor window.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_resetpage->setText(QCoreApplication::translate("VPN_Prov", "&Clear Page", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_whatsthis->setToolTip(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>What's This</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        toolButton_whatsthis->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Enter &quot;Whats This&quot; mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolButton_whatsthis->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_exit->setWhatsThis(QCoreApplication::translate("VPN_Prov", "<html><head/><body><p>Exit the dialog.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_exit->setText(QCoreApplication::translate("VPN_Prov", "E&xit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VPN_Prov: public Ui_VPN_Prov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VPN_PROV_EDITOR_H
