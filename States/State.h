#ifndef _STATES_STATE_H_
#define _STATES_STATE_H_

class State
{
public:
    virtual void init() = 0;
    virtual void process() = 0;
};

#endif
