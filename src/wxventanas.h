///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxventanas__
#define __wxventanas__

#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/dialog.h>
#include <wx/html/htmlwin.h>
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>
#include <wx/html/htmlwin.h>
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxprincipal
///////////////////////////////////////////////////////////////////////////////
class wxprincipal : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu11;
		wxMenuItem* m_menuItem10;
		wxMenu* m_menu3;
		//wxMenu* m_menu5;
		wxButton* bot_abre_par;
		wxButton* bot_cierra_par;
		wxButton* bot_negacion;
		wxButton* bot_y;
		wxButton* bot_y_neg;
		wxButton* bot_o;
		wxButton* bot_o_neg;
		wxButton* bot_o_ex;
		wxButton* bot_imp;
		wxButton* bot_2imp;
		wxChoice* box_variables;
		wxChoice* var_car;
		wxTextCtrl* caja;
		wxButton* bot_hacer;
		wxButton* bot_borrar;
		wxGrid* m_grid1;
		wxGrid* m_grid2;
		wxRichTextCtrl* m_richText2;
		wxHtmlWindow* mirahtml;
		// Virtual event handlers, overide them in your derived class
		virtual void click_simbologia( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_exp_texto( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_exp_binario( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_exp_excel( wxCommandEvent& event ){ event.Skip(); }
		virtual void clikc_imp_binario( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cerrar_bin( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_salir( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_equi( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_prob_negacion( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_sintaxis( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_about( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_abre_par( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cierra_par( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_negacion( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_y( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_y_neg( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_o( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_o_neg( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_o_ex( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_imp( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_2imp( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_choice( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_posibles( wxCommandEvent& event ){ event.Skip(); }
		virtual void caja_cambia( wxCommandEvent& event ){ event.Skip(); }
		virtual void press_enter( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_hacer( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_borrar( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxprincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AnallogicA"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1035,550 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~wxprincipal();
		
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Anallogica_equiva
///////////////////////////////////////////////////////////////////////////////
class Anallogica_equiva : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxChoice* eligem1;
		wxTextCtrl* sent_1;
		wxFilePickerCtrl* m_filePicker1;
		wxStaticText* m_staticText2;
		wxChoice* eligem2;
		wxTextCtrl* sent_2;
		wxFilePickerCtrl* m_filePicker2;
		wxRichTextCtrl* box_resu;
		wxButton* bot_borra;
		wxButton* bot_hacer;
		wxButton* bot_cancelar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void click_car_var1( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cargar_1( wxFileDirPickerEvent& event ){ event.Skip(); }
		virtual void click_car_var2( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cargar_2( wxFileDirPickerEvent& event ){ event.Skip(); }
		virtual void click_borra( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_hacer( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		Anallogica_equiva( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AnallogicA::Equivalencia"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,300 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Anallogica_equiva();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ayuda
///////////////////////////////////////////////////////////////////////////////
class ayuda : public wxDialog 
{
	private:
	
	protected:
		wxHtmlWindow* navegador;
	
	public:
		ayuda( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AnallogicA::Reporte"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,600 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ayuda();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class About
///////////////////////////////////////////////////////////////////////////////
class About : public wxDialog 
{
	private:
	
	protected:
	
	public:
		About( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~About();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Anallogica_negacion
///////////////////////////////////////////////////////////////////////////////
class Anallogica_negacion : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxChoice* eligem1;
		wxTextCtrl* sent_1;
		wxFilePickerCtrl* m_filePicker11;
		wxStaticText* m_staticText2;
		wxChoice* eligem2;
		wxTextCtrl* sent_2;
		wxFilePickerCtrl* m_filePicker1;
		wxRichTextCtrl* box_resu;
		wxButton* bot_borra;
		wxButton* bot_hacer;
		wxButton* bot_cancelar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void click_car_var1( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cargar_1( wxFileDirPickerEvent& event ){ event.Skip(); }
		virtual void click_car_var2( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cargar_2( wxFileDirPickerEvent& event ){ event.Skip(); }
		virtual void click_borra( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_hacer( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_cancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		Anallogica_negacion( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AnallogicA::Negacion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,300 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Anallogica_negacion();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class confirmar_bin
///////////////////////////////////////////////////////////////////////////////
class confirmar_bin : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText6;
		wxButton* m_button16;
		wxButton* m_button17;
		wxButton* m_button18;
		
		// Virtual event handlers, overide them in your derived class
		virtual void click_sob( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_aniadir( wxCommandEvent& event ){ event.Skip(); }
		virtual void click_otro_nombre( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		confirmar_bin( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Confirmar accion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~confirmar_bin();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class selector_simboloes
///////////////////////////////////////////////////////////////////////////////
class selector_simboloes : public wxDialog {
private:
	
protected:
	wxStaticText* m_staticText1;
//wxBitmapButton* m_bpButton1;
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
wxButton* ok;
wxCheckBox* unosyceros;

// Virtual event handlers, overide them in your derived class
//virtual void click_help( wxCommandEvent& event ) { event.Skip(); }
virtual void click_ok( wxCommandEvent& event ) { event.Skip(); }
virtual void estacheck( wxCommandEvent& event ) { event.Skip(); }

public:
	
	selector_simboloes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("AnallogicA::selector"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 393,353 ), long style = wxCAPTION|wxTAB_TRAVERSAL );
~selector_simboloes();

};

#endif //__wxventanas__
