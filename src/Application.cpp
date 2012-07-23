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

#include "Application.hpp"
#include "Frame.hpp"

// create the app
IMPLEMENT_APP(MyApp)

// initialize the frame
bool MyApp::OnInit()
{

    MyFrame* pFrame = new MyFrame(0L, _("wxWidgets::"));

    pFrame->Show();
    return true;
}
