#pragma once
#include "Movie.h"
#include "Storage.h"
#include "EditDBForm.h"

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CardForm
	/// </summary>
	public ref class CardForm : public System::Windows::Forms::Form
	{
	public:
		CardForm(int index,Movies^ movies)
		{
			InitializeComponent();
			this->index = index;
			this->movies = movies;
			ShowItem();
			//
			//TODO: добавьте код конструктора
			//
		}
		void ShowItem();
		void DisplayForm();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: int index;
		   Movie^ SuitableMovie;
		   Movies^ movies;
		   EditDBForm^ parent;
		   Bitmap^ img;
		   int count = 0;
	protected:





	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1_Annotation;

	private: System::Windows::Forms::Button^ button1_Change;
	private: System::Windows::Forms::Button^ button1_Save;
	private: System::Windows::Forms::Label^ label1_Genre;
	private: System::Windows::Forms::Label^ label1_Release;
	private: System::Windows::Forms::Label^ label1_Data;
	private: System::Windows::Forms::Label^ label1_Rating;
	private: System::Windows::Forms::Label^ label1_Title;
	private: System::Windows::Forms::TextBox^ textBox1_Rating;
	private: System::Windows::Forms::TextBox^ textBox1_Genre;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox1_Title;
	private: System::Windows::Forms::TextBox^ textBox1_Release;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1_LoadN;
	private: System::Windows::Forms::TextBox^ textBox_Poster;
	private: System::Windows::Forms::Button^ button_Cancel;

	private: System::Windows::Forms::Button^ button1_Close;
	private: System::ComponentModel::IContainer^ components;











	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1_Annotation = (gcnew System::Windows::Forms::Label());
			this->button1_Change = (gcnew System::Windows::Forms::Button());
			this->button1_Save = (gcnew System::Windows::Forms::Button());
			this->label1_Genre = (gcnew System::Windows::Forms::Label());
			this->label1_Release = (gcnew System::Windows::Forms::Label());
			this->label1_Data = (gcnew System::Windows::Forms::Label());
			this->label1_Rating = (gcnew System::Windows::Forms::Label());
			this->label1_Title = (gcnew System::Windows::Forms::Label());
			this->textBox1_Rating = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_Genre = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox1_Title = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_Release = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1_LoadN = (gcnew System::Windows::Forms::Button());
			this->textBox_Poster = (gcnew System::Windows::Forms::TextBox());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button1_Close = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(16, 21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(265, 293);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &CardForm::pictureBox1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Snow;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(16, 403);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(568, 121);
			this->textBox1->TabIndex = 6;
			// 
			// label1_Annotation
			// 
			this->label1_Annotation->AutoSize = true;
			this->label1_Annotation->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Annotation->Location = System::Drawing::Point(12, 378);
			this->label1_Annotation->Name = L"label1_Annotation";
			this->label1_Annotation->Size = System::Drawing::Size(85, 19);
			this->label1_Annotation->TabIndex = 7;
			this->label1_Annotation->Text = L"Аннотация";
			// 
			// button1_Change
			// 
			this->button1_Change->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Change->Location = System::Drawing::Point(618, 24);
			this->button1_Change->Name = L"button1_Change";
			this->button1_Change->Size = System::Drawing::Size(141, 53);
			this->button1_Change->TabIndex = 9;
			this->button1_Change->Text = L"Изменить";
			this->button1_Change->UseVisualStyleBackColor = true;
			this->button1_Change->Click += gcnew System::EventHandler(this, &CardForm::button1_Change_Click);
			// 
			// button1_Save
			// 
			this->button1_Save->Enabled = false;
			this->button1_Save->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Save->Location = System::Drawing::Point(618, 130);
			this->button1_Save->Name = L"button1_Save";
			this->button1_Save->Size = System::Drawing::Size(141, 56);
			this->button1_Save->TabIndex = 10;
			this->button1_Save->Text = L"Сохранить";
			this->button1_Save->UseVisualStyleBackColor = true;
			this->button1_Save->Click += gcnew System::EventHandler(this, &CardForm::button1_Save_Click);
			// 
			// label1_Genre
			// 
			this->label1_Genre->AutoSize = true;
			this->label1_Genre->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Genre->Location = System::Drawing::Point(317, 197);
			this->label1_Genre->Name = L"label1_Genre";
			this->label1_Genre->Size = System::Drawing::Size(47, 19);
			this->label1_Genre->TabIndex = 4;
			this->label1_Genre->Text = L"Жанр";
			// 
			// label1_Release
			// 
			this->label1_Release->AutoSize = true;
			this->label1_Release->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Release->Location = System::Drawing::Point(315, 258);
			this->label1_Release->Name = L"label1_Release";
			this->label1_Release->Size = System::Drawing::Size(48, 19);
			this->label1_Release->TabIndex = 5;
			this->label1_Release->Text = L"Релиз";
			// 
			// label1_Data
			// 
			this->label1_Data->AutoSize = true;
			this->label1_Data->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Data->Location = System::Drawing::Point(317, 130);
			this->label1_Data->Name = L"label1_Data";
			this->label1_Data->Size = System::Drawing::Size(93, 19);
			this->label1_Data->TabIndex = 3;
			this->label1_Data->Text = L"Дата выхода";
			// 
			// label1_Rating
			// 
			this->label1_Rating->AutoSize = true;
			this->label1_Rating->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Rating->Location = System::Drawing::Point(317, 72);
			this->label1_Rating->Name = L"label1_Rating";
			this->label1_Rating->Size = System::Drawing::Size(65, 19);
			this->label1_Rating->TabIndex = 2;
			this->label1_Rating->Text = L"Рейтинг";
			// 
			// label1_Title
			// 
			this->label1_Title->AutoSize = true;
			this->label1_Title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Title->Location = System::Drawing::Point(317, 24);
			this->label1_Title->Name = L"label1_Title";
			this->label1_Title->Size = System::Drawing::Size(73, 19);
			this->label1_Title->TabIndex = 1;
			this->label1_Title->Text = L"Название";
			// 
			// textBox1_Rating
			// 
			this->textBox1_Rating->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Rating->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Rating->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1_Rating->Location = System::Drawing::Point(413, 71);
			this->textBox1_Rating->Name = L"textBox1_Rating";
			this->textBox1_Rating->Size = System::Drawing::Size(161, 25);
			this->textBox1_Rating->TabIndex = 7;
			this->textBox1_Rating->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CardForm::textBox1_Rating_KeyPress);
			// 
			// textBox1_Genre
			// 
			this->textBox1_Genre->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Genre->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Genre->Location = System::Drawing::Point(402, 197);
			this->textBox1_Genre->Name = L"textBox1_Genre";
			this->textBox1_Genre->Size = System::Drawing::Size(172, 25);
			this->textBox1_Genre->TabIndex = 9;
			this->textBox1_Genre->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CardForm::textBox1_Genre_KeyPress);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(413, 130);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(161, 25);
			this->dateTimePicker1->TabIndex = 11;
			// 
			// textBox1_Title
			// 
			this->textBox1_Title->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Title->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1_Title->Location = System::Drawing::Point(413, 21);
			this->textBox1_Title->Name = L"textBox1_Title";
			this->textBox1_Title->Size = System::Drawing::Size(161, 25);
			this->textBox1_Title->TabIndex = 12;
			// 
			// textBox1_Release
			// 
			this->textBox1_Release->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Release->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Release->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1_Release->Location = System::Drawing::Point(402, 258);
			this->textBox1_Release->Name = L"textBox1_Release";
			this->textBox1_Release->Size = System::Drawing::Size(172, 25);
			this->textBox1_Release->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label1->Location = System::Drawing::Point(312, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(272, 311);
			this->label1->TabIndex = 13;
			this->label1->Click += gcnew System::EventHandler(this, &CardForm::label1_Click);
			// 
			// button1_LoadN
			// 
			this->button1_LoadN->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_LoadN->Location = System::Drawing::Point(63, 330);
			this->button1_LoadN->Name = L"button1_LoadN";
			this->button1_LoadN->Size = System::Drawing::Size(197, 31);
			this->button1_LoadN->TabIndex = 14;
			this->button1_LoadN->Text = L"Загрузить";
			this->button1_LoadN->UseVisualStyleBackColor = true;
			this->button1_LoadN->Visible = false;
			this->button1_LoadN->Click += gcnew System::EventHandler(this, &CardForm::button1_LoadN_Click);
			// 
			// textBox_Poster
			// 
			this->textBox_Poster->Location = System::Drawing::Point(413, 294);
			this->textBox_Poster->Name = L"textBox_Poster";
			this->textBox_Poster->Size = System::Drawing::Size(136, 20);
			this->textBox_Poster->TabIndex = 15;
			this->textBox_Poster->Visible = false;
			// 
			// button_Cancel
			// 
			this->button_Cancel->Enabled = false;
			this->button_Cancel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Cancel->Location = System::Drawing::Point(618, 240);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(141, 56);
			this->button_Cancel->TabIndex = 16;
			this->button_Cancel->Text = L"Отменить";
			this->button_Cancel->UseVisualStyleBackColor = true;
			this->button_Cancel->Click += gcnew System::EventHandler(this, &CardForm::button_Cancel_Click);
			// 
			// button1_Close
			// 
			this->button1_Close->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Close->Location = System::Drawing::Point(618, 444);
			this->button1_Close->Name = L"button1_Close";
			this->button1_Close->Size = System::Drawing::Size(141, 56);
			this->button1_Close->TabIndex = 17;
			this->button1_Close->Text = L"Назад";
			this->button1_Close->UseVisualStyleBackColor = true;
			this->button1_Close->Click += gcnew System::EventHandler(this, &CardForm::button1_Close_Click);
			// 
			// CardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(771, 536);
			this->Controls->Add(this->button1_Close);
			this->Controls->Add(this->button_Cancel);
			this->Controls->Add(this->textBox_Poster);
			this->Controls->Add(this->button1_LoadN);
			this->Controls->Add(this->textBox1_Release);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label1_Release);
			this->Controls->Add(this->textBox1_Genre);
			this->Controls->Add(this->textBox1_Title);
			this->Controls->Add(this->button1_Save);
			this->Controls->Add(this->label1_Genre);
			this->Controls->Add(this->button1_Change);
			this->Controls->Add(this->label1_Data);
			this->Controls->Add(this->textBox1_Rating);
			this->Controls->Add(this->label1_Annotation);
			this->Controls->Add(this->label1_Rating);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1_Title);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"CardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"CardForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CardForm::CardForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CardForm::CardForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Change_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Save_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CardForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_LoadN_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CardForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_Rating_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void textBox1_Genre_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void button_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Close_Click(System::Object^ sender, System::EventArgs^ e);
};
}
