//---------------------------------------------------------------------------


#pragma hdrstop

#include "DMdb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
TDataBaseModule *DataBaseModule;
//---------------------------------------------------------------------------
__fastcall TDataBaseModule::TDataBaseModule(TComponent* Owner)
	: TDataModule(Owner), isDBExits(false)
{
}

void TDataBaseModule::Initialize()
{
	try
	{
		String dbFile = FDConnection->Params->Values["Database"];
		isDBExits = FileExists(dbFile);

		FDConnection->Open();
		if (!isDBExits)
		{
			CreateTables();
		}
	}
	catch (Exception& e)
	{
		ShowMessage("Error: " + e.Message);
    }
}

bool TDataBaseModule::CreateTables()
{
    try
	{
		String SQL =

			"CREATE TABLE IF NOT EXISTS metadata ("
			"  id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"  name TEXT NOT NULL,"
			"  last_update TEXT NOT NULL,"
			"  kind INTEGER NOT NULL"
			");"

			"CREATE TABLE IF NOT EXISTS passwords ("
			"  id INTEGER PRIMARY KEY"
			"  REFERENCES metadata(id)"
			"		ON DELETE CASCADE"
			"		ON UPDATE CASCADE,"
			"  password TEXT NOT NULL"
			");"

			"CREATE TABLE IF NOT EXISTS logins ("
			"  id INTEGER PRIMARY KEY"
			"  REFERENCES metadata(id)"
			"  		ON DELETE CASCADE"
			"		ON UPDATE CASCADE,"
			"  login TEXT NOT NULL"
			");"

			"CREATE TABLE IF NOT EXISTS urls ("
			"  id INTEGER PRIMARY KEY"
			"  REFERENCES metadata(id)"
			"		ON DELETE CASCADE"
            "		ON UPDATE CASCADE,"
			"  url TEXT NOT NULL"
			");";

		FDConnection->ExecSQL(SQL);
		return true;
	}
	catch (Exception& E)
	{
		ShowMessage("Error: " + E.Message);
        return false;
	}
}
//---------------------------------------------------------------------------
