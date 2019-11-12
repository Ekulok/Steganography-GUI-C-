#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

namespace SteganographyGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Reflection;


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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;


	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(188, 238);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 89);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Input Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(594, 58);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(568, 444);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(188, 652);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 89);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Get Text";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(594, 552);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(568, 288);
			this->textBox1->TabIndex = 3;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 1051);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Steganography";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// do your stuff
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;
	OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog;

	openFileDialog2->InitialDirectory = "c:\\";
	openFileDialog2->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog2->FilterIndex = 2;
	openFileDialog2->RestoreDirectory = true;

	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// do your stuff
		if ((myStream = openFileDialog2->OpenFile()) != nullptr)
		{
			String^ strfilename = openFileDialog2->InitialDirectory + openFileDialog2->FileName;
			//String^ Readfile = File::ReadAllText(strfilename);
			
			try
			{
				// a StreamReader is like ifstream
				StreamReader^ DataIn = File::OpenText(strfilename); // we go to the catch block if error
				// definitions
				String^ DataStr;
				int count = 0;
				//array will contain the results of the DataStr split
				array<String^>^ result;
				//the string Split method needs an array of chars to split on
				//in this case, we have an array of only 1 char: the blank.
				array<Char>^ separ = gcnew array<Char>{' '};
				//we read a line of our file and put it in DataStr as long as it is not equal to null
				while ((DataStr = DataIn->ReadLine()) != nullptr)
				{
					count++; //Linecount in the file
					// MessageBox, just for testing if we read the line successfully
					// or set a breakpoint and watch it in the debugger
					MessageBox::Show("Line " + count + " " + DataStr);
					//split the line
					result = DataStr->Split(separ);
					// if line 1 of the testfile is read, result[0] will contain "Item"
					// result[1] will be "20" etc. see also the debug picture
				}
			}
			catch (Exception ^ e)
			{
				if (dynamic_cast<FileNotFoundException^>(e))
					MessageBox::Show("File " + strfilename + " not found");
			}
		
		
				myStream->Close();
		}
	}
	}
	};
}
