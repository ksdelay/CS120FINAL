//
// Created by Kevin Delay on 11/27/2016
// Edited by Nick Medor on 12/01/2016
//

#include "Collectables.h"

Collectables::Collectables() {
}

Collectables::Collectables(Point location, Direction direction){
	setLocation(location);
	setDirection(direction);
}

Point Collectables::getLocation() const {
	return location;
}

Direction Collectables::getDirection() const {
	return direction;
}

void Collectables::setLocation(Point location) {
	this->location = location;
}

void Collectables::setDirection(Direction direction) {
	this->direction = direction;
}

void Collectables::interact() {
}

void Collectables::move() {
	if (checkMove()) {
		direction.setXComponent(-1 * direction.getXComponent());
	}
	location.setXCoordinate(location.getXCoordinate() + 2 * direction.getXComponent());
	if (location.getYCoordinate() > -5) {
		location.setYCoordinate(location.getYCoordinate() - 1);
	}
	else {
		respawn();
	}
}

void Collectables::respawn() {
	location.setYCoordinate(250);
}

bool Collectables::checkMove() const {
	if (location.getXCoordinate() + 2 * direction.getXComponent() < 0 || location.getXCoordinate() + 2 * direction.getXComponent() > 250) {
		return true;
	}
	else {
		return false;
	}
}

Points::Points(){
}

Points::Points(Point location, Direction direction){
	setLocation(location);
	setDirection(direction);
}

void Points::interact() {
	cout << "1";
}

Multiplier::Multiplier(){
}

Multiplier::Multiplier(Point location, Direction direction){
	setLocation(location);
	setDirection(direction);
}

void Multiplier::interact() {
	cout << "2";
}
