#include "main.h"
#include "absolute.h"
#include "sizer.h"
#include "border.h"
#include "align.h"
#include "gotoclass.h"
#include "customButton.h"

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

    //GotoClass* gotoclass = new GotoClass(wxT("GotoClass"));
    //gotoclass->Show(true);


    //Custom Button:
    /**/
    // make sure to call this first
    wxInitAllImageHandlers();
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, wxT("Hello wxDC"), wxPoint(50, 50), wxSize(800, 600));
    // then simply create like this
    CustomButton* m_btn_1 = new CustomButton(frame, wxT("My Custom Button 11"));
    sizer->Add(m_btn_1, 0, wxALL, 5);
    CustomButton* m_btn_2 = new CustomButton(frame, wxT("Hello World!"));
    sizer->Add(m_btn_2, 0, wxALL, 5);
    CustomButton* m_btn_3 = new CustomButton(frame, wxT("Foo Bar"));
    sizer->Add(m_btn_3, 0, wxALL, 5);
    frame->SetSizer(sizer);
    frame->Show();
    

    return true;
}