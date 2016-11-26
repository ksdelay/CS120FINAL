//
// Created by Nick Medor on 11/15/16
//

#ifndef Asteroid_h
#define Asreroid_h

#include "Direction.h"

class Asteroid {
public:

	Asteroid();

	Asteroid(double xLocation, double yLocation, double speed, double size, Direction direction);

	double getXLocation() const;

	double getYLocation() const;

	double getSpeed() const;

	double getSize() const;

	Direction getDirection() const;

	void setXLocation(double xLocation);

	void setYLocation(double yLocation);

	void setSpeed(double speed);

	void setSize(double size);

	void setDirection(Direction direction);

	void move();

	void hit();

	void respawn();

private:

	double xLocation;
	double yLocation;
	double speed;
	double size;
	Direction direction;

};

#endif