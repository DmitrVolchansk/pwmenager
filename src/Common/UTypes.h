#ifndef TYPES_H
#define TYPES_H
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
using TString = std::string;
//---------------------------------------------------------------------------
struct TDataHolder {
	const TString name = "name";
	const TString login = "login";
	const TString pword = "password";
};
//---------------------------------------------------------------------------
#endif
