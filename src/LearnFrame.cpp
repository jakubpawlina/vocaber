#include "LearnFrame.h"

LearnFrame::LearnFrame(const wxString &title, const wxString &dataFilePath) : wxFrame(nullptr, wxID_ANY, title), dataFilePath(dataFilePath) {
    CreateControls();
}

void LearnFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 24)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 16)));

    panel = new wxPanel(this);
    panel->SetFont(mainFont);

    wxString labelText = "Path: " + dataFilePath;
    wxClientDC dc(panel);
    dc.SetFont(headlineFont);
    wxSize labelSize = dc.GetTextExtent(labelText);
    headlineText = new wxStaticText(panel, wxID_ANY, labelText, wxPoint(0, 40), wxSize(800, labelSize.GetHeight()), wxALIGN_CENTER_HORIZONTAL);
    headlineText->SetFont(headlineFont);
}
