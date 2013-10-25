#include "sentencia.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include    <cstdlib>
#include    <ctime>
#include    <sys/timeb.h>
using namespace std;
//
sentencia::sentencia(string Sentee) {
	version="AnallogicA 1.5";
	Sente_recivida=Sentee;//almaceno la sentencia
	Sente=Sentee;/*guardo la sentencia */
	longi=Sente.size();//calculo la longitud
	longi_p=longi;//calculo la longitud
	cantidad_renombrado=0;//pongo en cero el contador de renombrados
	letra=65;//variable para renombrado, inicializada en 'A'
	supera_abc=false;//controla letras para reemplazar
	hecho=false;//bandera para saber si ya se analizo
	
}
sentencia::sentencia(){
}

void sentencia::hace(string Sentee){	
	Sente_recivida=Sentee;//almaceno la sentencia
	Sente=Sentee;/*guardo la sentencia */
	longi=Sente.size();//calculo la longitud
	longi_p=longi;//calculo la longitud
	cantidad_renombrado=0;//pongo en cero el contador de renombrados
	letra=65;//variable para renombrado, inicializada en 'A'
	supera_abc=false;
	hecho=false;//bandera para saber si ya se analizo
}
	
sentencia::~sentencia() {
}

string sentencia::devolver(){
	return Sente;
}

bool sentencia::actualiza_sente(string &sent){
	if (cantidad_renombrado==0){//si nunca se renombro se toma la sentencia de llegada
		sent=Sente;
	}else{
		sent=Sente_mod[cantidad_renombrado-1];//si se renombro alguna vez se toma la ultima modificacion
	}
	return true;
}

bool sentencia::pariente(int &posi){
	bool flag=false;//bandera para el control del while
	bool flag2=false;//bandera para devolver si se puede realizar la accion
	int var=0;
	string sentence;
	actualiza_sente(sentence);
	while(flag==false){
		if (sentence[var]=='('){
			if (((sentence[var+1]>=97)&&(sentence[var+1]<=122))||((sentence[var+1]>=65)&&(sentence[var+1]<=90))){
				if ((sentence[var+2]=='.')||(sentence[var+2]=='|')||(sentence[var+2]=='>')||(sentence[var+2]=='%')||(sentence[var+2]=='@')||(sentence[var+2]=='#')||(sentence[var+2]=='?')){
					if (((sentence[var+3]>=97)&&(sentence[var+3]<=122))||((sentence[var+3]>=65)&&(sentence[var+3]<=90))){
						if (sentence[var+4]==')'){
							flag=true;
							flag2=true;
							posi=var;
						}
					}
				}
			}
		}
		var++;
		if((var==longi)||(longi<=4)){
			flag=true;
		}
	}
	return flag2;
}
bool sentencia::simple(int &posi, char operad){
	bool flag=false;//bandera para el control del while
	bool flag2=false;//bandera para devolver si se puede realizar la accion
	int var=-1;
	string sentence;
	actualiza_sente(sentence);
	while(flag==false){
		if ((sentence[var]!='(')||(sentence[var+4]!=')')){
			if (((sentence[var+1]>=97)&&(sentence[var+1]<=122))||((sentence[var+1]>=65)&&(sentence[var+1]<=90))){
				if (sentence[var+2]==operad){
					if (((sentence[var+3]>=97)&&(sentence[var+3]<=122))||((sentence[var+3]>=65)&&(sentence[var+3]<=90))){
						flag=true;
						flag2=true;
						posi=var;
						posi++;
					}
				}
			}
		}
		var++;
		if((var==longi)||(longi<=4)){
			flag=true;
		}
	}
	return flag2;
}

bool sentencia::simplex(int &posi, char operad){
	bool flag=false;//bandera para el control del while
	bool flag2=false;//bandera para devolver si se puede realizar la accion
	int var=-1;
	string sentence;
	actualiza_sente(sentence);
	while(flag==false){
//		if ((sentence[var]!='(')||(sentence[var+4]!=')')){
			if (((sentence[var+1]>=97)&&(sentence[var+1]<=122))||((sentence[var+1]>=65)&&(sentence[var+1]<=90))){
				if (sentence[var+2]==operad){
					if (((sentence[var+3]>=97)&&(sentence[var+3]<=122))||((sentence[var+3]>=65)&&(sentence[var+3]<=90))){
						flag=true;
						flag2=true;
						posi=var;
						posi++;
					}
				}
			}
//		}
		var++;
		if((var==longi)||(longi<=4)){
			flag=true;
		}
	}
	return flag2;
}



