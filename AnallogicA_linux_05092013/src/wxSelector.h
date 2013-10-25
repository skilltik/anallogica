///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxSelector__
#define __wxSelector__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class selector_simboloes
///////////////////////////////////////////////////////////////////////////////
class selector_simboloes : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxBitmapButton* m_bpButton1;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_textCtrl11;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_textCtrl12;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_textCtrl13;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_textCtrl14;
		wxStaticText* m_staticText35;
		wxTextCtrl* m_textCtrl15;
		wxStaticText* m_staticText36;
		wxTextCtrl* m_textCtrl16;
		wxStaticText* m_staticText361;
		wxTextCtrl* m_textCtrl161;
		wxStaticText* m_staticText3611;
		wxCheckBox* unosyceros;
		wxButton* ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void click_help( wxCommandEvent& event ) { event.Skip(); }
		virtual void estacheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_ok( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		selector_simboloes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AnallogicA::selector"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 393,386 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~selector_simboloes();
	
};

#endif //__wxSelector__
