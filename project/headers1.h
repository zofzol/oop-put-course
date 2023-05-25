
#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <sstream>
#include <memory>
#include <cassert>
#include <fstream>
#include <ctime>
#include <string>
#include <algorithm>


using namespace std;

class Game
{
    private:
    string your_name;

    public:
    virtual void Your_Name()=0;
    virtual void Play()=0;
    virtual void Rules()=0;

    string name_;
    int number_of_played_games;

    Game()
    {
        number_of_played_games=0;
        your_name="xxx";
    }
};

#endif
