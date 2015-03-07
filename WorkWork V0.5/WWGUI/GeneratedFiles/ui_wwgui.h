/********************************************************************************
** Form generated from reading UI file 'wwgui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WWGUI_H
#define UI_WWGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WWGUIClass
{
public:
    QWidget *centralWidget;
    QToolButton *MinimizeButton;
    QToolButton *CloseButton;
    QLabel *TaskType;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *Table;
    QLabel *Prompt;
    QLineEdit *Input;
    QLabel *SideWindowHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WWGUIClass)
    {
        if (WWGUIClass->objectName().isEmpty())
            WWGUIClass->setObjectName(QStringLiteral("WWGUIClass"));
        WWGUIClass->resize(721, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WWGUIClass->sizePolicy().hasHeightForWidth());
        WWGUIClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        WWGUIClass->setFont(font);
        WWGUIClass->setToolTipDuration(0);
        centralWidget = new QWidget(WWGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MinimizeButton = new QToolButton(centralWidget);
        MinimizeButton->setObjectName(QStringLiteral("MinimizeButton"));
        MinimizeButton->setGeometry(QRect(669, 0, 26, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        MinimizeButton->setFont(font1);
        MinimizeButton->setFocusPolicy(Qt::NoFocus);
        MinimizeButton->setStyleSheet(QLatin1String("QToolButton#MinimizeButton {\n"
"	background-image: url(:/WWGUI/Resources/window_buttons.png);\n"
"	background-position: top left;\n"
"	border-style: flat;\n"
"}\n"
"\n"
"QToolButton#MinimizeButton::hover {\n"
"	background-image: url(:/WWGUI/Resources/window_buttons_hovered.png);\n"
"	background-position: top left;\n"
"	border-style: flat;\n"
"}"));
        CloseButton = new QToolButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(695, 0, 26, 30));
        CloseButton->setMaximumSize(QSize(16777215, 16777201));
        CloseButton->setFont(font1);
        CloseButton->setFocusPolicy(Qt::NoFocus);
        CloseButton->setStyleSheet(QLatin1String("QToolButton#CloseButton {\n"
"	background-image: url(:WWGUI/Resources/window_buttons.png);\n"
"	background-position: top right;\n"
"	border-style: flat;\n"
"}\n"
"\n"
"QToolButton#CloseButton::hover {\n"
"	background-image: url(:WWGUI/Resources/window_buttons_hovered.png);\n"
"	background-position: top right;\n"
"	border-style: flat;\n"
"}"));
        TaskType = new QLabel(centralWidget);
        TaskType->setObjectName(QStringLiteral("TaskType"));
        TaskType->setGeometry(QRect(10, 10, 421, 19));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 39, 701, 411));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Table = new QTableWidget(layoutWidget);
        Table->setObjectName(QStringLiteral("Table"));
        Table->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Table->sizePolicy().hasHeightForWidth());
        Table->setSizePolicy(sizePolicy1);
        Table->setFocusPolicy(Qt::NoFocus);
        Table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table->setTabKeyNavigation(false);
        Table->setDragDropOverwriteMode(true);
        Table->setSelectionBehavior(QAbstractItemView::SelectItems);
        Table->horizontalHeader()->setHighlightSections(false);
        Table->verticalHeader()->setVisible(false);

        gridLayout->addWidget(Table, 0, 0, 1, 1);

        Prompt = new QLabel(layoutWidget);
        Prompt->setObjectName(QStringLiteral("Prompt"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        Prompt->setFont(font2);

        gridLayout->addWidget(Prompt, 1, 0, 1, 1);

        Input = new QLineEdit(layoutWidget);
        Input->setObjectName(QStringLiteral("Input"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        Input->setFont(font3);

        gridLayout->addWidget(Input, 2, 0, 1, 1);

        SideWindowHelp = new QLabel(centralWidget);
        SideWindowHelp->setObjectName(QStringLiteral("SideWindowHelp"));
        SideWindowHelp->setGeometry(QRect(470, 10, 191, 19));
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        SideWindowHelp->setFont(font4);
        WWGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WWGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font5;
        font5.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        statusBar->setFont(font5);
        WWGUIClass->setStatusBar(statusBar);
        QWidget::setTabOrder(Input, Table);
        QWidget::setTabOrder(Table, MinimizeButton);
        QWidget::setTabOrder(MinimizeButton, CloseButton);

        retranslateUi(WWGUIClass);

        QMetaObject::connectSlotsByName(WWGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *WWGUIClass)
    {
        WWGUIClass->setWindowTitle(QApplication::translate("WWGUIClass", "WorkWork", 0));
        MinimizeButton->setText(QString());
        CloseButton->setText(QString());
        TaskType->setText(QString());
        Prompt->setText(QString());
        SideWindowHelp->setText(QApplication::translate("WWGUIClass", "Press F12 for Side Window ", 0));
    } // retranslateUi

};

namespace Ui {
    class WWGUIClass: public Ui_WWGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WWGUI_H
