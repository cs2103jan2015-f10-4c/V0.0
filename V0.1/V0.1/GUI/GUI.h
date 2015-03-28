#pragma once
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <cliext/vector>
#include "Logic.h"
#include "Storage.h"
#include "DisplayWindow.h"
#using <mscorlib.dll>

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

	private: System::Windows::Forms::TextBox^  feedbackWindow;
	private: System::Windows::Forms::Label^  SystemResponse;
	private: System::Windows::Forms::ListView^  DisplayContent;

	private: System::Windows::Forms::ColumnHeader^  Index;
	private: System::Windows::Forms::ColumnHeader^  TaskName;
	private: System::Windows::Forms::ColumnHeader^  Start;
	private: System::Windows::Forms::ColumnHeader^  End;
	private: System::Windows::Forms::ColumnHeader^  Status;
    
   
	protected:System::Windows::Forms::ListViewItem^ listViewItems;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comfirmButton = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->feedbackWindow = (gcnew System::Windows::Forms::TextBox());
			this->SystemResponse = (gcnew System::Windows::Forms::Label());
			this->DisplayContent = (gcnew System::Windows::Forms::ListView());
			this->Index = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskName = (gcnew System::Windows::Forms::ColumnHeader());
			this->Start = (gcnew System::Windows::Forms::ColumnHeader());
			this->End = (gcnew System::Windows::Forms::ColumnHeader());
			this->Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// comfirmButton
			// 
			this->comfirmButton->Location = System::Drawing::Point(667, 24);
			this->comfirmButton->Name = L"comfirmButton";
			this->comfirmButton->Size = System::Drawing::Size(60, 21);
			this->comfirmButton->TabIndex = 0;
			this->comfirmButton->Text = L"Enter";
			this->comfirmButton->UseVisualStyleBackColor = true;
			this->comfirmButton->Click += gcnew System::EventHandler(this, &MyForm::comfirmButton_Click);
			// 
			// inputBox
			// 
			this->inputBox->Location = System::Drawing::Point(24, 24);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(637, 21);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &MyForm::inputBox_TextChanged);
			// 
			// feedbackWindow
			// 
			this->feedbackWindow->Location = System::Drawing::Point(544, 69);
			this->feedbackWindow->Multiline = true;
			this->feedbackWindow->Name = L"feedbackWindow";
			this->feedbackWindow->Size = System::Drawing::Size(183, 237);
			this->feedbackWindow->TabIndex = 3;
			this->feedbackWindow->TextChanged += gcnew System::EventHandler(this, &MyForm::feedbackWindow_TextChanged);
			// 
			// SystemResponse
			// 
			this->SystemResponse->AutoSize = true;
			this->SystemResponse->Location = System::Drawing::Point(24, 309);
			this->SystemResponse->Name = L"SystemResponse";
			this->SystemResponse->Size = System::Drawing::Size(89, 12);
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
			this->DisplayContent->FullRowSelect = true;
			this->DisplayContent->GridLines = true;
			this->DisplayContent->Location = System::Drawing::Point(26, 69);
			this->DisplayContent->Name = L"DisplayContent";
			this->DisplayContent->Size = System::Drawing::Size(512, 237);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 343);
			this->Controls->Add(this->DisplayContent);
			this->Controls->Add(this->SystemResponse);
			this->Controls->Add(this->feedbackWindow);
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

		     string instruction;//initialise the feedbackwindow with aceptable inputs
			 int count = 0;
			 size_t tempStart=0;
			 size_t tempEnd=0;
			 String^ temp;
			 string componentInfo;
			// storage.readFile(); Logic loadfile to be added;
	
		     this->SystemResponse->Text = "Hello Jim. Welcome to RushHour!\r\n\r\nWhat would you like to do?";
			 this->feedbackWindow->Text = gcnew String(instruction.c_str());
			 string returnInfo = Logic::tellGUI();
			 String^ tempString = gcnew String(returnInfo.c_str());

			 for (int i = 0; i < returnInfo.size(); i++){

				 if (returnInfo.at(i) == ']') {
					 count++;
				 }
			 }
			 while (count > 0) {
				 /****Index****/		
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems = gcnew Windows::Forms::ListViewItem(temp);
				 /****Task Name****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Starting Time****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Ending Time***/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Status****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				

				DisplayContent->Items->Add(this->listViewItems);
				count -=5 ;
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
		     size_t tempEnd = 0;
		     String^ temp;
		     string componentInfo;
		     string userInput = msclr::interop::marshal_as<string>(inputBox->Text);

		     inputBox -> Clear();
			 DisplayContent->Items->Clear();

		     Logic::executeUserCommand(userInput);
			 string returnInfo = Logic::tellGUI();
			 String^ tempString = gcnew String(returnInfo.c_str());
			 
			 for (int i = 0; i < returnInfo.size(); i++){

				 if (returnInfo.at(i) == ']') {
					 count++;
				 }
			 }
			 while (count > 0) {
				 /****Index****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems = gcnew Windows::Forms::ListViewItem(temp);
				 /****Task Name****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Starting Time****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Ending Time***/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);
				 /****Status****/
				 tempStart = tempEnd + 1;
				 tempEnd = returnInfo.find_first_of("]", tempStart);
				 componentInfo = returnInfo.substr(tempStart, tempEnd - tempStart);
				 temp = gcnew String(componentInfo.c_str());
				 listViewItems->SubItems->Add(temp);


				 DisplayContent->Items->Add(this->listViewItems);
				 count -= 5;
			 }


			 

	}
	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
    }
	private: System::Void feedbackWindow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
    private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
    }
    private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
    }
};
}
