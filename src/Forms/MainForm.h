//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Menus.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <vector>
#include "ShowCaseFrame.h"
#include "CustomDlgForm.h"
//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *Add;
	TMenuItem *Search;
	TMenuItem *Generate;
	TMenuItem *Settings;
	TScrollBox *ShowCaseLayout;
	TPanel *SearchPanel;
	TSpeedButton *CloseButton;
	TEdit *SearchEdit;
	TSpeedButton *SearchBtn;
	void __fastcall SwitchSearchPnlVisible(TObject *Sender);
	void __fastcall GenerateClick(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SearchBtnClick(TObject *Sender);
private:	// User declarations
	TFCustomDlg* customDlg;
	std::vector<TFShowCase*> showCases;
public:		// User declarations
	__fastcall TFMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
