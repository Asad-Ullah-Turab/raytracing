#include "Bulb.h"
#include "Circle.h"
#include "Global.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_timer.h>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

void HandleEvents(SDL_Event &, bool &, const vector<Circle *> &,
                  const vector<Bulb *> &);
void HandleDraw(SDL_Renderer *, const vector<Circle *> &,
                const vector<Bulb *> &);

int main() {

  // Initialze SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initalize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 1;
  }

  // Create an SDL window
  SDL_Window *window = SDL_CreateWindow("Ray Tracing", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                        SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (!window) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_Quit();
    return 1;
  }

  // Create a renderer
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Creating objects
  SDL_Color color{255, 255, 0, 255};
  SDL_Color rayColor{255, 255, 75, 10};
  Bulb bulb(50, 200, 200, color, 1000, 1, rayColor);

  color = {255, 0, 0, 255};
  DraggableCircle circle(120, 800, 150, color);
  color = {0, 255, 0, 255};
  DraggableCircle circle2(80, 800, 450, color);

  vector<Circle *> circles = {&circle, &circle2};
  vector<Bulb *> bulbs = {&bulb};

  // Main Loop
  bool running = true;
  SDL_Event event;
  while (running) {

    HandleEvents(event, running, circles, bulbs);
    HandleDraw(renderer, circles, bulbs);

    // Update
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

void HandleEvents(SDL_Event &event, bool &running,
                  const vector<Circle *> &circles,
                  const vector<Bulb *> &bulbs) {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    } else if (event.type == SDL_MOUSEMOTION &&
               event.motion.state == SDL_BUTTON_LMASK) {
      for (Circle *circle : circles) {
        circle->HandleEvent(event);
      }
      for (Bulb *bulb : bulbs) {
        bulb->HandleEvent(event);
      }
    }
  }
}

void HandleDraw(SDL_Renderer *renderer, const vector<Circle *> &circles,
                const vector<Bulb *> &bulbs) {
  for (const Circle *circle : circles) {
    circle->DrawCircle(renderer);
  }
  for (const Bulb *bulb : bulbs) {
    bulb->CastRays(renderer, circles);
    bulb->DrawCircle(renderer);
  }
}
