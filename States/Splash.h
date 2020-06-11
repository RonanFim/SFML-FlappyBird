#ifndef _STATES_SPLASH_H_
#define _STATES_SPLASH_H_

#include "State.h"
#include "../GameData.h"

class Splash : public State
{
public:
    Splash(GameDataRef game);
    void init();
    void process();

private:
    GameDataRef _game;
};

#endif
