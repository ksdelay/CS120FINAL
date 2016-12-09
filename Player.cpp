//
// Created by Junchi Li on 11/15/2016.
// Edited by Nick Medor on 12/01/2016 - replaced xLocation and
//		yLocation with Point location, removed speed and
//		direction fields, renamed points to score
//

#include "Player.h"

Player::Player() {
	score = 0;
	life = 10;
	userName = "";
}

Player::Player(string userName, Point location) {
	score = 0;
	life = 10;
	setUserName(userName);
	setLocation(location);
}

int Player::getScore() const {
	return score;
}

int Player::getLife() const {
	return life;
}

string Player::getUserName() const {
	return userName;
}

Point Player::getLocation() const {
	return location;
}

double Player::getXCoord() const {
	return(location.getXCoordinate());
}

double Player::getYCoord() const {
	return(location.getYCoordinate());
}

void Player::setXCoord(double x) {
	location.setXCoordinate(x);
}

void Player::setYCoord(double y) {
	location.setYCoordinate(y);
}

void Player::setScore(int score) {
	this->score = score;
}

void Player::setLife(int life) {
	this->life = life;
}

void Player::setUserName(string userName) {
	this->userName = userName;
}

void Player::setLocation(Point location) {
	this->location = location;
}

void Player::shoot() {
	// not sure about this method yet
}

void Player::moveLeft() {
	if (checkMoveLeft()) {
		location.setXCoordinate(location.getXCoordinate() - 10);
	}
	else {
		location.setXCoordinate(0);
	}
}

void Player::moveRight() {
	if (checkMoveRight()) {
		location.setXCoordinate(location.getXCoordinate() + 10);
	}
	else {
		location.setXCoordinate(500 - 50); // depends on width of window pane
	}
}

bool Player::checkMoveLeft() const {
	if (location.getXCoordinate() - 2 < 0) {
		return false;
	}
	else {
		return true;
	}
}

bool Player::checkMoveRight() const {
	if (location.getXCoordinate() + 50 >= 500 ) { // depends on width of window pane
		return false;
	}
	else {
		return true;
	}
}