#include "main.h"

int reserv = 0;

// reserv = 0 - меню
// reserv = 1 - меню д/з 1
// reserv = 2 - меню д/з 2
// reserv = 3 - меню д/з 3
// reserv = 4 - меню д/з 4
// reserv = 5 - меню д/з 5
// reserv = 6 - шарики

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
    groupBox_HW1->Visible = true;
    back->Visible = true;
}

System::Void ProjectWin::main::HW2_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_HW2->Visible = true;
    back->Visible = true;
}

System::Void ProjectWin::main::HW3_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_HW3->Visible = true;
    back->Visible = true;
}

System::Void ProjectWin::main::HW4_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_HW4->Visible = true;
    back->Visible = true;
}

System::Void ProjectWin::main::back_Click(System::Object^ sender, System::EventArgs^ e)
{
    switch (reserv)
    {
    case 0:
    {
        groupBox_HW->Visible = true;
        groupBox_another->Visible = true;
        groupBox_HW1->Visible = false;
        groupBox_HW2->Visible = false;
        groupBox_HW3->Visible = false;
        groupBox_HW4->Visible = false;
        groupBox_settings->Visible = false;
        groupBox_balls->Visible = false;
        back->Visible = false;
        settings->Visible = true;
        break;
    }
    case 1:
    {
        groupBox_HW1->Visible = true;
        groupBox_settings->Visible = false;
        settings->Visible = true;
        reserv = 0;
        break;
    }
    case 2:
    {
        groupBox_HW2->Visible = true;
        groupBox_settings->Visible = false;
        settings->Visible = true;
        reserv = 0;
        break;
    }
    case 3:
    {
        groupBox_HW3->Visible = true;
        groupBox_settings->Visible = false;
        settings->Visible = true;
        reserv = 0;
        break;
    }
    case 4:
    {
        groupBox_HW4->Visible = true;
        groupBox_settings->Visible = false;
        settings->Visible = true;
        reserv = 0;
        break;
    }
    case 6:
    {
        groupBox_balls->Visible = true;
        groupBox_settings->Visible = false;
        settings->Visible = true;
        reserv = 0;
        break;
    }
    }
}

System::Void ProjectWin::main::settings_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (groupBox_HW1->Visible == true) reserv = 1;
    else if (groupBox_HW2->Visible == true) reserv = 2;
    else if (groupBox_HW3->Visible == true) reserv = 3;
    else if (groupBox_HW4->Visible == true) reserv = 4;
    else if (groupBox_balls->Visible == true) reserv = 6;

    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_HW1->Visible = false;
    groupBox_HW2->Visible = false;
    groupBox_HW3->Visible = false;
    groupBox_HW4->Visible = false;
    groupBox_balls->Visible = false;
    groupBox_settings->Visible = true;
    back->Visible = true;
    settings->Visible = false;
}

System::Void ProjectWin::main::apply_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_dark->Checked == true)
    {
        BackColor = System::Drawing::Color::Black;
        ForeColor = System::Drawing::Color::Red;
        groupBox_HW->ForeColor = System::Drawing::Color::Red;
        groupBox_HW1->ForeColor = System::Drawing::Color::Red;
        groupBox_HW2->ForeColor = System::Drawing::Color::Red;
        groupBox_HW3->ForeColor = System::Drawing::Color::Red;
        groupBox_another->ForeColor = System::Drawing::Color::Red;
        groupBox_settings->ForeColor = System::Drawing::Color::Red;
        groupBox_balls->ForeColor = System::Drawing::Color::Red;
        textBox_cntball->ForeColor = System::Drawing::Color::Red;
        textBox_cntball->BackColor = System::Drawing::Color::Black;
    }
    else if(checkBox_light->Checked == true)
    {
        BackColor = System::Drawing::Color::White;
        ForeColor = System::Drawing::Color::Black;
        groupBox_HW->ForeColor = System::Drawing::Color::Black;
        groupBox_HW1->ForeColor = System::Drawing::Color::Black;
        groupBox_HW2->ForeColor = System::Drawing::Color::Black;
        groupBox_HW3->ForeColor = System::Drawing::Color::Black;
        groupBox_another->ForeColor = System::Drawing::Color::Black;
        groupBox_settings->ForeColor = System::Drawing::Color::Black;
        groupBox_balls->ForeColor = System::Drawing::Color::Black;
        textBox_cntball->ForeColor = System::Drawing::Color::Black;
        textBox_cntball->BackColor = System::Drawing::Color::White;
    }
}

System::Void ProjectWin::main::balls1_Click(System::Object^ sender, System::EventArgs^ e)
{
    groupBox_HW->Visible = false;
    groupBox_another->Visible = false;
    groupBox_balls->Visible = true;
    back->Visible = true;
}

System::Void ProjectWin::main::calculate_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox_cntball->Text != "")
    {
        label_allpermut->Text = balls_allpermut(textBox_cntball->Text);
        if (label_allpermut->Text != "") label_right->Text = balls_right(textBox_cntball->Text);
        else label_right->Text = "";
    }
}

System::Void ProjectWin::main::checkBox_light_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_light->Checked == true)
        checkBox_dark->Checked = false;
    else checkBox_dark->Checked = true;
}

System::Void ProjectWin::main::checkBox_dark_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_dark->Checked == true)
        checkBox_light->Checked = false;
    else checkBox_light->Checked = true;
}
