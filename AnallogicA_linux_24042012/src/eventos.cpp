#include "eventos.h"
#include <string>
#include "sentencia.h"
#include "eventos_equiva.h"
#include <vector>
#include "eventos_negacion.h"
#include "../logana.xpm"
#include "eventos_ayuda.h"
#include <wx/splash.h>
#include <wx/msgdlg.h>
#include <cstdio>
#include <fstream>
#include "eventos_confirmar_bin.h"
#include <iomanip>
#include "eventos_selector.h"
#include <wx/string.h>
#include <cstdlib>
#include "eventos_sudoku.h"
#include <wx/html/htmlwin.h>
using namespace std;

eventos::eventos(wxWindow *parent) : wxprincipal(parent) {
	SetIcon(wxIcon(logana_xpm));
	Show();
	Wversion=wxT("AnallogicA 1.5");
	m_statusBar1->SetStatusText(Wversion);
	//mirahtml->LoadPage(wxT("anallogica.html"));
	cargaindex();
	eventos_selector *nueva=new eventos_selector(this); //muestro ventana de simbolos
	nueva->ShowModal();	
	//cargo simbolos
	carga_simbolos();
	bot_y_neg->SetLabel(wxT("  Conjuncion \n Negativa (")+lista_simbolos_wx[1]+wxT(")"));
	bot_negacion->SetLabel(wxT("Negacion (")+lista_simbolos_wx[7]+wxT(")"));
	bot_y->SetLabel(wxT("Conjuncion (")+lista_simbolos_wx[0]+wxT(")"));
	bot_o->SetLabel(wxT("Disjuncion (")+lista_simbolos_wx[2]+wxT(")"));
	bot_o_ex->SetLabel(wxT("   Dinjuncion \n Exclusiva (")+lista_simbolos_wx[4]+wxT(")"));
	bot_imp->SetLabel(wxT("Implicacion (")+lista_simbolos_wx[5]+wxT(")"));
	bot_2imp->SetLabel(wxT("Bicondicional (")+lista_simbolos_wx[6]+wxT(")"));
	bot_o_neg->SetLabel(wxT("   Dinjuncion \n Negativa (")+lista_simbolos_wx[3]+wxT(")"));
	lista_songs();
}

eventos::~eventos() {
}

void eventos::click_exp_texto( wxCommandEvent& event ) {
	if ((!(caja->IsEmpty()))){
	wxString ruta=archi(1);//obtengo ruta de archivo 
	string Ruta=wxs2s(ruta);//cargo direxion 
	Ruta+=".html";
	fstream reporte_out;
	if (!ruta.empty()) {//compruebo que la ruta no esta vacia
		if (analizame.hecho==false){click_hacer(event);}
		FILE *fich;
		fich=fopen(Ruta.c_str(),"rb");
		analizame.reportehtml(Ruta,0);
//		if (!fich){//no existe, hacer uno
//			//analizame.reportehtml(Ruta,0);
//
//			}else{//ya existe, sobreescribir
//			eventos_confirmar_bin *nueva=new eventos_confirmar_bin(this);
//			int accion=nueva->ShowModal();//pregunto accion a realizar
//
//		}

	}
	}else{
		//crap2
		//escribe_richtext("Escriba una sentencia logica");
		wxMessageBox(wxT("Escriba una sentencia logica"));
	}
}

void eventos::click_exp_binario( wxCommandEvent& event ) {
	if (!(caja->IsEmpty())){
	wxString ruta=archi(0);
	string Ruta=wxs2s(ruta);//cargo direxion
	if (!ruta.empty()){
		FILE *fich;
		fich=fopen(Ruta.c_str(),"rb");
		wxString tex;
		tex=caja->GetValue();
		string covv=wxs2s(tex);
		string cov="{"+covv+"}";
		if (!fich){//no existe, hacer uno
			sentencia analizame(covv);
			Ruta+=".vpl";
			analizame.reporte_bina(Ruta);
		}else{//ya existe,sobreescribir o añadir?  //añadir por el momento
			eventos_confirmar_bin *nueva=new eventos_confirmar_bin(this);
			int accion=nueva->ShowModal();
			if (accion==0){
				fstream reporte_out(Ruta.c_str(), ios::out| ios::binary);
				reporte_out.clear();
				if (reporte_out.good()==true){
					char tex;
					for (unsigned int i=0;i<cov.size();i++){
						tex=cov[i];
						reporte_out.write(&tex,sizeof(tex));
					}
					reporte_out.close();
				}
			}
			if (accion==1){
				fstream reporte_out(Ruta.c_str(), ios::out| ios::binary|ios::app);
				reporte_out.seekg(ios::end);
				if (reporte_out.good()==true){
					char tex;
					for (unsigned int i=0;i<cov.size();i++){
						tex=cov[i];
						reporte_out.write(&tex,sizeof(tex));
					}
					reporte_out.close();
				}
			}
		}
		m_statusBar1->SetStatusText(wxT("Archivo Exportado con exito!"));
	}
}else{
		//crap2
		//escribe_richtext("Escriba una sentencia logica");
		wxMessageBox(wxT("Escriba una sentencia logica"));
	}
}

void eventos::clikc_imp_binario( wxCommandEvent& event ) {
	wxString filename=archi(0);//obtengo ruta de archivo
	int canti=0;
	if (!filename.empty()){
		if ((m_menuItem10->IsEnabled())==true){//si selecciona borro todo lo anteriror
		click_cerrar_bin(event);
		var_car->Clear();
		var_car->Disable();
		sentencias.clear();
		click_borrar(event);
		}
		string cov=wxs2s(filename);
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
			if (canti>1){var_car->Enable();}
				string auxx;
				string ot;
				for (unsigned int i=0;i<texo.size();i++){
					if (texo[i]=='}'){
						var_car->Append(wxString::FromAscii(auxx.c_str()));
						sentencias.push_back(auxx);
						ot=auxx;
						auxx.clear();
					}else{
						if (texo[i]!='{'){
							auxx+=texo[i];
						}
					}
				}
				caja->SetValue(wxString::FromAscii(ot.c_str()));
				var_car->UpdateWindowUI();
				m_menuItem10->Enable();
			m_statusBar1->SetStatusText(wxT("Archivo importado con exito!"));
		}
	}
}

void eventos::click_salir( wxCommandEvent& event ) {//cerrar programa
	Close();
}

void eventos::click_sintaxis( wxCommandEvent& event ) {
	//limpio todo antes de hacer
	wxString tex;
	tex=caja->GetValue();//saco variable de la caja de texo
	string cov=wxs2s(tex);// sentencia en string
	sentencia uno(cov);//creo el objeto
	vector<string> log; //vector con posibles errores
	analizame=uno;//copia 
	if (uno.errores(cov,log,lista_simbolos)==false){
		uno.traduce(lista_simbolos);
		analizame.traduce(lista_simbolos);
		if (uno.analiza_sintaxis(log)==true){
			cargaindex();
			wxMessageBox(wxT("Sintaxis correcta"),wxT("info"),wxICON_INFORMATION);
			m_statusBar1->SetStatusText(wxT("Sintaxis correcta"));
		}else{
			//crap2
			//escribe_richtext("Informe de errores de sintaxis");
			analizame.indexhtml("anafile.html",0,log);
			mirahtml->LoadPage(wxT("anafile.html"));
			m_statusBar1->SetStatusText(wxT("Errores de sintaxis"));
		}
	}else{
		//crap2
		//escribe_richtext("Informe de errores");
		analizame.indexhtml("anafile.html",0,log);
		mirahtml->LoadPage(wxT("anafile.html"));
		m_statusBar1->SetStatusText(wxT("Errores"));
	}	
}

void eventos::click_about( wxCommandEvent& event ) {

}

void eventos::click_abre_par( wxCommandEvent& event ) {
	set_caja("(");	
}

void eventos::click_cierra_par( wxCommandEvent& event ) {
	set_caja(")");
}

