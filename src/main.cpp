#include "Circle.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <iostream>
#include <ostream>

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

void HandleDraw(SDL_Renderer *);

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

  bool running = true;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    // Draw
    HandleDraw(renderer);

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

void HandleDraw(SDL_Renderer *renderer) {

  Circle circle(20, 200, 200);
  SDL_Color color{200, 20, 20, 255};
  circle.DrawCircle(renderer, color);
}
