
#include <RunAction.hh>
#include <StepAction.hh>
#include <EventAction.hh>

EventAction::EventAction(RunAction *runAction) : run(runAction) {
}
void EventAction::BeginOfEventAction(const G4Event *anEvent) {
    EnergyDep = 0;
}

void EventAction::EndOfEventAction(const G4Event *anEvent) {
    run->AddEvent(EnergyDep);
    run->AddSumEnergy(EnergySum);
   // G4cout<<"КОЛИЧЕСТВО ГАММА-КВАНТОВ  = "<<num<<'\n';
}

void EventAction::AddEnDep(G4double en){
    EnergyDep=+en;
}

void EventAction::AddSunEn(G4double en) {
    EnergySum=+en;

}

