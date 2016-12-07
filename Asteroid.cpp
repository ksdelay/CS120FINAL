//
// Created by Nick Medor on 11/26/16
//

#include "Asteroid.h"
#include <cmath>

Asteroid::Asteroid() {
	speed = 0.05;
	size = 1;
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
	if ((location.getXCoordinate() + speed*direction.getXComponent()) <= 0 || (location.getXCoordinate() + speed*direction.getXComponent()) >= 500) { // the 250 value is dependent on the size of the game's window pane
		direction.setXComponent(direction.getXComponent()*-1);
	}
	else if ((location.getYCoordinate() - speed*direction.getYComponent()) <= 50) {
		respawn();
	}
	else {
		location.setYCoordinate(location.getYCoordinate() - speed);
		location.setXCoordinate(location.getXCoordinate() + speed*direction.getXComponent());
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
	location.setYCoordinate(rand() % 100 + 550); // this value is dependent on the size of the game's window pane
}