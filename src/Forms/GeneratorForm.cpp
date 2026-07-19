//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "GeneratorForm.h"
//---------------------------------------------------------------------------
#include <random>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFGenerator *FGenerator;
//---------------------------------------------------------------------------
constexpr std::string_view lowerCase = "abcdefghijklmnopqrstuvwxyz";
constexpr std::string_view upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr std::string_view digits = "0123456789";
constexpr std::string_view splChars = "!@#$%^&*";
//---------------------------------------------------------------------------
__fastcall TFGenerator::TFGenerator(TComponent* Owner, const String& btnCap)
	: TForm(Owner)
{
	generate();
    SelectButton->Text = btnCap;
}
//---------------------------------------------------------------------------
System::String TFGenerator::getPassword() const noexcept
{
	return this->GeneratorEdit->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFGenerator::SwitchSeedVisible(TObject *Sender)
{
	SeedEdit->Visible = SeedCheck->IsChecked;
}
//---------------------------------------------------------------------------
std::string TFGenerator::getCharSet() const noexcept
{
	std::string resCharSet;
	resCharSet.append( lowerCase.data(), lowerCase.size() );

	if (LettersCheck->IsChecked)
		resCharSet.append( upperCase.data(), upperCase.size() );

	if (DigitsCheck->IsChecked)
		resCharSet.append( digits.data(), digits.size() );

	if (SCharsCheck->IsChecked)
		resCharSet.append( splChars.data(), splChars.size() );

	return resCharSet;
}
//---------------------------------------------------------------------------
void TFGenerator::generate()
{
	const std::string charSet = getCharSet();

	std::random_device rdd;
	std::mt19937 gen(rdd());
	std::uniform_int_distribution<> distrib(0, charSet.size() - 1);

	std::string result;
	int len = LengthSpin->Value;
	for (auto i = 0; i < len; i++)
		result.push_back( charSet[distrib(gen)] );

	GeneratorEdit->Text = result.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TFGenerator::ReroleBtnClick(TObject *Sender)
{
	generate();
}
//---------------------------------------------------------------------------

