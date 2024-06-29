#include "CardForm.h"

void WinAppFilmLibrary::CardForm::ShowItem()
{
	this->SuitableMovie = this->sr->find_Movie_index(this->index);

	
	this->textBox1_Rating->Text = SuitableMovie->Rating.ToString();
	this->textBox1_Rating->ReadOnly = true;

	textBox1_Title->Text = SuitableMovie->Title;
	this->textBox1_Title->ReadOnly = true;

	this->textBox1_Genre->Text = String::Join(", ", SuitableMovie->Genre);
	this->textBox1_Genre->ReadOnly = true;

	this->textBox1_Release->Text = SuitableMovie->Release.ToString();
	this->textBox1_Release->ReadOnly = true;

	this->dateTimePicker1->Value = SuitableMovie->Data;
	this->dateTimePicker1->Enabled = false;

	this->textBox1->Text = SuitableMovie->Annotation;
	this->textBox1->ReadOnly = true;

	//this->textBox2->ReadOnly = true;
	Bitmap^ img = gcnew Bitmap("C:\\Movie_Library\\Image.jpg");
	this->pictureBox1->Image = img;
	this->pictureBox1->Enabled = false;
}

System::Void WinAppFilmLibrary::CardForm::button1_Change_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->textBox1_Title->ReadOnly = false;


	this->textBox1_Rating->ReadOnly = false;


	this->textBox1_Genre->ReadOnly = false;


	this->textBox1_Release->ReadOnly = false;


	this->dateTimePicker1->Enabled = false;


	this->textBox1->ReadOnly = false;

	this->pictureBox1->Enabled = false;

	this->button1_Change->Visible = false;

	this->button1_Save->Visible = true;
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::button1_Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool flag = true;
	for each (Control ^ control in this->Controls)
	{

		TextBox^ textBox = dynamic_cast<TextBox^>(control);
		if (textBox != nullptr) {
			String^ st = textBox->Text;
			st = st->Replace(" ", "");
			if (!String::IsNullOrEmpty(textBox->Text))
			{
				continue;
			}
			else
			{
				flag = false;
				break;
			}
		}
	}
	if (flag == true) {

		String^ tmp_Title = this->textBox1_Title->Text;
		String^ tmp_Annotation = textBox1->Text;
		DateTime tmp_Data = this->dateTimePicker1->Value;
		array<String^>^ tmp_Genre = this->textBox1_Genre->Text->Split(',');
		double tmp_Rating = Convert::ToDouble(this->textBox1_Rating->Text);

		SuitableMovie->Title = tmp_Title;
		SuitableMovie->Annotation = tmp_Annotation;
		SuitableMovie->Data = tmp_Data;
		SuitableMovie->Genre = tmp_Genre;
		SuitableMovie->Rating = tmp_Rating;

	}

	ShowItem();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::CardForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	parent = dynamic_cast<EditDBForm^>(this->Owner);// Ìועמהû ןונגמי פמנלû
	return System::Void();
}
