#ifndef _STATES_STATE_H_
#define _STATES_STATE_H_

class State
{
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void HandleInput() = 0;
    virtual void Draw() = 0;
};

#endif
