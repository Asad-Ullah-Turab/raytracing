#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL_pixels.h>
#include <SDL_render.h>
class Circle {
private:
  double radius;
  double x;
  double y;

public:
  Circle(double radius, double x, double y);

  double getRadius();
  void setRadius(double r);

  double getX();
  void setX(double x);

  double getY();
  void setY(double y);

  double getArea();
  double getCircumference();

  virtual void DrawCircle(SDL_Renderer *renderer, SDL_Color color);
};

#endif // !CIRCLE_H
