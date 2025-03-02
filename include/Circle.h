#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_render.h>
#include <vector>
class Circle {
private:
  double radius;
  double x;
  double y;
  SDL_Color color;

public:
  Circle(double radius, double x, double y, SDL_Color color);

  double getRadius() const;
  void setRadius(double r);

  double getX() const;
  void setX(double x);

  double getY() const;
  void setY(double y);

  SDL_Color getColor() const;
  void setColor(SDL_Color color);

  double getArea() const;
  double getCircumference();

  virtual void DrawCircle(SDL_Renderer *renderer) const;
  virtual void HandleEvent(const SDL_Event &event) {};
};

#endif // !CIRCLE_H
