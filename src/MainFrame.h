#pragma once
#include <wx/wx.h>
#include "LearnFrame.h"

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    wxPanel* panel{};
    wxStaticText* headlineText{};
    wxButton* button{};

    void CreateControls();

    void OnButtonClicked(wxCommandEvent &evt);
};
