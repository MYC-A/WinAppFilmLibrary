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
		InsertForm(EditDBForm^ editForm, Storage^ sr)
		{
			InitializeComponent();
			this->editForm = editForm;
			this->sr = sr;
			//
			//TODO: добавьте код конструктора
			//
		}

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
		EditDBForm^ editForm;
		Storage^ sr;

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
			this->SuspendLayout();
			// 
			// label_Poster
			// 
			this->label_Poster->AutoSize = true;
			this->label_Poster->Location = System::Drawing::Point(66, 40);
			this->label_Poster->Name = L"label_Poster";
			this->label_Poster->Size = System::Drawing::Size(44, 13);
			this->label_Poster->TabIndex = 0;
			this->label_Poster->Text = L"Постер";
			// 
			// label_Title
			// 
			this->label_Title->AutoSize = true;
			this->label_Title->Location = System::Drawing::Point(66, 88);
			this->label_Title->Name = L"label_Title";
			this->label_Title->Size = System::Drawing::Size(57, 13);
			this->label_Title->TabIndex = 1;
			this->label_Title->Text = L"Название";
			// 
			// label_Data
			// 
			this->label_Data->AutoSize = true;
			this->label_Data->Location = System::Drawing::Point(66, 130);
			this->label_Data->Name = L"label_Data";
			this->label_Data->Size = System::Drawing::Size(73, 13);
			this->label_Data->TabIndex = 2;
			this->label_Data->Text = L"Дата выхода";
			// 
			// label_Genre
			// 
			this->label_Genre->AutoSize = true;
			this->label_Genre->Location = System::Drawing::Point(66, 174);
			this->label_Genre->Name = L"label_Genre";
			this->label_Genre->Size = System::Drawing::Size(36, 13);
			this->label_Genre->TabIndex = 3;
			this->label_Genre->Text = L"Жанр";
			// 
			// label_Rating
			// 
			this->label_Rating->AutoSize = true;
			this->label_Rating->Location = System::Drawing::Point(66, 210);
			this->label_Rating->Name = L"label_Rating";
			this->label_Rating->Size = System::Drawing::Size(48, 13);
			this->label_Rating->TabIndex = 4;
			this->label_Rating->Text = L"Рейтинг";
			// 
			// textBox_Annotation
			// 
			this->textBox_Annotation->Location = System::Drawing::Point(158, 251);
			this->textBox_Annotation->Multiline = true;
			this->textBox_Annotation->Name = L"textBox_Annotation";
			this->textBox_Annotation->Size = System::Drawing::Size(356, 98);
			this->textBox_Annotation->TabIndex = 5;
			// 
			// label_Annotation
			// 
			this->label_Annotation->AutoSize = true;
			this->label_Annotation->Location = System::Drawing::Point(66, 254);
			this->label_Annotation->Name = L"label_Annotation";
			this->label_Annotation->Size = System::Drawing::Size(61, 13);
			this->label_Annotation->TabIndex = 6;
			this->label_Annotation->Text = L"Аннотация";
			// 
			// textBox_Poster
			// 
			this->textBox_Poster->Location = System::Drawing::Point(167, 37);
			this->textBox_Poster->Name = L"textBox_Poster";
			this->textBox_Poster->Size = System::Drawing::Size(100, 20);
			this->textBox_Poster->TabIndex = 7;
			// 
			// textBox_Title
			// 
			this->textBox_Title->Location = System::Drawing::Point(167, 88);
			this->textBox_Title->Name = L"textBox_Title";
			this->textBox_Title->Size = System::Drawing::Size(100, 20);
			this->textBox_Title->TabIndex = 8;
			// 
			// textBox_Genre
			// 
			this->textBox_Genre->Location = System::Drawing::Point(167, 167);
			this->textBox_Genre->Name = L"textBox_Genre";
			this->textBox_Genre->Size = System::Drawing::Size(100, 20);
			this->textBox_Genre->TabIndex = 9;
			// 
			// textBox_Rating
			// 
			this->textBox_Rating->Location = System::Drawing::Point(167, 207);
			this->textBox_Rating->Name = L"textBox_Rating";
			this->textBox_Rating->Size = System::Drawing::Size(100, 20);
			this->textBox_Rating->TabIndex = 10;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(167, 130);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 11;
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(54, 368);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(101, 40);
			this->button_Save->TabIndex = 12;
			this->button_Save->Text = L"Сохранить";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &InsertForm::button_Save_Click);
			// 
			// button_Clear
			// 
			this->button_Clear->Location = System::Drawing::Point(478, 368);
			this->button_Clear->Name = L"button_Clear";
			this->button_Clear->Size = System::Drawing::Size(101, 40);
			this->button_Clear->TabIndex = 14;
			this->button_Clear->Text = L"Отменить";
			this->button_Clear->UseVisualStyleBackColor = true;
			// 
			// InsertForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(605, 420);
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
			this->Text = L"InsertForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Save_Click(System::Object^ sender, System::EventArgs^ e);
};
}
