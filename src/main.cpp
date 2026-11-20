#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <vector>
#include <random>
#include "Window.h"
#include "tile.h"

int main(int, char**) {
  // initialisation
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;
  const auto* fmt = SDL_GetPixelFormatDetails(GameWindow.GetSurface()->format);
  //building the grid
  constexpr int Columns = 64;
  constexpr int Rows = 64;
  constexpr int Cell = 16;
  std::vector<tile> Tiles;
  Tiles.reserve(Rows * Columns);
  for (int Row = 0; Row < Rows; ++Row) {
    for (int col = 0; col < Columns; ++col) {
      Tiles.emplace_back(
        SDL_Rect{col * Cell, Row * Cell, Cell, Cell},
        fmt
      );
    }
  }
  std::mt19937 rng{std::random_device{}()};
  std::uniform_int_distribution<int> distribution{1, 100};
  for (int i = 0; i < Tiles.size(); i++) {
    int result = distribution(rng);
    if (result <= 10) Tiles[i].SetType(Type::bare);
    else if (result <= 30) Tiles[i].SetType(Type::growing);
    else Tiles[i].SetType(Type::mature);
  }
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
    const int rowOffSets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int colOffSets[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < Tiles.size(); i++) {
      int row = i / Columns;
      int col = i % Columns;
    }
    for (auto& MyTile : Tiles) {
      MyTile.Update(rng);
    }
    // Render background
    GameWindow.render();
    // Render everything else
    for (const auto& MyTile : Tiles) {
      MyTile.Render(GameWindow.GetSurface());
    }
    // Swap buffer
    GameWindow.update();
    SDL_Delay(100);
  }

  // shutdown
  SDL_Quit();
  return 0;
}