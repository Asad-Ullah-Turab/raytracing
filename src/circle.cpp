#include "circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::getRadius() { return radius; }

void Circle::setRadius(double r) { radius = r; }

double Circle::getArea() { return M_PI * radius * radius; }

double Circle::getCircumference() { return 2 * M_PI * radius; }
