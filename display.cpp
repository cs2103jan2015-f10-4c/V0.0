#include "display.h"

void Display::displayAll() {
    vector<string> taskStorage;
    taskStorage = Storage:: get
    int lineNumber = 1;

	if (taskStorage.empty()) {
		cout << "File is empty" << endl;   //error message
	}
	else {
		for (size_t i = 0; i < taskStorage.size(); i++) {
			cout << lineNumber << "." << taskStorage[i] << endl;
			lineNumber++;
            }
	}
}
