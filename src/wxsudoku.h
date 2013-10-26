///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxsudoku__
#define __wxsudoku__

#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/valgen.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class sudoku_main
///////////////////////////////////////////////////////////////////////////////
class sudoku_main : public wxFrame 
{
	private:
	
	protected:
		wxGrid* m_grid2;
		wxButton* m_limpiar;
		wxButton* m_comprobar;
		wxButton* m_nuevo;
		wxButton* m_salir;
		wxButton* about;
		
		// Virtual event handlers, overide them in your derived class
		virtual void click_limpiar( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_comprobar( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_nuevo( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_salir( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_about( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		sudoku_main( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Te amo Day :)"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 292,222 ), long style = wxCAPTION|wxTAB_TRAVERSAL );
		~sudoku_main();
	
};

#endif //__wxsudoku__
