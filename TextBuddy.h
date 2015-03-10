/*This program is a command line interface which manipulates text file according to user command.
The expected inputs are listed below:
===================================================
Welcome to TextBuddy. mytextfile.txt is ready for use

command: add little brown fox

added to mytextfile.txt: ¡°little brown fox¡±

command: display

1. little brown fox

command: add jumped over the moon

added to mytextfile.txt: ¡°jumped over the moon¡±

command: display

1. little brown fox

2. jumped over the moon

command: delete 2

deleted from mytextfile.txt: ¡°jumped over the moon¡±

command: display

1. little brown fox

command: clear

all content deleted from mytextfile.txt

command: display

mytextfile.txt is empty

command: exit

===================================================

*/

#ifndef _TEXTBUDDY_H_
#define _TEXTBUDDY_H_
#define MAX_CHAR 255

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


/*This class uses a vector to store the text message.
It loads the previous data from the file (if any) and additional datas
by taking in user coommands and write these changes into the target textfile.
*/
class TextBuddy
{
private:
	static fstream myfile; // to input and extract text.
	static string filename;  // in order to display the name of file in the post-command messages
	static vector <string> textStorage;

	//These are the variables that are used to store post-command messages
	static string WELCOME_MESSAGE;
	static string ADDED_MESSAGE;
	static string DELETED_MESSAGE;
	static string NOTFOUND_MESSAGE;
	static string SORTED_MESSAGE;
	static string CLEAR_MESSAGE;
	static string ERROR_MESSAGE;   //invalid line number given in delete command
	static string INVALID_MESSAGE; //invalid command
	static string EMPTY_MESSAGE;
	static char outputStatement[MAX_CHAR];

	static enum COMMAND_TYPE {
		COMMAND_ADD, COMMAND_DISPLAY, COMMAND_DELETE, COMMAND_CLEAR, COMMAND_SORT, COMMAND_SEARCH,
		COMMAND_INVALID, COMMAND_EXIT
	}; //These are the possible command type.

	static void showUser(string text);
	static void showUser(vector<string> textLines);
	//the two showUser method is meant to display the repective messages.
	static void inputToFile();// to modify the file after each execution of command
	static string toLowerCase(string text);// to facillitate sort and search functionalities

public:

	static string command;
	TextBuddy(string fileName);
	~TextBuddy();

	static void  displayWELCOME_MESSAGE();
	static void  processCommand();
	static COMMAND_TYPE getCommandType(string usercommand);
	static void executeCommand(COMMAND_TYPE commandType);

	static string addText(string text);   // new text message will be stored at the last space in the vector.
	static string deleteText(int index); // deletion of text require a index number to locate the desired text line.
	static vector<string> displayAll(); //display what is in the file so far.
	static vector<string> sortText();
	static vector<string> searchText(string text);

	static string clearAll();
	

	void main();

};
#endif
