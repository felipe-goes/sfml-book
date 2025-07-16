#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "game/Snake.hpp"
#include "game/World.hpp"
#include "graphics/Textbox.hpp"
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
  void MoveSprite();
  Window m_window;
  World m_world;
  Snake m_snake;

  sf::Texture m_mushroomTexture;
  sf::Texture m_texture;
  sf::Sprite m_mushroom;
  sf::Sprite m_sprite;
  sf::Vector2i m_increment;

  sf::Clock m_clock;
  float m_elapsed;
  float m_mushroomScaleFactor;

  Textbox m_textbox;
};
