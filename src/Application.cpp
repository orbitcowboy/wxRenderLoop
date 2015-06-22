// --------------------------
/// @author Dr. Martin Ettl
/// @date   2014-12-03
// --------------------------

#include "Application.hpp"
#include "Frame.hpp"

/// OnInit will usually create a top window as a bare minimum. Unlike in earlier versions of wxWidgets,
/// OnInit does not return a frame. Instead it returns a boolean value which indicates whether processing should continue (true) or not (false).
bool MyApp::OnInit(void)
{
    render_loop_on = false;

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new MyFrame(0L, wxT("wxWidgets::wxTemplate"));

    drawPane = new BasicDrawPane( frame );
    sizer->Add(drawPane, 1, wxEXPAND);

    frame->SetSizer(sizer);
    frame->Show();

    activateRenderLoop(true);
    return true;
}

void MyApp::activateRenderLoop(bool on)
{
    if(on && !render_loop_on)
    {
        Connect( wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(MyApp::onIdle) );
        render_loop_on = true;
    }
    else if(!on && render_loop_on)
    {
        Disconnect( wxEVT_IDLE, wxIdleEventHandler(MyApp::onIdle) );
        render_loop_on = false;
    }
}

void MyApp::onIdle(wxIdleEvent& evt)
{
    if(render_loop_on)
    {
        drawPane->paintNow();
        evt.RequestMore(); // render continuously, not only once on idle
    }
}
