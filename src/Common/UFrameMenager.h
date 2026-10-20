//---------------------------------------------------------------------------

#ifndef UFrameMenagerH
#define UFrameMenagerH

#include "ShowCaseService.h"
//---------------------------------------------------------------------------
namespace FrameMenager {

	enum mode {
		lgn
	};

	void launch(TShowCaseService& scs, const mode mode);
}

#endif
