#include "Collectables.h"
Collectables::Collectables() {
    type = "";
}

Collectables::Collectables(string typeIn){
    type = typeIn;
}
void Collectables::setType(string inType) {
    type = inType;
}
string Collectables::getType() const {
    return(type);
}
void Collectables::interact() {

}


Points::Points(){
    xLocation = 0;
    yLocation = 0;
    value = 0;
    size = 0;
    speed = 0;
    setType("Points");
}

Points::Points(int inValue, int inX, int inY, Direction inDirection, int inSpeed, int inSize){
    value = inValue;
    setType("Points");
    setXLocation(inX);
    setYLocation(inY);
    setSpeed(inSpeed);
    setSize(inSize);
    setDirection(inDirection);

}
void Points::move()
{
    if ((xLocation + speed*direction.getXComponent()) <= 0 || (xLocation + speed*direction.getXComponent()) >= 250) { // the 250 value is dependent on the size of the game's window pane
        direction.setXComponent(direction.getXComponent()*-1);
    }
    if ((yLocation - speed) < -5) {
        respawn();
    }
    else {
        yLocation = yLocation - speed;
        xLocation = xLocation + speed*direction.getXComponent();
    }
}
void Points::respawn() {

}
int Points::getValue() const {
    return(value);
}
int Points::getXLocation() const{
    return(xLocation);
}
int Points::getYLocation() const{
    return(yLocation);
}
int Points::getSpeed() const{
    return(speed);
}
int Points::getSize() const{
    return(size);
}
Direction Points::getDirection() const{
    return(direction);
}
void Points::setXLocation(int inX) {
    xLocation = inX;

}
void Points::setYLocation(int inY) {
    yLocation = inY;

}
void Points::setSpeed(int inSpeed){
    speed = inSpeed;
}
void Points::setSize(int inSize){
    size = inSize;
}
void Points::setDirection(Direction inDirection){
    direction.setDirection(inDirection.getXComponent(), inDirection.getYComponent());
}

void Points::setValue(int inValue) {
    value = inValue;
}

void Points::interact() {
    cout<<"1";

}


Multiplier::Multiplier(){
    xLocation = 0;
    yLocation = 0;
    value = 0;
    size = 0;
    speed = 0;
    setType("Mult");
}

Multiplier::Multiplier(double inMult, int inX, int inY, Direction inDirection, int inSpeed, int inSize){
    value = inMult;
    setType("Mult");
    setXLocation(inX);
    setYLocation(inY);
    setSpeed(inSpeed);
    setSize(inSize);
    setDirection(inDirection);

}
void Multiplier::move()
{
    if ((xLocation + speed*direction.getXComponent()) <= 0 || (xLocation + speed*direction.getXComponent()) >= 250) { // the 250 value is dependent on the size of the game's window pane
        direction.setXComponent(direction.getXComponent()*-1);
    }
    if ((yLocation - speed) < -5) {
        respawn();
    }
    else {
        yLocation = yLocation - speed;
        xLocation = xLocation + speed*direction.getXComponent();
    }
}
void Multiplier::respawn() {
}

double Multiplier::getValue() const {
    return(value);
}
int Multiplier::getXLocation() const {
    return(xLocation);
}
int Multiplier::getYLocation() const {
    return(yLocation;
}
int Multiplier::getSpeed() const {
    return(speed);
}
int Multiplier::getSize() const {
    return(size);
}
Direction Multiplier::getDirection() const {
    return(direction);
}
void Multiplier::setXLocation(int inX)  {
    xLocation = inX;
}
void Multiplier::setYLocation(int inY)  {
    xLocation = inY;
}
void Multiplier::setSpeed(int inSpeed)  {
    speed = inSpeed;
}
void Multiplier::setSize(int inSize)  {
    size = inSize;
}
void Multiplier::setDirection(Direction inDirection)  {
    direction.setDirection(inDirection.getXComponent(), inDirection.getYComponent());

}
void Multiplier::setValue(int inValue){
    value = inValue;
}
void Multiplier::interact() {
    cout<<"1";
}