bool sentencia::renombra(int posi, int cantidad_reemplazar){
	string sentence;
	actualiza_sente(sentence);//actualizo a la ultima modificacion
	tabla_renombrado[cantidad_renombrado][0]=sentence.substr(posi,cantidad_reemplazar);//saco el parentesis simple
	tabla_renombrado[cantidad_renombrado][1]=letra;//lo nombro con un numero
	if (cantidad_renombrado==0){//pregunto si ya se renombo alguna vez
		Sente_mod[cantidad_renombrado]=Sente; //si nunca se renombro se usa la proposicion original
	}else{
		Sente_mod[cantidad_renombrado]=Sente_mod[cantidad_renombrado-1];//sino se usa la ultima
	}
	Sente_mod[cantidad_renombrado].replace(posi,cantidad_reemplazar,tabla_renombrado[cantidad_renombrado][1]);//agrego a arreglo de modificaciones
	sentence=Sente_mod[cantidad_renombrado];
	cantidad_renombrado++;
	letra++;//aumento variable para renombrar
	longi=longi-cantidad_reemplazar+1;//calcula de nuevo la longitud en base a lo reemplazado
	if ((letra==91)&&(longi!=1)){supera_abc=true;}//verifica que existan variables disponibles para renombrar
	return true;
}

bool sentencia::res_by_op(){
	string sentence;
	actualiza_sente(sentence);
	char arr_op[7]={'.','#','|','?','@','>','%'};
	rm_par_in();//elimino parentesis innecesarios
	negacion();// reemplazo negaciones
	rm_par_in();//elimino parentesis innecesarios
	actualiza_sente(sentence);
	
	while (longi>1){
		sigue:
		bool corta=false;
		int i=0;
		while(i<7){
			if (supera_abc==true){	//
				longi=1;			//Verifica que no se hayan acabado las variables para renombrar
				return true;		//
			}
			int posi2=0;
			while((simplex(posi2,arr_op[i]))==true/*||(corta==false)*/){//cada vez que se realiza alguna accion se comienza de nuevo
				if (supera_abc==true){ 	//
					longi=1;			//Verifica que no se hayan acabado las variables para renombrar
					return true;		//
				}
				posi2=0;
				if (simple(posi2,arr_op[i])){//verifico si hay operaciones fuera de parentesis simples
					renombra(posi2,3);
					actualiza_sente(sentence);
					corta=true;
					goto sigue;
					
				}
				int posi=0;
				while(pariente(posi)){// reemplazo parentesis simples
					renombra(posi,5);
					actualiza_sente(sentence);
					corta=true;
					goto sigue;
					
				}
				if (negacion()==true){// reemplazo negaciones
					actualiza_sente(sentence);
					corta=true;
					goto sigue;
					
				}
				if (rm_par_in()==true){//elimino parentesis innecesarios
					actualiza_sente(sentence);
					corta=true;
					goto sigue;
					
				}
			}
			negacion();
			rm_par_in();
			i++;
		}
	}
	return true;
	
}

bool sentencia::negacion(){
	string sentence;
	actualiza_sente(sentence);
	cantidad_negadores=0;//contador de operadores de negacion
	for (int i=0;i<longi;i++){
		if(sentence[i]=='-'){
			cantidad_negadores++;
		}
	}
	int aux=cantidad_negadores;
	bool flag=true;
	for (int a=0;a<aux;a++){
		actualiza_sente(sentence);
		int i=0;
		flag=true;
		while ((i<longi)&&(flag==true)){
			if (((sentence[i]=='-')&&(sentence[i+1]>=97)&&(sentence[i+1]<=122))||((sentence[i]=='-')&&(sentence[i+1]>=65)&&(sentence[i+1]<=90))){
				renombra(i,2);
				cantidad_negadores--;
				flag=false;
			}
			i++;
		}
		rm_par_in();
	}
	return true;
}

bool sentencia::inicia_atomos(){
	for (int i=0;i<longi;i++){
		if ((Sente[i]>=97)&&(Sente[i]<=122)){
			bool flag=false;
			for (unsigned int j=0;j<atomos.size();j++){//busca si ya existe
				if(atomos[j]==Sente[i]){
					flag=true;
				}
			}
			if ((flag==false)||(atomos.size()==0)){atomos.push_back(Sente[i]);}//si no existe lo agrega
		}
	}
	cantidad_atomos_int=atomos.size();
	return true;
}

bool sentencia::crear_matriz(){
	
	comb=pow(2,cantidad_atomos_int);//calcula cantidad de combinaciones
	
	tabla_logica=new string*[comb+1];		//
	for (int i=0;i<comb+1;i++)				// crea matriz dinamica para la tabla logica
		tabla_logica[i]=new string[55];	//
	
	
	for (int i=0;i!=cantidad_atomos_int;i++){	//
		tabla_logica[0][i]=atomos[i];			//llena primera fila con atomos
	}
	
	int conta=0;
	for (int i=cantidad_atomos_int;i<(cantidad_renombrado+cantidad_atomos_int);i++){	//
		tabla_logica[0][i]=tabla_renombrado[conta][1];									//llena primera fila con moleculas
		conta++;																		//
	}
	
	total_renombrado=cantidad_renombrado+cantidad_atomos_int; //calcula cantidad recombrado en total
	
	int aux2;										// crea combinaciones de V y F 
	aux2=cantidad_atomos_int;						//
	int aux4;										//
	int aux3=1;										//
	for (int j=aux2-1;j!=-1;j--){					//
		aux3=aux3*2;								//
		aux4=1;										//
		for (int q=0;q<(comb/aux3);q++){			//
			for (int h=0;h<aux3/2;h++){				//
				tabla_logica[aux4][j]="V";			//
				aux4++;								//
			}										//
			for (int h=0;h<aux3/2;h++){				//
				tabla_logica[aux4][j]="F";			//
				aux4++;								//
			}
		}
	}
	return true;
}

