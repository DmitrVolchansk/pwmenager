//---------------------------------------------------------------------------

#ifndef UDBMenagerH
#define UDBMenagerH
//---------------------------------------------------------------------------
#include <map>
#include "DMdb.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
using TMapIntStr = std::map<int, String>;
using TUPtrMapIntStr = std::unique_ptr<TMapIntStr>;
//---------------------------------------------------------------------------
class TDBMenager {
	private:
        static TFDQuery* getQRY();
	public:
		static TUPtrMapIntStr getAllNames();
		static int addToDB(const TUPtrDataHolder& data);
		static void delFromDB(const int id);
		static void updDB(const int id, const TUPtrDataHolder& data);
		static TUPtrDataHolder getFromDB(const int id);
};
//---------------------------------------------------------------------------
#endif
