#include "EditDBForm.h"
#include "InsertForm.h"

void WinAppFilmLibrary::EditDBForm::UpdateListView()
{
	listView->Items->Clear();
	ImageList^ imageList = gcnew ImageList();
	imageList->ImageSize = System::Drawing::Size(100, 100);

	for each (Movie ^ movie in sr->movieList)
	{
		ListViewItem^ item = gcnew ListViewItem();
		item->ImageIndex = movie->Id;
		imageList->Images->Add(movie->Title, gcnew Bitmap("C:\\Movie_Library\\Image.jpg"));

		item->SubItems->Add(movie->Title);
		item->SubItems->Add(movie->Data.ToString());
		item->SubItems->Add(String::Join(", ", movie->Genre));
		item->SubItems->Add(movie->Rating.ToString());
		item->SubItems->Add(movie->Annotation);
		item->SubItems->Add(movie->Id.ToString());
		listView->Items->Add(item);
	}
	listView->SmallImageList = imageList;
    return;
}

System::Void WinAppFilmLibrary::EditDBForm::button_Insert_Click(System::Object^ sender, System::EventArgs^ e)
{
    InsertForm^ insertForm = gcnew InsertForm(this,sr);
    
    insertForm->ShowDialog();

    return System::Void();
}
