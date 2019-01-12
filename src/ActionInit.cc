
#include "ActionInit.hh"
#include "EventAction.hh"
#include "StepAction.hh"
#include "RunAction.hh"

ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const {
    SetUserAction(new PrimaryGen);

    RunAction* runAction = new RunAction;
    SetUserAction(runAction);

    EventAction* eventAction = new EventAction(runAction);
    SetUserAction(eventAction);

    SetUserAction(new StepAction(eventAction));


}