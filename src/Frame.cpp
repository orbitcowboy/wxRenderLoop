// --------------------------
/// @author ettl martin
/// @date   2013-11-26
// --------------------------
#include "Frame.hpp"
#include <wx/textdlg.h>

// wxEvent Table
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_QUIT            , MyFrame::OnQuit)
    EVT_MENU(ID_ABOUT           , MyFrame::OnAbout)
END_EVENT_TABLE()

MyFrame::MyFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
    , m_pMenubar(NULL)
    , m_pFileMenu(NULL)
    , m_pHelpMenu(NULL)
{
    // set up the menu bar
    vSetUpMenuBar();

    // set up the status bar
    vSetUpStatusBar();

    // create a panel to place all the controls
    m_pPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(600, 600));

    // set the window size
    this->SetSize(300, 150);
}

MyFrame::~MyFrame() {}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close();
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxAboutDialogInfo AboutDialogInfo;
    AboutDialogInfo.AddDeveloper(wxT("Dr. rer. nat. Martin Ettl"));
    AboutDialogInfo.SetDescription(wxT("wxWidgets minimal demo\nby\nDr. rer. nat. Martin Ettl"));
    AboutDialogInfo.SetName(wxT("wxTemplate"));
    AboutDialogInfo.SetVersion(wxT(__DATE__));
    wxAboutBox(AboutDialogInfo);
}

void MyFrame::vOnButton(wxCommandEvent &event)
{
    switch(event.GetId())
    {
        default:
            break;
    }
    return;
}

void MyFrame::vSetUpMenuBar(void)
{
#if wxUSE_MENUS
    m_pMenubar = new wxMenuBar();

    // set up the file menu
    m_pFileMenu = new wxMenu(_T(""));
    m_pFileMenu->Append(ID_QUIT, _("&Quit\tAlt-F4"), _("Quit the application"));
    m_pMenubar->Append(m_pFileMenu, _("&File"));

    // set up the help menu
    m_pHelpMenu = new wxMenu(_T(""));
    m_pHelpMenu->Append(ID_ABOUT, _("&About\tF1"), _("Show info about this application"));
    m_pMenubar->Append(m_pHelpMenu, _("&Help"));

    // realize the menu(send it to the window)
    SetMenuBar(m_pMenubar);
#endif // wxUSE_MENUS
}

void MyFrame::vSetUpStatusBar(void)
{
#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello user !"), 0);
    SetStatusText(wxVERSION_STRING, 1);
#endif // wxUSE_STATUSBAR   
}
