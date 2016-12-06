//
// Created by Nick Medor on 11/26/2016
// Edited by Junchi Li on 11/27/2016
//

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

#include "Asteroid.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
#include "Bullet.h"
#include "Collectables.h"

GLdouble width, height;
int wd;

int triX;
int triY;
Point x(50.0, 50.0);
Player character("Kevin", x);
Asteroid asteroid;
using namespace std;



void testClasses();
void directionGetters(Direction direction);
void asteroidGetters(Asteroid asteroid);
void bulletGetters(Bullet bullet);
void playerGetters(Player player);
void pointsGetters(Points points);
void multiplierGetters(Multiplier multiplier);
void createSavedGames();
void loadGame();
void moveAsteroid();

void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void display()
{
	glViewport(0, 0, width, height);

	// do an orthographic parallel projection with the coordinate
	// system set to first quadrant, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, 0.0, height, -1.f, 1.f);



	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	glColor3f(0.1, 0.2, 0.3);
	glVertex2f(character.getXCoord(), character.getYCoord());
	glVertex2f(character.getXCoord()+100, character.getYCoord());
	glVertex2f(character.getXCoord()+50, character.getYCoord()+150);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 50, 0);
	glVertex3f(500, 50, 0);
	glVertex3f(500, 0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.28f, 0.23f, 0.54f);
	glVertex2i(asteroid.getLocation().getXCoordinate(), asteroid.getLocation().getYCoordinate());
	glVertex2i(asteroid.getLocation().getXCoordinate(), asteroid.getLocation().getYCoordinate() + asteroid.getSize() * 50);
	glVertex2i(asteroid.getLocation().getXCoordinate() + asteroid.getSize() * 50, asteroid.getLocation().getYCoordinate() + asteroid.getSize() * 50);
	glVertex2i(asteroid.getLocation().getXCoordinate() + asteroid.getSize() * 50, asteroid.getLocation().getYCoordinate());
	glEnd();

	glFlush();

	glutIdleFunc(moveAsteroid);

}

void moveAsteroid() {
	asteroid.move();
	glutPostRedisplay();
}

void kbd(unsigned char key, int x, int y)
{
	// escape
	if (key == 27) {
		glutDestroyWindow(wd);
		exit(0);
	}

	return;
}

