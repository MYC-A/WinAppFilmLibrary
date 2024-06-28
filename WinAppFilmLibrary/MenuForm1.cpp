#include "MenuForm1.h"


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
