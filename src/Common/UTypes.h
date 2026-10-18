#ifndef TYPES_H
#define TYPES_H
//---------------------------------------------------------------------------
struct TDataHolder {
	const String name;
	const String login;
	const String pword;
};
//---------------------------------------------------------------------------
using TUPtrDataHolder = std::unique_ptr<TDataHolder>;
//---------------------------------------------------------------------------
struct TMetaData {
	const int id;
	const String name;
    const bool isOld;
};
//---------------------------------------------------------------------------
#endif
