#include "game/Game.hpp"

int main() {
  srand(time(nullptr));

  // Program entry point
  Game game;  // Creating our game object
  sf::Time timeAccumulator = sf::seconds(0);
  float fps = 120.f;  // make this have at least the 30 and 60 fps options
  sf::Time frameTime = sf::seconds(1.f / fps);

  while (!game.GetWindow()->IsDone()) {
    // Game loop
    // game.HandleInput();

    sf::Time deltaTime = game.GetElapsed();
    game.Update(deltaTime.asSeconds());

    timeAccumulator += deltaTime;
    if (timeAccumulator >= frameTime) {
      game.Render();
      timeAccumulator -= frameTime;
    }
  }
}
