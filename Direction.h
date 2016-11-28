//
// Created by Nick Medor on 11/16/16
//


#ifndef Direction_h
#define Direction_h

class Direction {
public:

	/*
	Default Constructor
	Requires: nothing
	Modifies: xComponent, yComponent
	Effects: sets default values to xComponent and yComponent
	Calls: nothing
	*/
	Direction();

	/*
	Non-Default Constructor
	Requires: double values for x and y component
	Modifies: xComponent, yComponent
	Effects: sets xComponent and yComponent to corresponing inputs
	Calls: setXComponent, setYComponent, normalize
	*/
	Direction(double xComponent, double yComponent);

	/*
	X Component Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of xComponent
	Calls: nothing
	*/
	double getXComponent() const;

	/*
	Y Component Getter
	Requires: nothing
	Modifies: nothing
	Effects: returns the value of yComponent
	Calls: nothing
	*/
	double getYComponent() const;

	/*
	X Component Setter
	Requires: double value for x component
	Modifies: xComponent
	Effects: sets the value of xComponent
	Calls: normalize
	*/
	void setXComponent(double xComponent);

	/*
	Y Component Setter
	Requires: double value for y component
	Modifies: yComponent
	Effects: sets the value of yComponent
	Calls: normalize
	*/
	void setYComponent(double yComponent);

	/*
	Direction Setter
	Requires: double values for x and y component
	Modifies: xComponent, yComponent
	Effects: sets the value of xComponent and yComponent
	Calls: normalize
	Reason: it's easier to set both the x and y components and
		then normalize rather than set each individually
	*/
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