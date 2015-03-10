//@RushHour
//CommandHistroy is used to track all important operations that have been done by the user
//Every important operations made by the user will be saved as a vector 
//The user is then able to undo or redo operations whenever needed


#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H
#include <stack>
#include <string>
#include <vector>


class CommandHistory {
public:

	CommandHistory();
	~CommandHistory();

	void saveCommand(vector<string> );
	bool undoCommand();
	bool redoCommand();

private:
	stack 








};

#endif