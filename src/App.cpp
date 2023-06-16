#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto* mainFrame = new MainFrame("Vocaber");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}
