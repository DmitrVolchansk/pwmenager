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
#endif
