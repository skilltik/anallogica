#ifndef EVENTOS_SUDOKU_H
#define EVENTOS_SUDOKU_H
#include "wxsudoku.h"

class eventos_sudoku : public sudoku_main {
	
private:
	
protected:
	void click_limpiar( wxCommandEvent& event ) ;
	void click_comprobar( wxCommandEvent& event ) ;
	void click_nuevo( wxCommandEvent& event ) ;
	void click_salir( wxCommandEvent& event ) ;
	void click_about( wxCommandEvent& event ) ;
	
public:
	eventos_sudoku(wxWindow *parent=NULL);
	~eventos_sudoku();
};

#endif

