///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxventanas.h"
#include <wx/valtext.h>

///////////////////////////////////////////////////////////////////////////

wxprincipal::wxprincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	m_menu11 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu11, wxID_ANY, wxString( wxT("HTML(web)") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu11->Append( m_menuItem1 );
	
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu11, wxID_ANY, wxString( wxT("Binario") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu11->Append( m_menuItem2 );
	
	wxMenuItem* m_meniutem003;
	m_meniutem003 = new wxMenuItem( m_menu11, wxID_ANY, wxString( wxT("csv (excel)") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu11->Append( m_meniutem003 );
	
	m_menu1->Append( -1, wxT("Exportar"), m_menu11 );
	
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Importar binario") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem3 );
	
	m_menuItem10 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("cerrar binario") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem10 );
	m_menuItem10->Enable( false );
	
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Salir") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem4 );
	
	m_menubar1->Append( m_menu1, wxT("Archivo") );
	
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem71;
	m_menuItem71 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Probar equivalentes") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem71 );
	
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Probar negacion") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem8 );
	
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Comprobar Sintaxis") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem5 );
	
	wxMenuItem* m_menuItem66;
	m_menuItem66 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Modificar simbologia") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem66 );
	
	m_menubar1->Append( m_menu3, wxT("Herramientas") );
	
	//m_menu5 = new wxMenu();
	//wxMenuItem* m_menuItem7;
	//m_menuItem7 = new wxMenuItem( m_menu5, wxID_ANY, wxString( wxT("About...") ) , wxEmptyString, wxITEM_NORMAL );
	//m_menu5->Append( m_menuItem7 );
	
	//m_menubar1->Append( m_menu5, wxT("Ayuda") );
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL );
	
	bot_abre_par = new wxButton( this, wxID_ANY, wxT("("), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_abre_par, 0, wxALL, 5 );
	
	bot_cierra_par = new wxButton( this, wxID_ANY, wxT(")"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_cierra_par, 0, wxALL, 5 );
	
	bot_negacion = new wxButton( this, wxID_ANY, wxT("Negacion       "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_negacion, 0, wxALL, 5 );
	
	bot_y = new wxButton( this, wxID_ANY, wxT("Conjuncion      "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_y, 0, wxALL, 5 );
	
	bot_y_neg = new wxButton( this, wxID_ANY, wxT("Conjuncion \n Negativa      "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_y_neg, 0, wxALL, 5 );
	
	bot_o = new wxButton( this, wxID_ANY, wxT("Dinjuncion     "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_o, 0, wxALL, 5 );
	
	bot_o_neg = new wxButton( this, wxID_ANY, wxT("Dinjuncion \n Negativa      "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_o_neg, 0, wxALL, 5 );
	
	bot_o_ex = new wxButton( this, wxID_ANY, wxT("Dinjuncion \n Exclusiva      "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_o_ex, 0, wxALL, 5 );
	
	bot_imp = new wxButton( this, wxID_ANY, wxT("Implicacion         "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_imp, 0, wxALL, 5 );
	
	bot_2imp = new wxButton( this, wxID_ANY, wxT("Bicondicional           "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer2->Add( bot_2imp, 0, wxALL, 5 );
	
	
	wxString box_variablesChoices[] = { wxT("a"), wxT("b"), wxT("c"), wxT("d"), wxT("e"), wxT("f"), wxT("g"), wxT("h"), wxT("i"), wxT("j"), wxT("k"), wxT("l"), wxT("m"), wxT("n"), wxT("o"), wxT("p"), wxT("q"), wxT("r"), wxT("s"), wxT("t"), wxT("u"), wxT("v"), wxT("w"), wxT("x"), wxT("y"), wxT("z") };
	int box_variablesNChoices = sizeof( box_variablesChoices ) / sizeof( wxString );
	box_variables = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, box_variablesNChoices, box_variablesChoices, 0 );
	box_variables->SetSelection( 0 );
	bSizer2->Add( box_variables, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALIGN_TOP|wxALL, 5 ); //<-
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString var_carChoices;
	var_car = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, var_carChoices, 0 );
	var_car->SetSelection( 0 );
	var_car->Enable( false );
	
	bSizer4->Add( var_car, 0, wxALL, 5 );
	
	caja = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer4->Add( caja, 1, wxALL|wxEXPAND, 5 );
	
	bot_hacer = new wxButton( this, wxID_ANY, wxT(" Hacer "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer4->Add( bot_hacer, 0, wxALL, 5 );
	
	bot_borrar = new wxButton( this, wxID_ANY, wxT(" Borrar "), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer4->Add( bot_borrar, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer4, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	mirahtml = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer5->Add( mirahtml, 1, wxEXPAND | wxALL, 5 );
	
	bSizer1->Add( bSizer5, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuItem66->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_simbologia ) );
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_exp_texto ) );
	this->Connect( m_menuItem2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_exp_binario ) );
	this->Connect( m_meniutem003->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_exp_excel ) );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::clikc_imp_binario ) );
	this->Connect( m_menuItem10->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_cerrar_bin ) );
	this->Connect( m_menuItem4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_salir ) );
	this->Connect( m_menuItem71->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_equi ) );
	this->Connect( m_menuItem8->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_prob_negacion ) );
	this->Connect( m_menuItem5->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_sintaxis ) );
	//this->Connect( m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_about ) );
	bot_abre_par->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_abre_par ), NULL, this );
	bot_cierra_par->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_cierra_par ), NULL, this );
	bot_negacion->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_negacion ), NULL, this );
	bot_y->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_y ), NULL, this );
	bot_y_neg->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_y_neg ), NULL, this );
	bot_o->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_o ), NULL, this );
	bot_o_neg->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_o_neg ), NULL, this );
	bot_o_ex->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_o_ex ), NULL, this );
	bot_imp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_imp ), NULL, this );
	bot_2imp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_2imp ), NULL, this );
	box_variables->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxprincipal::click_choice ), NULL, this );
	var_car->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxprincipal::click_posibles ), NULL, this );
	caja->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxprincipal::caja_cambia ), NULL, this );
	caja->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxprincipal::press_enter ), NULL, this );
	bot_hacer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_hacer ), NULL, this );
	bot_borrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_borrar ), NULL, this );
}

