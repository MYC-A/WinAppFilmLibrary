#include "EditDBForm.h"
#include "InsertForm.h"
#include "CardForm.h"

void WinAppFilmLibrary::EditDBForm::UpdateListView()
{
	listView->Items->Clear();
	listView->DataBindings->Clear();
	System::GC::Collect();//Сборка мусора
	listView->BeginUpdate();
	ImageList^ imageList = gcnew ImageList();
	imageList->ImageSize = System::Drawing::Size(100, 100);
	int count = 0;//Добавить
	
	for each (Movie ^ movie in sr->movieList)
	{
		ListViewItem^ item = gcnew ListViewItem();
		item->ImageIndex = count++;
		imageList->Images->Add(movie->Id.ToString(), gcnew Bitmap("C:\\Movie_Library\\Image.jpg"));

		item->SubItems->Add(movie->Title);
		item->SubItems->Add(movie->Data.ToString());
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

System::Void WinAppFilmLibrary::EditDBForm::button_Insert_Click(System::Object^ sender, System::EventArgs^ e)
{
    InsertForm^ insertForm = gcnew InsertForm(this,sr);
    
    insertForm->ShowDialog();

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
	}
	catch(System::Exception^){
		MessageBox::Show("Выберите фильм", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	
	return System::Void();
}

System::Void WinAppFilmLibrary::EditDBForm::button1_Duplicate_Click(System::Object^ sender, System::EventArgs^ e)
{
	int index = 0;
	int flag = false; // Вывод что дубликаты удалены
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
