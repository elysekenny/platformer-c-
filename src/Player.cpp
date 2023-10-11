//
// Created by e3-kenny on 09/03/2023.
//

#include "Player.h"
#include <iostream>

Player::Player()
{
  player = new sf::Sprite;
}

Player::~Player()
{
  if(player != nullptr)
  {
    delete player;
    player = nullptr;
  }
}

bool Player::initPlayer(sf::RenderWindow& window)
{

  player->setPosition(60, window.getSize().y - 115);
  player->setScale(2.2,2.2);
  return true;
}

bool Player::initHealth(sf::RenderWindow& window)
{
  if(!heart_texture.loadFromFile("Data/Images/heart.png"))
  {
    std::cout << "unable to load texture \n";
  }

  lives = 5;
  for(int i = 0; i < 5; i++)
  {
    hearts[i].setTexture(heart_texture);
    hearts[i].setPosition(20 + (60 * i), 30);
    hearts[i].setScale(0.2,0.2);
  }

  return true;
}

void Player::animatePlayer(sf::RenderWindow& window)
{
  switch(player_state)
  {
      //the speed of the animation will vary based on the state
    case AnimationState::IDLE:
      animation_speed = 0.22;
      break;

    case AnimationState::WALK:
      animation_speed = 0.12;
      break;

    case AnimationState::JUMP:
      animation_speed = 0.16;
      break;

    case AnimationState::DAMAGE:
      animation_speed = 0.2;
      break;

    case AnimationState::DEATH:
      animation_speed = 0.35;
      break;

  }
      if (animation_clock.getElapsedTime().asSeconds() >= animation_speed)
      {
        if (sprite_sheet_rect.left >= animated_texture.getSize().x / sprites_on_sheet * (sprites_on_sheet -1))
        {
          sprite_sheet_rect.left = 0;
        }
        else
        {
          sprite_sheet_rect.left += animated_texture.getSize().x / sprites_on_sheet;
        }

        player->setTextureRect(sprite_sheet_rect);
        animation_clock.restart();
      }
}


void Player::flipPlayer(bool to_the_right)
{
  if(to_the_right)
  {
    player->setScale(2.2,2.2);
    player->setPosition(player->getPosition().x - player->getGlobalBounds().width, player->getPosition().y);
  }
  else
  {
    player->setScale(-2.2,2.2);
    player->setPosition(player->getPosition().x + player->getGlobalBounds().width, player->getPosition().y);
  }
}

void Player::jump(sf::RenderWindow& window, std::string prev_state, float jump_dist, bool to_the_right)
{
  if(prev_state == "IDLE")
  {
    // if the player is idle the jump is directly vertical
        player->setPosition(player->getPosition().x, player->getPosition().y + jump_dist);

  }
  else if(prev_state == "WALK")
  {
    if(to_the_right)
    {
      player->setPosition(player->getPosition().x + 4,
                         player->getPosition().y + jump_dist);
    }
    else
    {
      player->setPosition(player->getPosition().x + - 4,
                         player->getPosition().y + jump_dist);
    }
  }
}

void Player::displayLives(sf::RenderWindow& window, int lives)
{
  for(int i = 0; i < lives; i ++)
  {
    window.draw(hearts[i]);
  }
}

bool Player::setState(std::string state)
{
  if(state == "IDLE")
  {
    player_state = AnimationState::IDLE;
    if(!animated_texture.loadFromFile("Data/Images/Crow Animations/crow_idle_resize.png"))
    {
      std::cout << "unable to load animation \n";
    }
    sprites_on_sheet = 4;
  }
  else if(state == "WALK")
  {
    player_state = AnimationState::WALK;
    if(!animated_texture.loadFromFile("Data/Images/Crow Animations/crow_walk_resize.png"))
    {
      std::cout << "unable to load animation \n";
    }
    sprites_on_sheet = 4;
  }
  else if(state == "JUMP")
  {
    player_state = AnimationState::JUMP;
    if(!animated_texture.loadFromFile("Data/Images/Crow Animations/crow_jump_resize.png"))
    {
      std::cout << "unable to load animation \n";
    }
    sprites_on_sheet = 6;
  }
  else if(state == "DAMAGE")
  {
    player_state = AnimationState::DAMAGE;
    if(!animated_texture.loadFromFile("Data/Images/Crow Animations/crow_damage.png"))
    {
      std::cout << "unable to load animation \n";
    }
    sprites_on_sheet = 3;
  }
  else if(state == "DEATH")
  {
    player_state = AnimationState::DEATH;
    if(!animated_texture.loadFromFile("Data/Images/Crow Animations/crow_death1.png"))
    {
      std::cout << "unable to load animation \n";
    }
    sprites_on_sheet = 5;
  }

  player->setTexture(animated_texture);
  sprite_sheet_rect = sf::IntRect(0,0, animated_texture.getSize().x / sprites_on_sheet, animated_texture.getSize().y);
  player->setTextureRect(sprite_sheet_rect);
  return true;
}

sf::Sprite* Player::getPlayer()
{
  return player;
}

int Player::getLives()
{
  return lives;
}
void Player::setLives(int lives)
{
  Player::lives = lives;
}
