
#ifndef EVENTOS_SELECTOR_H
#define EVENTOS_SELECTOR_H
#include "wxventanas.h"
class eventos_selector:public selector_simboloes {
private:
protected:
	void click_help( wxCommandEvent& event );
	void click_ok( wxCommandEvent& event );
	void press_enter( wxCommandEvent& event );
public:
	eventos_selector(wxWindow *parent=NULL);
	~eventos_selector();
};

#endif

