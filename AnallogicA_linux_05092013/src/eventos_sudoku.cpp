#include "eventos_sudoku.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include "wxsudoku.h"
#include <string>
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/icon.h>
#include <vector>
#include <algorithm>
using namespace std;

string wxs2s(wxString pasa){
	char buf[500];																//
	strcpy( buf, (const char*)(pasa).mb_str(wxConvUTF8) );	//convuerto direccion a string
	string cov=buf;	
	return cov;
}
//----------------------
struct sudoku { //nazwa struktury
	int p;          //przechowuje liczby
	int b;          //odpowiada za wyswietlanie/chowanie liczb w ukrytej tablicy
	
};
int sudoku(struct sudoku tablica[9][9],int x, int y){
	//    printf("%d %d", x,y);
	int tab[9] = {1,1,1,1,1,1,1,1,1};//same jedynki
	int i,j;
	
	for(i=0;i<y;++i){//sprawdza x;sy
		tab[tablica[x][i].p-1]=0; //jesli jest to dajesz 0
	}
	
	for(i=0;i<x;++i){//sprawdza y'ki
		tab[tablica[i][y].p-1]=0; //jesli jest to to dajesz
	}
	
	for(i=(3*(x/3));i<(3*(x/3)+3);++i){ //znajduje pierwszy pjt w kwadracie, wpierw x
		for(j=(3*(y/3));j<y;++j){ //...potem y'k
			tab[tablica[i][j].p-1]=0; //sprawdza jaka liczba jest i wstawia 0 jesli nie mozna juz jej wstawi\u0107
		}
	}
	int n=0;
	for(i=0;i<9;++i){
		
		n=n+tab[i];//sprawdza wielkosc tablicy
	}
	
	int *tab2; //nowa tablica z rozmiarem n
	tab2=(int*)malloc(sizeof(int)*n);
	
	j=0; //bedzie potrzebny do wskazania punktu
	for(i=0;i<9;++i){
		if(tab[i]==1){
			tab2[j]=i+1;
			j++;
		}
	}
	
	int ny, nx;// odpowiadaja za pozycje
	
	if(x==8){
		ny=y+1; //wiekszamy y'k
		nx=0;   //zeruje x zeby przesunac na kolejny wiersz "potem"
	}
	else {
		ny=y; //bez zmian
		nx=x+1;//przesuwamy x w prawo
	}
	
	//    int spr;
	//    printf("\n\n\t\tnx %d, ny %d", nx, ny);
	//    scanf("%d", &spr);
	
	while(n>0){
		int los=rand()%n;//losuje indeks z tabliczy liczb
		tablica[x][y].p=tab2[los];//przypisuje do tablicy x y wylosowana liczbe z tab2 z indeksem [los]
		tab2[los]=tab2[n-1]; //mam tab2 z liczbami i zmniejszam tablice o jeden
		
		n--;
		
		if(x==8 && y==8) {
			free(tab2); // unikam wycieku pamieci
			return 1;
		}
		
		if (sudoku(tablica,nx,ny)==1){
			free(tab2); // unikam wycieku pamieci
			return 1;
		} //jesli zwraca 1 to znaczy ze sie udalo to losuj kolejny raz  nowa
		
	}
	free(tab2); // unikam wycieku pamieci
	return 0;
}

int ukryjl(struct sudoku tablica[9][9]){//funkcja ukrywa liczby
	int i=0,j=0;//zmienne potrzebne
	
	for(i=0;i<9;++i){//robie zeby ukryte pola byly zresetowane
		for(j=0;j<9;++j){
			tablica[i][j].b=0;
		}
	}
	
	for(i=0;i<28;++i){
		tablica[rand()%9][rand()%9].b=1;
	}
}

int wypisz(struct sudoku tablica[9][9]){
	int i=0,j=0;
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				if(tablica[i][j].b==1){
				} //nic nie ma
			}
		}
		
		
}


