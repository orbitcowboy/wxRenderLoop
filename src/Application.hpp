// --------------------------
/// @author Dr. Martin Ettl
/// @date   2014-12-03
// --------------------------

#ifndef APP_H
#define APP_H

#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class BasicDrawPane : public wxPanel
{
    public:
        BasicDrawPane(wxFrame* parent);

        void paintEvent(wxPaintEvent& evt);
        void paintNow();
        void render( wxDC& dc );

        DECLARE_EVENT_TABLE()
};

class MyFrame;

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
        void onIdle(wxIdleEvent& evt);

        bool render_loop_on;
        MyFrame* frame;
        BasicDrawPane* drawPane;
    public:
        void activateRenderLoop(bool on);
};

#endif // APP_H
