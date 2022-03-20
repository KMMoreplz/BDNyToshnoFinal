#include "MyForm.h"
using namespace System::Data::OleDb;
System::Void BDNyToshnoFinal::MyForm::âûõîäToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
//çàãðóçèòü
System::Void BDNyToshnoFinal::MyForm::îáíîâèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionsString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseCpp.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionsString);

    dbConnection->Open();
    String^ query = "SELECT * FROM [Employers]";
    OleDbCommand^ dbComand = gcnew OleDbCommand(query,dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader();

    if (dbReader->HasRows == false) {
        MessageBox::Show("Error of reading!", "ERROR!");
    }
    else {
        while (dbReader->Read()) {
            dataGridView1->Rows->Add(dbReader["ID"], dbReader["FIO"], dbReader["Phone"], dbReader["department"], dbReader["post"]);
        }
    }
    dbReader->Close();
    dbConnection->Close();
    return System::Void();
}

System::Void BDNyToshnoFinal::MyForm::äîáàâèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count!=1)
    {
        MessageBox::Show("Chose 1 string to add!", "Attention!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[1]->Value == nullptr || 
        dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[4]->Value == nullptr  )
    {
        MessageBox::Show("Not all DATA entered!", "Attention!");
        return;
    }
    String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ FIO = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Phone = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ department = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ post = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

    String^ connectionsString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseCpp.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionsString);

    dbConnection->Open();
    String^ query = "INSERT INTO [Employers] VALUES(" + ID +",'" + FIO+ "'," + Phone+ ",'" + department+ "','" + post + "')";
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
    
    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("Error", "Error");
    else
        MessageBox::Show("OK!", "SUCCESS!");

    dbConnection->Close();
    return System::Void();
}
//îáíîâèòü)
System::Void BDNyToshnoFinal::MyForm::óäàëèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Chose 1 string to add!", "Attention!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[4]->Value == nullptr)
    {
        MessageBox::Show("Not all DATA entered!", "Attention!");
        return;
    }
    String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ FIO = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Phone = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ department = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ post = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

    String^ connectionsString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseCpp.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionsString);

    dbConnection->Open();
    String^ query = "UPDATE [Employers] SET FIO='"+ FIO +"', Phone=" + Phone +", department='" + department +"', post='" + post +"' WHERE ID=" + ID;
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("Error", "Error");
    else
        MessageBox::Show("OK!", "SUCCESS!");

    dbConnection->Close();
    return System::Void();
}
//óäàëèòü*
System::Void BDNyToshnoFinal::MyForm::ñîõðàíèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Chose 1 string to add!", "Attention!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
    {
        MessageBox::Show("Not all DATA entered!", "Attention!");
        return;
    }
    String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
  

    String^ connectionsString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=DatabaseCpp.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionsString);

    dbConnection->Open();
    String^ query = "DELETE FROM [Employers] WHERE ID=" + ID;
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("Error", "Error");
    else {
        MessageBox::Show("OK!", "SUCCESS!");
        dataGridView1->Rows->RemoveAt(index);
    }
    dbConnection->Close();
    return System::Void();
}
