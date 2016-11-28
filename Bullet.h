//
// Created by Junchi Li on 11/15/2016.
//

#ifndef BULLET_H
#define BULLET_H
#include <string>
#include "Direction.h"
using namespace std;

class Bullet {
public:
	/**
	* Default Constructor
	* Requires: nothing
	* Modifies: xLocation,yLocation,speed,size,direction
	* Effects: sets default Bullet class value
	* Calls: nothing
	*/
	Bullet();
	/**
	* non-Default Constructor
	* Requires: values for x and y location
	* Modifies: xLocation,yLocation,speed,size,direction
	* Effects: sets bullet x and y location Bullet class value
	* Calls: nothing
	*/
	Bullet(double xLocation, double yLocation);

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
	* speed Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of speed
	* Calls: nothing
	*/
	double getSpeed() const;

	/**
	* size Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of size
	* Calls: nothing
	*/
	double getSize() const;

	/**
	* Direction Getter
	* Requires: nothing
	* Modifies: nothing
	* Effects: returns the value of direction
	* Calls: nothing
	*/
	Direction getDirection() const;

	/**
	* speed Setter
	* Requires: nothing
	* Modifies: speed
	* Effects: set the speed
	* Calls: nothing
	*/
	void setSpeed(double speed);

	/**
	* size Setter
	* Requires: nothing
	* Modifies: size
	* Effects: set the size
	* Calls: nothing
	*/
	void setSize(double size);

	/**
	* direction Setter
	* Requires: nothing
	* Modifies: direction
	* Effects: set the direction
	* Calls: Direction::setDirection()
	*/
	void setDirection(Direction direction);

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
	* Move Bullet
	* Requires: nothing
	* Modifies: size, xLocation, yLocation
	* Effects: let bullet move by speed and direction
	* Calls: nothing
	*/
	void BulletMove();

	/**
	* Bullet hit
	* Requires: nothing
	* Modifies: size
	* Effects: make bullet size to 0 when bullet hit
	* Calls: nothing
	*/
	void BulletHit();

private:
	double xLocation;
	double yLocation;
	double speed;
	double size;
	Direction direction;
protected:
};



#endif // !BULLET_H

