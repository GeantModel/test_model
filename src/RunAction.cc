
#include <G4Run.hh>
#include <G4UserRunAction.hh>
#include <G4SIunits.hh>
#include "RunAction.hh"
#include "EventAction.hh"

using namespace std;

RunAction::RunAction() {
    result = new map<G4double, G4int>;
}

RunAction::~RunAction() {
    delete result;
}

void RunAction::BeginOfRunAction(const G4Run *aRun) {
    result->clear();
    SumE = 0;
    G4double nStep = 1000;
    G4double eMax = 2.0;
    for (int i = 0; i < nStep; i++) {
        result->emplace(i * eMax / nStep, 0);
    }
}
void RunAction::EndOfRunAction(const G4Run *aRun) {

    fstream fout("/mnt/hgfs/VMplayer/Test2/Detector.txt", std::ios::out);
    fout<<"Энерговыделение епта  "<<SumE<<"\n";
    for (auto it: *result)
        fout << it.first<< " | " << it.second << "\n";
    fout.close();
    cout<<"%%%%%%%%%%%%%%%%%%%%_KONEC_%%%%%%%%%%%%%%%%%%%%%%%%;";
}

void RunAction::AddSumEnergy(G4double energy) {
     SumE=+energy;
}

void RunAction::AddEvent(G4double energy) {
    result->lower_bound(energy)->second++;
}