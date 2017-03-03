/********************************************************************************
** Form generated from reading UI file 'ChipItem.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIPITEM_H
#define UI_CHIPITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChipItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetBase;
    QGridLayout *gridLayout;
    QWidget *widImgOper;
    QHBoxLayout *horizontalLayout;
    QPushButton *chkHideChip;
    QPushButton *chkLockAspect;
    QPushButton *chkLockPos;
    QPushButton *chkLockSize;
    QPushButton *chkLockAngle;
    QSpacerItem *horizontalSpacer;
    QPushButton *butMiddle;
    QPushButton *butScaleFull;
    QLabel *labChipIcon;
    QFrame *line;
    QLabel *labSourceName;

    void setupUi(QWidget *ChipItem)
    {
        if (ChipItem->objectName().isEmpty())
            ChipItem->setObjectName(QString::fromUtf8("ChipItem"));
        ChipItem->resize(200, 44);
        ChipItem->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#butMiddle{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/butMiddle.png);\n"
"}\n"
"QPushButton#butMiddle:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/butMiddle_H.png);\n"
"}\n"
"QPushButton#butMiddle:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/butMiddle_D.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#butScaleFull{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/butScaleFull.png);\n"
"}\n"
"QPushButton#butScaleFull:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/butScaleFull_H.png);\n"
"}\n"
"QPushButton#butScaleFull:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/butScaleFull_D.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#chkLockAspect{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAspect.png);\n"
"}\n"
"QPushButton#chkLockAspect:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAspect_H.png);\n"
"}\n"
"QPushButton#chkLockAspect:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAspect_D.png);\n"
""
                        "}\n"
"QPushButton#chkLockAspect:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAspect_C.png);\n"
"}\n"
"QPushButton#chkLockAspect:hover:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAspect_H_C.png);\n"
"}\n"
"QPushButton#chkLockAspect:disabled:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAspect_D_C.png);\n"
"}\n"
"\n"
"QPushButton#chkLockPos{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockPos.png);\n"
"}\n"
"QPushButton#chkLockPos:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockPos_H.png);\n"
"}\n"
"QPushButton#chkLockPos:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockPos_D.png);\n"
"}\n"
"QPushButton#chkLockPos:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockPos_C.png);\n"
"}\n"
"QPushButton#chkLockPos:hover:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockPos_H_C.png);\n"
"}\n"
"QPushButton#chkLockPos:disabled:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockPos_D_C.png)"
                        ";\n"
"}\n"
"\n"
"QPushButton#chkLockSize{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockSize.png);\n"
"}\n"
"QPushButton#chkLockSize:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockSize_H.png);\n"
"}\n"
"QPushButton#chkLockSize:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockSize_D.png);\n"
"}\n"
"QPushButton#chkLockSize:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockSize_C.png);\n"
"}\n"
"QPushButton#chkLockSize:hover:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockSize_H_C.png);\n"
"}\n"
"QPushButton#chkLockSize:disabled:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockSize_D_C.png);\n"
"}\n"
"\n"
"QPushButton#chkLockAngle{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAngle.png);\n"
"}\n"
"QPushButton#chkLockAngle:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAngle_H.png);\n"
"}\n"
"QPushButton#chkLockAngle:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAngle_D"
                        ".png);\n"
"}\n"
"QPushButton#chkLockAngle:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAngle_C.png);\n"
"}\n"
"QPushButton#chkLockAngle:hover:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAngle_H_C.png);\n"
"}\n"
"QPushButton#chkLockAngle:disabled:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkLockAngle_D_C.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#chkHideChip{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/chkHideChip.png);\n"
"}\n"
"QPushButton#chkHideChip:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/chkHideChip_H.png);\n"
"}\n"
"QPushButton#chkHideChip:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/chkHideChip_D.png);\n"
"}\n"
"QPushButton#chkHideChip:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkHideChip_C.png);\n"
"}\n"
"QPushButton#chkHideChip:hover:checked{\n"
"	border-image:url(:/Resources/ItemToolbar/chkHideChip_H_C.png);\n"
"}\n"
"QPushButton#chkHideChip:disabled:checked{\n"
"	border-image:url(:/Resources/ItemToolba"
                        "r/chkHideChip_D_C.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(ChipItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetBase = new QWidget(ChipItem);
        widgetBase->setObjectName(QString::fromUtf8("widgetBase"));
        widgetBase->setMinimumSize(QSize(0, 36));
        widgetBase->setMaximumSize(QSize(16777215, 36));
        gridLayout = new QGridLayout(widgetBase);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(2);
        widImgOper = new QWidget(widgetBase);
        widImgOper->setObjectName(QString::fromUtf8("widImgOper"));
        widImgOper->setEnabled(false);
        horizontalLayout = new QHBoxLayout(widImgOper);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chkHideChip = new QPushButton(widImgOper);
        chkHideChip->setObjectName(QString::fromUtf8("chkHideChip"));
        chkHideChip->setMinimumSize(QSize(16, 16));
        chkHideChip->setMaximumSize(QSize(16, 16));
        chkHideChip->setCheckable(true);

        horizontalLayout->addWidget(chkHideChip);

        chkLockAspect = new QPushButton(widImgOper);
        chkLockAspect->setObjectName(QString::fromUtf8("chkLockAspect"));
        chkLockAspect->setMinimumSize(QSize(16, 16));
        chkLockAspect->setMaximumSize(QSize(16, 16));
        chkLockAspect->setCheckable(true);

        horizontalLayout->addWidget(chkLockAspect);

        chkLockPos = new QPushButton(widImgOper);
        chkLockPos->setObjectName(QString::fromUtf8("chkLockPos"));
        chkLockPos->setMinimumSize(QSize(16, 16));
        chkLockPos->setMaximumSize(QSize(16, 16));
        chkLockPos->setCheckable(true);

        horizontalLayout->addWidget(chkLockPos);

        chkLockSize = new QPushButton(widImgOper);
        chkLockSize->setObjectName(QString::fromUtf8("chkLockSize"));
        chkLockSize->setMinimumSize(QSize(16, 16));
        chkLockSize->setMaximumSize(QSize(16, 16));
        chkLockSize->setCheckable(true);

        horizontalLayout->addWidget(chkLockSize);

        chkLockAngle = new QPushButton(widImgOper);
        chkLockAngle->setObjectName(QString::fromUtf8("chkLockAngle"));
        chkLockAngle->setMinimumSize(QSize(16, 16));
        chkLockAngle->setMaximumSize(QSize(16, 16));
        chkLockAngle->setCheckable(true);

        horizontalLayout->addWidget(chkLockAngle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        butMiddle = new QPushButton(widImgOper);
        butMiddle->setObjectName(QString::fromUtf8("butMiddle"));
        butMiddle->setMinimumSize(QSize(16, 16));
        butMiddle->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(butMiddle);

        butScaleFull = new QPushButton(widImgOper);
        butScaleFull->setObjectName(QString::fromUtf8("butScaleFull"));
        butScaleFull->setMinimumSize(QSize(16, 16));
        butScaleFull->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(butScaleFull);


        gridLayout->addWidget(widImgOper, 1, 2, 1, 1);

        labChipIcon = new QLabel(widgetBase);
        labChipIcon->setObjectName(QString::fromUtf8("labChipIcon"));
        labChipIcon->setMinimumSize(QSize(32, 32));
        labChipIcon->setMaximumSize(QSize(32, 32));

        gridLayout->addWidget(labChipIcon, 0, 0, 2, 1);

        line = new QFrame(widgetBase);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(line, 0, 1, 2, 1);

        labSourceName = new QLabel(widgetBase);
        labSourceName->setObjectName(QString::fromUtf8("labSourceName"));

        gridLayout->addWidget(labSourceName, 0, 2, 1, 1);


        verticalLayout->addWidget(widgetBase);


        retranslateUi(ChipItem);

        QMetaObject::connectSlotsByName(ChipItem);
    } // setupUi

    void retranslateUi(QWidget *ChipItem)
    {
        ChipItem->setWindowTitle(QApplication::translate("ChipItem", "ChipItem", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chkHideChip->setToolTip(QApplication::translate("ChipItem", "\346\230\276\347\244\272\343\200\201\351\232\220\350\227\217\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        chkLockAspect->setToolTip(QApplication::translate("ChipItem", "\351\224\201\345\256\232\345\233\276\345\203\217\347\274\251\346\224\276\347\232\204\345\256\275\351\253\230\346\257\224\344\276\213\357\274\214\344\273\245\345\233\276\345\203\217\347\232\204\345\216\237\345\247\213\345\210\206\350\276\250\347\216\207\344\270\272\345\237\272\345\207\206", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        chkLockPos->setToolTip(QApplication::translate("ChipItem", "\351\224\201\345\256\232\345\233\276\345\203\217\347\232\204\344\275\215\347\275\256\357\274\214\351\230\262\346\255\242\344\275\277\347\224\250\351\274\240\346\240\207\350\277\233\350\241\214\346\213\226\345\212\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        chkLockSize->setToolTip(QApplication::translate("ChipItem", "\351\224\201\345\256\232\345\233\276\345\203\217\347\232\204\345\244\247\345\260\217\357\274\214\351\230\262\346\255\242\344\275\277\347\224\250\351\274\240\346\240\207\346\213\226\346\213\275\345\233\276\345\203\217\350\276\271\347\274\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        chkLockAngle->setToolTip(QApplication::translate("ChipItem", "\351\224\201\345\256\232\345\233\276\345\203\217\347\232\204\346\227\213\350\275\254\350\247\222\345\272\246\357\274\214\351\230\262\346\255\242\346\214\211\344\270\213Ctrl\351\224\256\345\220\216\347\224\250\351\274\240\346\240\207\346\213\226\346\213\275\346\224\271\345\217\230\345\233\276\345\203\217\346\230\276\347\244\272\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        butMiddle->setToolTip(QApplication::translate("ChipItem", "\346\212\212\345\233\276\345\203\217\346\230\276\347\244\272\345\234\250\347\224\273\345\270\203\347\232\204\346\255\243\344\270\255", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        butScaleFull->setToolTip(QApplication::translate("ChipItem", "\346\212\212\345\233\276\345\203\217\351\223\272\346\273\241\346\225\264\344\270\252\347\224\273\345\270\203\357\274\214\345\246\202\346\236\234\345\233\276\345\203\217\347\232\204\346\257\224\344\276\213\345\222\214\347\224\273\345\270\203\344\270\215\345\220\214\357\274\214\345\260\206\344\274\232\345\210\207\346\215\242\351\223\272\346\273\241\347\232\204\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ChipItem: public Ui_ChipItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIPITEM_H
