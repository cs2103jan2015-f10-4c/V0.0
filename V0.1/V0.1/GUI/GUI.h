#pragma once
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <cliext/vector>
#include "Parser.h"
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
	private: System::Windows::Forms::TextBox^  displayWindow;
	private: System::Windows::Forms::TextBox^  feedbackWindow;



	protected:

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
			this->displayWindow = (gcnew System::Windows::Forms::TextBox());
			this->feedbackWindow = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// comfirmButton
			// 
			this->comfirmButton->Location = System::Drawing::Point(401, 24);
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
			this->inputBox->Size = System::Drawing::Size(357, 21);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &MyForm::inputBox_TextChanged);
			// 
			// displayWindow
			// 
			this->displayWindow->Location = System::Drawing::Point(24, 70);
			this->displayWindow->Multiline = true;
			this->displayWindow->Name = L"displayWindow";
			this->displayWindow->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->displayWindow->Size = System::Drawing::Size(357, 226);
			this->displayWindow->TabIndex = 2;
			this->displayWindow->TextChanged += gcnew System::EventHandler(this, &MyForm::displayWindow_TextChanged);
			// 
			// feedbackWindow
			// 
			this->feedbackWindow->Location = System::Drawing::Point(394, 69);
			this->feedbackWindow->Multiline = true;
			this->feedbackWindow->Name = L"feedbackWindow";
			this->feedbackWindow->Size = System::Drawing::Size(67, 226);
			this->feedbackWindow->TabIndex = 3;
			this->feedbackWindow->TextChanged += gcnew System::EventHandler(this, &MyForm::feedbackWindow_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(491, 308);
			this->Controls->Add(this->feedbackWindow);
			this->Controls->Add(this->displayWindow);
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
		     this->feedbackWindow->Text = "Hello Jim. Welcome to RushHour!\r\n\r\nWhat would you like to do?";
	}

	private: System::Void inputBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		     if (e->KeyCode == Keys::Enter) {
			 comfirmButton->PerformClick();
		}
	}
	private: System::Void comfirmButton_Click(System::Object^  sender, System::EventArgs^  e) {
		     string userInput = msclr::interop::marshal_as<string>(inputBox->Text);
		     inputBox -> Clear();
		     Parser::determineCommand(userInput);
		     string displayString = Feedback::getDisplay();// to be changed 
		     //string responseString = Feedback::getResponse();
		    // textBox3->Text = msclr::interop::marshal_as<String^>(responseString);
		     ->Text = msclr::interop::marshal_as<String^>(displayString);//
	}
	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
    }
	private: System::Void feedbackWindow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void displayWindow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
