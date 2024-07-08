#include "CardForm.h"

void WinAppFilmLibrary::CardForm::ShowItem()
{
	if (pictureBox1->Image != nullptr)
	{
		delete img;
		delete pictureBox1->Image;
	}
	if (SuitableMovie == nullptr)
	{
		//this->SuitableMovie = this->movies->find_Movie_index(this->index);
		this->SuitableMovie = this->parent->movies->find_Movie_id(this->index);
	}

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

	img = gcnew Bitmap(SuitableMovie->Poster); //
	this->pictureBox1->Image = img;
	this->pictureBox1->Enabled = false;

}

void WinAppFilmLibrary::CardForm::DisplayForm()
{
	this->textBox1_Title->ReadOnly = false;


	this->textBox1_Rating->ReadOnly = false;


	this->textBox1_Genre->ReadOnly = false;


	this->textBox1_Release->ReadOnly = true;


	this->dateTimePicker1->Enabled = true;


	this->textBox1->ReadOnly = false;

	this->pictureBox1->Enabled = false;


	this->button1_Save->Enabled = true;
	this->button1_LoadN->Visible = true;
	this->button_Cancel->Enabled = true;
	this->button1_Change->Enabled = false;

	return;
}

bool WinAppFilmLibrary::CardForm::checking_for_occupancy()
{
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
				return false;
			}
		}
	}

	return true;
}

System::Void WinAppFilmLibrary::CardForm::button1_Change_Click(System::Object^ sender, System::EventArgs^ e)
{
	DisplayForm();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::button1_Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool flag = checking_for_occupancy();
	
	if (flag) {
		count++;
		String^ tmp_Poster = this->textBox_Poster->Text;
		String^ tmp_Title = this->textBox1_Title->Text->Trim();
		String^ tmp_Annotation = textBox1->Text;
		DateTime tmp_Data = this->dateTimePicker1->Value;
		bool tmp_Release = (tmp_Data <= DateTime::Now.Date);
		array<String^>^ tmp_Genre = this->textBox1_Genre->Text->Split(',');

		String^ genres = String::Join(",", tmp_Genre);
		genres = genres->Replace(" ", ""); // Удаляем все пробелы
		genres = genres->TrimEnd(','); // Удаляем последнюю запятую, если есть
		
		tmp_Genre = genres->Split(',');

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
		parent->movies->Edit(this->index, tmp_Poster, tmp_Title, tmp_Annotation, tmp_Data, tmp_Genre,tmp_Rating, tmp_Release);
		/*SuitableMovie->Poster = tmp_Poster;
		SuitableMovie->Title = tmp_Title;
		SuitableMovie->Annotation = tmp_Annotation;
		SuitableMovie->Data = tmp_Data;
		SuitableMovie->Genre = tmp_Genre;
		SuitableMovie->Rating = tmp_Rating;
		SuitableMovie->Release = tmp_Release;
		*/
		parent->EditForDisplays(SuitableMovie->Id.ToString(), index, count);
		Storage::save_AllMovie(this->parent->movies);
		System::GC::Collect();

	}
	else {
		MessageBox::Show("Карточка заполнена неполностью", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	this->button1_Save->Enabled = false;
	this->button_Cancel->Enabled = false;
	this->button1_Change->Enabled = true;

	ShowItem();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::CardForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	System::GC::Collect();
	parent = dynamic_cast<EditDBForm^>(this->Owner);
	ShowItem();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::button1_LoadN_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	//Отображение 
	ofd->Filter = "Image Files(*.BMP;*.JPG;*.PNG;*.ICO)|*.BMP;*.JPG;*.PNG;*.ICO|All files(*.*)|*.*";
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

System::Void WinAppFilmLibrary::CardForm::textBox1_Rating_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08) {
		e->Handled = true;
	}

	// Проверка на ввод вещественных чисел от 0 до 10
	if (e->KeyChar == ',') {
		// Проверка на наличие только одной точки
		if (textBox1_Rating->Text->Contains(",")) {
			e->Handled = true;
		}
	}
	if (textBox1_Rating->Text == "0" && e->KeyChar != ',' && e->KeyChar != '\b')
	{
		e->Handled = true;
	}
	//if ( (textBox_Rating->Text->StartsWith("0") && e->KeyChar != ',') )
	//{e->Handled = true;}
	if (Char::IsDigit(e->KeyChar)) {
		// Проверка на ввод чисел в диапазоне от 0 до 10
		double num = Double::Parse(textBox1_Rating->Text + e->KeyChar);
		if (num < 0 || num > 10) {
			e->Handled = true;
		}
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::textBox1_Genre_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	String^ Symbol = e->KeyChar.ToString();
	if (!System::Text::RegularExpressions::Regex::IsMatch(Symbol, L"[а-яА-Яa-zA-Z, ]") &&
		e->KeyChar != (char)Keys::Back && e->KeyChar != (char)Keys::Delete) {
		e->Handled = true;
		return;
	}



	// Если текущий ввод - запятая
	if (Symbol == ",") {
		// Проверяем, не стоит ли запятая в конце текста
		if (textBox1_Genre->Text->EndsWith(",")) {
			e->Handled = true;
			return;
		}
	}

	// Если текущий ввод - пробел
	if (Symbol == " ") {
		// Проверяем, не стоит ли пробел после запятой
		if (!textBox1_Genre->Text->EndsWith(",")) {
			e->Handled = true;
			return;
		}
		// Проверяем, есть ли уже пробел после запятой
		if (textBox1_Genre->Text->Length > 1 && textBox1_Genre->Text[textBox1_Genre->Text->Length - 2] == ',') {
			e->Handled = true;
			return;
		}
	}

	// Запрещаем ввод точек
	if (Symbol == ".") {
		e->Handled = true;
		return;
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::button_Cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	ShowItem();
	this->button1_Change->Enabled = true;
	this->button_Cancel->Enabled = false;
	this->button1_Save->Enabled = false;
	return System::Void();
}

System::Void WinAppFilmLibrary::CardForm::button1_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}
