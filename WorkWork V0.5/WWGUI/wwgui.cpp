//@author A0097195N
#include "wwgui.h"

const char WWGUI::a                            = 'a';
const char WWGUI::c                            = 'c';
const char WWGUI::d                            = 'd';
const char WWGUI::e                            = 'e';
const char WWGUI::h                            = 'h';
const char WWGUI::i                            = 'i';
const char WWGUI::o                            = 'o';
const char WWGUI::q                            = 'q';
const char WWGUI::r                            = 'r';
const char WWGUI::s                            = 's';
const char WWGUI::u                            = 'u';
const char WWGUI::v                            = 'v';

const QString WWGUI::ADD_INPUT_MSG             = "add";
const QString WWGUI::DELETE_INPUT_MSG          = "delete";
const QString WWGUI::EDIT_INPUT_MSG            = "edit";
const QString WWGUI::COMPLETE_INPUT_MSG        = "complete";
const QString WWGUI::INCOMPLETE_INPUT_MSG      = "incomplete";
const QString WWGUI::SEARCH_INPUT_MSG          = "search";
const QString WWGUI::VIEW_INPUT_MSG            = "view";
const QString WWGUI::REDO_INPUT_MSG            = "redo";
const QString WWGUI::UNDO_INPUT_MSG            = "undo";
const QString WWGUI::HELP_INPUT_MSG            = "help";
const QString WWGUI::QUIT_INPUT_MSG            = "quit";

const QString WWGUI::COMMAND_PROMPT            = "Commands available:\n[a]dd, [d]elete, [e]dit, [c]omplete, [i]ncomplete, [s]earch, [v]iew, [r]edo, [u]ndo, [h]elp, [q]uit";
const QString WWGUI::ADD_PROMPT                = "Task name is a must!\nadd [task name] {start date} {start time} {end time} {end time}";
const QString WWGUI::DELETE_PROMPT             = "Enter the index of the task\ndelete <index / all>";
const QString WWGUI::EDIT_PROMPT               = "Enter the component you wish to edit\nedit <index> [taskname] {start date} {start time} {end time} {end time}";
const QString WWGUI::COMPLETE_PROMPT           = "Which task have you completed?\ncomplete <index>";
const QString WWGUI::INCOMPLETE_PROMPT         = "Which task do you want to incomplete?\nincomplete <index>";
const QString WWGUI::SEARCH_PROMPT             = "Searching for something?\nsearch [keyword] {date} {time}";
const QString WWGUI::VIEW_PROMPT               = "\nview < all / deadline / timed / floating / today / complete / incomplete / overdue >";
const QString WWGUI::REDO_PROMPT               = "\nRedo last action? Press enter to redo";
const QString WWGUI::UNDO_PROMPT               = "\nUndo last action? Press enter to undo";
const QString WWGUI::HELP_PROMPT               = "\nhelp < add / delete/ edit / complete / incomplete/ search / view / redo / undo / quit >";
const QString WWGUI::QUIT_PROMPT               = "\nQuitting program? Press enter to quit";

const QString WWGUI::VIEW                      = "view ";
const QString WWGUI::ALL                       = "all";
const QString WWGUI::DEADLINE                  = "deadline";
const QString WWGUI::TIMED                     = "timed";
const QString WWGUI::FLOATING                  = "floating";
const QString WWGUI::TODAY                     = "today";
const QString WWGUI::COMPLETE                  = "complete";
const QString WWGUI::INCOMPLETE                = "incomplete";
const QString WWGUI::OVERDUE                   = "overdue";
const QString WWGUI::SEARCH                    = "search";

const QString WWGUI::EMPTY_QSPACE              = " ";
const QString WWGUI::EMPTY_QSTRING             = "";
const QString WWGUI::EMPTY_DISPLAY_MSG         = "You have entered nothing!";
const QString WWGUI::WORKWORK_TITLE            = "WorkWork";
const QString WWGUI::HELP_TITLE                = "Help";
const QString WWGUI::REFRESH_DISPLAY           = "refresh";
const QString WWGUI::WORKWORK_IMAGE            = ":/WWGUI/Resources/workwork.png";
const QString WWGUI::BROWN_BACKGROUND          = "background: rgb(245, 222, 179);";
const QString WWGUI::WHITE_BACKGROUND          = "background: white;";

