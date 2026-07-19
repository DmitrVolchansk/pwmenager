//---------------------------------------------------------------------------

#pragma hdrstop

#include "DMDataBase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
TDataModuleDB *DBModule = nullptr;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TDataModuleDB::TDataModuleDB(TComponent* Owner)
	: TDataModule(Owner), isDBExits(false)
{
}

void TDataModuleDB::Initialize()
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

bool TDataModuleDB::CreateTables()
{
    try
	{
		String SQL =
			"CREATE TABLE IF NOT EXISTS auth ("
			"  id INTEGER PRIMARY KEY AUTOINCREMENT,"
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
