//
// Created by Nick Medor on 11/15/16
//

#ifndef Asteroid_h
#define Asreroid_h

#include "Direction.h"
#include "Point.h"

class Asteroid {
public:

	/*
	Default Constructor
	Requires: nothing
	Modifies: location, speed, size, direction
	Effects: sets default values for all fields
	Calls: nothing
	*/
	Asteroid();

	/*
	Non-Default Constructor
	Requires: double values for x and y locations, speed, size, and
		a direction
	Modifies: location, speed, size, direction
	Effects: sets input values for all fields
	Calls: setLocation, setSpeed, setSize, setDirection
	*/
	Asteroid(Point location, double speed, double size, Direction direction);

	/*
	Location Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns location
	Calls: nothing
	*/
	Point getLocation() const;

	/*
	Speed Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of speed
	Calls: nothing
	*/
	double getSpeed() const;

	/*
	Size Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of size
	Calls: nothing
	*/
	double getSize() const;

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
	Requires: Point object for location
	Modifies: location
	Effects: sets location
	Calls: nothing
	*/
	void setLocation(Point location);

	/*
	Speed Setter
	Requires: double value for speed
	Modifies: speed
	Effects: sets the value of speed
	Calls: nothing
	*/
	void setSpeed(double speed);

	/*
	Size Setter
	Requires: double value for size
	Modifies: size
	Effects: sets the value of size
	Calls: nothing
	*/
	void setSize(double size);

	/*
	Direction Setter
	Requires: Direction object for direction
	Modifies: direction
	Effects: sets the fields within direction
	Calls: nothing
	*/
	void setDirection(Direction direction);

	/*
	Move
	Requires: nothing
	Modifies: location
	Effects: Provides the movement that animates the asteroid so
		that it is falling towards the player by changing its x
		and y coordinates accordingly based off of its speed and
		direction; Changes sign of its direction's x component if
		it reaches a side boundary of the window pane
	Calls: Can call respawn; setXComponent and getXComponent of
		direction class
	Reason: The asteroids will need to animate without any user
		input; this method allows for easily controlling this
		behavior and can be called periodically to create the
		desired falling behavior of the asteroids.
	*/
	void move();

	/*
	Hit
	Requires: The asteroid should have been hit by a bullet
	Modifies: size, speed (possibly)
	Effects: Reduces the size of the asteroid or calls respawn
		if the asteroid cannot be further reduced in size in
		which case it will also increase the speed of the asteroid
	Calls: Can call respawn
	Reason: The asteroid is allowed to be hit multiple times by
		bullets until it can no longer be reduced in size. Each
		time it is completely shot down by the player it increases
		its speed to increase the difficulty of the game.
	*/
	void hit();

	/*
	Respawn
	Requires: The asteroid should have fallen out from the bottom
		of the playing area or have been shot down by the player
	Modifies: yLocation
	Effects: sets yLocation to a value above the top of the window
		pane
	Calls: nothing
	Reason: There will be a set number of asteroids generated each
		game with the asteroids falling down towards the player.
		The asteroid should move to some location above the window
		pane to begin falling again after reaching the bottom of
		the window pane or after being shot down to keep the game
		going.
	*/
	void respawn();

private:

	Point location;
	double speed;
	double size;
	Direction direction;

};

#endif