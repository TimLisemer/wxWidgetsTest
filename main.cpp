#include "main.h"
#include "absolute.h"
#include "sizer.h"
#include "border.h"
#include "align.h"
#include "gotoclass.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    //Absolute* absolute = new Absolute(wxT("Absolute"));
    //absolute->Show(true);

    //Sizer* sizer = new Sizer(wxT("Sizer"));
    //sizer->Show(true);

    //Border* border = new Border(wxT("Border"));
    //border->Show(true);

    //Align* align = new Align(wxT("Align"));
    //align->Show(true);

    GotoClass* gotoclass = new GotoClass(wxT("GotoClass"));
    gotoclass->Show(true);

    return true;
}