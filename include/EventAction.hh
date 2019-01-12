

#ifndef PW_2_GEOMETRY_EVENTACT_HH
#define PW_2_GEOMETRY_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "RunAction.hh"

class RunAction;

class EventAction: public G4UserEventAction {
public:
    explicit EventAction(RunAction* runAction);

    void BeginOfEventAction(const G4Event *anEvent);
    void EndOfEventAction(const G4Event *anEvent);
    void AddEnDep(G4double en);
    void AddSunEn(G4double en);

private: RunAction *run;
    G4double EnergyDep;
    G4double EnergySum;
};

#endif //PW_2_GEOMETRY_EVENTACT_HH
