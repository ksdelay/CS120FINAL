//
// Created by Junchi Li on 11/15/2016.
//

#include "Bullet.h"

Bullet::Bullet() {
	xLocation = 0;
	yLocation = 0;
	speed = 5;
	size = 0;
	direction.setDirection(0, 1);
}
Bullet::Bullet(double xLocation, double yLocation) {
	setXLocation(xLocation);
	setYLocation(yLocation);
	speed = 5;
	size = 1;
	direction.setDirection(0, 1);
}
double Bullet::getXLocation() const {
	return xLocation;
}

double Bullet::getYLocation() const {
	return yLocation;
}

double Bullet::getSpeed() const {
	return speed;
}

double Bullet::getSize() const {
	return size;
}

Direction Bullet::getDirection() const {
	return direction;
}

void Bullet::setXLocation(double xLocation) {
	this->xLocation = xLocation;
}

void Bullet::setYLocation(double yLocation) {
	this->yLocation = yLocation;
}

void Bullet::setSpeed(double speed) {
	this->speed = speed;
}

void Bullet::setSize(double size) {
	this->size = size;
}
void Bullet::setDirection(Direction direction) {
	this->direction.setDirection(direction.getXComponent(), direction.getYComponent());
}
void Bullet::BulletMove() {
	if ((yLocation + speed*direction.getYComponent()) >= 250) {
		size=0;
	}
	else if ((xLocation + speed*direction.getXComponent()) <= 0 || (xLocation + speed*direction.getXComponent()) >= 250) {
		size=0;
	}
	else {
		yLocation = yLocation + speed*direction.getYComponent();
		xLocation = xLocation + speed*direction.getXComponent();
	}
}
void Bullet::BulletHit() {
	size=0;
}