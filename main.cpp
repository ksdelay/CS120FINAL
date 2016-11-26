//
// Created by Nick Medor on 11/26/2016
//

#include "Asteroid.h"
#include <iostream>
#include <string>
using namespace std;

void testClasses();
void directionGetters(Direction direction);
void asteroidGetters(Asteroid asteroid);

int main() {

	testClasses();

	cin.get();
}

void testClasses() {

	// Test Direction class:

	cout << "Testing the Direction class:\n";
	cout << endl;

	// Test default constructor and getters:

	Direction direction1;
	cout << "The default Direction should have an x and y component\n";
	cout << "of 0 and -1, respectively:\n";
	directionGetters(direction1);

	// Test non-default constructor and normalize:

	Direction direction2(1, 1);
	cout << "The non-default Direction should have an x and y\n";
	cout << "component of 0.707:\n";
	directionGetters(direction2);

	// Test setters:

	cout << "The values of x and y component should change from\n";
	cout << "0.707 to 0 and 1, respectively:\n";
	direction2.setXComponent(0);
	direction2.setYComponent(1);
	directionGetters(direction2);

	// Test setDirection:

	cout << "The values of x and y component should change from\n";
	cout << "0 and 1 to 0 and -1, respectively:\n";
	direction2.setDirection(0,-1);
	directionGetters(direction2);

	// Test Asteroid class:

	cout << "Testing the Asteroid class:\n";
	cout << endl;

	// Test default constructor and getters:

	Asteroid asteroid1;
	cout << "The default Asteroid should have an x and y location\n";
	cout << "of 0, a speed and size of 1, and a direction with an\n";
	cout << "x and y component of 0 and -1, respectively:\n";
	asteroidGetters(asteroid1);

	// Test non-default constructor:

	direction2.setDirection(1, 1);
	Asteroid asteroid2(100, 200, 4, 3, direction2);
	cout << "The non-default Asteroid should have an x location, y\n";
	cout << "location, speed, and size of 100, 200, 4, and 3, and a\n";
	cout << "direction with an x and y component of 0.707:\n";
	asteroidGetters(asteroid2);

	// Test setters:

	direction2.setDirection(1, 2);
	asteroid2.setDirection(direction2);
	asteroid2.setXLocation(50);
	asteroid2.setYLocation(60);
	asteroid2.setSize(2);
	asteroid2.setSpeed(1.5);
	cout << "The values x location, y location, speed, and size\n";
	cout << "should change to 50, 60, 1.5, and 2, respectively, and\n";
	cout << "the direction should change to have an x and y\n";
	cout << "component of 0.45 and 0.89, respectively:\n";
	asteroidGetters(asteroid2);

	// Test move:

	asteroid2.move();
	cout << "The x and y location should change accordingly:\n";
	asteroidGetters(asteroid2);

	// Test asteroid deflecting off right side of window pane:

	direction2.setDirection(1, 0);
	asteroid2.setDirection(direction2);
	asteroid2.setSpeed(5);
	asteroid2.setXLocation(249);
	cout << "The direction should change such that the x component\n";
	cout << "switches sign after the asteroid moves:\n";
	cout << endl;
	cout << "Before moving:\n";
	asteroidGetters(asteroid2);
	asteroid2.move();
	cout << "After moving:\n";
	asteroidGetters(asteroid2);

	// Test asteroid deflecting off left side of window pane:

	asteroid2.setXLocation(1);
	cout << "The direction should change such that the x component\n";
	cout << "switches sign after the asteroid moves:\n";
	cout << endl;
	cout << "Before moving:\n";
	asteroidGetters(asteroid2);
	asteroid2.move();
	cout << "After moving:\n";
	asteroidGetters(asteroid2);

	// Test respawn after falling off bottom of window pane:

	asteroid2.setYLocation(1);
	cout << "The y location should change to 250 after the move\n";
	cout << "method is called on the asteroid:\n";
	cout << endl;
	cout << "Before moving:\n";
	asteroidGetters(asteroid2);
	asteroid2.move();
	cout << "After moving:\n";
	asteroidGetters(asteroid2);

	// Test respawn after being hit:

	asteroid2.setSize(0);
	asteroid2.setYLocation(100);
	cout << "The y location should change to 250, the size should\n";
	cout << "change to 1, and the speed should increase after the\n";
	cout << "asteroid is hit:\n";
	cout << endl;
	cout << "Before hit:\n";
	asteroidGetters(asteroid2);
	asteroid2.hit();
	cout << "After hit:\n";
	asteroidGetters(asteroid2);

}

void directionGetters(Direction direction) {
	cout << "x Component: " << direction.getXComponent() << endl;
	cout << "y Component: " << direction.getYComponent() << endl;
	cout << endl;
}

void asteroidGetters(Asteroid asteroid) {
	cout << "x Location: " << asteroid.getXLocation() << endl;
	cout << "y Location: " << asteroid.getYLocation() << endl;
	cout << "Speed: " << asteroid.getSpeed() << endl;
	cout << "Size: " << asteroid.getSize() << endl;
	cout << "Direction fields:\n";
	directionGetters(asteroid.getDirection());
}