wxprincipal::~wxprincipal()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_simbologia ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_exp_texto ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_exp_binario ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_exp_excel ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::clikc_imp_binario ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_cerrar_bin ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_salir ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_equi ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_prob_negacion ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_sintaxis ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxprincipal::click_about ) );
	bot_abre_par->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_abre_par ), NULL, this );
	bot_cierra_par->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_cierra_par ), NULL, this );
	bot_negacion->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_negacion ), NULL, this );
	bot_y->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_y ), NULL, this );
	bot_y_neg->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_y_neg ), NULL, this );
	bot_o->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_o ), NULL, this );
	bot_o_neg->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_o_neg ), NULL, this );
	bot_o_ex->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_o_ex ), NULL, this );
	bot_imp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_imp ), NULL, this );
	bot_2imp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_2imp ), NULL, this );
	box_variables->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxprincipal::click_choice ), NULL, this );
	var_car->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxprincipal::click_posibles ), NULL, this );
	caja->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxprincipal::caja_cambia ), NULL, this );
	caja->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxprincipal::press_enter ), NULL, this );
	bot_hacer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_hacer ), NULL, this );
	bot_borrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxprincipal::click_borrar ), NULL, this );
}

Anallogica_equiva::Anallogica_equiva( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Sentencia 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString eligem1Choices;
	eligem1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eligem1Choices, 0 );
	eligem1->SetSelection( 0 );
	eligem1->Enable( false );
	
	bSizer12->Add( eligem1, 0, wxALL, 5 );
	
	sent_1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( sent_1, 1, wxALL, 5 );
	
	m_filePicker1 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.vpl"), wxDefaultPosition, wxDefaultSize,0);
	bSizer12->Add( m_filePicker1, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer12, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Sentencia 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString eligem2Choices;
	eligem2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eligem2Choices, 0 );
	eligem2->SetSelection( 0 );
	eligem2->Enable( false );
	
	bSizer14->Add( eligem2, 0, wxALL, 5 );
	
	sent_2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( sent_2, 1, wxALL, 5 );
	
	m_filePicker2 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.vpl"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer14->Add( m_filePicker2, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer14, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	box_resu = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxHSCROLL|wxNO_BORDER|wxSUNKEN_BORDER|wxVSCROLL|wxWANTS_CHARS );
	bSizer8->Add( box_resu, 1, wxEXPAND | wxALL, 5 );
	
	bSizer6->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	bot_borra = new wxButton( this, wxID_ANY, wxT("Borrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( bot_borra, 0, wxALL, 5 );
	
	bot_hacer = new wxButton( this, wxID_ANY, wxT("Hacer"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( bot_hacer, 0, wxALL, 5 );
	
	bot_cancelar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( bot_cancelar, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer6 );
	this->Layout();
	
	// Connect Events
	eligem1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_equiva::click_car_var1 ), NULL, this );
	m_filePicker1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_equiva::click_cargar_1 ), NULL, this );
	eligem2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_equiva::click_car_var2 ), NULL, this );
	m_filePicker2->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_equiva::click_cargar_2 ), NULL, this );
	bot_borra->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_equiva::click_borra ), NULL, this );
	bot_hacer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_equiva::click_hacer ), NULL, this );
	bot_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_equiva::click_cancel ), NULL, this );
}

