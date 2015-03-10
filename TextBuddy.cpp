#include "TextBuddy.h"

char TextBuddy::outputStatement[MAX_CHAR];
string TextBuddy::WELCOME_MESSAGE = "Welcome to TextBuddy. %s is ready for use.";
string TextBuddy::ADDED_MESSAGE = "Added to %s: \"%s\"";
string TextBuddy::DELETED_MESSAGE = "Deleted from %s: \"%s\"";
string TextBuddy::SORTED_MESSAGE = "All content sorted :";
string TextBuddy::NOTFOUND_MESSAGE = "The word is not found in the file, please try again\n";
string TextBuddy::CLEAR_MESSAGE = "All content deleted from %s";
string TextBuddy::INVALID_MESSAGE = "The command is invalid. Please re-enter.";
string TextBuddy::ERROR_MESSAGE = "This line does not exist. Please try again.";
string TextBuddy::EMPTY_MESSAGE = "%s is empty\n";
vector <string> TextBuddy::textStorage;
string TextBuddy::filename;
fstream TextBuddy::myfile;



TextBuddy::TextBuddy(string file){
	filename = file;
	string text;
	myfile.open(filename, ios::in);
	if (myfile.peek() != EOF){
		while (getline(myfile, text)){
			textStorage.push_back(text);
		}
	}
	myfile.close();
}

TextBuddy::~TextBuddy(){}


void TextBuddy::main(){

	displayWELCOME_MESSAGE();
	processCommand();
   
}

void TextBuddy::displayWELCOME_MESSAGE(){

	sprintf_s(outputStatement, WELCOME_MESSAGE.c_str(), filename.c_str());
	//To write the welcome message into outputstatement in a formatted way 
	showUser(outputStatement);
}


void TextBuddy::processCommand(){

	string command;
	COMMAND_TYPE userCommand;

	do{
		cout << "command: ";
		cin >> command;
		userCommand = getCommandType(command);
		executeCommand(userCommand);

	} while (userCommand != COMMAND_EXIT);

}

TextBuddy::COMMAND_TYPE TextBuddy::getCommandType(string userCommand){

	if (userCommand == "add"){
		return COMMAND_ADD;
	}
	else if (userCommand == "display"){
		return COMMAND_DISPLAY;
	}
	else if (userCommand == "delete"){
		return COMMAND_DELETE;
	}
	else if (userCommand == "sort"){
		return COMMAND_SORT;
	}
	else if (userCommand == "search"){
		return COMMAND_SEARCH;
	}
	else if (userCommand == "clear"){
		return COMMAND_CLEAR;
	}
	else if (userCommand == "exit"){
		return COMMAND_EXIT;
	}
	else{
		return COMMAND_INVALID;
	}
} // Command Type can be made insensitive to uppercase or lowercase letters


void TextBuddy::executeCommand(COMMAND_TYPE userCommand){
	char whitespace;
	string message;
	static vector <string> textForDisplay;

	if (userCommand == COMMAND_ADD) {

		string text;
		cin >> noskipws >> whitespace; 
		getline(cin, text);
		message = addText(text);
		showUser(message);

	}
    else if (userCommand == COMMAND_DELETE) {

		size_t lineNumber;
		cin >> noskipws >> whitespace;
		cin >> lineNumber;
		getchar();
		message = deleteText(lineNumber);
		showUser(message);

	}
	else if (userCommand == COMMAND_DISPLAY) {

		textForDisplay = displayAll();
		showUser(textForDisplay);
		getchar();

	}
	else if (userCommand == COMMAND_SORT) {

		showUser(SORTED_MESSAGE);
		textForDisplay = sortText();
		showUser(textForDisplay);
		getchar();

	}
	else if (userCommand == COMMAND_SEARCH) {

		string text;
		cin >> noskipws >> whitespace;
		getline(cin, text);
		textForDisplay = searchText(text);
		showUser(textForDisplay);

	}
	else if (userCommand == COMMAND_CLEAR) {

		message = clearAll();
		showUser(message);
		getchar();

	}
	else if (userCommand == COMMAND_EXIT){

		exit(0);

	}
	else {
		showUser(INVALID_MESSAGE);
		getchar();
	} 
}

