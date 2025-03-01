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

  double getArea();

  double getCircumference();

  void DrawCircle(SDL_Renderer *renderer, SDL_Color color);
};
