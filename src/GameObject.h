//
// Created by e3-kenny on 09/03/2023.
//

#ifndef PLATFORMERSFML_GAMEOBJECT_H
#define PLATFORMERSFML_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
 public:
  GameObject();
  ~GameObject();

  //getters and setters
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();

  void setVisibility(bool);
  bool getVisibility();

  //any other methods
  static void horizontalMovement(sf::RenderWindow&, sf::Sprite*, bool, float, float);

 private:
  sf::Sprite* sprite = nullptr;

  bool is_visible;
};

#endif // PLATFORMERSFML_GAMEOBJECT_H
