//
// Created by Nick Medor on 11/16/16
//


#ifndef Point_h
#define Point_h

class Point {
public:

	/*
	Default Constructor
	Requires: nothing
	Modifies: xCoordinate, yCoordinate
	Effects: sets default values to xCoordinate and yCoordinate
	Calls: nothing
	*/
	Point();

	/*
	Non-Default Constructor
	Requires: double values for x and y coordinate
	Modifies: xCoordinate, yCoordinate
	Effects: sets xCoordinate and yCoordinate to corresponing inputs
	Calls: setXCoordinate, setYCoordinate
	*/
	Point(double xCoordinate, double yCoordinate);

	/*
	X Coordinate Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of xCoordinate
	Calls: nothing
	*/
	double getXCoordinate() const;

	/*
	Y Coordinate Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of yCoordinate
	Calls: nothing
	*/
	double getYCoordinate() const;

	/*
	X Coordinate Setter
	Requires: double value for x coordinate
	Modifies: xCoordinate
	Effects: sets the value of xCoordinate
	Calls: nothing
	*/
	void setXCoordinate(double xComponent);

	/*
	Y Coordinate Setter
	Requires: double value for y coordinate
	Modifies: yCoordinate
	Effects: sets the value of yCoordinate
	Calls: nothing
	*/
	void setYCoordinate(double yComponent);

private:

	double xCoordinate;
	double yCoordinate;

};

#endif
