#include "FinishFrame.h"

FinishFrame::FinishFrame(const wxString &title) :
    wxFrame(nullptr, wxID_ANY, "Vocaber | Learning: " + title) {

    this->sizer->AddStretchSpacer();

    this->staticText = new wxStaticText(this, wxID_ANY, "Learning finished!");
    this->staticText->SetFont(wxFontInfo(wxSize(0, 30)).Bold());
    this->staticText->SetForegroundColour(wxColour(100, 200, 0, 255));
    this->sizer->Add(this->staticText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 20);

    this->sizer->AddStretchSpacer();

    SetSizer(this->sizer);
}
