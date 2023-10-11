//
// Created by e3-kenny on 09/03/2023.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
  trash_monster = new sf::Sprite;
  tooth_walkers[0] = new sf::Sprite;
  tooth_walkers[1] = new sf::Sprite;
}

Enemy::~Enemy()
{
  if(trash_monster != nullptr)
  {
    delete trash_monster;
    trash_monster = nullptr;
  }

  if(tooth_walkers[0] != nullptr)
  {
    delete tooth_walkers[0];
    tooth_walkers[0] = nullptr;
  }

  if(tooth_walkers[1] != nullptr)
  {
    delete tooth_walkers[1];
    tooth_walkers[1] = nullptr;
  }
}

bool Enemy::initialiseEnemies()
{
    if(!trash_monster_texture.loadFromFile("Data/Images/Trash Monster/Trash Monster/Trash Monster-Sheet-Idle.png"))
    {
      std::cout << "unable to load texture \n";
    }

    trash_monster->setTexture(trash_monster_texture);
    trash_monster->setPosition(900, 600);
    trash_monster->setScale(1.8,1.8);

    if (!tooth_walker_texture.loadFromFile("Data/Images/tooth walker/tooth walker/tooth walker sprite-Sheet-Idle.png"))
    {
      std::cout << "unable to load texture \n";
    }

    tooth_walkers[0]->setTexture(tooth_walker_texture);
    tooth_walkers[0]->setPosition(200,68);
    tooth_walkers[0]->setScale(1.8, 1.8);

    tooth_walkers[1]->setTexture(tooth_walker_texture);
    tooth_walkers[1]->setPosition(800, 310);
    tooth_walkers[1]->setScale(1.8, 1.8);


    trash_m_rect = sf::IntRect(0,0, trash_monster_texture.getSize().x / 6, trash_monster_texture.getSize().y);
    trash_monster->setTextureRect(trash_m_rect);

    tooth_w_rect = sf::IntRect(0,0, tooth_walker_texture.getSize().x / 6, tooth_walker_texture.getSize().y);
    tooth_walkers[0]->setTextureRect(tooth_w_rect);
    tooth_walkers[1]->setTextureRect(tooth_w_rect);

    return true;
}


void Enemy::animator()
{
  if (animation_clock_tooth.getElapsedTime().asSeconds() >= 0.18)
  {
    if (tooth_w_rect.left >= tooth_walker_texture.getSize().x / 6 * 5)
    {
      tooth_w_rect.left = 0;
    }
    else
    {
      tooth_w_rect.left += tooth_walker_texture.getSize().x / 6;
    }

    tooth_walkers[0]->setTextureRect(tooth_w_rect);
    tooth_walkers[1]->setTextureRect(tooth_w_rect);
    animation_clock_tooth.restart();
  }

  if (animation_clock_trash.getElapsedTime().asSeconds() >= 0.1)
  {
    if (trash_m_rect.left >= trash_monster_texture.getSize().x / 6 * 5)
    {
      trash_m_rect.left = 0;
    }
    else
    {
      trash_m_rect.left += trash_monster_texture.getSize().x / 6;
    }

    trash_monster->setTextureRect(trash_m_rect);
    animation_clock_trash.restart();
  }
}

void Enemy::renderEnemies(sf::RenderWindow& window)
{
  window.draw(*trash_monster);

  for(int i = 0; i < 2; i++)
  {
    window.draw(*tooth_walkers[i]);
  }
}

sf::Sprite* Enemy::getEnemyByName(std::string enemy_name)
{
  if(enemy_name == "TOOTH_WALKER_1")
  {
    return tooth_walkers[0];
  }

  if(enemy_name == "TOOTH_WALKER_2")
  {
    return tooth_walkers[1];
  }

  if(enemy_name == "TRASH_MONSTER")
  {
    return trash_monster;
  }

}