void kbdS(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {
		character.moveLeft();
	}

	if (key == GLUT_KEY_RIGHT)
	{
		character.moveRight();
		
	}
	glutPostRedisplay();

	return;
}
int main(int argc, char** argv) {
	int decision;
	cout << "1 for text 2 for graphics:";
	cin >> decision;

	if (decision==2) {
		glutInit(&argc, argv);          // Initialize GLUT

		glutInitDisplayMode(GLUT_RGBA);
		width = 500;
		height = 500;
		triX = 50;
		triY = 50;
		asteroid.setDirection(Direction(1, -1));

		glutInitWindowSize((int)width, (int)height);
		glutInitWindowPosition(100, 500); // Position the window's initial top-left corner
										  /* create the window and store the handle to it */
		wd = glutCreateWindow("Fun with Drawing!" /* title */);


		glutDisplayFunc(display);       // Register callback handler for window re-paint event
		initGL();                       // Our own OpenGL initialization
										// register keyboard press event processing function
										// works for numbers, letters, spacebar, etc.
		glutKeyboardFunc(kbd);

		// register special event: function keys, arrows, etc.
		glutSpecialFunc(kbdS);

		glutMainLoop();
	}// Enter the event-processing loop
	
	testClasses();
	loadGame();

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
	direction2.setDirection(0, -1);
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
	Asteroid asteroid2(Point(100, 200), 4, 3, direction2);
	cout << "The non-default Asteroid should have an x location, y\n";
	cout << "location, speed, and size of 100, 200, 4, and 3, and a\n";
	cout << "direction with an x and y component of 0.707:\n";
	asteroidGetters(asteroid2);

	// Test setters:

	direction2.setDirection(1, 2);
	asteroid2.setDirection(direction2);
	asteroid2.setLocation(Point(50, 60));
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
	asteroid2.setLocation(Point(249, asteroid2.getLocation().getYCoordinate()));
	cout << "The direction should change such that the x component\n";
	cout << "switches sign after the asteroid moves:\n";
	cout << endl;
	cout << "Before moving:\n";
	asteroidGetters(asteroid2);
	asteroid2.move();
	cout << "After moving:\n";
	asteroidGetters(asteroid2);

	// Test asteroid deflecting off left side of window pane:

	asteroid2.setLocation(Point(1, asteroid2.getLocation().getYCoordinate()));
	cout << "The direction should change such that the x component\n";
	cout << "switches sign after the asteroid moves:\n";
	cout << endl;
	cout << "Before moving:\n";
	asteroidGetters(asteroid2);
	asteroid2.move();
	cout << "After moving:\n";
	asteroidGetters(asteroid2);

	// Test respawn after falling off bottom of window pane:

	asteroid2.setLocation(Point(asteroid2.getLocation().getXCoordinate(), 1));
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
	asteroid2.setLocation(Point(asteroid2.getLocation().getXCoordinate(), 100));
	cout << "The y location should change to 250, the size should\n";
	cout << "change to 1, and the speed should increase after the\n";
	cout << "asteroid is hit:\n";
	cout << endl;
	cout << "Before hit:\n";
	asteroidGetters(asteroid2);
	asteroid2.hit();
	cout << "After hit:\n";
	asteroidGetters(asteroid2);

	// Test Bullet class
	cout << "Testing the Bullet class:\n";
	cout << endl;

	// Test default constructor and getters
	Bullet bullet1;
	cout << "The default Bullet should have an x and y location\n";
	cout << "of 0:\n";
	bulletGetters(bullet1);

	// Test non-default constructor:
	Bullet bullet2(Point(10, 15));
	cout << "The non-default Bullet should have an x and y location\n";
	cout << "of 10 and 15:\n";
	bulletGetters(bullet2);

	// Test setters:
	bullet1.setLocation(Point(50, 60));
	cout << "The values x location and y location should change\n";
	cout << "to 50 and 60, respectively: \n";
	bulletGetters(bullet1);

	// Test move:

	bullet1.move();
	cout << "The y location should change accordingly:\n";
	bulletGetters(bullet1);

	// Test if bullet touch the top of window pane
	bullet2.setLocation(Point(bullet2.getLocation().getXCoordinate(),249));
	cout << "Before:\n";
	bulletGetters(bullet2);
	bullet2.move();
	cout << "After:\n";
	bulletGetters(bullet2);

	//Test player class
	cout << "Testing the player class:\n";
	cout << endl;

	//Test default constructor and getters
	Player player1;
	cout << "The default player should have an x and y location\n";
	cout << "of 0, a score of 0, and a user name of "":\n";
	playerGetters(player1);

	//Test non-default constructor
	Player player2("Jerry", Point(10, 15));
	cout << "The non-default player should have an x and y location\n";
	cout << "of 10 and 15, a score of 0, and a user name of 'Jerry':\n";
	playerGetters(player2);

	//Test setters
	Direction direction3(1, 0);
	player2.setUserName("Ben");
	player2.setScore(100);
	player2.setLocation(Point(50, 40));
	cout << "The player should have an x and y location of 50 and 40,\n";
	cout << "a score of 100, and a user name of 'Ben':\n";
	playerGetters(player2);

	//Test move
	cout << "Test move\n";
	cout << "The x location should change accordingly\n";
	player2.moveLeft();
	playerGetters(player2);
	player2.moveRight();
	player2.moveRight();
	playerGetters(player2);

	//Test move to right of window pane
	cout << "Test move to right of window pane\n";
	player2.setLocation(Point(250, player2.getLocation().getYCoordinate()));
	cout << "x location should not change\n";
	cout << "Before:\n";
	playerGetters(player2);
	player2.moveRight();
	cout << "After:\n";
	playerGetters(player2);

	//Test move to left of window pane
	cout << "Test move to left of window pane\n";
	player2.setLocation(Point(0, player2.getLocation().getYCoordinate()));
	cout << "x location should not change\n";
	cout << "Before:\n";
	playerGetters(player2);
	player2.moveLeft();
	cout << "After:\n";
	playerGetters(player2);

	// Test Collectables

	cout << "Testing the Collectables classes:\n" << endl;

	Direction testDirection(1, 1);
	Direction testDirection2(3, 3);
	Points Point10(Point(1, 1), testDirection);
	cout << "Printing the =x location of 1, y location of 1, and\n";
	cout << "direction components of 0.707 and 0.707, respectively:\n";
	pointsGetters(Point10);
	
	//Default constructor
	Points Point1;
	cout << "Printing the x location of 0, y location of 0, and\n";
	cout << "direction components of 0 and -1, respectively:\n";
	pointsGetters(Point1);
	
	//Set testers
	Point1.setLocation(Point(3, 3));
	Point1.setDirection(testDirection2);
	cout << "Printing the x location of 3, y location of 3, and\n";
	cout << "direction components of 0.707 and 0.707, respectively:\n";
	pointsGetters(Point1);

	Point1.move();
	cout << "New x and Y coordinates after 'move' is called:\n";
	pointsGetters(Point1);

	Multiplier dubMult(Point(1, 1), testDirection);
	cout << "Printing the x location of 1, y location of 1, and\n";
	cout << "direction components of 0.707 and 0.707, respectively:\n";
	multiplierGetters(dubMult);
	
	//Default constructor
	Multiplier defaultTest;
	cout << "Printing the x location of 0, y location of 0, and\n";
	cout << "direction components of 0 and -1, respectively:\n";
	multiplierGetters(defaultTest);

	//Set testers
	defaultTest.setLocation(Point(3, 3));
	defaultTest.setDirection(testDirection2);
	cout << "Printing the x location of 3, y location of 3, and\n";
	cout << "direction components of 0.707 and 0.707, respectively:\n";
	multiplierGetters(defaultTest);
}

