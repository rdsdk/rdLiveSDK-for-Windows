/********************************************************************************
** Form generated from reading UI file 'DlgAddLive.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGADDLIVE_H
#define UI_DLGADDLIVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgAddLive
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *combLiveType;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *texRtmpUrl;
    QLabel *label_5;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *texSdkUserId;
    QLabel *label_4;
    QWidget *page_3;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *texRdLiveUserName;
    QLabel *label_7;
    QLineEdit *texRdLivePassword;
    QCheckBox *chkRdLiveAutoLogin;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *butOK;
    QPushButton *butCancel;

    void setupUi(QDialog *DlgAddLive)
    {
        if (DlgAddLive->objectName().isEmpty())
            DlgAddLive->setObjectName(QString::fromUtf8("DlgAddLive"));
        DlgAddLive->resize(257, 163);
        verticalLayout = new QVBoxLayout(DlgAddLive);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DlgAddLive);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        combLiveType = new QComboBox(DlgAddLive);
        combLiveType->setObjectName(QString::fromUtf8("combLiveType"));

        horizontalLayout->addWidget(combLiveType);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(DlgAddLive);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        texRtmpUrl = new QLineEdit(page);
        texRtmpUrl->setObjectName(QString::fromUtf8("texRtmpUrl"));
        texRtmpUrl->setMaxLength(256);

        verticalLayout_2->addWidget(texRtmpUrl);

        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        texSdkUserId = new QLineEdit(page_2);
        texSdkUserId->setObjectName(QString::fromUtf8("texSdkUserId"));
        texSdkUserId->setMaxLength(32);

        verticalLayout_3->addWidget(texSdkUserId);

        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout = new QGridLayout(page_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        texRdLiveUserName = new QLineEdit(page_3);
        texRdLiveUserName->setObjectName(QString::fromUtf8("texRdLiveUserName"));
        texRdLiveUserName->setMaxLength(64);

        gridLayout->addWidget(texRdLiveUserName, 0, 1, 1, 1);

        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        texRdLivePassword = new QLineEdit(page_3);
        texRdLivePassword->setObjectName(QString::fromUtf8("texRdLivePassword"));
        texRdLivePassword->setMaxLength(64);
        texRdLivePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(texRdLivePassword, 1, 1, 1, 1);

        chkRdLiveAutoLogin = new QCheckBox(page_3);
        chkRdLiveAutoLogin->setObjectName(QString::fromUtf8("chkRdLiveAutoLogin"));

        gridLayout->addWidget(chkRdLiveAutoLogin, 2, 1, 1, 1);

        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        butOK = new QPushButton(DlgAddLive);
        butOK->setObjectName(QString::fromUtf8("butOK"));
        butOK->setDefault(true);

        horizontalLayout_2->addWidget(butOK);

        butCancel = new QPushButton(DlgAddLive);
        butCancel->setObjectName(QString::fromUtf8("butCancel"));

        horizontalLayout_2->addWidget(butCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DlgAddLive);
        QObject::connect(combLiveType, SIGNAL(currentIndexChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgAddLive);
    } // setupUi

    void retranslateUi(QDialog *DlgAddLive)
    {
        DlgAddLive->setWindowTitle(QApplication::translate("DlgAddLive", "DlgAddLive", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgAddLive", "\347\233\264\346\222\255\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        combLiveType->clear();
        combLiveType->insertItems(0, QStringList()
         << QApplication::translate("DlgAddLive", "RTMP \347\233\264\346\222\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgAddLive", "RDLiveSDK \344\272\221\347\233\264\346\222\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgAddLive", "\351\224\220\345\212\250\347\233\264\346\222\255 (\344\272\221\347\233\264\346\222\255)", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("DlgAddLive", "RTMP \347\233\264\346\222\255\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DlgAddLive", "\344\276\213\345\246\202\357\274\232rtmp://192.168.0.1/live/abc", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DlgAddLive", "\347\224\250\346\210\267ID\357\274\210\350\203\275\346\240\207\350\257\206\347\224\250\346\210\267\345\224\257\344\270\200\346\200\247\347\232\204\345\255\227\347\254\246\344\270\262\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DlgAddLive", "\345\260\217\345\206\231\345\255\227\346\257\215\345\222\214\346\225\260\345\255\227\347\232\204\347\273\204\345\220\210\357\274\214\345\260\217\344\272\21632\344\270\252\345\255\227\347\254\246", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DlgAddLive", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DlgAddLive", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        chkRdLiveAutoLogin->setText(QApplication::translate("DlgAddLive", "\350\207\252\345\212\250\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        butOK->setText(QApplication::translate("DlgAddLive", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        butCancel->setText(QApplication::translate("DlgAddLive", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgAddLive: public Ui_DlgAddLive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGADDLIVE_H
