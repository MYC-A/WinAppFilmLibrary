#pragma once
#include "SearcForm.h"

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CardView
	/// </summary>
	public ref class CardView : public System::Windows::Forms::Form
	{
	public:
		CardView(int index)
		{
			InitializeComponent();
			this->index = index;
			//
			//TODO: добавьте код конструктора
			//
		}
		void ShowItem();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CardView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int index;
		   Movie^ SuitableMovie; // выбранный фильм
		   SearcForm^ parent; // Переменная для формы родителя
		   Bitmap^ img;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label1_Release;
	private: System::Windows::Forms::TextBox^ textBox1_Genre;
	private: System::Windows::Forms::TextBox^ textBox1_Title;
	private: System::Windows::Forms::Label^ label1_Genre;
	private: System::Windows::Forms::Label^ label1_Data;
	private: System::Windows::Forms::TextBox^ textBox1_Rating;
	private: System::Windows::Forms::Label^ label1_Rating;
	private: System::Windows::Forms::Label^ label1_Title;
	private: System::Windows::Forms::TextBox^ textBox_Poster;
	private: System::Windows::Forms::Button^ button1_Close;
	private: System::Windows::Forms::Label^ label1_Annotation;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox1_Release;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1_Release = (gcnew System::Windows::Forms::Label());
			this->textBox1_Genre = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_Title = (gcnew System::Windows::Forms::TextBox());
			this->label1_Genre = (gcnew System::Windows::Forms::Label());
			this->label1_Data = (gcnew System::Windows::Forms::Label());
			this->textBox1_Rating = (gcnew System::Windows::Forms::TextBox());
			this->label1_Rating = (gcnew System::Windows::Forms::Label());
			this->label1_Title = (gcnew System::Windows::Forms::Label());
			this->textBox_Poster = (gcnew System::Windows::Forms::TextBox());
			this->button1_Close = (gcnew System::Windows::Forms::Button());
			this->label1_Annotation = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1_Release = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(265, 293);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label1->Location = System::Drawing::Point(298, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(302, 311);
			this->label1->TabIndex = 14;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(419, 130);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(172, 25);
			this->dateTimePicker1->TabIndex = 23;
			// 
			// label1_Release
			// 
			this->label1_Release->AutoSize = true;
			this->label1_Release->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Release->Location = System::Drawing::Point(321, 258);
			this->label1_Release->Name = L"label1_Release";
			this->label1_Release->Size = System::Drawing::Size(48, 19);
			this->label1_Release->TabIndex = 19;
			this->label1_Release->Text = L"Релиз";
			// 
			// textBox1_Genre
			// 
			this->textBox1_Genre->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Genre->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Genre->Location = System::Drawing::Point(408, 197);
			this->textBox1_Genre->Name = L"textBox1_Genre";
			this->textBox1_Genre->ReadOnly = true;
			this->textBox1_Genre->Size = System::Drawing::Size(183, 25);
			this->textBox1_Genre->TabIndex = 21;
			// 
			// textBox1_Title
			// 
			this->textBox1_Title->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Title->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1_Title->Location = System::Drawing::Point(419, 21);
			this->textBox1_Title->Name = L"textBox1_Title";
			this->textBox1_Title->ReadOnly = true;
			this->textBox1_Title->Size = System::Drawing::Size(172, 25);
			this->textBox1_Title->TabIndex = 24;
			// 
			// label1_Genre
			// 
			this->label1_Genre->AutoSize = true;
			this->label1_Genre->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Genre->Location = System::Drawing::Point(323, 197);
			this->label1_Genre->Name = L"label1_Genre";
			this->label1_Genre->Size = System::Drawing::Size(47, 19);
			this->label1_Genre->TabIndex = 18;
			this->label1_Genre->Text = L"Жанр";
			// 
			// label1_Data
			// 
			this->label1_Data->AutoSize = true;
			this->label1_Data->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Data->Location = System::Drawing::Point(323, 130);
			this->label1_Data->Name = L"label1_Data";
			this->label1_Data->Size = System::Drawing::Size(93, 19);
			this->label1_Data->TabIndex = 17;
			this->label1_Data->Text = L"Дата выхода";
			// 
			// textBox1_Rating
			// 
			this->textBox1_Rating->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Rating->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Rating->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1_Rating->Location = System::Drawing::Point(419, 71);
			this->textBox1_Rating->Name = L"textBox1_Rating";
			this->textBox1_Rating->ReadOnly = true;
			this->textBox1_Rating->Size = System::Drawing::Size(172, 25);
			this->textBox1_Rating->TabIndex = 20;
			// 
			// label1_Rating
			// 
			this->label1_Rating->AutoSize = true;
			this->label1_Rating->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Rating->Location = System::Drawing::Point(323, 72);
			this->label1_Rating->Name = L"label1_Rating";
			this->label1_Rating->Size = System::Drawing::Size(65, 19);
			this->label1_Rating->TabIndex = 16;
			this->label1_Rating->Text = L"Рейтинг";
			// 
			// label1_Title
			// 
			this->label1_Title->AutoSize = true;
			this->label1_Title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Title->Location = System::Drawing::Point(323, 24);
			this->label1_Title->Name = L"label1_Title";
			this->label1_Title->Size = System::Drawing::Size(73, 19);
			this->label1_Title->TabIndex = 15;
			this->label1_Title->Text = L"Название";
			// 
			// textBox_Poster
			// 
			this->textBox_Poster->Location = System::Drawing::Point(408, 289);
			this->textBox_Poster->Name = L"textBox_Poster";
			this->textBox_Poster->Size = System::Drawing::Size(136, 20);
			this->textBox_Poster->TabIndex = 25;
			this->textBox_Poster->Visible = false;
			// 
			// button1_Close
			// 
			this->button1_Close->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Close->Location = System::Drawing::Point(627, 12);
			this->button1_Close->Name = L"button1_Close";
			this->button1_Close->Size = System::Drawing::Size(109, 56);
			this->button1_Close->TabIndex = 28;
			this->button1_Close->Text = L"Назад";
			this->button1_Close->UseVisualStyleBackColor = true;
			this->button1_Close->Click += gcnew System::EventHandler(this, &CardView::button1_Close_Click);
			// 
			// label1_Annotation
			// 
			this->label1_Annotation->AutoSize = true;
			this->label1_Annotation->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Annotation->Location = System::Drawing::Point(8, 357);
			this->label1_Annotation->Name = L"label1_Annotation";
			this->label1_Annotation->Size = System::Drawing::Size(85, 19);
			this->label1_Annotation->TabIndex = 27;
			this->label1_Annotation->Text = L"Аннотация";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Snow;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 382);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(579, 121);
			this->textBox1->TabIndex = 26;
			// 
			// textBox1_Release
			// 
			this->textBox1_Release->BackColor = System::Drawing::Color::Snow;
			this->textBox1_Release->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_Release->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox1_Release->Location = System::Drawing::Point(408, 258);
			this->textBox1_Release->Name = L"textBox1_Release";
			this->textBox1_Release->ReadOnly = true;
			this->textBox1_Release->Size = System::Drawing::Size(183, 25);
			this->textBox1_Release->TabIndex = 22;
			// 
			// CardView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 515);
			this->Controls->Add(this->button1_Close);
			this->Controls->Add(this->label1_Annotation);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox_Poster);
			this->Controls->Add(this->textBox1_Release);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label1_Release);
			this->Controls->Add(this->textBox1_Genre);
			this->Controls->Add(this->textBox1_Title);
			this->Controls->Add(this->label1_Genre);
			this->Controls->Add(this->label1_Data);
			this->Controls->Add(this->textBox1_Rating);
			this->Controls->Add(this->label1_Rating);
			this->Controls->Add(this->label1_Title);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"CardView";
			this->Text = L"CardView";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CardView::CardView_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CardView::CardView_Load);
			this->Leave += gcnew System::EventHandler(this, &CardView::CardView_Leave);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CardView_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void CardView_Leave(System::Object^ sender, System::EventArgs^ e);
private: System::Void CardView_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void button1_Close_Click(System::Object^ sender, System::EventArgs^ e);

};
}
