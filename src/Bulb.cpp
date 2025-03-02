#include "Bulb.h"
#include "DraggableCircle.h"
#include "Global.h"
#include <SDL_pixels.h>
#include <SDL_render.h>
#include <algorithm>

Bulb::Bulb(double radius, double x, double y, SDL_Color cirlceColor,
           int rayCount, int rayThickness, SDL_Color rayColor)
    : DraggableCircle(radius, x, y, cirlceColor), rayCount(rayCount),
      rayThickness(rayThickness), rayColor(rayColor) {}

int Bulb::getRayCount() const { return this->rayCount; }

void Bulb::setRayCount(int rayCount) { this->rayCount = rayCount; }

int Bulb::getRayThickness() const { return this->rayThickness; }

void Bulb::setRayThickness(int rayThickness) {
  this->rayThickness = rayThickness;
}

SDL_Color Bulb::getRayColor() { return this->rayColor; }
void Bulb::setRayColor(SDL_Color color) { this->rayColor = color; }

void Bulb::HandleEvent(const SDL_Event &event) {
  DraggableCircle::HandleEvent(event);
}

void Bulb::CastRays(SDL_Renderer *renderer,
                    const std::vector<Circle *> &circles) const {
  double angleStep = 360.0 / rayCount;
  SDL_SetRenderDrawColor(renderer, getColor().r, getColor().g, getColor().b,
                         getColor().a);

  for (int i = 0; i < rayCount; i++) {
    double angle = i * angleStep * M_PI / 180.0;
    double dirX = cos(angle);
    double dirY = sin(angle);

    double endX = getX();
    double endY = getY();

    // Extend ray until it reaches the screen boundary
    double tMin = std::numeric_limits<double>::infinity();

    if (dirX > 0)
      tMin = std::min(tMin, (SCREEN_WIDTH - getX()) / dirX);
    else if (dirX < 0)
      tMin = std::min(tMin, -getX() / dirX);

    if (dirY > 0)
      tMin = std::min(tMin, (SCREEN_HEIGHT - getY()) / dirY);
    else if (dirY < 0)
      tMin = std::min(tMin, -getY() / dirY);

    // Check intersection with all circles
    for (const auto &circle : circles) {
      double cx = circle->getX();
      double cy = circle->getY();
      double r = circle->getRadius();

      // Quadratic formula coefficients
      double A = dirX * dirX + dirY * dirY;
      double B = 2 * (dirX * (getX() - cx) + dirY * (getY() - cy));
      double C =
          (getX() - cx) * (getX() - cx) + (getY() - cy) * (getY() - cy) - r * r;

      double discriminant = B * B - 4 * A * C;

      if (discriminant >= 0) { // Ray intersects circle
        double t1 = (-B - sqrt(discriminant)) / (2 * A);
        double t2 = (-B + sqrt(discriminant)) / (2 * A);

        if (t1 > 0 && t1 < tMin)
          tMin = t1;
        if (t2 > 0 && t2 < tMin)
          tMin = t2;
      }
    }

    // Compute final ray endpoint
    endX = getX() + tMin * dirX;
    endY = getY() + tMin * dirY;

    // Round to avoid precision issues
    endX = round(endX);
    endY = round(endY);

    // std::cout << "Ray ends at: " << endX << " , " << endY << std::endl;

    // Draw the ray
    SDL_SetRenderDrawColor(renderer, rayColor.r, rayColor.g, rayColor.b,
                           rayColor.a);
    SDL_RenderDrawLine(renderer, static_cast<int>(getX()),
                       static_cast<int>(getY()), static_cast<int>(endX),
                       static_cast<int>(endY));
  }
}
