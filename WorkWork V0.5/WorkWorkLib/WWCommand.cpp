//@author A0097547M

//WWCommand.cpp

#include <string>
#include "WWCommand.h"
#include "WWUtilities.h"

using namespace std;

WWCommand::WWCommand() {
	_hasCommand = false;
}

void WWCommand::setCommand(WWUtilities::CommandType inputCommand) {
	_command = inputCommand;
	_hasCommand = true;
}

void WWCommand::setDetail(string inputDetail) {
	_detail = inputDetail;
}

void WWCommand::setDate1(string inputDate1) {
	_date1 = inputDate1;
}

void WWCommand::setTime1(string inputTime1) {
	_time1 = inputTime1;
}

void WWCommand::setDate2(string inputDate2) {
	_date2 = inputDate2;
}

void WWCommand::setTime2(string inputTime2) {
	_time2 = inputTime2;
}

bool WWCommand::hasCommand() {
	return _hasCommand;
}

bool WWCommand::hasDetail() {
	return (!_detail.empty());
}

bool WWCommand::hasDate1() {
	return (!_date1.empty());
}

bool WWCommand::hasTime1() {
	return (!_time1.empty());
}

bool WWCommand::hasDate2() {
	return (!_date2.empty());
}

bool WWCommand::hasTime2() {
	return (!_time2.empty());
}

WWUtilities::CommandType WWCommand::getCommand() {
	return _command;
}

string WWCommand::getDetail() {
	return _detail;
}

string WWCommand::getDate1() {
	return _date1;
}

string WWCommand::getTime1() {
	return _time1;
}

string WWCommand::getDate2() {
	return _date2;
}

string WWCommand::getTime2() {
	return _time2;
}

void WWCommand::clearCommand() {
	_command = WWUtilities::INVALID;
	_detail = "";
	_date1 = "";
	_time1 = "";
	_date2 = "";
	_time2 = "";
	_hasCommand = false;
}