//
// Created by student on 21.04.18.
//

#ifndef PW_2_GEOMETRY_STEPACTION_HH
#define PW_2_GEOMETRY_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <EventAction.hh>

class EventAction;

class StepAction: public G4UserSteppingAction{
public:
    StepAction(EventAction* eventAction);
    void UserSteppingAction(const G4Step*);

private:
    EventAction* event;
};

#endif //PW_2_GEOMETRY_STEPACTION_HH