WWGUI::WWGUI(QWidget *parent): QMainWindow(parent) {
	ui.setupUi(this);
	WorkWork = new WWUI();
	setUpUI();
}

WWGUI::~WWGUI() {
	//hides the trayicon before exiting the program
	trayIcon->hide();
	delete WorkWork;
}

//setting up the UI
void WWGUI::setUpUI() {
	setUpConnections();
	setUpTable();
	setUpShortcuts();
	setUpFormatting();
	setUpTrayIcon();
	setUpDisplay();
}

//setting up the connections(signals and slots).
void WWGUI::setUpConnections() {
	connect(ui.Input, SIGNAL(textEdited(QString)), this,SLOT(promptMsg()));
	connect(ui.Input, SIGNAL(textEdited(QString)), this, SLOT(checkAlphabet()));
	connect(ui.Input, SIGNAL(returnPressed()), this, SLOT(run()));
	connect(ui.MinimizeButton, SIGNAL(clicked()), this, SLOT(minimizeWindow()));
	connect(ui.CloseButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(refreshDisplay()));
	timer->start(TEN_SEC);
}

//formatting the table
void WWGUI::setUpTable() {
	setColumnWidth();
	fixColumnWidth();
}

//initialising the shortcuts 
void WWGUI::setUpShortcuts() {
	//for viewing different types of tasks
	new QShortcut(Qt::Key_F1, this, SLOT(viewAll()));
	new QShortcut(Qt::Key_F2, this, SLOT(viewDeadline()));
	new QShortcut(Qt::Key_F3, this, SLOT(viewTimed()));
	new QShortcut(Qt::Key_F4, this, SLOT(viewFloating()));
	new QShortcut(Qt::Key_F5, this, SLOT(viewToday()));
	new QShortcut(Qt::Key_F6, this, SLOT(viewComplete()));
	new QShortcut(Qt::Key_F7, this, SLOT(viewIncomplete()));
	new QShortcut(Qt::Key_F8, this, SLOT(viewOverdue()));
	//for displaying the side window (shows a random floating task and the shortcuts available to the user)
	new QShortcut(Qt::Key_F12, this, SLOT(popDialog()));
	//clears the entire text in input box
	new QShortcut(Qt::Key_Escape, this, SLOT(clearText()));
	//for scrollbars 
	new QShortcut(Qt::Key_Up, this, SLOT(scrollUp()));
	new QShortcut(Qt::Key_Down, this, SLOT(scrollDown()));
	new QShortcut(Qt::Key_PageUp, this, SLOT(scrollUp()));
	new QShortcut(Qt::Key_PageDown, this, SLOT(scrollDown()));
	//for general help
	new QShortcut(Qt::CTRL + Qt::Key_F1, this, SLOT(helpFunction()));
	//for minimizing program
	new QShortcut(Qt::CTRL + Qt::Key_F2, this, SLOT(minimizeWindow()));
}

void WWGUI::setUpFormatting() {
	//removing the border of main window
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
	//changing background colour to brown
	this->setStyleSheet(BROWN_BACKGROUND);
	//setting the background colour of table, input box and buttons
	ui.Table->setStyleSheet(WHITE_BACKGROUND);
	ui.Input->setStyleSheet(WHITE_BACKGROUND);
}

//initialising the trayicon for the program 
void WWGUI::setUpTrayIcon() {
	QPixmap pixmap(WORKWORK_IMAGE);
	QIcon image(pixmap);
	QMainWindow::setWindowIcon(image);
	trayIcon = new QSystemTrayIcon(image, this);
	trayIcon->show();
	trayIcon->setToolTip(WORKWORK_TITLE);
	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
}

//initialising the display whenever the user on the program
void WWGUI::setUpDisplay() {
	welcomePrompt();
	startingDisplay();
}