void directionGetters(Direction direction) {
	cout << "x Component: " << direction.getXComponent() << endl;
	cout << "y Component: " << direction.getYComponent() << endl;
	cout << endl;
}

void asteroidGetters(Asteroid asteroid) {
	cout << "x Location: " << asteroid.getLocation().getXCoordinate() << endl;
	cout << "y Location: " << asteroid.getLocation().getYCoordinate() << endl;
	cout << "Speed: " << asteroid.getSpeed() << endl;
	cout << "Size: " << asteroid.getSize() << endl;
	cout << "Direction fields:\n";
	directionGetters(asteroid.getDirection());
}

void bulletGetters(Bullet bullet) {
	cout << "x Location: " << bullet.getLocation().getXCoordinate() << endl;
	cout << "y Location: " << bullet.getLocation().getYCoordinate() << endl << endl;
}

void playerGetters(Player player) {
	cout << "x Location: " << player.getLocation().getXCoordinate() << endl;
	cout << "y Location: " << player.getLocation().getYCoordinate() << endl;
	cout << "score: " << player.getScore() << endl;
	cout << "user name: " << player.getUserName() << endl << endl;
}

void pointsGetters(Points points) {
	cout << "x Location: " << points.getLocation().getXCoordinate() << endl;
	cout << "y Location: " << points.getLocation().getYCoordinate() << endl;
	cout << "Direction fields:\n";
	cout << "x Component: " << points.getDirection().getXComponent() << endl;
	cout << "y Component: " << points.getDirection().getYComponent() << endl << endl;
}

void multiplierGetters(Multiplier multiplier) {
	cout << "x Location: " << multiplier.getLocation().getXCoordinate() << endl;
	cout << "y Location: " << multiplier.getLocation().getYCoordinate() << endl;
	cout << "Direction fields:\n";
	cout << "x Component: " << multiplier.getDirection().getXComponent() << endl;
	cout << "y Component: " << multiplier.getDirection().getYComponent() << endl << endl;
}

void loadGame() {
	ifstream fileIn;
	fileIn.open("previousGames.txt");
	if (!(fileIn.is_open())) {
		createSavedGames();
	}
	fileIn.close();

	string response;
	Player player;
	cout << endl << "Would you like to load a previous game? (y/n)\n";
	cin >> response;
	if (response == "y") {
		cout << "Which game would you like to load? (enter the number)\n";
		ifstream fileIn;
		fileIn.open("previousGames.txt");
		string text;
		int count = 1;
		while (!fileIn.eof()) {
			getline(fileIn, text);
			cout << count << "\t" << text << "\t";
			getline(fileIn, text);
			cout << text << endl;
			count++;
		}
		fileIn.close();
		int gameChoice;
		cin >> gameChoice;
		string loadedUserName;
		string loadedPointsStr;
		fileIn.open("previousGames.txt");
		for (int i = 1; i < gameChoice; ++i) {
			getline(fileIn, text);
			getline(fileIn, text);
		}
		getline(fileIn, loadedUserName);
		getline(fileIn, loadedPointsStr);
		fileIn.close();
		int loadedPointsInt = atoi(loadedPointsStr.c_str());
		player.setUserName(loadedUserName);
		player.setScore(loadedPointsInt);
		cout << endl << "Your username and score have been set to " << player.getUserName();
		cout << " and\n" << player.getScore() << ", respectively." << endl;
		cin.get();
	}
	else {
		cout << endl << "Enter your name:\n";
		cin >> response;
		player.setUserName(response);
		ofstream fileOut;
		fileOut.open("previousGames.txt", ios_base::app);
		if (fileOut) {
			fileOut << "\n" << player.getUserName() << "\n" << player.getScore();
		}
		fileOut.close();
		cout << "Your new player has been saved.\n";
		cin.get();
	}
}

void createSavedGames() {
	Player player1("Bob", Point(50, 50));
	player1.setScore(100);
	Player player2("Sara", Point(60, 50));
	player2.setScore(50);
	ofstream fileOut;
	fileOut.open("previousGames.txt");
	if (fileOut) {
		fileOut << player1.getUserName() << "\n" << player1.getScore() << endl;
		fileOut << player2.getUserName() << "\n" << player2.getScore();
	}
	fileOut.close();
}