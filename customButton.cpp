#include "customButton.h"

BEGIN_EVENT_TABLE(CustomButton, wxPanel)

    EVT_MOTION(CustomButton::mouseMoved)
    EVT_LEFT_DOWN(CustomButton::mouseDown)
    EVT_LEFT_UP(CustomButton::mouseReleased)
    EVT_RIGHT_DOWN(CustomButton::rightClick)
    EVT_LEAVE_WINDOW(CustomButton::mouseLeftWindow)
    EVT_KEY_DOWN(CustomButton::keyPressed)
    EVT_KEY_UP(CustomButton::keyReleased)
    EVT_MOUSEWHEEL(CustomButton::mouseWheelMoved)

    // catch paint events
    EVT_PAINT(CustomButton::paintEvent)

END_EVENT_TABLE()


CustomButton::CustomButton(wxFrame* parent, wxString text) :
    wxWindow(parent, wxID_ANY) {
    SetMinSize(wxSize(buttonWidth, buttonHeight));
    this->text = text;
    pressedDown = false;
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void CustomButton::paintEvent(wxPaintEvent& evt) {
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void CustomButton::paintNow() {
    // depending on your system you may need to look at double-buffered dcs
    wxClientDC dc(this);
    render(dc);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void CustomButton::render(wxDC& dc) {
    if (pressedDown)
        dc.SetBrush(*wxRED_BRUSH);
    else
        dc.SetBrush(*wxGREY_BRUSH);

    dc.DrawRectangle(0, 0, buttonWidth, buttonHeight);
    dc.DrawText(text, 20, 15);
}

void CustomButton::mouseDown(wxMouseEvent& event) {
    pressedDown = true;
    paintNow();
}
void CustomButton::mouseReleased(wxMouseEvent& event) {
    pressedDown = false;
    paintNow();

    wxMessageBox(wxT("You pressed a custom button"));
}
void CustomButton::mouseLeftWindow(wxMouseEvent& event) {
    if (pressedDown) {
        pressedDown = false;
        paintNow();
    }
}

// currently unused events
void CustomButton::mouseMoved(wxMouseEvent& event) {}
void CustomButton::mouseWheelMoved(wxMouseEvent& event) {}
void CustomButton::rightClick(wxMouseEvent& event) {}
void CustomButton::keyPressed(wxKeyEvent& event) {}
void CustomButton::keyReleased(wxKeyEvent& event) {}