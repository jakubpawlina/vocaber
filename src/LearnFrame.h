#pragma once
#include <wx/wx.h>

class LearnFrame : public wxFrame {
public:
    explicit LearnFrame(const wxString& title, const wxString& dataFilePath);
private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* headlineText = new wxStaticText();

    wxString dataFilePath{};

    void CreateControls();

    void OnInputEnter(wxCommandEvent &evt);
    void OnButtonClicked(wxCommandEvent &evt);

    void CheckUserAnswer();
};
