// --------------------------
/// @author ettl martin
/// @date   2013-11-26
// --------------------------
#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/aboutdlg.h>

class MyFrame: public wxFrame
{
        enum wxIDs
        {
            ID_ABOUT = wxID_HIGHEST
                       , ID_QUIT
        };

    public:

        MyFrame(wxFrame *frame, const wxString& title);
        virtual ~MyFrame();

    private:

        // ---------------
        // Event Handler :
        // ---------------
        void OnQuit   (wxCommandEvent& );
        void OnAbout  (wxCommandEvent& );
        void vOnButton(wxCommandEvent& );

        // -----------------
        // Helper functions:
        // -----------------
        void vSetUpMenuBar  (void);
        void vSetUpStatusBar(void);

        wxPanel * m_panel;
        wxMenuBar * m_menuBar;
        wxMenu * m_fileMenu;
        wxMenu * m_helpMenu;

        DECLARE_EVENT_TABLE()
};
#endif // MAIN_H
