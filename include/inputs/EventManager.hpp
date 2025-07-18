#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include "./Binding.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using Callbacks = std::unordered_map<std::string, std::function<void()> >;

class EventManager {
 public:
  EventManager();
  ~EventManager();

  bool AddBinding(Binding* l_binding);
  bool RemoveBinding(std::string l_name);

  void SetFocus(const bool& l_focus);

  // Needs to be defined in the header!
  template <class T>
  bool AddCallback(const std::string& l_name, void (T::*l_func)(),
                   T* l_instance) {
    auto temp = std::bind(l_func, l_instance);
    return m_callbacks.emplace(l_name, temp).second;
  }

  void RemoveCallback(const std::string& l_name) {
    m_callbacks.erase(l_name);
  }

  void HandleEvent(sf::Event& l_event);
  void Update();

  sf::Vector2i GetMousePos(sf::RenderWindow* l_wind = nullptr) {
    return (l_wind ? sf::Mouse::getPosition(*l_wind)
                   : sf::Mouse::getPosition());
  }

 private:
  void LoadBindings();

  Bindings m_bindings;
  Callbacks m_callbacks;
  bool m_hasFocus;
};
