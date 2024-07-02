#include "InsertForm.h"

System::Void WinAppFilmLibrary::InsertForm::button_Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	int tmp_index = sr->Current_Id++;
	String^ tmp_Poster = textBox_Poster->Text;
	String^ tmp_Title = textBox_Title->Text;
	String^ tmp_Annotation = textBox_Annotation->Text;
	DateTime tmp_Data = dateTimePicker1->Value;
	array<String^>^ tmp_Genre = textBox_Genre->Text->Split(',');
	double tmp_Rating = Convert::ToDouble(textBox_Rating->Text);

	Movie^ newMovie = gcnew Movie(tmp_index, tmp_Poster, tmp_Title, tmp_Data, tmp_Genre, tmp_Rating, tmp_Annotation);
	sr->movieList->Add(newMovie);


	sr->save_Movie(newMovie);
	editForm->UpdateListView();
	delete newMovie; //
	sr->save_Id();
	delete pictureBox1_Poster->Image;
}

System::Void WinAppFilmLibrary::InsertForm::button1_Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	//Отображение 
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
			MessageBox::Show("Невозможно открыть выбранный файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
	System::GC::Collect();
	return System::Void();
}
