/********************************************************************************
** Form generated from reading UI file 'RdLiveSdkDemo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RDLIVESDKDEMO_H
#define UI_RDLIVESDKDEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "cpreviewwnd.h"
#include "crangeslider.h"
#include "dlgencodersetting.h"

QT_BEGIN_NAMESPACE

class Ui_RDLiveSdkDemoClass
{
public:
    QAction *actAddScene;
    QAction *actBSceneCount0;
    QAction *actBSceneCount2;
    QAction *actBSceneCount4;
    QAction *actBSceneCount6;
    QAction *actBSceneCount8;
    QAction *actShowScrollBar;
    QAction *actShowAddScene;
    QAction *actShowCurrOnBack;
    QAction *actShowSceneName;
    QAction *actBSceneScale;
    QAction *actClearCurScene;
    QAction *actBSceneUp;
    QAction *actBSceneDown;
    QAction *actBSceneLeft;
    QAction *actBSceneRight;
    QAction *actRestorePreview;
    QAction *actSwapVH;
    QAction *actPreviewOpenGL;
    QAction *actiAddPicture;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    CPreviewWnd *widPreview;
    QWidget *widControl;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widVolumeOperOut_3;
    QGridLayout *gridLayout_9;
    QWidget *widVolumeOperOut_4;
    QGridLayout *gridLayout_10;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *chkStart;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widVolumeOperSpk;
    QGridLayout *gridLayout_7;
    QPushButton *chkSpeaker;
    QPushButton *butAudioPopSpk;
    CRangeSlider *widVolumeSpk;
    QWidget *widVolumeOperMic;
    QGridLayout *gridLayout_8;
    QPushButton *chkMicrophone;
    QPushButton *butAudioPopMic;
    CRangeSlider *widVolumeMic;
    QSpacerItem *horizontalSpacer_4;
    QTabWidget *tabSector;
    QWidget *tabCurrScene;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *butAddChip;
    QSpacerItem *horizontalSpacer;
    QPushButton *butUpChip;
    QPushButton *butDownChip;
    QPushButton *butCloseChip;
    QListWidget *listWidChips;
    QWidget *tabSetting;
    QVBoxLayout *verticalLayout_3;
    DlgEncoderSetting *widEncoderSetting;
    QMenuBar *menuBar;
    QMenu *menuChipInput;
    QMenu *menuAddScreen;
    QMenu *menuAddCamera;
    QMenu *menuScene;
    QMenu *menuDeleteScene;
    QMenu *menuSwitchScene;
    QMenu *menuPreviewLayout;
    QMenu *menuBScenePos;
    QMenu *menuRenameScene;
    QMenu *menuImage;
    QMenu *menuFpses;
    QMenu *menuPreviewScale;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RDLiveSdkDemoClass)
    {
        if (RDLiveSdkDemoClass->objectName().isEmpty())
            RDLiveSdkDemoClass->setObjectName(QString::fromUtf8("RDLiveSdkDemoClass"));
        RDLiveSdkDemoClass->resize(684, 574);
        RDLiveSdkDemoClass->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#butCloseChip{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/butCloseChip.png);\n"
"}\n"
"QPushButton#butCloseChip:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/butCloseChip_H.png);\n"
"}\n"
"QPushButton#butCloseChip:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/butCloseChip_D.png);\n"
"}\n"
"\n"
"QPushButton#butUpChip{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/butUpChip.png);\n"
"}\n"
"QPushButton#butUpChip:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/butUpChip_H.png);\n"
"}\n"
"QPushButton#butUpChip:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/butUpChip_D.png);\n"
"}\n"
"\n"
"QPushButton#butDownChip{\n"
"	border:none;\n"
"	border-image:url(:/Resources/ItemToolbar/butDownChip.png);\n"
"}\n"
"QPushButton#butDownChip:hover{\n"
"	border-image:url(:/Resources/ItemToolbar/butDownChip_H.png);\n"
"}\n"
"QPushButton#butDownChip:disabled{\n"
"	border-image:url(:/Resources/ItemToolbar/butDownChip_D.png);\n"
"}\n"
"\n"
"QPushButt"
                        "on#chkSpeaker{\n"
"	border:none;\n"
"	border-image:url(:/Resources/chkSpeaker.png);\n"
"}\n"
"QPushButton#chkSpeaker:hover{\n"
"	border-image:url(:/Resources/chkSpeaker_H.png);\n"
"}\n"
"QPushButton#chkSpeaker:disabled{\n"
"	border-image:url(:/Resources/chkSpeaker_D.png);\n"
"}\n"
"QPushButton#chkSpeaker:checked{\n"
"	border-image:url(:/Resources/chkSpeaker_C.png);\n"
"}\n"
"QPushButton#chkSpeaker:hover:checked{\n"
"	border-image:url(:/Resources/chkSpeaker_H_C.png);\n"
"}\n"
"QPushButton#chkSpeaker:disabled:checked{\n"
"	border-image:url(:/Resources/chkSpeaker_D_C.png);\n"
"}\n"
"\n"
"QPushButton#chkMicrophone{\n"
"	border:none;\n"
"	border-image:url(:/Resources/chkMicrophone.png);\n"
"}\n"
"QPushButton#chkMicrophone:hover{\n"
"	border-image:url(:/Resources/chkMicrophone_H.png);\n"
"}\n"
"QPushButton#chkMicrophone:disabled{\n"
"	border-image:url(:/Resources/chkMicrophone_D.png);\n"
"}\n"
"QPushButton#chkMicrophone:checked{\n"
"	border-image:url(:/Resources/chkMicrophone_C.png);\n"
"}\n"
"QPushButton#chkMicroph"
                        "one:hover:checked{\n"
"	border-image:url(:/Resources/chkMicrophone_H_C.png);\n"
"}\n"
"QPushButton#chkMicrophone:disabled:checked{\n"
"	border-image:url(:/Resources/chkMicrophone_D_C.png);\n"
"}\n"
"\n"
"QPushButton#butAudioPopSpk{\n"
"	border:none;\n"
"	border-image:url(:/Resources/butAudioPopup.png);\n"
"}\n"
"QPushButton#butAudioPopSpk:hover{\n"
"	border-image:url(:/Resources/butAudioPopup_H.png);\n"
"}\n"
"QPushButton#butAudioPopSpk:disabled{\n"
"	border-image:url(:/Resources/butAudioPopup_D.png);\n"
"}\n"
"\n"
"QPushButton#butAudioPopMic{\n"
"	border:none;\n"
"	border-image:url(:/Resources/butAudioPopup.png);\n"
"}\n"
"QPushButton#butAudioPopMic:hover{\n"
"	border-image:url(:/Resources/butAudioPopup_H.png);\n"
"}\n"
"QPushButton#butAudioPopMic:disabled{\n"
"	border-image:url(:/Resources/butAudioPopup_D.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#chkStart{\n"
"	border:none;\n"
"	border-image:url(:/Resources/chkStart.png);\n"
"}\n"
"QPushButton#chkStart:hover{\n"
"	border-image:url(:/Resources/chkStart_H.png);\n"
""
                        "}\n"
"QPushButton#chkStart:disabled{\n"
"	border-image:url(:/Resources/chkStart_D.png);\n"
"}\n"
"QPushButton#chkStart:checked{\n"
"	border-image:url(:/Resources/chkStart_C.png);\n"
"}\n"
"QPushButton#chkStart:hover:checked{\n"
"	border-image:url(:/Resources/chkStart_H_C.png);\n"
"}\n"
"QPushButton#chkStart:disabled:checked{\n"
"	border-image:url(:/Resources/chkStart_D_C.png);\n"
"}\n"
"\n"
""));
        actAddScene = new QAction(RDLiveSdkDemoClass);
        actAddScene->setObjectName(QString::fromUtf8("actAddScene"));
        actBSceneCount0 = new QAction(RDLiveSdkDemoClass);
        actBSceneCount0->setObjectName(QString::fromUtf8("actBSceneCount0"));
        actBSceneCount0->setCheckable(true);
        actBSceneCount2 = new QAction(RDLiveSdkDemoClass);
        actBSceneCount2->setObjectName(QString::fromUtf8("actBSceneCount2"));
        actBSceneCount2->setCheckable(true);
        actBSceneCount4 = new QAction(RDLiveSdkDemoClass);
        actBSceneCount4->setObjectName(QString::fromUtf8("actBSceneCount4"));
        actBSceneCount4->setCheckable(true);
        actBSceneCount6 = new QAction(RDLiveSdkDemoClass);
        actBSceneCount6->setObjectName(QString::fromUtf8("actBSceneCount6"));
        actBSceneCount6->setCheckable(true);
        actBSceneCount8 = new QAction(RDLiveSdkDemoClass);
        actBSceneCount8->setObjectName(QString::fromUtf8("actBSceneCount8"));
        actBSceneCount8->setCheckable(true);
        actShowScrollBar = new QAction(RDLiveSdkDemoClass);
        actShowScrollBar->setObjectName(QString::fromUtf8("actShowScrollBar"));
        actShowScrollBar->setCheckable(true);
        actShowAddScene = new QAction(RDLiveSdkDemoClass);
        actShowAddScene->setObjectName(QString::fromUtf8("actShowAddScene"));
        actShowAddScene->setCheckable(true);
        actShowCurrOnBack = new QAction(RDLiveSdkDemoClass);
        actShowCurrOnBack->setObjectName(QString::fromUtf8("actShowCurrOnBack"));
        actShowCurrOnBack->setCheckable(true);
        actShowSceneName = new QAction(RDLiveSdkDemoClass);
        actShowSceneName->setObjectName(QString::fromUtf8("actShowSceneName"));
        actShowSceneName->setCheckable(true);
        actBSceneScale = new QAction(RDLiveSdkDemoClass);
        actBSceneScale->setObjectName(QString::fromUtf8("actBSceneScale"));
        actBSceneScale->setCheckable(true);
        actClearCurScene = new QAction(RDLiveSdkDemoClass);
        actClearCurScene->setObjectName(QString::fromUtf8("actClearCurScene"));
        actBSceneUp = new QAction(RDLiveSdkDemoClass);
        actBSceneUp->setObjectName(QString::fromUtf8("actBSceneUp"));
        actBSceneUp->setCheckable(true);
        actBSceneDown = new QAction(RDLiveSdkDemoClass);
        actBSceneDown->setObjectName(QString::fromUtf8("actBSceneDown"));
        actBSceneDown->setCheckable(true);
        actBSceneLeft = new QAction(RDLiveSdkDemoClass);
        actBSceneLeft->setObjectName(QString::fromUtf8("actBSceneLeft"));
        actBSceneLeft->setCheckable(true);
        actBSceneRight = new QAction(RDLiveSdkDemoClass);
        actBSceneRight->setObjectName(QString::fromUtf8("actBSceneRight"));
        actBSceneRight->setCheckable(true);
        actRestorePreview = new QAction(RDLiveSdkDemoClass);
        actRestorePreview->setObjectName(QString::fromUtf8("actRestorePreview"));
        actSwapVH = new QAction(RDLiveSdkDemoClass);
        actSwapVH->setObjectName(QString::fromUtf8("actSwapVH"));
        actSwapVH->setCheckable(true);
        actPreviewOpenGL = new QAction(RDLiveSdkDemoClass);
        actPreviewOpenGL->setObjectName(QString::fromUtf8("actPreviewOpenGL"));
        actPreviewOpenGL->setCheckable(true);
        actiAddPicture = new QAction(RDLiveSdkDemoClass);
        actiAddPicture->setObjectName(QString::fromUtf8("actiAddPicture"));
        centralWidget = new QWidget(RDLiveSdkDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widPreview = new CPreviewWnd(centralWidget);
        widPreview->setObjectName(QString::fromUtf8("widPreview"));
        widPreview->setMinimumSize(QSize(176, 144));
        widPreview->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 127);"));

        gridLayout->addWidget(widPreview, 0, 0, 1, 1);

        widControl = new QWidget(centralWidget);
        widControl->setObjectName(QString::fromUtf8("widControl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widControl->sizePolicy().hasHeightForWidth());
        widControl->setSizePolicy(sizePolicy);
        widControl->setMinimumSize(QSize(0, 32));
        widControl->setMaximumSize(QSize(16777215, 32));
        widControl->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(widControl);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 0, 6, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        widVolumeOperOut_3 = new QWidget(widControl);
        widVolumeOperOut_3->setObjectName(QString::fromUtf8("widVolumeOperOut_3"));
        widVolumeOperOut_3->setMinimumSize(QSize(32, 16));
        widVolumeOperOut_3->setMaximumSize(QSize(32, 16));
        gridLayout_9 = new QGridLayout(widVolumeOperOut_3);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));

        horizontalLayout_3->addWidget(widVolumeOperOut_3);

        widVolumeOperOut_4 = new QWidget(widControl);
        widVolumeOperOut_4->setObjectName(QString::fromUtf8("widVolumeOperOut_4"));
        widVolumeOperOut_4->setMinimumSize(QSize(32, 16));
        widVolumeOperOut_4->setMaximumSize(QSize(32, 16));
        gridLayout_10 = new QGridLayout(widVolumeOperOut_4);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));

        horizontalLayout_3->addWidget(widVolumeOperOut_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        chkStart = new QPushButton(widControl);
        chkStart->setObjectName(QString::fromUtf8("chkStart"));
        chkStart->setMinimumSize(QSize(32, 32));
        chkStart->setMaximumSize(QSize(32, 32));
        chkStart->setCheckable(true);

        horizontalLayout_3->addWidget(chkStart);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        widVolumeOperSpk = new QWidget(widControl);
        widVolumeOperSpk->setObjectName(QString::fromUtf8("widVolumeOperSpk"));
        widVolumeOperSpk->setMinimumSize(QSize(32, 24));
        widVolumeOperSpk->setMaximumSize(QSize(32, 24));
        gridLayout_7 = new QGridLayout(widVolumeOperSpk);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(0);
        gridLayout_7->setVerticalSpacing(1);
        chkSpeaker = new QPushButton(widVolumeOperSpk);
        chkSpeaker->setObjectName(QString::fromUtf8("chkSpeaker"));
        chkSpeaker->setMinimumSize(QSize(16, 16));
        chkSpeaker->setMaximumSize(QSize(16, 16));
        chkSpeaker->setCheckable(true);

        gridLayout_7->addWidget(chkSpeaker, 0, 0, 1, 1);

        butAudioPopSpk = new QPushButton(widVolumeOperSpk);
        butAudioPopSpk->setObjectName(QString::fromUtf8("butAudioPopSpk"));
        butAudioPopSpk->setMinimumSize(QSize(13, 9));
        butAudioPopSpk->setMaximumSize(QSize(13, 9));
        butAudioPopSpk->setCheckable(true);

        gridLayout_7->addWidget(butAudioPopSpk, 0, 1, 1, 1);

        widVolumeSpk = new CRangeSlider(widVolumeOperSpk);
        widVolumeSpk->setObjectName(QString::fromUtf8("widVolumeSpk"));
        widVolumeSpk->setMinimumSize(QSize(32, 7));
        widVolumeSpk->setMaximumSize(QSize(32, 7));

        gridLayout_7->addWidget(widVolumeSpk, 1, 0, 1, 2);


        horizontalLayout_3->addWidget(widVolumeOperSpk);

        widVolumeOperMic = new QWidget(widControl);
        widVolumeOperMic->setObjectName(QString::fromUtf8("widVolumeOperMic"));
        widVolumeOperMic->setMinimumSize(QSize(32, 24));
        widVolumeOperMic->setMaximumSize(QSize(32, 24));
        gridLayout_8 = new QGridLayout(widVolumeOperMic);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(0);
        gridLayout_8->setVerticalSpacing(1);
        chkMicrophone = new QPushButton(widVolumeOperMic);
        chkMicrophone->setObjectName(QString::fromUtf8("chkMicrophone"));
        chkMicrophone->setMinimumSize(QSize(16, 16));
        chkMicrophone->setMaximumSize(QSize(16, 16));
        chkMicrophone->setCheckable(true);

        gridLayout_8->addWidget(chkMicrophone, 0, 0, 1, 1);

        butAudioPopMic = new QPushButton(widVolumeOperMic);
        butAudioPopMic->setObjectName(QString::fromUtf8("butAudioPopMic"));
        butAudioPopMic->setMinimumSize(QSize(13, 9));
        butAudioPopMic->setMaximumSize(QSize(13, 9));
        butAudioPopMic->setCheckable(true);

        gridLayout_8->addWidget(butAudioPopMic, 0, 1, 1, 1);

        widVolumeMic = new CRangeSlider(widVolumeOperMic);
        widVolumeMic->setObjectName(QString::fromUtf8("widVolumeMic"));
        widVolumeMic->setMinimumSize(QSize(32, 7));
        widVolumeMic->setMaximumSize(QSize(32, 7));

        gridLayout_8->addWidget(widVolumeMic, 1, 0, 1, 2);


        horizontalLayout_3->addWidget(widVolumeOperMic);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widControl, 1, 0, 1, 1);

        tabSector = new QTabWidget(centralWidget);
        tabSector->setObjectName(QString::fromUtf8("tabSector"));
        tabSector->setMinimumSize(QSize(250, 0));
        tabSector->setMaximumSize(QSize(250, 16777215));
        tabCurrScene = new QWidget();
        tabCurrScene->setObjectName(QString::fromUtf8("tabCurrScene"));
        verticalLayout = new QVBoxLayout(tabCurrScene);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        butAddChip = new QPushButton(tabCurrScene);
        butAddChip->setObjectName(QString::fromUtf8("butAddChip"));

        horizontalLayout->addWidget(butAddChip);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        butUpChip = new QPushButton(tabCurrScene);
        butUpChip->setObjectName(QString::fromUtf8("butUpChip"));
        butUpChip->setMinimumSize(QSize(16, 16));
        butUpChip->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(butUpChip);

        butDownChip = new QPushButton(tabCurrScene);
        butDownChip->setObjectName(QString::fromUtf8("butDownChip"));
        butDownChip->setMinimumSize(QSize(16, 16));
        butDownChip->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(butDownChip);

        butCloseChip = new QPushButton(tabCurrScene);
        butCloseChip->setObjectName(QString::fromUtf8("butCloseChip"));
        butCloseChip->setMinimumSize(QSize(16, 16));
        butCloseChip->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(butCloseChip);


        verticalLayout->addLayout(horizontalLayout);

        listWidChips = new QListWidget(tabCurrScene);
        listWidChips->setObjectName(QString::fromUtf8("listWidChips"));

        verticalLayout->addWidget(listWidChips);

        tabSector->addTab(tabCurrScene, QString());
        tabSetting = new QWidget();
        tabSetting->setObjectName(QString::fromUtf8("tabSetting"));
        verticalLayout_3 = new QVBoxLayout(tabSetting);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widEncoderSetting = new DlgEncoderSetting(tabSetting);
        widEncoderSetting->setObjectName(QString::fromUtf8("widEncoderSetting"));

        verticalLayout_3->addWidget(widEncoderSetting);

        tabSector->addTab(tabSetting, QString());

        gridLayout->addWidget(tabSector, 0, 1, 2, 1);

        RDLiveSdkDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RDLiveSdkDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 684, 23));
        menuChipInput = new QMenu(menuBar);
        menuChipInput->setObjectName(QString::fromUtf8("menuChipInput"));
        menuAddScreen = new QMenu(menuChipInput);
        menuAddScreen->setObjectName(QString::fromUtf8("menuAddScreen"));
        menuAddCamera = new QMenu(menuChipInput);
        menuAddCamera->setObjectName(QString::fromUtf8("menuAddCamera"));
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QString::fromUtf8("menuScene"));
        menuDeleteScene = new QMenu(menuScene);
        menuDeleteScene->setObjectName(QString::fromUtf8("menuDeleteScene"));
        menuSwitchScene = new QMenu(menuScene);
        menuSwitchScene->setObjectName(QString::fromUtf8("menuSwitchScene"));
        menuPreviewLayout = new QMenu(menuScene);
        menuPreviewLayout->setObjectName(QString::fromUtf8("menuPreviewLayout"));
        menuBScenePos = new QMenu(menuPreviewLayout);
        menuBScenePos->setObjectName(QString::fromUtf8("menuBScenePos"));
        menuRenameScene = new QMenu(menuScene);
        menuRenameScene->setObjectName(QString::fromUtf8("menuRenameScene"));
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName(QString::fromUtf8("menuImage"));
        menuFpses = new QMenu(menuImage);
        menuFpses->setObjectName(QString::fromUtf8("menuFpses"));
        menuPreviewScale = new QMenu(menuImage);
        menuPreviewScale->setObjectName(QString::fromUtf8("menuPreviewScale"));
        RDLiveSdkDemoClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(RDLiveSdkDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RDLiveSdkDemoClass->setStatusBar(statusBar);

        menuBar->addAction(menuImage->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuBar->addAction(menuChipInput->menuAction());
        menuChipInput->addAction(menuAddScreen->menuAction());
        menuChipInput->addAction(menuAddCamera->menuAction());
        menuChipInput->addAction(actiAddPicture);
        menuAddScreen->addSeparator();
        menuAddCamera->addSeparator();
        menuScene->addAction(actAddScene);
        menuScene->addAction(menuSwitchScene->menuAction());
        menuScene->addAction(menuDeleteScene->menuAction());
        menuScene->addAction(menuRenameScene->menuAction());
        menuScene->addSeparator();
        menuScene->addAction(menuPreviewLayout->menuAction());
        menuScene->addAction(actClearCurScene);
        menuDeleteScene->addSeparator();
        menuSwitchScene->addSeparator();
        menuPreviewLayout->addAction(actBSceneCount0);
        menuPreviewLayout->addAction(actBSceneCount2);
        menuPreviewLayout->addAction(actBSceneCount4);
        menuPreviewLayout->addAction(actBSceneCount6);
        menuPreviewLayout->addAction(actBSceneCount8);
        menuPreviewLayout->addSeparator();
        menuPreviewLayout->addAction(actShowAddScene);
        menuPreviewLayout->addAction(actShowScrollBar);
        menuPreviewLayout->addAction(actShowSceneName);
        menuPreviewLayout->addAction(actShowCurrOnBack);
        menuPreviewLayout->addAction(actBSceneScale);
        menuPreviewLayout->addSeparator();
        menuPreviewLayout->addAction(menuBScenePos->menuAction());
        menuPreviewLayout->addSeparator();
        menuPreviewLayout->addAction(actRestorePreview);
        menuBScenePos->addAction(actBSceneUp);
        menuBScenePos->addAction(actBSceneDown);
        menuBScenePos->addAction(actBSceneLeft);
        menuBScenePos->addAction(actBSceneRight);
        menuRenameScene->addSeparator();
        menuImage->addAction(actSwapVH);
        menuImage->addSeparator();
        menuImage->addAction(menuFpses->menuAction());
        menuImage->addSeparator();
        menuImage->addAction(menuPreviewScale->menuAction());
        menuImage->addAction(actPreviewOpenGL);
        menuImage->addSeparator();
        menuFpses->addSeparator();
        menuPreviewScale->addSeparator();

        retranslateUi(RDLiveSdkDemoClass);

        tabSector->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RDLiveSdkDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *RDLiveSdkDemoClass)
    {
        RDLiveSdkDemoClass->setWindowTitle(QApplication::translate("RDLiveSdkDemoClass", "RDLiveSdkDemo", 0, QApplication::UnicodeUTF8));
        actAddScene->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\267\273\345\212\240\345\234\272\346\231\257\342\200\246\342\200\246", 0, QApplication::UnicodeUTF8));
        actBSceneCount0->setText(QApplication::translate("RDLiveSdkDemoClass", "\345\205\263\351\227\255\345\220\216\345\217\260\345\234\272\346\231\257\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        actBSceneCount2->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272 2 \344\270\252\345\220\216\345\217\260\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        actBSceneCount4->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272 4 \344\270\252\345\220\216\345\217\260\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        actBSceneCount6->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272 6 \344\270\252\345\220\216\345\217\260\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        actBSceneCount8->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272 8 \344\270\252\345\220\216\345\217\260\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        actShowScrollBar->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272\345\234\272\346\231\257\346\273\232\345\212\250\346\235\241", 0, QApplication::UnicodeUTF8));
        actShowAddScene->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272\346\267\273\345\212\240\345\234\272\346\231\257\346\214\211\351\222\256", 0, QApplication::UnicodeUTF8));
        actShowCurrOnBack->setText(QApplication::translate("RDLiveSdkDemoClass", "\345\220\216\345\217\260\346\230\276\347\244\272\345\275\223\345\211\215\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        actShowSceneName->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272\345\234\272\346\231\257\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        actBSceneScale->setText(QApplication::translate("RDLiveSdkDemoClass", "\351\274\240\346\240\207\347\247\273\345\205\245\345\234\272\346\231\257\346\224\276\345\244\247", 0, QApplication::UnicodeUTF8));
        actClearCurScene->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\270\205\347\251\272\345\275\223\345\211\215\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        actBSceneUp->setText(QApplication::translate("RDLiveSdkDemoClass", "\344\270\212", 0, QApplication::UnicodeUTF8));
        actBSceneDown->setText(QApplication::translate("RDLiveSdkDemoClass", "\344\270\213", 0, QApplication::UnicodeUTF8));
        actBSceneLeft->setText(QApplication::translate("RDLiveSdkDemoClass", "\345\267\246", 0, QApplication::UnicodeUTF8));
        actBSceneRight->setText(QApplication::translate("RDLiveSdkDemoClass", "\345\217\263", 0, QApplication::UnicodeUTF8));
        actRestorePreview->setText(QApplication::translate("RDLiveSdkDemoClass", "\350\277\230\345\216\237\351\242\204\350\247\210\345\270\203\345\261\200", 0, QApplication::UnicodeUTF8));
        actSwapVH->setText(QApplication::translate("RDLiveSdkDemoClass", "\344\272\244\346\215\242\345\256\275\345\222\214\351\253\230", 0, QApplication::UnicodeUTF8));
        actPreviewOpenGL->setText(QApplication::translate("RDLiveSdkDemoClass", "\351\242\204\350\247\210\344\275\277\347\224\250\347\241\254\344\273\266\345\212\240\351\200\237", 0, QApplication::UnicodeUTF8));
        actiAddPicture->setText(QApplication::translate("RDLiveSdkDemoClass", "\345\233\276\345\203\217\346\226\207\344\273\266\342\200\246\342\200\246", 0, QApplication::UnicodeUTF8));
        chkSpeaker->setText(QString());
        butAudioPopSpk->setText(QString());
        chkMicrophone->setText(QString());
        butAudioPopMic->setText(QString());
        butAddChip->setText(QApplication::translate("RDLiveSdkDemoClass", "\346\267\273\345\212\240\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        tabSector->setTabText(tabSector->indexOf(tabCurrScene), QApplication::translate("RDLiveSdkDemoClass", "\345\275\223\345\211\215\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        tabSector->setTabText(tabSector->indexOf(tabSetting), QApplication::translate("RDLiveSdkDemoClass", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        menuChipInput->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        menuAddScreen->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\261\217\345\271\225/\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        menuAddCamera->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\346\221\204\345\203\217\345\244\264", 0, QApplication::UnicodeUTF8));
        menuScene->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        menuDeleteScene->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\210\240\351\231\244\345\234\272\346\231\257", 0, QApplication::UnicodeUTF8));
        menuSwitchScene->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\210\207\346\215\242\345\210\260", 0, QApplication::UnicodeUTF8));
        menuPreviewLayout->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\351\242\204\350\247\210\345\270\203\345\261\200", 0, QApplication::UnicodeUTF8));
        menuBScenePos->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\346\230\276\347\244\272\347\232\204\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        menuRenameScene->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\234\272\346\231\257\351\207\215\345\221\275\345\220\215", 0, QApplication::UnicodeUTF8));
        menuImage->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        menuFpses->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\345\270\247\347\216\207", 0, QApplication::UnicodeUTF8));
        menuPreviewScale->setTitle(QApplication::translate("RDLiveSdkDemoClass", "\351\242\204\350\247\210\347\274\251\346\224\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RDLiveSdkDemoClass: public Ui_RDLiveSdkDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RDLIVESDKDEMO_H
