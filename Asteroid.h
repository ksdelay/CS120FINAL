//
// Created by Nick Medor on 11/15/16
//

#ifndef Asteroid_h
#define Asreroid_h

#include "Direction.h"

class Asteroid {
public:

	Asteroid();

	Asteroid(double xLocation, double yLocation, double speed, double size, Direction direction);

	double getXLocation() const;

	double getYLocation() const;

	double getSpeed() const;

	double getSize() const;

	Direction getDirection() const;

	void setXLocation(double xLocation);

	void setYLocation(double yLocation);

	void setSpeed(double speed);

	void setSize(double size);

	void setDirection(Direction direction);

	/*
	Move
	Requires: nothing
	Modifies: xLocation, yLocation
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

	double xLocation;
	double yLocation;
	double speed;
	double size;
	Direction direction;

};

#endif