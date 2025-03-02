#include "DraggableCircle.h"
#include <SDL_events.h>

DraggableCircle::DraggableCircle(double radius, double x, double y)
    : Circle(radius, x, y) {}

void DraggableCircle::DrawCircle(SDL_Renderer *renderer, SDL_Color color)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_MOUSEMOTION && event.motion.state == 1)
    {
      this->setX(event.motion.x);
      this->setY(event.motion.y);
    }
  }
}

void DraggableCircle::HandleEvent(const SDL_Event &event)
{
  if (event.type == SDL_MOUSEMOTION && event.motion.state == SDL_BUTTON_LMASK)
  {
    this->setX(event.motion.x);
    this->setY(event.motion.y);
  }
}
