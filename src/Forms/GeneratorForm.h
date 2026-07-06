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
	TCheckBox *UnderWork;
	TCornerButton *SelectButton;
	TEdit *CoreEdit;
private:	// User declarations
public:		// User declarations
	__fastcall TFGenerator(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFGenerator *FGenerator;
//---------------------------------------------------------------------------
#endif
