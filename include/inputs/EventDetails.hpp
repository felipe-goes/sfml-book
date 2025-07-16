#pragma once

#include <string>

#include "SFML/Config.hpp"
#include "SFML/System/Vector2.hpp"

struct EventDetails {
  explicit EventDetails(const std::string& l_bindName) : m_name(l_bindName) {
    Clear();
  }
  std::string m_name;

  sf::Vector2i m_size;
  sf::Uint32 m_textEntered;

  sf::Vector2i m_mouse;
  int m_mouseWheelDelta;
  int m_keyCode;  // Single key code

  void Clear() {
    m_size = sf::Vector2i(0, 0);
    m_textEntered = 0;
    m_mouse = sf::Vector2i(0, 0);
    m_mouseWheelDelta = 0;
    m_keyCode = -1;
  }
};
