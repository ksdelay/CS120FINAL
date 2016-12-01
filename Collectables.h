//
// Created by Kevin Delay on 11/27/2016
// Edited by Nick Medor on 12/01/2016
//

#ifndef TEST_COLLECTABLES_H
#define TEST_COLLECTABLES_H
#include"Point.h"
#include"Direction.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Collectables {

public:

	/* 
	Default Constructor
	Requires: nothing
	Modifies: location, direction
	Effects: sets default values to fields
	*/
	Collectables();

	/*
	Non-default Constructor
	Requires: Point, Direction
	Modifies: location, direction
	Effects: sets fields to inputs
	Calls: setLocation, setDirection
	*/
	Collectables(Point location, Direction direction);

	/*
	Location Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns location
	Calls: nothing
	*/
	Point getLocation() const;

	/*
	Direction Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns direction
	Calls: nothing
	*/
	Direction getDirection() const;

	/*
	Location Setter
	Requires: Point
	Modifies: location
	Effects: sets location
	Calls: nothing
	*/
	void setLocation(Point location);

	/*
	Direction Setter
	Requires: Direction
	Modifies: direction
	Effects: sets direction
	Calls: nothing
	*/
	void setDirection(Direction direction);

	/*
	Interact
	Requires: nothing
	Modifies: nothing
	Effects: nothing
	Calls: nothing
	*/
	virtual void interact() = 0;

	/*
	Move
	Requires: nothing
	Modifies: location
	Effects: moves collectable down the screen depending
		on its direction; changes xComponent of direction
		if collectable hits sides of window
	Calls: checkMove
	*/
	void move();

	/*
	Respawn
	Requires: nothing
	Modifies: currently sets x and y to flat value, set to random in future
	Effects: nothing
	*/
	void respawn();

protected:

	Point location;
	Direction direction;

	/*
	Check Move
	Requires: nothing
	Modifies: nothing
	Effects: checks collectables location to see if it will
		still be in the window after a move
	*/
	bool checkMove() const;

};

class Points:public Collectables {

public:

	/*
	Defualt Constructor
	Requires: nothing
	Modifies: location, direction
	Effects: sets deafult field values
	Calls: nothing
	*/
    Points();

	/*
	Non-defualt Constructor
	Requires: Point, Direction
	Modifies: location, direction
	Effects: sets fields to inputs
	Calls: nothing
	*/
	Points(Point location, Direction direction);

	virtual void interact() override;

};

class Multiplier: public Collectables {

public:

	/*
	Default Constructor
	Requires: nothing
	Modifies: location, direction
	Effects: sets default values to fields
	Calls: nothing
	*/
	Multiplier();

	/*
	Non-default Constructor
	Requires: Point, Direction
	Modifies: location, direction
	Effects: sets fields to inputs
	Calls: setLocation, setDirection
	*/
	Multiplier(Point location, Direction direction);

	virtual void interact() override;

};
#endif //TEST_COLLECTABLES_H