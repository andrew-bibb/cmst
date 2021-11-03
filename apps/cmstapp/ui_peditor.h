/********************************************************************************
** Form generated from reading UI file 'peditor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDITOR_H
#define UI_PEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QLabel *label_ipv4address;
    QLineEdit *lineEdit_ipv4gateway;
    QLabel *label_ipv4netmask;
    QLabel *label_ipv4gateway;
    QLineEdit *lineEdit_ipv4netmask;
    QComboBox *comboBox_ipv4method;
    QLabel *label_ipv4method;
    QSpacerItem *verticalSpacer;
    QWidget *ipv6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QComboBox *comboBox_ipv6method;
    QStackedWidget *stackedWidget_ipv601;
    QWidget *page;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_ipv6privacy;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6;
    QWidget *page_3;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QSpinBox *spinBox_ipv6prefixlength;
    QLineEdit *lineEdit_ipv6gateway;
    QLabel *label_7;
    QLineEdit *lineEdit_ipv6address;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_4;
    QLabel *label_ipv6method;
    QWidget *proxy;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_13;
    QComboBox *comboBox_proxymethod;
    QStackedWidget *stackedWidget_proxy01;
    QWidget *page_0;
    QWidget *page_1;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLineEdit *lineEdit_proxyurl;
    QSpacerItem *verticalSpacer_7;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLineEdit *lineEdit_proxyservers;
    QLabel *label_12;
    QLineEdit *lineEdit_proxyexcludes;
    QSpacerItem *verticalSpacer_6;
    QWidget *mDNS;
    QCheckBox *checkBox_mdns;
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
            Peditor->setObjectName(QString::fromUtf8("Peditor"));
        Peditor->resize(306, 484);
        Peditor->setSizeGripEnabled(true);
        Peditor->setModal(true);
        verticalLayout_3 = new QVBoxLayout(Peditor);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolBox_peditor = new QToolBox(Peditor);
        toolBox_peditor->setObjectName(QString::fromUtf8("toolBox_peditor"));
        general = new QWidget();
        general->setObjectName(QString::fromUtf8("general"));
        general->setGeometry(QRect(0, 0, 288, 163));
        verticalLayout_9 = new QVBoxLayout(general);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        checkBox_autoconnect = new QCheckBox(general);
        checkBox_autoconnect->setObjectName(QString::fromUtf8("checkBox_autoconnect"));

        verticalLayout_9->addWidget(checkBox_autoconnect);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);

        toolBox_peditor->addItem(general, QString::fromUtf8("&General"));
        nameservers = new QWidget();
        nameservers->setObjectName(QString::fromUtf8("nameservers"));
        nameservers->setGeometry(QRect(0, 0, 98, 47));
        verticalLayout_2 = new QVBoxLayout(nameservers);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_nameservers = new QLineEdit(nameservers);
        lineEdit_nameservers->setObjectName(QString::fromUtf8("lineEdit_nameservers"));
#if QT_CONFIG(whatsthis)
        lineEdit_nameservers->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)

        verticalLayout_2->addWidget(lineEdit_nameservers);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        toolBox_peditor->addItem(nameservers, QString::fromUtf8("&Nameservers"));
        timeservers = new QWidget();
        timeservers->setObjectName(QString::fromUtf8("timeservers"));
        timeservers->setGeometry(QRect(0, 0, 98, 47));
        verticalLayout_4 = new QVBoxLayout(timeservers);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_timeservers = new QLineEdit(timeservers);
        lineEdit_timeservers->setObjectName(QString::fromUtf8("lineEdit_timeservers"));
#if QT_CONFIG(whatsthis)
        lineEdit_timeservers->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)

        verticalLayout_4->addWidget(lineEdit_timeservers);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        toolBox_peditor->addItem(timeservers, QString::fromUtf8("&Timeservers"));
        domains = new QWidget();
        domains->setObjectName(QString::fromUtf8("domains"));
        domains->setGeometry(QRect(0, 0, 98, 47));
        verticalLayout_5 = new QVBoxLayout(domains);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lineEdit_domains = new QLineEdit(domains);
        lineEdit_domains->setObjectName(QString::fromUtf8("lineEdit_domains"));
#if QT_CONFIG(whatsthis)
        lineEdit_domains->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)

        verticalLayout_5->addWidget(lineEdit_domains);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);

        toolBox_peditor->addItem(domains, QString::fromUtf8("&Domains"));
        ipv4 = new QWidget();
        ipv4->setObjectName(QString::fromUtf8("ipv4"));
        ipv4->setGeometry(QRect(0, 0, 159, 136));
        verticalLayout = new QVBoxLayout(ipv4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_ipv4address = new QLineEdit(ipv4);
        lineEdit_ipv4address->setObjectName(QString::fromUtf8("lineEdit_ipv4address"));

        gridLayout_2->addWidget(lineEdit_ipv4address, 1, 1, 1, 1);

        label_ipv4address = new QLabel(ipv4);
        label_ipv4address->setObjectName(QString::fromUtf8("label_ipv4address"));

        gridLayout_2->addWidget(label_ipv4address, 1, 0, 1, 1);

        lineEdit_ipv4gateway = new QLineEdit(ipv4);
        lineEdit_ipv4gateway->setObjectName(QString::fromUtf8("lineEdit_ipv4gateway"));

        gridLayout_2->addWidget(lineEdit_ipv4gateway, 3, 1, 1, 1);

        label_ipv4netmask = new QLabel(ipv4);
        label_ipv4netmask->setObjectName(QString::fromUtf8("label_ipv4netmask"));

        gridLayout_2->addWidget(label_ipv4netmask, 2, 0, 1, 1);

        label_ipv4gateway = new QLabel(ipv4);
        label_ipv4gateway->setObjectName(QString::fromUtf8("label_ipv4gateway"));

        gridLayout_2->addWidget(label_ipv4gateway, 3, 0, 1, 1);

        lineEdit_ipv4netmask = new QLineEdit(ipv4);
        lineEdit_ipv4netmask->setObjectName(QString::fromUtf8("lineEdit_ipv4netmask"));

        gridLayout_2->addWidget(lineEdit_ipv4netmask, 2, 1, 1, 1);

        comboBox_ipv4method = new QComboBox(ipv4);
        comboBox_ipv4method->setObjectName(QString::fromUtf8("comboBox_ipv4method"));

        gridLayout_2->addWidget(comboBox_ipv4method, 0, 1, 1, 1);

        label_ipv4method = new QLabel(ipv4);
        label_ipv4method->setObjectName(QString::fromUtf8("label_ipv4method"));

        gridLayout_2->addWidget(label_ipv4method, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolBox_peditor->addItem(ipv4, QString::fromUtf8("IPv&4"));
        ipv6 = new QWidget();
        ipv6->setObjectName(QString::fromUtf8("ipv6"));
        ipv6->setGeometry(QRect(0, 0, 172, 155));
        gridLayout_5 = new QGridLayout(ipv6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_ipv6method = new QComboBox(ipv6);
        comboBox_ipv6method->setObjectName(QString::fromUtf8("comboBox_ipv6method"));

        gridLayout->addWidget(comboBox_ipv6method, 0, 1, 1, 1);

        stackedWidget_ipv601 = new QStackedWidget(ipv6);
        stackedWidget_ipv601->setObjectName(QString::fromUtf8("stackedWidget_ipv601"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_7 = new QGridLayout(page);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        comboBox_ipv6privacy = new QComboBox(page);
        comboBox_ipv6privacy->setObjectName(QString::fromUtf8("comboBox_ipv6privacy"));

        gridLayout_7->addWidget(comboBox_ipv6privacy, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 1, 0, 1, 2);

        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 0, 0, 1, 1);

        stackedWidget_ipv601->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_6 = new QGridLayout(page_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 2, 0, 1, 1);

        spinBox_ipv6prefixlength = new QSpinBox(page_3);
        spinBox_ipv6prefixlength->setObjectName(QString::fromUtf8("spinBox_ipv6prefixlength"));
        spinBox_ipv6prefixlength->setMaximum(255);

        gridLayout_6->addWidget(spinBox_ipv6prefixlength, 0, 1, 1, 1);

        lineEdit_ipv6gateway = new QLineEdit(page_3);
        lineEdit_ipv6gateway->setObjectName(QString::fromUtf8("lineEdit_ipv6gateway"));

        gridLayout_6->addWidget(lineEdit_ipv6gateway, 2, 1, 1, 1);

        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_ipv6address = new QLineEdit(page_3);
        lineEdit_ipv6address->setObjectName(QString::fromUtf8("lineEdit_ipv6address"));

        gridLayout_6->addWidget(lineEdit_ipv6address, 1, 1, 1, 1);

        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 3, 0, 1, 2);

        stackedWidget_ipv601->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_ipv601->addWidget(page_4);

        gridLayout->addWidget(stackedWidget_ipv601, 1, 0, 1, 2);

        label_ipv6method = new QLabel(ipv6);
        label_ipv6method->setObjectName(QString::fromUtf8("label_ipv6method"));

        gridLayout->addWidget(label_ipv6method, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        toolBox_peditor->addItem(ipv6, QString::fromUtf8("IPv&6"));
        proxy = new QWidget();
        proxy->setObjectName(QString::fromUtf8("proxy"));
        proxy->setGeometry(QRect(0, 0, 98, 28));
        layoutWidget = new QWidget(proxy);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 2, 281, 189));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 0, 0, 1, 1);

        comboBox_proxymethod = new QComboBox(layoutWidget);
        comboBox_proxymethod->setObjectName(QString::fromUtf8("comboBox_proxymethod"));

        gridLayout_4->addWidget(comboBox_proxymethod, 0, 1, 1, 1);

        stackedWidget_proxy01 = new QStackedWidget(layoutWidget);
        stackedWidget_proxy01->setObjectName(QString::fromUtf8("stackedWidget_proxy01"));
        page_0 = new QWidget();
        page_0->setObjectName(QString::fromUtf8("page_0"));
        stackedWidget_proxy01->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        gridLayout_3 = new QGridLayout(page_1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_10 = new QLabel(page_1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        lineEdit_proxyurl = new QLineEdit(page_1);
        lineEdit_proxyurl->setObjectName(QString::fromUtf8("lineEdit_proxyurl"));

        gridLayout_3->addWidget(lineEdit_proxyurl, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 1, 1, 1, 1);

        stackedWidget_proxy01->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_8 = new QVBoxLayout(page_2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_8->addWidget(label_11);

        lineEdit_proxyservers = new QLineEdit(page_2);
        lineEdit_proxyservers->setObjectName(QString::fromUtf8("lineEdit_proxyservers"));

        verticalLayout_8->addWidget(lineEdit_proxyservers);

        label_12 = new QLabel(page_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_8->addWidget(label_12);

        lineEdit_proxyexcludes = new QLineEdit(page_2);
        lineEdit_proxyexcludes->setObjectName(QString::fromUtf8("lineEdit_proxyexcludes"));

        verticalLayout_8->addWidget(lineEdit_proxyexcludes);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        stackedWidget_proxy01->addWidget(page_2);

        gridLayout_4->addWidget(stackedWidget_proxy01, 1, 0, 1, 2);

        toolBox_peditor->addItem(proxy, QString::fromUtf8("&Proxy"));
        mDNS = new QWidget();
        mDNS->setObjectName(QString::fromUtf8("mDNS"));
        mDNS->setGeometry(QRect(0, 0, 98, 28));
        checkBox_mdns = new QCheckBox(mDNS);
        checkBox_mdns->setObjectName(QString::fromUtf8("checkBox_mdns"));
        checkBox_mdns->setGeometry(QRect(10, 0, 281, 21));
        toolBox_peditor->addItem(mDNS, QString::fromUtf8("&mDNS"));

        verticalLayout_3->addWidget(toolBox_peditor);

        line = new QFrame(Peditor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_whatsthis = new QToolButton(Peditor);
        toolButton_whatsthis->setObjectName(QString::fromUtf8("toolButton_whatsthis"));

        horizontalLayout->addWidget(toolButton_whatsthis);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_resetpage = new QPushButton(Peditor);
        pushButton_resetpage->setObjectName(QString::fromUtf8("pushButton_resetpage"));

        horizontalLayout->addWidget(pushButton_resetpage);

        pushButton_resetall = new QPushButton(Peditor);
        pushButton_resetall->setObjectName(QString::fromUtf8("pushButton_resetall"));

        horizontalLayout->addWidget(pushButton_resetall);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(Peditor);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setEnabled(true);

        horizontalLayout_2->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(Peditor);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        verticalLayout_3->addLayout(horizontalLayout_2);

#if QT_CONFIG(shortcut)
        label_4->setBuddy(lineEdit_ipv6gateway);
        label_7->setBuddy(spinBox_ipv6prefixlength);
        label_5->setBuddy(lineEdit_ipv6address);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(checkBox_autoconnect, lineEdit_nameservers);
        QWidget::setTabOrder(lineEdit_nameservers, lineEdit_timeservers);
        QWidget::setTabOrder(lineEdit_timeservers, lineEdit_domains);
        QWidget::setTabOrder(lineEdit_domains, comboBox_ipv4method);
        QWidget::setTabOrder(comboBox_ipv4method, lineEdit_ipv4address);
        QWidget::setTabOrder(lineEdit_ipv4address, lineEdit_ipv4netmask);
        QWidget::setTabOrder(lineEdit_ipv4netmask, lineEdit_ipv4gateway);
        QWidget::setTabOrder(lineEdit_ipv4gateway, comboBox_ipv6method);
        QWidget::setTabOrder(comboBox_ipv6method, comboBox_ipv6privacy);
        QWidget::setTabOrder(comboBox_ipv6privacy, spinBox_ipv6prefixlength);
        QWidget::setTabOrder(spinBox_ipv6prefixlength, lineEdit_ipv6address);
        QWidget::setTabOrder(lineEdit_ipv6address, lineEdit_ipv6gateway);
        QWidget::setTabOrder(lineEdit_ipv6gateway, comboBox_proxymethod);
        QWidget::setTabOrder(comboBox_proxymethod, lineEdit_proxyurl);
        QWidget::setTabOrder(lineEdit_proxyurl, lineEdit_proxyservers);
        QWidget::setTabOrder(lineEdit_proxyservers, lineEdit_proxyexcludes);
        QWidget::setTabOrder(lineEdit_proxyexcludes, toolButton_whatsthis);
        QWidget::setTabOrder(toolButton_whatsthis, pushButton_resetpage);
        QWidget::setTabOrder(pushButton_resetpage, pushButton_resetall);
        QWidget::setTabOrder(pushButton_resetall, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_cancel);

        retranslateUi(Peditor);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), Peditor, SLOT(reject()));
        QObject::connect(comboBox_ipv6method, SIGNAL(currentIndexChanged(int)), stackedWidget_ipv601, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_proxymethod, SIGNAL(activated(int)), stackedWidget_proxy01, SLOT(setCurrentIndex(int)));

        stackedWidget_ipv601->setCurrentIndex(1);
        stackedWidget_proxy01->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Peditor);
    } // setupUi

    void retranslateUi(QDialog *Peditor)
    {
        Peditor->setWindowTitle(QCoreApplication::translate("Peditor", "Property Editor", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox_autoconnect->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>If checked this service will auto-connect when no other connection is available. This is only available for services marked &quot;Favorite&quot;. </p><p>The service will not auto-connect while roaming.</p></body></html>", "property editor"));
#endif // QT_CONFIG(whatsthis)
        checkBox_autoconnect->setText(QCoreApplication::translate("Peditor", "AutoConnect", nullptr));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(general), QCoreApplication::translate("Peditor", "&General", nullptr));
#if QT_CONFIG(whatsthis)
        nameservers->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The list of manually configured domain name servers. Some cellular networks don't provide correct name servers and this allows for an override.</p><p>This array is sorted by priority and the first entry in the list represents the nameserver with the highest priority.</p><p>When using manual configuration and no global nameservers are configured, then it is useful to configure this setting.</p><p>Enter one or more IP addresses. Separate each address you enter by a comma, semi-colon, vertical bar, or by white space.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(nameservers), QCoreApplication::translate("Peditor", "&Nameservers", nullptr));
#if QT_CONFIG(whatsthis)
        timeservers->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The list of manually configured time servers.</p><p>The first entry in the list represents the timeserver with the highest priority.</p><p>When using manual configuration this setting is useful to override all the other timeserver settings. This is service specific, hence only the values for the default service are used.</p><p>Changes to this property will result in restart of NTP query.</p><p>Enter one or more IP addresses. Separate each address you enter by a comma, semi-colon, vertical bar, or by white space.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(timeservers), QCoreApplication::translate("Peditor", "&Timeservers", nullptr));
#if QT_CONFIG(whatsthis)
        domains->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>List of manually configures search domains.</p><p>Enter one or more IP addresses. Separate each address you enter by a comma, semi-colon, vertical bar, or by white space.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(domains), QCoreApplication::translate("Peditor", "&Domains", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_ipv4address->setWhatsThis(QCoreApplication::translate("Peditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The IPv4 address to use for this connection.</p></body></html>", "property editor"));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        label_ipv4address->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv4 address to use for this connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_ipv4address->setText(QCoreApplication::translate("Peditor", "Address", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_ipv4gateway->setWhatsThis(QCoreApplication::translate("Peditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The IPv4 gateway for this connection. This field is optional and may be left blank</p></body></html>", "property editor"));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        label_ipv4netmask->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv4 netmask for this connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_ipv4netmask->setText(QCoreApplication::translate("Peditor", "Netmask", nullptr));
#if QT_CONFIG(whatsthis)
        label_ipv4gateway->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv4 gateway for this connection. This field is optional and may be left blank</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_ipv4gateway->setText(QCoreApplication::translate("Peditor", "Gateway", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_ipv4netmask->setWhatsThis(QCoreApplication::translate("Peditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The IPv4 netmask for this connection.</p></body></html>", "property editor"));
#endif // QT_CONFIG(whatsthis)
        comboBox_ipv4method->setCurrentText(QString());
#if QT_CONFIG(whatsthis)
        label_ipv4method->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Possible values of <span style=\" font-weight:600;\">dhcp</span>, <span style=\" font-weight:600;\">manual</span>, and <span style=\" font-weight:600;\">off</span>.</p><p>If <span style=\" font-weight:600;\">manual</span> is selected boxes for <span style=\" font-weight:600;\">Address</span>, <span style=\" font-weight:600;\">Netmask</span> and<span style=\" font-weight:600;\"> Gateway</span> will become visible.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_ipv4method->setText(QCoreApplication::translate("Peditor", "Method", nullptr));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(ipv4), QCoreApplication::translate("Peditor", "IPv&4", nullptr));
        comboBox_ipv6method->setCurrentText(QString());
#if QT_CONFIG(whatsthis)
        comboBox_ipv6privacy->setWhatsThis(QCoreApplication::translate("Peditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enable or disable the IPv6 privacy extension as described in RFC 4941,</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Disabled</span>: privacy extension is disabled and normal autoconf addresses are used.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Enabled</span>: the system prefers to use public addresses over temporary add"
                        "resses.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Prefered</span>: privacy extension is enabled and the system prefers temporary addresses over public addresses.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        comboBox_ipv6privacy->setCurrentText(QString());
#if QT_CONFIG(whatsthis)
        label_6->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Enable or disable the IPv6 privacy extension as described in RFC 4941,</p><p><span style=\" font-weight:600;\">Disabled</span>: privacy extension is disabled and normal autoconf addresses are used.</p><p><span style=\" font-weight:600;\">Enabled</span>: the system prefers to use public addresses over temporary addresses.</p><p><span style=\" font-weight:600;\">Prefered</span>: privacy extension is enabled and the system prefers temporary addresses over public addresses.</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_6->setText(QCoreApplication::translate("Peditor", "Privacy", nullptr));
#if QT_CONFIG(whatsthis)
        label_4->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv6 gateway for this connection. This field is optional and may be left blank</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_4->setText(QCoreApplication::translate("Peditor", "Gateway", nullptr));
#if QT_CONFIG(whatsthis)
        spinBox_ipv6prefixlength->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The prefix length of the IPv6 connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        lineEdit_ipv6gateway->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv6 gateway for this connection. This field is optional and may be left blank</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        label_7->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The prefix length of the IPv6 connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_7->setText(QCoreApplication::translate("Peditor", "Prefix Length", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_ipv6address->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv6 address to use for this connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_ipv6address->setText(QString());
#if QT_CONFIG(whatsthis)
        label_5->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>The IPv6 address to use for this connection.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_5->setText(QCoreApplication::translate("Peditor", "Address", nullptr));
#if QT_CONFIG(whatsthis)
        label_ipv6method->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Possible values are &quot;auto&quot;, &quot;manual&quot;,  and &quot;off&quot;</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_ipv6method->setText(QCoreApplication::translate("Peditor", "Method", nullptr));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(ipv6), QCoreApplication::translate("Peditor", "IPv&6", nullptr));
#if QT_CONFIG(whatsthis)
        proxy->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>User configuration of Proxy settings.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_13->setText(QCoreApplication::translate("Peditor", "Method", nullptr));
        comboBox_proxymethod->setCurrentText(QString());
        label_10->setText(QCoreApplication::translate("Peditor", "URL", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_proxyurl->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Automatic proxy configuration URL.  Used by the &quot;auto&quot; method.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_11->setText(QCoreApplication::translate("Peditor", "Servers", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_proxyservers->setWhatsThis(QCoreApplication::translate("Peditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Used when &quot;manual&quot; is set.List of proxy URIs. The URI without a protocol will be interpreted as the generic proxy URI.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter one or more IP addresses. Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", "property editor"));
#endif // QT_CONFIG(whatsthis)
        label_12->setText(QCoreApplication::translate("Peditor", "Excludes", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_proxyexcludes->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Used when &quot;manual&quot; is set.  A list of hosts which can be accessed directly.</p><p><br/></p><p>Enter one or more IP addresses.  Separate each address you enter by a comma, semi-colon, or by white space.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(proxy), QCoreApplication::translate("Peditor", "&Proxy", nullptr));
#if QT_CONFIG(whatsthis)
        mDNS->setWhatsThis(QCoreApplication::translate("Peditor", "Check to enable mDNS. Note that mDNS requires a DNS backend which supports it.\n"
"\n"
"", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        checkBox_mdns->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Check to enable mDNS.  Note that mDNS requires a DNS backend which supports it.</p><p><br/></p></body></html>", "property editor"));
#endif // QT_CONFIG(whatsthis)
        checkBox_mdns->setText(QCoreApplication::translate("Peditor", "Enable mDNS ", nullptr));
        toolBox_peditor->setItemText(toolBox_peditor->indexOf(mDNS), QCoreApplication::translate("Peditor", "&mDNS", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_whatsthis->setToolTip(QCoreApplication::translate("Peditor", "<html><head/><body><p>What's This</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_whatsthis->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_resetpage->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Clear all entries on the current page.</p><p>This button will reset every field on the current page to the default value, which generally means nothing in the field.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_resetpage->setText(QCoreApplication::translate("Peditor", "Reset Pa&ge", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_resetall->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Clear all fields on every page of the dialog.</p><p>This will reset every field on every page to the default value for the field. </p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_resetall->setText(QCoreApplication::translate("Peditor", "Reset &All", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_ok->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Accept the entries, send them to Connman, and close the dialog.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_ok->setText(QCoreApplication::translate("Peditor", "OK", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_cancel->setWhatsThis(QCoreApplication::translate("Peditor", "<html><head/><body><p>Close the dialog without sending any entries to Connman.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_cancel->setText(QCoreApplication::translate("Peditor", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Peditor: public Ui_Peditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDITOR_H
