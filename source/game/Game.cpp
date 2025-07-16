#include "game/Game.hpp"

#include <iostream>

Game::Game()
    : m_window("Snake", sf::Vector2u(800, 600)),
      m_world(sf::Vector2u(800, 600)),
      m_snake(m_world.GetBlockSize()) {
  // Setting up class members
  m_elapsed = m_clock.restart().asSeconds();
  m_textbox.Setup(8, 14, 350, sf::Vector2f(434, 450));
  m_textbox.Add("Seeded random number generator with: " +
                std::to_string(time(NULL)));
  m_mushroomScaleFactor = 0.1;
  m_mushroomTexture.loadFromFile("./assets/imgs/mushroom.png");
  m_mushroom.setTexture(m_mushroomTexture);
  m_mushroom.setScale(m_mushroomScaleFactor, m_mushroomScaleFactor);

  m_texture.loadFromFile("./assets/imgs/mushroom.png");
  m_sprite.setTexture(m_texture);
  m_sprite.setScale(m_mushroomScaleFactor, m_mushroomScaleFactor);

  m_increment = sf::Vector2i(400, 400);  // 400px a second
  m_window.GetEventManager()->AddCallback("Move", &Game::MoveSprite, this);
}

Game::~Game() {
}

void Game::HandleInput() {
  m_window.Update();  // Update window events
}

void Game::Update(float f_delta) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      m_snake.GetPhysicalDirection() != Direction::Down) {
    m_snake.SetDirection(Direction::Up);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
             m_snake.GetPhysicalDirection() != Direction::Up) {
    m_snake.SetDirection(Direction::Down);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
             m_snake.GetPhysicalDirection() != Direction::Right) {
    m_snake.SetDirection(Direction::Left);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
             m_snake.GetPhysicalDirection() != Direction::Left) {
    m_snake.SetDirection(Direction::Right);
  }

  float timestep = 1.0f / m_snake.GetSpeed();

  if (m_elapsed >= timestep) {
    m_snake.Tick();
    m_world.Update(m_snake, m_textbox);
    m_elapsed -= timestep;
    if (m_snake.HasLost()) {
      m_snake.Reset();
    }
  }

  MoveMushroom(f_delta);
}

void Game::MoveSprite() {
  sf::Vector2i mousepos =
      m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
  m_sprite.setPosition(mousepos.x, mousepos.y);
  std::cout << "Moving sprite to: " << mousepos.x << ":" << mousepos.y
            << std::endl;
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
  // Clear
  m_window.BeginDraw();

  // Draw
  m_window.Draw(m_sprite);
  m_window.Draw(m_mushroom);
  // m_world.Render(*m_window.GetRenderWindow());
  // m_snake.Render(*m_window.GetRenderWindow());
  // m_textbox.Render(*m_window.GetRenderWindow());

  // Display
  m_window.EndDraw();
}

sf::Time Game::GetElapsed() {
  sf::Time clock_restart = m_clock.restart();
  m_elapsed += clock_restart.asSeconds();
  return clock_restart;
}

Window* Game::GetWindow() {
  return &m_window;
}