//starting display 
void WWGUI::startingDisplay() {
	_PageIndex = ALL_PAGE_INDEX;
	QString viewInput = VIEW + ALL;
	runProgram(viewInput, _PageIndex);
}

//welcome prompt for the user when he first start the program
void WWGUI::welcomePrompt() {
	ui.Prompt->setText(COMMAND_PROMPT);
}

//setting the columns width of the table
void WWGUI::setColumnWidth() {
	ui.Table->setColumnCount(COLUMN_INDEX);
	ui.Table->setColumnWidth(TASK_INDEX, TASK_INDEX_LENGTH);
	ui.Table->setColumnWidth(TASK_DESC, TASK_NAME_LENGTH);
	ui.Table->setColumnWidth(DATE, DATE_LENGTH);
	ui.Table->horizontalHeader()->hide();
}

//fixing the columns width of the table
void WWGUI::fixColumnWidth() {
	for(unsigned int col = FIRST_COLUMN_INDEX ; col < COLUMN_INDEX ; col++) {
		ui.Table->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Fixed);
	}
}

//updates the table with the list of tasks 
void WWGUI::updateDisplay() {
	//updates the label eg to show "ALL" to inform the user that the table is showing all tasks
	updateLabel();
	ui.Table->clearContents();
	ui.Table->setRowCount(ZERO_ROW);

	QFont font;
	font.setPointSize(FONT_SIZE_14);
	font.setBold(true);

	for (unsigned row = FIRST_ROW_INDEX; row < _listOfTasks.size(); row++) {
		ui.Table->insertRow( ui.Table->rowCount() );
		
		QString taskIndex = QString::number(row + ONE_ROW_INDEX);
		QTableWidgetItem *displayIndex = new QTableWidgetItem(taskIndex);
		displayIndex->setFont(font);
		displayIndex->setTextAlignment(Qt::AlignCenter);
		ui.Table->setItem(row, FIRST_COLUMN_INDEX, displayIndex);
		
		QTableWidgetItem *displayTaskDesc = new QTableWidgetItem(QString::fromStdString(_listOfTasks[row][FIRST_ELEMENT_INDEX]));	
		displayTaskDesc->setFont(font);
		ui.Table->setItem(row, SECOND_COLUMN_INDEX, displayTaskDesc);

		QTableWidgetItem *displayDate = new QTableWidgetItem(QString::fromStdString(_listOfTasks[row][SECOND_ELEMENT_INDEX]));	
		ui.Table->setItem(row, THIRD_COLUMN_INDEX, displayDate);
		//setting the background color of the index based on the status of the task
		if(_listOfTasks[row][THIRD_ELEMENT_INDEX] == COMPLETE.toStdString()) {
			displayIndex->setBackgroundColor(QColor(180,238,180));
		} else if(_listOfTasks[row][THIRD_ELEMENT_INDEX] == INCOMPLETE.toStdString()) {
			displayIndex->setBackgroundColor(QColor(255,255,255));
		} else if(_listOfTasks[row][THIRD_ELEMENT_INDEX] == OVERDUE.toStdString()) {
			displayIndex->setBackgroundColor(QColor(255,193,193));
		} else if(_listOfTasks[row][THIRD_ELEMENT_INDEX] == TODAY.toStdString()) {
			displayIndex->setBackgroundColor(QColor(255, 255, 100));
		}
		ui.Table->resizeRowsToContents();
	}
}

