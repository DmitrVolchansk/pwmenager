//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
#include "DMdb.h"
//---------------------------------------------------------------------------
USEFORM("src\Frames\AddingFrame.cpp", FAdding); /* TFrame: File Type */
USEFORM("src\Forms\MainForm.cpp", FMain);
USEFORM("src\Forms\GeneratorForm.cpp", FGenerator);
USEFORM("src\Frames\BaseFrame.cpp", FBase); /* TFrame: File Type */
USEFORM("src\Frames\ViewingFrame.cpp", FViewing); /* TFrame: File Type */
USEFORM("src\Frames\EditFrame.cpp", FEdit); /* TFrame: File Type */
USEFORM("src\Forms\CustomDlgForm.cpp", FCustomDlg);
USEFORM("src\DataModules\DMdb.cpp", DataBaseModule); /* TDataModule: File Type */
USEFORM("src\Frames\ShowCaseFrame.cpp", FShowCase); /* TFrame: File Type */
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();

		DataBaseModule = new TDataBaseModule(Application);
		DataBaseModule->Initialize();

        Application->CreateForm(__classid(TFMain), &FMain);
		Application->CreateForm(__classid(TDataBaseModule), &DataBaseModule);
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
