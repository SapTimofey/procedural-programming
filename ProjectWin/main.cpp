#include "main.h"

using namespace System;
using namespace System::Windows::Forms;

//System::Drawing::Color setColorBack = System::Drawing::Color::Black;
//System::Drawing::Color setColorText = System::Drawing::Color::Red;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ProjectWin::main form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}

System::Void ProjectWin::main::MyForm1_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void ProjectWin::main::exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Вы действительно хотите выйти?", "Выход", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
        this->Close();
        
}

System::Void ProjectWin::main::HW1_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_HW1->Location = System::Drawing::Point(12, 12);
    groupBox_HW1->Visible = true;
    back->Visible = true;
    settings->Visible = false;
}

System::Void ProjectWin::main::back_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = true;
    groupBox_another->Visible = true;
    //groupBox_HW1->Location = System::Drawing::Point(358, 443);
    groupBox_HW1->Visible = false;
    groupBox_settings->Visible = false;
    back->Visible = false;
    settings->Visible = true;
}

System::Void ProjectWin::main::settings_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_settings->Location = System::Drawing::Point(12, 12);
    groupBox_settings->Visible = true;
    back->Visible = true;
    settings->Visible = false;
}

System::Void ProjectWin::main::apply_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (listBox1->SelectedIndex == 0)
    {
        BackColor = System::Drawing::Color::Black;
        ForeColor = System::Drawing::Color::Red;
        groupBox_HW->ForeColor = System::Drawing::Color::Red;
        groupBox_HW1->ForeColor = System::Drawing::Color::Red;
        groupBox_another->ForeColor = System::Drawing::Color::Red;
        groupBox_settings->ForeColor = System::Drawing::Color::Red;
        listBox1->BackColor = System::Drawing::Color::Black;
        listBox1->ForeColor = System::Drawing::Color::Red;
    }
    else
    {
        BackColor = System::Drawing::Color::White;
        ForeColor = System::Drawing::Color::Black;
        groupBox_HW->ForeColor = System::Drawing::Color::Black;
        groupBox_HW1->ForeColor = System::Drawing::Color::Black;
        groupBox_another->ForeColor = System::Drawing::Color::Black;
        groupBox_settings->ForeColor = System::Drawing::Color::Black;
        listBox1->BackColor = System::Drawing::Color::White;
        listBox1->ForeColor = System::Drawing::Color::Black;
    }
}
