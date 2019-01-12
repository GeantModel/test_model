//
// Created by student on 21.04.18.
//

#ifndef PW_2_GEOMETRY_RUNACTION_HH
#define PW_2_GEOMETRY_RUNACTION_HH

#include <G4UserRunAction.hh>
#include <map>
#include <fstream>

using namespace std;

class RunAction : public G4UserRunAction {
private:
    map<G4double, G4int> *result;
    G4double SumE;
    // map<G4double, G4int> *result_YAP;
    // G4double N1, N2;

public:
    RunAction();
    ~RunAction();

    void BeginOfRunAction(const G4Run *aRun) override;
    void EndOfRunAction(const G4Run *aRun) override;
    void AddEvent(G4double energy);
    void AddSumEnergy(G4double energy);
    // void AddEvent_YAP(G4String name, G4double energy);


};
#endif //PW_2_GEOMETRY_RUNACTION_HH
