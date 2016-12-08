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
	location.setXCoordinate(location.getXCoordinate() + 0.025 * direction.getXComponent());
	if (location.getYCoordinate() > 50) {
		location.setYCoordinate(location.getYCoordinate() - 0.025);
	}
	else {
		respawn();
	}
}

void Collectables::respawn() {
	location.setYCoordinate(550);
}

bool Collectables::checkMove() const {
	if (location.getXCoordinate() + 0.025 * direction.getXComponent() < 0 || location.getXCoordinate() + 0.025 * direction.getXComponent() > 480) {
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
