//
// Created by e3-kenny on 09/03/2023.
//

#ifndef PLATFORMERSFML_PLAYER_H
#define PLATFORMERSFML_PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Player: public GameObject
{
 public:
  enum class AnimationState
  {
    IDLE,
    WALK,
    JUMP,
    DAMAGE,
    DEATH
  };

  Player();
  ~Player();

  bool initPlayer(sf::RenderWindow&);
  bool initHealth(sf::RenderWindow&);

  void animatePlayer(sf::RenderWindow&);
  void flipPlayer(bool);
  void jump(sf::RenderWindow&, std::string, float, bool);
  void displayLives(sf::RenderWindow&, int);

  //getter and setter
  bool setState(std::string);
  sf::Sprite* getPlayer();
  int getLives();
  void setLives(int lives);

 private:
  AnimationState player_state = AnimationState::IDLE;

  sf::Clock animation_clock;

  sf::Sprite* player;
  sf::Sprite hearts[5];

  sf::Texture animated_texture;
  sf::Texture heart_texture;
  sf::IntRect sprite_sheet_rect;

  //float values
  float animation_speed;

  //int values
  int sprites_on_sheet;
  int lives = 3;
  };

#endif // PLATFORMERSFML_PLAYER_H