Anallogica_equiva::~Anallogica_equiva()
{
	// Disconnect Events
	eligem1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_equiva::click_car_var1 ), NULL, this );
	m_filePicker1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_equiva::click_cargar_1 ), NULL, this );
	eligem2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_equiva::click_car_var2 ), NULL, this );
	m_filePicker2->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_equiva::click_cargar_2 ), NULL, this );
	bot_borra->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_equiva::click_borra ), NULL, this );
	bot_hacer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_equiva::click_hacer ), NULL, this );
	bot_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_equiva::click_cancel ), NULL, this );
}

ayuda::ayuda( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	navegador = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer16->Add( navegador, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer16 );
	this->Layout();
}

ayuda::~ayuda()
{
}

About::About( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
}

About::~About()
{
}

Anallogica_negacion::Anallogica_negacion( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Sentencia 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString eligem1Choices;
	eligem1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eligem1Choices, 0 );
	eligem1->SetSelection( 0 );
	eligem1->Enable( false );
	
	bSizer121->Add( eligem1, 0, wxALL, 5 );
	
	sent_1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer121->Add( sent_1, 1, wxALL, 5 );
	
	m_filePicker11 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.vpl"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer121->Add( m_filePicker11, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer121, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Sentencia 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString eligem2Choices;
	eligem2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eligem2Choices, 0 );
	eligem2->SetSelection( 0 );
	eligem2->Enable( false );
	
	bSizer12->Add( eligem2, 0, wxALL, 5 );
	
	sent_2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( sent_2, 1, wxALL, 5 );
	
	m_filePicker1 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.vpl"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer12->Add( m_filePicker1, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer12, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	box_resu = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxHSCROLL|wxNO_BORDER|wxSUNKEN_BORDER|wxVSCROLL|wxWANTS_CHARS );
	bSizer8->Add( box_resu, 1, wxEXPAND | wxALL, 5 );
	
	bSizer6->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	bot_borra = new wxButton( this, wxID_ANY, wxT("Borrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( bot_borra, 0, wxALL, 5 );
	
	bot_hacer = new wxButton( this, wxID_ANY, wxT("Hacer"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( bot_hacer, 0, wxALL, 5 );
	
	bot_cancelar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( bot_cancelar, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer6 );
	this->Layout();
	
	// Connect Events
	eligem1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_negacion::click_car_var1 ), NULL, this );
	m_filePicker11->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_negacion::click_cargar_1 ), NULL, this );
	eligem2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_negacion::click_car_var2 ), NULL, this );
	m_filePicker1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_negacion::click_cargar_2 ), NULL, this );
	bot_borra->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_negacion::click_borra ), NULL, this );
	bot_hacer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_negacion::click_hacer ), NULL, this );
	bot_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_negacion::click_cancel ), NULL, this );
}

Anallogica_negacion::~Anallogica_negacion()
{
	// Disconnect Events
	eligem1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_negacion::click_car_var1 ), NULL, this );
	m_filePicker11->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_negacion::click_cargar_1 ), NULL, this );
	eligem2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Anallogica_negacion::click_car_var2 ), NULL, this );
	m_filePicker1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Anallogica_negacion::click_cargar_2 ), NULL, this );
	bot_borra->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_negacion::click_borra ), NULL, this );
	bot_hacer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_negacion::click_hacer ), NULL, this );
	bot_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Anallogica_negacion::click_cancel ), NULL, this );
}

