#include "eventos_ayuda.h"

eventos_ayuda::eventos_ayuda(wxString rut,wxWindow *parent) : ayuda(parent) {
	navegador->LoadPage(rut);
}

eventos_ayuda::~eventos_ayuda() {
}

