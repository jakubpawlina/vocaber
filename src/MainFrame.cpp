#include "MainFrame.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
}

void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 24)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 16)));

    panel = new wxPanel(this);
    panel->SetFont(mainFont);

    wxString labelText = "VOCABER";
    wxClientDC dc(panel);
    dc.SetFont(headlineFont);
    wxSize labelSize = dc.GetTextExtent(labelText);
    headlineText = new wxStaticText(panel, wxID_ANY, labelText, wxPoint(0, 40), wxSize(800, labelSize.GetHeight()), wxALIGN_CENTER_HORIZONTAL);
    headlineText->SetFont(headlineFont);

    button = new wxButton(panel, wxID_ANY, "Start test", wxPoint(350, 100), wxSize(100, 35));
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
}

void MainFrame::OnButtonClicked(wxCommandEvent &evt) {
    LearnFrame* learnFrame = new LearnFrame("VOCABER - LEARN");
    learnFrame->SetClientSize(800, 600);
    learnFrame->Center();
    learnFrame->Show();
}