//used for the shortcuts that displays the different modes of displays
void WWGUI::displayTable(int PageIndex) {
	QString viewInput;
	switch(PageIndex) {
		case ALL_PAGE_INDEX: {
			viewInput =  VIEW + ALL;
			ui.TaskType->setText(ALL.toUpper());
			break;
		}
		case DEADLINE_PAGE_INDEX: {
			viewInput =  VIEW + DEADLINE;
			ui.TaskType->setText(DEADLINE.toUpper());
			break;
		}
		case TIMED_PAGE_INDEX: {
			viewInput = VIEW + TIMED;
			ui.TaskType->setText(TIMED.toUpper());
			break;
		}
		case FLOATING_PAGE_INDEX: {
			viewInput = VIEW + FLOATING;
			ui.TaskType->setText(FLOATING.toUpper());
			break;
		}
		case TODAY_PAGE_INDEX: {
			viewInput = VIEW + TODAY;
			ui.TaskType->setText(TODAY.toUpper());
			break;
		}
		case COMPLETE_PAGE_INDEX: {
			viewInput = VIEW + COMPLETE;
			ui.TaskType->setText(COMPLETE.toUpper());
			break;
		}
		case INCOMPLETE_PAGE_INDEX: {
			viewInput = VIEW + INCOMPLETE;
			ui.TaskType->setText(INCOMPLETE.toUpper());
			break;
		}
		case OVERDUE_PAGE_INDEX: {
			viewInput = VIEW + OVERDUE;
			ui.TaskType->setText(OVERDUE.toUpper());
			break;
		}
		case SEARCH_PAGE_INDEX: {
			viewInput = VIEW + SEARCH;
			ui.TaskType->setText(SEARCH.toUpper());
			break;
		}
		default: {
			viewInput =  VIEW + ALL;
			ui.TaskType->setText(ALL.toUpper());
		}
	}
	runProgram(viewInput,_PageIndex);
}

//updates the label that shows the types of tasks that the user is currently looking at
void WWGUI::updateLabel() {
	switch(_PageIndex) {
		case ALL_PAGE_INDEX: {
			ui.TaskType->setText(ALL.toUpper());
			break;
		}
		case DEADLINE_PAGE_INDEX: {
			ui.TaskType->setText(DEADLINE.toUpper());
			break;
		}
		case TIMED_PAGE_INDEX: {
			ui.TaskType->setText(TIMED.toUpper());
			break;
		}
		case FLOATING_PAGE_INDEX: {
			ui.TaskType->setText(FLOATING.toUpper());
			break;
		}
		case TODAY_PAGE_INDEX: {
			ui.TaskType->setText(TODAY.toUpper());
			break;
		}
		case COMPLETE_PAGE_INDEX: {
			ui.TaskType->setText(COMPLETE.toUpper());
			break;
		}
		case INCOMPLETE_PAGE_INDEX: {
			ui.TaskType->setText(INCOMPLETE.toUpper());
			break;
		}
		case OVERDUE_PAGE_INDEX: {
			ui.TaskType->setText(OVERDUE.toUpper());
			break;
		}
		case SEARCH_PAGE_INDEX: {
			ui.TaskType->setText(SEARCH.toUpper());
			break;
		}
		default: {
			ui.TaskType->setText(ALL.toUpper());
		}
	}
}

//refreshes the main display every 60 seconds
void WWGUI::refreshDisplay() {
	runProgram(REFRESH_DISPLAY, _PageIndex);
}

//sends the user input to WWUI and gets display information from WWUI, updates the side window and gives feedback to the user
// Display information received
// 1) the updated list of tasks
// 2) a random floating task
// 3) the appropriate page index to display the list of tasks 
// 4) getting the feedback for the user input and displaying it to the user  
void WWGUI::runProgram(QString input, int PageIndex) {
	WorkWork->runProgram(input.toStdString(), PageIndex);
	_listOfTasks = WorkWork->display();
	_PageIndex = WorkWork->getPageIndex();
	//floating task should not be empty string
	//a string should inform the user that there is no floating task
	_floatingTask = QString::fromStdString(WorkWork->getFloatingTask());
	assert(_floatingTask != EMPTY_QSTRING);
	_dialog.setFloatingTask(_floatingTask);
	updateDisplay();
	//system response string should not be empty
	QString _sysResp = QString::fromStdString(WorkWork->displaySystemResponse());
	assert(_sysResp != EMPTY_QSTRING);
	statusBar()->showMessage(_sysResp);
}

