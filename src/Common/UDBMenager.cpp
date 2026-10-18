//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDBMenager.h"
#include "UDataValidater.h"
//---------------------------------------------------------------------------
namespace {
	Firedac::Comp::Client::TFDQuery* getQRY()
	{
		TFDQuery* qry = new TFDQuery(nullptr);
		qry->Connection = DataBaseModule->FDConnection;
		return qry;
	}
}
//---------------------------------------------------------------------------
namespace dbmenager {

	TInfoVector getAllNames()
	{
		TFDQuery* qry = getQRY();
		TInfoVector result;
		try
		{
			qry->SQL->Text = "SELECT id, name, last_update FROM auth";
			qry->Open();

			while (!qry->Eof){

				result.push_back( TMetaData {
					.id = qry->FieldByName("id")->AsInteger,
					.name = qry->FieldByName("name")->AsString,
					.isOld = datevalidation::isDateOld( qry->FieldByName("last_update")->AsString )
				});

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
	//-----------------------------------------------------------------------
	int addToDB(const TDataHolder& data)
	{
		TFDQuery* qry = getQRY();
		int newId;
		try
		{
			qry->SQL->Text = "INSERT INTO auth (name, login, password, last_update)"
							" VALUES (:name, :login, :password, :last_update)"
							" RETURNING id";
			qry->ParamByName("name")->AsString = data.name;
			qry->ParamByName("login")->AsString = data.login;
			qry->ParamByName("password")->AsString = data.pword;
			qry->ParamByName("last_update")->AsString = datevalidation::getCurrentDateToString();
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
	//-----------------------------------------------------------------------
	void delFromDB(const int id)
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
	//-----------------------------------------------------------------------
	void updDB(const int id, const TDataHolder& data)
	{
		TFDQuery* qry = getQRY();
		try
		{
			qry->SQL->Text = "UPDATE auth SET name = :name, login = :login, password = :pswrd, last_update = :lu WHERE id = :id";
			qry->ParamByName("name")->AsString = data.name;
			qry->ParamByName("login")->AsString = data.login;
			qry->ParamByName("pswrd")->AsString = data.pword;
			qry->ParamByName("lu")->AsString = datevalidation::getCurrentDateToString();
			qry->ParamByName("id")->AsInteger = id;

			qry->ExecSQL();
		}
		__finally
		{
			qry->Close();
			delete qry;
		}
	}
	//-----------------------------------------------------------------------
	TDataHolder getFromDB(const int id)
	{
		TFDQuery* qry = getQRY();
		try
		{
			qry->SQL->Text = "SELECT name, login, password FROM auth WHERE id = :id";
			qry->ParamByName("id")->AsInteger = id;
			qry->Open();
			return TDataHolder {
				.name = qry->FieldByName("name")->AsString,
				.login = qry->FieldByName("login")->AsString,
				.pword = qry->FieldByName("password")->AsString
			};
		}
		__finally
		{
			qry->Close();
			delete qry;
		}
		return TDataHolder{};
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
