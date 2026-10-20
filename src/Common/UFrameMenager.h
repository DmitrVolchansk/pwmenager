//---------------------------------------------------------------------------

#ifndef UFrameMenagerH
#define UFrameMenagerH

#include "ShowCaseService.h"
//---------------------------------------------------------------------------
namespace FrameMenager {

	enum mode_t {
		lgn
	};

	void launch(TShowCaseService& scs, const mode_t mode);
}

#endif
