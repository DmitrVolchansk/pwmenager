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
__fastcall std::string TDataSendler::get_shortName() const noexcept
{
	return this->shortName;
}
//---------------------------------------------------------------------------
__fastcall std::string TDataSendler::get_login() const noexcept
{
	return this->login;
}
//---------------------------------------------------------------------------
__fastcall std::string TDataSendler::get_password() const noexcept
{
	return this->password;
}
//---------------------------------------------------------------------------
