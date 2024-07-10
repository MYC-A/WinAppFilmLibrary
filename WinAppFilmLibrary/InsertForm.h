#pragma once
#include "EditDBForm.h"

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для InsertForm
	/// </summary>
	public ref class InsertForm : public System::Windows::Forms::Form
	{
	public:
		InsertForm()
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		bool checking_for_occupancy();


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~InsertForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		EditDBForm^ parent;
		int count = 0;
		Bitmap^ img; //

	private: System::Windows::Forms::Label^ label_Poster;
	private: System::Windows::Forms::Label^ label_Title;
	private: System::Windows::Forms::Label^ label_Data;
	private: System::Windows::Forms::Label^ label_Genre;
	private: System::Windows::Forms::Label^ label_Rating;
	private: System::Windows::Forms::TextBox^ textBox_Annotation;

	private: System::Windows::Forms::Label^ label_Annotation;
	private: System::Windows::Forms::TextBox^ textBox_Poster;
	private: System::Windows::Forms::TextBox^ textBox_Title;
	private: System::Windows::Forms::TextBox^ textBox_Genre;
	private: System::Windows::Forms::TextBox^ textBox_Rating;




	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Button^ button_Save;
	private: System::Windows::Forms::Button^ button_Clear;
	private: System::Windows::Forms::PictureBox^ pictureBox1_Poster;
	private: System::Windows::Forms::Button^ button1_Load;
	private: System::Windows::Forms::Button^ button_Close;
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
			this->label_Poster = (gcnew System::Windows::Forms::Label());
			this->label_Title = (gcnew System::Windows::Forms::Label());
			this->label_Data = (gcnew System::Windows::Forms::Label());
			this->label_Genre = (gcnew System::Windows::Forms::Label());
			this->label_Rating = (gcnew System::Windows::Forms::Label());
			this->textBox_Annotation = (gcnew System::Windows::Forms::TextBox());
			this->label_Annotation = (gcnew System::Windows::Forms::Label());
			this->textBox_Poster = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Title = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Genre = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Rating = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->button_Clear = (gcnew System::Windows::Forms::Button());
			this->pictureBox1_Poster = (gcnew System::Windows::Forms::PictureBox());
			this->button1_Load = (gcnew System::Windows::Forms::Button());
			this->button_Close = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_Poster))->BeginInit();
			this->SuspendLayout();
			// 
			// label_Poster
			// 
			this->label_Poster->AutoSize = true;
			this->label_Poster->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Poster->Location = System::Drawing::Point(53, 57);
			this->label_Poster->Name = L"label_Poster";
			this->label_Poster->Size = System::Drawing::Size(68, 21);
			this->label_Poster->TabIndex = 0;
			this->label_Poster->Text = L"Постер";
			// 
			// label_Title
			// 
			this->label_Title->AutoSize = true;
			this->label_Title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Title->Location = System::Drawing::Point(37, 202);
			this->label_Title->Name = L"label_Title";
			this->label_Title->Size = System::Drawing::Size(84, 21);
			this->label_Title->TabIndex = 1;
			this->label_Title->Text = L"Название";
			// 
			// label_Data
			// 
			this->label_Data->AutoSize = true;
			this->label_Data->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Data->Location = System::Drawing::Point(12, 246);
			this->label_Data->Name = L"label_Data";
			this->label_Data->Size = System::Drawing::Size(109, 21);
			this->label_Data->TabIndex = 2;
			this->label_Data->Text = L"Дата выхода";
			// 
			// label_Genre
			// 
			this->label_Genre->AutoSize = true;
			this->label_Genre->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Genre->Location = System::Drawing::Point(66, 282);
			this->label_Genre->Name = L"label_Genre";
			this->label_Genre->Size = System::Drawing::Size(55, 21);
			this->label_Genre->TabIndex = 3;
			this->label_Genre->Text = L"Жанр";
			// 
			// label_Rating
			// 
			this->label_Rating->AutoSize = true;
			this->label_Rating->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Rating->Location = System::Drawing::Point(46, 322);
			this->label_Rating->Name = L"label_Rating";
			this->label_Rating->Size = System::Drawing::Size(75, 21);
			this->label_Rating->TabIndex = 4;
			this->label_Rating->Text = L"Рейтинг";
			// 
			// textBox_Annotation
			// 
			this->textBox_Annotation->Location = System::Drawing::Point(127, 376);
			this->textBox_Annotation->Multiline = true;
			this->textBox_Annotation->Name = L"textBox_Annotation";
			this->textBox_Annotation->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox_Annotation->Size = System::Drawing::Size(441, 98);
			this->textBox_Annotation->TabIndex = 5;
			this->textBox_Annotation->TextChanged += gcnew System::EventHandler(this, &InsertForm::textBox_Annotation_TextChanged);
			// 
			// label_Annotation
			// 
			this->label_Annotation->AutoSize = true;
			this->label_Annotation->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Annotation->Location = System::Drawing::Point(23, 411);
			this->label_Annotation->Name = L"label_Annotation";
			this->label_Annotation->Size = System::Drawing::Size(98, 21);
			this->label_Annotation->TabIndex = 6;
			this->label_Annotation->Text = L"Аннотация";
			// 
			// textBox_Poster
			// 
			this->textBox_Poster->Location = System::Drawing::Point(156, 37);
			this->textBox_Poster->Name = L"textBox_Poster";
			this->textBox_Poster->Size = System::Drawing::Size(100, 20);
			this->textBox_Poster->TabIndex = 7;
			this->textBox_Poster->Visible = false;
			// 
			// textBox_Title
			// 
			this->textBox_Title->Location = System::Drawing::Point(127, 202);
			this->textBox_Title->Name = L"textBox_Title";
			this->textBox_Title->Size = System::Drawing::Size(200, 20);
			this->textBox_Title->TabIndex = 8;
			// 
			// textBox_Genre
			// 
			this->textBox_Genre->Location = System::Drawing::Point(127, 283);
			this->textBox_Genre->Name = L"textBox_Genre";
			this->textBox_Genre->Size = System::Drawing::Size(200, 20);
			this->textBox_Genre->TabIndex = 9;
			this->textBox_Genre->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InsertForm::textBox_Genre_KeyPress);
			// 
			// textBox_Rating
			// 
			this->textBox_Rating->Location = System::Drawing::Point(127, 322);
			this->textBox_Rating->Name = L"textBox_Rating";
			this->textBox_Rating->Size = System::Drawing::Size(195, 20);
			this->textBox_Rating->TabIndex = 10;
			this->textBox_Rating->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InsertForm::textBox_Rating_KeyPress);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(127, 245);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 11;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &InsertForm::dateTimePicker1_ValueChanged);
			// 
			// button_Save
			// 
			this->button_Save->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Save->Location = System::Drawing::Point(543, 20);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(131, 58);
			this->button_Save->TabIndex = 12;
			this->button_Save->Text = L"Сохранить";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &InsertForm::button_Save_Click);
			// 
			// button_Clear
			// 
			this->button_Clear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Clear->Location = System::Drawing::Point(543, 123);
			this->button_Clear->Name = L"button_Clear";
			this->button_Clear->Size = System::Drawing::Size(131, 58);
			this->button_Clear->TabIndex = 14;
			this->button_Clear->Text = L"Отменить";
			this->button_Clear->UseVisualStyleBackColor = true;
			this->button_Clear->Click += gcnew System::EventHandler(this, &InsertForm::button_Clear_Click);
			// 
			// pictureBox1_Poster
			// 
			this->pictureBox1_Poster->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1_Poster->Location = System::Drawing::Point(127, 12);
			this->pictureBox1_Poster->Name = L"pictureBox1_Poster";
			this->pictureBox1_Poster->Size = System::Drawing::Size(200, 132);
			this->pictureBox1_Poster->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1_Poster->TabIndex = 15;
			this->pictureBox1_Poster->TabStop = false;
			// 
			// button1_Load
			// 
			this->button1_Load->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Load->Location = System::Drawing::Point(156, 150);
			this->button1_Load->Name = L"button1_Load";
			this->button1_Load->Size = System::Drawing::Size(116, 31);
			this->button1_Load->TabIndex = 16;
			this->button1_Load->Text = L"Загрузить";
			this->button1_Load->UseVisualStyleBackColor = true;
			this->button1_Load->Click += gcnew System::EventHandler(this, &InsertForm::button1_Load_Click);
			// 
			// button_Close
			// 
			this->button_Close->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Close->Location = System::Drawing::Point(553, 480);
			this->button_Close->Name = L"button_Close";
			this->button_Close->Size = System::Drawing::Size(131, 58);
			this->button_Close->TabIndex = 17;
			this->button_Close->Text = L"Назад";
			this->button_Close->UseVisualStyleBackColor = true;
			this->button_Close->Click += gcnew System::EventHandler(this, &InsertForm::button_Close_Click);
			// 
			// InsertForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 541);
			this->Controls->Add(this->button_Close);
			this->Controls->Add(this->button1_Load);
			this->Controls->Add(this->pictureBox1_Poster);
			this->Controls->Add(this->button_Clear);
			this->Controls->Add(this->button_Save);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox_Rating);
			this->Controls->Add(this->textBox_Genre);
			this->Controls->Add(this->textBox_Title);
			this->Controls->Add(this->textBox_Poster);
			this->Controls->Add(this->label_Annotation);
			this->Controls->Add(this->textBox_Annotation);
			this->Controls->Add(this->label_Rating);
			this->Controls->Add(this->label_Genre);
			this->Controls->Add(this->label_Data);
			this->Controls->Add(this->label_Title);
			this->Controls->Add(this->label_Poster);
			this->Name = L"InsertForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"InsertForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &InsertForm::InsertForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &InsertForm::InsertForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_Poster))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Save_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox_Annotation_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void InsertForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void InsertForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox_Rating_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void textBox_Genre_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void button_Clear_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Close_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
};
}
