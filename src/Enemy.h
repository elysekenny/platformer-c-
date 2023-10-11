//
// Created by e3-kenny on 09/03/2023.
//

#ifndef PLATFORMERSFML_ENEMY_H
#define PLATFORMERSFML_ENEMY_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Enemy: public GameObject
{
 public:
  Enemy();
  ~Enemy();

  bool initialiseEnemies();
  void animator();
  void renderEnemies(sf::RenderWindow&);

  sf::Sprite* getEnemyByName(std::string);

 private:

  sf::Sprite* tooth_walkers[2];
  sf::Sprite* trash_monster;

  sf::Texture tooth_walker_texture;
  sf::Texture trash_monster_texture;

  sf::Clock animation_clock_tooth;
  sf::Clock animation_clock_trash;

  sf::IntRect tooth_w_rect;
  sf::IntRect trash_m_rect;
};

#endif // PLATFORMERSFML_ENEMY_H
