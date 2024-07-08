#pragma once

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button_rules;
	private: System::Windows::Forms::PictureBox^ pictureBox1_Background;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_rules = (gcnew System::Windows::Forms::Button());
			this->pictureBox1_Background = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_Background))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::RoyalBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Complex_IV25", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->button1->Location = System::Drawing::Point(41, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(196, 76);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Кинотека";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button_rules
			// 
			this->button_rules->BackColor = System::Drawing::Color::RoyalBlue;
			this->button_rules->Font = (gcnew System::Drawing::Font(L"Complex_IV25", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_rules->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->button_rules->Location = System::Drawing::Point(41, 295);
			this->button_rules->Name = L"button_rules";
			this->button_rules->Size = System::Drawing::Size(196, 76);
			this->button_rules->TabIndex = 1;
			this->button_rules->Text = L"Правила польозования";
			this->button_rules->UseVisualStyleBackColor = false;
			this->button_rules->Click += gcnew System::EventHandler(this, &MyForm::button_rules_Click);
			// 
			// pictureBox1_Background
			// 
			this->pictureBox1_Background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1_Background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1_Background.Image")));
			this->pictureBox1_Background->Location = System::Drawing::Point(0, 0);
			this->pictureBox1_Background->Name = L"pictureBox1_Background";
			this->pictureBox1_Background->Size = System::Drawing::Size(1089, 726);
			this->pictureBox1_Background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1_Background->TabIndex = 2;
			this->pictureBox1_Background->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1089, 726);
			this->Controls->Add(this->button_rules);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1_Background);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1105, 765);
			this->MinimumSize = System::Drawing::Size(1105, 765);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_Background))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_rules_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
