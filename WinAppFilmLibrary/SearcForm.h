#pragma once
#include "Movie.h"
#include "Storage.h"

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SearcForm
	/// </summary>
	public ref class SearcForm : public System::Windows::Forms::Form
	{
	public:
		SearcForm(Storage^ sr)
		{
			InitializeComponent();
			this->sr = sr;
			this->list_view_movie = sr->movieList;
			UpdateListView();
			//
			//TODO: добавьте код конструктора
			//
		}
		void UpdateListView();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearcForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView;
		   List<Movie^>^ list_view_movie;
		   Storage^ sr;
	protected:
	private: System::Windows::Forms::ColumnHeader^ Poster;
	private: System::Windows::Forms::ColumnHeader^ Title;
	private: System::Windows::Forms::ColumnHeader^ Data;
	private: System::Windows::Forms::ColumnHeader^ Genre;
	private: System::Windows::Forms::ColumnHeader^ Rating;
	private: System::Windows::Forms::TextBox^ textBox1_Search;
	private: System::Windows::Forms::Button^ button1_Search;
	private: System::Windows::Forms::TextBox^ textBox_RatingFrom;
	private: System::Windows::Forms::TextBox^ textBox_Ratingto;



	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;



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
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Poster = (gcnew System::Windows::Forms::ColumnHeader());
			this->Title = (gcnew System::Windows::Forms::ColumnHeader());
			this->Data = (gcnew System::Windows::Forms::ColumnHeader());
			this->Genre = (gcnew System::Windows::Forms::ColumnHeader());
			this->Rating = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox1_Search = (gcnew System::Windows::Forms::TextBox());
			this->button1_Search = (gcnew System::Windows::Forms::Button());
			this->textBox_RatingFrom = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Ratingto = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView
			// 
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Poster, this->Title,
					this->Data, this->Genre, this->Rating
			});
			this->listView->FullRowSelect = true;
			this->listView->GridLines = true;
			this->listView->HideSelection = false;
			this->listView->Location = System::Drawing::Point(12, 153);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(725, 507);
			this->listView->TabIndex = 1;
			this->listView->UseCompatibleStateImageBehavior = false;
			this->listView->View = System::Windows::Forms::View::Details;
			// 
			// Poster
			// 
			this->Poster->Text = L"Постер";
			this->Poster->Width = 153;
			// 
			// Title
			// 
			this->Title->Text = L"Название";
			this->Title->Width = 147;
			// 
			// Data
			// 
			this->Data->Text = L"Дата выхода в прокат";
			this->Data->Width = 162;
			// 
			// Genre
			// 
			this->Genre->Text = L"Жанр";
			this->Genre->Width = 129;
			// 
			// Rating
			// 
			this->Rating->Text = L"Рейтинг";
			this->Rating->Width = 143;
			// 
			// textBox1_Search
			// 
			this->textBox1_Search->Location = System::Drawing::Point(87, 12);
			this->textBox1_Search->Multiline = true;
			this->textBox1_Search->Name = L"textBox1_Search";
			this->textBox1_Search->Size = System::Drawing::Size(406, 31);
			this->textBox1_Search->TabIndex = 2;
			// 
			// button1_Search
			// 
			this->button1_Search->Location = System::Drawing::Point(543, 12);
			this->button1_Search->Name = L"button1_Search";
			this->button1_Search->Size = System::Drawing::Size(152, 47);
			this->button1_Search->TabIndex = 3;
			this->button1_Search->Text = L"Поиск";
			this->button1_Search->UseVisualStyleBackColor = true;
			this->button1_Search->Click += gcnew System::EventHandler(this, &SearcForm::button1_Search_Click);
			// 
			// textBox_RatingFrom
			// 
			this->textBox_RatingFrom->Location = System::Drawing::Point(81, 109);
			this->textBox_RatingFrom->Name = L"textBox_RatingFrom";
			this->textBox_RatingFrom->Size = System::Drawing::Size(100, 20);
			this->textBox_RatingFrom->TabIndex = 4;
			// 
			// textBox_Ratingto
			// 
			this->textBox_Ratingto->Location = System::Drawing::Point(212, 109);
			this->textBox_Ratingto->Name = L"textBox_Ratingto";
			this->textBox_Ratingto->Size = System::Drawing::Size(100, 20);
			this->textBox_Ratingto->TabIndex = 5;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Checked = false;
			this->dateTimePicker1->CustomFormat = L"\'";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(87, 59);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->ShowCheckBox = true;
			this->dateTimePicker1->Size = System::Drawing::Size(225, 20);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &SearcForm::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(187, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"до";
			// 
			// SearcForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 672);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox_Ratingto);
			this->Controls->Add(this->textBox_RatingFrom);
			this->Controls->Add(this->button1_Search);
			this->Controls->Add(this->textBox1_Search);
			this->Controls->Add(this->listView);
			this->Name = L"SearcForm";
			this->Text = L"SearcForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SearcForm::SearcForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Search_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SearcForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
};
}
