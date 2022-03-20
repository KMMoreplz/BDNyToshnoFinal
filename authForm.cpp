#include "authForm.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;
[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    BDNyToshnoFinal::authForm form;
    Application::Run(% form);
    BDNyToshnoFinal::MyForm form1;
    Application::Run(% form1);

}

System::Void BDNyToshnoFinal::authForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    //BDNyToshnoFinal::MyForm form1;
    MyForm^ f2 = gcnew MyForm;
    f2->Show();
    this->Hide();
    Application::ExitThread;
    return System::Void();
}