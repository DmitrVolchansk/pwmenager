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
namespace dbmenager {
	TInfoVector getAllNames();
	int addToDB(const TDataHolder& data);
	void delFromDB(const int id);
	void updDB(const int id, const TDataHolder& data);
	TDataHolder getFromDB(const int id);
};
//---------------------------------------------------------------------------
#endif
