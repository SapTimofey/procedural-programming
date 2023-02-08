#include "HomeWork1_menu.h"
#include "HomeWork1.h"


System::Void ProjectWin::HomeWork1_menu::back_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    main^ m = gcnew main();
    m->Show();
}

System::Void ProjectWin::HomeWork1_menu::task_name_Click(System::Object^ sender, System::EventArgs^ e)
{
    
}
