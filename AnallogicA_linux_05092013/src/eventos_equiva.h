
#ifndef EVENTOS_EQUIVA_H
#define EVENTOS_EQUIVA_H
#include "wxventanas.h"
#include "eventos.h"

class eventos_equiva : public Anallogica_equiva{
	
private:
	
protected:
	void click_car_var1( wxCommandEvent& event );
	void click_car_var2( wxCommandEvent& event );
	void click_cargar_2( wxFileDirPickerEvent& event );
	void click_cargar_1( wxFileDirPickerEvent& event );
	void click_borra( wxCommandEvent& event );
	void click_hacer( wxCommandEvent& event );
	void click_cancel( wxCommandEvent& event );
public:
	eventos_equiva(string *lista_simbolos,wxWindow *parent);
	~eventos_equiva();
	string traduce(string var);
	void set_caja(string met);//funcion para escribir en la caja de texto
	void escribe_richtext(string llega);//escribe en el cuadro de texto
	void escribe_errores(vector<string> llega);//escribe todos los errores
	void limpia_espacios(wxString &tex);
	string lista_simbolo[8];
	vector<string> sentencias;
	vector<string> sentencias2;
	string unoos;
	friend class eventos;
	friend class sentencia;
};

#endif

