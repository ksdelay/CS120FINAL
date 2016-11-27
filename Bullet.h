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
	Bullet();

	Bullet(double xLocation, double yLocation);

	double getXLocation() const;

	double getYLocation() const;

	double getSpeed() const;

	double getSize() const;

	Direction getDirection() const;

	void setSpeed(double speed);

	void setSize(double size);

	void setDirection(Direction direction);

	void setXLocation(double xLocation);

	void setYLocation(double yLocation);

	void BulletMove();

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

