//
// Created by Nick Medor on 11/26/16
//

#include "Asteroid.h"

Asteroid::Asteroid() {
	xLocation = 0;
	yLocation = 0;
	speed = 1;
	size = 1;
}

Asteroid::Asteroid(double xLocation, double yLocation, double speed, double size, Direction direction) {
	setXLocation(xLocation);
	setYLocation(yLocation);
	setSpeed(speed);
	setSize(size);
	setDirection(direction);
}

double Asteroid::getXLocation() const {
	return xLocation;
}

double Asteroid::getYLocation() const {
	return yLocation;
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

void Asteroid::setXLocation(double xLocation) {
	this->xLocation = xLocation;
}

void Asteroid::setYLocation(double yLocation) {
	this->yLocation = yLocation;
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
	if ((xLocation + speed*direction.getXComponent()) <= 0 || (xLocation + speed*direction.getXComponent()) >= 250) { // the 250 value is dependent on the size of the game's window pane
		direction.setXComponent(direction.getXComponent()*-1);
	}
	if ((yLocation - speed) < -5) {
		respawn();
	}
	else {
		yLocation = yLocation - speed;
		xLocation = xLocation + speed*direction.getXComponent();
	}
}

void Asteroid::hit() {
	if (size == 0) {
		setSize(1);
		setSpeed(speed*1.05);
		respawn();
	}
	else {
		size--;
	}
}

void Asteroid::respawn() {
	yLocation = 250; // this value is dependent on the size of the game's window pane
}