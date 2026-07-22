//---------------------------------------------------------------------------

#ifndef UDBMenagerH
#define UDBMenagerH
//---------------------------------------------------------------------------
#include <vector>
#include "DMdb.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
using TInfoVector = std::vector<TMetaData>;
//---------------------------------------------------------------------------
class TDBMenager {
	private:
        static TFDQuery* getQRY();
	public:
		static TInfoVector getAllNames();
		static int addToDB(const TUPtrDataHolder data);
		static void delFromDB(const int id);
		static void updDB(const int id, const TUPtrDataHolder data);
		static TUPtrDataHolder getFromDB(const int id);
};
//---------------------------------------------------------------------------
#endif
