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

#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
// wx Includes
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/aboutdlg.h>

// derive from wxFrame
class MyFrame: public wxFrame
{
        // event handler id's
        enum wxIDs
        {
            ID_ABOUT = wxID_HIGHEST
            , ID_QUIT
        };

    public:

        // Ctor
        MyFrame(wxFrame *frame, const wxString& title);
        // Dtor
        virtual ~MyFrame();

    private:

        // ---------------
        // Event Handler :
        // ---------------
        void OnQuit   (wxCommandEvent& event);
        void OnAbout  (wxCommandEvent& event);
        void vOnButton(wxCommandEvent& event);

        // -----------------
        // Helper functions:
        // -----------------
        void vSetUpMenuBar  (void);
        void vSetUpStatusBar(void);

        // ------------------
        // create a panel   :
        // ------------------
        wxPanel     *m_pPanel;

        // ------------------
        // create menue
        // ------------------
        wxMenuBar   *m_pMenubar ;
        wxMenu      *m_pFileMenu;
        wxMenu      *m_pHelpMenu;


        // create an eventtable, to connect the eventhandler functions
        // with the ID's
        DECLARE_EVENT_TABLE()
};




#endif // MAIN_H

// *************************************************************************
// * END OF FILE (CVS Concurrent Version Control)
// * -----------------------------------------------------------------------
// * $RCSfile: $
// * $Revision: $
// *************************************************************************


