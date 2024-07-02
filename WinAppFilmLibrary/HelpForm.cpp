#include "HelpForm.h"

System::Void WinAppFilmLibrary::HelpForm::HelpForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    array<String^>^ ss2 = { "               Правила пользования приложением\n\n","\r Работа с начальным окном\n\ ", "\rПри нажатии на кнопку 'Кинотека' вы сможете перейти в меню приложения", "DDDDDDDD","EEEEEEEE" };
    String^ s = Environment::NewLine;
    array<System::Drawing::Font^>^ fnt = gcnew array<System::Drawing::Font^>(5);

    richTextBox_HelpText->SelectionStart = 0;
    richTextBox_HelpText->SelectionLength = 13;
    System::Drawing::FontStyle newFontStyle;
    System::Drawing::Font^ currentFont = richTextBox_HelpText->SelectionFont;
    newFontStyle = richTextBox_HelpText->SelectionFont->Style | FontStyle::Bold;

    fnt[0] = gcnew System::Drawing::Font("Timew New Roman", 16, System::Drawing::FontStyle::Bold);
    fnt[1] = gcnew System::Drawing::Font("Timew New Roman", 14);
    //fnt[2] = gcnew System::Drawing::Font("Constantia", 14);
    //fnt[3] = gcnew System::Drawing::Font("Dotum", 14, System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Strikeout);
    //fnt[4] = gcnew System::Drawing::Font("ENAVERS MT", 12, System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Strikeout);
    
    
    for (int i = 0; i < 2; i++)
    {
        richTextBox_HelpText->SelectionFont = fnt[i];
        richTextBox_HelpText->AppendText(ss2[i] + s);
    }

    richTextBox_HelpText->SelectionFont = gcnew System::Drawing::Font(currentFont->FontFamily, currentFont->Size, newFontStyle);

   
    return System::Void();
}
