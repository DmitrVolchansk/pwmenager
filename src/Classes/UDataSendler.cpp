//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDataSendler.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


TDataSendler::TDataSendler(const std::string &name,
	const std::string &login, const std::string &password):
	shortName(name), login(login), password(password)
{
}

__fastcall std TDataSendler::get_shortName() const noexcept
{
    return this->shortName;
}

__fastcall std TDataSendler::get_login() const noexcept
{
    return this->login;
}

__fastcall std TDataSendler::get_password() const noexcept
{
    return this->password;
}
