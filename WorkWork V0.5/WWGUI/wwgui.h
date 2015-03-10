//@author A0097195N
//Description: This class displays the list of tasks to the user
//             This class only contain WWUI that is related to the display of WWGUI
//             This class takes in the input from the user, processes it 
//             and updates the main display accordingly

#ifndef WWGUI_H
#define WWGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_wwgui.h"
#include "WWUI.h"
#include "popUpDialog.h"
#include <cassert>
#include <QSystemtrayicon>
#include <QString>
#include <QShortcut>
#include <QMessageBox>
#include <QHeaderView>
#include <QScrollbar>
#include <QTimer>

class WWGUI : public QMainWindow
{
	Q_OBJECT

public:
	WWGUI(QWidget *parent = 0);
	~WWGUI();

private:
	//page index
	static const int ALL_PAGE_INDEX = 0;
	static const int DEADLINE_PAGE_INDEX = 1;
	static const int TIMED_PAGE_INDEX = 2;
	static const int FLOATING_PAGE_INDEX = 3;
	static const int TODAY_PAGE_INDEX = 4;
	static const int COMPLETE_PAGE_INDEX = 5;
	static const int INCOMPLETE_PAGE_INDEX = 6;
	static const int OVERDUE_PAGE_INDEX = 7;
	static const int SEARCH_PAGE_INDEX = 8;
	//length of keyword
	static const int ADD_LENGTH = 3;
	static const int DELETE_LENGTH = 6;
	static const int EDIT_LENGTH = 4;
	static const int COMPLETE_LENGTH = 8;
	static const int INCOMPLETE_LENGTH = 10;
	static const int SEARCH_LENGTH = 6;
	static const int VIEW_LENGTH = 4;
	static const int HELP_LENGTH = 4;
	static const int EMPTY_SPACE_LENGTH = 1;
	//for setting up table
	static const int STARTING_INDEX = 0;
	static const int COLUMN_INDEX = 3;
	static const int FONT_SIZE_14 = 14;
	static const int FIRST_COLUMN_INDEX = 0;
	static const int SECOND_COLUMN_INDEX = 1;
	static const int THIRD_COLUMN_INDEX = 2;
	static const int TASK_INDEX_LENGTH = 45;
	static const int TASK_NAME_LENGTH = 475;
	static const int DATE_LENGTH = 162;
	static const int FIRST_ROW_INDEX = 0;
	static const int FIRST_ELEMENT_INDEX = 0;
	static const int SECOND_ELEMENT_INDEX = 1;
	static const int THIRD_ELEMENT_INDEX = 2;
	static const int ZERO_ROW = 0;
	static const int ONE_ROW_INDEX = 1;
	//Timer ten sec
	static const int TEN_SEC = 10000;
	//Character prompt text and changetext
	static const char a;
	static const char c;
	static const char d;
	static const char e;
	static const char h;
	static const char i;
	static const char o;
	static const char q;
	static const char r;
	static const char s;
	static const char u;
	static const char v;
	//QString for message
	static const QString ADD_INPUT_MSG;
	static const QString DELETE_INPUT_MSG;
	static const QString EDIT_INPUT_MSG;
	static const QString COMPLETE_INPUT_MSG;
	static const QString INCOMPLETE_INPUT_MSG;
	static const QString SEARCH_INPUT_MSG;
	static const QString VIEW_INPUT_MSG;
	static const QString REDO_INPUT_MSG;
	static const QString UNDO_INPUT_MSG;
	static const QString HELP_INPUT_MSG;
	static const QString QUIT_INPUT_MSG;
	//QString for prompt
	static const QString COMMAND_PROMPT;
	static const QString ADD_PROMPT;
	static const QString DELETE_PROMPT;
	static const QString EDIT_PROMPT;
	static const QString COMPLETE_PROMPT;
	static const QString INCOMPLETE_PROMPT;
	static const QString SEARCH_PROMPT;	
	static const QString VIEW_PROMPT;
	static const QString REDO_PROMPT;
	static const QString UNDO_PROMPT;
	static const QString HELP_PROMPT;
	static const QString QUIT_PROMPT;
	//QString for label display
	static const QString VIEW;
	static const QString ALL;
	static const QString DEADLINE;
	static const QString TIMED;
	static const QString FLOATING;
	static const QString TODAY;
	static const QString COMPLETE;
	static const QString INCOMPLETE;
	static const QString OVERDUE;
	static const QString SEARCH;
	//Other QString
	static const QString EMPTY_QSPACE;
	static const QString EMPTY_QSTRING;
	static const QString EMPTY_DISPLAY_MSG;
	static const QString WORKWORK_TITLE;
	static const QString HELP_TITLE;
	static const QString REFRESH_DISPLAY;
	static const QString WORKWORK_IMAGE;
	static const QString BROWN_BACKGROUND;
	static const QString WHITE_BACKGROUND;

	static enum ColumnHeader {
		TASK_INDEX, 
		TASK_DESC, 
		DATE
	};

	//Initialising Variables
	Ui::WWGUIClass ui;
	WWUI *WorkWork;						
	int _PageIndex;
	int _LengthOfIndex;
	QSystemTrayIcon *trayIcon;
	popUpDialog _dialog;
	QString _floatingTask;
	std::vector<std::vector<std::string>> _listOfTasks;
	//Mouse position
	QPoint _windowPos;
	QPoint _mousePos;
	QPoint _dPos;

	//Setting up UI
	void setUpUI();
	void setUpConnections();
	void setUpTable();
	void setUpShortcuts();
	void setUpFormatting();
	void setUpTrayIcon();
	void setUpDisplay();
	//For starting display
	void welcomePrompt();
	void startingDisplay();
	//Formatting table display
	void setColumnWidth();
	void fixColumnWidth();
	//Updating display
	void updateDisplay();
	void displayTable(int tabPageIndex);
	void updateLabel();
	//running program in UI
	void runProgram (QString input, int PageIndex);
	//help
	void helpAdd();
	void helpDelete();
	void helpEdit();
	void helpComplete();
	void helpIncomplete();
	void helpSearch();	
	void helpView();
	void helpRedo();
	void helpUndo();
	void helpQuit();
	//Displaying of message box for help
	void displayMsgBox(QString title, QString description);
	//Moving window
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);

private slots:
	//Inserting word in input box
	void checkAlphabet();
	void clearText();
	//For scrollbars
	void scrollUp();
	void scrollDown();
	//viewing
	void viewAll();
	void viewDeadline();
	void viewTimed();
	void viewFloating();
	void viewToday();
	void viewComplete();
	void viewIncomplete();
	void viewOverdue();
	//Others
	void run();
	void helpFunction();
	void promptMsg();
	void iconIsActived(QSystemTrayIcon::ActivationReason);
	void popDialog();
	void minimizeWindow();
	void closeWindow();
	void refreshDisplay();
};

#endif // WWGUI_H
