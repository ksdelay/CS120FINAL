//
// Created by Junchi Li on 11/15/2016.
// Edited by Nick Medor on 12/01/2016 - replaced xLocation and
//		yLocation with Point location, removed speed, size, and
//		direction fields
//

#include "Bullet.h"

Bullet::Bullet() {
}

Bullet::Bullet(Point location) {
	setLocation(location);
	inUse = false;
}

Point Bullet::getLocation() const {
	return location;
}


double Bullet::getXCoord() const {
	return(location.getXCoordinate());
}

double Bullet::getYCoord() const {
	return(location.getYCoordinate());
}
bool Bullet::getInUse() const {
	return(inUse);
}
void Bullet::setInUse(bool active)
{
	inUse = active;
}
void Bullet::setXCoord(double x)
{
	location.setXCoordinate(x);
}
void Bullet::setYCoord(double y)
{
	location.setYCoordinate(y);
}
void Bullet::setLocation(Point location) {
	this->location = location;
}

void Bullet::move() {
	if (!(location.getYCoordinate() + .05 >= 499)) {
		location.setYCoordinate(location.getYCoordinate() + .05);
	}
	else {
		respawn();
	}
}

void Bullet::hit() {
	// not sure what to do here yet
}
void Bullet::respawn() {
	location.setXCoordinate(700);
	location.setYCoordinate(700);
	inUse = false;
}