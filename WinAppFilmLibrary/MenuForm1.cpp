#include "MenuForm1.h"
#include "EditDBForm.h"
#include "SearcForm.h"


void WinAppFilmLibrary::MenuForm1::InitializeBDFilms()
{
    this->sr->load_Movie();
    this->sr->load_Id();
    


   return;
}

System::Void WinAppFilmLibrary::MenuForm1::button1_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
    int count = sr->Current_Id;
    MessageBox::Show(count.ToString(), "Закрытие", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    return System::Void();
}

System::Void WinAppFilmLibrary::MenuForm1::button_Editing_Click(System::Object^ sender, System::EventArgs^ e)
{
    EditDBForm^ iftr = gcnew EditDBForm(sr);
    iftr->ShowDialog();
    delete iftr;
    iftr = nullptr;
    System::GC::Collect();//
    return System::Void();
}

System::Void WinAppFilmLibrary::MenuForm1::button_Search_Click(System::Object^ sender, System::EventArgs^ e)
{
    SearcForm^ iftr = gcnew SearcForm(sr);
    iftr->ShowDialog();
    delete iftr;
    iftr = nullptr;
    //iftr = nullptr;
    //System::GC::Collect();
    return System::Void();
}
