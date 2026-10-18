//---------------------------------------------------------------------------

#ifndef UDataValidaterH
#define UDataValidaterH

//---------------------------------------------------------------------------
class DataValidater{
	public:
		bool isDateOld(const String& date) const noexcept;
		String getCurrentDateToString() const noexcept;
	private:
        bool DbStringToDate(const String& s, TDateTime& outDate) const;
};

#endif
