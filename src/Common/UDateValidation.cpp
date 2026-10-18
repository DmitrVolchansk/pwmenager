//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDateValidation.h"

#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>

//---------------------------------------------------------------------------
namespace {
	bool DbStringToDate(const String& s, TDateTime& outDate)
	{
		TFormatSettings fs;
		fs.DateSeparator = '-';
		fs.ShortDateFormat = "yyyy-mm-dd";
		fs.LongDateFormat  = "yyyy-mm-dd";

		try
		{
			outDate = StrToDate(s, fs);
			return true;
		} catch (const EConvertError&) {
			return false;
		}
	}
}
//---------------------------------------------------------------------------
namespace datevalidation {
	bool isDateOld(const String& dateStr) noexcept
	{
		TDateTime dt;
		if (!DbStringToDate(dateStr, dt))
			return false;

		TDateTime target = IncMonth(dt, 1);
		TDate today = Date();

		return today >= target;
	}
	//-----------------------------------------------------------------------
	System::String getCurrentDateToString() noexcept
	{
		TFormatSettings fs;
		fs.DateSeparator   = '-';
		fs.ShortDateFormat = "yyyy-mm-dd";
		fs.LongDateFormat  = "yyyy-mm-dd";
		return FormatDateTime("yyyy-mm-dd", Date(), fs);
	}
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