string TextBuddy::toLowerCase(string text) {
	string lowCaseText = text;
	for (int i = 0; i<lowCaseText.size(); i++)
		lowCaseText[i] = tolower(lowCaseText[i]);

	return lowCaseText;
}


void TextBuddy::showUser(string text) {
	cout << text << endl;
}

void TextBuddy::showUser(vector<string> textLines) {

	for (int i = 0; i < textLines.size(); i++) {
		string output = textLines[i];
		cout << output;	
	}
}

string TextBuddy::addText(string text){
	textStorage.push_back(text);
	inputToFile();
	sprintf_s(outputStatement, ADDED_MESSAGE.c_str(), filename.c_str(), text.c_str());

	return outputStatement;
}


string TextBuddy::deleteText(int index){

	if (index <= textStorage.size() && index > 0 ){

		string deletedText;
		deletedText = textStorage[index - 1];
		textStorage.erase(textStorage.begin() + (index - 1));
		sprintf_s(outputStatement, DELETED_MESSAGE.c_str(), filename.c_str(), deletedText.c_str());
		inputToFile();
	}

	else{

		return ERROR_MESSAGE;
	}

	return outputStatement;
}

vector<string> TextBuddy::displayAll(){

	vector<string> allText;
	int lineNum = 1;

	if (textStorage.empty()){
		sprintf_s(outputStatement, EMPTY_MESSAGE.c_str(), filename.c_str());
		allText.push_back(outputStatement);
	}
	else{
		for (int i = 0; i < textStorage.size(); i++){

			ostringstream output;
			output << lineNum << ". " << textStorage[i] << endl;
			lineNum++;
			string NumberedText = output.str();
			allText.push_back(NumberedText);
		}
	}
    return allText;
}
vector<string> TextBuddy::sortText(){
	vector <string> lowerCaseString; //a temporary storage for lowercase strings
	vector <string> sortedText;

	for (int i = 0; i<textStorage.size(); i++){
		lowerCaseString.push_back(toLowerCase(textStorage[i]));
	}

	sort(lowerCaseString.begin(), lowerCaseString.end(), less<string>());
	for (auto i = lowerCaseString.begin(); i != lowerCaseString.end(); ++i){
		ostringstream output;
		output << *i << endl;
		sortedText.push_back(output.str());
	}

	return sortedText;
}

vector<string> TextBuddy::searchText(string text){
	text = toLowerCase(text);
	vector <string> searchingResult;
	size_t found;

	for (int i = 0; i < textStorage.size(); i++){

		ostringstream output;
		found = textStorage[i].find(text);

		if (found != string::npos){
			output << textStorage[i] << endl;
			searchingResult.push_back(output.str());
		}
	}

	if (searchingResult.size() == 0)
	{
		searchingResult.push_back(NOTFOUND_MESSAGE);
	}

	return searchingResult;

}



string TextBuddy::clearAll(){
	textStorage.clear();

	myfile.open(filename);
	myfile << "";
	myfile.close();
	sprintf_s(outputStatement, CLEAR_MESSAGE.c_str(), filename.c_str());

	return outputStatement;
} 

void TextBuddy::inputToFile(){

	myfile.open(filename, ios::out);
	vector<string>::iterator it;
	for (it = textStorage.begin(); it <textStorage.end(); ++it){
		myfile << *it << endl;
	}
	myfile.close();
}

int main(int argc, char* argv[]){
	
	if (argc < 2) {
		string file = "myfile.txt";
		TextBuddy myfile(file);
	    myfile.main();
	}

	else{
		string file = argv[1];
		TextBuddy myfile(file);
		myfile.main();
	}
	return 0;

}