#include "InsertForm.h"

bool WinAppFilmLibrary::InsertForm::checking_for_occupancy()
{
	Control^ control1 = gcnew Control();

	for each (Control ^ control in this->Controls)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(control);
		if (textBox != nullptr) {
			String^ st = textBox->Text;
			st = st->Replace(" ", "");
			if (!String::IsNullOrWhiteSpace(st))
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

System::Void WinAppFilmLibrary::InsertForm::button_Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool flag = checking_for_occupancy();;
	

	if (flag) {

		int tmp_index = parent->movies->getCurrent_Id();
		parent->movies->SetCurrent_Id(tmp_index + 1);

		count++;
		String^ tmp_Poster = textBox_Poster->Text;
		String^ tmp_Title = textBox_Title->Text->Trim();
		String^ tmp_Annotation = textBox_Annotation->Text;
		DateTime tmp_Data = dateTimePicker1->Value;
		array<String^>^ tmp_Genre = textBox_Genre->Text->Split(',');
		//double tmp_Rating = Convert::ToDouble(textBox_Rating->Text);
		double tmp_Rating;
		try {
			if (tmp_Data <= DateTime::Now.Date) {

				double tmp_Rating1 = Convert::ToDouble(this->textBox_Rating->Text);
				tmp_Rating = tmp_Rating1;
			}
			else {
				tmp_Rating = 0;
			}
		}
		catch (System::Exception^) {
			MessageBox::Show("Некоректный ввод", "Ошбка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return System::Void();
		}


		Movie^ newMovie = gcnew Movie(tmp_index, tmp_Poster, tmp_Title, tmp_Data, tmp_Genre, tmp_Rating, tmp_Annotation);
		parent->movies->addMovie(newMovie);


		Storage::save_Movie(newMovie);
		Storage::save_Id(parent->movies->getCurrent_Id());

		parent->AddForDisplays(count);

		delete newMovie; //
		delete pictureBox1_Poster->Image;
	}
	else {
		MessageBox::Show("Карточка заполнена неполностью", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void WinAppFilmLibrary::InsertForm::button1_Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	//Отображение 
	ofd->Filter = "Image Files(*.BMP;*.JPG;*.PNG;*.ICO)|*.BMP;*.JPG;*.PNG;*.ICO|All files(*.*)|*.*";
	if (pictureBox1_Poster->Image != nullptr)
	{
		delete pictureBox1_Poster->Image;
		delete img;
		img = nullptr;
	}
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try
		{
			img = gcnew Bitmap(ofd->FileName);
			pictureBox1_Poster->Image = img;
			textBox_Poster->Text = ofd->FileName;
		}
		catch (System::Exception^)
		{
			MessageBox::Show("Невозможно открыть выбранный файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::InsertForm::InsertForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (pictureBox1_Poster->Image != nullptr)
	{
		delete pictureBox1_Poster->Image;
		delete img;
		img = nullptr;
	}
	System::GC::Collect();
	return System::Void();
}

System::Void WinAppFilmLibrary::InsertForm::InsertForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	parent = dynamic_cast<EditDBForm^>(this->Owner);
	System::GC::Collect();
	return System::Void();
}

System::Void WinAppFilmLibrary::InsertForm::textBox_Rating_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08 && e->KeyChar != 0x03) {
		e->Handled = true;
	}

	if (e->KeyChar == ',' && textBox_Rating->Text->Length == 0) {
		e->Handled = true; //Проверка, на запятую после числа

	}

	// Проверка на ввод вещественных чисел от 0 до 10
	if (e->KeyChar == ',') {
		// Проверка на наличие только одной точки
		if (textBox_Rating->Text->Contains(",")) {
			e->Handled = true;
		}
	}
	if (textBox_Rating->Text == "0" && e->KeyChar != ',' && e->KeyChar != '\b')
	{
		e->Handled = true;
	}
	//if ( (textBox_Rating->Text->StartsWith("0") && e->KeyChar != ',') )
	//{e->Handled = true;}
	if (Char::IsDigit(e->KeyChar)) {
		// Проверка на ввод чисел в диапазоне от 0 до 10
		double num = Double::Parse(textBox_Rating->Text + e->KeyChar);
		if (num < 0 || num > 10) {
			e->Handled = true;
		}
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::InsertForm::textBox_Genre_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
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
		if (textBox_Genre->Text->EndsWith(",")) {
			e->Handled = true;
			return;
		}
	}

	// Если текущий ввод - пробел
	if (Symbol == " ") {
		// Проверяем, не стоит ли пробел после запятой
		if (!textBox_Genre->Text->EndsWith(",")) {
			e->Handled = true;
			return;
		}
		// Проверяем, есть ли уже пробел после запятой
		if (textBox_Genre->Text->Length > 1 && textBox_Genre->Text[textBox_Genre->Text->Length - 2] == ',') {
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

System::Void WinAppFilmLibrary::InsertForm::button_Clear_Click(System::Object^ sender, System::EventArgs^ e)
{
	for each (Control ^ control in Controls)
	{
		if (TextBox::typeid == control->GetType())
		{
			safe_cast<TextBox^>(control)->Text = String::Empty;
		}
	}
	pictureBox1_Poster->Image = nullptr;
	return System::Void();
}

System::Void WinAppFilmLibrary::InsertForm::button_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}

System::Void WinAppFilmLibrary::InsertForm::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (dateTimePicker1->Value.Date <= DateTime::Now.Date) {
		if (this->textBox_Rating->Text->Equals("-")) {
			this->textBox_Rating->Clear();
			this->textBox_Rating->ReadOnly = false;
		}

	}
	else
	{
		this->textBox_Rating->Text = "-";
		this->textBox_Rating->ReadOnly = true;
	}
	return System::Void();
}

