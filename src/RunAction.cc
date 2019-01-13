
#include <G4Run.hh>
#include <G4UserRunAction.hh>
#include <G4SIunits.hh>
#include "RunAction.hh"
#include "EventAction.hh"
#include <G4SIunits.hh>

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
    int nStep = 100;
    G4double eMax = 2.0 * MeV;
    for (int i = 0; i < nStep; i++) {
        result->emplace(i * eMax / nStep, 0);
    }
}
void RunAction::EndOfRunAction(const G4Run *aRun) {

    fstream fout("../result.txt", std::ios::out);
    fout<<"Энерговыделение епта  "<<SumE<<"\n";
    for (auto it: *result)
        fout << it.first<< " " << it.second << "\n";
    fout.close();
    cout<<"%%%%%%%%%%%%%%%%%%%%_KONEC_%%%%%%%%%%%%%%%%%%%%%%%%;";
}
void RunAction::AddSumEnergy(G4double energy) {
     SumE=+energy;
}
void RunAction::AddEvent(G4double energy) {
    auto it = result->lower_bound(energy);
    it->second++;
}