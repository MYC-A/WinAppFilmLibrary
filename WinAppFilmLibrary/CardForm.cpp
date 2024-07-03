#include "CardForm.h"

void WinAppFilmLibrary::CardForm::ShowItem()
{
	if (pictureBox1->Image != nullptr)
	{
		delete pictureBox1->Image;
	}
	this->SuitableMovie = this->movies->find_Movie_index(this->index);

	this->textBox_Poster->Text = SuitableMovie->Poster;
	this->button1_LoadN->Visible = false;

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
	Bitmap^ img = gcnew Bitmap(textBox_Poster->Text);
	this->pictureBox1->Image = img;
	this->pictureBox1->Enabled = false;
}

void WinAppFilmLibrary::CardForm::DisplayForm()
{
	this->textBox1_Title->ReadOnly = false;


	this->textBox1_Rating->ReadOnly = false;


	this->textBox1_Genre->ReadOnly = false;


	this->textBox1_Release->ReadOnly = false;


	this->dateTimePicker1->Enabled = true;


	this->textBox1->ReadOnly = false;

	this->pictureBox1->Enabled = false;


	this->button1_Save->Enabled = true;
	this->button1_LoadN->Visible = true;
	this->button1_Change->Enabled = false;
	return;
}

System::Void WinAppFilmLibrary::CardForm::button1_Change_Click(System::Object^ sender, System::EventArgs^ e)
{
	DisplayForm();
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
		count++;
		String^ tmp_Poster = this->textBox_Poster->Text;
		String^ tmp_Title = this->textBox1_Title->Text;
		String^ tmp_Annotation = textBox1->Text;
		DateTime tmp_Data = this->dateTimePicker1->Value;
		array<String^>^ tmp_Genre = this->textBox1_Genre->Text->Split(',');
		double tmp_Rating;
		try {
			double tmp_Rating1 = Convert::ToDouble(this->textBox1_Rating->Text);
			tmp_Rating = tmp_Rating1;
		}
		catch (System::Exception^) {
			MessageBox::Show("Некоректный ввод", "Ошбка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			ShowItem();
			return System::Void();
		}
		
		SuitableMovie->Poster = tmp_Poster;
		SuitableMovie->Title = tmp_Title;
		SuitableMovie->Annotation = tmp_Annotation;
		SuitableMovie->Data = tmp_Data;
		SuitableMovie->Genre = tmp_Genre;
		SuitableMovie->Rating = tmp_Rating;
		parent->EditForDisplays(SuitableMovie->Id.ToString(), index, count);
	}
	else {
		MessageBox::Show("Карточка заполнена неполностью", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	this->button1_Save->Enabled = false;
	this->button1_Change->Enabled = true;

	ShowItem();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::CardForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	System::GC::Collect();
	parent = dynamic_cast<EditDBForm^>(this->Owner);// Методы первой формы
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::button1_LoadN_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	//Отображение 
	ofd->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files(*.*)|*.*";
	if (pictureBox1->Image != nullptr)
	{
		delete pictureBox1->Image;
		delete img;
	}
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try
		{
			img = gcnew Bitmap(ofd->FileName);
			pictureBox1->Image = img;
			textBox_Poster->Text = ofd->FileName;
		}
		catch (System::Exception^)
		{
			MessageBox::Show("Невозможно открыть выбранный файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::CardForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (pictureBox1->Image != nullptr)
	{
		delete pictureBox1->Image;
		delete pictureBox1;
		delete img;
	}
	System::GC::Collect();
	return System::Void();
}
