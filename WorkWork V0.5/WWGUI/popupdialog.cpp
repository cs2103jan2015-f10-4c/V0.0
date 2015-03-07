//@author A0097195N
#include "popupdialog.h"

const QString popUpDialog::BROWN_BACKGROUND = "background: rgb(245, 222, 179);";
const QString popUpDialog::WHITE_BACKGROUND = "background: white;";
const QString popUpDialog::FLOATING_LABEL   = "<font color='black'>Got Time? </font>";
const QString popUpDialog::SHORTCUTS_LABEL  = "<font color='black'>Shortcuts </font>";

popUpDialog::popUpDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setUpDialog();
}

popUpDialog::~popUpDialog() {
}

//To set up the floating task box that shows a random floating task
void popUpDialog::setFloatingTask(QString floatingTask) {
	ui.FloatingBox->setText(floatingTask);
}

//formatting the pop up dialog
void popUpDialog::setUpDialog() {
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Popup);
	colorFormatting();
	setUpShortcutBox();
}

//To set up the display that shows the various shortcuts to the user
void popUpDialog::setUpShortcutBox() {
	const QString shortcutString = \
		"<b>Esc:</b>"
		" Clear text box<br />"
		"<br />"
		"<b>F1:</b>"
		" View all<br />"
		"<b>F2:</b>"
		" View Deadline<br />"	
		"<b>F3:</b>"
		" View Timed<br />"
		"<b>F4:</b>"
		" View Floating<br />"
		"<b>F5:</b>"
		" View Today<br />"
		"<b>F6:</b>"
		" View Complete<br />"	
		"<b>F7:</b>"
		" View Incomplete<br />"
		"<b>F8:</b>"
		" View Overdue<br />"
		"<br />"
		"<b>F12:</b>"
		" Un/Hide side windows<br />"
		"<br />"
		"<b>Ctrl + F1:</b>"
		" Help<br />"
		"<b>Ctrl + F2:</b>"
		" Minimize Window<br />";
	ui.ShortcutsBox->setText(shortcutString);
}

//formatting the background of the pop up dialog
void popUpDialog::colorFormatting() {
	this->setStyleSheet(BROWN_BACKGROUND);
	ui.FloatingText->setText(FLOATING_LABEL);
	ui.Shortcuts->setText(SHORTCUTS_LABEL);
	ui.FloatingBox->setStyleSheet(WHITE_BACKGROUND);
	ui.ShortcutsBox->setStyleSheet(WHITE_BACKGROUND);
}

//moving of the pop up dialog with mouse
void popUpDialog::mousePressEvent(QMouseEvent *event) {                                                                                                      
	this->_windowPos = this->pos();   
	this->_mousePos = event->globalPos();  
	this->_dPos = _mousePos - _windowPos;  
}  

//moving of the pop up dialog with mouse
void popUpDialog::mouseMoveEvent(QMouseEvent *event) { 
	this->move(event->globalPos() - this->_dPos);  
} 