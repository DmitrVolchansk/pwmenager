//---------------------------------------------------------------------------

#ifndef ShowCaseServiceH
#define ShowCaseServiceH

#include <System.SysUtils.hpp>
#include <vector>
#include "ShowCaseFrame.h"
//---------------------------------------------------------------------------
class TShowCaseService{
	private:
		std::vector<TFShowCase*> showCaseVector;
        TScrollBox* layout;

		TFShowCase* createCase(const TShowCaseParam& params);
        bool contains(const String& str1, const String& str2) const noexcept;
	public:
		explicit TShowCaseService(std::vector<TFShowCase*>& vector, TScrollBox* pare);
		void addNew(const TShowCaseParam& params);
		void filterBy(const String& name) const noexcept;
		void resetShowCaseFilter() const noexcept;
        void load();
};
#endif