confirmar_bin::confirmar_bin( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("El nombre seleccionado ya existe!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer18->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer17->Add( bSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button16 = new wxButton( this, wxID_ANY, wxT("Sobreescribir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button16, 0, wxALL, 5 );
	
	m_button17 = new wxButton( this, wxID_ANY, wxT("Añadir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button17, 0, wxALL, 5 );
	
	m_button18 = new wxButton( this, wxID_ANY, wxT("cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button18, 0, wxALL, 5 );
	
	bSizer17->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer17 );
	this->Layout();
	bSizer17->Fit( this );
	
	// Connect Events
	m_button16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( confirmar_bin::click_sob ), NULL, this );
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( confirmar_bin::click_aniadir ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( confirmar_bin::click_otro_nombre ), NULL, this );
}

confirmar_bin::~confirmar_bin()
{
	// Disconnect Events
	m_button16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( confirmar_bin::click_sob ), NULL, this );
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( confirmar_bin::click_aniadir ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( confirmar_bin::click_otro_nombre ), NULL, this );
}


selector_simboloes::selector_simboloes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	//////////
	wxTextValidator nameValidator(wxFILTER_INCLUDE_CHAR_LIST);
	wxArrayString letters;
	
	
	 letters.Add(wxT("!"));
	 letters.Add(wxT("$")); letters.Add(wxT("%"));
	letters.Add(wxT("=")); letters.Add(wxT("/")); letters.Add(wxT("&"));
	letters.Add(wxT("?")); letters.Add(wxT("*"));
	letters.Add(wxT("`")); letters.Add(wxT("^"));
	letters.Add(wxT("\\"));
 	letters.Add(wxT(";")); letters.Add(wxT(",")); letters.Add(wxT("."));
	letters.Add(wxT("-")); letters.Add(wxT("_")); letters.Add(wxT(":"));
	letters.Add(wxT("[")); letters.Add(wxT("]")); letters.Add(wxT("{"));
	letters.Add(wxT("@")); letters.Add(wxT("|")); letters.Add(wxT("}"));
	letters.Add(wxT("#")); letters.Add(wxT("~"));
	letters.Add(wxT(">")); letters.Add(wxT("<")); 
	
	
	nameValidator.SetIncludes(letters);
	
	//////////////
	
	
	
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Terminologia por defecto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer18->Add( m_staticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
//	m_bpButton1 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("img/help.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_BOTTOM );
//	bSizer18->Add( m_bpButton1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
//	
	bSizer1->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Conjuncion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer2->Add( m_staticText3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0,nameValidator);
	bSizer2->Add( m_textCtrl1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Conjuncion Negativa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer21->Add( m_staticText31, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 ,nameValidator);
	bSizer21->Add( m_textCtrl11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Disjuncion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer22->Add( m_staticText32, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 ,nameValidator);
	bSizer22->Add( m_textCtrl12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer22, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Disjuncion Negativa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer23->Add( m_staticText33, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0,nameValidator );
	bSizer23->Add( m_textCtrl13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer23, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Disjuncion Exclusiva"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer24->Add( m_staticText34, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl14 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0,nameValidator );
	bSizer24->Add( m_textCtrl14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("Implicacion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer25->Add( m_staticText35, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl15 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 ,nameValidator);
	bSizer25->Add( m_textCtrl15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText36 = new wxStaticText( this, wxID_ANY, wxT("Bidondicional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer26->Add( m_staticText36, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl16 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 ,nameValidator);
	bSizer26->Add( m_textCtrl16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer26, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer261;
	bSizer261 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText361 = new wxStaticText( this, wxID_ANY, wxT("Negacion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361->Wrap( -1 );
	bSizer261->Add( m_staticText361, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl161 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 ,nameValidator);
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
//	m_bpButton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_help ), NULL, this );
	ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_ok ), NULL, this );
	unosyceros->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( selector_simboloes::estacheck ), NULL, this );
}

selector_simboloes::~selector_simboloes()
{
	// Disconnect Events
//	m_bpButton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_help ), NULL, this );
	ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( selector_simboloes::click_ok ), NULL, this );
	unosyceros->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( selector_simboloes::estacheck ), NULL, this );
}
