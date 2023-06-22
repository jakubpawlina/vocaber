#include "LearnFrame.h"


LearnFrame::LearnFrame(const wxString &title, const wxString &dataFilePath, nlohmann::json &json) :
        wxFrame(nullptr, wxID_ANY, "Vocaber | Learning: " + title), dataFilePath(dataFilePath) {
    this->setTitle = title.ToStdString();
    this->questions = loadFromJSON(json);
    CreateControls();
    BindEventHandlers();
}


void LearnFrame::CreateControls() {
    wxFont questionFont(wxFontInfo(wxSize(0, 20)).Bold());

    this->sizer->AddStretchSpacer();

    wxBitmap originalBitmap = (wxFileExists(this->defaultQuestionImagePath)) ? wxBitmap(defaultQuestionImagePath) : wxBitmap();
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
    if (originalBitmap.IsOk()) {
        this->questionImageBitmap = new wxStaticBitmap(this, wxID_ANY, scaleWxBitmap(originalBitmap, wxSize(500, 300)));
        this->sizer->Add(this->questionImageBitmap, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);
    } else {
        this->questionImageBitmap->Hide();
    }

    this->questionText = new wxStaticText(this, wxID_ANY, this->questions[currentQuestionIndex].getTerm());
    this->questionText->SetFont(questionFont);
    this->sizer->Add(this->questionText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 30);

    this->userAnswerInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(500, 35), wxTE_CENTER | wxTE_PROCESS_ENTER);
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
    if (this->userAnswerInput->GetValue().ToStdString() == questions[currentQuestionIndex].getDefinition()) {
        this->staticText->SetLabel("This is the correct answer! Good job!");
        this->staticText->SetForegroundColour(wxColour(100, 200, 0, 255));
        ++(this->acquiredResult);
    } else {
        this->staticText->SetLabel("Incorrect! Should be: " + questions[currentQuestionIndex].getDefinition() + ".");
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
    ++(this->currentQuestionIndex);
    if (this->currentQuestionIndex == this->questions.size()) {
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
        this->questionText->SetLabel(this->questions[currentQuestionIndex].getTerm());
        wxBitmap originalBitmap = (wxFileExists(this->defaultQuestionImagePath)) ? wxBitmap(defaultQuestionImagePath) : wxBitmap();
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