bool sentencia::analiza_moleculas(){
	string lee_molecula;
	string letra,letra2,simbolo;
	for (int i=0;i<cantidad_renombrado;i++){
		lee_molecula=tabla_renombrado[i][0];
		int h=0;
		if (lee_molecula.size()==2){
			letra=lee_molecula.substr(1,1);
			while (tabla_logica[0][h]!=letra){
				h++;
			}
			for (int b=1;b<comb+1;b++){
				if (tabla_logica[b][h]=="V"){
					tabla_logica[b][i+cantidad_atomos_int]="F";
				}else{
					tabla_logica[b][i+cantidad_atomos_int]="V";
				}
			}
		}else{
			if(lee_molecula.find(".",0)!=string::npos){
				h=lee_molecula.find(".",0);
			}else{
				if(lee_molecula.find("#",0)!=string::npos){
					h=lee_molecula.find("#",0);
				}else{
					if(lee_molecula.find("|",0)!=string::npos){
						h=lee_molecula.find("|",0);
					}else{
						if(lee_molecula.find("?",0)!=string::npos){
							h=lee_molecula.find("?",0);
						}else{
							if(lee_molecula.find("@",0)!=string::npos){
								h=lee_molecula.find("@",0);
							}else{
								if(lee_molecula.find(">",0)!=string::npos){
									h=lee_molecula.find(">",0);
								}else{
									if(lee_molecula.find("%",0)!=string::npos){
										h=lee_molecula.find("%",0);
									}
								}
							}
						}	
					}
				}	
			}
			letra=lee_molecula[h-1];
			letra2=lee_molecula[h+1];
			simbolo=lee_molecula[h];
			int conta_letra=0;
			while (tabla_logica[0][conta_letra]!=letra){
				conta_letra++;
			}
			int conta_letra2=0;
			while (tabla_logica[0][conta_letra2]!=letra2){
				conta_letra2++;
			}
			int selector;
			if (simbolo=="."){selector=1;}
			if (simbolo=="#"){selector=2;}
			if (simbolo=="|"){selector=3;}
			if (simbolo=="?"){selector=4;}
			if (simbolo=="@"){selector=5;}
			if (simbolo==">"){selector=6;}
			if (simbolo=="%"){selector=7;}
			for (int b=1;b<comb+1;b++){
				switch (selector){
				case 1:
					if ((tabla_logica[b][conta_letra]=="V")&&(tabla_logica[b][conta_letra2]=="V")){
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}
					break;
				case 2:
					if ((tabla_logica[b][conta_letra]=="F")&&(tabla_logica[b][conta_letra2]=="F")){
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}	
					break;
				case 3:
					if ((tabla_logica[b][conta_letra]=="F")&&(tabla_logica[b][conta_letra2]=="F")){
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}	
					break;
					
				case 4:
					if ((tabla_logica[b][conta_letra]=="V")&&(tabla_logica[b][conta_letra2]=="V")){
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}
					break;	
					
				case 5:
					if (tabla_logica[b][conta_letra]!=tabla_logica[b][conta_letra2]){
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}	
					break;
				case 6:
					if ((tabla_logica[b][conta_letra]=="V")&&(tabla_logica[b][conta_letra2]=="F")){
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}	
					break;
				case 7:
					if (tabla_logica[b][conta_letra]==tabla_logica[b][conta_letra2]){
						tabla_logica[b][i+cantidad_atomos_int]="V";
					}else{
						tabla_logica[b][i+cantidad_atomos_int]="F";
					}	
					break;
				}
			}
		}
	}
	return true;
}
bool sentencia::analiza_sintaxis(vector<string> &log){
	char carac,carac_d;
	int conta_var=0;
	for (int i=0;i<(longi_p);i++){
		carac=Sente[i];
		carac_d=Sente[i+1];
		char selector;
		if ((carac>=97)&&(carac<=122)){selector=0;}//letra
		if (carac=='('){selector=1;}
		if (carac==')'){selector=2;}
		if ((carac=='.')||(carac=='#')||(carac=='|')||(carac=='?')||(carac=='>')||(carac=='%')||(carac=='@')){selector=3;}//operador
		if (carac=='-'){selector=4;}
		switch(selector){
		case 0:
			if ((carac_d>=97)&&(carac_d<=122)){log.push_back("variables seguidass { '"+Sente.substr(i,2)+"' }");}
			if (carac_d=='('){log.push_back("falta operador entre variables y parentesis { '"+Sente.substr(i,2)+"' }");}
			if (carac_d=='-'){log.push_back("operador unario fuera de rangoo { '"+Sente.substr(i,2)+"' }");}
			conta_var++;
			break;
		case 1:
			if (carac_d==')'){log.push_back("parentesis vacios {} '"+Sente.substr(i,2)+"' }");}
			break;
		case 2:
			if (carac_d=='('){log.push_back("operador faltante entre parentesis { '"+Sente.substr(i,2)+"' }");}
			if (carac_d=='-'){log.push_back("operador unario fuera de rango { '"+Sente.substr(i,2)+"' }");}
			if ((carac_d>=97)&&(carac_d<=122)){log.push_back("operador faltante entre parentesis y variable { '"+Sente.substr(i,2)+"' }");}
			break;	
		case 3:
			if ((carac_d=='.')||(carac_d=='#')||(carac_d=='|')||(carac_d=='?')||(carac_d=='>')||(carac_d=='%')||(carac_d=='@')){log.push_back("operadores dobles { '"+Sente.substr(i,2)+"' }");}
			if (carac_d==')'){log.push_back("falta variable entre operador y parentesis { '"+Sente.substr(i,2)+"' }");}
			if (i==0){log.push_back("faltan variables {} ");}
			if (i>0){
				char carac_i=Sente[i-1];
				if ((!((carac_i>=97)&&(carac_i<=122))==true)&&(carac_i!=')')){log.push_back("faltan variables {} ");}
			}
			if (!(Sente[i+1])){log.push_back("faltan variables {}");}
			break;
		case 4:
			if ((carac_d=='.')||(carac_d=='#')||(carac_d=='|')||(carac_d=='?')||(carac_d=='>')||(carac_d=='%')){log.push_back("negador y operador binario juntos { '"+Sente.substr(i,2)+"' }");}
			if (carac_d==')'){log.push_back("negador o parentesis juntos{ '"+Sente.substr(i,2)+"' }");}
			if (Sente.size()==1){log.push_back("faltan variables {...} ");}
			
			break;
		}	
	}
	if (Sente.size()==0){log.push_back("Introduzca una sentencia logica para analizar");}
	//controla negadores seguidos sin variables
	if (conta_var==0){
		log.push_back("faltan variables {} ");
	}
	if (log.size()!=0){
		return false;//si hay errores
	}else{
		return true;//si la sintaxis es correcta
	}
}

