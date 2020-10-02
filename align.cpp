#include "align.h"

Align::Align(const wxString& title) : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(300, 200)) {

    wxPanel* panel = new wxPanel(this, -1);                             //panel placed inside wxFrame and using its default Sizer --> Only one item spanning over full Screen

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);

    wxButton* ok = new wxButton(panel, -1, wxT("Ok"));                  //Ok Button
    wxButton* cancel = new wxButton(panel, -1, wxT("Cancel"));          //Cancel Button

    hbox1->Add(new wxPanel(panel, -1));                                 //Creating new panel inside first panel and using hbox1 Box Sizer
    vbox->Add(hbox1, 1, wxEXPAND);                                      //Placing hbox1 Sizer inside vbox Sizer

    hbox2->Add(ok);                                                     //Adding Ok and Cancel button to hbox2 Sizer
    hbox2->Add(cancel);

    vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);        //Adding hbox2 Sizer to vbox Sizer, aligning it to the right and adding a margin of 10 to the bottom and right

    panel->SetSizer(vbox);                                              //Replacing panels default Sizer with vbox Sizer

    Centre();
}