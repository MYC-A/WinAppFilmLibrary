#include "CardForm.h"

void WinAppFilmLibrary::CardForm::ShowItem()
{
	if (pictureBox1->Image != nullptr) 
	{
		delete img; // Удаляем изображение для загрузки нового
		delete pictureBox1->Image;
	}
	if (SuitableMovie == nullptr)
	{
		this->SuitableMovie = this->parent->movies->find_Movie_id(this->index);
	}

	//Заполнение данных в форме

	this->textBox_Poster->Text = SuitableMovie->Poster;
	this->button1_LoadN->Visible = false;

	if (SuitableMovie->Release) {
		this->textBox1_Rating->Text = SuitableMovie->Rating.ToString();
	}
	else {
		this->textBox1_Rating->Text = "-";
	}
	this->textBox1_Rating->ReadOnly = true;

	textBox1_Title->Text = SuitableMovie->Title;
	this->textBox1_Title->ReadOnly = true;

	this->textBox1_Genre->Text = String::Join(", ", SuitableMovie->Genre);
	this->textBox1_Genre->ReadOnly = true;


	if (SuitableMovie->Release) {
		this->label_ReleaseView->Text = "Состоялся";
	}
	else {
		this->label_ReleaseView->Text = "Ожидается";
	}
	

	this->dateTimePicker1->Value = SuitableMovie->Data;
	this->dateTimePicker1->Enabled = false;

	this->textBox1->Text = SuitableMovie->Annotation;
	this->textBox1->ReadOnly = true;
	

	img = gcnew Bitmap(SuitableMovie->Poster); //
	this->pictureBox1->Image = img;
	this->pictureBox1->Enabled = false;

}

void WinAppFilmLibrary::CardForm::DisplayForm()
{
	this->textBox1_Title->ReadOnly = false;

	if (SuitableMovie->Release) {
		this->textBox1_Rating->ReadOnly = false;
	}
	else {
		this->textBox1_Rating->ReadOnly = true;
	}


	this->textBox1_Genre->ReadOnly = false;




	this->dateTimePicker1->Enabled = true;


	this->textBox1->ReadOnly = false;

	this->pictureBox1->Enabled = false;


	this->button1_Save->Enabled = true;
	this->button1_LoadN->Visible = true;
	this->button_Cancel->Enabled = true;
	this->button1_Change->Enabled = false;

	return;
}

bool WinAppFilmLibrary::CardForm::checking_for_occupancy() // Проверка заполненности полей
{
	for each (Control ^ control in this->Controls)
	{

		TextBox^ textBox = dynamic_cast<TextBox^>(control);  // Ищем все TextBox
		if (textBox != nullptr) {
			String^ st = textBox->Text;
			st = st->Replace(" ", ""); //Заменяем возможные пустые пробелы
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
		count++; //Переменная для метода отображения изменений

		//Сохранение данных во временные переменный
		String^ tmp_Poster = this->textBox_Poster->Text;
		String^ tmp_Title = this->textBox1_Title->Text->Trim();
		String^ tmp_Annotation = textBox1->Text;
		DateTime tmp_Data = this->dateTimePicker1->Value;
		bool tmp_Release = (tmp_Data <= DateTime::Now.Date);
		array<String^>^ tmp_Genre = this->textBox1_Genre->Text->Split(',');


		String^ genres = String::Join(",", tmp_Genre);
		genres = genres->Replace(" ", "");// Удаляем все пробелы
		genres = genres->TrimEnd(','); // Удаляем последнюю запятую, если есть
		genres = genres->TrimStart(',');//Удаляем запятые без слов запятую, если есть
		
		if (String::IsNullOrEmpty(genres)) {
			MessageBox::Show("Некоректный ввод жанра", "Ошбка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			ShowItem();
			this->button1_Save->Enabled = false;
			this->button_Cancel->Enabled = false;             //Добавить
			this->button1_Change->Enabled = true;
			return System::Void();
		}
		
		tmp_Genre = genres->Split(',');

		

		double tmp_Rating;
		try {
			if (tmp_Release) {

				double tmp_Rating1 = Convert::ToDouble(this->textBox1_Rating->Text);
				tmp_Rating = tmp_Rating1;
			}
			else {
				tmp_Rating = 0;
			}
		}
		catch (System::Exception^) {
			MessageBox::Show("Некоректный ввод", "Ошбка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			ShowItem();
			return System::Void();
		}
		parent->movies->Edit(this->index, tmp_Poster, tmp_Title, tmp_Annotation, tmp_Data, tmp_Genre,tmp_Rating, tmp_Release); //Изменение 
		
		parent->EditForDisplays(SuitableMovie->Id.ToString(), index, count); // Вызов формы для отображения изменений 
		Storage::save_AllMovie(this->parent->movies); // Сохраняем полученные изменения в файле

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
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08 && e->KeyChar != 0x03) {
		e->Handled = true;
	}

	if (e->KeyChar == ',' && textBox1_Rating->Text->Length == 0) {
		e->Handled = true; //Проверка, на запятую после числа

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

	//if (textBox1_Genre->SelectionLength > 0 && e->KeyChar != (char)Keys::Back && e->KeyChar != (char)Keys::Delete) {
		// Пользователь пытается заменить выделенный текст
		//e->Handled = true; // Отмечаем событие как обработанное
	//}


	if (Symbol == "," && textBox1_Genre->Text->Length == 0) {                   //Добавить
		// Проверяем, не стоит ли запятая в нале текста
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

System::Void WinAppFilmLibrary::CardForm::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (dateTimePicker1->Value.Date <= DateTime::Now.Date) {
		if (this->textBox1_Rating->Text->Equals("-")) {
			this->textBox1_Rating->Clear();
			this->textBox1_Rating->ReadOnly = false;
		}

	}
	else
	{
		this->textBox1_Rating->Text = "-";
		this->textBox1_Rating->ReadOnly = true;
	}
	return System::Void();
}
