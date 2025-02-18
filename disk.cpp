#include "disk.h"
#include <cmath>

Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

double Disk::getX(){return this->x;}
double Disk::getY(){return this->y;}
double Disk::getRadius(){return this->radius;}
void Disk::setX(double newx) {this->x = newx;}
void Disk::setY(double newy) {this->y = newy;}

void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

double Disk::distance(Disk& other){

    double dx = x - other.x;
    double dy = y - other.y;

    double d = sqrt(pow(dx,2) + pow(dy,2));

    return d;

}