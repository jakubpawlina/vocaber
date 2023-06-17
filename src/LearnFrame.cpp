#include "LearnFrame.h"


LearnFrame::LearnFrame(const wxString &title, const wxString &dataFilePath) :
        wxFrame(nullptr, wxID_ANY, title), dataFilePath(dataFilePath) {
    CreateControls();
    BindEventHandlers();
}


void LearnFrame::CreateControls() {
    wxFont questionFont(wxFontInfo(wxSize(0, 20)).Bold());

    this->sizer->AddStretchSpacer();

    this->staticText = new wxStaticText(this, wxID_ANY, "Using data from file: " + this->dataFilePath);
    this->sizer->Add(this->staticText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    this->questionImageBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap("../assets/image.jpg", wxBITMAP_TYPE_JPEG));
    this->questionImageBitmap->SetMaxSize(wxSize(500, 300));
    this->sizer->Add(this->questionImageBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);

    this->questionText = new wxStaticText(this, wxID_ANY, "example question");
    this->questionText->SetFont(questionFont);
    this->sizer->Add(this->questionText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 30);

    this->userAnswerInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, 35), wxTE_CENTER | wxTE_PROCESS_ENTER);
    this->userAnswerInput->SetFocus();
    this->sizer->Add(this->userAnswerInput, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 10);

    this->checkAnswerButton = new wxButton(this, wxID_ANY, "Check answer!", wxDefaultPosition, wxSize(120, 35));
    this->sizer->Add(this->checkAnswerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);

    this->sizer->AddStretchSpacer();

    SetSizer(this->sizer);
}


void LearnFrame::CheckUserAnswer() {
    wxMessageBox(wxT("Answer is correct (or not)!"));
    staticText->SetLabel("An answer has been provided.");
    sizer->Layout();
}


void LearnFrame::OnInputEnter([[maybe_unused]] wxCommandEvent &evt) {
    LearnFrame::CheckUserAnswer();
}


void LearnFrame::OnButtonClicked([[maybe_unused]] wxCommandEvent &evt) {
    LearnFrame::CheckUserAnswer();
}


void LearnFrame::BindEventHandlers() {
    this->userAnswerInput->Bind(wxEVT_TEXT_ENTER, &LearnFrame::OnInputEnter, this);
    this->checkAnswerButton->Bind(wxEVT_BUTTON, &LearnFrame::OnButtonClicked, this);
}
