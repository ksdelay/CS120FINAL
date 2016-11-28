#ifndef TEST_COLLECTABLES_H
#define TEST_COLLECTABLES_H
#include"Direction.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
class Collectables
{
public:
    /** Default constructor for Collectables
     * Requires: Nothing
     * Modifies: value of type
     * Effects: nothing
     */
    Collectables();
    /** non default constructor
     * Requires: String
     * Modifies: Types value
     * Effects: nothing
     */
    Collectables(string type);
    /**
     * abstract method to interact with player
     * Requires: nothing
     * Modifies: Nothing
     * Effects: nothing
     */
    virtual void interact() = 0;
    /**
     * Type Setter
     * Requires: string
     * Modifies: Type
     * Effects: nothing
     */
    void setType(string inType);
    /**
      *Type getter
     * Requires: nothing
     * Modifies: Nothing
     * Effects: returns type
     */
    string getType() const;
protected:
    string type;

};
class Points:public Collectables
{
public:
    /**
     * Defualt points constructor
     * Requires: nothing
     * Modifies: value, x and y location, size and speed
     * Effects: nothing
     */
    Points();
    /**
   * Defualt points constructor
   * Requires: value, x and y location, direction, speed and size
   * Modifies: value, x and y location, size and speed and direction
   * Effects: nothing
   */
    Points(int inValue, int inX, int inY, Direction inDirection, int inSpeed, int inSize);
    /**
     * Move method
     * Requires:Nothing
     * Modifies:X and Y location
     * Effects: moves point
     */
    void move();
    /**
     * Respawn method
     * Requires: nothing
     * Modifies: currently sets x and y to flat value, set to random in future
     * Effects: nothing
     */
    void respawn();
    //Getters
    int getValue() const;
    int getXLocation() const;
    int getYLocation() const;
    int getSpeed() const;
    int getSize() const;
    Direction getDirection() const;
    //Setters
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    void setSpeed(int inSpeed);
    void setSize(int size);
    void setDirection(Direction direction);
    void setValue(int inValue);
    virtual void interact() override;

protected:
    int value;
    int xLocation;
    int yLocation;
    Direction direction;
    int speed;
    int size;


};
class Multiplier: public Collectables
{
public:
    //Default constructor
    Multiplier();
    //Non defualt
    Multiplier(double inMult, int inX, int inY, Direction inDirection, int inSpeed, int inSize);
    void move();
    void respawn();
    //Getters
    double getValue() const;
    int getXLocation() const;
    int getYLocation() const;
    int getSpeed() const;
    int getSize() const;
    Direction getDirection() const;
    //setters
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    void setSpeed(int inSpeed);
    void setSize(int size);
    void setDirection(Direction direction);
    void setValue(int inValue);
    virtual void interact() override;
protected:
    double value;
    int xLocation;
    int yLocation;
    Direction direction;
    int speed;
    int size;

};
#endif //TEST_COLLECTABLES_H