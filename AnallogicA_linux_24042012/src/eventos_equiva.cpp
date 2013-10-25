#include <wx/msgdlg.h>
#include "eventos_equiva.h"
#include "eventos.h"
#include "sentencia.h"
#include <wx/string.h>
#include <string>
#include <algorithm>
using namespace std;

eventos_equiva::eventos_equiva(string *lista_simbolos, wxWindow *parent) : Anallogica_equiva(parent) {
	for (int i=0;i<8;i++){
		lista_simbolo[i]=lista_simbolos[i];
	}
}

void eventos_equiva::click_borra( wxCommandEvent& event ) {
	sent_1->Clear();
	sent_2->Clear();
	box_resu->Clear();
}

void eventos_equiva::click_hacer( wxCommandEvent& event ) {
	box_resu->Clear();
	wxString lee;
	string aux;
	string aux2;
	lee=sent_1->GetValue();
	limpia_espacios(lee);//limpia caracteres en blanco
	sent_1->SetValue(lee);// reemplazo por texto sin espacios en caja 
	char buf[100];
	char buf2[100];
	strcpy( buf, (const char*)lee.mb_str(wxConvUTF8) );
	aux=buf;
	sentencia uno(aux);
	lee=sent_2->GetValue();
	limpia_espacios(lee);//limpia caracteres en blanco
	sent_2->SetValue(lee);// reemplazo por texto sin espacios en caja 
	strcpy( buf2, (const char*)lee.mb_str(wxConvUTF8) );
	aux2=buf2;
	sentencia dos(aux2);
	string aa("("+aux+")"+lista_simbolo[6]+"("+aux2+")");
	sentencia tres(aa);
	vector<string> log;
	vector<string> log2;
	vector<string> log3;
	vector<string> log4;
	vector<char> atomos1;
	vector<char> atomos2;

	if ((aux=="666")&&(aux2=="thenumberofthebeast")){
		escribe_richtext("Woe to you, Oh Earth and Sea, for the Devil sends the beast");
		escribe_richtext("with wrath, because he knows the time is short... ");
		escribe_richtext("Let him who hath understanding reckon the number of the beast");
		escribe_richtext("for it is a human number, its number is Six hundred and sixty six.");
		wxMessageBox(wxT("666 the number of the beast...666 the one for you and me"),wxT(" up the irons!"),wxICON_INFORMATION);
	}else{
		
		if ((uno.errores(aux,log,lista_simbolo)==false)&&(dos.errores(aux2,log2,lista_simbolo)==false)){
			uno.traduce(lista_simbolo);
			dos.traduce(lista_simbolo);
			tres.traduce(lista_simbolo);
			if ((uno.analiza_sintaxis(log3)==true)&&(dos.analiza_sintaxis(log4)==true)){
				uno.resuelve(unoos);
				dos.resuelve(unoos);
				tres.resuelve(unoos);
				bool flag=false;
				atomos1=uno.devuelve_atomos();
				atomos2=dos.devuelve_atomos();
				sort(atomos1.begin(),atomos1.end());
				sort(atomos2.begin(),atomos2.end());
				if (atomos1==atomos2){
					if (uno.comb==dos.comb){
						if (tres.conclu()=="tautologia"){
							flag=true;
						}
					}
					if (flag==true){
						escribe_richtext("Son logicamente Equivalentes");
						escribe_richtext("ambos son "+uno.conclu());
					}else{
						escribe_richtext("Distinto valor logico");
						escribe_richtext(traduce(uno.devolver())+" -->> "+uno.conclu());
						escribe_richtext(traduce(dos.devolver())+" -->> "+dos.conclu());
					}
				}else{
					escribe_richtext("Utilice las mismas variables en ambas proposiciones");
				}
			}else{
				escribe_richtext("Informe de errores de sintaxis");
				escribe_errores(log3);
				escribe_errores(log4);
			}
		}else{
			escribe_richtext("Informe de errores");
			escribe_errores(log);
			escribe_errores(log2);
		}
	}
}

void eventos_equiva::click_cancel( wxCommandEvent& event ) {
	EndModal(0);
}

eventos_equiva::~eventos_equiva() {
}

void eventos_equiva::click_cargar_1( wxFileDirPickerEvent& event ) {	
	wxString filename;
	filename=m_filePicker1->GetPath();
	char buf[100];
	strcpy( buf, (const char*)filename.mb_str(wxConvUTF8) );
	string cov=buf;

	
	eligem1->Disable();
	eligem1->Clear();
	sentencias.clear();
	box_resu->Clear();
	int canti=0;
//	wxMessageBox(filename);
	if (!filename.empty()){
		char buf[100];
		strcpy( buf, (const char*)filename.mb_str(wxConvUTF8) );
		string cov=buf;
		//tengo direccion
		fstream reporte_out(cov.c_str(),ios::in| ios::binary);
		string texo;
		char tex;
		if (reporte_out.good()==true){
			int tam;
			reporte_out.seekg(0,ios::end);
			tam=reporte_out.tellg();
			tam=tam/sizeof(tex);
			reporte_out.seekg(0,ios::beg);
			for (int i=0;i<tam;i++){
				reporte_out.read(&tex,sizeof(tex));
				texo+=tex;
				if (tex=='{'){canti++;}
			}
			if (canti>1){eligem1->Enable();}
				string auxx;
				string ot;
				for (unsigned int i=0;i<texo.size();i++){
					if (texo[i]=='}'){
						eligem1->Append(wxString::FromAscii(auxx.c_str()));
						sentencias.push_back(auxx);
						ot=auxx;
						auxx.clear();
					}else{
						if (texo[i]!='{'){
							auxx+=texo[i];
						}
					}
				}
				sent_1->SetValue(wxString::FromAscii(ot.c_str()));
		}
		
	}
	
}

