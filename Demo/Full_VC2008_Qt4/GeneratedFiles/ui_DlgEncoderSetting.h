/********************************************************************************
** Form generated from reading UI file 'DlgEncoderSetting.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGENCODERSETTING_H
#define UI_DLGENCODERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgEncoderSetting
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QGroupBox *grpOptVideoAdv;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QComboBox *combVideoVBVMode;
    QLabel *label_23;
    QLabel *label_24;
    QSpinBox *spinVBVBitrateMax;
    QLabel *label_7;
    QLabel *label_20;
    QLabel *label_8;
    QSpinBox *spinVBVBufSize;
    QSpinBox *spinVideoIDR;
    QSpinBox *spinVideoIMin;
    QLabel *label_22;
    QSpinBox *spinVideoRef;
    QLabel *label_25;
    QSpinBox *spinVideoBFrame;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QLabel *labVideoEncoderTitle;
    QComboBox *combVideoEncoder;
    QLabel *labVideoPersetTitle;
    QSpinBox *spinVideoBitrate;
    QLabel *labVideoBitrateTitle;
    QComboBox *combVideoPerset;
    QLabel *label_6;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_3;
    QSpinBox *spinAudioBitrate;
    QRadioButton *radSingleChannel;
    QRadioButton *radDoubleChannel;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QComboBox *combAudioSamples;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *editVideoTitle;
    QGroupBox *gboxSaveToFile;
    QGridLayout *gridLayout_2;
    QLabel *labVideoDirTitle;
    QComboBox *combVideoFileFormat;
    QLabel *labVideoFormatTitle;
    QSpinBox *spinVideoSplitSize;
    QLabel *label_36;
    QLabel *label_37;
    QLineEdit *editVideoDir;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *butBrowVideoDir;
    QPushButton *butViewVideoDir;
    QLabel *labAcceditLocalDays;
    QGroupBox *gboxLiveToNet;
    QVBoxLayout *verticalLayout_2;
    QLabel *labAcceditLiveDays;
    QListView *listViewLiveUrls;
    QCheckBox *chkAdaptiveNetwork;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *butAddLiveUrl;
    QPushButton *butDelLiveUrl;
    QCheckBox *chkOutputVCamera;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DlgEncoderSetting)
    {
        if (DlgEncoderSetting->objectName().isEmpty())
            DlgEncoderSetting->setObjectName(QString::fromUtf8("DlgEncoderSetting"));
        DlgEncoderSetting->resize(400, 660);
        verticalLayout = new QVBoxLayout(DlgEncoderSetting);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolBox = new QToolBox(DlgEncoderSetting);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 400, 582));
        gridLayout_5 = new QGridLayout(page);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        grpOptVideoAdv = new QGroupBox(page);
        grpOptVideoAdv->setObjectName(QString::fromUtf8("grpOptVideoAdv"));
        gridLayout_3 = new QGridLayout(grpOptVideoAdv);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, -1, 6, -1);
        label_18 = new QLabel(grpOptVideoAdv);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_18, 0, 0, 1, 1);

        combVideoVBVMode = new QComboBox(grpOptVideoAdv);
        combVideoVBVMode->setObjectName(QString::fromUtf8("combVideoVBVMode"));

        gridLayout_3->addWidget(combVideoVBVMode, 0, 1, 1, 2);

        label_23 = new QLabel(grpOptVideoAdv);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_23, 1, 0, 1, 1);

        label_24 = new QLabel(grpOptVideoAdv);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_24, 2, 0, 1, 1);

        spinVBVBitrateMax = new QSpinBox(grpOptVideoAdv);
        spinVBVBitrateMax->setObjectName(QString::fromUtf8("spinVBVBitrateMax"));
        spinVBVBitrateMax->setMaximum(10000);
        spinVBVBitrateMax->setSingleStep(200);

        gridLayout_3->addWidget(spinVBVBitrateMax, 1, 1, 1, 1);

        label_7 = new QLabel(grpOptVideoAdv);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 2, 1, 1);

        label_20 = new QLabel(grpOptVideoAdv);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_20, 4, 0, 1, 1);

        label_8 = new QLabel(grpOptVideoAdv);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 2, 2, 1, 1);

        spinVBVBufSize = new QSpinBox(grpOptVideoAdv);
        spinVBVBufSize->setObjectName(QString::fromUtf8("spinVBVBufSize"));
        spinVBVBufSize->setMaximum(10000);
        spinVBVBufSize->setSingleStep(200);

        gridLayout_3->addWidget(spinVBVBufSize, 2, 1, 1, 1);

        spinVideoIDR = new QSpinBox(grpOptVideoAdv);
        spinVideoIDR->setObjectName(QString::fromUtf8("spinVideoIDR"));
        spinVideoIDR->setMaximum(6000);

        gridLayout_3->addWidget(spinVideoIDR, 4, 1, 1, 1);

        spinVideoIMin = new QSpinBox(grpOptVideoAdv);
        spinVideoIMin->setObjectName(QString::fromUtf8("spinVideoIMin"));
        spinVideoIMin->setMaximum(6000);

        gridLayout_3->addWidget(spinVideoIMin, 5, 1, 1, 1);

        label_22 = new QLabel(grpOptVideoAdv);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_22, 5, 0, 1, 1);

        spinVideoRef = new QSpinBox(grpOptVideoAdv);
        spinVideoRef->setObjectName(QString::fromUtf8("spinVideoRef"));
        spinVideoRef->setMaximum(16);

        gridLayout_3->addWidget(spinVideoRef, 6, 1, 1, 1);

        label_25 = new QLabel(grpOptVideoAdv);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_25, 6, 0, 1, 1);

        spinVideoBFrame = new QSpinBox(grpOptVideoAdv);
        spinVideoBFrame->setObjectName(QString::fromUtf8("spinVideoBFrame"));
        spinVideoBFrame->setMaximum(8);

        gridLayout_3->addWidget(spinVideoBFrame, 7, 1, 1, 1);

        label_5 = new QLabel(grpOptVideoAdv);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 7, 0, 1, 1);

        label_10 = new QLabel(grpOptVideoAdv);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setTextFormat(Qt::AutoText);

        gridLayout_3->addWidget(label_10, 4, 2, 2, 1);

        label_4 = new QLabel(grpOptVideoAdv);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 3, 0, 1, 3);


        gridLayout_5->addWidget(grpOptVideoAdv, 3, 0, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 4, 0, 1, 1);

        labVideoEncoderTitle = new QLabel(page);
        labVideoEncoderTitle->setObjectName(QString::fromUtf8("labVideoEncoderTitle"));
        labVideoEncoderTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labVideoEncoderTitle, 0, 0, 1, 1);

        combVideoEncoder = new QComboBox(page);
        combVideoEncoder->setObjectName(QString::fromUtf8("combVideoEncoder"));

        gridLayout_5->addWidget(combVideoEncoder, 0, 1, 1, 2);

        labVideoPersetTitle = new QLabel(page);
        labVideoPersetTitle->setObjectName(QString::fromUtf8("labVideoPersetTitle"));
        labVideoPersetTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labVideoPersetTitle, 1, 0, 1, 1);

        spinVideoBitrate = new QSpinBox(page);
        spinVideoBitrate->setObjectName(QString::fromUtf8("spinVideoBitrate"));
        spinVideoBitrate->setMinimum(200);
        spinVideoBitrate->setMaximum(10000);
        spinVideoBitrate->setSingleStep(200);
        spinVideoBitrate->setValue(800);

        gridLayout_5->addWidget(spinVideoBitrate, 2, 1, 1, 1);

        labVideoBitrateTitle = new QLabel(page);
        labVideoBitrateTitle->setObjectName(QString::fromUtf8("labVideoBitrateTitle"));
        labVideoBitrateTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labVideoBitrateTitle, 2, 0, 1, 1);

        combVideoPerset = new QComboBox(page);
        combVideoPerset->setObjectName(QString::fromUtf8("combVideoPerset"));

        gridLayout_5->addWidget(combVideoPerset, 1, 1, 1, 2);

        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 2, 2, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("\350\247\206\351\242\221\347\274\226\347\240\201"));
        grpOptVideoAdv->raise();
        spinVideoBitrate->raise();
        labVideoEncoderTitle->raise();
        labVideoBitrateTitle->raise();
        combVideoPerset->raise();
        labVideoPersetTitle->raise();
        label_6->raise();
        combVideoEncoder->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 400, 582));
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 1, 0, 1, 1);

        label_9 = new QLabel(page_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 2, 1, 1);

        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);

        spinAudioBitrate = new QSpinBox(page_2);
        spinAudioBitrate->setObjectName(QString::fromUtf8("spinAudioBitrate"));
        spinAudioBitrate->setMinimumSize(QSize(69, 0));
        spinAudioBitrate->setMinimum(16);
        spinAudioBitrate->setMaximum(256);
        spinAudioBitrate->setSingleStep(16);
        spinAudioBitrate->setValue(64);

        gridLayout_6->addWidget(spinAudioBitrate, 0, 1, 1, 1);

        radSingleChannel = new QRadioButton(page_2);
        radSingleChannel->setObjectName(QString::fromUtf8("radSingleChannel"));

        gridLayout_6->addWidget(radSingleChannel, 1, 1, 1, 1);

        radDoubleChannel = new QRadioButton(page_2);
        radDoubleChannel->setObjectName(QString::fromUtf8("radDoubleChannel"));

        gridLayout_6->addWidget(radDoubleChannel, 1, 2, 1, 1);

        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 3, 1, 1, 1);

        combAudioSamples = new QComboBox(page_2);
        combAudioSamples->setObjectName(QString::fromUtf8("combAudioSamples"));

        gridLayout_6->addWidget(combAudioSamples, 2, 1, 1, 2);

        toolBox->addItem(page_2, QString::fromUtf8("\351\237\263\351\242\221\347\274\226\347\240\201"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 400, 582));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        editVideoTitle = new QLineEdit(page_3);
        editVideoTitle->setObjectName(QString::fromUtf8("editVideoTitle"));

        horizontalLayout->addWidget(editVideoTitle);


        verticalLayout_4->addLayout(horizontalLayout);

        gboxSaveToFile = new QGroupBox(page_3);
        gboxSaveToFile->setObjectName(QString::fromUtf8("gboxSaveToFile"));
        gboxSaveToFile->setCheckable(true);
        gridLayout_2 = new QGridLayout(gboxSaveToFile);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labVideoDirTitle = new QLabel(gboxSaveToFile);
        labVideoDirTitle->setObjectName(QString::fromUtf8("labVideoDirTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labVideoDirTitle->sizePolicy().hasHeightForWidth());
        labVideoDirTitle->setSizePolicy(sizePolicy);
        labVideoDirTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(labVideoDirTitle, 1, 0, 1, 1);

        combVideoFileFormat = new QComboBox(gboxSaveToFile);
        combVideoFileFormat->setObjectName(QString::fromUtf8("combVideoFileFormat"));

        gridLayout_2->addWidget(combVideoFileFormat, 3, 1, 1, 1);

        labVideoFormatTitle = new QLabel(gboxSaveToFile);
        labVideoFormatTitle->setObjectName(QString::fromUtf8("labVideoFormatTitle"));
        labVideoFormatTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(labVideoFormatTitle, 3, 0, 1, 1);

        spinVideoSplitSize = new QSpinBox(gboxSaveToFile);
        spinVideoSplitSize->setObjectName(QString::fromUtf8("spinVideoSplitSize"));
        spinVideoSplitSize->setMaximum(8192);
        spinVideoSplitSize->setSingleStep(256);

        gridLayout_2->addWidget(spinVideoSplitSize, 4, 1, 1, 1);

        label_36 = new QLabel(gboxSaveToFile);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_36, 4, 0, 1, 1);

        label_37 = new QLabel(gboxSaveToFile);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_2->addWidget(label_37, 4, 2, 1, 1);

        editVideoDir = new QLineEdit(gboxSaveToFile);
        editVideoDir->setObjectName(QString::fromUtf8("editVideoDir"));

        gridLayout_2->addWidget(editVideoDir, 2, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        butBrowVideoDir = new QPushButton(gboxSaveToFile);
        butBrowVideoDir->setObjectName(QString::fromUtf8("butBrowVideoDir"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(butBrowVideoDir->sizePolicy().hasHeightForWidth());
        butBrowVideoDir->setSizePolicy(sizePolicy1);
        butBrowVideoDir->setMaximumSize(QSize(16, 16));

        horizontalLayout_4->addWidget(butBrowVideoDir);

        butViewVideoDir = new QPushButton(gboxSaveToFile);
        butViewVideoDir->setObjectName(QString::fromUtf8("butViewVideoDir"));
        butViewVideoDir->setMaximumSize(QSize(16, 16));

        horizontalLayout_4->addWidget(butViewVideoDir);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 1, 1, 2);

        labAcceditLocalDays = new QLabel(gboxSaveToFile);
        labAcceditLocalDays->setObjectName(QString::fromUtf8("labAcceditLocalDays"));

        gridLayout_2->addWidget(labAcceditLocalDays, 0, 0, 1, 3);


        verticalLayout_4->addWidget(gboxSaveToFile);

        gboxLiveToNet = new QGroupBox(page_3);
        gboxLiveToNet->setObjectName(QString::fromUtf8("gboxLiveToNet"));
        gboxLiveToNet->setCheckable(true);
        verticalLayout_2 = new QVBoxLayout(gboxLiveToNet);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labAcceditLiveDays = new QLabel(gboxLiveToNet);
        labAcceditLiveDays->setObjectName(QString::fromUtf8("labAcceditLiveDays"));

        verticalLayout_2->addWidget(labAcceditLiveDays);

        listViewLiveUrls = new QListView(gboxLiveToNet);
        listViewLiveUrls->setObjectName(QString::fromUtf8("listViewLiveUrls"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listViewLiveUrls->sizePolicy().hasHeightForWidth());
        listViewLiveUrls->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(listViewLiveUrls);

        chkAdaptiveNetwork = new QCheckBox(gboxLiveToNet);
        chkAdaptiveNetwork->setObjectName(QString::fromUtf8("chkAdaptiveNetwork"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(chkAdaptiveNetwork->sizePolicy().hasHeightForWidth());
        chkAdaptiveNetwork->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(chkAdaptiveNetwork);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        butAddLiveUrl = new QPushButton(gboxLiveToNet);
        butAddLiveUrl->setObjectName(QString::fromUtf8("butAddLiveUrl"));

        horizontalLayout_2->addWidget(butAddLiveUrl);

        butDelLiveUrl = new QPushButton(gboxLiveToNet);
        butDelLiveUrl->setObjectName(QString::fromUtf8("butDelLiveUrl"));

        horizontalLayout_2->addWidget(butDelLiveUrl);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(gboxLiveToNet);

        chkOutputVCamera = new QCheckBox(page_3);
        chkOutputVCamera->setObjectName(QString::fromUtf8("chkOutputVCamera"));

        verticalLayout_4->addWidget(chkOutputVCamera);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        toolBox->addItem(page_3, QString::fromUtf8("\347\274\226\347\240\201\350\276\223\345\207\272"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(DlgEncoderSetting);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DlgEncoderSetting);
    } // setupUi

    void retranslateUi(QWidget *DlgEncoderSetting)
    {
        DlgEncoderSetting->setWindowTitle(QApplication::translate("DlgEncoderSetting", "DlgEncoderSetting", 0, QApplication::UnicodeUTF8));
        grpOptVideoAdv->setTitle(QApplication::translate("DlgEncoderSetting", "\351\253\230\347\272\247\350\256\276\347\275\256(\350\257\267\350\260\250\346\205\216\344\277\256\346\224\271)", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("DlgEncoderSetting", "\347\240\201\347\216\207\346\250\241\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        combVideoVBVMode->clear();
        combVideoVBVMode->insertItems(0, QStringList()
         << QApplication::translate("DlgEncoderSetting", "ABR(\345\271\263\345\235\207\347\240\201\347\216\207)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgEncoderSetting", "VBR(\345\217\257\345\217\230\347\240\201\347\216\207)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgEncoderSetting", "CBR(\345\233\272\345\256\232\347\240\201\347\216\207)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgEncoderSetting", "CQP(\346\201\222\345\256\232\350\264\250\351\207\217)", 0, QApplication::UnicodeUTF8)
        );
        label_23->setText(QApplication::translate("DlgEncoderSetting", "\346\234\200\345\244\247\347\240\201\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("DlgEncoderSetting", "VBV \347\274\223\345\255\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DlgEncoderSetting", "kbit/s", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("DlgEncoderSetting", "IDR \351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DlgEncoderSetting", "kbit", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("DlgEncoderSetting", "I \345\270\247\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("DlgEncoderSetting", "Ref \345\274\225\347\224\250\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DlgEncoderSetting", "B \345\270\247\351\227\264\351\232\224\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        label_4->setText(QApplication::translate("DlgEncoderSetting", "\344\273\245\344\270\213\350\256\276\347\275\256\344\277\235\346\214\201\344\270\272 0 \345\210\231\344\275\277\347\224\250\351\273\230\350\256\244\345\200\274", 0, QApplication::UnicodeUTF8));
        labVideoEncoderTitle->setText(QApplication::translate("DlgEncoderSetting", "\347\274\226\347\240\201\345\231\250\357\274\232", 0, QApplication::UnicodeUTF8));
        labVideoPersetTitle->setText(QApplication::translate("DlgEncoderSetting", "\350\264\250\351\207\217\345\217\202\350\200\203\357\274\232", 0, QApplication::UnicodeUTF8));
        labVideoBitrateTitle->setText(QApplication::translate("DlgEncoderSetting", "\347\240\201\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DlgEncoderSetting", "kbit/s", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("DlgEncoderSetting", "\350\247\206\351\242\221\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgEncoderSetting", "\345\243\260\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DlgEncoderSetting", "kbit/s", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DlgEncoderSetting", "\347\240\201\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        radSingleChannel->setText(QApplication::translate("DlgEncoderSetting", "\345\215\225\345\243\260\351\201\223", 0, QApplication::UnicodeUTF8));
        radDoubleChannel->setText(QApplication::translate("DlgEncoderSetting", "\347\253\213\344\275\223\345\243\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DlgEncoderSetting", "\351\207\207\346\240\267\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("DlgEncoderSetting", "\351\237\263\351\242\221\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DlgEncoderSetting", "\346\240\207\351\242\230\357\274\232", 0, QApplication::UnicodeUTF8));
        gboxSaveToFile->setTitle(QApplication::translate("DlgEncoderSetting", "\344\277\235\345\255\230\345\210\260\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        labVideoDirTitle->setText(QApplication::translate("DlgEncoderSetting", "\350\247\206\351\242\221\346\226\207\344\273\266\345\244\271\357\274\232", 0, QApplication::UnicodeUTF8));
        combVideoFileFormat->clear();
        combVideoFileFormat->insertItems(0, QStringList()
         << QApplication::translate("DlgEncoderSetting", "flv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgEncoderSetting", "mp4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgEncoderSetting", "avi", 0, QApplication::UnicodeUTF8)
        );
        labVideoFormatTitle->setText(QApplication::translate("DlgEncoderSetting", "\346\226\207\344\273\266\346\240\274\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("DlgEncoderSetting", "\346\226\207\344\273\266\345\210\206\345\215\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("DlgEncoderSetting", "MB", 0, QApplication::UnicodeUTF8));
        butBrowVideoDir->setText(QApplication::translate("DlgEncoderSetting", "B", 0, QApplication::UnicodeUTF8));
        butViewVideoDir->setText(QApplication::translate("DlgEncoderSetting", "V", 0, QApplication::UnicodeUTF8));
        labAcceditLocalDays->setText(QString());
        gboxLiveToNet->setTitle(QApplication::translate("DlgEncoderSetting", "\347\233\264\346\222\255\345\210\260\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        labAcceditLiveDays->setText(QString());
        chkAdaptiveNetwork->setText(QApplication::translate("DlgEncoderSetting", "\347\233\264\346\222\255\344\270\212\344\274\240\346\227\266\350\207\252\345\212\250\351\200\202\345\272\224\347\275\221\347\273\234\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        butAddLiveUrl->setText(QApplication::translate("DlgEncoderSetting", "\346\267\273\345\212\240\347\233\264\346\222\255\347\233\256\346\240\207", 0, QApplication::UnicodeUTF8));
        butDelLiveUrl->setText(QApplication::translate("DlgEncoderSetting", "\345\210\240\351\231\244\351\200\211\344\270\255\351\241\271", 0, QApplication::UnicodeUTF8));
        chkOutputVCamera->setText(QApplication::translate("DlgEncoderSetting", "\350\276\223\345\207\272\345\210\260\350\231\232\346\213\237\346\221\204\345\203\217\345\244\264", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("DlgEncoderSetting", "\347\274\226\347\240\201\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgEncoderSetting: public Ui_DlgEncoderSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGENCODERSETTING_H
