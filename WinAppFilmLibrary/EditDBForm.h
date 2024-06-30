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
		EditDBForm(Storage^ sr)
		{
			InitializeComponent();
			this -> sr = sr;
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
		~EditDBForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: Storage^ sr;
	private: System::Windows::Forms::ListView^ listView;
	protected:

	protected:
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::ColumnHeader^ Poster;
	private: System::Windows::Forms::ColumnHeader^ Title;
	private: System::Windows::Forms::ColumnHeader^ Data;
	private: System::Windows::Forms::ColumnHeader^ Genre;
	private: System::Windows::Forms::ColumnHeader^ Rating;
	private: System::Windows::Forms::Button^ button_Insert;
	private: System::Windows::Forms::Button^ button_Delete;
	private: System::Windows::Forms::Button^ button_Rearward;
	private: System::Windows::Forms::Button^ button1_Duplicate;

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
			this->listView = (gcnew System::Windows::Forms::ListView());
			this->Poster = (gcnew System::Windows::Forms::ColumnHeader());
			this->Title = (gcnew System::Windows::Forms::ColumnHeader());
			this->Data = (gcnew System::Windows::Forms::ColumnHeader());
			this->Genre = (gcnew System::Windows::Forms::ColumnHeader());
			this->Rating = (gcnew System::Windows::Forms::ColumnHeader());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button_Insert = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Rearward = (gcnew System::Windows::Forms::Button());
			this->button1_Duplicate = (gcnew System::Windows::Forms::Button());
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
			this->listView->Location = System::Drawing::Point(12, 30);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(735, 499);
			this->listView->TabIndex = 0;
			this->listView->UseCompatibleStateImageBehavior = false;
			this->listView->View = System::Windows::Forms::View::Details;
			this->listView->SelectedIndexChanged += gcnew System::EventHandler(this, &EditDBForm::listView_SelectedIndexChanged);
			this->listView->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &EditDBForm::listView_MouseDoubleClick);
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
			// button_Insert
			// 
			this->button_Insert->Location = System::Drawing::Point(753, 30);
			this->button_Insert->Name = L"button_Insert";
			this->button_Insert->Size = System::Drawing::Size(118, 46);
			this->button_Insert->TabIndex = 1;
			this->button_Insert->Text = L"Добавить";
			this->button_Insert->UseVisualStyleBackColor = true;
			this->button_Insert->Click += gcnew System::EventHandler(this, &EditDBForm::button_Insert_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Location = System::Drawing::Point(753, 179);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(118, 46);
			this->button_Delete->TabIndex = 2;
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &EditDBForm::button_Delete_Click);
			// 
			// button_Rearward
			// 
			this->button_Rearward->Location = System::Drawing::Point(753, 483);
			this->button_Rearward->Name = L"button_Rearward";
			this->button_Rearward->Size = System::Drawing::Size(118, 46);
			this->button_Rearward->TabIndex = 3;
			this->button_Rearward->Text = L"Назад";
			this->button_Rearward->UseVisualStyleBackColor = true;
			// 
			// button1_Duplicate
			// 
			this->button1_Duplicate->Location = System::Drawing::Point(753, 332);
			this->button1_Duplicate->Name = L"button1_Duplicate";
			this->button1_Duplicate->Size = System::Drawing::Size(118, 46);
			this->button1_Duplicate->TabIndex = 4;
			this->button1_Duplicate->Text = L"Удалить дубликаты";
			this->button1_Duplicate->UseVisualStyleBackColor = true;
			this->button1_Duplicate->Click += gcnew System::EventHandler(this, &EditDBForm::button1_Duplicate_Click);
			// 
			// EditDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 541);
			this->Controls->Add(this->button1_Duplicate);
			this->Controls->Add(this->button_Rearward);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->button_Insert);
			this->Controls->Add(this->listView);
			this->Name = L"EditDBForm";
			this->Text = L"EditDBForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void button_Insert_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void listView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void listView_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Duplicate_Click(System::Object^ sender, System::EventArgs^ e);
};
}
