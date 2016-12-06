//
// Created by Junchi Li on 11/15/2016.
// Edited by Nick Medor on 12/01/2016 - replaced xLocation and
//		yLocation with Point location, removed speed, size, and
//		direction fields
//

#ifndef BULLET_H
#define BULLET_H
#include "Point.h"

class Bullet {
public:

	/*
	Default Constructor
	Requires: nothing
	Modifies: location
	Effects: sets default location
	Calls: nothing
	*/
	Bullet();

	/*
	Non-Default Constructor
	Requires: Point location object
	Modifies: location
	Effects: sets location to input Point
	Calls: setLocation
	*/
	Bullet(Point location);

	/*
	Location Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns location
	Calls: nothing
	*/
	Point getLocation() const;
	/*
	X coord Getter
	Requires: Nothing
	Modifies:Nothing
	Effects: Returns X coordinate
	Calls:
	points x coord getter
	*/
	double getXCoord() const;

	/*
	Y coord Getter
	Requires: Nothing
	Modifies:Nothing
	Effects: Returns Y coordinate
	Calls:
	points Y coord getter
	*/
	double getYCoord() const;
	/*
	Score Setter
	Requires: nothing
	Modifies: points
	Effects: sets the score
	Calls: nothing
	*/

	/*
	X coord setter
	Requires:double X
	Modifies:locations x Coord
	Effects:Changes X Coord to given double
	Calls: Location x coord setter
	*/
	void setXCoord(double x);

	/*
	X coord setter
	Requires:double X
	Modifies:locations x Coord
	Effects:Changes X Coord to given double
	Calls: Location x coord setter
	*/
	void setYCoord(double y);

	/*
	Location Setter
	Requires: nothing
	Modifies: location
	Effects: sets location to input Point
	Calls: nothing
	*/
	void setLocation(Point location);

	/*
	Move
	Requires: nothing
	Modifies: location
	Effects: increase yCoordinate of location so that the
		bullet moves up the screen
	Calls: nothing
	*/
	void move();

	/*
	Hit
	Requires: nothing
	Modifies: not sure yet
	Effects: not sure yet
	Calls: nothing
	*/
	void hit();

private:

	Point location;

};

#endif // !BULLET_H

