/********************************************************************************
** Form generated from reading UI file 'scrollbox.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCROLLBOX_H
#define UI_SCROLLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
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
            ScrollBox->setObjectName(QStringLiteral("ScrollBox"));
        ScrollBox->resize(397, 488);
        ScrollBox->setSizeGripEnabled(true);
        verticalLayout_2 = new QVBoxLayout(ScrollBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(ScrollBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 377, 440));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_displaytext = new QLabel(scrollAreaWidgetContents);
        label_displaytext->setObjectName(QStringLiteral("label_displaytext"));
        label_displaytext->setWordWrap(true);
        label_displaytext->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(label_displaytext);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(ScrollBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        ScrollBox->setWindowTitle(QApplication::translate("ScrollBox", "Scrollbox", 0));
        label_displaytext->setText(QApplication::translate("ScrollBox", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ScrollBox: public Ui_ScrollBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCROLLBOX_H
