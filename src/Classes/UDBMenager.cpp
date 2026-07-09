//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDBMenager.h"
//---------------------------------------------------------------------------
Firedac::Comp::Client::TFDQuery* TDBMenager::getQRY()
{
	TFDQuery* qry = new TFDQuery(nullptr);
	qry->Connection = DBModule->FDConnection;
    return qry;
}
//---------------------------------------------------------------------------
System::Classes::TStringList* TDBMenager::getAllNames()
{
	TFDQuery* qry = getQRY();
	auto strList = new TStringList();
	try
	{
		qry->SQL->Text = "SELECT name FROM auth";
        qry->Open();
		while (!qry->Eof){
			strList->Add( qry->FieldByName("name")->AsString );
            qry->Next();
		}
	} __finally {
		qry->Close();
        delete qry;
    }
    return strList;
}
//---------------------------------------------------------------------------
void TDBMenager::addToDB(const TDataHolder* data)
{
	TFDQuery* qry = getQRY();
	try
	{
		qry->SQL->Text = "INSERT INTO auth (name, login, password) VALUES (:name, :login, :password)";
		qry->ParamByName("name")->AsString = data->name;
		qry->ParamByName("login")->AsString = data->login;
		qry->ParamByName("password")->AsString = data->pword;
		qry->ExecSQL();
	}
	__finally
	{
		qry->Close();
		delete qry;
	}
}
//---------------------------------------------------------------------------
void TDBMenager::delFromDB(const String& name)
{
	TFDQuery* qry = getQRY();
	try
	{
		qry->SQL->Text = "DELETE FROM auth WHERE name = :name";
		qry->ParamByName("name")->AsString = name;
		qry->ExecSQL();
    }
    __finally
    {
        qry->Close();
        delete qry;
	}
}
//---------------------------------------------------------------------------
void TDBMenager::updDB(const TDataHolder* data)
{
	// TODO: update wth id
}
//---------------------------------------------------------------------------
TDataHolder* TDBMenager::getFromDB(const String& name)
{
    TFDQuery* qry = getQRY();
    TDataHolder* data = nullptr;
	try
	{
		qry->SQL->Text = "SELECT * FROM auth WHERE name = :name" ;
        qry->ParamByName("name")->AsString = name;
        qry->Open();
		data = new TDataHolder{
			.name = name,
			.login = qry->FieldByName("login")->AsString,
			.pword = qry->FieldByName("password")->AsString
		};
	}
	__finally
	{
		qry->Close();
		delete qry;
	}
    return data;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
