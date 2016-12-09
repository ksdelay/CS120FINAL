//
// Created by Nick Medor on 11/26/16
//

#include "Asteroid.h"
#include <cmath>

Asteroid::Asteroid() {
	speed = 0.035;
	size = 1;
	direction.setDirection(randDouble(.01, 1), randDouble(.01, 1));
	location.setXCoordinate(0);
	location.setYCoordinate(500);
}

Asteroid::Asteroid(Point location, double speed, double size, Direction direction) {
	setLocation(location);
	setSpeed(speed);
	setSize(size);
	setDirection(direction);
}

Point Asteroid::getLocation() const {
	return location;
}

double Asteroid::getSpeed() const {
	return speed;
}

double Asteroid::getSize() const {
	return size;
}

Direction Asteroid::getDirection() const {
	return direction;
}

void Asteroid::setLocation(Point location) {
	this->location = location;
}

void Asteroid::setSpeed(double speed) {
	this->speed = speed;
}

void Asteroid::setSize(double size) {
	this->size = size;
}
void Asteroid::setDirection(Direction direction) {
	this->direction.setDirection(direction.getXComponent(), direction.getYComponent());
}

void Asteroid::move() {
	if ((location.getXCoordinate() + speed*direction.getXComponent()) <= 0 || (location.getXCoordinate() + speed*direction.getXComponent()) >= (500 - size*50)) { // the 250 value is dependent on the size of the game's window pane
		direction.setXComponent(direction.getXComponent()*-1);
	}
	if ((location.getYCoordinate() - speed) < 49) {
		respawn();
	}
	else {
		location.setYCoordinate(location.getYCoordinate() - speed);
		location.setXCoordinate(location.getXCoordinate() + speed*direction.getXComponent());
	}
}

void Asteroid::hit() {
	if (size == 0.5) {
		setSize(1);
		setSpeed(speed*1.05);
		respawn();
	}
	else {
		size = size - 0.5;
	}
}

void Asteroid::respawn() {
	location.setYCoordinate(rand() % 100 + 550);
	direction.setDirection(randDouble(.01, 1), randDouble(.01, 1));// this value is dependent on the size of the game's window pane
}
double Asteroid::randDouble(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}