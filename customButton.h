#include <wx/wx.h>
#include <wx/sizer.h>

class CustomButton : public wxWindow
{

    bool pressedDown;
    wxString text;
        
    static const int buttonWidth = 200;
    static const int buttonHeight = 50;
        
public:
    CustomButton(wxFrame* parent, wxString text);
        
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
        
    void render(wxDC& dc);
        
    // some useful events
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);
        
    DECLARE_EVENT_TABLE();
};

/*
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
*/