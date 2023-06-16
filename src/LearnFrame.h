#pragma once
#include <wx/wx.h>

class LearnFrame : public wxFrame {
public:
    explicit LearnFrame(const wxString& title, const wxString& dataFilePath);
private:
    wxPanel* panel{};
    wxStaticText* headlineText{};

    wxString dataFilePath{};

    void CreateControls();
};
