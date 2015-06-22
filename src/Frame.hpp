// --------------------------
/// @author Dr. Martin Ettl
/// @date   2014-12-03
// --------------------------
#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/aboutdlg.h>
#include <wx/config.h>

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

        // Event handler, which is called when the program terminates.
        void OnQuit   (wxCommandEvent& );
        void onClose(wxCloseEvent& evt);
        // Event handler, which is called when F1-key is pressed.
        void OnAbout  (wxCommandEvent& );
        // Event handler, which is called when a button is pressed.
        void OnButton (wxCommandEvent& );

        // Save the current program settings using wxConfig.
        void SaveCurrentProgramSettings(void);

        // Restore the current program settings using wxConfig.
        void RestoreCurrentProgramSettings(void);

        // A helper function to set up the menu bar.
        void SetUpMenuBar  (void);
        // A helper function to set up the status bar.
        void SetUpStatusBar(void);


        wxPanel * m_panel;
        wxMenuBar * m_menuBar;
        wxMenu * m_fileMenu;
        wxMenu * m_helpMenu;
        wxConfig * m_config;

        DECLARE_EVENT_TABLE()
};
#endif // MAIN_H
