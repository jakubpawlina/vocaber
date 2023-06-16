#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    wxPanel* panel{};
    wxStaticText* headlineText{};

    void CreateControls();
};