void eventos::click_negacion( wxCommandEvent& event ) {
	set_caja(lista_simbolos[7]);
}

void eventos::click_y( wxCommandEvent& event ) {
	set_caja(lista_simbolos[0]);
}

void eventos::click_o( wxCommandEvent& event ) {
	set_caja(lista_simbolos[2]);
	
}
void eventos::click_o_ex( wxCommandEvent& event ) {
	set_caja(lista_simbolos[4]);
}
void eventos::click_imp( wxCommandEvent& event ) {
	set_caja(lista_simbolos[5]);
}

void eventos::click_2imp( wxCommandEvent& event ) {
	set_caja(lista_simbolos[6]);
}

void eventos::click_choice( wxCommandEvent& event ) {
	int index=box_variables->GetCurrentSelection();
	wxString arreglo(wxT("abcdefghijklmnopqrstuvwxyz"));
	caja->WriteText(arreglo[index]);
}

void eventos::click_hacer( wxCommandEvent& event ) {
	//crap
	cargaindex();
	analizame.limpia();
	carga_simbolos();
	//limpio todo antes de hacer
	wxString tex;
	tex=caja->GetValue();//saca sentencia de la caja de texto en wxString
	limpia_espacios(tex);//limpia caracteres en blanco
	caja->SetValue(tex);// reemplazo por texto sin espacios en caja 
	string cov=wxs2s(tex);//sentencia en srting
	srand ( time(NULL) );
	if (cov=="666"){
		for (int i=1;i<666;i++){
			wxString plop=wxT("Up the Irons ");
			wxMessageBox(songs[rand()%51],plop,wxICON_INFORMATION);
		}
		wxString plop=wxT("Up the Irons! 666/666");
		wxMessageBox(wxT("The number of the beast \\m/"),plop,wxICON_INFORMATION);
	}else{
		if (cov=="skilltik"){
			wxMessageBox(wxT("Henry Suarez \n a.k.a Skilltik \n skilltik@gmail.com"),wxT("info"),wxICON_INFORMATION);
		}else{
			if (cov=="day"){
				eventos_sudoku *nsudoku=new eventos_sudoku(this);
				nsudoku->Show();	
			}else{
			vector<string> log;//vector para recoger errores si existen
			sentencia uno(cov);//creo variable para el proceso
			analizame=uno;//copia para otras acciones
			if (analizame.errores(cov,log,lista_simbolos)==false){//compruebo errores de simbolos
				uno.traduce(lista_simbolos);      //traduce a lenguaje del programa
				analizame.traduce(lista_simbolos);//
				if (analizame.analiza_sintaxis(log)==true){//compruebo errores de sintaxis
					if (analizame.resuelve(unoos)==true){ //aplica el algoritmo
						uno.resuelve(unoos);       				
						analizame.indexhtml("anafile.html",1,log);
						mirahtml->LoadPage(wxT("anafile.html"));
						if (uno.supera_abc==false){
							//
						}else{
							m_statusBar1->SetStatusText(wxT("ANALISIS NO COMPLETADO, DEMASIADAS COMBINACIONES!!"));
							wxMessageBox(wxT("ANALISIS NO COMPLETADO, DEMASIADAS COMBINACIONES!!"));
						}
						int aux[3];
						uno.contador(aux);														
						m_statusBar1->SetStatusText(wxT("listo!"));								//
					}else{
						m_statusBar1->SetStatusText(wxT("ANALISIS NO COMPLETADO, DEMASIADAS VARIABLES DISTINTAS!!"));
						wxMessageBox(wxT("ANALISIS NO COMPLETADO, DEMASIADAS VARIABLES DISTINTAS!!"));
					}
				}else{
					analizame.indexhtml("anafile.html",0,log);
					mirahtml->LoadPage(wxT("anafile.html"));
					m_statusBar1->SetStatusText(wxT("Errores de sintaxis"));
				}
			}else{
				m_statusBar1->SetStatusText(wxT("Errores!"));
				analizame.indexhtml("anafile.html",0,log);
				mirahtml->LoadPage(wxT("anafile.html"));
			}	
			}
	}
	}
}

void eventos::click_borrar( wxCommandEvent& event ) {
	caja->Clear();
	cargaindex();
	m_statusBar1->SetStatusText(Wversion);
	
}

void eventos::click_equi( wxCommandEvent& event ) {
	eventos_equiva *nueva=new eventos_equiva(lista_simbolos,this);
	nueva->ShowModal();
}

string eventos::traduce(string var){
	int selector;
	unsigned int i=0;
	unsigned int tam=var.size();
	char simbolo;
	while (i<tam){
		simbolo=var[i];
		switch (simbolo){
		case '.':
			var.replace(i,1,lista_simbolos[0]);
			tam+=lista_simbolos[0].length()-1;
			i+=lista_simbolos[0].length()-1;
			break;
		case '|':
			var.replace(i,1,lista_simbolos[2]);
			tam+=lista_simbolos[2].length()-1;
			i+=lista_simbolos[2].length()-1;
			break;
		case '@':
			var.replace(i,1,lista_simbolos[4]);
			tam+=lista_simbolos[4].length()-1;
			i+=lista_simbolos[4].length()-1;
			break;
		case '#':
			var.replace(i,1,lista_simbolos[1]);
			tam+=lista_simbolos[1].length()-1;
			i+=lista_simbolos[1].length()-1;
			break;
		case '>':
			var.replace(i,1,lista_simbolos[5]);
			tam+=lista_simbolos[5].length()-1;
			i+=lista_simbolos[5].length()-1;
			break;		
		case '%':
			var.replace(i,1,lista_simbolos[6]);
			tam+=lista_simbolos[6].length()-1;
			i+=lista_simbolos[6].length()-1;
			break;
		case '?':
			var.replace(i,1,lista_simbolos[3]);
			tam+=lista_simbolos[3].length()-1;
			i+=lista_simbolos[3].length()-1;
			break;
		case '-':
			var.replace(i,1,lista_simbolos[7]);
			tam+=lista_simbolos[7].length()-1;
			i+=lista_simbolos[7].length()-1;
			break;
		}
		selector=0;
		i++;
	}
	return var;
}

void eventos::click_prob_negacion( wxCommandEvent& event ) {
	eventos_negacion *nueva=new eventos_negacion(lista_simbolos,this);
	nueva->ShowModal();
}
void eventos::set_caja(string met){
	caja->WriteText(wxString::FromAscii(met.c_str()));
}

wxString eventos::archi(int tipo){
	if(tipo==0){//binario
		wxString ruta =	wxFileSelector(wxT("Selecciona un nombre de archivo"), wxT(""),wxT("Anallogica_"),wxT("*.vpl"),wxT("*.vpl"));
		return ruta;
	}else{
		if (tipo==1){//texto
		wxString ruta =	wxFileSelector(wxT("Selecciona un nombre de archivo"), wxT(""),wxT("Anallogica_"),wxT("*.html"),wxT("*.html"));
		return ruta;
		}else{//csv
			wxString ruta =	wxFileSelector(wxT("Selecciona un nombre de archivo"), wxT(""),wxT("Anallogica_"),wxT("*.csv"),wxT("*.csv"));
			return ruta;
		}
	}
}

void eventos::click_cerrar_bin( wxCommandEvent& event ) {
	var_car->Clear();
	var_car->Disable();
	sentencias.clear();
	click_borrar(event);
	m_menuItem10->Enable(false);
}

void eventos::press_enter( wxCommandEvent& event ) {
	click_hacer(event);
}
string eventos::wxs2s(wxString pasa){
	char buf[500];																//
	strcpy( buf, (const char*)(pasa).mb_str(wxConvUTF8) );	//convuerto direccion a string
	string cov=buf;	
	return cov;
}

