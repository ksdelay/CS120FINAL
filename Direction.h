//
// Created by Nick Medor on 11/16/16
//


#ifndef Direction_h
#define Direction_h

class Direction {
public:

	Direction();

	Direction(double xComponent, double yComponent);

	double getXComponent() const;

	double getYComponent() const;

	void setXComponent(double xComponent);

	void setYComponent(double yComponent);

	void setDirection(double xComponent, double yComponent);

private:

	/*
	Normalize
	Requires: nothing
	Modifies: xComponent, yComponent
	Effects: changes the values of xComponent and yComponent such
		that they produce a unit direction length of 1
	Calls: abs from the Math library for determining each components
		sign
	Reason: The direction should be kept as a unit vector so that its
		magnitude will have no effect on the speed at which either a
		bullet or asteroid moves
	*/
	void normalize();

	double xComponent;
	double yComponent;

};

#endif