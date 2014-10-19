/********************************************************************************
** Form generated from reading UI file 'peditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDITOR_H
#define UI_PEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Peditor
{
public:
    QVBoxLayout *verticalLayout_3;
    QToolBox *toolBox_peditor;
    QWidget *general;
    QVBoxLayout *verticalLayout_9;
    QCheckBox *checkBox_autoconnect;
    QSpacerItem *verticalSpacer_9;
    QWidget *nameservers;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_nameservers;
    QSpacerItem *verticalSpacer_4;
    QWidget *timeservers;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_timeservers;
    QSpacerItem *verticalSpacer_5;
    QWidget *domains;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_domains;
    QSpacerItem *verticalSpacer_8;
    QWidget *ipv4;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_ipv4address;
    QLabel *label;
    QLineEdit *lineEdit_ipv4gateway;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_ipv4netmask;
    QComboBox *comboBox_ipv4method;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;
    QWidget *ipv6;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QComboBox *comboBox_ipv6method;
    QLabel *label_4;
    QSpinBox *spinBox_ipv6prefixlength;
    QLabel *label_7;
    QLineEdit *lineEdit_ipv6address;
    QLabel *label_6;
    QLineEdit *lineEdit_ipv6gateway;
    QLabel *label_5;
    QComboBox *comboBox_ipv6privacy;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_2;
    QWidget *proxy;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QComboBox *comboBox_proxymethod;
    QStackedWidget *stackedWidget_proxy01;
    QWidget *page_0;
    QWidget *page_1;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_proxyurl;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_10;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLineEdit *lineEdit_proxyservers;
    QLabel *label_12;
    QLineEdit *lineEdit_proxyexcludes;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_whatsthis;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_resetpage;
    QPushButton *pushButton_resetall;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Peditor)
    {
        if (Peditor->objectName().isEmpty())
            Peditor->setObjectName(QStringLiteral("Peditor"));
        Peditor->resize(297, 450);
        Peditor->setSizeGripEnabled(true);
        Peditor->setModal(true);
        verticalLayout_3 = new QVBoxLayout(Peditor);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        toolBox_peditor = new QToolBox(Peditor);
        toolBox_peditor->setObjectName(QStringLiteral("toolBox_peditor"));
        general = new QWidget();
        general->setObjectName(QStringLiteral("general"));
        general->setGeometry(QRect(0, 0, 279, 166));
        verticalLayout_9 = new QVBoxLayout(general);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        checkBox_autoconnect = new QCheckBox(general);
        checkBox_autoconnect->setObjectName(QStringLiteral("checkBox_autoconnect"));

        verticalLayout_9->addWidget(checkBox_autoconnect);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);

        toolBox_peditor->addItem(general, QStringLiteral("&General"));
        nameservers = new QWidget();
        nameservers->setObjectName(QStringLiteral("nameservers"));
        nameservers->setGeometry(QRect(0, 0, 279, 166));
        verticalLayout_2 = new QVBoxLayout(nameservers);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_nameservers = new QLineEdit(nameservers);
        lineEdit_nameservers->setObjectName(QStringLiteral("lineEdit_nameservers"));

        verticalLayout_2->addWidget(lineEdit_nameservers);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        toolBox_peditor->addItem(nameservers, QStringLiteral("&Nameservers"));
        timeservers = new QWidget();
        timeservers->setObjectName(QStringLiteral("timeservers"));
        timeservers->setGeometry(QRect(0, 0, 279, 166));
        verticalLayout_4 = new QVBoxLayout(timeservers);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEdit_timeservers = new QLineEdit(timeservers);
        lineEdit_timeservers->setObjectName(QStringLiteral("lineEdit_timeservers"));

        verticalLayout_4->addWidget(lineEdit_timeservers);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        toolBox_peditor->addItem(timeservers, QStringLiteral("&TImeservers"));
        domains = new QWidget();
        domains->setObjectName(QStringLiteral("domains"));
        domains->setGeometry(QRect(0, 0, 279, 166));
        verticalLayout_5 = new QVBoxLayout(domains);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_domains = new QLineEdit(domains);
        lineEdit_domains->setObjectName(QStringLiteral("lineEdit_domains"));

        verticalLayout_5->addWidget(lineEdit_domains);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);

        toolBox_peditor->addItem(domains, QStringLiteral("&Domains"));
        ipv4 = new QWidget();
        ipv4->setObjectName(QStringLiteral("ipv4"));
        ipv4->setGeometry(QRect(0, 0, 154, 132));
        verticalLayout = new QVBoxLayout(ipv4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_ipv4address = new QLineEdit(ipv4);
        lineEdit_ipv4address->setObjectName(QStringLiteral("lineEdit_ipv4address"));

        gridLayout_2->addWidget(lineEdit_ipv4address, 1, 1, 1, 1);

        label = new QLabel(ipv4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        lineEdit_ipv4gateway = new QLineEdit(ipv4);
        lineEdit_ipv4gateway->setObjectName(QStringLiteral("lineEdit_ipv4gateway"));

        gridLayout_2->addWidget(lineEdit_ipv4gateway, 3, 1, 1, 1);

        label_2 = new QLabel(ipv4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(ipv4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_ipv4netmask = new QLineEdit(ipv4);
        lineEdit_ipv4netmask->setObjectName(QStringLiteral("lineEdit_ipv4netmask"));

        gridLayout_2->addWidget(lineEdit_ipv4netmask, 2, 1, 1, 1);

        comboBox_ipv4method = new QComboBox(ipv4);
        comboBox_ipv4method->setObjectName(QStringLiteral("comboBox_ipv4method"));

        gridLayout_2->addWidget(comboBox_ipv4method, 0, 1, 1, 1);

        label_8 = new QLabel(ipv4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolBox_peditor->addItem(ipv4, QStringLiteral("IPv&4"));
        ipv6 = new QWidget();
        ipv6->setObjectName(QStringLiteral("ipv6"));
        ipv6->setGeometry(QRect(0, 0, 194, 161));
        verticalLayout_6 = new QVBoxLayout(ipv6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_ipv6method = new QComboBox(ipv6);
        comboBox_ipv6method->setObjectName(QStringLiteral("comboBox_ipv6method"));

        gridLayout->addWidget(comboBox_ipv6method, 0, 1, 1, 1);

        label_4 = new QLabel(ipv6);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        spinBox_ipv6prefixlength = new QSpinBox(ipv6);
        spinBox_ipv6prefixlength->setObjectName(QStringLiteral("spinBox_ipv6prefixlength"));
        spinBox_ipv6prefixlength->setMaximum(255);

        gridLayout->addWidget(spinBox_ipv6prefixlength, 1, 1, 1, 1);

        label_7 = new QLabel(ipv6);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_ipv6address = new QLineEdit(ipv6);
        lineEdit_ipv6address->setObjectName(QStringLiteral("lineEdit_ipv6address"));

        gridLayout->addWidget(lineEdit_ipv6address, 2, 1, 1, 1);

        label_6 = new QLabel(ipv6);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_ipv6gateway = new QLineEdit(ipv6);
        lineEdit_ipv6gateway->setObjectName(QStringLiteral("lineEdit_ipv6gateway"));

        gridLayout->addWidget(lineEdit_ipv6gateway, 3, 1, 1, 1);

        label_5 = new QLabel(ipv6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        comboBox_ipv6privacy = new QComboBox(ipv6);
        comboBox_ipv6privacy->setObjectName(QStringLiteral("comboBox_ipv6privacy"));

        gridLayout->addWidget(comboBox_ipv6privacy, 4, 1, 1, 1);

        label_9 = new QLabel(ipv6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        toolBox_peditor->addItem(ipv6, QStringLiteral("IPv&6"));
        proxy = new QWidget();
        proxy->setObjectName(QStringLiteral("proxy"));
        proxy->setGeometry(QRect(0, 0, 146, 168));
        verticalLayout_7 = new QVBoxLayout(proxy);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_13 = new QLabel(proxy);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        comboBox_proxymethod = new QComboBox(proxy);
        comboBox_proxymethod->setObjectName(QStringLiteral("comboBox_proxymethod"));

        gridLayout_3->addWidget(comboBox_proxymethod, 0, 1, 1, 1);

        stackedWidget_proxy01 = new QStackedWidget(proxy);
        stackedWidget_proxy01->setObjectName(QStringLiteral("stackedWidget_proxy01"));
        page_0 = new QWidget();
        page_0->setObjectName(QStringLiteral("page_0"));
        stackedWidget_proxy01->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        gridLayout_4 = new QGridLayout(page_1);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_proxyurl = new QLineEdit(page_1);
        lineEdit_proxyurl->setObjectName(QStringLiteral("lineEdit_proxyurl"));

        gridLayout_4->addWidget(lineEdit_proxyurl, 0, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 173, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_7, 1, 2, 1, 1);

        label_10 = new QLabel(page_1);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);

        stackedWidget_proxy01->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_8 = new QVBoxLayout(page_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_8->addWidget(label_11);

        lineEdit_proxyservers = new QLineEdit(page_2);
        lineEdit_proxyservers->setObjectName(QStringLiteral("lineEdit_proxyservers"));

        verticalLayout_8->addWidget(lineEdit_proxyservers);

        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_8->addWidget(label_12);

        lineEdit_proxyexcludes = new QLineEdit(page_2);
        lineEdit_proxyexcludes->setObjectName(QStringLiteral("lineEdit_proxyexcludes"));

        verticalLayout_8->addWidget(lineEdit_proxyexcludes);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        stackedWidget_proxy01->addWidget(page_2);

        gridLayout_3->addWidget(stackedWidget_proxy01, 1, 0, 1, 2);


        verticalLayout_7->addLayout(gridLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 243, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        toolBox_peditor->addItem(proxy, QStringLiteral("&Proxy"));

        verticalLayout_3->addWidget(toolBox_peditor);

        line = new QFrame(Peditor);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_whatsthis = new QToolButton(Peditor);
        toolButton_whatsthis->setObjectName(QStringLiteral("toolButton_whatsthis"));

        horizontalLayout->addWidget(toolButton_whatsthis);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_resetpage = new QPushButton(Peditor);
        pushButton_resetpage->setObjectName(QStringLiteral("pushButton_resetpage"));

        horizontalLayout->addWidget(pushButton_resetpage);

        pushButton_resetall = new QPushButton(Peditor);
        pushButton_resetall->setObjectName(QStringLiteral("pushButton_resetall"));

        horizontalLayout->addWidget(pushButton_resetall);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(Peditor);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setEnabled(true);

        horizontalLayout_2->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(Peditor);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        verticalLayout_3->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(comboBox_ipv4method, lineEdit_ipv4address);
        QWidget::setTabOrder(lineEdit_ipv4address, lineEdit_ipv4netmask);
        QWidget::setTabOrder(lineEdit_ipv4netmask, lineEdit_ipv4gateway);
        QWidget::setTabOrder(lineEdit_ipv4gateway, comboBox_ipv6method);
        QWidget::setTabOrder(comboBox_ipv6method, spinBox_ipv6prefixlength);
        QWidget::setTabOrder(spinBox_ipv6prefixlength, lineEdit_ipv6address);
        QWidget::setTabOrder(lineEdit_ipv6address, lineEdit_ipv6gateway);
        QWidget::setTabOrder(lineEdit_ipv6gateway, comboBox_ipv6privacy);
        QWidget::setTabOrder(comboBox_ipv6privacy, comboBox_proxymethod);
        QWidget::setTabOrder(comboBox_proxymethod, lineEdit_proxyurl);
        QWidget::setTabOrder(lineEdit_proxyurl, toolButton_whatsthis);
        QWidget::setTabOrder(toolButton_whatsthis, pushButton_resetpage);
        QWidget::setTabOrder(pushButton_resetpage, pushButton_resetall);
        QWidget::setTabOrder(pushButton_resetall, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_cancel);

        retranslateUi(Peditor);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), Peditor, SLOT(reject()));
        QObject::connect(comboBox_proxymethod, SIGNAL(activated(int)), stackedWidget_proxy01, SLOT(setCurrentIndex(int)));

        toolBox_peditor->setCurrentIndex(0);
        stackedWidget_proxy01->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Peditor);
    } // setupUi

    void retranslateUi(QDialog *Peditor)
    {
        Peditor->setWindowTitle(QApplication::translate("Peditor", "Property Editor", 0));
#ifndef QT_NO_WHATSTHIS
        checkBox_autoconnect->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>If checked this service will auto-connect when no other connection is available. This is only available for services marked &quot;Favorite&quot;. </p><p>The service will not auto-connect while roaming.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        checkBox_autoconnect->setText(QApplication::translate("Peditor", "AutoConnect", 0));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(general), QApplication::translate("Peditor", "&General", 0));
#ifndef QT_NO_WHATSTHIS
        nameservers->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>The list of manually configured domain name servers. Some cellular networks don't provide correct name servers and this allows for an override.</p><p>This array is sorted by priority and the first entry in the list represents the nameserver with the highest priority.</p><p>When using manual configuration and no global nameservers are configured, then it is useful to configure this setting.</p><p>Enter one or more IP addresses.  Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(nameservers), QApplication::translate("Peditor", "&Nameservers", 0));
#ifndef QT_NO_WHATSTHIS
        timeservers->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>The list of manually configured time servers.</p><p>The first entry in the list represents the timeserver with the highest priority.</p><p>When using manual configuration this setting is useful to override all the other timeserver settings. This is service specific, hence only the values for the default service are used.</p><p>Changes to this property will result in restart of NTP query.</p><p>Enter one or more IP addresses.  Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(timeservers), QApplication::translate("Peditor", "&TImeservers", 0));
#ifndef QT_NO_WHATSTHIS
        domains->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>List of manually configures search domains.</p><p>Enter one or more IP addresses.  Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(domains), QApplication::translate("Peditor", "&Domains", 0));
#ifndef QT_NO_WHATSTHIS
        ipv4->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>User configuration of IPv4 settings.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Peditor", "Address", 0));
        label_2->setText(QApplication::translate("Peditor", "Netmask", 0));
        label_3->setText(QApplication::translate("Peditor", "Gateway", 0));
        comboBox_ipv4method->clear();
        comboBox_ipv4method->insertItems(0, QStringList()
         << QApplication::translate("Peditor", "DHCP", 0)
         << QApplication::translate("Peditor", "Manual", 0)
         << QApplication::translate("Peditor", "Off", 0)
        );
        label_8->setText(QApplication::translate("Peditor", "Method", 0));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(ipv4), QApplication::translate("Peditor", "IPv&4", 0));
#ifndef QT_NO_WHATSTHIS
        ipv6->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>User configuration of IPv6 settings</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        comboBox_ipv6method->clear();
        comboBox_ipv6method->insertItems(0, QStringList()
         << QApplication::translate("Peditor", "Auto", 0)
         << QApplication::translate("Peditor", "Manual", 0)
         << QApplication::translate("Peditor", "Off", 0)
        );
        label_4->setText(QApplication::translate("Peditor", "Gateway", 0));
        label_7->setText(QApplication::translate("Peditor", "Prefix Length", 0));
        label_6->setText(QApplication::translate("Peditor", "Privacy", 0));
        label_5->setText(QApplication::translate("Peditor", "Address", 0));
        comboBox_ipv6privacy->clear();
        comboBox_ipv6privacy->insertItems(0, QStringList()
         << QApplication::translate("Peditor", "Disabled", 0)
         << QApplication::translate("Peditor", "Preferred", 0)
         << QApplication::translate("Peditor", "Enabled", 0)
        );
        label_9->setText(QApplication::translate("Peditor", "Method", 0));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(ipv6), QApplication::translate("Peditor", "IPv&6", 0));
#ifndef QT_NO_WHATSTHIS
        proxy->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>User configuration of Proxy settings.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_13->setText(QApplication::translate("Peditor", "Method", 0));
        comboBox_proxymethod->clear();
        comboBox_proxymethod->insertItems(0, QStringList()
         << QApplication::translate("Peditor", "Direct", 0)
         << QApplication::translate("Peditor", "Auto", 0)
         << QApplication::translate("Peditor", "Manual", 0)
        );
#ifndef QT_NO_WHATSTHIS
        lineEdit_proxyurl->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Automatic proxy configuration URL.  Used by the &quot;auto&quot; method.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_10->setText(QApplication::translate("Peditor", "URL", 0));
        label_11->setText(QApplication::translate("Peditor", "Servers", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_proxyservers->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Used when &quot;manual&quot; is set.List of proxy URIs.  The URI without a protocol will be interpreted as the generic proxy URI.</p><p>Enter one or more IP addresses. Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_12->setText(QApplication::translate("Peditor", "Excludes", 0));
#ifndef QT_NO_WHATSTHIS
        lineEdit_proxyexcludes->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Used when &quot;manual&quot; is set.  A list of hosts which can be accessed directly.</p><p><br/></p><p>Enter one or more IP addresses.  Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(proxy), QApplication::translate("Peditor", "&Proxy", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_whatsthis->setToolTip(QApplication::translate("Peditor", "<html><head/><body><p>What's This</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        toolButton_whatsthis->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_resetpage->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Clear all entries on the current page.</p><p>This button will reset every field on the current page to the default value, which generally means nothing in the field.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_resetpage->setText(QApplication::translate("Peditor", "Reset Pa&ge", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_resetall->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Clear all fields on every page of the dialog.</p><p>This will reset every field on every page to the default value for the field. </p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_resetall->setText(QApplication::translate("Peditor", "Reset &All", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_ok->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Accept the entries, send them to Connman, and close the dialog.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_ok->setText(QApplication::translate("Peditor", "OK", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_cancel->setWhatsThis(QApplication::translate("Peditor", "<html><head/><body><p>Close the dialog without sending any entries to Connman.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_cancel->setText(QApplication::translate("Peditor", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Peditor: public Ui_Peditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDITOR_H
