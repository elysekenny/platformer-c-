//
// Created by e3-kenny on 09/03/2023.
//

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject()
{
  sprite = new sf::Sprite;
}

GameObject::~GameObject()
{
  if(sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}

bool GameObject::initialiseSprite(sf::Texture &texture, std::string filename)
{
  if(!texture.loadFromFile(filename))
  {
    std::cout << "sprite texture cannot be loaded";
    return false;
  }

  if(sprite != nullptr)
  {
    sprite->setTexture(texture);
    sprite->setScale(1,1);
  }

  return true;
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

void GameObject::setVisibility(bool visibility)
{
  is_visible = visibility;
}

bool GameObject::getVisibility()
{
  return is_visible;
}

void GameObject::horizontalMovement(sf::RenderWindow& window, sf::Sprite* sprite, bool to_the_right, float speed, float dt)
{
  //one overall movement so that i can move player and enemies in the same class basically
  if(to_the_right)
  {
    //positive direction
    sprite->setPosition(sprite->getPosition().x + speed * dt, sprite->getPosition().y);
  }
  else
  {
    //negative
    sprite->setPosition(sprite->getPosition().x - speed * dt, sprite->getPosition().y);
  }
}