//Different help messages for different commands
void WWGUI::helpAdd() {
	const QString HELP_ADD = \
		"<b>Add</b><br />"
		"This command is used to add tasks to WorkWork.<br />"
		"Tasks may be timed, floating or have a deadline.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'a' for 'add'.<br />"
		"* Enter task description.<br />"
		"* Enter one date/time to specify a deadline task.<br />"
		"* Enter two dates/time to specify a timed task.<br />"
		"* No date/time is needed for floating task.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* add school project 1apr 1600h 21apr2014 0500h<br />"
		"* add Save Princess Peach 22/12/2014<br />"
		"* add Meeting 11.00am<br />"
		"* add Take afternoon nap<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_ADD);
}

void WWGUI::helpDelete() {
	const QString HELP_DELETE = \
		"<b>Delete</b><br />"
		"This command is used to delete tasks.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'd' for 'delete'.<br />"
		"* Enter the task's index.<br />"
		"* Enter 'all' to clear all tasks.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* delete 2<br />"
		"* delete all<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_DELETE);
}

void WWGUI::helpEdit() {
	const QString HELP_EDIT = \
		"<b>Edit</b><br />"
		"This command allows you to change the attributes of a task.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'e' for 'edit' followed by the task's index.<br />"
		"* Specify the changes you want to make<br />"
		"  whether to task description, start date/time or end date/time.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* edit 1 Dental appointment<br />"
		"* edit 2 12:00pm 30/10<br />"
		"* edit 1 31 Oct 9am 4Apr 5pm<br />"
		"* edit 3 2000h 2130h<br />"
		"* edit 4 Get hair cut 31/10<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_EDIT);
}

void WWGUI::helpComplete() {
	const QString HELP_COMPLETE = \
		"<b>Complete</b><br />"
		"This command marks a task as complete.<br />"
		" The index of the completed task will be marked in green.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'c' for complete.<br />"
		"* Specify the index of the task to mark it as completed.<br />"
		"<br />"
		"<b>Example</b><br />"
		"* complete 2<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_COMPLETE);
}

void WWGUI::helpIncomplete() {
	const QString HELP_INCOMPLETE = \
		"<b>Incomplete</b><br />"
		"This command marks a task as incomplete.<br />"
		" The index of the incomplete task will be marked in white.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'i' for 'incomplete'.<br />"
		"* Enter the index of the task to mark it as incomplete.<br />"
		"<br />"
		"<b>Example</b><br />"
		"* incomplete 1<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_INCOMPLETE);
}

void WWGUI::helpSearch() {
	const QString HELP_SEARCH = \
		"<b>Search</b><br />"
		"This command will search for tasks containing certain keywords.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 's' for 'search'.<br />"
		"* Enter the words you want to search.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* search boss<br />"
		"* search homework<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_SEARCH);
}

void WWGUI::helpView() {
	const QString HELP_VIEW = \
		"<b>View</b><br />"
		"This command displays all saved tasks.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'v' for 'view'. <br />"
		"* Enter a display mode. Options are 'all', 'deadline',<br />"
		"  'timed', 'floating', 'today', 'complete', 'incomplete'.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* view all<br />"
		"* view deadline<br />"
		"* view timed<br />"
		"* view floating<br />"
		"* view today<br />"
		"* view complete<br />"
		"* view incomplete<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_VIEW);
}

void WWGUI::helpRedo() {
	const QString HELP_REDO = \
		"<b>Redo</b><br />"
		"This command reverts the last 'undo' operation on the task list.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'r' for 'redo' and enter.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* redo<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_REDO);
}

void WWGUI::helpUndo() {
	const QString HELP_UNDO = \
		"<b>Undo</b><br />"
		"This command reverts the last operation on the task list.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'u' for 'undo' and enter.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* undo<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_UNDO);
}

void WWGUI::helpQuit() {
	const QString HELP_QUIT = \
		"<b>Quit</b><br />"
		"This command quits the program.<br />"
		"<br />"
		"<b>Command format</b><br />"
		"* Press 'q' for 'quit' and enter.<br />"
		"<br />"
		"<b>Examples</b><br />"
		"* quit<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HELP_QUIT);
}

