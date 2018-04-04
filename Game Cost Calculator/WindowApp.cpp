#include "WindowApp.h"

//(*InternalHeaders(WindowApp)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(WindowApp)
//*)

BEGIN_EVENT_TABLE(WindowApp,wxDialog)
	//(*EventTable(WindowApp)
	//*)
END_EVENT_TABLE()

WindowApp::WindowApp(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(WindowApp)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

WindowApp::~WindowApp()
{
	//(*Destroy(WindowApp)
	//*)
}

