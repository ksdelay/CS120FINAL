//
// Created by Nick Medor on 12/01/16
//

#include "Point.h"

Point::Point() {
	xCoordinate = 0;
	yCoordinate = 0;
}

Point::Point(double xCoordinate, double yCoordinate) {
	setXCoordinate(xCoordinate);
	setYCoordinate(yCoordinate);
}

double Point::getXCoordinate() const {
	return xCoordinate;
}

double Point::getYCoordinate() const {
	return yCoordinate;
}

void Point::setXCoordinate(double xCoordinate) {
	this->xCoordinate = xCoordinate;
}

void Point::setYCoordinate(double yCoordinate) {
	this->yCoordinate = yCoordinate;
}