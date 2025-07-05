#pragma once

#include <string>
#include <vector>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"

using MessageContainer = std::vector<std::string>;

class Textbox {
 public:
  Textbox();
  Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
  ~Textbox();

  void Setup(int l_visible, int l_charSize, int l_width,
             sf::Vector2f l_screenPos);

  void Add(std::string l_message);
  void Clear();

  void Render(sf::RenderWindow& l_wind);

 private:
  MessageContainer m_messages;

  sf::RectangleShape m_backdrop;
  sf::Font m_font;
  sf::Text m_content;
};
