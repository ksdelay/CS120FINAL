//
// Created by Junchi Li on 11/15/2016.
//

#include "Player.h"

Player::Player() {
	points = 0;
	userName = "";
	xLocation = 0;
	yLocation = 0;
	speed = 1;
	direction.setDirection(1, 0);
}
Player::Player(string userName, double xLocation, double yLocation) {
	points = 0;
	setUserName(userName);
	setXLocation(xLocation);
	setYLocation(yLocation);
	bullet.setXLocation(xLocation);
	bullet.setYLocation(yLocation);
	speed = 1;
	direction.setDirection(1, 0);
	shootBullet = bullet;
}
string Player::getUserName() {
	return userName;
}
void Player::setUserName(string userName) {
	this->userName = userName;
}
int Player::returnPoints() {
	return points;
}
void Player::setPoints(int points) {
	this->points = points;
}
double Player::getXLocation() const {
	return xLocation;
}

double Player::getYLocation() const {
	return yLocation;
}

Direction Player::getDirection() const {
	return direction;
}

void Player::setXLocation(double xLocation) {
	this->xLocation = xLocation;
	bullet.setXLocation(xLocation);
	shootBullet = bullet;
}

void Player::setYLocation(double yLocation) {
	this->yLocation = yLocation;
	bullet.setYLocation(yLocation);
	shootBullet = bullet;
}

void Player::setDirection(Direction direction) {
	this->direction.setDirection(direction.getXComponent(), direction.getYComponent());
}
void Player::playerShoot() {
	shootBullet = bullet;
	shootBullet.setYLocation(bullet.getYLocation());
	shootBullet.setSize(1);
	shootBullet.BulletMove();
	setShootBullet(shootBullet);
}
void Player::playerMove() {
	if ((xLocation + speed*direction.getXComponent()) < 0 || (xLocation + speed*direction.getXComponent()) > 250) { 
		xLocation = xLocation;
		bullet.setXLocation(xLocation);
		shootBullet = bullet;
	}
	else if ((yLocation + speed*direction.getYComponent()) < 0 || (yLocation + speed*direction.getYComponent()) > 250) {
		yLocation = yLocation;
		bullet.setYLocation(yLocation);
		shootBullet = bullet;
	}
	else {
		yLocation = yLocation + speed*direction.getYComponent();
		xLocation = xLocation + speed*direction.getXComponent();
		bullet.setXLocation(xLocation);
		bullet.setYLocation(yLocation);
		shootBullet = bullet;
	}
}
Bullet Player::getBullet() const{
	return bullet;
}
void Player::setBullet(Bullet bullet) {
	this->bullet = Bullet(bullet.getXLocation(),bullet.getYLocation());
}
Bullet Player::getShootBullet() const{
	return shootBullet;
}
void Player::setShootBullet(Bullet bullet) {
	shootBullet = Bullet(bullet.getXLocation(), bullet.getYLocation());
}