void eventos::click_exp_excel( wxCommandEvent& event ) {
	if ((!(caja->IsEmpty()))){
		if (analizame.hecho==false){click_hacer(event);}
		wxString ruta=archi(2);//obtengo ruta de archivo 
		string Ruta=wxs2s(ruta);//cargo direxion 
		Ruta+=".csv";
		if (!ruta.empty()) {//compruebo que la ruta no esta vacia
			if (analizame.hecho==false){click_hacer(event);}
			FILE *fich;
			fich=fopen(Ruta.c_str(),"rb");
			if (!fich){//no existe, hacer uno
				fstream reporte_out;
				reporte_out.open(Ruta.c_str(), ios::app| ios::out);
				if (reporte_out.good()==true){
					string dat;
					for (int k=0;k<analizame.cantidad_atomos_int;k++){//muestro los atomos
						reporte_out<<analizame.tabla_logica[0][k]<<",";
					}
					for (int k=0;k<analizame.cantidad_renombrado;k++){//muestro las moleculas
						reporte_out<<analizame.traduce_inver(analizame.tabla_renombrado[k][0])<<",";
					}
					reporte_out<<endl;
					for (int k=1;k<analizame.comb+1;k++){//mostrar matriz
						for (int i=0;i<analizame.total_renombrado;i++){
							reporte_out<<analizame.tabla_logica[k][i]<<",";
						}
						reporte_out<<endl;
					}
					reporte_out.close();
				}
			}else{//ya existe, aniadir o sobreescribir? 
			}
			m_statusBar1->SetStatusText(wxT("Archivo Exportado con exito!"));
		}
	}else{
		//crap2
		//escribe_richtext("Escriba una sentencia logica");
		wxMessageBox(wxT("Escriba una sentencia logica"));
	}
}

void eventos::caja_cambia( wxCommandEvent& event ) {
	analizame.hecho=false;
}



void eventos::click_y_neg( wxCommandEvent& event ) {
	set_caja(lista_simbolos[1]);	
}

void eventos::click_o_neg( wxCommandEvent& event ) {
	set_caja(lista_simbolos[3]);
}

