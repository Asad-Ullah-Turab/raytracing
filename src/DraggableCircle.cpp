#include "DraggableCircle.h"
#include <SDL_events.h>
#include <SDL_pixels.h>

DraggableCircle::DraggableCircle(double radius, double x, double y,
                                 SDL_Color color)
    : Circle(radius, x, y, color) {}

void DraggableCircle::HandleEvent(const SDL_Event &event) {
  // Checkt if event is mount drag
  if ((event.type == SDL_MOUSEMOTION && event.motion.state == 1) && (true)) {

    // Check if the mouse dragged inside the circle
    double distance_sqrd =
        std::pow(getX() - event.motion.x, 2) + pow(getY() - event.motion.y, 2);
    if (distance_sqrd <= pow(getRadius(), 2)) {
      this->setX(event.motion.x);
      this->setY(event.motion.y);
    }
  }
}
