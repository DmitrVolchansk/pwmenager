//---------------------------------------------------------------------------

#ifndef CustomDlgFormH
#define CustomDlgFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "BaseFrame.h"
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFCustomDlg : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TFCustomDlg(TComponent* Owner, TFBase* frame);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCustomDlg *FCustomDlg;
//---------------------------------------------------------------------------
#endif
