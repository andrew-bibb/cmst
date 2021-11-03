/********************************************************************************
** Form generated from reading UI file 'scrollbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCROLLBOX_H
#define UI_SCROLLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScrollBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label_displaytext;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScrollBox)
    {
        if (ScrollBox->objectName().isEmpty())
            ScrollBox->setObjectName(QString::fromUtf8("ScrollBox"));
        ScrollBox->resize(397, 488);
        ScrollBox->setSizeGripEnabled(true);
        verticalLayout_2 = new QVBoxLayout(ScrollBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(ScrollBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 377, 440));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_displaytext = new QLabel(scrollAreaWidgetContents);
        label_displaytext->setObjectName(QString::fromUtf8("label_displaytext"));
        label_displaytext->setWordWrap(true);
        label_displaytext->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(label_displaytext);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(ScrollBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(ScrollBox);
        QObject::connect(buttonBox, SIGNAL(accepted()), ScrollBox, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ScrollBox, SLOT(reject()));

        QMetaObject::connectSlotsByName(ScrollBox);
    } // setupUi

    void retranslateUi(QDialog *ScrollBox)
    {
        ScrollBox->setWindowTitle(QCoreApplication::translate("ScrollBox", "Scrollbox", nullptr));
        label_displaytext->setText(QCoreApplication::translate("ScrollBox", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScrollBox: public Ui_ScrollBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCROLLBOX_H
