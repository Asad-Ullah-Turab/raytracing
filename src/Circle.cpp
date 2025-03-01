#include "Circle.h"
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <cmath>

Circle::Circle(double radius, double x, double y)
    : radius(radius), x(x), y(y) {}

double Circle::getRadius() { return radius; }

void Circle::setRadius(double r) { radius = r; }

double Circle::getArea() { return M_PI * radius * radius; }

double Circle::getCircumference() { return 2 * M_PI * radius; }

void Circle::DrawCircle(SDL_Renderer *renderer, SDL_Color color) {
  SDL_Rect rect{20, 20, (int)radius, (int)radius};
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}
