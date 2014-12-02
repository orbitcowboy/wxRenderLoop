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

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // APP_H
