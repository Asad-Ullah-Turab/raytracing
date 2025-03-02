#include "DraggableCircle.h"
#include <SDL_render.h>
#include <vector>

class Bulb : public DraggableCircle {
private:
  int rayCount;
  int rayThickness;

public:
  Bulb(double radius, double x, double y, SDL_Color color, int rayCount,
       int rayThickness);

  int getRayCount() const;
  void setRayCount(int rayCount);

  int getRayThickness() const;
  void setRayThickness(int rayThickness);

  void HandleEvent(const SDL_Event &event) override;
  void CastRays(SDL_Renderer *renderer,
                const std::vector<Circle *> &circles) const;
};
