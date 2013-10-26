
#ifndef SENTENCIA_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#define SENTENCIA_H

class sentencia {
protected:
	string Sente_recivida;//Sentencia original
	string Sente_original_traducida;
	string Sente;//traducida a lenguaje del programa NO SE MODIFICA
	string Sente_mod[55];//arreglo de modificaciones de sentencia
	string tabla_renombrado[55][2]; //arreglo con las equivalencias de los renombrados de los parentesis simples
	string **tabla_logica;//tabla logica final
	int letra;//variable para renombrado
	int cantidad_renombrado; //cantidad de renombrados en el arreglo;
	int total_renombrado;//total renombrado
	int longi_p;//longitud de la sentencia al traducir al lenguaje del programa NO SE  MODIFICA NUNCA
	int longi;//logitud de la sentencia, se va modificando al aplicar el algoritmo
	int comb;//cantidad de variables en potencias de 2
	int cantidad_atomos_int;//cantidad de atomos en variable int
	int cantidad_negadores;
	vector<char> atomos;//vector con las letras iniciales
	vector<char> ::iterator cantidad_atomos;//cantidad en el vector, hasta donde empiezan las letras repetidas 
	
	bool supera_abc;
	bool hecho;//bandera para saber si se analizo la sentencia
	
	
public:
	sentencia(string Sentee);//envio sentencia cargada por interfaz
	sentencia();
	void hace(string Sentee);
	void contador(int *aux);
	~sentencia();
	string devolver();//devuelve la sentencia original
	string num(int i);//pasa de int a string
	string conclu();//devuelve la conclusion de la sentencia
	string importa_binario(string lugar);
	string traduce_inver(string var);//pasa de simbolos del programa a simbolos normales
	bool pariente(int &posi);/*comprueba la existencia de parentesis simple y si existe devuelve 
	                         la posicion donde comienza*/ /// (p>q)
	bool actualiza_sente(string &sent);//devuelve la ultima modificacion de Sente o del Sente_mod
	bool renombra(int posi, int cantidad_reemplazar);//renombra y lo agrega a la tabla_renombrado;
	bool res_by_op();//resolucion por prioridad de operador
	bool negacion();//reemplaza operadores unarios de negacion por variables
	bool inicia_atomos();//inicia las combinaciones de los atomos en la tabla_logica
	bool crear_matriz();//inicializar valor V y F la matrif final
	bool analiza_moleculas();//analizaar tablas
	bool analiza_sintaxis(vector<string> &log);//comprueba sintaxis
	bool rm_par_in();//remueve parentesis inecesarios
	bool traduce(string *lista_simbolos);//pasa de simbolos de entrada a simbolos usados por el programa
	bool reporte(string dire, int wha);//crea archivo con la salida del programa
	bool reportehtml(string dire, int wha);//crea archivo con la salida del programa
	bool indexhtml(string dire, int wha,vector<string> llega);//crea archivo con la salida del programa
	bool comprueba_par();//pregunta por pazrentesis repetido simple
	bool resuelve(string unocero);//resuelve aplicando todas las funciones
	const sentencia &operator=(const sentencia &sen);//sobrecaarga del operador =
	bool errores(string linea, vector<string> &log,string *lista_simbolos);//
	bool reporte_bina(string lugar);
	bool simple(int &posi, char operad);//verifica posibilidad de evaluar parentesis No simples
	bool simplex(int &posi, char operad);//verifica posibilidad de evaluar parentesis para wl while del algoritmo de analisis
	friend class eventos;
	friend class eventos_equiva;
	friend class eventos_negacion;
	string lista_simbol[8];
	void limpia();
	void unosyceros();
	vector<char> devuelve_atomos();
	string version;
	string limpiahtml(string linea);//agrega escapes para exportar en html
	int tiempodecalculo; //variable para medir el tiempo de calculo

};

#endif

