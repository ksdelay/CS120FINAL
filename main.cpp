//
// Created by Nick Medor on 11/26/2016
// Edited by Junchi Li on 11/27/2016
//

#include "Asteroid.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
using namespace std;

void testClasses();
void directionGetters(Direction direction);
void asteroidGetters(Asteroid asteroid);
void bulletGetters(Bullet bullet);
void playerGetters(Player player);
void testFileIO();

int main() {

	testClasses();
	//testFileIO();
	
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
		player.setPoints(loadedPointsInt);
		cout << endl << "Your username and score have been set to " << player.getUserName();
		cout << " and\n" << player.returnPoints() << ", respectively." << endl;
		cin.get();
	}
	else {
		cout << endl << "Enter your name:\n";
		cin >> response;
		player.setUserName(response);
		ofstream fileOut;
		fileOut.open("previousGames.txt", ios_base::app);
		if (fileOut) {
			fileOut << player.getUserName() << "\n" << player.returnPoints();
		}
		fileOut.close();
		cout << "Your new player has been saved.\n";
		cin.get();
	}
	
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

	// Test Bullet class
	cout << "Testing the Bullet class:\n";
	cout << endl;

	// Test default constructor and getters
	Bullet bullet1;
	cout << "The default Bullet should have an x and y location\n";
	cout << "of 0, a speed and size of 5 and 0, and a direction with an\n";
	cout << "x and y component of 0 and 1 , respectively:\n";
	bulletGetters(bullet1);

	// Test non-default constructor:
	Bullet bullet2(10, 15);
	cout << "The non-default Bullet should have an x and y location\n";
	cout << "of 10 and 15, a speed and size of 5 and 1, and a direction with an\n";
	cout << "x and y component of 0 and 1 , respectively:\n";
	bulletGetters(bullet2);

	// Test setters:
	bullet1.setXLocation(50);
	bullet1.setYLocation(60);
	bullet1.setSize(2);
	bullet1.setSpeed(1.5);
	cout << "The values x location, y location, speed, and size\n";
	cout << "should change to 50, 60, 1.5, and 2, and\n";
	cout << "the direction x and y should be 0 and 1,respectively: \n";
	bulletGetters(bullet1);

	// Test move:

	bullet1.BulletMove();
	cout << "The x and y location should change accordingly:\n";
	bulletGetters(bullet1);

	// Test if bullet touch the top of window pane
	bullet2.setYLocation(249);
	cout << "The size of the bullet should become 0:\n";
	cout << "Before:\n";
	bulletGetters(bullet2);
	bullet2.BulletMove();
	cout << "After:\n";
	bulletGetters(bullet2);

	//Test player class
	cout << "Testing the player class:\n";
	cout << endl;

	//Test default constructor and getters
	Player player1;
	cout << "The default player should have an x and y location\n";
	cout << "of 0, a points of 0,a user name of "" and a direction with an\n";
	cout << "x and y component of 1 and 0 , respectively:\n";
	playerGetters(player1);

	//Test non-default constructor
	Player player2("Jerry",10,15);
	cout << "The default player should have an x and y location\n";
	cout << "of 10 and 15, a points of 0,a user name of 'Jerry' and a direction with an\n";
	cout << "x and y component of 1 and 0 , respectively:\n";
	playerGetters(player2);

	//Test setters
	Direction direction3(1, 0);
	player2.setUserName("Ben");
	player2.setDirection(direction3);
	player2.setPoints(100);
	player2.setXLocation(50);
	player2.setYLocation(40);
	cout << "The default player should have an x and y location\n";
	cout << "of 50 and 40, a points of 100,a user name of 'Ben' and a direction with an\n";
	cout << "x and y component of 1 and 0 , respectively:\n";
	playerGetters(player2);

	//Test shoot
	cout << "Test shoot\n";
	cout << "Before:\n";
	playerGetters(player2);
	cout << "shoot bullet:\n";
	bulletGetters(player2.getShootBullet());
	cout << "After:\n";
	cout << "Shoot Bullet's x and y location should change accordingly\n";
	player2.playerShoot();
	playerGetters(player2);
	cout << "shoot bullet:\n";
	bulletGetters(player2.getShootBullet());

	//Test move
	cout << "Test move\n";
	cout << "The x and y location should change accordingly\n";
	player2.playerMove();
	playerGetters(player2);

	//Test move to right of window pane
	cout << "Test move to right of window pane\n";
	player2.setXLocation(250);
	cout << "x location should not change\n";
	cout << "Before:\n";
	playerGetters(player2);
	player2.playerMove();
	cout << "After:\n";
	playerGetters(player2);

	//Test move to left of window pane
	cout << "Test move to left of window pane\n";
	Direction direction4(-1,0);
	player2.setDirection(direction4);
	player2.setXLocation(0);
	cout << "x location should not change\n";
	cout << "Before:\n";
	playerGetters(player2);
	player2.playerMove();
	cout << "After:\n";
	playerGetters(player2);

	//Test move to top of window pane
	cout << "Test move to top of window pane\n";
	Direction direction5(0, 1);
	player2.setDirection(direction5);
	player2.setYLocation(250);
	cout << "y location should not change\n";
	cout << "Before:\n";
	playerGetters(player2);
	player2.playerMove();
	cout << "After:\n";
	playerGetters(player2);

	//Test move to bottom of window pane
	cout << "Test move to bottom of window pane\n";
	Direction direction6(0, -1);
	player2.setDirection(direction6);
	player2.setYLocation(0);
	cout << "y location should not change\n";
	cout << "Before:\n";
	playerGetters(player2);
	player2.playerMove();
	cout << "After:\n";
	playerGetters(player2);

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

void bulletGetters(Bullet bullet) {
	cout << "x Location: " << bullet.getXLocation() << endl;
	cout << "y Location: " << bullet.getYLocation() << endl;
	cout << "Speed: " << bullet.getSpeed() << endl;
	cout << "Size: " << bullet.getSize() << endl;
	cout << "Bullet Direction fields:\n";
	directionGetters(bullet.getDirection());
}

void playerGetters(Player player) {
	cout << "x Location: " << player.getXLocation() << endl;
	cout << "y Location: " << player.getYLocation() << endl;
	cout << "points: " << player.returnPoints() << endl;
	cout << "user name: " << player.getUserName() << endl;
	cout << "Direction fields:\n";
	directionGetters(player.getDirection());
	cout << "Bullet fields:\n";
	bulletGetters(player.getBullet());
}

void testFileIO() {
	Player player1("Bob", 50, 50);
	player1.setPoints(100);
	Player player2("Sara", 60, 50);
	player2.setPoints(50);
	ofstream fileOut;
	fileOut.open("previousGames.txt");
	if (fileOut) {
		fileOut << player1.getUserName() << "\n" << player1.returnPoints() << endl;
		fileOut << player2.getUserName() << "\n" << player2.returnPoints();
	}
	fileOut.close();
	/*
	cout << endl << "Highscores:\n" << endl;

	ifstream fileIn("highscores.txt");
	while (fileIn) {
		string text;
		getline(fileIn, text);
		cout << text << endl;
	}
	fileIn.close();
	*/
}