#include "Circle.h"
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <cmath>

Circle::Circle(double radius, double x, double y, SDL_Color color)
    : radius(radius), x(x), y(y), color(color) {}

double Circle::getRadius() const { return this->radius; }

void Circle::setRadius(double r) { this->radius = r; }

double Circle::getX() const { return this->x; }

void Circle::setX(double x) { this->x = x; }

double Circle::getY() const { return this->y; }

void Circle::setY(double y) { this->y = y; }

SDL_Color Circle::getColor() const { return this->color; }

void Circle::setColor(SDL_Color color) { this->color = color; }

double Circle::getArea() const { return M_PI * radius * radius; }

double Circle::getCircumference() { return 2 * M_PI * radius; }

void Circle::DrawCircle(SDL_Renderer *renderer) const {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  for (int i = x - radius; i < x + radius; i++) {
    for (int j = y - radius; j < y + radius; j++) {
      double distance_sqrd = std::pow(x - i, 2) + pow(y - j, 2);
      if (distance_sqrd <= pow(radius, 2)) {
        SDL_RenderDrawPoint(renderer, i, j);
      }
    }
  }
}
