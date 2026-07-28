//---------------------------------------------------------------------------

#ifndef GeneratorFormH
#define GeneratorFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.EditBox.hpp>
#include <FMX.SpinBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TFGenerator : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GeneratorGBox;
	TEdit *GeneratorEdit;
	TSpeedButton *CopyBtn;
	TSpeedButton *ReroleBtn;
	TGroupBox *SettingsHolderGBox;
	TGroupBox *UsesCheckHolderGBox;
	TGroupBox *LengthHolderGBox;
	TSpinBox *LengthSpin;
	TCheckBox *LettersCheck;
	TCheckBox *DigitsCheck;
	TCheckBox *SCharsCheck;
	TCheckBox *SeedCheck;
	TCornerButton *SelectButton;
	TEdit *SeedEdit;
	void __fastcall SwitchSeedVisible(TObject *Sender);
	void __fastcall ReroleBtnClick(TObject *Sender);
	void __fastcall CopyBtnClick(TObject *Sender);
private:	// User declarations
	void generate();
    std::string getCharSet() const noexcept;
public:		// User declarations
	__fastcall TFGenerator(TComponent* Owner, const String& btnCap = "Close");
    String getSelection() const noexcept;
};
//---------------------------------------------------------------------------
extern PACKAGE TFGenerator *FGenerator;
//---------------------------------------------------------------------------
#endif
