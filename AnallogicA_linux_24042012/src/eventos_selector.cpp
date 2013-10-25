#include "eventos_selector.h"
#include <wx/msgdlg.h>
#include <cstring>
#include <fstream>
#include <wx/string.h>
using namespace std;
eventos_selector::eventos_selector(wxWindow *parent) : selector_simboloes(parent) {
	fstream simbologia;
	simbologia.open("simbologia",ios::in);
	string aux_simbologia;
	wxString aux_simbologia_wx[9];
	
	if (simbologia.good()==true){
		for (int i=0;i<9;i++){
			simbologia>>aux_simbologia;
			aux_simbologia_wx[i]=wxString::FromAscii(aux_simbologia.c_str());
			if (i==8){
				if (aux_simbologia=="1"){
					unosyceros->SetValue(true);
					
					}
				}
		}
		m_textCtrl1->SetValue(aux_simbologia_wx[0]);
		m_textCtrl11->SetValue(aux_simbologia_wx[1]);
		m_textCtrl12->SetValue(aux_simbologia_wx[2]);
		m_textCtrl13->SetValue(aux_simbologia_wx[3]);
		m_textCtrl14->SetValue(aux_simbologia_wx[4]);
		m_textCtrl15->SetValue(aux_simbologia_wx[5]);
		m_textCtrl16->SetValue(aux_simbologia_wx[6]);
		m_textCtrl161->SetValue(aux_simbologia_wx[7]);
//		if (&aux_simbologia[8]==wxT("1")){
//			unosyceros->SetValue(true);
//		}
		
	}
}

eventos_selector::~eventos_selector() {	
}

void eventos_selector::click_help( wxCommandEvent& event ) { 
//	eventos_ayuda *nueva=new eventos_ayuda(ruta+wxT(".txt"),this);
}
void eventos_selector::click_ok( wxCommandEvent& event ) {
	fstream simbologia;
	simbologia.open("simbologia", ios::out);
	bool vacio=false;
	
	wxString aux_value[9];
	aux_value[0]=m_textCtrl1->GetValue(); //
	aux_value[1]=m_textCtrl11->GetValue();
	aux_value[2]=m_textCtrl12->GetValue();
	aux_value[3]=m_textCtrl13->GetValue();
	aux_value[4]=m_textCtrl14->GetValue();
	aux_value[5]=m_textCtrl15->GetValue();
	aux_value[6]=m_textCtrl16->GetValue();
	aux_value[7]=m_textCtrl161->GetValue();//// leo las cajas
	bool unos=unosyceros->IsChecked();
	if (unos==true){
		aux_value[8]=wxT("1");
	}else{
		aux_value[8]=wxT("0");
	}
	
	for (int i=0;i<8;i++){ //compruebo que todos los campos esten llenos
		if (aux_value[i]==wxT("")){vacio=true;}
	}
	bool repetido=false;
	for (int i=0;i<8;i++){
		for (int j=i+1;j<8;j++){
			if (aux_value[i]==aux_value[j]){
				repetido=true;
			}
		}
	}
	if (vacio==false){
		if (repetido==false){
			if (aux_value[7].Length()==1){
				if (simbologia.good()==true){
					char buf[500];																//
					string cov;
					for (int i=0;i<9;i++){
						strcpy( buf, (const char*)(aux_value[i]).mb_str(wxConvUTF8) );	//convuerto direccion a string
						cov=buf;
						simbologia<<cov<<endl;
					}
					Close();
				}
			}else{
				wxMessageBox(wxT("Solo un caracter para el negador logico"));
			}
		}else{
			wxMessageBox(wxT("Otorgue simbolos diferentes para cada operador logico"));
		}
	}else{
		wxMessageBox(wxT("Otorgue un caracter a cada operador logico"));
	}
}

void eventos_selector::press_enter( wxCommandEvent& event ) {
	click_ok(event);
}
