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
}