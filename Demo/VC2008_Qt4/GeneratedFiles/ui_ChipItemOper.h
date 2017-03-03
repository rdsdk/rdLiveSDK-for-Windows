/********************************************************************************
** Form generated from reading UI file 'ChipItemOper.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIPITEMOPER_H
#define UI_CHIPITEMOPER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "crangeslider.h"

QT_BEGIN_NAMESPACE

class Ui_ChipItemOper
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout;
    QWidget *widgetClip;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *butClip16_9;
    QPushButton *butClip9_16;
    QPushButton *butClip4_3;
    QPushButton *butClip3_4;
    QPushButton *butRestore;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    CRangeSlider *widClipLR;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    CRangeSlider *widClipTB;
    QSpacerItem *verticalSpacer;
    QWidget *tab_4;

    void setupUi(QWidget *ChipItemOper)
    {
        if (ChipItemOper->objectName().isEmpty())
            ChipItemOper->setObjectName(QString::fromUtf8("ChipItemOper"));
        ChipItemOper->resize(234, 112);
        ChipItemOper->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#butClip16_9{\n"
"	border: 1px solid #8f8f91;\n"
"	background-color: #dfefef;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton#butClip16_9:hover{\n"
"	border: 1px solid #9f9f91;\n"
"	background-color: #efefff;\n"
"}\n"
"QPushButton#butClip16_9:disabled{\n"
"	border: 1px solid #7f7f7f;\n"
"	background-color: #7f7f7f;\n"
"}\n"
"\n"
"QPushButton#butClip9_16{\n"
"	border: 1px solid #8f8f91;\n"
"	background-color: #dfefef;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton#butClip9_16:hover{\n"
"	border: 1px solid #9f9f91;\n"
"	background-color: #efefff;\n"
"}\n"
"QPushButton#butClip9_16:disabled{\n"
"	border: 1px solid #7f7f7f;\n"
"	background-color: #7f7f7f;\n"
"}\n"
"\n"
"QPushButton#butClip4_3{\n"
"	border: 1px solid #8f8f91;\n"
"	background-color: #dfefef;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton#butClip4_3:hover{\n"
"	border: 1px solid #9f9f91;\n"
"	background-color: #efefff;\n"
"}\n"
"QPushButton#butClip4_3:disabled{\n"
"	border: 1px solid #7f7f7f;\n"
"	background-color: #7f7f7f;\n"
"}\n"
"\n"
""
                        "QPushButton#butClip3_4{\n"
"	border: 1px solid #8f8f91;\n"
"	background-color: #dfefef;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton#butClip3_4:hover{\n"
"	border: 1px solid #9f9f91;\n"
"	background-color: #efefff;\n"
"}\n"
"QPushButton#butClip3_4:disabled{\n"
"	border: 1px solid #7f7f7f;\n"
"	background-color: #7f7f7f;\n"
"}\n"
"\n"
"QPushButton#butRestore{\n"
"	border: 1px solid #8f8f91;\n"
"	background-color: #dfefef;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton#butRestore:hover{\n"
"	border: 1px solid #9f9f91;\n"
"	background-color: #efefff;\n"
"}\n"
"QPushButton#butRestore:disabled{\n"
"	border: 1px solid #7f7f7f;\n"
"	background-color: #7f7f7f;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(ChipItemOper);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget = new QTabWidget(ChipItemOper);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout = new QVBoxLayout(tab_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetClip = new QWidget(tab_3);
        widgetClip->setObjectName(QString::fromUtf8("widgetClip"));
        widgetClip->setMinimumSize(QSize(0, 55));
        widgetClip->setMaximumSize(QSize(16777215, 55));
        verticalLayout_2 = new QVBoxLayout(widgetClip);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widgetClip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(40, 0));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        butClip16_9 = new QPushButton(widgetClip);
        butClip16_9->setObjectName(QString::fromUtf8("butClip16_9"));
        butClip16_9->setMinimumSize(QSize(32, 16));
        butClip16_9->setMaximumSize(QSize(32, 16));

        horizontalLayout_2->addWidget(butClip16_9);

        butClip9_16 = new QPushButton(widgetClip);
        butClip9_16->setObjectName(QString::fromUtf8("butClip9_16"));
        butClip9_16->setMinimumSize(QSize(32, 16));
        butClip9_16->setMaximumSize(QSize(32, 16));

        horizontalLayout_2->addWidget(butClip9_16);

        butClip4_3 = new QPushButton(widgetClip);
        butClip4_3->setObjectName(QString::fromUtf8("butClip4_3"));
        butClip4_3->setMinimumSize(QSize(24, 16));
        butClip4_3->setMaximumSize(QSize(24, 16));

        horizontalLayout_2->addWidget(butClip4_3);

        butClip3_4 = new QPushButton(widgetClip);
        butClip3_4->setObjectName(QString::fromUtf8("butClip3_4"));
        butClip3_4->setMinimumSize(QSize(24, 16));
        butClip3_4->setMaximumSize(QSize(24, 16));

        horizontalLayout_2->addWidget(butClip3_4);

        butRestore = new QPushButton(widgetClip);
        butRestore->setObjectName(QString::fromUtf8("butRestore"));
        butRestore->setMinimumSize(QSize(16, 16));
        butRestore->setMaximumSize(QSize(16, 16));

        horizontalLayout_2->addWidget(butRestore);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widgetClip);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        widClipLR = new CRangeSlider(widgetClip);
        widClipLR->setObjectName(QString::fromUtf8("widClipLR"));

        horizontalLayout_3->addWidget(widClipLR);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widgetClip);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(40, 0));
        label_5->setMaximumSize(QSize(40, 16777215));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_5);

        widClipTB = new CRangeSlider(widgetClip);
        widClipTB->setObjectName(QString::fromUtf8("widClipTB"));

        horizontalLayout_4->addWidget(widClipTB);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(widgetClip);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(tab_3, QString());
        widgetClip->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_4->addWidget(tabWidget);


        retranslateUi(ChipItemOper);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChipItemOper);
    } // setupUi

    void retranslateUi(QWidget *ChipItemOper)
    {
        ChipItemOper->setWindowTitle(QApplication::translate("ChipItemOper", "ChipItemOper", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChipItemOper", "\345\211\252\350\243\201\357\274\232", 0, QApplication::UnicodeUTF8));
        butClip16_9->setText(QApplication::translate("ChipItemOper", "16:9", 0, QApplication::UnicodeUTF8));
        butClip9_16->setText(QApplication::translate("ChipItemOper", "9:16", 0, QApplication::UnicodeUTF8));
        butClip4_3->setText(QApplication::translate("ChipItemOper", "4:3", 0, QApplication::UnicodeUTF8));
        butClip3_4->setText(QApplication::translate("ChipItemOper", "3:4", 0, QApplication::UnicodeUTF8));
        butRestore->setText(QApplication::translate("ChipItemOper", "R", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChipItemOper", "\345\267\246\345\217\263", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ChipItemOper", "\344\270\212\344\270\213", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ChipItemOper", "\345\237\272\346\234\254", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ChipItemOper", "\347\211\271\346\225\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChipItemOper: public Ui_ChipItemOper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIPITEMOPER_H