void eventos_equiva::click_cargar_2( wxFileDirPickerEvent& event ) {
	wxString filename;
	filename=m_filePicker2->GetPath();
	char buf[100];
	strcpy( buf, (const char*)filename.mb_str(wxConvUTF8) );
	string cov=buf;

	eligem2->Disable();
	eligem2->Clear();
	sentencias2.clear();
	box_resu->Clear();
	int canti=0;
//	wxMessageBox(filename);
	if (!filename.empty()){
		char buf[100];
		strcpy( buf, (const char*)filename.mb_str(wxConvUTF8) );
		string cov=buf;
		//tengo direccion
		fstream reporte_out(cov.c_str(),ios::in| ios::binary);
		string texo;
		char tex;
		if (reporte_out.good()==true){
			int tam;
			reporte_out.seekg(0,ios::end);
			tam=reporte_out.tellg();
			tam=tam/sizeof(tex);
			reporte_out.seekg(0,ios::beg);
			for (int i=0;i<tam;i++){
				reporte_out.read(&tex,sizeof(tex));
				texo+=tex;
				if (tex=='{'){canti++;}
			}
			if (canti>1){eligem2->Enable();}
				string auxx;
				string ot;
				for (unsigned int i=0;i<texo.size();i++){
					if (texo[i]=='}'){
						eligem2->Append(wxString::FromAscii(auxx.c_str()));
						sentencias2.push_back(auxx);
						ot=auxx;
						auxx.clear();
					}else{
						if (texo[i]!='{'){
							auxx+=texo[i];
						}
					}
				}
				sent_2->SetValue(wxString::FromAscii(ot.c_str()));

		}
		
	}
	
}

string eventos_equiva::traduce(string var){
//	int selector;
//	unsigned int i=0;
//	unsigned int tam=var.size();
//	char simbolo;
//	while (i<tam){
//		simbolo=var[i];
//		switch (simbolo){
//		case '.':
//			var.replace(i,1,"&");
//			break;
//		case '|':
//			var.replace(i,1,"||");
//			tam+=1;
//			i+=1;
//			break;
//		case '>':
//			var.replace(i,1,"=>");
//			tam+=1;
//			i+=1;
//			break;		
//		case '%':
//			var.replace(i,1,"<=>");
//			tam+=2;
//			i+=2;
//			break;
//		}
//		selector=0;
//		i++;
//	}
//	return var;
	
	int selector;
	unsigned int i=0;
	unsigned int tam=var.size();
	char simbolo;
	while (i<tam){
		simbolo=var[i];
		switch (simbolo){
		case '.':
			var.replace(i,1,lista_simbolo[0]);
			tam+=lista_simbolo[0].length()-1;
			i+=lista_simbolo[0].length()-1;
			break;
		case '|':
			var.replace(i,1,lista_simbolo[2]);
			tam+=lista_simbolo[2].length()-1;
			i+=lista_simbolo[2].length()-1;
			break;
		case '@':
			var.replace(i,1,lista_simbolo[4]);
			tam+=lista_simbolo[4].length()-1;
			i+=lista_simbolo[4].length()-1;
			break;
		case '#':
			var.replace(i,1,lista_simbolo[1]);
			tam+=lista_simbolo[1].length()-1;
			i+=lista_simbolo[1].length()-1;
			break;
		case '>':
			var.replace(i,1,lista_simbolo[5]);
			tam+=lista_simbolo[5].length()-1;
			i+=lista_simbolo[5].length()-1;
			break;		
		case '%':
			var.replace(i,1,lista_simbolo[6]);
			tam+=lista_simbolo[6].length()-1;
			i+=lista_simbolo[6].length()-1;
			break;
		case '?':
			var.replace(i,1,lista_simbolo[3]);
			tam+=lista_simbolo[3].length()-1;
			i+=lista_simbolo[3].length()-1;
			break;
		case '-':
			var.replace(i,1,lista_simbolo[7]);
			tam+=lista_simbolo[7].length()-1;
			i+=lista_simbolo[7].length()-1;
			break;
		}
		selector=0;
		i++;
	}
	return var;
}
void eventos_equiva::escribe_richtext(string llega){
	box_resu->AppendText(wxString::FromAscii(llega.c_str()));
	box_resu->Newline();
}
void eventos_equiva::escribe_errores(vector<string> llega){
	string aux;
	for (unsigned int i=0;i<llega.size();i++){
		aux=llega[i];
		escribe_richtext(traduce(aux));
	}
}

void eventos_equiva::click_car_var1( wxCommandEvent& event ) {
	wxString linea;
	int index=eligem1->GetCurrentSelection();
	linea=wxString::FromAscii((sentencias[index]).c_str());
	sent_1->SetValue(linea);
	box_resu->Clear();
}

void eventos_equiva::click_car_var2( wxCommandEvent& event ) {
	wxString linea;
	int index=eligem2->GetCurrentSelection();
	linea=wxString::FromAscii((sentencias2[index]).c_str());
	sent_2->SetValue(linea);
	box_resu->Clear();
}

void eventos_equiva::limpia_espacios(wxString &tex){
	int i=0;
	unsigned int selector= tex.Len();
	wxString tex2;
	wxString blanco=wxT(" ");
	for(unsigned int j=0;j<=selector;j++){
		if (tex[j]!=blanco){
			tex2+=tex[j];
			i++;
		}
	}
	tex=tex2;
}
