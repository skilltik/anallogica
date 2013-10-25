///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxsudoku.h"
#include <wx/valtext.h>

///////////////////////////////////////////////////////////////////////////

sudoku_main::sudoku_main( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	//////////
//	wxTextValidator nameValidator(wxFILTER_INCLUDE_CHAR_LIST);
//	wxArrayString letters;
//	
//	
//	letters.Add(wxT("1")); letters.Add(wxT("2")); letters.Add(wxT("3"));
//	letters.Add(wxT("4")); letters.Add(wxT("5")); letters.Add(wxT("6"));
//	letters.Add(wxT("7")); letters.Add(wxT("8")); letters.Add(wxT("9"));
//	
//	nameValidator.SetIncludes(letters);
	
	//////////////
	m_grid2 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid2->CreateGrid( 9, 9 );
	m_grid2->EnableEditing( true );
	m_grid2->EnableGridLines( true );
	m_grid2->EnableDragGridSize( false );
	m_grid2->SetMargins( 0, 0 );
//	m_grid2->SetValidator(nameValidator);
	
	// Columns
	m_grid2->SetColSize( 0, 30 );
	m_grid2->AutoSizeColumns();
	m_grid2->EnableDragColMove( false );
	m_grid2->EnableDragColSize( true );
	m_grid2->SetColLabelSize( 0 );
	m_grid2->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid2->EnableDragRowSize( true );
	m_grid2->SetRowLabelSize( 0 );
	m_grid2->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid2->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer1->Add( m_grid2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_limpiar = new wxButton( this, wxID_ANY, wxT("Limpiar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_limpiar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_comprobar = new wxButton( this, wxID_ANY, wxT("Comprobar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_comprobar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_nuevo = new wxButton( this, wxID_ANY, wxT("Nuevo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_nuevo, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_salir = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_salir, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	about = new wxButton( this, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( about, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_limpiar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_limpiar ), NULL, this );
	m_comprobar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_comprobar ), NULL, this );
	m_nuevo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_nuevo ), NULL, this );
	m_salir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_salir ), NULL, this );
	about->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_about ), NULL, this );
}

sudoku_main::~sudoku_main()
{
	// Disconnect Events
	m_limpiar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_limpiar ), NULL, this );
	m_comprobar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_comprobar ), NULL, this );
	m_nuevo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_nuevo ), NULL, this );
	m_salir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_salir ), NULL, this );
	about->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( sudoku_main::click_about ), NULL, this );
	
}
