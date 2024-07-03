#include "EditDBForm.h"
#include "InsertForm.h"
#include "CardForm.h"

void WinAppFilmLibrary::EditDBForm::UpdateListView()
{
	int count_items = listView->Items->Count;
	while (listView->Items->Count != 0) {
		listView->Items->RemoveAt(0);
	}
	System::GC::Collect();
	listView->Items->Clear();
	listView->DataBindings->Clear();
	listView->BeginUpdate();
	ImageList^ imageList = gcnew ImageList();
	imageList->ImageSize = System::Drawing::Size(110, 120); //
	int count = 0;//Добавить
	System::GC::Collect();//Сборка мусора

	for each (Movie ^ movie in sr->movieList)
	{   //Bitmap
		Bitmap^ a = gcnew Bitmap(movie->Poster);
				
		ListViewItem^ item = gcnew ListViewItem();

		item->ImageIndex = count++; //

		//item->ImageKey = movie->Id.ToString(); //


		imageList->Images->Add(movie->Id.ToString(), a);

		item->SubItems->Add(movie->Title);
		item->SubItems->Add(movie->Data.ToShortDateString());
		item->SubItems->Add(String::Join(", ", movie->Genre));
		item->SubItems->Add(movie->Rating.ToString());
		item->SubItems->Add(movie->Annotation);
		item->SubItems->Add(movie->Id.ToString());
		listView->Items->Add(item);
		//delete item;
		a = nullptr;
		delete a;
	}
	listView->SmallImageList = imageList;
	listView->EndUpdate();
	//listView->DataBindings->Clear();
	System::GC::Collect(); //Добавить
	return;
}

void WinAppFilmLibrary::EditDBForm::GB()
{
	System::GC::Collect();
	return;
}

System::Void WinAppFilmLibrary::EditDBForm::button_Insert_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::GC::Collect();
    InsertForm^ insertForm = gcnew InsertForm(this,sr);
    
    insertForm->ShowDialog();
	delete insertForm;
	insertForm = nullptr;
	UpdateListView();
	System::GC::Collect();

    return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::listView_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	CardForm^iftr = gcnew CardForm(Convert::ToInt32(listView->SelectedItems[0]->SubItems[6]->Text),sr);
	iftr->Owner = this; //Устанавливаем родителя
	iftr->Left = this->Left;
	iftr->Top = this->Top;
	iftr->ShowDialog();
	delete iftr; //Удяляем форму
	iftr = nullptr; // стираем ссылку
	//UpdateListView();
	System::GC::Collect();
	
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		int id = Convert::ToInt32(listView->SelectedItems[0]->SubItems[6]->Text);
		//button_Delete->Enabled = false;
		for each (Movie ^ movie in sr->movieList) {
			if (movie->Id == id) {
				sr->movieList->Remove(movie);
				break;
			}
		}
		UpdateListView();
		System::GC::Collect();//
	}
	catch(System::Exception^){
		MessageBox::Show("Выберите фильм", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	System::GC::Collect();
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::button1_Duplicate_Click(System::Object^ sender, System::EventArgs^ e)
{
	int index = 0;
	for (int i = 0; i < sr->movieList->Count; i++) {
		for (int j = i + 1; j < sr->movieList->Count; j++)
		{
			index = j;
			if ((sr->movieList[i]->Title == sr->movieList[j]->Title) && (sr->movieList[i]->Data.ToShortDateString() == sr->movieList[j]->Data.ToShortDateString()))
			{
				sr->movieList->RemoveAt(index);
				j--;
			}
		}
	}
	UpdateListView();
	System::GC::Collect();
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::EditDBForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	System::GC::Collect();
	return System::Void();
}
