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
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "crangeslider.h"

QT_BEGIN_NAMESPACE

class Ui_ChipItemOper
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tabPlay;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stkChipPlayType;
    QWidget *pageMovie;
    QVBoxLayout *verticalLayout_8;
    CRangeSlider *widPlayProgress;
    QStackedWidget *stkPlayControl;
    QWidget *stpPlayOper;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *butPlay;
    QPushButton *butPause;
    QPushButton *butStop;
    QSpacerItem *horizontalSpacer;
    QPushButton *chkMute;
    CRangeSlider *widPlayVolume;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *chkLoopPlay;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labPalyRangeTit;
    QLabel *labPalyRange;
    QPushButton *butSetPlayRange;
    QWidget *stpPlayRange;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QTimeEdit *tiePlayStart;
    QLabel *label_3;
    QTimeEdit *tiePlayEnd;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *chkPreviewRange;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *butUsePlayRange;
    QWidget *pageText;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QPushButton *butTexItalic;
    QPushButton *butTexBold;
    QPushButton *butTexSizeByWidth;
    QPushButton *butTexColor;
    QDoubleSpinBox *dspScrollCharPerSecond;
    QTextEdit *texInput;
    QWidget *pagePicList;
    QGridLayout *gridLayout_3;
    QListView *listView;
    QPushButton *butAddPicToList;
    QPushButton *butDelPicFromList;
    QWidget *tab_Image;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QWidget *widgetColor;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QSlider *hsSaturation;
    QLabel *label_6;
    QLabel *label_4;
    QSlider *hsHue;
    QLabel *label_8;
    QSlider *hsContrast;
    QSlider *hsLighteness;
    QLabel *label_9;
    QSlider *hsTransparency;
    QPushButton *chkFixedHue;
    QFrame *line;
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
    QFrame *line_2;
    QWidget *widgetRotate;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_13;
    QSlider *hsRotateX;
    QSlider *hsRotateY;
    QLabel *label_12;
    QSlider *hsRotateZ;
    QDoubleSpinBox *dspRotateX;
    QDoubleSpinBox *dspRotateY;
    QDoubleSpinBox *dspRotateZ;
    QSpacerItem *verticalSpacer;
    QWidget *tab_4;

    void setupUi(QWidget *ChipItemOper)
    {
        if (ChipItemOper->objectName().isEmpty())
            ChipItemOper->setObjectName(QString::fromUtf8("ChipItemOper"));
        ChipItemOper->resize(365, 135);
        ChipItemOper->setMinimumSize(QSize(0, 135));
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
"}\n"
"\n"
"\n"
"QPushButton#butPlay{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemOper/butPlay.png);\n"
"}\n"
"QPushButton#butPlay:hover{\n"
"	border-image:url(:/Resources/ItemOper/butPlay_H.png);\n"
"}\n"
"QPushButton#butPlay:disabled{\n"
"	border-image:url(:/Resources/ItemOper/butPlay_D.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#butPause{\n"
"	bord"
                        "er:none;\n"
"	border-image:url(:/Resources/ItemOper/butPause.png);\n"
"}\n"
"QPushButton#butPause:hover{\n"
"	border-image:url(:/Resources/ItemOper/butPause_H.png);\n"
"}\n"
"QPushButton#butPause:disabled{\n"
"	border-image:url(:/Resources/ItemOper/butPause_D.png);\n"
"}\n"
"\n"
"QPushButton#butUsePlayRange{\n"
"	border:none;\n"
"	color: blue;\n"
"}\n"
"QPushButton#butSetPlayRange{\n"
"	border:none;\n"
"	color: blue;\n"
"}\n"
"\n"
"QPushButton#butStop{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemOper/butStop.png);\n"
"}\n"
"QPushButton#butStop:hover{\n"
"	border-image:url(:/Resources/ItemOper/butStop_H.png);\n"
"}\n"
"QPushButton#butStop:disabled{\n"
"	border-image:url(:/Resources/ItemOper/butStop_D.png);\n"
"}\n"
"\n"
"QPushButton#chkMute{\n"
"	border:none;\n"
"	border-image:url(\":/Resources/ItemOper/chkSpeaker.png\");\n"
"}\n"
"QPushButton#chkMute:hover{\n"
"	border-image:url(\":/Resources/ItemOper/chkSpeaker_H.png\");\n"
"}\n"
"QPushButton#chkMute:disabled{\n"
"	border-image:url(\":/Resources/I"
                        "temOper/chkSpeaker_D.png\");\n"
"}\n"
"QPushButton#chkMute:checked{\n"
"	border:none;\n"
"	border-image:url(\":/Resources/ItemOper/chkSpeaker_C.png\");\n"
"}\n"
"QPushButton#chkMute:hover:checked{\n"
"	border-image:url(\":/Resources/ItemOper/chkSpeaker_H_C.png\");\n"
"}\n"
"QPushButton#chkMute:disabled:checked{\n"
"	border-image:url(\":/Resources/ItemOper/chkSpeaker_D_C.png\");\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(ChipItemOper);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget = new QTabWidget(ChipItemOper);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabPlay = new QWidget();
        tabPlay->setObjectName(QString::fromUtf8("tabPlay"));
        verticalLayout_3 = new QVBoxLayout(tabPlay);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 6, 4, 6);
        stkChipPlayType = new QStackedWidget(tabPlay);
        stkChipPlayType->setObjectName(QString::fromUtf8("stkChipPlayType"));
        pageMovie = new QWidget();
        pageMovie->setObjectName(QString::fromUtf8("pageMovie"));
        verticalLayout_8 = new QVBoxLayout(pageMovie);
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widPlayProgress = new CRangeSlider(pageMovie);
        widPlayProgress->setObjectName(QString::fromUtf8("widPlayProgress"));
        widPlayProgress->setMinimumSize(QSize(0, 14));
        widPlayProgress->setMaximumSize(QSize(16777215, 14));

        verticalLayout_8->addWidget(widPlayProgress);

        stkPlayControl = new QStackedWidget(pageMovie);
        stkPlayControl->setObjectName(QString::fromUtf8("stkPlayControl"));
        stpPlayOper = new QWidget();
        stpPlayOper->setObjectName(QString::fromUtf8("stpPlayOper"));
        verticalLayout_5 = new QVBoxLayout(stpPlayOper);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        butPlay = new QPushButton(stpPlayOper);
        butPlay->setObjectName(QString::fromUtf8("butPlay"));
        butPlay->setMinimumSize(QSize(16, 16));
        butPlay->setMaximumSize(QSize(16, 16));

        horizontalLayout_7->addWidget(butPlay);

        butPause = new QPushButton(stpPlayOper);
        butPause->setObjectName(QString::fromUtf8("butPause"));
        butPause->setEnabled(false);
        butPause->setMinimumSize(QSize(16, 16));
        butPause->setMaximumSize(QSize(16, 16));

        horizontalLayout_7->addWidget(butPause);

        butStop = new QPushButton(stpPlayOper);
        butStop->setObjectName(QString::fromUtf8("butStop"));
        butStop->setEnabled(false);
        butStop->setMinimumSize(QSize(16, 16));
        butStop->setMaximumSize(QSize(16, 16));

        horizontalLayout_7->addWidget(butStop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        chkMute = new QPushButton(stpPlayOper);
        chkMute->setObjectName(QString::fromUtf8("chkMute"));
        chkMute->setMinimumSize(QSize(16, 16));
        chkMute->setMaximumSize(QSize(16, 16));
        chkMute->setCheckable(true);
        chkMute->setChecked(false);

        horizontalLayout_7->addWidget(chkMute);

        widPlayVolume = new CRangeSlider(stpPlayOper);
        widPlayVolume->setObjectName(QString::fromUtf8("widPlayVolume"));
        widPlayVolume->setMinimumSize(QSize(50, 10));
        widPlayVolume->setMaximumSize(QSize(16777215, 10));

        horizontalLayout_7->addWidget(widPlayVolume);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        chkLoopPlay = new QCheckBox(stpPlayOper);
        chkLoopPlay->setObjectName(QString::fromUtf8("chkLoopPlay"));

        horizontalLayout_6->addWidget(chkLoopPlay);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        labPalyRangeTit = new QLabel(stpPlayOper);
        labPalyRangeTit->setObjectName(QString::fromUtf8("labPalyRangeTit"));

        horizontalLayout_6->addWidget(labPalyRangeTit);

        labPalyRange = new QLabel(stpPlayOper);
        labPalyRange->setObjectName(QString::fromUtf8("labPalyRange"));

        horizontalLayout_6->addWidget(labPalyRange);

        butSetPlayRange = new QPushButton(stpPlayOper);
        butSetPlayRange->setObjectName(QString::fromUtf8("butSetPlayRange"));
        butSetPlayRange->setMinimumSize(QSize(0, 16));
        butSetPlayRange->setMaximumSize(QSize(16777215, 16));
        QFont font;
        font.setUnderline(true);
        butSetPlayRange->setFont(font);

        horizontalLayout_6->addWidget(butSetPlayRange);


        verticalLayout_5->addLayout(horizontalLayout_6);

        stkPlayControl->addWidget(stpPlayOper);
        stpPlayRange = new QWidget();
        stpPlayRange->setObjectName(QString::fromUtf8("stpPlayRange"));
        verticalLayout_6 = new QVBoxLayout(stpPlayRange);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tiePlayStart = new QTimeEdit(stpPlayRange);
        tiePlayStart->setObjectName(QString::fromUtf8("tiePlayStart"));
        tiePlayStart->setMinimumTime(QTime(0, 0, 0));

        horizontalLayout_8->addWidget(tiePlayStart);

        label_3 = new QLabel(stpPlayRange);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        tiePlayEnd = new QTimeEdit(stpPlayRange);
        tiePlayEnd->setObjectName(QString::fromUtf8("tiePlayEnd"));
        tiePlayEnd->setMinimumTime(QTime(0, 0, 0));

        horizontalLayout_8->addWidget(tiePlayEnd);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        chkPreviewRange = new QCheckBox(stpPlayRange);
        chkPreviewRange->setObjectName(QString::fromUtf8("chkPreviewRange"));

        horizontalLayout_9->addWidget(chkPreviewRange);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        butUsePlayRange = new QPushButton(stpPlayRange);
        butUsePlayRange->setObjectName(QString::fromUtf8("butUsePlayRange"));
        butUsePlayRange->setMinimumSize(QSize(0, 16));
        butUsePlayRange->setMaximumSize(QSize(16777215, 16));
        butUsePlayRange->setFont(font);

        horizontalLayout_9->addWidget(butUsePlayRange);


        verticalLayout_6->addLayout(horizontalLayout_9);

        stkPlayControl->addWidget(stpPlayRange);

        verticalLayout_8->addWidget(stkPlayControl);

        stkChipPlayType->addWidget(pageMovie);
        pageText = new QWidget();
        pageText->setObjectName(QString::fromUtf8("pageText"));
        verticalLayout_9 = new QVBoxLayout(pageText);
        verticalLayout_9->setSpacing(2);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fontComboBox = new QFontComboBox(pageText);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setEditable(false);

        horizontalLayout->addWidget(fontComboBox);

        butTexItalic = new QPushButton(pageText);
        butTexItalic->setObjectName(QString::fromUtf8("butTexItalic"));
        butTexItalic->setMaximumSize(QSize(16, 16));
        QFont font1;
        font1.setItalic(true);
        butTexItalic->setFont(font1);
        butTexItalic->setCheckable(true);

        horizontalLayout->addWidget(butTexItalic);

        butTexBold = new QPushButton(pageText);
        butTexBold->setObjectName(QString::fromUtf8("butTexBold"));
        butTexBold->setMaximumSize(QSize(16, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        butTexBold->setFont(font2);
        butTexBold->setCheckable(true);

        horizontalLayout->addWidget(butTexBold);

        butTexSizeByWidth = new QPushButton(pageText);
        butTexSizeByWidth->setObjectName(QString::fromUtf8("butTexSizeByWidth"));
        butTexSizeByWidth->setMaximumSize(QSize(16, 16));
        butTexSizeByWidth->setCheckable(true);

        horizontalLayout->addWidget(butTexSizeByWidth);

        butTexColor = new QPushButton(pageText);
        butTexColor->setObjectName(QString::fromUtf8("butTexColor"));
        butTexColor->setMaximumSize(QSize(16, 16));
        butTexColor->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 255, 139);"));

        horizontalLayout->addWidget(butTexColor);

        dspScrollCharPerSecond = new QDoubleSpinBox(pageText);
        dspScrollCharPerSecond->setObjectName(QString::fromUtf8("dspScrollCharPerSecond"));
        dspScrollCharPerSecond->setDecimals(1);
        dspScrollCharPerSecond->setMaximum(9);
        dspScrollCharPerSecond->setSingleStep(0.2);

        horizontalLayout->addWidget(dspScrollCharPerSecond);


        verticalLayout_9->addLayout(horizontalLayout);

        texInput = new QTextEdit(pageText);
        texInput->setObjectName(QString::fromUtf8("texInput"));

        verticalLayout_9->addWidget(texInput);

        stkChipPlayType->addWidget(pageText);
        pagePicList = new QWidget();
        pagePicList->setObjectName(QString::fromUtf8("pagePicList"));
        gridLayout_3 = new QGridLayout(pagePicList);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        listView = new QListView(pagePicList);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout_3->addWidget(listView, 0, 0, 2, 1);

        butAddPicToList = new QPushButton(pagePicList);
        butAddPicToList->setObjectName(QString::fromUtf8("butAddPicToList"));

        gridLayout_3->addWidget(butAddPicToList, 0, 1, 1, 1);

        butDelPicFromList = new QPushButton(pagePicList);
        butDelPicFromList->setObjectName(QString::fromUtf8("butDelPicFromList"));

        gridLayout_3->addWidget(butDelPicFromList, 1, 1, 1, 1);

        stkChipPlayType->addWidget(pagePicList);

        verticalLayout_3->addWidget(stkChipPlayType);

        tabWidget->addTab(tabPlay, QString());
        tab_Image = new QWidget();
        tab_Image->setObjectName(QString::fromUtf8("tab_Image"));
        verticalLayout = new QVBoxLayout(tab_Image);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 6, 4, 6);
        scrollArea = new QScrollArea(tab_Image);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 334, 247));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setSpacing(4);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 4, 0);
        widgetColor = new QWidget(scrollAreaWidgetContents);
        widgetColor->setObjectName(QString::fromUtf8("widgetColor"));
        gridLayout = new QGridLayout(widgetColor);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(widgetColor);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        hsSaturation = new QSlider(widgetColor);
        hsSaturation->setObjectName(QString::fromUtf8("hsSaturation"));
        hsSaturation->setMaximumSize(QSize(16777215, 14));
        hsSaturation->setMinimum(-99);
        hsSaturation->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsSaturation, 1, 1, 1, 1);

        label_6 = new QLabel(widgetColor);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_4 = new QLabel(widgetColor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        hsHue = new QSlider(widgetColor);
        hsHue->setObjectName(QString::fromUtf8("hsHue"));
        hsHue->setMaximumSize(QSize(16777215, 14));
        hsHue->setMinimum(-99);
        hsHue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsHue, 0, 1, 1, 1);

        label_8 = new QLabel(widgetColor);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        hsContrast = new QSlider(widgetColor);
        hsContrast->setObjectName(QString::fromUtf8("hsContrast"));
        hsContrast->setMaximumSize(QSize(16777215, 14));
        hsContrast->setMinimum(-99);
        hsContrast->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsContrast, 3, 1, 1, 1);

        hsLighteness = new QSlider(widgetColor);
        hsLighteness->setObjectName(QString::fromUtf8("hsLighteness"));
        hsLighteness->setMaximumSize(QSize(16777215, 14));
        hsLighteness->setMinimum(-99);
        hsLighteness->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsLighteness, 2, 1, 1, 1);

        label_9 = new QLabel(widgetColor);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        hsTransparency = new QSlider(widgetColor);
        hsTransparency->setObjectName(QString::fromUtf8("hsTransparency"));
        hsTransparency->setMaximumSize(QSize(16777215, 14));
        hsTransparency->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsTransparency, 4, 1, 1, 1);

        chkFixedHue = new QPushButton(widgetColor);
        chkFixedHue->setObjectName(QString::fromUtf8("chkFixedHue"));
        chkFixedHue->setMaximumSize(QSize(16, 16));
        chkFixedHue->setCheckable(true);

        gridLayout->addWidget(chkFixedHue, 0, 2, 1, 1);


        verticalLayout_7->addWidget(widgetColor);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        widgetClip = new QWidget(scrollAreaWidgetContents);
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


        verticalLayout_7->addWidget(widgetClip);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        widgetRotate = new QWidget(scrollAreaWidgetContents);
        widgetRotate->setObjectName(QString::fromUtf8("widgetRotate"));
        gridLayout_2 = new QGridLayout(widgetRotate);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(4);
        gridLayout_2->setVerticalSpacing(2);
        label_11 = new QLabel(widgetRotate);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        label_10 = new QLabel(widgetRotate);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        label_13 = new QLabel(widgetRotate);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 3, 0, 1, 1);

        hsRotateX = new QSlider(widgetRotate);
        hsRotateX->setObjectName(QString::fromUtf8("hsRotateX"));
        hsRotateX->setMaximumSize(QSize(16777215, 14));
        hsRotateX->setMinimum(-180);
        hsRotateX->setMaximum(180);
        hsRotateX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(hsRotateX, 1, 1, 1, 1);

        hsRotateY = new QSlider(widgetRotate);
        hsRotateY->setObjectName(QString::fromUtf8("hsRotateY"));
        hsRotateY->setMaximumSize(QSize(16777215, 14));
        hsRotateY->setMinimum(-180);
        hsRotateY->setMaximum(180);
        hsRotateY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(hsRotateY, 2, 1, 1, 1);

        label_12 = new QLabel(widgetRotate);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 2, 0, 1, 1);

        hsRotateZ = new QSlider(widgetRotate);
        hsRotateZ->setObjectName(QString::fromUtf8("hsRotateZ"));
        hsRotateZ->setMaximumSize(QSize(16777215, 14));
        hsRotateZ->setMinimum(-180);
        hsRotateZ->setMaximum(180);
        hsRotateZ->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(hsRotateZ, 3, 1, 1, 1);

        dspRotateX = new QDoubleSpinBox(widgetRotate);
        dspRotateX->setObjectName(QString::fromUtf8("dspRotateX"));
        dspRotateX->setDecimals(1);
        dspRotateX->setMinimum(-180);
        dspRotateX->setMaximum(180);

        gridLayout_2->addWidget(dspRotateX, 1, 2, 1, 1);

        dspRotateY = new QDoubleSpinBox(widgetRotate);
        dspRotateY->setObjectName(QString::fromUtf8("dspRotateY"));
        dspRotateY->setDecimals(1);
        dspRotateY->setMinimum(-180);
        dspRotateY->setMaximum(180);

        gridLayout_2->addWidget(dspRotateY, 2, 2, 1, 1);

        dspRotateZ = new QDoubleSpinBox(widgetRotate);
        dspRotateZ->setObjectName(QString::fromUtf8("dspRotateZ"));
        dspRotateZ->setDecimals(1);
        dspRotateZ->setMinimum(-180);
        dspRotateZ->setMaximum(180);

        gridLayout_2->addWidget(dspRotateZ, 3, 2, 1, 1);


        verticalLayout_7->addWidget(widgetRotate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        tabWidget->addTab(tab_Image, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_4->addWidget(tabWidget);


        retranslateUi(ChipItemOper);

        tabWidget->setCurrentIndex(0);
        stkChipPlayType->setCurrentIndex(0);
        stkPlayControl->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ChipItemOper);
    } // setupUi

    void retranslateUi(QWidget *ChipItemOper)
    {
        ChipItemOper->setWindowTitle(QApplication::translate("ChipItemOper", "ChipItemOper", 0, QApplication::UnicodeUTF8));
        chkLoopPlay->setText(QApplication::translate("ChipItemOper", "\345\276\252\347\216\257\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        labPalyRangeTit->setText(QApplication::translate("ChipItemOper", "\346\222\255\346\224\276\350\214\203\345\233\264\357\274\232", 0, QApplication::UnicodeUTF8));
        labPalyRange->setText(QApplication::translate("ChipItemOper", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        butSetPlayRange->setText(QApplication::translate("ChipItemOper", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tiePlayStart->setDisplayFormat(QApplication::translate("ChipItemOper", "H:mm:ss.zzz", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChipItemOper", "\350\207\263", 0, QApplication::UnicodeUTF8));
        tiePlayEnd->setDisplayFormat(QApplication::translate("ChipItemOper", "H:mm:ss.zzz", 0, QApplication::UnicodeUTF8));
        chkPreviewRange->setText(QApplication::translate("ChipItemOper", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        butUsePlayRange->setText(QApplication::translate("ChipItemOper", "\345\272\224\347\224\250\346\222\255\346\224\276\350\214\203\345\233\264", 0, QApplication::UnicodeUTF8));
        butTexItalic->setText(QApplication::translate("ChipItemOper", "I", 0, QApplication::UnicodeUTF8));
        butTexBold->setText(QApplication::translate("ChipItemOper", "B", 0, QApplication::UnicodeUTF8));
        butTexSizeByWidth->setText(QApplication::translate("ChipItemOper", "H", 0, QApplication::UnicodeUTF8));
        butTexColor->setText(QApplication::translate("ChipItemOper", "C", 0, QApplication::UnicodeUTF8));
        butAddPicToList->setText(QApplication::translate("ChipItemOper", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        butDelPicFromList->setText(QApplication::translate("ChipItemOper", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPlay), QApplication::translate("ChipItemOper", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ChipItemOper", "\344\272\256\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ChipItemOper", "\346\265\223\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ChipItemOper", "\351\242\234\350\211\262\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ChipItemOper", "\345\257\271\346\257\224\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ChipItemOper", "\351\200\217\346\230\216\357\274\232", 0, QApplication::UnicodeUTF8));
        chkFixedHue->setText(QApplication::translate("ChipItemOper", "S", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChipItemOper", "\345\211\252\350\243\201\357\274\232", 0, QApplication::UnicodeUTF8));
        butClip16_9->setText(QApplication::translate("ChipItemOper", "16:9", 0, QApplication::UnicodeUTF8));
        butClip9_16->setText(QApplication::translate("ChipItemOper", "9:16", 0, QApplication::UnicodeUTF8));
        butClip4_3->setText(QApplication::translate("ChipItemOper", "4:3", 0, QApplication::UnicodeUTF8));
        butClip3_4->setText(QApplication::translate("ChipItemOper", "3:4", 0, QApplication::UnicodeUTF8));
        butRestore->setText(QApplication::translate("ChipItemOper", "R", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChipItemOper", "\345\267\246\345\217\263", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ChipItemOper", "\344\270\212\344\270\213", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ChipItemOper", "X \350\275\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ChipItemOper", "\346\227\213\350\275\254", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ChipItemOper", "Z \350\275\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ChipItemOper", "Y \350\275\264\357\274\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Image), QApplication::translate("ChipItemOper", "\345\237\272\346\234\254", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ChipItemOper", "\347\211\271\346\225\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChipItemOper: public Ui_ChipItemOper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIPITEMOPER_H
