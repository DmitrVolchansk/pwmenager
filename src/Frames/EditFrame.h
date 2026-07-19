//---------------------------------------------------------------------------

#ifndef EditFrameH
#define EditFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "AddingFrame.h"
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "UTypes.h"
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TFEdit : public TFAdding
{
__published:	// IDE-managed Components
	TButton *CancelBtn;
private:	// User declarations
public:		// User declarations
	__fastcall TFEdit(TComponent* Owner, const TUPtrDataHolder& data);
};
//---------------------------------------------------------------------------
extern PACKAGE TFEdit *FEdit;
//---------------------------------------------------------------------------
#endif
