#include "FinishFrame.h"

FinishFrame::FinishFrame(const wxString &title, unsigned int result, unsigned int maxResult) :
    wxFrame(nullptr, wxID_ANY, "Vocaber | Learning: " + title), result_(result), maxResult_(maxResult) {
    CreateControls();
}

void FinishFrame::CreateControls() {
    this->sizer->AddStretchSpacer();

    this->staticText = new wxStaticText(this, wxID_ANY, "Learning finished!");
    this->staticText->SetFont(wxFontInfo(wxSize(0, 30)).Bold());
    this->staticText->SetForegroundColour(wxColour(100, 200, 0, 255));
    this->sizer->Add(this->staticText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 20);

    this->resultInfo = new wxStaticText(this, wxID_ANY, "Result: " + std::to_string(this->result_) + " / " + std::to_string(this->maxResult_));
    this->resultInfo->SetFont(wxFontInfo(wxSize(0, 20)).Bold());
    this->sizer->Add(this->resultInfo, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 20);

    this->sizer->AddStretchSpacer();

    SetSizer(this->sizer);
}