bool sentencia::rm_par_in(){
	if (cantidad_renombrado==0){
		while(comprueba_par()==true){
			for (int h=0;h<longi;h++){
				if ((Sente[h]=='(')&&(Sente[h+2]==')')){
					Sente.erase(h,1);
					Sente.erase(h+1,1);
					longi=longi-2;
				}
			}
		}
	}else{
		while(comprueba_par()==true){
			for (int h=0;h<longi;h++){
				if ((Sente_mod[cantidad_renombrado-1][h]=='(')&&(Sente_mod[cantidad_renombrado-1][h+2]==')')){
					Sente_mod[cantidad_renombrado-1].erase(h,1);
					Sente_mod[cantidad_renombrado-1].erase(h+1,1);
					longi=longi-2;
				}
			}
		}
	}
	return true;
}
bool sentencia::comprueba_par(){
	string sentence;
	actualiza_sente(sentence);
	bool retorno=false;
	for (int i=0;i<longi;i++){
		if ((sentence[i]=='(')&&(sentence[i+2]==')')){
			retorno=true;
		}
	}
	return retorno;
}
bool sentencia::traduce(string *lista_simbolos){
	for (int i=0;i<8;i++){
		lista_simbol[i]=lista_simbolos[i];
	}
	string frase;
	size_t posi;
	string simbolos_numeros[8]={"0","1","2","3","4","5","6","7"};
	string simbolos_anallogica[8]={".","#","|","?","@",">","%","-"};
	//reemplazo todos los simbolos menos las negaciones por numeros
	for (int i=0;i<7;i++){
		string aux=lista_simbolos[i];
		posi=Sente.find(aux);
		int control=0;
		while((posi!=string::npos)){
			if (((Sente[posi-1]>=97)&&(Sente[posi-1]<=122))||Sente[posi-1]==')'){
				if (((Sente[posi+lista_simbolos[i].length()]>=97)&&(Sente[posi+lista_simbolos[i].length()]<=122))||(Sente[posi+lista_simbolos[i].length()]=='(')||(Sente[posi+lista_simbolos[i].length()]==lista_simbolos[7][0])){
					Sente=Sente.replace(posi,aux.length(),simbolos_numeros[i]);
				}
			}
			control=posi+1;
			posi=Sente.find(aux,control);
		}
	}

	unsigned int s=0;
	string aux=lista_simbolos[7];
	while (s!=Sente.length()){
		string verifica=Sente.substr(s,aux.length());
		if (verifica==aux){
			Sente=Sente.replace(s,aux.length(),simbolos_numeros[7]);
		}
		s=s+aux.length();
	}
	
	//reemplazo los numeros por la simbologia interna del programa
	for (int i=0;i<8;i++){
		string aux=simbolos_numeros[i];
		posi=Sente.find(aux);
		while(posi!=string::npos){
			Sente=Sente.replace(posi,1,simbolos_anallogica[i]);
			posi=Sente.find(aux);
		}
	}
	Sente_original_traducida=Sente;
	longi_p=longi=Sente.length();
	return true;
}
bool sentencia::reporte(string dire, int wha){
	fstream reporte_out;
	if (wha==0){
		reporte_out.open(dire.c_str(), ios::app| ios::out);
		
	}
	if (wha==1){
		reporte_out.open(dire.c_str(), ios::out|ios::trunc);
	}
	if (reporte_out.good()==true){
		string dat;
		int anchos[100];
		for (int i=0;i<100;i++)//inicio el arreglo en espacio estandar de 2
			anchos[i]=2;
//		time_t tAct = time(NULL);//variable para la fecha y hora
//		dat=asctime(localtime(&tAct));
		int barra=0;
		barra=dire.find_last_of('/');
		version="AnallogicA 1.5";
		reporte_out<<version<<setfill('-')<<setw(45)<<"/"<<endl;
		reporte_out<<"Nombre de archivo: "<<dire.substr(barra+1)<<endl;
		reporte_out<<"Archivo creado: "<<dat;
		reporte_out<<setfill('-')<<setw(60)<<"/"<<endl;
		reporte_out<<"Sentencia logica: "<<Sente_recivida<<endl<<endl;
		for (int i=0;i<cantidad_renombrado;i++){//muestro el desarrolo del algoritmo y sus sutituciones
			reporte_out<<traduce_inver(Sente_mod[i])<<setfill(' ')<<setw(10)<<traduce_inver(tabla_renombrado[i][0])<<"<-->"<<traduce_inver(tabla_renombrado[i][1])<<endl;}
		reporte_out<<endl;
		reporte_out<<" ";
		
		for (int k=0;k<cantidad_atomos_int;k++){//muestro los atomos
			reporte_out<<tabla_logica[0][k]<<" | ";
		}
		for (int k=0;k<cantidad_renombrado;k++){//muestro las moleculas
			reporte_out<<traduce_inver(tabla_renombrado[k][0])<<" | ";
			anchos[k+cantidad_atomos_int]=((tabla_renombrado[k][0].size()+6)/2);
		}
		reporte_out<<endl;
		for (int k=1;k<comb+1;k++){//mostrar matriz
			for (int i=0;i<total_renombrado;i++){
				reporte_out<<setfill(' ')<<setw(anchos[i])<<tabla_logica[k][i]<<setw(anchos[i])<<"|";
			}
			if (k==0){
				reporte_out<<endl;
				for (int i=0;i<total_renombrado*3;i++){
					reporte_out<<"-";
				}
			}
			reporte_out<<endl;
		}
		reporte_out<<endl;
		reporte_out<<setfill('-')<<setw(60)<<"/"<<endl;
		reporte_out.close();
		return true;
	}else{
		return false;
	}	
}