void eventos::limpia_espacios(wxString &tex){
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
void eventos::click_simbologia( wxCommandEvent& event ) {
	eventos_selector *nueva=new eventos_selector(this);
	nueva->ShowModal();	
	carga_simbolos();
	bot_y_neg->SetLabel(wxT("  Conjuncion \n Negativa (")+lista_simbolos_wx[1]+wxT(")"));
	bot_negacion->SetLabel(wxT("Negacion (")+lista_simbolos_wx[7]+wxT(")"));
	bot_y->SetLabel(wxT("Conjuncion (")+lista_simbolos_wx[0]+wxT(")"));
	bot_o->SetLabel(wxT("Disjuncion (")+lista_simbolos_wx[2]+wxT(")"));
	bot_o_ex->SetLabel(wxT("   Dinjuncion \n Exclusiva (")+lista_simbolos_wx[4]+wxT(")"));
	bot_imp->SetLabel(wxT("Implicacion (")+lista_simbolos_wx[5]+wxT(")"));
	bot_2imp->SetLabel(wxT("Bicondicional (")+lista_simbolos_wx[6]+wxT(")"));
	bot_o_neg->SetLabel(wxT("   Dinjuncion \n Negativa (")+lista_simbolos_wx[3]+wxT(")"));
}
void eventos::carga_simbolos(){
	fstream simbologia;
	unoos="1";
	simbologia.open("simbologia",ios::in);
	if (simbologia.good()==true){
		for (int i=0;i<9;i++){
			if (i!=8){
				simbologia>>lista_simbolos[i];
				lista_simbolos_wx[i]=wxString::FromAscii(lista_simbolos[i].c_str());
			}else{
				simbologia>>unoos;
			}	
		}
		//
	}
}

string eventos::num(int i){	//   int a string
	string num;
	int temp;
	while(i / 10!=0){
		temp=i%10;
		i= i/10;
		temp =temp + 48;
		num = (char)temp + num;
	}
	i=i+48;
	num = (char)i + num ;
	return num;
}

void eventos::lista_songs(){
	songs[	0	]=wxT("	2 Minutes to Midnight	");
	songs[	1	]=wxT("	Aces High 	");
	songs[	2	]=wxT("	The Angel and the Gambler	");
	songs[	3	]=wxT("	Be Quick or Be Dead	");
	songs[	4	]=wxT("	Bring Your Daughter... to the Slaughter	");
	songs[	5	]=wxT("	Can I Play with Madness	");
	songs[	6	]=wxT("	Charlotte the Harlot	");
	songs[	7	]=wxT("	The Clairvoyant 	");
	songs[	8	]=wxT("	Cross-Eyed Mary	");
	songs[	9	]=wxT("	Different World 	");
	songs[	10	]=wxT("	El Dorado 	");
	songs[	11	]=wxT("	The Evil That Men Do 	");
	songs[	12	]=wxT("	Fear of the Dark 	");
	songs[	13	]=wxT("	Flight of Icarus	");
	songs[	14	]=wxT("	From Here to Eternity	");
	songs[	15	]=wxT("	Futureal	");
	songs[	16	]=wxT("	Hallowed Be Thy Name	");
	songs[	17	]=wxT("	Holy Smoke 	");
	songs[	18	]=wxT("	I Got the Fire	");
	songs[	19	]=wxT("	Infinite Dreams	");
	songs[	20	]=wxT("	Iron Maiden 	");
	songs[	21	]=wxT("	Lord of the Flies 	");
	songs[	22	]=wxT("	Man on the Edge	");
	songs[	23	]=wxT("	The Number of the Beast 	");
	songs[	24	]=wxT("	Out of the Silent Planet 	");
	songs[	25	]=wxT("	Paschendale 	");
	songs[	26	]=wxT("	Phantom of the Opera 	");
	songs[	27	]=wxT("	Prowler	");
	songs[	28	]=wxT("	Prowler '88	");
	songs[	29	]=wxT("	Purgatory 	");
	songs[	30	]=wxT("	Quest for Fire 	");
	songs[	31	]=wxT("	Rainmaker 	");
	songs[	32	]=wxT("	The Reincarnation of Benjamin Breeg	");
	songs[	33	]=wxT("	Remember Tomorrow	");
	songs[	34	]=wxT("	Roll Over Beethoven	");
	songs[	35	]=wxT("	Run to the Hills	");
	songs[	36	]=wxT("	Running Free	");
	songs[	37	]=wxT("	Sanctuary 	");
	songs[	38	]=wxT("	Satellite 15... The Final Frontier	");
	songs[	39	]=wxT("	Strange World 	");
	songs[	40	]=wxT("	Stranger in a Strange Land 	");
	songs[	41	]=wxT("	Transylvania 	");
	songs[	42	]=wxT("	The Trooper	");
	songs[	43	]=wxT("	Twilight Zone	");
	songs[	44	]=wxT("	Virus 	");
	songs[	45	]=wxT("	Wasted Years	");
	songs[	46	]=wxT("	Wasting Love	");
	songs[	47	]=wxT("	The Wicker Man 	");
	songs[	48	]=wxT("	Wildest Dreams 	");
	songs[	49	]=wxT("	Women in Uniform	");
	songs[	50	]=wxT("	Wrathchild	");
}

void eventos::cargaindex(){
	mirahtml->SetPage(wxT("<html><head><title></title></head><body bgcolor=\"BLACK\" align=\"center\"><br><br><br><center><font size=\"-3\">"
		"<font color=black>***********</font><font color=#030303>*</font><font color=#131313>*</font><font color=#212121>*</font><font color=#323232>*</font><font color=#464646>*</font><font color=#525252>*</font><font color=#575757>*</font><font color=#585858>*</font><font color=#555555>*</font><font color=#4b4b4b>*</font><font color=#3a3a3a>*</font><font color=#262626>*</font><font color=#181818>*</font><font color=#080808>*</font><font color=black>***************************************************************************************************************************************</font><br><font color=black>*********</font><font color=#242424>*</font><font color=#737373>*</font><font color=#b7b7b7>*</font><font color=#dcdcdc>*</font><font color=#f4f4f4>*</font><font color=#fefefe>*</font><font color=#f9f9f9>*</font><font color=#e2e2e2>*</font><font color=#d5d5d5>*</font><font color=#d3d3d3>*</font><font color=#dbdbdb>*</font><font color=#f1f1f1>*</font><font color=white>*</font><font color=#fafafa>*</font><font "
		"color=#e6e6e6>*</font><font color=#c7c7c7>*</font><font color=#8f8f8f>*</font><font color=#3f3f3f>*</font><font color=#040404>*</font><font color=black>***************************************</font><font color=#050505>*</font><font color=#323232>*</font><font color=#1e1e1e>*</font><font color=black>*************************************************************</font><font color=#171717>*</font><font color=#3b3b3b>*</font><font color=#080808>*</font><font color=black>**************************</font><br><font color=black>********</font><font color=#6f6f6f>*</font><font color=#ececec>*</font><font color=white>***</font><font color=#ececec>*</font><font color=#737373>*</font><font color=#282828>*</font><font color=#161616>*</font><font color=#111111>*</font><font color=#101010>*</font><font color=#131313>*</font><font color=#1e1e1e>*</font><font color=#4f4f4f>*</font><font color=#c4c4c4>*</font><font color=white>***</font><font color=#f7f7f7>*</font><font color=#b0b0b0>*</font><font color=#0f0f0f>*</font><font "
		"color=black>***********************************</font><font color=#030303>*</font><font color=#282828>*</font><font color=#7d7d7d>*</font><font color=#cdcdcd>*</font><font color=#cbcbcb>*</font><font color=#343434>*</font><font color=black>*************************************************************</font><font color=#212121>*</font><font color=#c7c7c7>*</font><font color=#d0d0d0>*</font><font color=#747474>*</font><font color=#191919>*</font><font color=#010101>*</font><font color=black>***********************</font><br><font color=black>*******</font><font color=#2c2c2c>*</font><font color=#fcfcfc>*</font><font color=white>****</font><font color=#525252>*</font><font color=#3b3b3b>*</font><font color=#c3c3c3>******</font><font color=#848484>*</font><font color=#0b0b0b>*</font><font color=#e6e6e6>*</font><font color=white>****</font><font color=#878787>*</font><font color=black>********************************</font><font color=#080808>*</font><font color=#2e2e2e>*</font><font color=#797979>*</font><font "
		"color=#cdcdcd>*</font><font color=#fdfdfd>*</font><font color=#f1f1f1>*</font><font color=#858585>*</font><font color=#0a0a0a>*</font><font color=black>***************************************************************</font><font color=#0b0b0b>*</font><font color=#949494>*</font><font color=#f9f9f9>*</font><font color=#f7f7f7>*</font><font color=#a9a9a9>*</font><font color=#494949>*</font><font color=#0f0f0f>*</font><font color=black>*********************</font><br><font color=black>*******</font><font color=#2c2c2c>*</font><font color=#fbfbfb>*</font><font color=white>****</font><font color=#525252>*</font><font color=#272727>*</font><font color=#828282>******</font><font color=#585858>*</font><font color=#0d0d0d>*</font><font color=#e5e5e5>*</font><font color=white>****</font><font color=#878787>*</font><font color=black>*****************************</font><font color=#020202>*</font><font color=#2d2d2d>*</font><font color=#777777>*</font><font color=#c5c5c5>*</font><font color=#f6f6f6>*</font><font "
		"color=white>**</font><font color=#c2c2c2>*</font><font color=#373737>*</font><font color=#010101>*</font><font color=black>*****************************************************************</font><font color=#0a0a0a>*</font><font color=#5e5e5e>*</font><font color=#e8e8e8>*</font><font color=white>*</font><font color=#fdfdfd>*</font><font color=#d3d3d3>*</font><font color=#7d7d7d>*</font><font color=#282828>*</font><font color=black>*******************</font><br><font color=black>*</font><font color=#020202>*</font><font color=black>*****</font><font color=#020202>*</font><font color=#757575>*</font><font color=#f3f3f3>*</font><font color=white>***</font><font color=#e7e7e7>*</font><font color=#6e6e6e>*</font><font color=#1e1e1e>*</font><font color=#080808>*</font><font color=#070707>*</font><font color=#060606>*</font><font color=#070707>*</font><font color=#101010>*</font><font color=#494949>*</font><font color=#bfbfbf>*</font><font color=white>***</font><font color=#fbfbfb>*</font><font color=#b7b7b7>*</"
		"font><font color=#131313>*</font><font color=black>**************************</font><font color=#040404>*</font><font color=#222222>*</font><font color=#747474>*</font><font color=#c8c8c8>*</font><font color=#f3f3f3>*</font><font color=white>***</font><font color=#f0f0f0>*</font><font color=#707070>*</font><font color=#0b0b0b>*</font><font color=#161616>*</font><font color=#7e7e7e>*</font><font color=#3b3b3b>*</font><font color=black>******************************************************</font><font color=#030303>*</font><font color=#040404>*</font><font color=#050505>*</font><font color=black>******</font><font color=#040404>*</font><font color=#cdcdcd>*</font><font color=#acacac>*</font><font color=#373737>*</font><font color=#c4c4c4>*</font><font color=#fefefe>*</font><font color=white>**</font><font color=#f0f0f0>*</font><font color=#b4b4b4>*</font><font color=#515151>*</font><font color=#0a0a0a>*</font><font color=black>****************</font><br><font color=#060606>*</font><font color=#a0a0a0>*</"
		"font><font color=#959595>*</font><font color=#727272>*</font><font color=#4f4f4f>*</font><font color=#303030>*</font><font color=#101010>*</font><font color=black>**</font><font color=#212121>*</font><font color=#787878>*</font><font color=#bdbdbd>*</font><font color=#dfdfdf>*</font><font color=#f0f0f0>*</font><font color=#fbfbfb>*</font><font color=#fdfdfd>*</font><font color=#e9e9e9>*</font><font color=#d8d8d8>*</font><font color=#d6d6d6>*</font><font color=#e1e1e1>*</font><font color=#f8f8f8>*</font><font color=#fdfdfd>*</font><font color=#f5f5f5>*</font><font color=#e6e6e6>*</font><font color=#cdcdcd>*</font><font color=#949494>*</font><font color=#414141>*</font><font color=#020202>*</font><font color=black>**</font><font color=#050505>*</font><font color=#141414>*</font><font color=#252525>*</font><font color=#3c3c3c>*</font><font color=#313131>*</font><font color=black>*****************</font><font color=#050505>*</font><font color=#292929>*</font><font color=#717171>*</font><font color=#c3c3c3>*</"
		"font><font color=#fbfbfb>*</font><font color=#e9e9e9>*</font><font color=#d1d1d1>*</font><font color=#e9e9e9>*</font><font color=white>*</font><font color=#fbfbfb>*</font><font color=#b1b1b1>*</font><font color=#242424>*</font><font color=#0b0b0b>*</font><font color=#696969>*</font><font color=#e8e8e8>*</font><font color=#fcfcfc>*</font><font color=#404040>*</font><font color=#010101>*</font><font color=black>**</font><font color=#101010>*</font><font color=#4f4f4f>**</font><font color=#4d4d4d>*</font><font color=#060606>*</font><font color=black>*</font><font color=#2f2f2f>*</font><font color=#434343>****</font><font color=#363636>*</font><font color=#030303>*</font><font color=black>*</font><font color=#202020>*</font><font color=#484848>*</font><font color=#454545>*</font><font color=#2a2a2a>*</font><font color=black>*</font><font color=#0f0f0f>*</font><font color=#535353>*</font><font color=#565656>*</font><font color=#4b4b4b>*</font><font color=#0a0a0a>*</font><font color=#050505>*</font><font color=#"
		"727272>*</font><font color=#888888>*</font><font color=#828282>*</font><font color=#6e6e6e>*</font><font color=#6d6d6d>**</font><font color=#6c6c6c>*</font><font color=#727272>*</font><font color=#7b7b7b>*</font><font color=#151515>*</font><font color=#212121>*</font><font color=#828282>*</font><font color=#858585>*</font><font color=#818181>*</font><font color=#7d7d7d>*</font><font color=#797979>*</font><font color=#757575>*</font><font color=#636363>*</font><font color=#151515>*</font><font color=black>******</font><font color=#030303>*</font><font color=#adadad>*</font><font color=#c5c5c5>*</font><font color=#c3c3c3>*</font><font color=#020202>*</font><font color=#070707>*</font><font color=#303030>*</font><font color=#7b7b7b>*</font><font color=#989898>*</font><font color=#9a9a9a>*</font><font color=#9b9b9b>*</font><font color=#e6e6e6>*</font><font color=white>*</font><font color=#cdcdcd>*</font><font color=#2f2f2f>*</font><font color=#888888>*</font><font color=#f6f6f6>*</font><font color=white>*</"
		"font><font color=#cbcbcb>**</font><font color=#f6f6f6>*</font><font color=#e0e0e0>*</font><font color=#868686>*</font><font color=#2e2e2e>*</font><font color=#050505>*</font><font color=black>*************</font><br><font color=black>*</font><font color=#656565>*</font><font color=#fafafa>*</font><font color=white>**</font><font color=#fafafa>*</font><font color=#949494>*</font><font color=#010101>*</font><font color=black>***</font><font color=#020202>*</font><font color=#141414>*</font><font color=#292929>*</font><font color=#3b3b3b>*</font><font color=#6a6a6a>*</font><font color=white>*****</font><font color=#646464>*</font><font color=#303030>*</font><font color=#1d1d1d>*</font><font color=#060606>*</font><font color=black>****</font><font color=#171717>*</font><font color=#bfbfbf>*</font><font color=#dcdcdc>*</font><font color=#f0f0f0>*</font><font color=#fefefe>*</font><font color=#8d8d8d>*</font><font color=black>****************</font><font color=#282828>*</font><font color=#b7b7b7>*</font><font "
		"color=#f1f1f1>*</font><font color=white>*</font><font color=#b1b1b1>*</font><font color=#5c5c5c>*</font><font color=#4e4e4e>*</font><font color=#dfdfdf>*</font><font color=white>**</font><font color=#9f9f9f>*</font><font color=#060606>*</font><font color=black>*</font><font color=#525252>*</font><font color=#fefefe>*</font><font color=white>**</font><font color=#e9e9e9>*</font><font color=#a2a2a2>*</font><font color=#424242>*</font><font color=#040404>*</font><font color=#3d3d3d>*</font><font color=white>**</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#b0b0b0>*</font><font color=white>*</font><font color=#ededed>*</font><font color=#909090>*</font><font color=#c6c6c6>*</font><font color=#f8f8f8>*</font><font color=#939393>*</font><font color=#101010>*</font><font color=#131313>*</font><font color=#9b9b9b>*</font><font color=#fdfdfd>*</font><font color=#ededed>*</font><font color=#626262>*</font><font color=#030303>*</font><font color=#585858>*</"
		"font><font color=#e9e9e9>*</font><font color=#fefefe>*</font><font color=#b3b3b3>*</font><font color=#1b1b1b>*</font><font color=#404040>*</font><font color=#f0f0f0>*</font><font color=#f5f5f5>*</font><font color=#515151>*</font><font color=#1d1d1d>**</font><font color=#1e1e1e>*</font><font color=#2c2c2c>*</font><font color=#dadada>*</font><font color=#c7c7c7>*</font><font color=#232323>*</font><font color=#6d6d6d>*</font><font color=#f9f9f9>*</font><font color=white>*</font><font color=#f9f9f9>*</font><font color=#d4d4d4>*</font><font color=#d3d3d3>**</font><font color=#adadad>*</font><font color=#3e3e3e>*</font><font color=black>*****</font><font color=#060606>*</font><font color=#ededed>*</font><font color=#e9e9e9>*</font><font color=#848484>*</font><font color=#030303>*</font><font color=#646464>*</font><font color=#f5f5f5>*</font><font color=white>*</font><font color=#d6d6d6>*</font><font color=gray>*</font><font color=#777777>*</font><font color=#767676>*</font><font color=#747474>*</font><font color=#"
		"737373>*</font><font color=#535353>*</font><font color=#030303>*</font><font color=#7c7c7c>*</font><font color=white>*</font><font color=#f7f7f7>*</font><font color=#686868>*</font><font color=#393939>*</font><font color=#939393>*</font><font color=#f9f9f9>*</font><font color=#f3f3f3>*</font><font color=#b5b5b5>*</font><font color=#1e1e1e>*</font><font color=black>************</font><br><font color=black>*</font><font color=#020202>*</font><font color=#474747>*</font><font color=#cdcdcd>*</font><font color=#fafafa>*</font><font color=white>*</font><font color=#fafafa>*</font><font color=#adadad>*</font><font color=#575757>*</font><font color=#272727>*</font><font color=#121212>*</font><font color=#0d0d0d>*</font><font color=#0b0b0b>*</font><font color=#0a0a0a>*</font><font color=#090909>*</font><font color=#333333>*</font><font color=white>*****</font><font color=#3a3a3a>*</font><font color=#090909>*</font><font color=#0a0a0a>*</font><font color=#0c0c0c>*</font><font color=#101010>*</font><font color=#"
		"202020>*</font><font color=#454545>*</font><font color=gray>*</font><font color=#dddddd>*</font><font color=white>**</font><font color=#fafafa>*</font><font color=#c7c7c7>*</font><font color=#343434>*</font><font color=black>**************</font><font color=#020202>*</font><font color=#505050>*</font><font color=#e9e9e9>*</font><font color=white>**</font><font color=#a3a3a3>*</font><font color=#050505>*</font><font color=#020202>*</font><font color=#626262>*</font><font color=white>***</font><font color=#787878>*</font><font color=black>**</font><font color=#5a5a5a>*</font><font color=white>***</font><font color=#e4e4e4>*</font><font color=#f9f9f9>**</font><font color=#d0d0d0>*</font><font color=#a2a2a2>*</font><font color=white>**</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#aeaeae>*</font><font color=white>*</font><font color=#f7f7f7>*</font><font color=#1a1a1a>*</font><font color=#161616>*</font><font color=#ababab>*</font><font color=#fdfdfd>*</"
		"font><font color=#d1d1d1>*</font><font color=#373737>*</font><font color=#050505>*</font><font color=#636363>*</font><font color=#f0f0f0>*</font><font color=#fafafa>*</font><font color=#969696>*</font><font color=#0c0c0c>*</font><font color=#282828>*</font><font color=#c9c9c9>*</font><font color=#fefefe>*</font><font color=#dfdfdf>*</font><font color=#444444>*</font><font color=#4b4b4b>*</font><font color=#f3f3f3>*</font><font color=#e4e4e4>*</font><font color=#3a3a3a>*</font><font color=#232323>*</font><font color=#282828>*</font><font color=#2e2e2e>*</font><font color=#979797>*</font><font color=white>*</font><font color=#d9d9d9>*</font><font color=#272727>*</font><font color=#5a5a5a>*</font><font color=#f4f4f4>*</font><font color=#fdfdfd>*</font><font color=#959595>*</font><font color=#131313>*</font><font color=#0b0b0b>**</font><font color=#090909>*</font><font color=black>*****</font><font color=#080808>*</font><font color=#858585>*</font><font color=#656565>*</font><font color=#cdcdcd>*</font><font "
		"color=#151515>*</font><font color=#717171>*</font><font color=white>**</font><font color=#8b8b8b>*</font><font color=black>*******</font><font color=#555555>*</font><font color=white>**</font><font color=#e2e2e2>*</font><font color=#0f0f0f>*</font><font color=#020202>*</font><font color=#595959>*</font><font color=#f5f5f5>*</font><font color=white>*</font><font color=#d6d6d6>*</font><font color=#262626>*</font><font color=black>***********</font><br><font color=black>***</font><font color=#040404>*</font><font color=#424242>*</font><font color=#919191>*</font><font color=#cdcdcd>*</font><font color=#ebebeb>*</font><font color=#fdfdfd>*</font><font color=white>*</font><font color=#f7f7f7>*</font><font color=#eaeaea>*</font><font color=#e2e2e2>*</font><font color=#dbdbdb>*</font><font color=#d6d6d6>*</font><font color=#d8d8d8>*</font><font color=white>*****</font><font color=#d8d8d8>*</font><font color=#d5d5d5>*</font><font color=#dddddd>*</font><font color=#e8e8e8>*</font><font color=#f5f5f5>*</font><font "
		"color=#fefefe>*</font><font color=white>*</font><font color=#fefefe>*</font><font color=#efefef>*</font><font color=#d1d1d1>*</font><font color=#959595>*</font><font color=#414141>*</font><font color=#030303>*</font><font color=black>**************</font><font color=#0b0b0b>*</font><font color=#868686>*</font><font color=#fbfbfb>*</font><font color=white>**</font><font color=#ececec>*</font><font color=#767676>*</font><font color=#8e8e8e>*</font><font color=#b0b0b0>*</font><font color=#e0e0e0>*</font><font color=white>***</font><font color=#666666>*</font><font color=black>**</font><font color=#5a5a5a>*</font><font color=white>***</font><font color=#5d5d5d>*</font><font color=#404040>*</font><font color=#ababab>*</font><font color=#f2f2f2>*</font><font color=white>***</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#ababab>*</font><font color=white>**</font><font color=#e2e2e2>*</font><font color=#afafaf>*</font><font color=#acacac>*</font><font color=#"
		"f3f3f3>*</font><font color=white>*</font><font color=#f5f5f5>*</font><font color=#787878>*</font><font color=#0a0a0a>*</font><font color=#313131>*</font><font color=#cecece>*</font><font color=white>*</font><font color=#c4c4c4>*</font><font color=#272727>*</font><font color=#0c0c0c>*</font><font color=#949494>*</font><font color=#fafafa>*</font><font color=#f8f8f8>*</font><font color=#7c7c7c>*</font><font color=#5b5b5b>*</font><font color=#c3c3c3>*****</font><font color=#c2c2c2>*</font><font color=#959595>*</font><font color=#696969>*</font><font color=#6b6b6b>*</font><font color=#010101>*</font><font color=#525252>*</font><font color=white>**</font><font color=#bababa>*</font><font color=#070707>*</font><font color=black>*</font><font color=#474747>*</font><font color=#979797>*</font><font color=#9e9e9e>***</font><font color=#989898>*</font><font color=#070707>*</font><font color=#a9a9a9>*</font><font color=#fefefe>*</font><font color=white>*</font><font color=#2e2e2e>*</font><font color=#6a6a6a>*</"
		"font><font color=white>**</font><font color=#909090>*</font><font color=black>*******</font><font color=#484848>*</font><font color=white>***</font><font color=#bdbdbd>*</font><font color=#8e8e8e>*</font><font color=#6f6f6f>*</font><font color=#9a9a9a>*</font><font color=#fefefe>*</font><font color=white>*</font><font color=#e0e0e0>*</font><font color=#313131>*</font><font color=black>**********</font><br><font color=black>******</font><font color=#080808>*</font><font color=#232323>*</font><font color=#414141>*</font><font color=#696969>*</font><font color=#8d8d8d>*</font><font color=#ababab>*</font><font color=#c2c2c2>*</font><font color=#d7d7d7>*</font><font color=#e8e8e8>*</font><font color=#f7f7f7>*</font><font color=white>*****</font><font color=#f7f7f7>*</font><font color=#e2e2e2>*</font><font color=#cdcdcd>*</font><font color=#bababa>*</font><font color=#a4a4a4>*</font><font color=#8a8a8a>*</font><font color=#6a6a6a>*</font><font color=#454545>*</font><font color=#272727>*</font><font color=#0b0b0b>*"
		"</font><font color=black>****************</font><font color=#1d1d1d>*</font><font color=#b7b7b7>*</font><font color=#fefefe>*</font><font color=white>**</font><font color=#fefefe>*</font><font color=#ededed>*</font><font color=#d4d4d4>*</font><font color=#bdbdbd>*</font><font color=#bbbbbb>*</font><font color=white>****</font><font color=#585858>*</font><font color=black>**</font><font color=#5a5a5a>*</font><font color=white>***</font><font color=#686868>*</font><font color=black>*</font><font color=#030303>*</font><font color=#303030>*</font><font color=#acacac>*</font><font color=white>**</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#a9a9a9>*</font><font color=white>**</font><font color=#e9e9e9>*</font><font color=#1a1a1a>*</font><font color=#232323>*</font><font color=#383838>*</font><font color=#b5b5b5>*</font><font color=white>*</font><font color=#fefefe>*</font><font color=#b9b9b9>*</font><font color=#1f1f1f>*</font><font color=#151515>*</"
		"font><font color=#acacac>*</font><font color=white>*</font><font color=#e3e3e3>*</font><font color=#3c3c3c>*</font><font color=#030303>*</font><font color=#a5a5a5>*</font><font color=white>*</font><font color=#fefefe>*</font><font color=#959595>*</font><font color=#797979>*</font><font color=#7a7a7a>**</font><font color=#7c7c7c>*</font><font color=#7d7d7d>*</font><font color=#7e7e7e>*</font><font color=#b5b5b5>*</font><font color=#eeeeee>*</font><font color=#cbcbcb>*</font><font color=black>*</font><font color=#313131>*</font><font color=white>**</font><font color=#f9f9f9>*</font><font color=#525252>*</font><font color=#464646>*</font><font color=#494949>*</font><font color=#8d8d8d>*</font><font color=#c8c8c8>*</font><font color=#f7f7f7>*</font><font color=white>*</font><font color=#f8f8f8>*</font><font color=#111111>*</font><font color=#d4d4d4>*</font><font color=white>**</font><font color=#464646>*</font><font color=#636363>*</font><font color=white>**</font><font color=#c2c2c2>*</font><font color=#6c6c6c>*"
		"</font><font color=#696969>*</font><font color=#676767>*</font><font color=#656565>*</font><font color=#636363>*</font><font color=#5f5f5f>*</font><font color=#070707>*</font><font color=#3b3b3b>*</font><font color=white>****</font><font color=#cacaca>*</font><font color=#c1c1c1>*</font><font color=#dbdbdb>*</font><font color=#f5f5f5>*</font><font color=white>**</font><font color=#e4e4e4>*</font><font color=#3a3a3a>*</font><font color=black>*********</font><br><font color=black>*******</font><font color=#010101>*</font><font color=#060606>*</font><font color=#0d0d0d>*</font><font color=#121212>*</font><font color=#1f1f1f>*</font><font color=#343434>*</font><font color=#484848>*</font><font color=#595959>*</font><font color=#707070>*</font><font color=#f8f8f8>*</font><font color=white>****</font><font color=#8e8e8e>*</font><font color=#454545>*</font><font color=#373737>*</font><font color=#242424>*</font><font color=#161616>*</font><font color=#0f0f0f>*</font><font color=#090909>*</font><font color=#030303>*"
		"</font><font color=black>****************</font><font color=#010101>*</font><font color=#424242>*</font><font color=#e1e1e1>*</font><font color=white>***</font><font color=#d1d1d1>*</font><font color=#373737>*</font><font color=#0e0e0e>*</font><font color=#090909>*</font><font color=#050505>*</font><font color=#5a5a5a>*</font><font color=white>****</font><font color=#5d5d5d>*</font><font color=#040404>*</font><font color=black>*</font><font color=#535353>*</font><font color=#f9f9f9>*</font><font color=white>**</font><font color=#b2b2b2>*</font><font color=#2d2d2d>*</font><font color=#010101>*</font><font color=black>*</font><font color=#575757>*</font><font color=white>**</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#a6a6a6>*</font><font color=white>**</font><font color=#e5e5e5>*</font><font color=#030303>*</font><font color=black>**</font><font color=#080808>*</font><font color=#e2e2e2>*</font><font color=white>**</font><font color=#5d5d5d>*</font><font "
		"color=black>*</font><font color=#4f4f4f>*</font><font color=white>**</font><font color=#999999>*</font><font color=#111111>*</font><font color=#616161>*</font><font color=#9d9d9d>**</font><font color=#9c9c9c>*****</font><font color=#9b9b9b>**</font><font color=#9a9a9a>*</font><font color=#8c8c8c>*</font><font color=#5f5f5f>*</font><font color=black>*</font><font color=#4a4a4a>*</font><font color=#f1f1f1>***</font><font color=#eeeeee>*</font><font color=#ededed>****</font><font color=#f1f1f1>*</font><font color=#f2f2f2>*</font><font color=#efefef>*</font><font color=#191919>*</font><font color=#b3b3b3>*</font><font color=#eeeeee>*</font><font color=#efefef>*</font><font color=#585858>*</font><font color=#565656>*</font><font color=#f0f0f0>******</font><font color=#f1f1f1>**</font><font color=#ececec>*</font><font color=#141414>*</font><font color=#3d3d3d>*</font><font color=white>****</font><font color=#7d7d7d>*</font><font color=#050505>*</font><font color=#0a0a0a>*</font><font color=#181818>*</font><font "
		"color=#b8b8b8>*</font><font color=#fefefe>*</font><font color=white>*</font><font color=#ededed>*</font><font color=#464646>*</font><font color=black>********</font><br><font color=black>****</font><font color=#0f0f0f>*</font><font color=#3d3d3d>*</font><font color=#737373>*</font><font color=#a1a1a1>*</font><font color=#c1c1c1>*</font><font color=#dbdbdb>*</font><font color=#f0f0f0>*</font><font color=#fdfdfd>*</font><font color=white>************</font><font color=#fefefe>*</font><font color=#f6f6f6>*</font><font color=#e4e4e4>*</font><font color=#cdcdcd>*</font><font color=#b1b1b1>*</font><font color=#888888>*</font><font color=#525252>*</font><font color=#202020>*</font><font color=#010101>*</font><font color=black>***********</font><font color=#070707>*</font><font color=#767676>*</font><font color=#f6f6f6>*</font><font color=white>**</font><font color=#fafafa>*</font><font color=#9a9a9a>*</font><font color=#111111>*</font><font color=black>****</font><font color=#585858>*</font><font color=#e4e4e4>*</"
		"font><font color=white>***</font><font color=#f5f5f5>*</font><font color=#adadad>*</font><font color=#4e4e4e>*</font><font color=#0f0f0f>*</font><font color=#424242>*</font><font color=#a3a3a3>*</font><font color=#cacaca>*</font><font color=#8c8c8c>*</font><font color=#424242>*</font><font color=#020202>*</font><font color=black>*</font><font color=#575757>*</font><font color=white>**</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#a4a4a4>*</font><font color=white>**</font><font color=#e1e1e1>*</font><font color=#020202>*</font><font color=black>**</font><font color=#040404>*</font><font color=#dedede>*</font><font color=#f6f6f6>**</font><font color=#444444>*</font><font color=black>*</font><font color=#3c3c3c>*</font><font color=#f0f0f0>**</font><font color=#eaeaea>*</font><font color=#dfdfdf>*</font><font color=#dedede>*</font><font color=#dddddd>**</font><font color=#dcdcdc>***</font><font color=#dbdbdb>**</font><font color=#e5e5e5>**</font><font color=#"
		"d9d9d9>*</font><font color=#030303>*</font><font color=black>**</font><font color=#0b0b0b>*</font><font color=#1e1e1e>*</font><font color=#1f1f1f>**</font><font color=#202020>**</font><font color=#212121>**</font><font color=#222222>**</font><font color=#232323>**</font><font color=#040404>*</font><font color=#0d0d0d>*</font><font color=#141414>*</font><font color=#171717>*</font><font color=#0b0b0b>*</font><font color=#090909>*</font><font color=#1a1a1a>**</font><font color=#1b1b1b>*</font><font color=#1c1c1c>**</font><font color=#1d1d1d>**</font><font color=#232323>*</font><font color=#5c5c5c>*</font><font color=#9e9e9e>*</font><font color=#ececec>*</font><font color=white>***</font><font color=#ededed>*</font><font color=#767676>*</font><font color=black>***</font><font color=#0c0c0c>*</font><font color=#a7a7a7>*</font><font color=#fefefe>*</font><font color=white>*</font><font color=#f2f2f2>*</font><font color=#545454>*</font><font color=black>*******</font><br><font color=black>***</font><font color=#"
		"5e5e5e>*</font><font color=#d6d6d6>*</font><font color=#fafafa>*</font><font color=white>*****</font><font color=#e9e9e9>*</font><font color=#bcbcbc>*</font><font color=#9a9a9a>*</font><font color=#818181>*</font><font color=#6f6f6f>*</font><font color=#636363>*</font><font color=#5d5d5d>*</font><font color=#5b5b5b>*</font><font color=#5f5f5f>*</font><font color=#686868>*</font><font color=#777777>*</font><font color=#8b8b8b>*</font><font color=#a7a7a7>*</font><font color=#cbcbcb>*</font><font color=#f5f5f5>*</font><font color=white>****</font><font color=#fefefe>*</font><font color=#e8e8e8>*</font><font color=#9e9e9e>*</font><font color=#141414>*</font><font color=black>*********</font><font color=#141414>*</font><font color=#a9a9a9>*</font><font color=#fdfdfd>*</font><font color=white>**</font><font color=#eeeeee>*</font><font color=#5d5d5d>*</font><font color=#040404>*</font><font color=black>*****</font><font color=#010101>*</font><font color=#1b1b1b>*</font><font color=#626262>*</font><font "
		"color=silver>*</font><font color=#fdfdfd>*</font><font color=#f3f3f3>*</font><font color=#b3b3b3>*</font><font color=#646464>*</font><font color=#0a0a0a>*</font><font color=black>*</font><font color=#010101>*</font><font color=#080808>*</font><font color=black>****</font><font color=#353535>*</font><font color=#bababa>*</font><font color=#e7e7e7>*</font><font color=#f8f8f8>*</font><font color=#121212>*</font><font color=black>*</font><font color=#a2a2a2>*</font><font color=white>**</font><font color=#f4f4f4>*</font><font color=#929292>*</font><font color=#363636>*</font><font color=black>*</font><font color=#010101>*</font><font color=#262626>*</font><font color=#2a2a2a>**</font><font color=#0a0a0a>*</font><font color=black>*</font><font color=#080808>*</font><font color=#242424>*</font><font color=#252525>****</font><font color=#262626>*****</font><font color=#272727>**</font><font color=#565656>*</font><font color=#aaaaaa>*</font><font color=#e9e9e9>*</font><font color=#0b0b0b>*</font><font color=black>****"
		"***********************</font><font color=#060606>*</font><font color=#5a5a5a>*</font><font color=#aeaeae>*</font><font color=#efefef>*</font><font color=white>*</font><font color=#d2d2d2>*</font><font color=#757575>*</font><font color=#252525>*</font><font color=#020202>*</font><font color=black>****</font><font color=#0a0a0a>*</font><font color=#9b9b9b>*</font><font color=white>**</font><font color=#f3f3f3>*</font><font color=#5e5e5e>*</font><font color=black>******</font><br><font color=black>**</font><font color=#040404>*</font><font color=#dbdbdb>*</font><font color=white>*****</font><font color=#f9f9f9>*</font><font color=#525252>*</font><font color=#0a0a0a>*</font><font color=#030303>*</font><font color=black>**********</font><font color=#010101>*</font><font color=#050505>*</font><font color=#131313>*</font><font color=#747474>*</font><font color=#fefefe>*</font><font color=white>*****</font><font color=#6d6d6d>*</font><font color=black>*******</font><font color=#010101>*</font><font color=#363636>*</"
		"font><font color=#d8d8d8>*</font><font color=white>***</font><font color=#d7d7d7>*</font><font color=#2a2a2a>*</font><font color=black>**********</font><font color=#040404>*</font><font color=#252525>*</font><font color=#121212>*</font><font color=#030303>*</font><font color=black>**********</font><font color=#030303>*</font><font color=#090909>*</font><font color=#242424>*</font><font color=#040404>*</font><font color=black>*</font><font color=#282828>*</font><font color=#6b6b6b>*</font><font color=#9e9e9e>*</font><font color=#d2d2d2>*</font><font color=#ededed>*</font><font color=#828282>*</font><font color=black>*********************</font><font color=#020202>*</font><font color=#101010>*</font><font color=#030303>*</font><font color=black>*****************************</font><font color=#020202>*</font><font color=#0f0f0f>*</font><font color=#2d2d2d>*</font><font color=#060606>*</font><font color=black>********</font><font color=#040404>*</font><font color=#8d8d8d>*</font><font color=#fefefe>*</font><font "
		"color=white>*</font><font color=#fafafa>*</font><font color=#6d6d6d>*</font><font color=#030303>*</font><font color=black>****</font><br><font color=black>***</font><font color=#373737>*</font><font color=#c1c1c1>*</font><font color=#fafafa>*</font><font color=white>***</font><font color=#fcfcfc>*</font><font color=#747474>*</font><font color=#0f0f0f>*</font><font color=black>*************</font><font color=#111111>*</font><font color=#7e7e7e>*</font><font color=#fefefe>*</font><font color=white>***</font><font color=#f6f6f6>*</font><font color=#a3a3a3>*</font><font color=#131313>*</font><font color=black>******</font><font color=#040404>*</font><font color=#676767>*</font><font color=#f0f0f0>*</font><font color=white>****</font><font color=#f3f3f3>*</font><font color=#acacac>*</font><font color=#4a4a4a>*</font><font color=#040404>*</font><font color=black>******************************</font><font color=#010101>*</font><font color=#1b1b1b>*</font><font color=#222222>*</font><font color=black>****************"
		"************************************************</font><font color=#070707>*</font><font color=#555555>*</font><font color=#b1b1b1>*</font><font color=#fdfdfd>*</font><font color=white>**</font><font color=#fbfbfb>*</font><font color=#7b7b7b>*</font><font color=#030303>*</font><font color=black>***</font><br><font color=black>****</font><font color=#090909>*</font><font color=#3d3d3d>*</font><font color=#909090>*</font><font color=#d7d7d7>*</font><font color=#fdfdfd>*</font><font color=white>*</font><font color=#fdfdfd>*</font><font color=#d6d6d6>*</font><font color=#828282>*</font><font color=#2e2e2e>*</font><font color=#020202>*</font><font color=black>*******</font><font color=#030303>*</font><font color=#343434>*</font><font color=#868686>*</font><font color=#d8d8d8>*</font><font color=#fdfdfd>*</font><font color=white>*</font><font color=#fefefe>*</font><font color=#d9d9d9>*</font><font color=#8b8b8b>*</font><font color=#343434>*</font><font color=#040404>*</font><font color=black>******</font><font "
		"color=#0b0b0b>*</font><font color=#9a9a9a>*</font><font color=#fafafa>*</font><font color=white>***</font><font color=#fefefe>*</font><font color=#dfdfdf>*</font><font color=#a6a6a6>*</font><font color=#6a6a6a>*</font><font color=#2f2f2f>*</font><font color=#020202>*</font><font color=black>*************************************************************************************************</font><font color=#040404>*</font><font color=#414141>*</font><font color=#919191>*</font><font color=#dddddd>*</font><font color=white>***</font><font color=#fcfcfc>*</font><font color=#878787>*</font><font color=#030303>*</font><font color=black>**</font><br><font color=black>**</font><font color=#5f5f5f>*</font><font color=#858585>****</font><font color=#898989>*</font><font color=#a0a0a0>*</font><font color=#d3d3d3>*</font><font color=#fbfbfb>*</font><font color=white>**</font><font color=#fcfcfc>*</font><font color=#dedede>*</font><font color=#5c5c5c>*</font><font color=black>*****</font><font color=#666666>*</font><font "
		"color=#e4e4e4>*</font><font color=#fcfcfc>*</font><font color=white>**</font><font color=#f9f9f9>*</font><font color=#c9c9c9>*</font><font color=#898989>*</font><font color=#676767>*</font><font color=#626262>*</font><font color=#606060>*</font><font color=#5f5f5f>*</font><font color=#5d5d5d>*</font><font color=#313131>*</font><font color=black>***</font><font color=#2c2c2c>*</font><font color=#cdcdcd>*</font><font color=#fdfdfd>*</font><font color=#eeeeee>*</font><font color=#d2d2d2>*</font><font color=#999999>*</font><font color=#5d5d5d>*</font><font color=#212121>*</font><font color=#040404>*</font><font color=#010101>*</font><font color=black>*******************************************************************************************************</font><font color=#050505>*</font><font color=#333333>*</font><font color=#838383>*</font><font color=#cfcfcf>*</font><font color=#f3f3f3>*</font><font color=#fefefe>*</font><font color=#9a9a9a>*</font><font color=#080808>*</font><font color=black>*</"
		"font><br><font color=black>**</font><font color=#bcbcbc>*</font><font color=#f8f8f8>***</font><font color=#f7f7f7>*</font><font color=#f6f6f6>***</font><font color=#f5f5f5>**</font><font color=#f4f4f4>**</font><font color=#f3f3f3>*</font><font color=#8f8f8f>*</font><font color=black>*****</font><font color=#878787>*</font><font color=#ececec>*</font><font color=#ededed>*</font><font color=#eeeeee>*</font><font color=#f0f0f0>*</font><font color=#f1f1f1>*</font><font color=#f3f3f3>*</font><font color=#f4f4f4>*</font><font color=#f6f6f6>*</font><font color=#f7f7f7>*</font><font color=#f9f9f9>*</font><font color=#fafafa>*</font><font color=#fbfbfb>*</font><font color=#8a8a8a>*</font><font color=black>*</font><font color=#010101>*</font><font color=#424242>*</font><font color=#ababab>*</font><font color=#8c8c8c>*</font><font color=#515151>*</font><font color=#242424>*</font><font color=#040404>*</font><font color=black>************************************************************************************************"
		"***************</font><font color=#040404>*</font><font color=#313131>*</font><font color=#767676>*</font><font color=#bfbfbf>*</font><font color=#979797>*</font><font color=#0c0c0c>*</font><br><font color=black>**</font><font color=#1a1a1a>*</font><font color=#232323>*</font><font color=#222222>***</font><font color=#212121>****</font><font color=#202020>****</font><font color=#121212>*</font><font color=black>*****</font><font color=#0f0f0f>*</font><font color=#1c1c1c>**</font><font color=#1d1d1d>*</font><font color=#1e1e1e>*</font><font color=#1f1f1f>**</font><font color=#202020>*</font><font color=#212121>*</font><font color=#222222>*</font><font color=#232323>*</font><font color=#242424>*</font><font color=#252525>*</font><font color=#151515>*</font><font color=black>*</font><font color=#010101>*</font><font color=#131313>*</font><font color=#060606>*</font><font color=black>**********************************************************************************************************************</font><font "
		"color=#070707>*</font><font color=#232323>*</font><font color=#202020>*</font><br>"
		"</font></center>"
		
		"<center><font color=white>"
		"AnallogicA V 1.5 09052013 - Henry Suarez (skilltik) - skilltik@gmail.com</font></center>"
		"</body></html>"));
}
