#include "LearnFrame.h"


LearnFrame::LearnFrame(const wxString &title, const wxString &dataFilePath, nlohmann::json &json) :
        wxFrame(nullptr, wxID_ANY, "Vocaber | Learning: " + title),
        dataFilePath(dataFilePath),
        correctAnswerMessages({
                        wxString("This is the correct answer! Good job! ") + wxUniChar(0x0001F929),
                        wxString("You're right! Bravo! ") + wxUniChar(0x0001F44F),
                        wxString("That's spotless! You've got it perfectly! ") + wxUniChar(0x0001F44C),
                        wxString("Absolutely right! You're on fire! ") + wxUniChar(0x0001F525),
                        wxString("You're on the money! That's the correct answer! ") + wxUniChar(0x0001F4B0),
                        wxString("You hit the bullseye! Well played! ") + wxUniChar(0x0001F3AF),
                        wxString("You've cracked it! Well done! ") + wxUniChar(0x0001F4AA)}),
        generator(this->random_device()),
        correctMessagesDistribution(0, static_cast<int>(this->correctAnswerMessages.size()) - 1),
        setTitle(title.ToStdString()),
        questions(loadFromJSON(json)) {
    CreateControls();
    BindEventHandlers();
}


void LearnFrame::CreateControls() {
    wxFont questionFont(wxFontInfo(wxSize(0, 20)).Bold());

    this->sizer->AddStretchSpacer();

    wxBitmap originalBitmap = getQuestionImage(this->currentQuestionIndex_);
    if (originalBitmap.IsOk()) {
        this->questionImageBitmap = new wxStaticBitmap(this, wxID_ANY, scaleWxBitmap(originalBitmap, wxSize(500, 300)));
        this->sizer->Add(this->questionImageBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);
    } else {
        this->questionImageBitmap->Hide();
    }

    this->questionText = new wxStaticText(this, wxID_ANY, this->questions[currentQuestionIndex_].getTerm());
    this->questionText->SetFont(questionFont);
    this->sizer->Add(this->questionText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 30);

    this->userAnswerInput = new wxTextCtrl(
            this, wxID_ANY, "", wxDefaultPosition, wxSize(500, 35), wxTE_CENTER | wxTE_PROCESS_ENTER);
    this->userAnswerInput->SetFocus();
    this->sizer->Add(this->userAnswerInput, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 10);

    this->staticText = new wxStaticText(this, wxID_ANY, "");
    this->staticText->SetFont(wxFontInfo().Bold());
    this->sizer->Add(this->staticText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);
    this->staticText->Hide();

    this->checkAnswerButton = new wxButton(this, wxID_ANY, "Check answer!", wxDefaultPosition, wxSize(120, 35));
    this->sizer->Add(this->checkAnswerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);

    this->nextQuestionButton = new wxButton(this, wxID_ANY, "Next question", wxDefaultPosition, wxSize(120, 35));
    this->sizer->Add(this->nextQuestionButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);
    this->nextQuestionButton->Hide();

    this->sizer->AddStretchSpacer();

    SetSizer(this->sizer);
}


void LearnFrame::CheckUserAnswer() {
    if (this->userAnswerInput->GetValue().ToStdString() == questions[currentQuestionIndex_].getDefinition()) {
        auto it = correctAnswerMessages.begin();
        std::advance(it, correctMessagesDistribution(generator));
        this->staticText->SetLabel(*it);
        this->staticText->SetForegroundColour(wxColour(100, 200, 0, 255));
        ++(this->acquiredResult);
    } else {
        this->staticText->SetLabel(wxString("Oops! That's not the right answer... ") + wxUniChar(0x0001F614)
            + " The correct one is \"" + questions[currentQuestionIndex_].getDefinition() + "\".");
        this->staticText->SetForegroundColour(wxColour(220, 0, 40, 255));
    }
    this->staticText->Show();
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
    ++(this->currentQuestionIndex_);
    if (this->currentQuestionIndex_ == this->questions.size()) {
        auto* finishFrame = new FinishFrame(this->setTitle, this->acquiredResult, this->questions.size());
        finishFrame->SetClientSize(800, 600);
        finishFrame->Center();
        finishFrame->Show();
        Close();
    } else {
        this->staticText->SetLabel("");
        this->staticText->Hide();
        this->nextQuestionButton->Hide();
        this->checkAnswerButton->Show();
        this->userAnswerInput->Clear();
        this->userAnswerInput->Enable(true);
        this->userAnswerInput->SetFocus();
        this->questionText->SetLabel(this->questions[currentQuestionIndex_].getTerm());
        wxBitmap originalBitmap = getQuestionImage(this->currentQuestionIndex_);
        if (originalBitmap.IsOk()) {
            this->questionImageBitmap->SetBitmap(scaleWxBitmap(originalBitmap, wxSize(500, 300)));
            this->questionImageBitmap->Show();
        } else {
            this->questionImageBitmap->Hide();
        }
        this->sizer->Layout();
    }
}


void LearnFrame::BindEventHandlers() {
    this->userAnswerInput->Bind(wxEVT_TEXT_ENTER, &LearnFrame::OnInputEnter, this);
    this->checkAnswerButton->Bind(wxEVT_BUTTON, &LearnFrame::OnCheckAnswerButtonClicked, this);
    this->nextQuestionButton->Bind(wxEVT_BUTTON, &LearnFrame::OnNextQuestionButtonClicked, this);
}


wxBitmap LearnFrame::getQuestionImage(size_t currentQuestionIndex) {
    wxBitmap originalBitmap = (wxFileExists(this->defaultQuestionImagePath)) ? wxBitmap(this->defaultQuestionImagePath) : wxBitmap();
    if (wxFileExists(this->questions[currentQuestionIndex].getImagePath())) {
        wxString extension = wxFileName(this->questions[currentQuestionIndex].getImagePath()).GetExt();
        if (extension.IsSameAs("bmp", false) || extension.IsSameAs("png", false) ||
            extension.IsSameAs("jpg", false) || extension.IsSameAs("jpeg", false)) {
            wxBitmap tmpBitmap;
            if (tmpBitmap.LoadFile(this->questions[currentQuestionIndex].getImagePath()) && tmpBitmap.IsOk()) {
                originalBitmap = tmpBitmap;
            }
        }
    }
    return originalBitmap;
}
