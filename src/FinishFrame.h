#pragma once
#include <wx/wx.h>

class FinishFrame : public wxFrame {
public:
    explicit FinishFrame(const wxString& title, unsigned int result, unsigned int maxResult);

private:
    unsigned int result_;
    unsigned int maxResult_;

    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "");
    wxStaticText* resultInfo = new wxStaticText(this, wxID_ANY, "");
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    void CreateControls();
};
