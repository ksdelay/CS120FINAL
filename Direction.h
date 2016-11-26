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

	void normalize();

	double xComponent;
	double yComponent;

};



#endif
