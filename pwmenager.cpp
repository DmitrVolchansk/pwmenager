//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("src\Forms\MainForm.cpp", FMain);
USEFORM("src\Frames\AddingFrame.cpp", FAdding); /* TFrame: File Type */
USEFORM("src\Frames\BaseFrame.cpp", FBase); /* TFrame: File Type */
USEFORM("src\Frames\ShowCaseFrame.cpp", FShowCase); /* TFrame: File Type */
USEFORM("src\Frames\ViewingFrame.cpp", FViewing); /* TFrame: File Type */
USEFORM("src\Forms\GeneratorForm.cpp", FGenerator);
USEFORM("src\Forms\CustomDlgForm.cpp", FCustomDlg);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TFMain), &FMain);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
