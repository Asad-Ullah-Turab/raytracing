#include "DraggableCircle.h"
#include <SDL_render.h>
#include <vector>

class Bulb : public DraggableCircle {
private:
  int rayCount;
  int rayThickness;
  SDL_Color rayColor;

public:
  Bulb(double radius, double x, double y, SDL_Color circleColor, int rayCount,
       int rayThickness, SDL_Color rayColor);

  int getRayCount() const;
  void setRayCount(int rayCount);

  int getRayThickness() const;
  void setRayThickness(int rayThickness);

  SDL_Color getRayColor();
  void setRayColor(SDL_Color color);

  void HandleEvent(const SDL_Event &event) override;
  void CastRays(SDL_Renderer *renderer,
                const std::vector<Circle *> &circles) const;
};
