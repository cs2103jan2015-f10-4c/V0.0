//@author A0114946B

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TASK_NAME = "ABC";
const string STARTING_TIME = "0001";
const string ENDING_TIME = "2359";
const string STATUS = "DONE";

const string TEST_TIMED_TASK = "1. meeting ;  2012-01-01 1000 ; 2012-01-01 1300 ; Done";
const string TEST_DEADLINE_TASK = "2. assignment ; 2012-01-01 1300 ; Ongoing";
const string TEST_FLOATING_TASK = "3. reply email ; Ongoing";


namespace UnitTeststorage
{		
	TEST_CLASS(UnitTestStorage)
	{
	public:
		
	
		TEST_METHOD(testRemoveIndex)
		{
			Storage fileStorage;

			string testInput;
			testInput = TEST_TIMED_TASK;
			string testOutput;
			testOutput = fileStorage.removeIndex(testInput);
			Assert::IsTrue(testOutput == " meeting ;  2012-01-01 1000 ; 2012-01-01 1300 ; Done");

			testInput = TEST_DEADLINE_TASK;
			testOutput = fileStorage.removeIndex(testInput);
			Assert::IsTrue(testOutput == " assignment ; 2012-01-01 1300 ; Ongoing");

			testInput = TEST_FLOATING_TASK;
			testOutput = fileStorage.removeIndex(testInput);
			Assert::IsTrue(testOutput == " reply email ; Ongoing");

		}
		
		TEST_METHOD(testGetTaskName)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;
			
			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getTaskName(testInput);
			Assert::IsTrue(testOutput == "meeting");

			testInput = TEST_DEADLINE_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getTaskName(testInput);
			Assert::IsTrue(testOutput == "assignment");

			testInput = TEST_FLOATING_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getTaskName(testInput);
			Assert::IsTrue(testOutput == "reply email");

		}

