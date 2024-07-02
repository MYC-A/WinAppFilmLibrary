#pragma once

namespace WinAppFilmLibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HelpForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		HelpForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox_HelpText;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox_HelpText = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox_HelpText
			// 
			this->richTextBox_HelpText->BackColor = System::Drawing::SystemColors::Info;
			this->richTextBox_HelpText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox_HelpText->Location = System::Drawing::Point(23, 43);
			this->richTextBox_HelpText->Name = L"richTextBox_HelpText";
			this->richTextBox_HelpText->Size = System::Drawing::Size(623, 391);
			this->richTextBox_HelpText->TabIndex = 0;
			this->richTextBox_HelpText->Text = L"";
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(687, 469);
			this->Controls->Add(this->richTextBox_HelpText);
			this->Name = L"HelpForm";
			this->Text = L"HelpForm";
			this->Load += gcnew System::EventHandler(this, &HelpForm::HelpForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void HelpForm_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
