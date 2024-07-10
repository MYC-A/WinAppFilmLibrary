#include "EditDBForm.h"
#include "InsertForm.h"
#include "CardForm.h"

void WinAppFilmLibrary::EditDBForm::UpdateListView()
{
	listView->Items->Clear();
	listView->DataBindings->Clear();
	listView->BeginUpdate();
	ImageList^ imageList = gcnew ImageList();
	imageList->ImageSize = System::Drawing::Size(110, 120); //
	//List<Movie^>^ movieList1 = movies->getmovieList();
	for each (Movie ^ movie in movies->getmovieList())
	{
		//Добавление в ListView

		Bitmap^ a = gcnew Bitmap(movie->Poster);

		ListViewItem^ item = gcnew ListViewItem();


		item->Name = movie->Id.ToString();
		item->ImageKey = movie->Id.ToString();
		imageList->Images->Add(movie->Id.ToString(), a);

		item->SubItems->Add(movie->Title);
		item->SubItems->Add(movie->Data.ToShortDateString());
		item->SubItems->Add(String::Join(", ", movie->Genre));
		if (movie->Release) {
			item->SubItems->Add(movie->Rating.ToString());
		}
		else {
			item->SubItems->Add("-");
		}
		item->SubItems->Add(movie->Annotation);
		item->SubItems->Add(movie->Id.ToString());
		listView->Items->Add(item);
		
	}
	listView->SmallImageList = imageList;
	listView->EndUpdate();
	return;
}

void WinAppFilmLibrary::EditDBForm::AddForDisplays(int Num_additions)
{
	ListViewItem^ item = gcnew ListViewItem();

	Movie^ movie1 = movies->getMovie(movies->getCount() - 1); //Берем добавленный элементы 


	item->Name = movie1->Id.ToString();
	ImageList^ imageList = listView->SmallImageList;

	//Добавление в ListView
	imageList->Images->Add(movie1->Id.ToString(), gcnew Bitmap(movie1->Poster));

	item->ImageKey = movie1->Id.ToString();

	item->SubItems->Add(movie1->Title);
	item->SubItems->Add(movie1->Data.ToShortDateString());
	item->SubItems->Add(String::Join(", ", movie1->Genre));

	if (movie1->Release) {
		item->SubItems->Add(movie1->Rating.ToString());
	}
	else {
		item->SubItems->Add("-");
	}
	item->SubItems->Add(movie1->Annotation);
	item->SubItems->Add(movie1->Id.ToString());
	listView->Items->Add(item);

	listView->SmallImageList = imageList;
	movie1 = nullptr;
	item = nullptr;

	delete movie1;
	delete item;
	//delete imageList;
	if (Num_additions % 10 == 0) {
		System::GC::Collect(); //Проверка на очищение памяти, если пользователь подряд будет добавлять один и тот же объект
	}
}

void WinAppFilmLibrary::EditDBForm::EditForDisplays(String^ Name, int id,int Num_additions)
{
	int index = movies->getIndex(id);

	String^ a = Name; // Замена на Name
	ListViewItem^ item = listView->Items[a];

	System::Drawing::Bitmap^ original = gcnew System::Drawing::Bitmap(movies->getMovie(index)->Poster);
	int newWidth = 110;
	int newHeight = 120;
	System::Drawing::Bitmap^ resized = gcnew System::Drawing::Bitmap(original, System::Drawing::Size(newWidth, newHeight));

	ImageList^ imageList = listView->SmallImageList;
	int j = imageList->Images->IndexOfKey(a); // Находим ссылку на исходное изображение  
	imageList->Images[j] = resized; //Замменяем исходное изображение

	//Изменяем данные в ListView

	item->SubItems[1]->Text = movies->getMovie(index)->Title; 
	item->SubItems[2]->Text = movies->getMovie(index)->Data.ToShortDateString();
	item->SubItems[3]->Text = String::Join(", ", movies->getMovie(index)->Genre);
	if (movies->getMovie(index)->Release) {
		item->SubItems[4]->Text = movies->getMovie(index)->Rating.ToString();
	}
	else {
		item->SubItems[4]->Text = "-";
	}
	listView->Refresh();
	if (Num_additions % 10 == 0) {
		System::GC::Collect(); //Проверка на очищение памяти, если пользователь подряд будет вносить измененние в один и тот же объект
	}
}

System::Void WinAppFilmLibrary::EditDBForm::button_Insert_Click(System::Object^ sender, System::EventArgs^ e)
{

    InsertForm^ insertForm = gcnew InsertForm();
	insertForm->Owner = this;
	insertForm->Left = this->Left;
	insertForm->Top = this->Top;


    insertForm->ShowDialog();
	delete insertForm;
	insertForm = nullptr;


    return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::listView_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	CardForm^ iftr = gcnew CardForm(Convert::ToInt32(listView->SelectedItems[0]->SubItems[6]->Text));
	iftr->Owner = this; //Устанавливаем родителя
	iftr->Left = this->Left;
	iftr->Top = this->Top;
	iftr->ShowDialog();
	delete iftr; //Удяляем форму
	iftr = nullptr; // стираем ссылку

	//System::GC::Collect();
	
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		int id = Convert::ToInt32(listView->SelectedItems[0]->SubItems[6]->Text); // Считывание id из экземпляра ListView
		Movie^ delete_tmp_Movie;
		String^ Name = listView->SelectedItems[0]->Name; // Считывание Name изображения экземпляра ListView

		delete_tmp_Movie = movies->find_Movie_id(id); //Поиск фильма д
		movies->deleteMovie(delete_tmp_Movie);
		listView->Items->RemoveByKey(Name); //Удаление с формы отображения
	}
	catch(System::Exception^){
		MessageBox::Show("Выберите фильм", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	Storage::save_AllMovie(movies);
	System::GC::Collect();//

	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::button1_Duplicate_Click(System::Object^ sender, System::EventArgs^ e)
{
	int index = 0;
	bool flag = false;
	for (int i = 0; i < movies->getCount(); i++) {
		for (int j = i + 1; j < movies->getCount(); j++)
		{
			index = j;
			if ((movies->getMovie(i)->Title == movies->getMovie(j)->Title) && (movies->getMovie(i)->Data.ToShortDateString() == movies->getMovie(j)->Data.ToShortDateString()))
			{
				listView->Items->RemoveByKey(movies->getMovie(index)->Id.ToString());
				movies->RemoveAt(index);
				j--;
				flag = true;
			}
		}
	}
	if (flag == true) {
		Storage::save_AllMovie(movies);
	}

	System::GC::Collect(); //


	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::EditDBForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	System::GC::Collect(); //Очищение памяти после загрузки изображений в UpdateListView
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::button_Rearward_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::OpenForms["MenuForm1"]->Show();
	this->Close();
	delete this;
	//Добавить
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::EditDBForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	System::GC::Collect();
	return System::Void();
}
