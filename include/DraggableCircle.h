#ifndef DRAGGABLE_CIRCLE_H
#define DRAGGABLE_CIRCLE_H

#include "Circle.h"
#include <SDL_events.h>

class DraggableCircle : Circle {
public:
  DraggableCircle(double radius, double x, double y);
  void DrawCircle(SDL_Renderer *renderer, SDL_Color color) override;
  void HandleEvent(const SDL_Event &event);
};

#endif // !DRAGGABLE_CIRCLE_H
