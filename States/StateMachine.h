#ifndef _STATES_STATEMACHINE_H_
#define _STATES_STATEMACHINE_H_

#include <memory>
#include <stack>

#include "State.h"

typedef std::shared_ptr<State> StateRef;

class StateMachine {
  public:
    void addState(StateRef newState, bool isReplacing = false);
    StateRef activeState();
    bool processChanges();
  private:
    std::stack<StateRef> machine;
    StateRef _newState;
    bool _isReplacing;
    bool _stateChanged;
};

#endif