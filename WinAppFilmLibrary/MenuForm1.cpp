#include "MenuForm1.h"
#include "EditDBForm.h"
#include "SearcForm.h"


void WinAppFilmLibrary::MenuForm1::InitializeBDFilms()
{
    Storage::load_Movie(movies);
    Storage::load_Id(movies);
    


   return;
}

System::Void WinAppFilmLibrary::MenuForm1::button1_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
    int count = movies->getCurrent_Id();
    MessageBox::Show(count.ToString(), "Закрытие", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    return System::Void();
}

System::Void WinAppFilmLibrary::MenuForm1::button_Editing_Click(System::Object^ sender, System::EventArgs^ e)
{
    EditDBForm^ iftr = gcnew EditDBForm(movies);
    iftr->StartPosition = this->StartPosition;
    iftr->ShowDialog();
    delete iftr;
    iftr = nullptr;
    System::GC::Collect();//
    return System::Void();
}

System::Void WinAppFilmLibrary::MenuForm1::button_Search_Click(System::Object^ sender, System::EventArgs^ e)
{
    SearcForm^ iftr = gcnew SearcForm(movies);
    iftr->ShowDialog();
    delete iftr;
    iftr = nullptr;
    //iftr = nullptr;
    //System::GC::Collect();
    return System::Void();
}
