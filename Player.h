//
// Created by Kevin on 11/15/2016.
//

#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H
#include<string>
using namespace std;
class Player
{
public:
    Player(string userName);
    string getUserName();
    int returnPoints();
    void playerShoot();
    void/*Direction*/ playerMove();
private:
    int points;
    String userName;
    /*direction*/ int playerPos();

protected:
};

#endif //FINAL_PLAYER_H
