//---------------------------------------------------------------------------

#ifndef UDBMenagerH
#define UDBMenagerH
//---------------------------------------------------------------------------
#include <map>
using TMapIntStr = std::map<int, String>;
//---------------------------------------------------------------------------
#include "DMDataBase.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
class TDBMenager {
	private:
        static TFDQuery* getQRY();
	public:
		static TMapIntStr* getAllNames();
		static int addToDB(const TDataHolder* data);
		static void delFromDB(const int id);
		static void updDB(const int id, const TDataHolder* data);
		static TDataHolder* getFromDB(const int id);
};
//---------------------------------------------------------------------------
#endif
