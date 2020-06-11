#include "StateMachine.h"

void StateMachine::addState(StateRef newState, bool isReplacing /* = false */ )
{
    _isReplacing = isReplacing;
    _stateChanged = true;
    _newState = std::move(newState);
}

StateRef StateMachine::activeState()
{
    if(machine.empty())
        return NULL;
    
    return machine.top();
}

bool StateMachine::processChanges()
{
    if(!_stateChanged)
        return false;

    if(_newState == NULL)
        return false;
    
    if(_isReplacing && !machine.empty())
        machine.pop();
    
    machine.push(std::move(_newState));
    machine.top()->Init();
    _stateChanged = false;

    return true;
}
