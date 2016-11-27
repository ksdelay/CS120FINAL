//
// Created by Nick Medor on 11/25/16
//

#include "Direction.h"
#include <cmath>

Direction::Direction() {
	xComponent = 0;
	yComponent = -1;
}

Direction::Direction(double xComponent, double yComponent) {
	setXComponent(xComponent);
	setYComponent(yComponent);
	normalize();
}

double Direction::getXComponent() const {
	return xComponent;
}

double Direction::getYComponent() const {
	return yComponent;
}

void Direction::setXComponent(double xComponent) {
	this->xComponent = xComponent;
}

void Direction::setYComponent(double yComponent) {
	this->yComponent = yComponent;
}

void Direction::setDirection(double xComponent, double yComponent) {
	setXComponent(xComponent);
	setYComponent(yComponent);
	normalize();
}

void Direction::normalize() {
	double angle = atan(yComponent / xComponent);
	if (xComponent < 0) {
		xComponent = -1 * abs(cos(angle));
	}
	else {
		xComponent = abs(cos(angle));
	}
	if (yComponent < 0) {
		yComponent = -1 * abs(sin(angle));
	}
	else {
		yComponent = abs(sin(angle));
	}
	if (abs(xComponent) < 0.001) {
		xComponent = 0;
	}
	if (abs(yComponent) < 0.001) {
		yComponent = 0;
	}
}