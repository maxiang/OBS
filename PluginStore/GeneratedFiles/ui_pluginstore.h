/********************************************************************************
** Form generated from reading UI file 'pluginstore.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINSTORE_H
#define UI_PLUGINSTORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PluginStore
{
public:
    QGroupBox *horizontalGroupBox;
    QPushButton *closeButton;
    QLabel *label;
    QPushButton *setButton;

    void setupUi(QDialog *PluginStore)
    {
        if (PluginStore->objectName().isEmpty())
            PluginStore->setObjectName(QStringLiteral("PluginStore"));
        PluginStore->setWindowModality(Qt::NonModal);
        PluginStore->resize(701, 526);
        QIcon icon;
        icon.addFile(QStringLiteral("app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PluginStore->setWindowIcon(icon);
        PluginStore->setSizeGripEnabled(false);
        horizontalGroupBox = new QGroupBox(PluginStore);
        horizontalGroupBox->setObjectName(QStringLiteral("horizontalGroupBox"));
        horizontalGroupBox->setGeometry(QRect(0, 0, 701, 40));
        horizontalGroupBox->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        horizontalGroupBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        closeButton = new QPushButton(horizontalGroupBox);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(660, 10, 15, 15));
        label = new QLabel(horizontalGroupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 4, 121, 31));
        label->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        setButton = new QPushButton(horizontalGroupBox);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(640, 10, 15, 15));

        retranslateUi(PluginStore);

        QMetaObject::connectSlotsByName(PluginStore);
    } // setupUi

    void retranslateUi(QDialog *PluginStore)
    {
        PluginStore->setWindowTitle(QApplication::translate("PluginStore", "PluginStore", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("PluginStore", "TextLabel", 0));
        setButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PluginStore: public Ui_PluginStore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINSTORE_H
