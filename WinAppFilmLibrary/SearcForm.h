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
		SearcForm(Movies^ movies)
		{
			InitializeComponent();
			this->movies = movies;
			this->list_view_movie = movies->getmovieList();
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
		   Movies^ movies;
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
	private: System::Windows::Forms::Label^ label1_Title;
	private: System::Windows::Forms::Label^ label2_Data;
	private: System::Windows::Forms::Label^ label3_Rating;
	private: System::Windows::Forms::Label^ label_to;







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
			this->label1_Title = (gcnew System::Windows::Forms::Label());
			this->label2_Data = (gcnew System::Windows::Forms::Label());
			this->label3_Rating = (gcnew System::Windows::Forms::Label());
			this->label_to = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView
			// 
			this->listView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Poster, this->Title,
					this->Data, this->Genre, this->Rating
			});
			this->listView->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listView->FullRowSelect = true;
			this->listView->GridLines = true;
			this->listView->HideSelection = false;
			this->listView->Location = System::Drawing::Point(1, 160);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(1100, 573);
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
			this->textBox1_Search->Location = System::Drawing::Point(125, 15);
			this->textBox1_Search->Multiline = true;
			this->textBox1_Search->Name = L"textBox1_Search";
			this->textBox1_Search->Size = System::Drawing::Size(406, 31);
			this->textBox1_Search->TabIndex = 2;
			// 
			// button1_Search
			// 
			this->button1_Search->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Search->Location = System::Drawing::Point(590, 12);
			this->button1_Search->Name = L"button1_Search";
			this->button1_Search->Size = System::Drawing::Size(152, 47);
			this->button1_Search->TabIndex = 3;
			this->button1_Search->Text = L"Поиск";
			this->button1_Search->UseVisualStyleBackColor = true;
			this->button1_Search->Click += gcnew System::EventHandler(this, &SearcForm::button1_Search_Click);
			// 
			// textBox_RatingFrom
			// 
			this->textBox_RatingFrom->Location = System::Drawing::Point(125, 110);
			this->textBox_RatingFrom->Name = L"textBox_RatingFrom";
			this->textBox_RatingFrom->Size = System::Drawing::Size(100, 20);
			this->textBox_RatingFrom->TabIndex = 4;
			// 
			// textBox_Ratingto
			// 
			this->textBox_Ratingto->Location = System::Drawing::Point(272, 110);
			this->textBox_Ratingto->Name = L"textBox_Ratingto";
			this->textBox_Ratingto->Size = System::Drawing::Size(100, 20);
			this->textBox_Ratingto->TabIndex = 5;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Checked = false;
			this->dateTimePicker1->CustomFormat = L"\'";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(125, 63);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->ShowCheckBox = true;
			this->dateTimePicker1->Size = System::Drawing::Size(247, 20);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &SearcForm::dateTimePicker1_ValueChanged);
			// 
			// label1_Title
			// 
			this->label1_Title->AutoSize = true;
			this->label1_Title->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_Title->Location = System::Drawing::Point(4, 15);
			this->label1_Title->Name = L"label1_Title";
			this->label1_Title->Size = System::Drawing::Size(93, 23);
			this->label1_Title->TabIndex = 7;
			this->label1_Title->Text = L"Название";
			// 
			// label2_Data
			// 
			this->label2_Data->AutoSize = true;
			this->label2_Data->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2_Data->Location = System::Drawing::Point(4, 60);
			this->label2_Data->Name = L"label2_Data";
			this->label2_Data->Size = System::Drawing::Size(115, 23);
			this->label2_Data->TabIndex = 8;
			this->label2_Data->Text = L"Дата выхода";
			// 
			// label3_Rating
			// 
			this->label3_Rating->AutoSize = true;
			this->label3_Rating->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3_Rating->Location = System::Drawing::Point(4, 107);
			this->label3_Rating->Name = L"label3_Rating";
			this->label3_Rating->Size = System::Drawing::Size(81, 23);
			this->label3_Rating->TabIndex = 9;
			this->label3_Rating->Text = L"Рейтинг";
			// 
			// label_to
			// 
			this->label_to->AutoSize = true;
			this->label_to->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_to->Location = System::Drawing::Point(236, 107);
			this->label_to->Name = L"label_to";
			this->label_to->Size = System::Drawing::Size(30, 23);
			this->label_to->TabIndex = 10;
			this->label_to->Text = L"до";
			// 
			// SearcForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1094, 726);
			this->Controls->Add(this->label_to);
			this->Controls->Add(this->label3_Rating);
			this->Controls->Add(this->label2_Data);
			this->Controls->Add(this->label1_Title);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox_Ratingto);
			this->Controls->Add(this->textBox_RatingFrom);
			this->Controls->Add(this->button1_Search);
			this->Controls->Add(this->textBox1_Search);
			this->Controls->Add(this->listView);
			this->Name = L"SearcForm";
			this->Text = L"SearcForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SearcForm::SearcForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &SearcForm::SearcForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Search_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SearcForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void SearcForm_Load(System::Object^ sender, System::EventArgs^ e);
};
}
