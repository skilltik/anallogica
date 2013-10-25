
#ifndef EVENTOS_CONFIRMAR_BIN_H
#define EVENTOS_CONFIRMAR_BIN_H
#include "wxventanas.h"

class eventos_confirmar_bin : public confirmar_bin {
	
private:
	
protected:
	void click_sob( wxCommandEvent& event );
	void click_aniadir( wxCommandEvent& event );
	void click_otro_nombre( wxCommandEvent& event );
	
public:
	eventos_confirmar_bin(wxWindow *parent=NULL);
	~eventos_confirmar_bin();
};

#endif

