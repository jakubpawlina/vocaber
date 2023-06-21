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

    wxBitmap originalBitmap = wxBitmap("../assets/460-2000x1000.jpg");
    wxSize maxSize(500, 300);
    double scaleWidth = static_cast<double>(maxSize.GetWidth()) / originalBitmap.GetWidth();
    double scaleHeight = static_cast<double>(maxSize.GetHeight()) / originalBitmap.GetHeight();
    double scaleFactor = std::min(scaleWidth, scaleHeight);
    int scaledWidth = static_cast<int>(originalBitmap.GetWidth() * scaleFactor);
    int scaledHeight = static_cast<int>(originalBitmap.GetHeight() * scaleFactor);
    wxImage scaledImage = originalBitmap.ConvertToImage().Rescale(scaledWidth, scaledHeight, wxIMAGE_QUALITY_HIGH);
    this->questionImageBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(scaledImage));
    this->sizer->Add(this->questionImageBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);

    this->questionText = new wxStaticText(this, wxID_ANY, "example question");
    this->questionText->SetFont(questionFont);
    this->sizer->Add(this->questionText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 30);

    this->userAnswerInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, 35), wxTE_CENTER | wxTE_PROCESS_ENTER);
    this->userAnswerInput->SetFocus();
    this->sizer->Add(this->userAnswerInput, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 10);

    this->checkAnswerButton = new wxButton(this, wxID_ANY, "Check answer!", wxDefaultPosition, wxSize(120, 35));
    this->sizer->Add(this->checkAnswerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);

    this->nextQuestionButton = new wxButton(this, wxID_ANY, "Next question", wxDefaultPosition, wxSize(120, 35));
    this->sizer->Add(this->nextQuestionButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);
    this->nextQuestionButton->Hide();

    this->sizer->AddStretchSpacer();

    SetSizer(this->sizer);
}


void LearnFrame::CheckUserAnswer() {
    this->staticText->SetLabel("An answer is correct (or not).");
    this->staticText->SetForegroundColour(wxColour(255, 200, 50, 255));
    this->staticText->SetFont(wxFontInfo().Bold());
    this->checkAnswerButton->Hide();
    this->nextQuestionButton->Show();
    this->nextQuestionButton->SetFocus();
    this->userAnswerInput->Enable(false);
    this->sizer->Layout();
}


void LearnFrame::OnInputEnter([[maybe_unused]] wxCommandEvent &evt) {
    LearnFrame::CheckUserAnswer();
}


void LearnFrame::OnCheckAnswerButtonClicked([[maybe_unused]] wxCommandEvent &evt) {
    LearnFrame::CheckUserAnswer();
}

void LearnFrame::OnNextQuestionButtonClicked([[maybe_unused]] wxCommandEvent &evt) {
    wxMessageBox(wxT("Not implemented yet!"));
}


void LearnFrame::BindEventHandlers() {
    this->userAnswerInput->Bind(wxEVT_TEXT_ENTER, &LearnFrame::OnInputEnter, this);
    this->checkAnswerButton->Bind(wxEVT_BUTTON, &LearnFrame::OnCheckAnswerButtonClicked, this);
    this->nextQuestionButton->Bind(wxEVT_BUTTON, &LearnFrame::OnNextQuestionButtonClicked, this);
}
