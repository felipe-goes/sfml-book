#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "game/Snake.hpp"
#include "graphics/Textbox.hpp"

class World {
 public:
  explicit World(sf::Vector2u l_windSize);
  ~World();

  int GetBlockSize();

  void RespawnApple();

  void Update(Snake& l_player, Textbox& l_textbox);
  void Render(sf::RenderWindow& l_window);

 private:
  sf::Vector2u m_windowSize;
  sf::Vector2i m_item;
  int m_blockSize;

  sf::CircleShape m_appleShape;
  sf::RectangleShape m_bounds[4];
};
