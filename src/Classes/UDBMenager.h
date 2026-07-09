//---------------------------------------------------------------------------

#ifndef UDBMenagerH
#define UDBMenagerH
//---------------------------------------------------------------------------
#include "DMDataBase.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
class TDBMenager {
	private:
        static TFDQuery* getQRY();
	public:
        static TStringList* getAllNames();
		static void addToDB(const TDataHolder* data);
		static void delFromDB(const String& name);
		static void updDB(const TDataHolder* data);
		static TDataHolder* getFromDB(const String& name);
};
//---------------------------------------------------------------------------
#endif
