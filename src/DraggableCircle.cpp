#include "DraggableCircle.h"
#include <SDL_events.h>
#include <SDL_pixels.h>

DraggableCircle::DraggableCircle(double radius, double x, double y,
                                 SDL_Color color)
    : Circle(radius, x, y, color) {}

void DraggableCircle::HandleEvent(const SDL_Event &event) {
  if (event.type == SDL_MOUSEMOTION && event.motion.state == 1) {
    this->setX(event.motion.x);
    this->setY(event.motion.y);
  }
}
