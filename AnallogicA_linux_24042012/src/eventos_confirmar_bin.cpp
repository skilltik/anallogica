
#include "eventos_confirmar_bin.h"

eventos_confirmar_bin::eventos_confirmar_bin(wxWindow *parent) : confirmar_bin(parent) {
}

eventos_confirmar_bin::~eventos_confirmar_bin() {
}

void eventos_confirmar_bin::click_sob( wxCommandEvent& event ) {
	EndModal(0);
}

void eventos_confirmar_bin::click_aniadir( wxCommandEvent& event ) {
	EndModal(1);
}

void eventos_confirmar_bin::click_otro_nombre( wxCommandEvent& event ) {
	EndModal(2);
}