string sentencia::limpiahtml(string linea){
	string::size_type  pos=0;
	for (int i=0;i<=linea.length();i++){
		for (char j=65;j<=65+cantidad_renombrado;j++){
			while (linea.find(j)<=linea.length()){
				pos=linea.find(j);
				if (pos<=linea.length()){
				linea.replace(pos,1,tabla_renombrado[j-65][0]);
				}
				pos = 0;
			}
		}
	}

	return linea;
}

bool sentencia::reportehtml(string dire, int wha){
	fstream reporte_out;
	reporte_out.open(dire.c_str(),ios::out);
	if (reporte_out.good()==true){reporte_out<<"<html>";
	reporte_out<<"<head>";
	reporte_out<<"<title></title>";
	reporte_out<<"</head>";
	reporte_out<<"<body>";
	reporte_out<<"<pre>";
		int aux[3];
		contador(aux);			
		int barra=0;
		barra=dire.find_last_of('/');
		reporte_out<<"Sentencia logica: "<<Sente_recivida<<endl;
		reporte_out<<"La proposicion logica es una "<<conclu()<<endl;
		reporte_out<<"Cantidad de operadores binarios: "<<aux[0]<<endl;
		reporte_out<<"Cantidad de operadores unarios: "<<aux[1]<<endl;
		reporte_out<<"Cantidad de variables logicas: "<<aux[2]<<endl;
		reporte_out<<"Cantidad de combinaciones: "<<comb<<endl;
		reporte_out<<"Tiempo empleado para calcular: "<<tiempodecalculo<<" milisegundos"<<endl;
		reporte_out<<"</pre>";
		reporte_out<<endl;
		reporte_out<<"<table border=\"0\" >";
		reporte_out<<"<tr align=\"center\" BGCOLOR=\"#6E6E6E\">";
		for (int k=0;k<cantidad_atomos_int;k++){//muestro los atomos
			reporte_out<<"<td>"<<tabla_logica[0][k]<<"</td>";
		}
		for (int k=0;k<cantidad_renombrado;k++){//muestro las moleculas
			reporte_out<<"<td>"<<traduce_inver(limpiahtml(tabla_renombrado[k][0]))<<"</td>";
			
		}
		reporte_out<<"</tr>";
		
		reporte_out<<endl;
		for (int k=1;((k<comb+1)&k<=8000);k++){//mostrar matriz
			reporte_out<<"<tr align=\"center\" >";
			
			for (int i=0;i<total_renombrado;i++){
				if (i%2==0){
					reporte_out<<"<td >"<<endl;
				}else{
					reporte_out<<"<td BGCOLOR=\"#BDBDBD\">"<<endl;
				}
				reporte_out<<tabla_logica[k][i]<<"</td>";
			}
			if (k<comb+1){
				reporte_out<<"</tr>";
				//reporte_out<<endl;
			}
			//reporte_out<<endl;
			
		}
		reporte_out<<"</table>";
		reporte_out<<"</body>";
		reporte_out<<"</html>";
		reporte_out<<endl;
		reporte_out.close();
		return true;

	reporte_out<<"</table>";
	reporte_out<<"</body>";
	reporte_out<<"</html>";
	reporte_out<<endl;
	reporte_out.close();
	
	}else{
		return false;
	}	
}

