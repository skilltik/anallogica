
#ifndef EVENTOS_H
#define EVENTOS_H
#include "wxventanas.h"
#include "sentencia.h"
#include "eventos_equiva.h"
#include <vector>
using namespace std;
class eventos : public wxprincipal {
	
private:
	
protected:
	void click_o_neg( wxCommandEvent& event );
	void click_y_neg( wxCommandEvent& event );
	void click_o_ex( wxCommandEvent& event );
	void caja_cambia( wxCommandEvent& event );
	void click_exp_excel( wxCommandEvent& event );
	void press_enter( wxCommandEvent& event );
	void click_cerrar_bin( wxCommandEvent& event );
	void click_cerrar( wxCommandEvent& event );
	void click_ayuda( wxCommandEvent& event );
	void click_prob_negacion( wxCommandEvent& event );
	void click_equi( wxCommandEvent& event );

	void click_exp_texto( wxCommandEvent& event );
	void click_exp_binario( wxCommandEvent& event );
	void clikc_imp_binario( wxCommandEvent& event );
	void click_salir( wxCommandEvent& event );
	void click_sintaxis( wxCommandEvent& event );
	void click_about( wxCommandEvent& event );
	void click_abre_par( wxCommandEvent& event );
	void click_cierra_par( wxCommandEvent& event );
	void click_negacion( wxCommandEvent& event );
	void click_y( wxCommandEvent& event );
	void click_o( wxCommandEvent& event );
	void click_imp( wxCommandEvent& event );
	void click_2imp( wxCommandEvent& event );
	void click_choice( wxCommandEvent& event );
	void click_hacer( wxCommandEvent& event );
	void click_borrar( wxCommandEvent& event );
	void click_simbologia( wxCommandEvent& event );
	string traduce(string var);
	vector<string> sentencias;
	wxString linea;
	wxString lista_simbolos_wx[8];
	string lista_simbolos[8];
	sentencia analizame,analizame2;
	void lista_songs();
	string num(int i);//pasa de int a string
	wxString songs[50];
	string unoos;
public:
	eventos(wxWindow *parent=NULL);
	~eventos();
	void set_caja(string met);//funcion para escribir en la caja de texto
	void limpia_espacios(wxString &tex);
	void carga_simbolos();
	friend class eventos_equiva;
	friend class sentencia;
	wxString archi(int tipo);
	string wxs2s(wxString pasa);
	wxString Wversion;
	void cargaindex();//cargo indexs
};


#endif

