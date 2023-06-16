#include "LearnFrame.h"

LearnFrame::LearnFrame(const wxString &title, const wxString &dataFilePath) : wxFrame(nullptr, wxID_ANY, title), dataFilePath(dataFilePath) {
    CreateControls();
}

void LearnFrame::CreateControls() {
    wxFont questionFont(wxFontInfo(wxSize(0, 20)).Bold());

    auto* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->AddStretchSpacer();

    auto* staticText = new wxStaticText(this, wxID_ANY, "Using data from file: " + this->dataFilePath);
    sizer->Add(staticText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    auto* staticBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap("image.jpg", wxBITMAP_TYPE_JPEG));
    wxSize imageSize(500, 300);
    staticBitmap->SetMaxSize(imageSize);
    sizer->Add(staticBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);

    auto* questionText = new wxStaticText(this, wxID_ANY, "example question");
    questionText->SetFont(questionFont);
    sizer->Add(questionText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 30);

    auto* textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, 35), wxTE_CENTER | wxTE_PROCESS_ENTER);
    textCtrl->SetFocus();
    sizer->Add(textCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 10);
    textCtrl->Bind(wxEVT_TEXT_ENTER, &LearnFrame::OnInputEnter, this);

    auto* checkButton = new wxButton(this, wxID_ANY, "Check answer!", wxDefaultPosition, wxSize(120, 35));
    sizer->Add(checkButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);
    checkButton->Bind(wxEVT_BUTTON, &LearnFrame::OnButtonClicked, this);

    sizer->AddStretchSpacer();

    SetSizer(sizer);
}

void LearnFrame::CheckUserAnswer() {
    wxMessageBox(wxT("Answer is correct (or not)!"));
}

void LearnFrame::OnInputEnter(wxCommandEvent &evt) {
    LearnFrame::CheckUserAnswer();
}

void LearnFrame::OnButtonClicked(wxCommandEvent &evt) {
    LearnFrame::CheckUserAnswer();
}
