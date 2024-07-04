#include "InsertForm.h"

System::Void WinAppFilmLibrary::InsertForm::button_Save_Click(System::Object^ sender, System::EventArgs^ e)
{

	int tmp_index = movies->getCurrent_Id();
	movies->SetCurrent_Id(tmp_index + 1);

	count++;
	String^ tmp_Poster = textBox_Poster->Text;
	String^ tmp_Title = textBox_Title->Text;
	String^ tmp_Annotation = textBox_Annotation->Text;
	DateTime tmp_Data = dateTimePicker1->Value;
	array<String^>^ tmp_Genre = textBox_Genre->Text->Split(',');
	double tmp_Rating = Convert::ToDouble(textBox_Rating->Text);

	Movie^ newMovie = gcnew Movie(tmp_index, tmp_Poster, tmp_Title, tmp_Data, tmp_Genre, tmp_Rating, tmp_Annotation);
	movies->addMovie(newMovie);


	Storage::save_Movie(newMovie);
	Storage::save_Id(movies->getCurrent_Id());

	parent->AddForDisplays(count);

	delete newMovie; //
	delete pictureBox1_Poster->Image;
}

System::Void WinAppFilmLibrary::InsertForm::button1_Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	//����������� 
	ofd->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files(*.*)|*.*";
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
			MessageBox::Show("���������� ������� ��������� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	System::GC::Collect();
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
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08) {
		e->Handled = true;
	}

	// �������� �� ���� ������������ ����� �� 0 �� 10
	if (e->KeyChar == ',') {
		// �������� �� ������� ������ ����� �����
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
		// �������� �� ���� ����� � ��������� �� 0 �� 10
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

	if (!System::Text::RegularExpressions::Regex::IsMatch(Symbol, L"[�-��-�a-zA-Z, ]") &&
		e->KeyChar != (char)Keys::Back && e->KeyChar != (char)Keys::Delete) {
		e->Handled = true;
		return;
	}



	// ���� ������� ���� - �������
	if (Symbol == ",") {
		// ���������, �� ����� �� ������� � ����� ������
		if (textBox_Genre->Text->EndsWith(",")) {
			e->Handled = true;
			return;
		}
	}

	// ���� ������� ���� - ������
	if (Symbol == " ") {
		// ���������, �� ����� �� ������ ����� �������
		if (!textBox_Genre->Text->EndsWith(",")) {
			e->Handled = true;
			return;
		}
		// ���������, ���� �� ��� ������ ����� �������
		if (textBox_Genre->Text->Length > 1 && textBox_Genre->Text[textBox_Genre->Text->Length - 2] == ',') {
			e->Handled = true;
			return;
		}
	}

	// ��������� ���� �����
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

