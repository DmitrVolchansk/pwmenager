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
TUPtrMapIntStr TDBMenager::getAllNames()
{
	TFDQuery* qry = getQRY();
	auto result = std::make_unique<TMapIntStr>();
	try
	{
		qry->SQL->Text = "SELECT id, name FROM auth";
		qry->Open();

		while (!qry->Eof){
            int id = qry->FieldByName("id")->AsInteger;
			String name = qry->FieldByName("name")->AsString;
			result->emplace(id, name);
			qry->Next();
		}
	}
	__finally
	{
		qry->Close();
		delete qry;
    }
	return result;
}
//---------------------------------------------------------------------------
int TDBMenager::addToDB(const TUPtrDataHolder& data)
{
	TFDQuery* qry = getQRY();
    int newId;
	try
	{
		qry->SQL->Text = "INSERT INTO auth (name, login, password)"
						" VALUES (:name, :login, :password)"
						" RETURNING id";
		qry->ParamByName("name")->AsString = data->name;
		qry->ParamByName("login")->AsString = data->login;
		qry->ParamByName("password")->AsString = data->pword;
		qry->Open();
		newId = qry->FieldByName("id")->AsInteger;
	}
	__finally
	{
		qry->Close();
		delete qry;
	}
    return newId;
}
//---------------------------------------------------------------------------
void TDBMenager::delFromDB(const int id)
{
	TFDQuery* qry = getQRY();
	try
	{
		qry->SQL->Text = "DELETE FROM auth WHERE id = :id";
		qry->ParamByName("id")->AsInteger = id;
		qry->ExecSQL();
    }
    __finally
    {
        qry->Close();
        delete qry;
	}
}
//---------------------------------------------------------------------------
void TDBMenager::updDB(const int id, const TUPtrDataHolder& data)
{
	TFDQuery* qry = getQRY();
	try
	{
		qry->SQL->Text = "UPDATE auth SET name = :name, login = :login, password = :pswrd WHERE id = :id";
		qry->ParamByName("name")->AsString = data->name;
		qry->ParamByName("login")->AsString = data->login;
		qry->ParamByName("pswrd")->AsString = data->pword;
		qry->ParamByName("id")->AsInteger = id;
		qry->ExecSQL();
	}
	__finally
	{
		qry->Close();
		delete qry;
	}
}
//---------------------------------------------------------------------------
TUPtrDataHolder TDBMenager::getFromDB(const int id)
{
    TFDQuery* qry = getQRY();
	TUPtrDataHolder data;
	try
	{
		qry->SQL->Text = "SELECT name, login, password FROM auth WHERE id = :id";
		qry->ParamByName("id")->AsInteger = id;
		qry->Open();
		data = std::make_unique<TDataHolder>(TDataHolder {
			.name = qry->FieldByName("name")->AsString,
			.login = qry->FieldByName("login")->AsString,
			.pword = qry->FieldByName("password")->AsString
		});
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
