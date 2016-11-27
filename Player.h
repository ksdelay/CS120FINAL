//
// Created by Junchi Li on 11/15/2016.
//

#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H
#include<string>
#include"Direction.h"
#include"Bullet.h"
using namespace std;
class Player
{
public:
	Player();

    Player(string userName, double xLocation, double yLocation);

    string getUserName();

	void setUserName(string userName);

    int returnPoints();

	void setPoints(int points);

	double getXLocation() const;

	double getYLocation() const;

	Direction getDirection() const;

	void setXLocation(double xLocation);

	void setYLocation(double yLocation);

	void setDirection(Direction direction);

    void playerShoot();

    void playerMove();

	Bullet getBullet() const;

	void setBullet(Bullet bullet);

	Bullet getShootBullet() const;

	void setShootBullet(Bullet bullet);
private:

    int points;
    string userName;
	double xLocation;
	double yLocation;
	Bullet bullet;
	Direction direction;
	double speed;
	Bullet shootBullet;
protected:
};

#endif //FINAL_PLAYER_H
