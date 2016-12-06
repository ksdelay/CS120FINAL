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
	location.setYCoordinate(location.getYCoordinate() + 5);
}

void Bullet::hit() {
	// not sure what to do here yet
}