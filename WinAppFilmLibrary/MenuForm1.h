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
	/// Сводка для MenuForm1
	/// </summary>
	public ref class MenuForm1 : public System::Windows::Forms::Form
	{
	public:
		MenuForm1(void)
		{
			InitializeComponent();
			InitializeBDFilms();
			//
			//TODO: добавьте код конструктора
			//
		}
		void InitializeBDFilms();
	private: System::Windows::Forms::Button^ button1_Close;
	private: System::Windows::Forms::Button^ button_Editing;



	private: System::Windows::Forms::Button^ button_Search;

	public:
		Storage^ sr = gcnew Storage();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MenuForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1_Close = (gcnew System::Windows::Forms::Button());
			this->button_Editing = (gcnew System::Windows::Forms::Button());
			this->button_Search = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1_Close
			// 
			this->button1_Close->Location = System::Drawing::Point(552, 330);
			this->button1_Close->Name = L"button1_Close";
			this->button1_Close->Size = System::Drawing::Size(108, 47);
			this->button1_Close->TabIndex = 0;
			this->button1_Close->Text = L"button1";
			this->button1_Close->UseVisualStyleBackColor = true;
			this->button1_Close->Click += gcnew System::EventHandler(this, &MenuForm1::button1_Close_Click);
			// 
			// button_Editing
			// 
			this->button_Editing->Location = System::Drawing::Point(552, 186);
			this->button_Editing->Name = L"button_Editing";
			this->button_Editing->Size = System::Drawing::Size(108, 47);
			this->button_Editing->TabIndex = 1;
			this->button_Editing->Text = L"Изменить базу фильмов";
			this->button_Editing->UseVisualStyleBackColor = true;
			this->button_Editing->Click += gcnew System::EventHandler(this, &MenuForm1::button_Editing_Click);
			// 
			// button_Search
			// 
			this->button_Search->Location = System::Drawing::Point(552, 54);
			this->button_Search->Name = L"button_Search";
			this->button_Search->Size = System::Drawing::Size(108, 47);
			this->button_Search->TabIndex = 2;
			this->button_Search->Text = L"Поиск";
			this->button_Search->UseVisualStyleBackColor = true;
			// 
			// MenuForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 404);
			this->Controls->Add(this->button_Search);
			this->Controls->Add(this->button_Editing);
			this->Controls->Add(this->button1_Close);
			this->Name = L"MenuForm1";
			this->Text = L"MenuForm1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Close_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Editing_Click(System::Object^ sender, System::EventArgs^ e);
	};
};
