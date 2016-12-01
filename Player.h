//
// Created by Junchi Li on 11/15/2016.
// Edited by Nick Medor on 12/01/2016 - replaced xLocation and
//		yLocation with Point location, removed speed and
//		direction fields, renamed points to score
//

#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H
#include<string>
#include"Point.h"
using namespace std;

class Player {

public:

	/*
	Default Constructor
	Requires: nothing
	Modifies: score, userName, location
	Effects: sets default field values
	Calls: nothing
	*/
	Player();

	/*
	Non-Default Constructor
	Requires: userName, location.
	Modifies: points, userName, location
	Effects: sets userName and location
	Calls: setUserName, setLocation
	*/
    Player(string userName, Point location);

	/*
	Score Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of score
	Calls: nothing
	*/
	int getScore() const;

	/*
	Username Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of userName
	Calls: nothing
	*/
    string getUserName() const;

	/*
	Location Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns location
	Calls: nothing
	*/
	Point getLocation() const;

	/*
	Score Setter
	Requires: nothing
	Modifies: points
	Effects: sets the score
	Calls: nothing
	*/
	void setScore(int score);

	/*
	Username Setter
	Requires: nothing
	Modifies: userName
	Effects: sets the userName
	Calls: nothing
	*/
	void setUserName(string userName);

	/*
	Location Setter
	Requires: nothing
	Modifies: location
	Effects: sets location
	Calls: nothing
	*/
	void setLocation(Point location);

	/*
	Shoot
	Requires: not sure
	Modifies: not sure
	Effects: not sure
	Calls: not sure
	*/
    void shoot();

	/*
	Move Left
	Requires: nothing
	Modifies: location
	Effects: make player move left
	Calls: checkMoveLeft
	*/
    void moveLeft();

	/*
	Move Right
	Requires: nothing
	Modifies: location
	Effects: make player move right
	Calls: checkMoveRight
	*/
	void moveRight();

private:

    int score;
    string userName;
	Point location;

	/*
	Check Move left
	Requires: nothing
	Modifies: nothing
	Effects: checks to see if player can move left
	Calls: nothing
	*/
	bool checkMoveLeft() const;

	/*
	Check Move Right
	Requires: nothing
	Modifies: nothing
	Effects: checks to see if player can move right
	Calls: nothing
	*/
	bool checkMoveRight() const;

};

#endif //FINAL_PLAYER_H
