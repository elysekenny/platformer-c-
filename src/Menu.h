//
// Created by e3-kenny on 09/03/2023.
//

#ifndef PLATFORMERSFML_MENU_H
#define PLATFORMERSFML_MENU_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Menu
{
 public:
  ~Menu();
  //initialising screens
  bool initMenu(sf::RenderWindow&);
  bool initMenuBackground(sf::RenderWindow&);
  bool initTutorial(sf::RenderWindow&);
  bool initPauseScreen(sf::RenderWindow&);
  bool initGameOver(sf::RenderWindow&);
  bool initGameWon(sf::RenderWindow&);
  void initDisplayedScore(int, sf::RenderWindow&);

  //any menu elements present in the main gameplay loop
  bool initGreyBackground(sf::RenderWindow&);
  bool initScore(sf::RenderWindow&);
  void updateScore(int);
  //pause screen has a seperate menu to render the entire thing over the sprites
  void pauseScreen(sf::RenderWindow&);

  //any menu screen that requires a selection of options
  bool menuSelection(sf::RenderWindow&, int);

  //one render called in this class with the game state parsed in
  void renderMenuElements(sf::RenderWindow&, int);

 private:
  //fonts used
  sf::Font title_font;
  sf::Font main_font;

  //all text options on the screen
  sf::Text title;
  sf::Text menu_option_play;
  sf::Text menu_option_controls;
  sf::Text menu_option_quit;
  sf::Text pause_text;
  sf::Text score_text;
  sf::Text end_score_text;
  sf::Text game_over_text;
  sf::Text game_won_text;
  sf::Text game_complete_button_prompt;

  // all textures
  // the texture used for the background as a pointer because there are 4 layers to the background
  sf::Texture* background_texture = nullptr;
  sf::Texture pause_texture;
  sf::Texture tutorial_texture;

  //background is a sprite
  GameObject* background_items = nullptr;
  sf::Sprite pause_screen;
  sf::Sprite tutorial_screen;

  //any integer values needed to be used for the ui and menu
  int no_of_background_elements = 4;
};

#endif // PLATFORMERSFML_MENU_H
