/********************************************************************************
** Form generated from reading UI file 'vpnagent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VPNAGENT_H
#define UI_VPNAGENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_VPNAgent
{
public:
    QFormLayout *formLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QLabel *label_host;
    QLineEdit *lineEdit_host;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QGroupBox *groupBox_openconnect;
    QFormLayout *formLayout_2;
    QLabel *label_cacert;
    QLineEdit *lineEdit_cacert;
    QLabel *label_clientcert;
    QLineEdit *lineEdit_clientcert;
    QLabel *label_cookie;
    QLineEdit *lineEdit_cookie;
    QLabel *servercert;
    QLineEdit *lineEdit_servercert;
    QLabel *label_vpnhost;
    QLineEdit *lineEdit_vpnhost;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_whatsthis;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox_savecredentials;

    void setupUi(QDialog *VPNAgent)
    {
        if (VPNAgent->objectName().isEmpty())
            VPNAgent->setObjectName(QString::fromUtf8("VPNAgent"));
        VPNAgent->resize(345, 433);
        formLayout = new QFormLayout(VPNAgent);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_username = new QLabel(VPNAgent);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_username);

        lineEdit_username = new QLineEdit(VPNAgent);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_username);

        label_password = new QLabel(VPNAgent);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(VPNAgent);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setClearButtonEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_password);

        label_host = new QLabel(VPNAgent);
        label_host->setObjectName(QString::fromUtf8("label_host"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_host);

        lineEdit_host = new QLineEdit(VPNAgent);
        lineEdit_host->setObjectName(QString::fromUtf8("lineEdit_host"));
        lineEdit_host->setClearButtonEnabled(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_host);

        label_name = new QLabel(VPNAgent);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(VPNAgent);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setClearButtonEnabled(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_name);

        groupBox_openconnect = new QGroupBox(VPNAgent);
        groupBox_openconnect->setObjectName(QString::fromUtf8("groupBox_openconnect"));
        formLayout_2 = new QFormLayout(groupBox_openconnect);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_cacert = new QLabel(groupBox_openconnect);
        label_cacert->setObjectName(QString::fromUtf8("label_cacert"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_cacert);

        lineEdit_cacert = new QLineEdit(groupBox_openconnect);
        lineEdit_cacert->setObjectName(QString::fromUtf8("lineEdit_cacert"));
        lineEdit_cacert->setClearButtonEnabled(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_cacert);

        label_clientcert = new QLabel(groupBox_openconnect);
        label_clientcert->setObjectName(QString::fromUtf8("label_clientcert"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_clientcert);

        lineEdit_clientcert = new QLineEdit(groupBox_openconnect);
        lineEdit_clientcert->setObjectName(QString::fromUtf8("lineEdit_clientcert"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_clientcert);

        label_cookie = new QLabel(groupBox_openconnect);
        label_cookie->setObjectName(QString::fromUtf8("label_cookie"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_cookie);

        lineEdit_cookie = new QLineEdit(groupBox_openconnect);
        lineEdit_cookie->setObjectName(QString::fromUtf8("lineEdit_cookie"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_cookie);

        servercert = new QLabel(groupBox_openconnect);
        servercert->setObjectName(QString::fromUtf8("servercert"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, servercert);

        lineEdit_servercert = new QLineEdit(groupBox_openconnect);
        lineEdit_servercert->setObjectName(QString::fromUtf8("lineEdit_servercert"));
        lineEdit_servercert->setClearButtonEnabled(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit_servercert);

        label_vpnhost = new QLabel(groupBox_openconnect);
        label_vpnhost->setObjectName(QString::fromUtf8("label_vpnhost"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_vpnhost);

        lineEdit_vpnhost = new QLineEdit(groupBox_openconnect);
        lineEdit_vpnhost->setObjectName(QString::fromUtf8("lineEdit_vpnhost"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEdit_vpnhost);


        formLayout->setWidget(7, QFormLayout::SpanningRole, groupBox_openconnect);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButton_whatsthis = new QToolButton(VPNAgent);
        toolButton_whatsthis->setObjectName(QString::fromUtf8("toolButton_whatsthis"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons16x16/images/16x16/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_whatsthis->setIcon(icon);

        horizontalLayout_3->addWidget(toolButton_whatsthis);

        horizontalSpacer_3 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_accept = new QPushButton(VPNAgent);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));

        horizontalLayout_3->addWidget(pushButton_accept);

        pushButton_cancel = new QPushButton(VPNAgent);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);


        formLayout->setLayout(9, QFormLayout::SpanningRole, horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(11, QFormLayout::LabelRole, verticalSpacer);

        checkBox_savecredentials = new QCheckBox(VPNAgent);
        checkBox_savecredentials->setObjectName(QString::fromUtf8("checkBox_savecredentials"));

        formLayout->setWidget(8, QFormLayout::LabelRole, checkBox_savecredentials);

#if QT_CONFIG(shortcut)
        label_username->setBuddy(lineEdit_username);
        label_password->setBuddy(lineEdit_password);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(lineEdit_username, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, lineEdit_host);
        QWidget::setTabOrder(lineEdit_host, lineEdit_cacert);
        QWidget::setTabOrder(lineEdit_cacert, lineEdit_clientcert);
        QWidget::setTabOrder(lineEdit_clientcert, lineEdit_cookie);
        QWidget::setTabOrder(lineEdit_cookie, lineEdit_servercert);
        QWidget::setTabOrder(lineEdit_servercert, lineEdit_vpnhost);
        QWidget::setTabOrder(lineEdit_vpnhost, pushButton_accept);
        QWidget::setTabOrder(pushButton_accept, pushButton_cancel);
        QWidget::setTabOrder(pushButton_cancel, toolButton_whatsthis);

        retranslateUi(VPNAgent);
        QObject::connect(pushButton_accept, SIGNAL(clicked()), VPNAgent, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), VPNAgent, SLOT(reject()));

        QMetaObject::connectSlotsByName(VPNAgent);
    } // setupUi

    void retranslateUi(QDialog *VPNAgent)
    {
        VPNAgent->setWindowTitle(QCoreApplication::translate("VPNAgent", "VPN Agent Input", nullptr));
        label_username->setText(QCoreApplication::translate("VPNAgent", "Username", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_username->setWhatsThis(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>WISPr username.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_password->setText(QCoreApplication::translate("VPNAgent", "Password", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_password->setWhatsThis(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>WISPr password.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_host->setText(QCoreApplication::translate("VPNAgent", "Host", nullptr));
        label_name->setText(QCoreApplication::translate("VPNAgent", "Name", nullptr));
        groupBox_openconnect->setTitle(QCoreApplication::translate("VPNAgent", "OpenConnect", nullptr));
        label_cacert->setText(QCoreApplication::translate("VPNAgent", "CA Cert.", nullptr));
        label_clientcert->setText(QCoreApplication::translate("VPNAgent", "Client Cert.", nullptr));
        label_cookie->setText(QCoreApplication::translate("VPNAgent", "Cookie", nullptr));
        servercert->setText(QCoreApplication::translate("VPNAgent", "Server Cert.", nullptr));
        label_vpnhost->setText(QCoreApplication::translate("VPNAgent", "VPN Host", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_whatsthis->setToolTip(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>What's This</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_whatsthis->setText(QCoreApplication::translate("VPNAgent", "...", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_accept->setToolTip(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>Continue the connection process.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_accept->setWhatsThis(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>Accept and use the answers you have provided in this dialog. </p><p>This will send your input to the connman daemon to continue the connection process.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_accept->setText(QCoreApplication::translate("VPNAgent", "O&K", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_cancel->setToolTip(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>Cancel the connection process.<br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_cancel->setWhatsThis(QCoreApplication::translate("VPNAgent", "<html><head/><body><p>Cancel the dialog. </p><p>This will send a message to the connman daemon that you have cancelled the connection request.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_cancel->setText(QCoreApplication::translate("VPNAgent", "&Cancel", nullptr));
        checkBox_savecredentials->setText(QCoreApplication::translate("VPNAgent", "Save Credentials", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VPNAgent: public Ui_VPNAgent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VPNAGENT_H
