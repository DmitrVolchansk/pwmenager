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
			"CREATE TABLE IF NOT EXISTS auth ("
			"  id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "  last_update TEXT NOT NULL,"
			"  name TEXT NOT NULL,"
			"  login TEXT NOT NULL,"
			"  password TEXT NOT NULL"
			");"
			"CREATE INDEX IF NOT EXISTS idx_users_name ON auth(name);";

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
