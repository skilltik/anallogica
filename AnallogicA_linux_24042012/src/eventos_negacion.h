
#ifndef EVENTOS_NEGACION_H
#define EVENTOS_NEGACION_H
#include "wxventanas.h"
#include <string>
#include <vector>
using namespace std;

class eventos_negacion : public Anallogica_negacion {
	
private:
	
protected:
	void click_car_var1( wxCommandEvent& event );
	void click_car_var2( wxCommandEvent& event );
	void click_cargar_1( wxFileDirPickerEvent& event );
	void click_cargar_2( wxFileDirPickerEvent& event );
	void click_borra( wxCommandEvent& event );
	void click_hacer( wxCommandEvent& event );
	void click_cancel( wxCommandEvent& event );
	
public:
	eventos_negacion(string *lista_simbolos,wxWindow *parent=NULL);
	~eventos_negacion();
	string traduce(string var);
	void set_caja(string met);//funcion para escribir en la caja de texto
	void escribe_richtext(string llega);//escribe en el cuadro de texto
	void escribe_errores(vector<string> llega);//escribe todos los errores
	void limpia_espacios(wxString &tex);
	string lista_simbol[8];
	vector<string> sentencias;
	vector<string> sentencias2;
	string unoos;
	friend class sentencia;
};

#endif

