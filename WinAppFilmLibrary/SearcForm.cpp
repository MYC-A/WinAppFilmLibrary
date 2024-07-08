#include "SearcForm.h"
#include "CardView.h"

void WinAppFilmLibrary::SearcForm::UpdateListView()
{
	listView->Items->Clear();
	listView->DataBindings->Clear();
	System::GC::Collect();//Сборка мусора
	listView->BeginUpdate();
	ImageList^ imageList = gcnew ImageList();
	imageList->ImageSize = System::Drawing::Size(120, 110);
	int count = 0;

	for each (Movie ^ movie in list_view_movie)
	{
		Bitmap^ a = gcnew Bitmap(movie->Poster);
		ListViewItem^ item = gcnew ListViewItem();
		item->Name = movie->Id.ToString();
		item->ImageIndex = count++;
		imageList->Images->Add(movie->Id.ToString(), a);


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
	if (this->textBox_RatingFrom->Text->Length > 0 && this->textBox_Ratingto->Text->Length > 0) {
		try {
			double tmp_RatingFrom1 = Convert::ToDouble(this->textBox_RatingFrom->Text);
			double tmp_Ratingto1 = Convert::ToDouble(this->textBox_Ratingto->Text);
			tmp_RatingFrom = tmp_RatingFrom1;
			tmp_Ratingto = tmp_Ratingto1;
			Rating_flag = true;
			//if (tmp_Ratingto == 0) {

		}
		catch (System::Exception^) {
			MessageBox::Show(L"Не корректный ввод", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
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
					list_view_movie = movies->find_Movie(textBox1_Search->Text->Trim(), dateTimePicker1->Value, tmp_RatingFrom, tmp_Ratingto);
				}
				else
				{
					list_view_movie = movies->find_Movie(textBox1_Search->Text->Trim(), dateTimePicker1->Value);
				}
			}
			else if (Rating_flag)
			{
				list_view_movie = movies->find_Movie(textBox1_Search->Text->Trim(), tmp_RatingFrom, tmp_Ratingto);
			}
			else
			{
				list_view_movie = movies->find_Movie(textBox1_Search->Text->Trim());
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
				UpdateListView();
		}
		else if(list_view_movie != movies->getmovieList()) 
		{
			list_view_movie = movies->getmovieList();
			UpdateListView();
		}
		//textBox1_Search->Clear();

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

System::Void WinAppFilmLibrary::SearcForm::button1_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::OpenForms["MenuForm1"]->Show();
	this->Close();
	delete this;
	return System::Void();
}

System::Void WinAppFilmLibrary::SearcForm::textBox_RatingFrom_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08) {
		e->Handled = true;
	}

	// Проверка на ввод вещественных чисел от 0 до 10
	if (e->KeyChar == ',') {
		// Проверка на наличие только одной точки
		if (textBox_RatingFrom->Text->Contains(",")) {
			e->Handled = true;
		}
	}
	if (textBox_RatingFrom->Text == "0" && e->KeyChar != ',' && e->KeyChar != '\b')
	{
		e->Handled = true;
	}
	//if ( (textBox_Rating->Text->StartsWith("0") && e->KeyChar != ',') )
	//{e->Handled = true;}
	if (Char::IsDigit(e->KeyChar)) {
		// Проверка на ввод чисел в диапазоне от 0 до 10
		double num = Double::Parse(textBox_RatingFrom->Text + e->KeyChar);
		if (num < 0 || num > 10) {
			e->Handled = true;
		}
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::SearcForm::textBox_Ratingto_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08) {
		e->Handled = true;
	}

	// Проверка на ввод вещественных чисел от 0 до 10
	if (e->KeyChar == ',') {
		// Проверка на наличие только одной точки
		if (textBox_Ratingto->Text->Contains(",")) {
			e->Handled = true;
		}
	}
	if (textBox_Ratingto->Text == "0" && e->KeyChar != ',' && e->KeyChar != '\b')
	{
		e->Handled = true;
	}
	//if ( (textBox_Rating->Text->StartsWith("0") && e->KeyChar != ',') )
	//{e->Handled = true;}
	if (Char::IsDigit(e->KeyChar)) {
		// Проверка на ввод чисел в диапазоне от 0 до 10
		double num = Double::Parse(textBox_Ratingto->Text + e->KeyChar);
		if (num < 0 || num > 10) {
			e->Handled = true;
		}
	}
	return System::Void();
}

System::Void WinAppFilmLibrary::SearcForm::listView_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	CardView^ iftr = gcnew CardView(Convert::ToInt32(listView->SelectedItems[0]->SubItems[6]->Text));
	iftr->Owner = this; //Устанавливаем родителя
	iftr->Left = this->Left;
	iftr->Top = this->Top;
	iftr->ShowDialog();
	//iftr = nullptr; // стираем ссылку
	delete iftr; //Удяляем форму
	return System::Void();
}

System::Void WinAppFilmLibrary::SearcForm::button1_Unrelease_Click(System::Object^ sender, System::EventArgs^ e)
{
	list_view_movie = movies->find_UnRelease_Movie();
	UpdateListView();
	return System::Void();
}
