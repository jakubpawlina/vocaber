#pragma once
#include <wx/wx.h>

#include "utilities/validate_json_input.h"

class LearnFrame : public wxFrame {
public:
    explicit LearnFrame(const wxString& title, const wxString& dataFilePath);

private:
    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "");
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxTextCtrl* userAnswerInput = new wxTextCtrl();
    wxButton* checkAnswerButton = new wxButton();
    wxStaticBitmap* questionImageBitmap = new wxStaticBitmap();
    wxStaticText* questionText = new wxStaticText();

    wxString dataFilePath{};

    void CreateControls();
    void BindEventHandlers();

    void OnInputEnter(wxCommandEvent &evt);
    void OnButtonClicked(wxCommandEvent &evt);

    void CheckUserAnswer();
};
