/********************************************************************************
** Form generated from reading UI file 'popupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPDIALOG_H
#define UI_POPUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_popUpDialogClass
{
public:
    QLabel *FloatingText;
    QTextBrowser *FloatingBox;
    QLabel *Shortcuts;
    QTextBrowser *ShortcutsBox;

    void setupUi(QWidget *popUpDialogClass)
    {
        if (popUpDialogClass->objectName().isEmpty())
            popUpDialogClass->setObjectName(QStringLiteral("popUpDialogClass"));
        popUpDialogClass->resize(276, 480);
        FloatingText = new QLabel(popUpDialogClass);
        FloatingText->setObjectName(QStringLiteral("FloatingText"));
        FloatingText->setEnabled(true);
        FloatingText->setGeometry(QRect(11, 21, 251, 16));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        FloatingText->setFont(font);
        FloatingBox = new QTextBrowser(popUpDialogClass);
        FloatingBox->setObjectName(QStringLiteral("FloatingBox"));
        FloatingBox->setEnabled(true);
        FloatingBox->setGeometry(QRect(11, 40, 256, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        FloatingBox->setFont(font1);
        FloatingBox->setFocusPolicy(Qt::NoFocus);
        Shortcuts = new QLabel(popUpDialogClass);
        Shortcuts->setObjectName(QStringLiteral("Shortcuts"));
        Shortcuts->setGeometry(QRect(11, 90, 251, 16));
        Shortcuts->setFont(font);
        ShortcutsBox = new QTextBrowser(popUpDialogClass);
        ShortcutsBox->setObjectName(QStringLiteral("ShortcutsBox"));
        ShortcutsBox->setGeometry(QRect(11, 108, 256, 341));
        QFont font2;
        font2.setPointSize(12);
        ShortcutsBox->setFont(font2);
        ShortcutsBox->setFocusPolicy(Qt::NoFocus);
        FloatingText->raise();
        Shortcuts->raise();
        FloatingBox->raise();
        ShortcutsBox->raise();

        retranslateUi(popUpDialogClass);

        QMetaObject::connectSlotsByName(popUpDialogClass);
    } // setupUi

    void retranslateUi(QWidget *popUpDialogClass)
    {
        popUpDialogClass->setWindowTitle(QApplication::translate("popUpDialogClass", "Form", 0));
        FloatingText->setText(QApplication::translate("popUpDialogClass", "Got Time?", 0));
        Shortcuts->setText(QApplication::translate("popUpDialogClass", "Shortcuts", 0));
    } // retranslateUi

};

namespace Ui {
    class popUpDialogClass: public Ui_popUpDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPDIALOG_H