//used to display the help messages for the various different commands
void WWGUI::displayMsgBox(QString title, QString description){
	QPixmap pixmap(WORKWORK_IMAGE);
	QIcon image(pixmap);
	QMessageBox msgBox;
	msgBox.setWindowTitle(title);
	msgBox.setWindowIcon(image);
	msgBox.setText(description);
	msgBox.exec();
}

//for moving the main window 
void WWGUI::mousePressEvent(QMouseEvent *event){                                                                                                      
	this->_windowPos = this->pos();   
	this->_mousePos = event->globalPos();  
	this->_dPos = _mousePos - _windowPos; 
}  
//for moving the main window 
void WWGUI::mouseMoveEvent(QMouseEvent *event){ 
	this->move(event->globalPos() - this->_dPos);  
} 

void WWGUI::iconIsActived(QSystemTrayIcon::ActivationReason) { 
	if(isMinimized()) {
		show();
		setWindowState(Qt::WindowActive);
	} else {
		showMinimized();
	}
}
//based on the first alphabet(regardless small or capital letter) that the user has entered,
//it will autofill the command word automatically
void WWGUI::checkAlphabet() {
	QString text = ui.Input->text();	
	text = text.toLower();

	if(text[STARTING_INDEX] == a && text.length() <= (ADD_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(ADD_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == d && text.length() <= (DELETE_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(DELETE_INPUT_MSG + EMPTY_QSPACE);
	}  else if (text[STARTING_INDEX] == e && text.length() <= (EDIT_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(EDIT_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == c && text.length() <= (COMPLETE_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(COMPLETE_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == i && text.length() <= (INCOMPLETE_LENGTH +EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(INCOMPLETE_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == s && text.length() <= (SEARCH_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(SEARCH_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == v && text.length() <= (VIEW_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(VIEW_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == r) {
		ui.Input->setText(REDO_INPUT_MSG);
	} else if (text[STARTING_INDEX] == u) {
		ui.Input->setText(UNDO_INPUT_MSG);
	} else if (text[STARTING_INDEX] == h && text.length() <= (HELP_LENGTH + EMPTY_SPACE_LENGTH)) {
		ui.Input->setText(HELP_INPUT_MSG + EMPTY_QSPACE);
	} else if (text[STARTING_INDEX] == q) {
		ui.Input->setText(QUIT_INPUT_MSG);
	} 
}
//alternative way to clear the text in the input box quickly
void WWGUI::clearText() {
	ui.Input->clear();
	ui.Prompt->setText(COMMAND_PROMPT);
}
//for setting up shortcuts for scrolling up the table
void WWGUI::scrollUp() {
	ui.Table->verticalScrollBar()->setSliderPosition(ui.Table->verticalScrollBar()->sliderPosition() - ui.Table->verticalScrollBar()->pageStep());
}
//for setting up shortcuts for scrolling down the table
void WWGUI::scrollDown() {
	ui.Table->verticalScrollBar()->setSliderPosition(ui.Table->verticalScrollBar()->sliderPosition() + ui.Table->verticalScrollBar()->pageStep());
}
//the view functions used for shortcuts. Shortcuts display different displays modes such as all, deadline, etc.
void WWGUI::viewAll() {
	displayTable(ALL_PAGE_INDEX);
}

void WWGUI::viewDeadline() {
	displayTable(DEADLINE_PAGE_INDEX);
}

void WWGUI::viewTimed() {
	displayTable(TIMED_PAGE_INDEX);
}

void WWGUI::viewFloating() {
	displayTable(FLOATING_PAGE_INDEX);
}

void WWGUI::viewToday() {
	displayTable(TODAY_PAGE_INDEX);
}

void WWGUI::viewComplete() {
	displayTable(COMPLETE_PAGE_INDEX);
}

void WWGUI::viewIncomplete() {
	displayTable(INCOMPLETE_PAGE_INDEX);
}

void WWGUI::viewOverdue() {
	displayTable(OVERDUE_PAGE_INDEX);
}
//activated when user presses enter
//processes userinput to check for help command and empty string
//Otherwise, user input will be sent to WWUI to process
void WWGUI::run() {
	ui.Prompt->setText(COMMAND_PROMPT);
	QString userInput = ui.Input->text();
	QString checkHelp = userInput.toLower();
	ui.Input->setText(EMPTY_QSTRING);
	try {
		//if userinput is empty will display to user a empty input message
		if(userInput == EMPTY_QSTRING) {
			throw EMPTY_QSTRING;
		}
		if( checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE ) {
			helpFunction();
		} else if( checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + ADD_INPUT_MSG ) {
			helpAdd();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + DELETE_INPUT_MSG ) {
			helpDelete();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + EDIT_INPUT_MSG ) {
			helpEdit();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + COMPLETE_INPUT_MSG ) {
			helpComplete();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + INCOMPLETE_INPUT_MSG ) {
			helpIncomplete();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + SEARCH_INPUT_MSG ) {
			helpSearch();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + VIEW_INPUT_MSG ) {
			helpView();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + REDO_INPUT_MSG ) {
			helpRedo();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + UNDO_INPUT_MSG ) {
			helpUndo();
		} else if (checkHelp == HELP_INPUT_MSG + EMPTY_QSPACE + QUIT_INPUT_MSG ) {
			helpQuit();
		} else {
			runProgram(userInput, _PageIndex);
		}
	} catch (QString) {
		ui.statusBar->showMessage(EMPTY_DISPLAY_MSG);
	}
}
//displays a prompt msg to aid the user in entering a valid user input
void WWGUI::promptMsg() {
	QString text = ui.Input->text();
	text = text.toLower();
	if(text == EMPTY_QSTRING) {
		ui.Prompt->setText(COMMAND_PROMPT);
	} else {
		if(text[STARTING_INDEX] == a ) {
			ui.Prompt->setText(ADD_PROMPT);
		} else if (text[STARTING_INDEX] == d) {
			ui.Prompt->setText(DELETE_PROMPT);
		} else if (text[STARTING_INDEX] == e) {
			ui.Prompt->setText(EDIT_PROMPT);
		} else if (text[STARTING_INDEX] == c) {
			ui.Prompt->setText(COMPLETE_PROMPT);
		} else if (text[STARTING_INDEX] == i) {
			ui.Prompt->setText(INCOMPLETE_PROMPT);
		} else if (text[STARTING_INDEX] == s) {
			ui.Prompt->setText(SEARCH_PROMPT);
		} else if (text[STARTING_INDEX] == v) {
			ui.Prompt->setText(VIEW_PROMPT);
		} else if (text[STARTING_INDEX] == r) {
			ui.Prompt->setText(REDO_PROMPT);
		} else if (text[STARTING_INDEX] == u) {
			ui.Prompt->setText(UNDO_PROMPT);
		} else if (text[STARTING_INDEX] == h) {
			ui.Prompt->setText(HELP_PROMPT);
		} else if (text[STARTING_INDEX] == q) {
			ui.Prompt->setText(QUIT_PROMPT);
		}
	}
}
//displays the side window dialog 
void WWGUI::popDialog() {
	if(_dialog.isVisible()) {
		_dialog.close();
	} else {
		QPoint ptGlobal = this->mapToGlobal(QPoint(this->width(), 0));
		_dialog.setGeometry(QRect(ptGlobal, _dialog.size()));
		_dialog.show();
	}
}

void WWGUI::helpFunction(){
	const QString HOTKEY_LIST = \
		"<b>Commands</b><br />"
		"[a]dd, [d]elete, [e]dit, [c]omplete, [i]ncomplete<br />"	
		"[s]earch, [r]edo, [u]ndo, [v]iew, [q]uit<br />"	
		"Type 'help', followed by any of the above, to see usage tips and examples.<br />"
		"<br />";
	displayMsgBox(HELP_TITLE, HOTKEY_LIST);
}

//closes the program and the pop up dialog if it is still opened
void WWGUI::closeWindow() {
	if(_dialog.isVisible()) {
		_dialog.close();
	}
	this->close();
}

void WWGUI::minimizeWindow() {
	if(_dialog.isVisible()) {
		_dialog.close();
	}
	this->showMinimized();
}
