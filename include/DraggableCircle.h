#ifndef DRAGGABLE_CIRCLE_H
#define DRAGGABLE_CIRCLE_H

#include "Circle.h"
#include <SDL_events.h>
#include <SDL_pixels.h>

class DraggableCircle : public Circle {
public:
  DraggableCircle(double radius, double x, double y, SDL_Color color);
  void HandleEvent(const SDL_Event &event) override;
};

#endif // !DRAGGABLE_CIRCLE_H
