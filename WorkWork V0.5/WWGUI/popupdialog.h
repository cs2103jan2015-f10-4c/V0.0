//@author A0097195N
//Description: This class creates a side window dialog for the GUI class
//             The side window contains a random floating task and all the shortcuts
//             that the user can use
#ifndef POPUPDIALOG_H
#define POPUPDIALOG_H

#include <QDialog>
#include "ui_popupdialog.h"
#include <QKeyEvent>
#include <QShortcut>

class popUpDialog : public QDialog
{
	Q_OBJECT

public:
	popUpDialog(QWidget *parent = 0);
	~popUpDialog();
	void setFloatingTask(QString);

private:
	static const QString BROWN_BACKGROUND;
	static const QString WHITE_BACKGROUND;
	static const QString FLOATING_LABEL;
	static const QString SHORTCUTS_LABEL;

	Ui::popUpDialogClass ui;
	//Mouse position
	QPoint _windowPos;
	QPoint _mousePos;
	QPoint _dPos;
	
	//Setting up pop up dialog
	void setUpDialog();
	void setUpShortcutBox();
	void colorFormatting();
	//Moving window
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
};

#endif // POPUPDIALOG_H
