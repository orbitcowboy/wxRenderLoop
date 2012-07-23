/***********************************************************************
* SVN: Version Control with Subversion
* ---------------------------------------------------------------------
* $Id$
***********************************************************************
* LICENSE AND WARRANTY INFORMATION
* ================================
*
* Copyright (C) 2011
* Forschungseinrichtung Satellitengeodaesie, TU Muenchen &
* Bundesamt fuer Kartographie und Geodaesie
* Geodetic Observatory Wettzell
* Sackenrieder Str. 25
* D-93444 Bad Koetzting
* Germany
*
* This program is FREE SOFTWARE under the terms of GNU Lesser General
* Public License v3 (or any later version) and may be used following
* this definitions as published by the Free Software Foundation at
* http://www.gnu.de/documents/lgpl-3.0.en.html. Software parts which
* include elements from external software distributions may be under
* different licenses as the Sun License/BSD License for the ONC/Sun RPC
* (http://www.opensource.org/licenses/bsd-license.php)
* and the wxWindows Library Licence for the GUI parts with wxWidgets
* (http://www.opensource.org/licenses/wxwindows.php).
* In case of variations to the above licenses each particular developer
* is responsible for defining the dedicated license conditions and terms.
*
* This program is distributed in the hope that it will be useful.
* IT IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING
* THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A
* PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE
* OR TRADE PRACTICE.
*
* The software is provided with no support and without any obligation
* on the part of the Geodetic Observatory Wettzell to assist in its
* use, correction, modification or enhancement. THE Geodetic Observatory
* Wettzell SHALL HAVE NO LIABILITY WITH RESPECT TO THE INFRINGEMENT OF
* COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THE SOFTWARE OR ANY PART
* THEREOF. In no event will the Geodetic Observatory Wettzell be liable
* for any lost revenue or profits or other special, indirect and
* consequential damages, even if the Geodetic Observatory Wettzell
* has been advised of the possibility of such damages.
*
* You should have received a copy of the license(s) along with this program.
**********************************************************************/

// --------------------------
/// @author ettl martin
/// @date   2012-01-24
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
    m_pPanel    = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(600, 600));

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
    AboutDialogInfo.AddDeveloper(wxT("Ettl Martin Dipl. Inf (FH)\nTechnical University of Munich\nResearch Department Satellite Geodesy\n-Fundamentalstation Wettzell -\nSackenrieder Str.25\nD-93444 Bad Koetzting\nEmail:ettl@fs.wettzell.de\n "));
    AboutDialogInfo.SetDescription(wxT("wxSample Demo\nby\nEttl Martin"));
    AboutDialogInfo.SetName(wxT("wxSampleApp"));
    AboutDialogInfo.SetVersion(wxT("v15.04.2009"));
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

    // realize the menu( send it to the window)
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
// *************************************************************************
// * END OF FILE (CVS Concurrent Version Control)
// * -----------------------------------------------------------------------
// * $RCSfile: $
// * $Revision: $
// *************************************************************************


