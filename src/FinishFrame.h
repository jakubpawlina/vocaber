#pragma once
#include <wx/wx.h>

class FinishFrame : public wxFrame {
public:
    explicit FinishFrame(const wxString& title);

private:
    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "");
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
};

