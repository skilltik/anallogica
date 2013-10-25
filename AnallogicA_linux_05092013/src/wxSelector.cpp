///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxSelector.h"

///////////////////////////////////////////////////////////////////////////

selector_simboloes::selector_simboloes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Terminologia por defecto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer18->Add( m_staticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton1 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("../img/help.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_BOTTOM );
	bSizer18->Add( m_bpButton1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	bSizer1->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Conjuncion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer2->Add( m_staticText3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_textCtrl1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Conjuncion Negativa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer21->Add( m_staticText31, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_textCtrl11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Disjuncion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer22->Add( m_staticText32, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_textCtrl12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer22, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Disjuncion Negativa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer23->Add( m_staticText33, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textCtrl13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer23, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Disjuncion Exclusiva"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer24->Add( m_staticText34, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl14 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_textCtrl14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("Implicacion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer25->Add( m_staticText35, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl15 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_textCtrl15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText36 = new wxStaticText( this, wxID_ANY, wxT("Bidondicional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer26->Add( m_staticText36, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl16 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_textCtrl16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer26, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer261;
	bSizer261 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText361 = new wxStaticText( this, wxID_ANY, wxT("Negacion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361->Wrap( -1 );
	bSizer261->Add( m_staticText361, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl161 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer261->Add( m_textCtrl161, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer261, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2611;
	bSizer2611 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3611 = new wxStaticText( this, wxID_ANY, wxT("Usar ceros y unos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611->Wrap( -1 );
	bSizer2611->Add( m_staticText3611, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	unosyceros = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2611->Add( unosyceros, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2611, 1, wxEXPAND, 5 );
	
	ok = new wxButton( this, wxID_ANY, wxT("Listo!"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( ok, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_help ), NULL, this );
	unosyceros->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( selector_simboloes::estacheck ), NULL, this );
	ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_ok ), NULL, this );
}

selector_simboloes::~selector_simboloes()
{
	// Disconnect Events
	m_bpButton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_help ), NULL, this );
	unosyceros->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( selector_simboloes::estacheck ), NULL, this );
	ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_ok ), NULL, this );
	
}
