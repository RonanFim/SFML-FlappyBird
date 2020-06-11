#ifndef _STATES_MENU_H_
#define _STATES_MENU_H_

#include "State.h"
#include "../GameData.h"

class Menu : public State
{
public:
    Menu(GameDataRef game);
    void init();
    void process();

private:
    GameDataRef _game;
};

#endif