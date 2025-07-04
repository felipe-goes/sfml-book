#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "graphics/Window.hpp"

class Game {
 public:
  Game();
  ~Game();

  void HandleInput();
  void Update(float f_delta);
  void Render();

  Window* GetWindow();
  sf::Time GetElapsed();

 private:
  void MoveMushroom(float f_delta);

  Window m_window;
  sf::Texture m_mushroomTexture;
  sf::Sprite m_mushroom;
  sf::Vector2i m_increment;

  sf::Clock m_clock;
  float m_mushroomScaleFactor;
};
