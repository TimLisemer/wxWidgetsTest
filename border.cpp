#include "border.h"

Border::Border(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 200)) {
    wxColour col1, col2;
    col1.Set(wxT("#4f5049"));
    col2.Set(wxT("#ededed"));

    wxPanel* panel = new wxPanel(this, -1);             //panel placed inside wxFrame and using its default sizer --> Only one item spanning over full Screen
    panel->SetBackgroundColour(col1);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);      //Custom Box Sizer

    wxPanel* midPan = new wxPanel(panel, wxID_ANY);     //midPan placed on a panel and using a custom box slicer
    midPan->SetBackgroundColour(col2);

    vbox->Add(midPan, 1, wxEXPAND | wxALL, 20);         //wxALL for all side space of 20; Alternative: wxLEFT wxRIGHT wxBOTTOM wxTOP

    panel->SetSizer(vbox);

    Centre();
}