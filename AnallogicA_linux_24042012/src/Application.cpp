
#include "Application.h"
#include <wx/image.h>
#include "eventos.h"
#include <wx/splash.h>
#include <wx/timer.h>

bool mxApplication::OnInit() {
	wxBitmap bitmap;
	wxInitAllImageHandlers();
	new eventos(NULL);
	return true;
}
