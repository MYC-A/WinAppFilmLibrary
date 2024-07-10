#include "CardView.h"

void WinAppFilmLibrary::CardView::ShowItem()
{
	if (pictureBox1->Image != nullptr)
	{
		delete img;
		delete pictureBox1->Image;
	}
	if (SuitableMovie == nullptr)
	{
		this->SuitableMovie = this->parent->movies->find_Movie_id(this->index); // Поиск фильма для отображения данных 
	}

	//Заполнение данных в форме

	this->textBox_Poster->Text = SuitableMovie->Poster;

	textBox1_Title->Text = SuitableMovie->Title;

	this->textBox1_Genre->Text = String::Join(", ", SuitableMovie->Genre);




	if (SuitableMovie->Release) {
		this->textBox1_Release->Text = "Состоялся";
	}
	else {
		this->textBox1_Release->Text = "Ожидается";
	}

	this->dateTimePicker1->Value = SuitableMovie->Data;

	if (SuitableMovie->Release) {
		this->textBox1_Rating->Text = SuitableMovie->Rating.ToString();
	}
	else {
		this->textBox1_Rating->Text = "-";
	}

	this->textBox1->Text = SuitableMovie->Annotation;


	img = gcnew Bitmap(SuitableMovie->Poster); //Создание изображения
	this->pictureBox1->Image = img;
	return System::Void();
}

System::Void WinAppFilmLibrary::CardView::CardView_Load(System::Object^ sender, System::EventArgs^ e)
{
	parent = dynamic_cast<SearcForm^>(this->Owner); //Информация о родителе
	ShowItem();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardView::CardView_Leave(System::Object^ sender, System::EventArgs^ e) //Удалить
{   //Проверить по память
	img = nullptr; 
	delete img;
	this->pictureBox1 = nullptr;
	delete this->pictureBox1;
	System::GC::Collect(); //очищение памяти
	return System::Void();
}

System::Void WinAppFilmLibrary::CardView::CardView_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	img = nullptr;
	delete img;
	this->pictureBox1 = nullptr;
	delete this->pictureBox1;
	delete this;
	//System::GC::Collect();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardView::button1_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}
