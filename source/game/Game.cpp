#include "game/Game.hpp"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)) {
  // Setting up class members
  m_mushroomScaleFactor = 0.1;
  m_mushroomTexture.loadFromFile("../../assets/imgs/mushroom.png");
  m_mushroom.setTexture(m_mushroomTexture);
  m_mushroom.setScale(m_mushroomScaleFactor, m_mushroomScaleFactor);
  m_increment = sf::Vector2i(400, 400);  // 400px a second
}

Game::~Game() {
}

void Game::Update(float f_delta) {
  m_window.Update();  // Update window events
  MoveMushroom(f_delta);
}

void Game::MoveMushroom(float f_delta) {
  sf::Vector2u l_windSize = m_window.GetWindowSize();
  sf::Vector2u l_textSize = m_mushroomTexture.getSize();

  l_textSize.x = l_textSize.x * m_mushroomScaleFactor;
  l_textSize.y = l_textSize.y * m_mushroomScaleFactor;

  if ((m_mushroom.getPosition().x > l_windSize.x - l_textSize.x &&
       m_increment.x > 0) ||
      (m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
    m_increment.x = -m_increment.x;
  }

  if ((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y &&
       m_increment.y > 0) ||
      (m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
    m_increment.y = -m_increment.y;
  }

  m_mushroom.setPosition(
      m_mushroom.getPosition().x + (m_increment.x * f_delta),
      m_mushroom.getPosition().y + (m_increment.y * f_delta));
}

void Game::Render() {
  m_window.BeginDraw();  // Clear
  m_window.Draw(m_mushroom);
  m_window.EndDraw();  // Display
}

sf::Time Game::GetElapsed() {
  return m_clock.restart();
}

Window* Game::GetWindow() {
  return &m_window;
}
