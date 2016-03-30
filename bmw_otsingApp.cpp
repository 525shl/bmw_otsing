/***************************************************************
 * Name:      bmw_otsingApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Janar Kivilo (m@kz.ee)
 * Created:   2015-11-27
 * Copyright: Janar Kivilo (kz.ee)
 * License:
 **************************************************************/

#include "bmw_otsingApp.h"

//(*AppHeaders
#include "bmw_otsingMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(bmw_otsingApp);

bool bmw_otsingApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	bmw_otsingFrame* Frame = new bmw_otsingFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
