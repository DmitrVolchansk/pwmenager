//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDataSendler.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
TDataSendler::TDataSendler(std::string& name,
	std::string& login, std::string& password):
	shortName(name), login(login), password(password)
{
}
//---------------------------------------------------------------------------
std::string __fastcall TDataSendler::get_shortName() const noexcept
{
	return this->shortName;
}
//---------------------------------------------------------------------------
 std::string __fastcall TDataSendler::get_login() const noexcept
{
	return this->login;
}
//---------------------------------------------------------------------------
std::string __fastcall TDataSendler::get_password() const noexcept
{
	return this->password;
}
//---------------------------------------------------------------------------