		TEST_METHOD(testGetStartingTime)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStartingTime(testInput);
			Assert::IsTrue(testOutput == "2012-01-01 1000");
		}

		TEST_METHOD(testGetEndingTime)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getEndingTime(testInput);
			Assert::IsTrue(testOutput == "2012-01-01 1300");
		}

		TEST_METHOD(testGetDueTime)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_DEADLINE_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getDueTime(testInput);
			Assert::IsTrue(testOutput == "2012-01-01 1300");
		}

		TEST_METHOD(testGetStatus)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStatus(testInput);
			Assert::IsTrue(testOutput == "Done");

			testInput = TEST_DEADLINE_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStatus(testInput);
			Assert::IsTrue(testOutput == "Ongoing");

			testInput = TEST_FLOATING_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStatus(testInput);
			Assert::IsTrue(testOutput == "Ongoing");
		}

		TEST_METHOD(testLoadTask)
		{
			Storage fileStorage;
			vector<string> testTaskLine;
			vector<Task> testTaskList;
			string trashTask = "Task has not been typed";

			testTaskLine.push_back(TEST_TIMED_TASK);
			testTaskLine.push_back(TEST_DEADLINE_TASK);
			testTaskLine.push_back(TEST_FLOATING_TASK);
			testTaskLine.push_back(trashTask);

			//trash task should not be retrieved into taskList
			fileStorage.loadTask(testTaskLine,testTaskList);
			int tasklistSize = testTaskList.size();
			int expectedSize = 3;
			Assert::IsTrue(tasklistSize == expectedSize);

			string expectedTimedTaskName = "meeting";
			string expectedTimedTaskStartTime = "2012-01-01 1000";
			string expectedTimedTaskEndTime = "2012-01-01 1300";
			string expectedTimedTaskStatus = "Done";
			string expectedTimedTaskType = "timed";

			Assert::IsTrue(testTaskList[0].taskName == expectedTimedTaskName);
			Assert::IsTrue(testTaskList[0].startingTime == expectedTimedTaskStartTime);
			Assert::IsTrue(testTaskList[0].endingTime == expectedTimedTaskEndTime);
			Assert::IsTrue(testTaskList[0].status == expectedTimedTaskStatus);
			Assert::IsTrue(testTaskList[0].type == expectedTimedTaskType);

			string expectedDeadlineTaskName = "assignment";
			string expectedDeadlineTaskDueTime = "2012-01-01 1300";
			string expectedDeadlineTaskStatus = "Ongoing";
			string expectedDeadlineTaskType = "deadline";

			Assert::IsTrue(testTaskList[1].taskName == expectedDeadlineTaskName);
			Assert::IsTrue(testTaskList[1].endingTime == expectedDeadlineTaskDueTime);
			Assert::IsTrue(testTaskList[1].status == expectedDeadlineTaskStatus);
			Assert::IsTrue(testTaskList[1].type == expectedDeadlineTaskType);

			string expectedFloatingTaskName = "reply email";
			string expectedFloatingTaskStatus = "Ongoing";
			string expectedFloatingTaskType = "floating";
			
			Assert::IsTrue(testTaskList[2].taskName == expectedFloatingTaskName);
			Assert::IsTrue(testTaskList[2].status == expectedFloatingTaskStatus);
			Assert::IsTrue(testTaskList[2].type == expectedFloatingTaskType);

		}

		TEST_METHOD(testGetOutFilePath)
		{
			Storage testStorage;
			
			string outFilePath;
			outFilePath = "abc";
			
			testStorage.setOutFilePath(outFilePath);
			string expectedOutFilePath = testStorage.getOutfilePath();
			Assert::IsTrue(outFilePath == expectedOutFilePath);

		}

		
		TEST_METHOD(testGetUserInputPath)
		{
			Storage testStorage;
			
			string userInputPath;
			userInputPath = "abc";
			
			testStorage.setUserInputPath(userInputPath);
			string expecteduserInputPath = testStorage.getUserInputPath();
			Assert::IsTrue(userInputPath == expecteduserInputPath);

		}

		TEST_METHOD(testHasDirectory)
		{
			Storage testStorage;
			
			string testPath1 = "myAppConfig.txt";
			ifstream readFile;
			readFile.open(testPath1.c_str());
			string testLine1;
			getline(readFile, testLine1);

			if(testStorage.hasDirectory() == true){
				string testPath2 = "myAppConfig.txt";
				ifstream file;
				file.open(testPath2.c_str());
				string testLine2;
				getline(file, testLine2);

				Assert::IsTrue(testLine1 == testLine2);
			}
			else{
				bool test = testStorage.hasDirectory();
				bool expectedOutcome = false;
				
				Assert::IsTrue(test == expectedOutcome);
			}

		}

		TEST_METHOD(testRetrieveTimedTask)
		{
			Storage testStorage;

			string task1 = " project ; 04-03-2015 1400 ; 04-03-2015 1600 ; Ongoing";
			string task2 = " lunch with Jim ; 10-03-2015 1800 ; 10-03-2015 2100 ; Done";
			string task3 = " lecture ; 03-03-2015 1000 ; 03-03-2015 1200 ; Overdue";

			vector<Task> testTaskList; 
			testStorage.retrieveTimedTask(task1, testTaskList);

			string expectedTimedTaskName = "project";
			string expectedTimedTaskStartTime = "04-03-2015 1400";
			string expectedTimedTaskEndTime = "04-03-2015 1600";
			string expectedTimedTaskStatus = "Ongoing";
			string expectedTimedTaskType = "timed";
			
			Assert::IsTrue(testTaskList[0].taskName == expectedTimedTaskName);
			Assert::IsTrue(testTaskList[0].startingTime == expectedTimedTaskStartTime);
			Assert::IsTrue(testTaskList[0].endingTime == expectedTimedTaskEndTime);
			Assert::IsTrue(testTaskList[0].status == expectedTimedTaskStatus);
			Assert::IsTrue(testTaskList[0].type == expectedTimedTaskType);

			testStorage.retrieveTimedTask(task2, testTaskList);

			expectedTimedTaskName = "lunch with Jim";
			expectedTimedTaskStartTime = "10-03-2015 1800";
			expectedTimedTaskEndTime = "10-03-2015 2100";
			expectedTimedTaskStatus = "Done";
			expectedTimedTaskType = "timed";
			
			Assert::IsTrue(testTaskList[1].taskName == expectedTimedTaskName);
			Assert::IsTrue(testTaskList[1].startingTime == expectedTimedTaskStartTime);
			Assert::IsTrue(testTaskList[1].endingTime == expectedTimedTaskEndTime);
			Assert::IsTrue(testTaskList[1].status == expectedTimedTaskStatus);
			Assert::IsTrue(testTaskList[1].type == expectedTimedTaskType);

			testStorage.retrieveTimedTask(task3, testTaskList);

			expectedTimedTaskName = "lecture";
			expectedTimedTaskStartTime = "03-03-2015 1000";
			expectedTimedTaskEndTime = "03-03-2015 1200";
			expectedTimedTaskStatus = "Overdue";
			expectedTimedTaskType = "timed";
			
			Assert::IsTrue(testTaskList[2].taskName == expectedTimedTaskName);
			Assert::IsTrue(testTaskList[2].startingTime == expectedTimedTaskStartTime);
			Assert::IsTrue(testTaskList[2].endingTime == expectedTimedTaskEndTime);
			Assert::IsTrue(testTaskList[2].status == expectedTimedTaskStatus);
			Assert::IsTrue(testTaskList[2].type == expectedTimedTaskType);

		}

		TEST_METHOD(testRetrieveDeadlineTask)
		{
			Storage testStorage;

			string task1 = " assignment ; 04-03-2015 1400 ; Done";
			string task2 = " tutorial ; 10-03-2015 2100 ; Ongoing";
			string task3 = " IE presentation ; 03-03-2015 1200 ; Overdue";

			vector<Task> testTaskList; 
			testStorage.retrieveDeadlineTask(task1, testTaskList);

			string expectedDeadlineTaskName = "assignment";
			string expectedDeadlineTaskStartTime = "";
			string expectedDeadlinedTaskEndTime = "04-03-2015 1400";
			string expectedDeadlineTaskStatus = "Done";
			string expectedDeadlineTaskType = "deadline";

			Assert::IsTrue(testTaskList[0].taskName == expectedDeadlineTaskName);
			Assert::IsTrue(testTaskList[0].startingTime == expectedDeadlineTaskStartTime);
			Assert::IsTrue(testTaskList[0].endingTime == expectedDeadlinedTaskEndTime);
			Assert::IsTrue(testTaskList[0].status == expectedDeadlineTaskStatus);
			Assert::IsTrue(testTaskList[0].type == expectedDeadlineTaskType);

			testStorage.retrieveDeadlineTask(task2, testTaskList);
			expectedDeadlineTaskName = "tutorial";
			expectedDeadlineTaskStartTime = "";
			expectedDeadlinedTaskEndTime = "10-03-2015 2100";
			expectedDeadlineTaskStatus = "Ongoing";
			expectedDeadlineTaskType = "deadline";

			Assert::IsTrue(testTaskList[1].taskName == expectedDeadlineTaskName);
			Assert::IsTrue(testTaskList[1].startingTime == expectedDeadlineTaskStartTime);
			Assert::IsTrue(testTaskList[1].endingTime == expectedDeadlinedTaskEndTime);
			Assert::IsTrue(testTaskList[1].status == expectedDeadlineTaskStatus);
			Assert::IsTrue(testTaskList[1].type == expectedDeadlineTaskType);

			testStorage.retrieveDeadlineTask(task3, testTaskList);
			expectedDeadlineTaskName = "IE presentation";
			expectedDeadlineTaskStartTime = "";
			expectedDeadlinedTaskEndTime = "03-03-2015 1200";
			expectedDeadlineTaskStatus = "Overdue";
			expectedDeadlineTaskType = "deadline";

			Assert::IsTrue(testTaskList[2].taskName == expectedDeadlineTaskName);
			Assert::IsTrue(testTaskList[2].startingTime == expectedDeadlineTaskStartTime);
			Assert::IsTrue(testTaskList[2].endingTime == expectedDeadlinedTaskEndTime);
			Assert::IsTrue(testTaskList[2].status == expectedDeadlineTaskStatus);
			Assert::IsTrue(testTaskList[2].type == expectedDeadlineTaskType);
		}

		TEST_METHOD(testRetrieveFloatingTask)
		{
			Storage testStorage;

			string task1 = " abc ; Done";
			string task2 = " 123 ; Ongoing";
			string task3 = " YYY ; Overdue";

			vector<Task> testTaskList;
			testStorage.retrieveFloatingTask(task1, testTaskList);
			
			string expectedFloatingTaskName = "abc";
			string expectedFloatingTaskStatus = "Done";
			string expectedFloatingTaskType = "floating";
			string expectedFloatingStartTime = "";
			string expectedFloatingEndTime = "";

			Assert::IsTrue(testTaskList[0].taskName == expectedFloatingTaskName);
			Assert::IsTrue(testTaskList[0].status == expectedFloatingTaskStatus);
			Assert::IsTrue(testTaskList[0].type == expectedFloatingTaskType);
			Assert::IsTrue(testTaskList[0].startingTime == expectedFloatingStartTime);
			Assert::IsTrue(testTaskList[0].endingTime == expectedFloatingEndTime);

			testStorage.retrieveFloatingTask(task2, testTaskList);
			expectedFloatingTaskName = "123";
			expectedFloatingTaskStatus = "Ongoing";
			expectedFloatingTaskType = "floating";
			expectedFloatingStartTime = "";
			expectedFloatingEndTime = "";

			Assert::IsTrue(testTaskList[1].taskName == expectedFloatingTaskName);
			Assert::IsTrue(testTaskList[1].status == expectedFloatingTaskStatus);
			Assert::IsTrue(testTaskList[1].type == expectedFloatingTaskType);
			Assert::IsTrue(testTaskList[1].startingTime == expectedFloatingStartTime);
			Assert::IsTrue(testTaskList[1].endingTime == expectedFloatingEndTime);

			testStorage.retrieveFloatingTask(task3, testTaskList);
			expectedFloatingTaskName = "YYY";
			expectedFloatingTaskStatus = "Overdue";
			expectedFloatingTaskType = "floating";
			expectedFloatingStartTime = "";
			expectedFloatingEndTime = "";

			Assert::IsTrue(testTaskList[2].taskName == expectedFloatingTaskName);
			Assert::IsTrue(testTaskList[2].status == expectedFloatingTaskStatus);
			Assert::IsTrue(testTaskList[2].type == expectedFloatingTaskType);
			Assert::IsTrue(testTaskList[2].startingTime == expectedFloatingStartTime);
			Assert::IsTrue(testTaskList[2].endingTime == expectedFloatingEndTime);

		}
		
		TEST_METHOD(testSaveFile)
		{
			Storage testStorage;
			string testFilePath = "testFile.txt";
			testStorage.setOutFilePath(testFilePath);
			
			//timed task
			Task testTask1;
			testTask1.setTaskName("ABC");
			testTask1.setStartingTime ("0000");
			testTask1.setEndingTime ("2359");
			testTask1.setDone ("DONE");
			testTask1.setType("timed");

			//deadline task
			Task testTask2;
			testTask2.setTaskName("AAA");
			testTask2.setStartingTime ("");
			testTask2.setEndingTime ("2200");
			testTask2.setDone ("DONE");
			testTask2.setType("deadline");

			//floating task
			Task testTask3;
			testTask3.setTaskName("BBB");
			testTask3.setStartingTime ("");
			testTask3.setEndingTime ("");
			testTask3.setDone ("ONGOING");
			testTask3.setType("floating");

			//task has not been specified type
			Task testTask4;
			testTask4.setTaskName("meeting");
			testTask3.setStartingTime ("");
			testTask3.setEndingTime ("");
			testTask3.setDone ("ONGOING");

			vector<Task> testTaskList;
			testTaskList.push_back(testTask1);
			testTaskList.push_back(testTask2);
			testTaskList.push_back(testTask3);
			testTaskList.push_back(testTask4);

			testStorage.saveFile(testTaskList);
			
			ifstream file(testFilePath.c_str());
			vector<string> testLine;
			string line;
			while(getline(file,line)){
				testLine.push_back(line);
			}
			int expectedSize = 5;
			
			Assert::IsTrue(testLine.size() == expectedSize);
			Assert::IsTrue(testLine[0] == " Tasklist: ");
			Assert::IsTrue(testLine[1] == "1. ABC ; 0000 ; 2359 ; DONE");
			Assert::IsTrue(testLine[2] == "2. AAA ; 2200 ; DONE");
			Assert::IsTrue(testLine[3] == "3. BBB ; ONGOING");
			Assert::IsTrue(testLine[4] == "Task has not been typed");

		}
	};
}

	