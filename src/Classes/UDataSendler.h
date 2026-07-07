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

		__fastcall TDataSendler() = default;
		__fastcall TDataSendler(std::string& name,
			std::string& login, std::string& password);
		__fastcall std::string get_shortName() const noexcept;
		__fastcall std::string get_login() const noexcept;
		__fastcall std::string get_password() const noexcept;

};
//---------------------------------------------------------------------------
#endif