bool sentencia::indexhtml(string dire, int wha, vector<string> llega){
	fstream reporte_out;
	reporte_out.open(dire.c_str(),ios::out);
	
	
	if (reporte_out.good()==true){reporte_out<<"<html>";
		reporte_out<<"<head>";
		reporte_out<<"<title></title>";
		reporte_out<<"</head>";
		reporte_out<<"<body>";
		reporte_out<<"<pre>";
		if (wha==1){
			int aux[3];
			contador(aux);			
			int barra=0;
			barra=dire.find_last_of('/');
			reporte_out<<"Sentencia logica: "<<Sente_recivida<<endl;
			reporte_out<<"La proposicion logica es una "<<conclu()<<endl;
			reporte_out<<"Cantidad de operadores binarios: "<<aux[0]<<endl;
			reporte_out<<"Cantidad de operadores unarios: "<<aux[1]<<endl;
			reporte_out<<"Cantidad de variables logicas: "<<aux[2]<<endl;
			reporte_out<<"Cantidad de combinaciones: "<<comb<<endl;
			reporte_out<<"Tiempo empleado para calcular: "<<tiempodecalculo<<" milisegundos"<<endl;
			reporte_out<<"</pre>";
			reporte_out<<endl;
			reporte_out<<"<table border=\"0\" >";
			reporte_out<<"<tr align=\"center\" BGCOLOR=\"#6E6E6E\">";
			for (int k=0;k<cantidad_atomos_int;k++){//muestro los atomos
				reporte_out<<"<td>"<<tabla_logica[0][k]<<"</td>";
			}
			for (int k=0;k<cantidad_renombrado;k++){//muestro las moleculas
				reporte_out<<"<td>"<<traduce_inver(limpiahtml(tabla_renombrado[k][0]))<<"</td>";
				
			}
			reporte_out<<"</tr>";
			
			reporte_out<<endl;
			for (int k=1;((k<comb+1)&k<=8000);k++){//mostrar matriz
				reporte_out<<"<tr align=\"center\" >";
				
				for (int i=0;i<total_renombrado;i++){
					if (i%2==0){
						reporte_out<<"<td >"<<endl;
					}else{
						reporte_out<<"<td BGCOLOR=\"#BDBDBD\">"<<endl;
					}
					reporte_out<<tabla_logica[k][i]<<"</td>";
				}
				if (k<comb+1){
					reporte_out<<"</tr>";
					//reporte_out<<endl;
				}
				//reporte_out<<endl;
				
			}
			reporte_out<<"</table>";
			reporte_out<<"</body>";
			reporte_out<<"</html>";
			reporte_out<<endl;
			reporte_out.close();
			return true;
			}
		if (wha==0){
			reporte_out<<"Ocurrieron los siguientes errores al analizar:"<<endl;
			string aux;
			for (unsigned int i=0;i<llega.size();i++){
				aux=llega[i];
				reporte_out<<aux<<endl;
			}
			reporte_out<<"</pre>";
		}
		reporte_out<<"</table>";
		reporte_out<<"</body>";
		reporte_out<<"</html>";
		reporte_out<<endl;
		reporte_out.close();

	}else{
		return false;
	}	
	
	
}

