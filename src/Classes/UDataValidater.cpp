//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDataValidater.h"

#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>

//---------------------------------------------------------------------------
bool DataValidater::DbStringToDate(const String& s, TDateTime& outDate) const {
    TFormatSettings fs;
    fs.DateSeparator = '-';
    fs.ShortDateFormat = "yyyy-mm-dd";
    fs.LongDateFormat  = "yyyy-mm-dd";

    try {
        outDate = StrToDate(s, fs);
        return true;
    } catch (const EConvertError&) {
        return false;
    }
}
//---------------------------------------------------------------------------
bool DataValidater::isDateOld(const String& dateStr) const noexcept
{
	TDateTime dt;
	if (!DbStringToDate(dateStr, dt))
		return false;

	TDateTime target = IncMonth(dt, 1);
	TDate today = Date();

	return today >= target;
}
//---------------------------------------------------------------------------
System::String DataValidater::getCurrentDateToString() const noexcept
{
    TFormatSettings fs;
    fs.DateSeparator   = '-';
	fs.ShortDateFormat = "yyyy-mm-dd";
	fs.LongDateFormat  = "yyyy-mm-dd";
	return FormatDateTime("yyyy-mm-dd", Date(), fs);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
