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
		//this->SuitableMovie = this->movies->find_Movie_index(this->index);
		this->SuitableMovie = this->parent->movies->find_Movie_id(this->index);
	}

	this->textBox_Poster->Text = SuitableMovie->Poster;

	this->textBox1_Rating->Text = SuitableMovie->Rating.ToString();

	textBox1_Title->Text = SuitableMovie->Title;

	this->textBox1_Genre->Text = String::Join(", ", SuitableMovie->Genre);

	this->textBox1_Release->Text = SuitableMovie->Release.ToString();

	this->dateTimePicker1->Value = SuitableMovie->Data;

	this->textBox1->Text = SuitableMovie->Annotation;

	img = gcnew Bitmap(SuitableMovie->Poster); //
	this->pictureBox1->Image = img;
	return System::Void();
}

System::Void WinAppFilmLibrary::CardView::CardView_Load(System::Object^ sender, System::EventArgs^ e)
{
	parent = dynamic_cast<SearcForm^>(this->Owner);
	ShowItem();
	return System::Void();
}

System::Void WinAppFilmLibrary::CardView::CardView_Leave(System::Object^ sender, System::EventArgs^ e)
{
	img = nullptr;
	delete img;
	this->pictureBox1 = nullptr;
	delete this->pictureBox1;
	System::GC::Collect();
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