bool sentencia::resuelve(string unocero){
	clock_t startC, finishC;
	struct timeb startT, finishT;       //
	unsigned int elements=100000;       //
	unsigned int operations=10000;      //variables para calcular tiempo de proceso
	unsigned int seconds, milliseconds; //
	startC = clock();                   //
	ftime(&startT);                     //
	rm_par_in();
	inicia_atomos();
	if (cantidad_atomos_int<=16){
		negacion();
		if (res_by_op()){
			crear_matriz();
			analiza_moleculas();
			hecho=true;
			if (unocero=="1"){
			unosyceros();
			}
			finishC = clock();
			ftime(&finishT);
			seconds = finishT.time - startT.time - 1;
			milliseconds = (1000 - startT.millitm) + finishT.millitm;
			tiempodecalculo= (milliseconds + seconds * 1000);
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
const sentencia &sentencia::operator=(const sentencia &sen){
	Sente_recivida=sen.Sente_recivida;
	Sente=sen.Sente;
	longi=sen.longi;
	longi_p=sen.longi_p;
	cantidad_renombrado=0;//pongo en cero el contador de renombrados
	letra=65;//variable para renombrado, inicializada en 'A'
	return *this;
}
string sentencia::conclu(){
	string conclu_str=(tabla_logica[1][cantidad_atomos_int+cantidad_renombrado-1]);
	string vv("1");
	string vvv("V");
	for (int i=2;i<=comb;i++){
		if (tabla_logica[i][cantidad_atomos_int+cantidad_renombrado-1]!=conclu_str){
			conclu_str="contingencia";
			return conclu_str;
		}
	}
	if ((conclu_str==vv)||(conclu_str==vvv)){
		conclu_str="tautologia";
		return conclu_str;
	}else{
		conclu_str="contradiccion";
		return conclu_str;
	}
}

bool sentencia::errores(string linea, vector<string> &log,string *lista_simbolos){
	
	//genere listado de caracteres permitidos
	string simb_per;
	for (int i=0;i<8;i++){
		simb_per+=lista_simbolos[i];
	}
	simb_per+="()";
	//
	
	bool letra=true;
	if (!(((Sente[0]>=97)&&(Sente[0]<=122))||Sente[0]==lista_simbolos[7][0]||Sente[0]=='(')){
		letra=false;
	}else{
	for (unsigned int g=0;g<Sente.length();g++){
//		if ((Sente[g]>=97)&&(Sente[g]<=122)){ //si es una letra
//			if (!(((Sente[g+1]==simb_per[0])||(Sente[g+1]==simb_per[1])||(Sente[g+1]==simb_per[2])||(Sente[g+1]==simb_per[3])||(Sente[g+1]==simb_per[4])||(Sente[g+1]==simb_per[5])||(Sente[g+1]==simb_per[6])||(Sente[g+1]==simb_per[7]))||(Sente[g+1]==')'))){
//				letra=false;
//			}
//		}else{
		if (Sente[g]=='('){
			if (!((Sente[g+1]=='(')||(Sente[g+1]==lista_simbolos[7][0])||((Sente[g+1]>=97)&&(Sente[g+1]<=122)))){
				letra=false;
				
			}
		}else{
		
			if (Sente[g]==lista_simbolos[7][0]){//si es un negador
				if (!(((Sente[g+1]>=97)&&(Sente[g+1]<=122))||Sente[g+1]=='('||(Sente[g+1]==lista_simbolos[7][0]))){
					letra=false;
					
					
				}
			}else{//si es simbolo
				if ((Sente[g]==simb_per[0])||(Sente[g]==simb_per[1])||(Sente[g]==simb_per[2])||(Sente[g]==simb_per[3])||(Sente[g]==simb_per[4])||(Sente[g]==simb_per[5])||(Sente[g]==simb_per[6])||(Sente[g]==simb_per[7])){
					if (!(((Sente[g+1]==simb_per[0])||(Sente[g+1]==simb_per[1])||(Sente[g+1]==simb_per[2])||(Sente[g+1]==simb_per[3])||(Sente[g+1]==simb_per[4])||(Sente[g+1]==simb_per[5])||(Sente[g+1]==simb_per[6])||(Sente[g+1]==simb_per[7]))||((Sente[g+1]>=97)&&(Sente[g+1]<=122))||
						Sente[g+1]==lista_simbolos[7][0]||Sente[g+1]=='(')){
							letra=false;
							
						}
				}
			}
		}
		
	}
}
	if (letra==false){
		log.push_back("Error de sintaxis, pueden faltar variables");
	}else{
		// filtro para ver que no pasen operadores internos
		string simbolos_anallogica[8]={".","#","|","?","@",">","%","-"};
		size_t posi=0;
		for (int i=0;i<8;i++){
			string aux=simbolos_anallogica[i];
			posi=Sente.find(aux);
			int control=0;
			while(posi!=string::npos){
				if (((Sente[posi-1]>=96)&&(Sente[posi-1]<=122))||(Sente[posi-1]==')')||((posi-1)==-1)){
					if (((Sente[posi+1]>=96)&&(Sente[posi+1]<=122))||(Sente[posi+1]=='(')||(Sente[posi+1]=='-')){
						bool flag=false;
						for (int j=0;j<8;j++){
							if (aux==lista_simbolos[j]){
								flag=true;
							}
						}
						if (flag==false){
							log.push_back("Operador desconocido o incompleto");
						}
					}
				}
				if ((aux=="-")&&(posi==0)){
					control+=1;
				}else{
					control+=posi;
				}
				
				posi=Sente.find(aux,control);
			}
		}
		
		int par_d=0;
		int par_i=0;
		for (unsigned int i=0;i<linea.size();i++){
			if (linea[i]=='('){par_d++;}
			if (linea[i]==')'){par_i++;}
		}
		if (par_d!=par_i){
			if (par_d>par_i){log.push_back("Falta cerrar un parentesis");}else{log.push_back("Falta abrir un parentesis");}
		}
		for (unsigned int i=0;i<linea.size();i++){
				if ((linea[i]>=48)&&(linea[i]<=57)){log.push_back("No estan permitidos los numeros { '"+Sente.substr(i,1)+"' }");}else{
					if ((linea[i]>=65)&&(linea[i]<=90)){log.push_back("No estan permitidos las mayusculas { '"+Sente.substr(i,1)+"' }");}else{
						/*if ((linea[i]!='-')&&(linea[i]!='(')&&(linea[i]!=')')&&((linea[i]<97)||(linea[i]>122))&&(linea[i]!='&')&&(linea[i]!='|')&&(linea[i]!='<')&&(linea[i]!='=')&&(linea[i]!='>')&&(linea[i]!='@')&&(linea[i]!='#')&&(linea[i]!='?')){log.push_back("No estan permitidos otros caracteres { '"+Sente.substr(i,1)+"' }");}*/
					}
				}
		}
		for (unsigned int i=0;i<linea.length();i++){
			bool flag=false;
			for (unsigned int j=0;j<simb_per.length();j++){
				if ((linea[i]>=97)&&(linea[i]<=122)){
					flag=true;
				}else{
					if (linea[i]==simb_per[j]){
						flag=true;
					}
				}
			}
			if (flag==false){log.push_back("Simbolo no valido{ "+Sente.substr(i,1)+" }");}
		}
		if (linea.size()==0){log.push_back("Introduzca una sentencia logica para analizar");}
	}
	if (log.size()>0){return true;}else{return false;}
}
string sentencia::num(int i){	//   int a string
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

bool sentencia::reporte_bina(string lugar){
	string aux="{"+Sente_recivida+"}";
	fstream reporte_out(lugar.c_str(), ios::out| ios::binary);
	if (reporte_out.good()==true){
		char tex;
		for (unsigned int i=0;i<aux.size();i++){
			tex=aux[i];
			reporte_out.write(&tex,sizeof(tex));
		}
		reporte_out.close();
		return true;
	}else{
		return false;
	}	
}
string sentencia::importa_binario(string lugar){
	fstream reporte_out(lugar.c_str(),ios::in| ios::binary);
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
		}
	}else{

	}
	return texo;
}

void sentencia::contador(int *aux){
	char simbolo;
	aux[0]=0;
	aux[1]=0;
	for (unsigned int i=0;i<Sente_original_traducida.size();i++){
		simbolo=Sente_original_traducida[i];
		if ((simbolo=='.')||(simbolo=='|')||(simbolo=='>')||(simbolo=='%')||(simbolo=='@')||(simbolo=='#')||(simbolo=='?')){aux[0]++;}
		if (simbolo=='-'){aux[1]++;}
	}
	aux[2]=cantidad_atomos_int;
}

string sentencia::traduce_inver(string var){
	int selector;
	unsigned int i=0;
	unsigned int tam=var.size();
	char simbolo;
	while (i<tam){
		simbolo=var[i];
		switch (simbolo){
		case '.':
			var.replace(i,1,lista_simbol[0]);
			break;
		case '|':
			var.replace(i,1,lista_simbol[2]);
			tam+=1;
			i+=1;
			break;
		case '@':
			var.replace(i,1,lista_simbol[4]);
			tam+=1;
			i+=1;
			break;
		case '#':
			var.replace(i,1,lista_simbol[1]);
			tam+=1;
			i+=1;
			break;
		case '>':
			var.replace(i,1,lista_simbol[5]);
			tam+=1;
			i+=1;
			break;		
		case '%':
			var.replace(i,1,lista_simbol[6]);
			tam+=2;
			i+=2;
			break;
		case '?':
			var.replace(i,1,lista_simbol[3]);
			tam+=2;
			i+=2;
			break;
		}
		selector=0;
		i++;
	}
	return var;
}
void sentencia::limpia(){
	//limpio
	longi_p=0;
	longi=0;
	Sente_recivida.clear();
	Sente.clear();
	Sente_mod->clear();
	Sente_original_traducida.clear();
	total_renombrado=0;
	comb=0;
	cantidad_atomos_int=0;
	cantidad_negadores=0;
	atomos.clear();
	supera_abc=false;
}
vector<char> sentencia::devuelve_atomos(){
	return atomos;
}

void sentencia::unosyceros(){
	for (int j=0;j<(cantidad_atomos_int+cantidad_renombrado);j++){
		for (int i=1;i<comb+1;i++){
			if (tabla_logica[i][j]=="V"){
				tabla_logica[i][j]="1";
			}else{
				tabla_logica[i][j]="0";
			}
		}
	}
}
