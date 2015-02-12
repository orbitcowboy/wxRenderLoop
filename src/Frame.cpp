// --------------------------
/// @author Dr. Martin Ettl
/// @date   2014-12-03
// --------------------------
#include "Frame.hpp"
#include <wx/textdlg.h>

// wxEvent Table
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_QUIT, MyFrame::OnQuit)
    EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
    //EVT_BUTTON(SOME_ID, MyFrame::OnButton)
END_EVENT_TABLE()

MyFrame::MyFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
    , m_menuBar(NULL)
    , m_fileMenu(NULL)
    , m_helpMenu(NULL)
{
    // set default size hints
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    // set up the menu bar
    SetUpMenuBar();

    // set up the status bar
    SetUpStatusBar();

    wxBoxSizer* boxSizer = new wxBoxSizer( wxVERTICAL );
    // create a panel to place all the controls
    m_panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(600, 600));
    boxSizer->Add(m_panel, 1, wxALL | wxEXPAND, 5);
    // set the sizer
    this->SetSizer( boxSizer );
    // force layout
    this->Layout();
    // set default window size
    this->SetSize(300, 150);
    // Restore settings from previous session
    RestoreCurrentProgramSettings();
}

MyFrame::~MyFrame(void)
{
    SaveCurrentProgramSettings();
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close();
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxAboutDialogInfo AboutDialogInfo;
    AboutDialogInfo.AddDeveloper(wxT("Dr. rer. nat. Martin Ettl"));
    AboutDialogInfo.SetName(this->GetTitle());
    AboutDialogInfo.SetVersion(wxT(__DATE__));
    wxAboutBox(AboutDialogInfo);
}

void MyFrame::OnButton(wxCommandEvent &event)
{
    switch(event.GetId())
    {
            /*
            case SOME_ID:
            {
                break;
            }
            */
        default:
        {
            // unknown id
            break;
        }
    }
    return;
}

void MyFrame::SetUpMenuBar(void)
{
#if wxUSE_MENUS
    m_menuBar = new wxMenuBar();

    // set up the file menu
    m_fileMenu = new wxMenu(_T(""));
    m_fileMenu->Append(ID_QUIT, _("&Quit\tAlt-F4"), _("Quit the application"));
    m_menuBar->Append(m_fileMenu, _("&File"));

    // set up the help menu
    m_helpMenu = new wxMenu(_T(""));
    m_helpMenu->Append(ID_ABOUT, _("&About\tF1"), _("Show info about this application"));
    m_menuBar->Append(m_helpMenu, _("&Help"));

    // realize the menu(send it to the window)
    SetMenuBar(m_menuBar);
#endif // wxUSE_MENUS
}

void MyFrame::SetUpStatusBar(void)
{
#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(wxEmptyString, 0);
    SetStatusText(wxVERSION_STRING, 1);
#endif // wxUSE_STATUSBAR   
}

void MyFrame::SaveCurrentProgramSettings(void)
{
    delete m_config;
}

void MyFrame::RestoreCurrentProgramSettings(void)
{
    m_config = new wxConfig(this->GetTitle());
    // restore settings
    wxString currentValue;
    if( m_config->Read("key", &currentValue) )
    {

    }
}
