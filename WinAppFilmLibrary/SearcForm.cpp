#include "SearcForm.h"

void WinAppFilmLibrary::SearcForm::UpdateListView()
{
	listView->Items->Clear();
	listView->DataBindings->Clear();
	System::GC::Collect();//Сборка мусора
	listView->BeginUpdate();
	ImageList^ imageList = gcnew ImageList();
	imageList->ImageSize = System::Drawing::Size(100, 100);
	int count = 0;//Добавить

	for each (Movie ^ movie in list_view_movie)
	{
		ListViewItem^ item = gcnew ListViewItem();
		item->ImageIndex = count++;
		imageList->Images->Add(movie->Id.ToString(), gcnew Bitmap(movie->Poster));

		item->SubItems->Add(movie->Title);
		item->SubItems->Add(movie->Data.ToShortDateString());
		item->SubItems->Add(String::Join(", ", movie->Genre));
		item->SubItems->Add(movie->Rating.ToString());
		item->SubItems->Add(movie->Annotation);
		item->SubItems->Add(movie->Id.ToString());
		listView->Items->Add(item);
	}
	listView->SmallImageList = imageList;
	listView->EndUpdate();
	return;
}

System::Void WinAppFilmLibrary::SearcForm::button1_Search_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ stSearch = textBox1_Search->Text;
	stSearch = stSearch->Replace(" ", "");

	//String^ stRatingFrom = textBox_RatingFrom->Text;
	//stRatingFrom = stRatingFrom ->Replace(" ", "");

	//String^ stRatingto = textBox_Ratingto->Text;
	//stRatingto = stRatingto->Replace(" ", "");
	bool Rating_flag = false;

	double tmp_RatingFrom;
	double tmp_Ratingto;
	try {
		double tmp_RatingFrom = Convert::ToDouble(this->textBox_RatingFrom->Text);
		double tmp_Ratingto = Convert::ToDouble(this->textBox_Ratingto->Text);
		Rating_flag = true;
		//if (tmp_Ratingto == 0) {
		
	}
	catch(System::Exception^){
		//Rating_flag = false;
	}


	String^ stdateTime = nullptr;
	if (dateTimePicker1->Checked) {
		stdateTime = dateTimePicker1->Value.ToShortDateString();
	}

		if (!String::IsNullOrWhiteSpace(stSearch)) 
		{
			if (stdateTime != nullptr)
			{
				if (Rating_flag)
				{
					list_view_movie = movies->find_Movie(textBox1_Search->Text, dateTimePicker1->Value, tmp_RatingFrom, tmp_Ratingto);
				}
				else
				{
					list_view_movie = movies->find_Movie(textBox1_Search->Text, dateTimePicker1->Value);
				}
			}
			else if (Rating_flag)
			{
				list_view_movie = movies->find_Movie(textBox1_Search->Text, tmp_RatingFrom, tmp_Ratingto);
			}
			else
			{
				list_view_movie = movies->find_Movie(textBox1_Search->Text);
			}
			UpdateListView();
		}

		else if (stdateTime != nullptr)
		{
			if (Rating_flag)
			{
				list_view_movie = movies->find_Movie(dateTimePicker1->Value, tmp_RatingFrom, tmp_Ratingto);
			}
			else {
				list_view_movie = movies->find_Movie(dateTimePicker1->Value);
			}
			UpdateListView();
		}
		else if(Rating_flag){
				list_view_movie = movies->find_Movie(tmp_RatingFrom, tmp_Ratingto);
		}
		//textBox1_Search->Clear();

    MessageBox::Show(dateTimePicker1->Checked.ToString(), "Нажатие", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    //dateTimePicker1->Checked
	

    list_view_movie;
    
    return System::Void();
}

System::Void WinAppFilmLibrary::SearcForm::SearcForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	listView->Items->Clear();
	listView->DataBindings->Clear();
	System::GC::Collect();
	return System::Void();
}

System::Void WinAppFilmLibrary::SearcForm::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	DateTimePicker^ dtp = dynamic_cast<DateTimePicker^>(sender);

	if (!dtp->ShowCheckBox || dtp->Checked)
	{
		// Устанавливаем формат, если флажок не отображается либо выбрана дата
		dtp->CustomFormat = "dd-MM-yyyy";
	}
	else
	{
		// Скрываем дату, если флажок не установлен
		dtp->CustomFormat = "'";
	}
	
	
}

System::Void WinAppFilmLibrary::SearcForm::SearcForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	System::GC::Collect();
	return System::Void();
}
