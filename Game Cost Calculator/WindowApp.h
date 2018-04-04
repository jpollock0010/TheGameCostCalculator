#ifndef WINDOWAPP_H
#define WINDOWAPP_H

//(*Headers(WindowApp)
#include <wx/menu.h>
#include <wx/dialog.h>
//*)

class WindowApp: public wxDialog
{
	public:

		WindowApp(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~WindowApp();

		//(*Declarations(WindowApp)
		wxMenu Menu1;
		//*)

	protected:

		//(*Identifiers(WindowApp)
		//*)

	private:

		//(*Handlers(WindowApp)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
