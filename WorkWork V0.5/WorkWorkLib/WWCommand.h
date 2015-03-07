//@author A0097547M
//WWCommand.h

#ifndef WWCOMMAND_H
#define WWCOMMAND_H

#include <string>
#include "WWUtilities.h"

//WWCommand is used to encapsulate the user input in a standard format.
//By encapsulating user input, WWLogic is able to access relevant information easily through the public methods
//WWCommand also provides public methods that allow WWLogic to check whether the information is available
//WWCommand also enumerates the possible operations that the user might want to perform as CommandType:
//	ADD, DELETE, EDIT, DONE.....etc

class WWCommand {
public:

	WWCommand();

	void setCommand(WWUtilities::CommandType);
	void setDetail(std::string);
	void setDate1(std::string);
	void setTime1(std::string);
	void setDate2(std::string);
	void setTime2(std::string);

	bool hasCommand();
	bool hasDetail();
	bool hasDate1();
	bool hasTime1();
	bool hasDate2();
	bool hasTime2();

	WWUtilities::CommandType getCommand();
	std::string getDetail();
	std::string getDate1();
	std::string getTime1();
	std::string getDate2();
	std::string getTime2();

	void clearCommand();

private:

	WWUtilities::CommandType _command;
	std::string _detail;
	std::string _date1;
	std::string _time1;
	std::string _date2;
	std::string _time2;
	bool _hasCommand;
};
#endif

/*
Comments:
-currently, any class that includes WWCommand can simply change the content that WWCommand has encapsulates
-by right only WWParser can change while WWLogic can only access
*/