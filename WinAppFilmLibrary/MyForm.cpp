#include "MyForm.h"
#include "MenuForm1.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	WinAppFilmLibrary::MyForm form;
	Application::Run(% form);

}

System::Void WinAppFilmLibrary::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("����� �����������", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	MenuForm1^ iftr = gcnew MenuForm1();
	iftr->Left = this->Left;
	iftr->Top = this->Top;
	iftr->Show();
	this->Hide();
	return System::Void();
}
