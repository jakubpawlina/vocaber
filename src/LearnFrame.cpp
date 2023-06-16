#include "LearnFrame.h"

LearnFrame::LearnFrame(const wxString &title, const wxString &dataFilePath) : wxFrame(nullptr, wxID_ANY, title), dataFilePath(dataFilePath) {
    CreateControls();
}

void LearnFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0, 24)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 16)));

    this->panel->SetFont(mainFont);
    this->panel->SetSizer(new wxBoxSizer(wxVERTICAL));

    wxString labelText = "Path: " + dataFilePath;
    wxClientDC dc(this->panel);
    dc.SetFont(headlineFont);
    wxSize labelSize = dc.GetTextExtent(labelText);
    headlineText = new wxStaticText(
            this->panel, wxID_ANY, labelText, wxPoint(0, 40),
            wxSize(800, labelSize.GetHeight()), wxALIGN_CENTER_HORIZONTAL
            );
    headlineText->SetFont(headlineFont);
    this->panel->GetSizer()->Add(this->headlineText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->panel->GetSizer()->Fit(this->panel);
}
