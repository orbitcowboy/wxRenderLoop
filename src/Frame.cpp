// --------------------------
/// @author Dr. Martin Ettl
/// @date   2014-12-03
// --------------------------
#include "Frame.hpp"
#include "Application.hpp"
#include <wx/textdlg.h>
#include <wx/app.h>

/// The use of IMPLEMENT_APP(appClass), which allows wxWidgets to dynamically create an instance of the application object at the appropriate point in wxWidgets initialization.
/// Previous versions of wxWidgets used to rely on the creation of a global application object, but this is no longer recommended, because required global initialization may not
/// have been performed at application object construction time.
IMPLEMENT_APP(MyApp)

// wxEvent Table
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_QUIT, MyFrame::OnQuit)
    EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
    //EVT_BUTTON(SOME_ID, MyFrame::OnButton)
    EVT_CLOSE(MyFrame::onClose)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
    EVT_PAINT(BasicDrawPane::paintEvent)
END_EVENT_TABLE()



BasicDrawPane::BasicDrawPane(wxFrame* parent) :
    wxPanel(parent)
{
}


void BasicDrawPane::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void BasicDrawPane::render( wxDC& dc )
{
    static int y = 0;
    static int y_speed = 2;

    y += y_speed;
    if(y < 0) y_speed = 2;
    if(y > 200) y_speed = -2;

    dc.SetBackground( *wxWHITE_BRUSH );
    dc.Clear();
    dc.DrawText(wxT("Testing"), 40, y);
}

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
    // Set default background color
    wxFrame::SetBackgroundColour(wxColor(235, 235, 235));
    // force layout
    wxFrame::Layout();
    // set default window size
    this->SetSize(300, 150);
    // Restore settings from previous session
    RestoreCurrentProgramSettings();
}

MyFrame::~MyFrame(void)
{
    SaveCurrentProgramSettings();
}

void MyFrame::onClose(wxCloseEvent& evt)
{
    wxGetApp().activateRenderLoop(false);
    evt.Skip(); // don't stop event, we still want window to close
}

void MyFrame::OnQuit(wxCommandEvent& event)
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
    wxFrame::SetMenuBar(m_menuBar);
#endif // wxUSE_MENUS
}

void MyFrame::SetUpStatusBar(void)
{
#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    wxFrame::CreateStatusBar(2);
    wxFrame::SetStatusText(wxEmptyString, 0);
    wxFrame::SetStatusText(wxVERSION_STRING, 1);
#endif // wxUSE_STATUSBAR   
}

void MyFrame::SaveCurrentProgramSettings(void)
{
    delete m_config;
}

void MyFrame::RestoreCurrentProgramSettings(void)
{
    m_config = new wxConfig(wxFrame::GetTitle());
    // restore settings
    wxString currentValue;
    if( m_config->Read(wxT("key"), &currentValue) )
    {

    }
}
