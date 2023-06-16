#pragma once
#include <wx/wx.h>

class LearnFrame : public wxFrame {
public:
    explicit LearnFrame(const wxString& title);
private:
    wxPanel* panel{};
    wxStaticText* headlineText{};

    void CreateControls();
};
