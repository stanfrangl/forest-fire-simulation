#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Window.h"

int main(int, char**) {
  // initialisation
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;

  // Application loop
  SDL_Event event;
  bool IsRunning = true;
  while (IsRunning) {
    // Process events
    while (SDL_PollEvent(&event)) {
      // examine event object and react
      if (event.type == SDL_EVENT_QUIT) IsRunning = false;
    }
    // Update objects
    // Display changes
  }

  // shutdown
  SDL_Quit();
  return 0;
}