//---------------------Codigo sudoku
string num(int i){	//   int a string
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

int i=0,j=0;
struct sudoku tablica[9][9];//[x][y]
string aux;
eventos_sudoku::eventos_sudoku(wxWindow *parent) : sudoku_main(parent) {
	srand(time(NULL));
	sudoku(tablica,0,0);//pierwsze wywolanie
	ukryjl(tablica);
//	wypisz(tablica);
	//----pinto grilla
	for (int i=0;i<9;i++){
		for (int j=3;j<6;j++){
			m_grid2->SetCellBackgroundColour(i,j,*wxGREEN);
		}
	}
	for (int i=0;i<9;i++){
		for (int j=3;j<6;j++){
			m_grid2->SetCellBackgroundColour(j,i,*wxGREEN);
		}
	}
	for (int i=3;i<6;i++){
		for (int j=3;j<6;j++){
				m_grid2->SetCellBackgroundColour(j,i,*wxWHITE);
		}
	}
	//---pinto grilla
	int i=0,j=0;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			if(tablica[i][j].b==1){
				aux=num(tablica[i][j].p);
				m_grid2->SetCellValue(i,j,wxString::FromAscii(aux.c_str()));
				m_grid2->SetCellTextColour(i,j,*wxRED);
//				m_grid2->SetCellBackgroundColour(i,j,*wxGREEN);
				m_grid2->SetReadOnly(i,j,true);
			} //nic nie ma
		}
	}
	
}

void eventos_sudoku::click_limpiar( wxCommandEvent& event )  {
	int i=0,j=0;
	aux="";
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			if(tablica[i][j].b==0){
				m_grid2->SetCellValue(i,j,wxString::FromAscii(aux.c_str()));
			} //nic nie ma
		}
	}
}

void eventos_sudoku::click_comprobar( wxCommandEvent& event )  {
	wxString saux, aux_wx;
	int i=0,j=0;
	bool ok=true;
	vector<string> comparacion;
	comparacion.insert(comparacion.end(),"1");
	comparacion.insert(comparacion.end(),"2");
	comparacion.insert(comparacion.end(),"3");
	comparacion.insert(comparacion.end(),"4");
	comparacion.insert(comparacion.end(),"5");
	comparacion.insert(comparacion.end(),"6");
	comparacion.insert(comparacion.end(),"7");
	comparacion.insert(comparacion.end(),"8");
	comparacion.insert(comparacion.end(),"9");
	vector<string> vector_ordena;
	vector<string> vector_ordena2;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			aux_wx=m_grid2->GetCellValue(i,j);
			if (aux_wx==wxT("1")||aux_wx==wxT("2")||aux_wx==wxT("3")||aux_wx==wxT("4")||aux_wx==wxT("5")||aux_wx==wxT("6")||aux_wx==wxT("7")||aux_wx==wxT("8")||aux_wx==wxT("9")){
				vector_ordena2.insert(vector_ordena2.end(),wxs2s(aux_wx));
			}else{
				ok=false;
			}
		}
		if (ok==true){
		sort(vector_ordena2.begin(), vector_ordena2.end());
			for (int m=0;m<9;m++){
				if (vector_ordena2[m]!=comparacion[m]){
					ok=false;
				}
			}
		}
		vector_ordena2.clear();
	}
	
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			aux_wx=m_grid2->GetCellValue(j,i);
			if (aux_wx==wxT("1")||aux_wx==wxT("2")||aux_wx==wxT("3")||aux_wx==wxT("4")||aux_wx==wxT("5")||aux_wx==wxT("6")||aux_wx==wxT("7")||aux_wx==wxT("8")||aux_wx==wxT("9")){
				vector_ordena.insert(vector_ordena.end(),wxs2s(aux_wx));
			}else{
				ok=false;
			}			
		}
		if (ok==true){
		sort(vector_ordena.begin(), vector_ordena.end());
			for (int m=0;m<9;m++){
				if (vector_ordena[m]!=comparacion[m]){
					ok=false;
				}
			}
		vector_ordena.clear();
		}
	}
	if (ok==true){
		wxMessageBox(wxT("!Sudoku correcto!"),wxT("Resultado"),wxICON_INFORMATION);
	}else{
		wxMessageBox(wxT("!Sudoku incorrecto!"),wxT("Resultado"),wxICON_INFORMATION);
	}
}

void eventos_sudoku::click_nuevo( wxCommandEvent& event )  {

	m_grid2->ClearGrid();
	srand(time(NULL));
	sudoku(tablica,0,0);//pierwsze wywolanie
	ukryjl(tablica);
	int i=0,j=0;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			if(tablica[i][j].b==1){
				aux=num(tablica[i][j].p);
				m_grid2->SetCellValue(i,j,wxString::FromAscii(aux.c_str()));
				m_grid2->SetCellTextColour(i,j,*wxRED);
				m_grid2->SetReadOnly(i,j,true);
			} //nic nie ma
		}
	}
}

void eventos_sudoku::click_salir( wxCommandEvent& event )  {
	Close();
}

void eventos_sudoku::click_about( wxCommandEvent& event )  {
	wxMessageBox(wxT("Felices 7 meses buitrita, te amo mucho "),wxT("=)"),wxICON_INFORMATION);
}

eventos_sudoku::~eventos_sudoku() {
	
}

