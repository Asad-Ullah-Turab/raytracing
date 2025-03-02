#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_render.h>
class Circle {
private:
  double radius;
  double x;
  double y;
  SDL_Color color;

public:
  Circle(double radius, double x, double y, SDL_Color color);

  double getRadius();
  void setRadius(double r);

  double getX();
  void setX(double x);

  double getY();
  void setY(double y);

  double getArea();
  double getCircumference();

  void DrawCircle(SDL_Renderer *renderer) const;

  virtual void HandleEvent(const SDL_Event &event) {};
};

#endif // !CIRCLE_H
