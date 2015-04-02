#pragma once
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <cliext/vector>
#include "Logic.h"
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
	private: System::Windows::Forms::RichTextBox^  feedbackWindow;


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
			this->feedbackWindow = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// comfirmButton
			// 
			this->comfirmButton->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comfirmButton->Location = System::Drawing::Point(488, 24);
			this->comfirmButton->Name = L"comfirmButton";
			this->comfirmButton->Size = System::Drawing::Size(57, 28);
			this->comfirmButton->TabIndex = 1;
			this->comfirmButton->Text = L"Enter";
			this->comfirmButton->UseVisualStyleBackColor = true;
			this->comfirmButton->Click += gcnew System::EventHandler(this, &MyForm::comfirmButton_Click);
			// 
			// inputBox
			// 
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(27, 24);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(456, 28);
			this->inputBox->TabIndex = 0;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &MyForm::inputBox_TextChanged);
			// 
			// SystemResponse
			// 
			this->SystemResponse->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SystemResponse->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->SystemResponse->Location = System::Drawing::Point(24, 309);
			this->SystemResponse->Name = L"SystemResponse";
			this->SystemResponse->Size = System::Drawing::Size(514, 25);
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
			this->DisplayContent->Location = System::Drawing::Point(26, 58);
			this->DisplayContent->Name = L"DisplayContent";
			this->DisplayContent->Size = System::Drawing::Size(512, 248);
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
			this->timer1->Interval = 6000;
			// 
			// feedbackWindow
			// 
			this->feedbackWindow->BackColor = System::Drawing::SystemColors::MenuBar;
			this->feedbackWindow->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->feedbackWindow->Location = System::Drawing::Point(551, 24);
			this->feedbackWindow->Name = L"feedbackWindow";
			this->feedbackWindow->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->feedbackWindow->Size = System::Drawing::Size(373, 311);
			this->feedbackWindow->TabIndex = 6;
			this->feedbackWindow->Text = L"";
			this->feedbackWindow->WordWrap = false;
			this->feedbackWindow->TextChanged += gcnew System::EventHandler(this, &MyForm::feedbackWindow_TextChanged_1);
			// 
			// MyForm
			// 
			this->AcceptButton = this->comfirmButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(946, 347);
			this->Controls->Add(this->feedbackWindow);
			this->Controls->Add(this->DisplayContent);
			this->Controls->Add(this->SystemResponse);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->comfirmButton);
			this->Name = L"MyForm";
			this->Text = L"RushHour";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		this->inputBox->Focus();

		ostringstream instruction;//initialise the feedbackwindow with aceptable inputs
		int count = 0;
		size_t tempStart = 0;
		size_t tempEnd = -2;
		String^ temp;
		string componentInfo;
		logic.checkDirectory();
		instruction << "Please read the instructions for supported functionalities below:\n\n"
			<< "ADD:to add a new task, three types are supported\n"
			<< "1.Floating: add;task\n"
			<< "2.Timed:    add;task;start(time);end(time)\n"
			<< "3.Deadine:  add;task(time);end(time)\n\n"
			<< "Time format supported:\n\n"

			<< "DELETE:to delete a task by specify the index of it in the overall tasklist\n"
			<< "1.delete;index\n\n"

			<< "EDIT:to modify a task by specify the index and the modified information,\nplease note the task type will change accordingly\n"
			<< "1.Type changed to floating:   edit;index;task(modified)\n"
			<< "2.Type changed to timed:      edit;index;task(modified);start(modified);end(modified)\n"
			<< "3.Type changed to deadline:   edit;index;task(modified);end(modified)\n\n"

			<< "SEARCH:to search by keywords\n"
			<< "1.search;keyword\n\n"

			<< "DISPLAY:to adjust the display window \n"
			<< "1.display;all\n"
			<< "2.display;timed\n"
			<< "3.display;floating\n"
			<< "4.display;deadline\n"
			<< "5.display;ongoing\n"
			<< "6.display;done\n"
			<< "7.display;overdue\n\n"

			<< "MARK DONE: to change the status of a task to done by index\n"
			<< "1.mark done;index\n\n"

			<< "UNDO: to undo the previous command\n"
			<< "1.undo\n\n"
			<< "REDO: to undo the previous undo command\n"
			<< "1.redo\n";//initialise the feedbackwindow with aceptable inputs
		string format = instruction.str();


		this->feedbackWindow->Text = gcnew String(format.c_str());
		string response = instruction.str();
		this->feedbackWindow->Text = gcnew String(response.c_str());

		string responseMessage = logic.tellGUIResponse();
		this->SystemResponse->Text = gcnew String(responseMessage.c_str());

		logic.refreshStatus();
		string returnInfo = logic.tellGUI();
		String^ tempString = gcnew String(returnInfo.c_str());

		for (int i = 0; i < returnInfo.size(); i++){

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

	private: System::Void inputBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter) {
			comfirmButton->PerformClick();
		}
	}
	private: System::Void comfirmButton_Click(System::Object^  sender, System::EventArgs^  e) {
		int count = 0;
		size_t tempStart = 0;
		size_t tempEnd = -2;
		String^ temp;
		string componentInfo;
		string userInput = msclr::interop::marshal_as<string>(inputBox->Text);

		inputBox->Clear();
		DisplayContent->Items->Clear();
		inputBox->Select(0, 0);
		logic.executeUserCommand(userInput);
		string returnInfo = logic.tellGUI();
		String^ tempString = gcnew String(returnInfo.c_str());

		for (int i = 0; i < returnInfo.size(); i++){

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


		string responseMessage = logic.tellGUIResponse();
		this->SystemResponse->Text = gcnew String(responseMessage.c_str());

	}

	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void feedbackWindow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		logic.refreshStatus();

	}
	private: System::Void feedbackWindow_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
	}
};
}