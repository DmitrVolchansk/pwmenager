//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDBMenager.h"
#include "UDateValidation.h"
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

	TMetaDTOVector getAllNames()
	{
		std::unique_ptr<TFDQuery> qry{getQRY()};
		TMetaDTOVector result;
        qry->Connection->StartTransaction();
		try
		{
			qry->SQL->Text = "SELECT id, name, last_update FROM metadata";
			qry->Open();

			while (!qry->Eof){

				result.push_back( TMetaData {
					.id = qry->FieldByName("id")->AsInteger,
					.name = qry->FieldByName("name")->AsString,
					.isOld = datevalidation::isDateOld( qry->FieldByName("last_update")->AsString )
				});

				qry->Next();
			}

            qry->Connection->Commit();
		}
		catch (...)
		{
            qry->Connection->Rollback();
		}
        qry->Close();
		return result;
	}
	//-----------------------------------------------------------------------
	int addToDB(const TDataHolder& data)
	{
		std::unique_ptr<TFDQuery> qry{getQRY()};
		int newId;
        qry->Connection->StartTransaction();
		try
		{
			qry->SQL->Text = "INSERT INTO metadata (name, last_update)"
							 "VALUES (:name, :lu);";
			qry->ParamByName("name")->AsString = data.name;
			qry->ParamByName("lu")->AsString = datevalidation::getCurrentDateToString();
			qry->ExecSQL();
			newId = qry->Connection->ExecSQLScalar("SELECT last_insert_rowid()");

			qry->SQL->Text = "INSERT INTO logins "
							 "VALUES (:id, :login);";
			qry->ParamByName("id")->AsInteger = newId;
			qry->ParamByName("login")->AsString = data.login;
			qry->ExecSQL();

			qry->SQL->Text = "INSERT INTO passwords "
							 "VALUES (:id, :password);";
			qry->ParamByName("id")->AsInteger = newId;
			qry->ParamByName("password")->AsString = data.pword;
			qry->ExecSQL();

			qry->Connection->Commit();
		}
		catch (...)
		{
			qry->Connection->Rollback();
		}
		qry->Close();
		return newId;
	}
	//-----------------------------------------------------------------------
	void delFromDB(const int id)
	{
		std::unique_ptr<TFDQuery> qry{getQRY()};
		qry->Connection->StartTransaction();
		try
		{
			qry->SQL->Text = "DELETE FROM metadata WHERE id = :id;";
			qry->ParamByName("id")->AsInteger = id;
			qry->ExecSQL();

			qry->Connection->Commit();
		}
		catch (...)
		{
			qry->Connection->Rollback();
		}
		qry->Close();
	}
	//-----------------------------------------------------------------------
	void updDB(const int id, const TDataHolder& data)
	{
		std::unique_ptr<TFDQuery> qry{getQRY()};
		qry->Connection->StartTransaction();
		try
		{
			qry->SQL->Text = "UPDATE metadata SET name = :name, last_update = :lu "
							 "WHERE id = :id;";
			qry->ParamByName("name")->AsString = data.name;
			qry->ParamByName("lu")->AsString = datevalidation::getCurrentDateToString();
			qry->ParamByName("id")->AsInteger = id;
			qry->ExecSQL();

			qry->SQL->Text = "UPDATE logins SET login = :login "
							 "WHERE id = :id;";
			qry->ParamByName("login")->AsString = data.login;
            qry->ParamByName("id")->AsInteger = id;
            qry->ExecSQL();

			qry->SQL->Text = "UPDATE passwords SET password = :psword "
							 "WHERE id = :id";
			qry->ParamByName("psword")->AsString = data.pword;
            qry->ParamByName("id")->AsInteger = id;
			qry->ExecSQL();

            qry->Connection->Commit();
		}
		catch (...)
		{
            qry->Connection->Rollback();
		}
		qry->Close();
	}
	//-----------------------------------------------------------------------
	TDataHolder getFromDB(const int id)
	{
		std::unique_ptr<TFDQuery> qry{getQRY()};
		try
		{
			qry->SQL->Text = "SELECT metadata.name, logins.login, passwords.password "
							 "FROM metadata "
							 "INNER JOIN logins ON metadata.id = logins.id "
							 "INNER JOIN passwords ON metadata.id = passwords.id "
							 "WHERE metadata.id = :id;";
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
		}
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
