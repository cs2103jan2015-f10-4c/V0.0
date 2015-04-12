//@author A0116363L
#pragma once
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <cliext/vector>
#include "Logic.h"
#include "Logger.h"
#using <mscorlib.dll>

Logic logic;

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  comfirmButton;
	protected:

	private: System::Windows::Forms::TextBox^  inputBox;


	private: System::Windows::Forms::Label^  SystemResponse;
	private: System::Windows::Forms::ListView^  DisplayContent;

	private: System::Windows::Forms::ColumnHeader^  Index;
	private: System::Windows::Forms::ColumnHeader^  TaskName;
	private: System::Windows::Forms::ColumnHeader^  Start;
	private: System::Windows::Forms::ColumnHeader^  End;
	private: System::Windows::Forms::ColumnHeader^  Status;


	protected:System::Windows::Forms::ListViewItem^ listViewItems;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  HelpButton;





	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->comfirmButton = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->SystemResponse = (gcnew System::Windows::Forms::Label());
			this->DisplayContent = (gcnew System::Windows::Forms::ListView());
			this->Index = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskName = (gcnew System::Windows::Forms::ColumnHeader());
			this->Start = (gcnew System::Windows::Forms::ColumnHeader());
			this->End = (gcnew System::Windows::Forms::ColumnHeader());
			this->Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comfirmButton
			// 
			this->comfirmButton->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comfirmButton->Location = System::Drawing::Point(461, 23);
			this->comfirmButton->Name = L"comfirmButton";
			this->comfirmButton->Size = System::Drawing::Size(62, 28);
			this->comfirmButton->TabIndex = 1;
			this->comfirmButton->Text = L"Enter";
			this->comfirmButton->UseVisualStyleBackColor = true;
			this->comfirmButton->Click += gcnew System::EventHandler(this, &MyForm::comfirmButton_Click);
			// 
			// inputBox
			// 
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(12, 24);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(443, 28);
			this->inputBox->TabIndex = 0;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &MyForm::inputBox_TextChanged);
			// 
			// SystemResponse
			// 
			this->SystemResponse->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SystemResponse->ForeColor = System::Drawing::Color::Red;
			this->SystemResponse->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->SystemResponse->Location = System::Drawing::Point(9, 498);
			this->SystemResponse->Name = L"SystemResponse";
			this->SystemResponse->Size = System::Drawing::Size(432, 26);
			this->SystemResponse->TabIndex = 4;
			this->SystemResponse->Text = L"SystemResponse";
			this->SystemResponse->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// DisplayContent
			// 
			this->DisplayContent->AllowColumnReorder = true;
			this->DisplayContent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Index, this->TaskName,
					this->Start, this->End, this->Status
			});
			this->DisplayContent->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DisplayContent->FullRowSelect = true;
			this->DisplayContent->GridLines = true;
			this->DisplayContent->Location = System::Drawing::Point(12, 58);
			this->DisplayContent->Name = L"DisplayContent";
			this->DisplayContent->Size = System::Drawing::Size(512, 437);
			this->DisplayContent->TabIndex = 5;
			this->DisplayContent->UseCompatibleStateImageBehavior = false;
			this->DisplayContent->View = System::Windows::Forms::View::Details;
			this->DisplayContent->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// Index
			// 
			this->Index->Text = L"Index";
			this->Index->Width = 50;
			// 
			// TaskName
			// 
			this->TaskName->Text = L"TaskName";
			this->TaskName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskName->Width = 100;
			// 
			// Start
			// 
			this->Start->Text = L"Start";
			this->Start->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Start->Width = 150;
			// 
			// End
			// 
			this->End->Text = L"End";
			this->End->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->End->Width = 150;
			// 
			// Status
			// 
			this->Status->Text = L"Status";
			this->Status->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 60000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick_1);
			// 
			// HelpButton
			// 
			this->HelpButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HelpButton->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HelpButton->ForeColor = System::Drawing::Color::Red;
			this->HelpButton->Location = System::Drawing::Point(448, 500);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(75, 23);
			this->HelpButton->TabIndex = 6;
			this->HelpButton->Text = L"Help ( F1 )";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AcceptButton = this->comfirmButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(541, 533);
			this->Controls->Add(this->HelpButton);
			this->Controls->Add(this->DisplayContent);
			this->Controls->Add(this->SystemResponse);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->comfirmButton);
			this->Font = (gcnew System::Drawing::Font(L"SimSun-ExtB", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm";
			this->Text = L"RushHour";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		//To register hotkeys in  the inetrface
		this->KeyPreview = true;
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);

		int count = 0;
		size_t tempStart = 0;
		size_t tempEnd = -2;
		String^ temp;
		string componentInfo;
		//To check whether user is a first-time user
		//We assume there is only one user for this software on each computer
		logic.checkDirectory();
	
		//To display the feedback message which is the user prompt for a file directory
		//or a welcome message for second-time user
		string responseMessage = logic.tellGUIResponse();
		this->SystemResponse->Text = gcnew String(responseMessage.c_str());

		//To update the status of any ouverdue tasks
		logic.refreshStatus();

		//To prepare the display window 
		string returnInfo = logic.tellGUI();
		String^ tempString = gcnew String(returnInfo.c_str());

		for (unsigned i = 0; i < returnInfo.size(); i++){

			if (returnInfo.at(i) == ']') {
				count++;
			}
		}
		while (count > 0) {
			/****Index****/
			tempStart = tempEnd + 3;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems = gcnew Windows::Forms::ListViewItem(temp);
			/****Task Name****/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);
			/****Starting Time****/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);
			/****Ending Time***/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);
			/****Status****/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);


			DisplayContent->Items->Add(this->listViewItems);
			count -= 5;
		}

	}


    //To register F1 as a hotkey for Help Button
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == System::Windows::Forms::Keys::F1) {
			this->HelpButton->PerformClick();
		}
	}
	

    //Specify the following procedures when the Enter button is clicked
	private: System::Void comfirmButton_Click(System::Object^  sender, System::EventArgs^  e) {

		int count = 0;
		size_t tempStart = 0;
		size_t tempEnd = -2;
		String^ temp;
		string componentInfo;
		//To extract the user input from the input textbox
		string userInput = msclr::interop::marshal_as<string>(inputBox->Text);

		//Clear the input box for next input and set the focus at the beginning of input textbox
		inputBox->Clear();
		inputBox->Select(0, 0);

		//clear the display window for updated tasklist
		DisplayContent->Items->Clear();
		
		//Pass the user input for further actions
		logic.executeUserCommand(userInput);

		//To prepare the display Window with the updated tasklist
		string returnInfo = logic.tellGUI();
		String^ tempString = gcnew String(returnInfo.c_str());

		for (unsigned i = 0; i < returnInfo.size(); i++){

			if (returnInfo.at(i) == ']') {
				count++;
			}
		}
		while (count > 0) {
			/****Index****/
			tempStart = tempEnd + 3;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems = gcnew Windows::Forms::ListViewItem(temp);
			/****Task Name****/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);
			/****Starting Time****/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);
			/****Ending Time***/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);
			/****Status****/
			tempStart = tempEnd + 2;
			tempEnd = returnInfo.find_first_of("]", tempStart);
			componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
			temp = gcnew String(componentInfo.c_str());
			listViewItems->SubItems->Add(temp);


			DisplayContent->Items->Add(this->listViewItems);
			count -= 5;
		}

		//To display feedback or user prompt
		string responseMessage = logic.tellGUIResponse();
		this->SystemResponse->Text = gcnew String(responseMessage.c_str());

	}

	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void feedbackWindow_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
	}

	//To automatically refresh the display Window every 60 seconds
    //The overdue tasks will be updated
    private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
		     int count = 0;
		     size_t tempStart = 0;
		     size_t tempEnd = -2;
		     String^ temp;
		     string componentInfo;

		     logic.refreshStatus();
			 DisplayContent->Items->Clear();
			 string returnInfo = logic.tellGUI();
			 String^ tempString = gcnew String(returnInfo.c_str());

			 for (unsigned i = 0; i < returnInfo.size(); i++){

				 if (returnInfo.at(i) == ']') {
					 count++;
				 }
			 }
			 while (count > 0) {
				 /****Index****/
				 tempStart = tempEnd + 3;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems = gcnew Windows::Forms::ListViewItem(temp);
				 /****Task Name****/
				 tempStart = tempEnd + 2;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Starting Time****/
				 tempStart = tempEnd + 2;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Ending Time***/
				 tempStart = tempEnd + 2;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Status****/
				 tempStart = tempEnd + 2;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);


				 DisplayContent->Items->Add(this->listViewItems);
				 count -= 5;
			 }
	         
    }

    //To display the message box containing information
	//to assist user with command format when help button is clicked
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				   ostringstream instruction;
			       instruction<< "Please read the instructions for supported functionalities below\n"
					   << "and note that the software is case sensitive:\n\n"
					   << "If you are reqired a directory, please specify a directory as following:\n"
					   << "directory; file path you want\n\n"
					   << "Supported commands:\n"
					   << "1.add;task\n"
					   << "2.add;task;start(time);end(time)\n"
					   << "3.add;task(time);end(time)\n"
					   << "4:delete;index\n"
					   << "5.edit;index;task(modified)\n"
					   << "6.edit;index;task(modified);start(modified);end(modified)\n"
					   << "7.edit;index;task(modified);end(modified)\n"
					   << "8.search;keyword\n"
					   << "9.display;all\n"
					   << "10.display;timed\n"
					   << "11.display;floating\n"
					   << "12.display;deadline\n"
					   << "13.display;ongoing\n"
					   << "14.display;done\n"
					   << "15.display;overdue\n"
					   << "16.mark done;index\n"
					   << "17.undo\n"
					   << "18.redo\n"
					   << "Time format supported:\n"
					   << "1852->18:52    1042am->10:42    09:13pm->21:13\n"	
					   << "21:33h->21:33  07.12am->07:12   1544h->15:44\n"
					   << "6/11->06-11-2015  3-12->03-12-2015  5/6/2017->05-06-2017 \n"
					   << "7-9-2018->07-09-2018  6Sep2013->06-11-2013  7sep2013->07-09-2013  8SEP2014->08-09-2013\n"
					   << "3MAY2016 18.43h   6dec2013 0900\n";

				   string format = instruction.str();
				   System::Windows::Forms::MessageBox::Show(gcnew String(format.c_str()));
               }
};
}