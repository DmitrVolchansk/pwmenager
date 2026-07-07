//---------------------------------------------------------------------------

#ifndef UDataSendlerH
#define UDataSendlerH
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
class TDataSendler {
	private:

		const std::string shortName = "name";
		const std::string login = "login";
		const std::string password = "password";

	public:

		TDataSendler() = default;
		TDataSendler(std::string& name,
			std::string& login, std::string& password);
		std::string __fastcall get_shortName() const noexcept;
		std::string __fastcall get_login() const noexcept;
		std::string __fastcall get_password() const noexcept;

};
//---------------------------------------------------------------------------
#endif
