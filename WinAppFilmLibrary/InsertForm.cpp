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


	sr->save_Id();
}
