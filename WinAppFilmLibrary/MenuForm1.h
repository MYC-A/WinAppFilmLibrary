#pragma once
#include "Storage.h"
#include "Movies.h"

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
	private: System::Windows::Forms::PictureBox^ pictureBox1_Background;

	public:
		Movies^ movies = gcnew Movies();

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm1::typeid));
			this->button1_Close = (gcnew System::Windows::Forms::Button());
			this->button_Editing = (gcnew System::Windows::Forms::Button());
			this->button_Search = (gcnew System::Windows::Forms::Button());
			this->pictureBox1_Background = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_Background))->BeginInit();
			this->SuspendLayout();
			// 
			// button1_Close
			// 
			this->button1_Close->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button1_Close->Font = (gcnew System::Drawing::Font(L"Garamond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_Close->ForeColor = System::Drawing::Color::GhostWhite;
			this->button1_Close->Location = System::Drawing::Point(902, 489);
			this->button1_Close->Name = L"button1_Close";
			this->button1_Close->Size = System::Drawing::Size(143, 76);
			this->button1_Close->TabIndex = 0;
			this->button1_Close->Text = L"Назад";
			this->button1_Close->UseVisualStyleBackColor = false;
			this->button1_Close->Click += gcnew System::EventHandler(this, &MenuForm1::button1_Close_Click);
			// 
			// button_Editing
			// 
			this->button_Editing->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button_Editing->Font = (gcnew System::Drawing::Font(L"Garamond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Editing->ForeColor = System::Drawing::Color::GhostWhite;
			this->button_Editing->Location = System::Drawing::Point(902, 280);
			this->button_Editing->Name = L"button_Editing";
			this->button_Editing->Size = System::Drawing::Size(143, 76);
			this->button_Editing->TabIndex = 1;
			this->button_Editing->Text = L"Изменить базу фильмов";
			this->button_Editing->UseVisualStyleBackColor = false;
			this->button_Editing->Click += gcnew System::EventHandler(this, &MenuForm1::button_Editing_Click);
			// 
			// button_Search
			// 
			this->button_Search->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button_Search->Font = (gcnew System::Drawing::Font(L"Garamond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Search->ForeColor = System::Drawing::Color::GhostWhite;
			this->button_Search->Location = System::Drawing::Point(902, 81);
			this->button_Search->Name = L"button_Search";
			this->button_Search->Size = System::Drawing::Size(143, 76);
			this->button_Search->TabIndex = 2;
			this->button_Search->Text = L"Поиск";
			this->button_Search->UseVisualStyleBackColor = false;
			this->button_Search->Click += gcnew System::EventHandler(this, &MenuForm1::button_Search_Click);
			// 
			// pictureBox1_Background
			// 
			this->pictureBox1_Background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1_Background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1_Background.Image")));
			this->pictureBox1_Background->Location = System::Drawing::Point(0, 0);
			this->pictureBox1_Background->Name = L"pictureBox1_Background";
			this->pictureBox1_Background->Size = System::Drawing::Size(1089, 726);
			this->pictureBox1_Background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1_Background->TabIndex = 3;
			this->pictureBox1_Background->TabStop = false;
			// 
			// MenuForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1089, 726);
			this->Controls->Add(this->button_Search);
			this->Controls->Add(this->button_Editing);
			this->Controls->Add(this->button1_Close);
			this->Controls->Add(this->pictureBox1_Background);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1105, 765);
			this->MinimumSize = System::Drawing::Size(1105, 765);
			this->Name = L"MenuForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MenuForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_Background))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Close_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Editing_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Search_Click(System::Object^ sender, System::EventArgs^ e);
	};
};
