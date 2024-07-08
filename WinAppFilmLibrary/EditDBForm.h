#pragma once
#include "Storage.h"

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для EditDBForm
	/// </summary>
	public ref class EditDBForm : public System::Windows::Forms::Form
	{
	public:
		EditDBForm(Movies^ movies)
		{
			this->movies = movies; //
			InitializeComponent();
			UpdateListView();
			//
			//TODO: добавьте код конструктора
			//
		}
		void UpdateListView();
		void GB();

		void AddForDisplays(int Num_additions);
		void EditForDisplays(String^ Name, int index,int Num_additions);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditDBForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: Movies^ movies;
	private: System::Windows::Forms::ListView^ listView;
	protected:

	protected:

	private: System::Windows::Forms::ColumnHeader^ Poster;
	private: System::Windows::Forms::ColumnHeader^ Title;
	private: System::Windows::Forms::ColumnHeader^ Data;
	private: System::Windows::Forms::ColumnHeader^ Genre;
	private: System::Windows::Forms::ColumnHeader^ Rating;
	private: System::Windows::Forms::Button^ button_Insert;
	private: System::Windows::Forms::Button^ button_Delete;

	private: System::Windows::Forms::Button^ button1_Duplicate;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button_Rearward;

	protected:





	protected:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditDBForm::typeid));
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Poster = (gcnew System::Windows::Forms::ColumnHeader());
			this->Title = (gcnew System::Windows::Forms::ColumnHeader());
			this->Data = (gcnew System::Windows::Forms::ColumnHeader());
			this->Genre = (gcnew System::Windows::Forms::ColumnHeader());
			this->Rating = (gcnew System::Windows::Forms::ColumnHeader());
			this->button_Insert = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button1_Duplicate = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_Rearward = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// listView
			// 
			this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Poster, this->Title,
					this->Data, this->Genre, this->Rating
			});
			this->listView->Dock = System::Windows::Forms::DockStyle::Left;
			this->listView->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView->FullRowSelect = true;
			this->listView->GridLines = true;
			this->listView->HideSelection = false;
			this->listView->Location = System::Drawing::Point(0, 0);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(902, 726);
			this->listView->TabIndex = 0;
			this->listView->UseCompatibleStateImageBehavior = false;
			this->listView->View = System::Windows::Forms::View::Details;
			this->listView->SelectedIndexChanged += gcnew System::EventHandler(this, &EditDBForm::listView_SelectedIndexChanged);
			this->listView->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EditDBForm::listView_MouseDoubleClick);
			// 
			// Poster
			// 
			this->Poster->Text = L"Постер";
			this->Poster->Width = 158;
			// 
			// Title
			// 
			this->Title->Text = L"Название";
			this->Title->Width = 174;
			// 
			// Data
			// 
			this->Data->Text = L"Дата выхода в прокат";
			this->Data->Width = 202;
			// 
			// Genre
			// 
			this->Genre->Text = L"Жанр";
			this->Genre->Width = 222;
			// 
			// Rating
			// 
			this->Rating->Text = L"Рейтинг";
			this->Rating->Width = 268;
			// 
			// button_Insert
			// 
			this->button_Insert->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button_Insert->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Insert->Location = System::Drawing::Point(922, 112);
			this->button_Insert->Name = L"button_Insert";
			this->button_Insert->Size = System::Drawing::Size(142, 59);
			this->button_Insert->TabIndex = 1;
			this->button_Insert->Text = L"Добавить";
			this->button_Insert->UseVisualStyleBackColor = false;
			this->button_Insert->Click += gcnew System::EventHandler(this, &EditDBForm::button_Insert_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button_Delete->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Delete->Location = System::Drawing::Point(922, 252);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(142, 59);
			this->button_Delete->TabIndex = 2;
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->UseVisualStyleBackColor = false;
			this->button_Delete->Click += gcnew System::EventHandler(this, &EditDBForm::button_Delete_Click);
			// 
			// button1_Duplicate
			// 
			this->button1_Duplicate->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button1_Duplicate->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Duplicate->Location = System::Drawing::Point(922, 404);
			this->button1_Duplicate->Name = L"button1_Duplicate";
			this->button1_Duplicate->Size = System::Drawing::Size(142, 59);
			this->button1_Duplicate->TabIndex = 4;
			this->button1_Duplicate->Text = L"Удалить дубликаты";
			this->button1_Duplicate->UseVisualStyleBackColor = false;
			this->button1_Duplicate->Click += gcnew System::EventHandler(this, &EditDBForm::button1_Duplicate_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(922, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(142, 79);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// button_Rearward
			// 
			this->button_Rearward->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button_Rearward->Font = (gcnew System::Drawing::Font(L"Constantia", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Rearward->Location = System::Drawing::Point(922, 572);
			this->button_Rearward->Name = L"button_Rearward";
			this->button_Rearward->Size = System::Drawing::Size(142, 59);
			this->button_Rearward->TabIndex = 3;
			this->button_Rearward->Text = L"Назад";
			this->button_Rearward->UseVisualStyleBackColor = false;
			this->button_Rearward->Click += gcnew System::EventHandler(this, &EditDBForm::button_Rearward_Click);
			// 
			// EditDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1089, 726);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1_Duplicate);
			this->Controls->Add(this->button_Rearward);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->button_Insert);
			this->Controls->Add(this->listView);
			this->MaximumSize = System::Drawing::Size(1105, 765);
			this->MinimumSize = System::Drawing::Size(1105, 765);
			this->Name = L"EditDBForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"EditDBForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EditDBForm::EditDBForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &EditDBForm::EditDBForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void button_Insert_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void listView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void listView_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Duplicate_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditDBForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Rearward_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditDBForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
