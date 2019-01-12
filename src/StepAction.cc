
#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include "StepAction.hh"
#include "EventAction.hh"

StepAction::StepAction(EventAction* eventAction):event(eventAction) {
   eventAction = event;
}

void StepAction::UserSteppingAction(const G4Step *aStep) {

    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_CH_log" &&
        aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma"  &&
        aStep->GetNumberOfSecondariesInCurrentStep() == 0
        ) {

        event->AddEnDep(aStep->GetTrack()->GetKineticEnergy());
        event->AddSunEn(aStep->GetTotalEnergyDeposit());

    }
}
    // aStep->GetTrack()->GetVolume()->GetName(),

  /*  if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName()=="scin_YAP_log" &&
        aStep->GetTrack()->GetParticleDefinition()->GetParticleName()=="gamma") {

        event->Data_YAP(aStep->GetTrack()->GetVolume()->GetName(), aStep->GetTrack()->GetKineticEnergy());

    }
*/


/*void StepAction::UserSteppingAction(const G4Step *step) {
    int num = 0;
    if (step->GetPostStepPoint()->GetPhysicalVolume() != nullptr)
        if (step->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "world_pvp"
            && step->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "shphere_pvp"
            && step->GetTrack()->GetKineticEnergy() > 3.2 * MeV
            && step->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma")
            //event->AddEnDep(step->GetTotalEnergyDeposit());
            event->AddGamma(1);
}
//GetPreStepPoint - точка наала шага */

