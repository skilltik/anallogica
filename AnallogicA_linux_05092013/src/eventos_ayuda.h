
#ifndef EVENTOS_AYUDA_H
#define EVENTOS_AYUDA_H
#include "wxventanas.h"

class eventos_ayuda : public ayuda {
	
private:
	
protected:
	wxString ruta;
public:
	eventos_ayuda(wxString rut,wxWindow *parent=NULL);
	~eventos_ayuda();
};

#endif

