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
	/**
	* Default Constructor
	* Requires: nothing
	* Modifies: points, userName,xLocation,yLocation,speed,direction
	* Effects: sets default Player class value
	* Calls: nothing
	*/
	Player();
	/**
	* non-Default Constructor
	* Requires: userName, x y location.
	* Modifies: points, userName,xLocation,yLocation,speed,direction
	* Effects: sets userName and x y location
	* Calls: nothing
	*/
    Player(string userName, double xLocation, double yLocation);

	/**
	* userName Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of userName
	* Calls: nothing
	*/
    string getUserName();

	/**
	* userName Setter
	* Requires: nothing
	* Modifies: userName
	* Effects: set the userName
	* Calls: nothing
	*/
	void setUserName(string userName);

	/**
	* points Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of points
	* Calls: nothing
	*/
    int returnPoints();

	/**
	* points Setter
	* Requires: nothing
	* Modifies: points
	* Effects: set the points
	* Calls: nothing
	*/
	void setPoints(int points);

	/**
	* XLocation Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of x location
	* Calls: nothing
	*/
	double getXLocation() const;

	/**
	* YLocation Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of y location
	* Calls: nothing
	*/
	double getYLocation() const;
	/**
	* Direction Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of direction
	* Calls: nothing
	*/
	Direction getDirection() const;

	/**
	* XLocation Setter
	* Requires: nothing
	* Modifies: xLocation
	* Effects: set the x location
	* Calls: nothing
	*/
	void setXLocation(double xLocation);

	/**
	* YLocation Setter
	* Requires: nothing
	* Modifies: yLocation
	* Effects: set the y location
	* Calls: nothing
	*/
	void setYLocation(double yLocation);

	/**
	* direction Setter
	* Requires: nothing
	* Modifies: direction
	* Effects: set the direction
	* Calls: Direction::setDirection()
	*/
	void setDirection(Direction direction);

	/**
	* shoot bullet
	* Requires: nothing
	* Modifies: shootBullet
	* Effects: make the shoot bullet move
	* Calls: Bullet::BulletMove,setSize,setYLocation
	*/
    void playerShoot();

	/**
	* player move
	* Requires: nothing
	* Modifies: xLocation, yLocation
	* Effects: make player move
	* Calls: nothing
	*/
    void playerMove();

	/**
	* Bullet Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: get the bullet
	* Calls: nothing
	*/
	Bullet getBullet() const;

	/**
	* Bullet Setter
	* Requires: nothing
	* Modifies: bullet
	* Effects: set the bullet
	* Calls: Bullet::Bullet()
	*/
	void setBullet(Bullet bullet);

	/**
	* shootBullet Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: get the shootBullet
	* Calls: nothing
	*/
	Bullet getShootBullet() const;

	/**
	* shootBullet Setter
	* Requires: nothing
	* Modifies: shootBullet
	* Effects: set the shootBullet
	* Calls: Bullet::Bullet()
	*/
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
