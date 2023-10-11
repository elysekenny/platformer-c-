//
// Created by e3-kenny on 09/03/2023.
//

#include "Menu.h"
#include <iostream>

Menu::~Menu()
{
  //to prevent memory leaks
  if(background_items != nullptr)
  {
    delete[] background_items;
    background_items = nullptr;
  }

  if(background_texture != nullptr)
  {
    delete background_items;
    background_texture = nullptr;
  }
}

bool Menu::initMenu(sf::RenderWindow& window)
{
  if(!title_font.loadFromFile("Data/Fonts/ka1.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  title.setString("-- platformer --");
  title.setFont(title_font);
  title.setCharacterSize(70);
  title.setFillColor(sf::Color(255,255,255,255));
  title.setPosition(
    window.getSize().x /2 - title.getGlobalBounds().width /2,75);

  menu_option_play.setString(">> PLAY <<");
  menu_option_play.setFont(main_font);
  menu_option_play.setCharacterSize(50);
  menu_option_play.setFillColor(sf::Color(255,255,255,255));
  menu_option_play.setPosition(
    window.getSize().x /2 - menu_option_play.getGlobalBounds().width /2,300);

  menu_option_controls.setString("HOW TO PLAY");
  menu_option_controls.setFont(main_font);
  menu_option_controls.setCharacterSize(50);
  menu_option_controls.setFillColor(sf::Color(170,170,170,255));
  menu_option_controls.setPosition(
    window.getSize().x /2 - menu_option_controls.getGlobalBounds().width /2,400);

  menu_option_quit.setString("QUIT");
  menu_option_quit.setFont(main_font);
  menu_option_quit.setCharacterSize(50);
  menu_option_quit.setFillColor(sf::Color(170,170,170,255));
  menu_option_quit.setPosition(
    window.getSize().x /2 - menu_option_quit.getGlobalBounds().width /2,500);

  return true;
}

bool Menu::initMenuBackground(sf::RenderWindow&)
{
  std::string layers[] = { "parallax-demon-woods-bg.png",
                           "parallax-demon-woods-far-trees.png",
                           "parallax-demon-woods-mid-trees.png",
                           "parallax-demon-woods-close-trees.png"};

  background_items = new GameObject[no_of_background_elements];
  for(int i = 0; i < no_of_background_elements; i++)
  {
    background_texture = new sf::Texture;
    background_items[i].initialiseSprite(*background_texture, "Data/Images/layers/" + layers[i]);
    background_items[i].getSprite()->setPosition(0,0);
    background_items[i].getSprite()->setScale(2.35,2.75);
  }

  return true;
}

bool Menu::initTutorial(sf::RenderWindow& window)
{
  if(!tutorial_texture.loadFromFile("Data/Images/tutorial-screen.png"))
  {
    std::cout << "unable to load texture \n";
  }

  tutorial_screen.setTexture(tutorial_texture);
  tutorial_screen.setPosition(0,0);
  tutorial_screen.setScale(1,1);

  return true;
}

bool Menu::initPauseScreen(sf::RenderWindow& window)
{
  if(!pause_texture.loadFromFile("Data/Images/pause-screen.png"))
  {
    std::cout << "unable to load texture \n";
  }

  pause_screen.setTexture(pause_texture);
  pause_screen.setPosition(0,0);
  pause_screen.setScale(1,1);

  if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  pause_text.setString(">> Press ESCAPE to resume << ");
  pause_text.setFont(main_font);
  pause_text.setCharacterSize(20);
  pause_text.setFillColor(sf::Color(255,255,255,255));
  pause_text.setPosition(window.getSize().x / 2 - pause_text.getGlobalBounds().width /2, 30);

  if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }
  return true;
}

bool Menu::initGameOver(sf::RenderWindow& window)
{
    if(!title_font.loadFromFile("Data/Fonts/ka1.ttf"))
    {
      std::cout << "an error has occurred whilst trying to load the font\n";
    }

    game_over_text.setString("-- GAME OVER YOU LOSE -- ");
    game_over_text.setFont(title_font);
    game_over_text.setCharacterSize(60);
    game_over_text.setFillColor(sf::Color(255,0,0,255));
    game_over_text.setPosition(window.getSize().x /2 - game_over_text.getGlobalBounds().width /2,50);


    if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
    {
      std::cout << "an error has occurred whilst trying to load the font\n";
    }

    game_complete_button_prompt.setString(">> Press ENTER to return to menu << \n      >> Press ESCAPE to quit <<");
    game_complete_button_prompt.setFont(main_font);
    game_complete_button_prompt.setCharacterSize(20);
    game_complete_button_prompt.setFillColor(sf::Color(255,255,255,255));
    game_complete_button_prompt.setPosition(
      window.getSize().x /2 - game_complete_button_prompt.getGlobalBounds().width /2,350);

    return true;
}

bool Menu::initGameWon(sf::RenderWindow& window)
{
  if(!title_font.loadFromFile("Data/Fonts/ka1.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  game_won_text.setString("-- YOU WIN -- ");
  game_won_text.setFont(title_font);
  game_won_text.setCharacterSize(60);
  game_won_text.setFillColor(sf::Color(0,255,0,255));
  game_won_text.setPosition(window.getSize().x /2 - game_won_text.getGlobalBounds().width /2,50);


  if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  game_complete_button_prompt.setString(">> Press ENTER to return to menu << \n      >> Press ESCAPE to quit <<");
  game_complete_button_prompt.setFont(main_font);
  game_complete_button_prompt.setCharacterSize(20);
  game_complete_button_prompt.setFillColor(sf::Color(255,255,255,255));
  game_complete_button_prompt.setPosition(
    window.getSize().x /2 - game_complete_button_prompt.getGlobalBounds().width /2,350);

  return true;
}

void Menu::initDisplayedScore(int score, sf::RenderWindow& window)
{
  if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  end_score_text.setString("-- Your final score was " + std::to_string(score) + " --");
  end_score_text.setFont(main_font);
  end_score_text.setCharacterSize(25);
  end_score_text.setFillColor(sf::Color(120,120,200,255));
  end_score_text.setPosition(
    window.getSize().x /2 - end_score_text.getGlobalBounds().width /2,650);
}

bool Menu::initGreyBackground(sf::RenderWindow& window)
{
  no_of_background_elements = 4;

  //resets the background but using the grey counterparts
  std::string layers[] = { "layers/parallax-demon-woods-bg-grey.png",
                           "layers/parallax-demon-woods-far-trees-grey.png",
                           "layers/parallax-demon-woods-mid-trees-grey.png",
                           "layers/parallax-demon-woods-close-trees-gray.png"};

   background_items = new GameObject[no_of_background_elements];
   for(int i = 0; i < no_of_background_elements; i++)
   {
     background_texture = new sf::Texture;
     background_items[i].initialiseSprite(*background_texture, "Data/Images/" + layers[i]);
     background_items[i].getSprite()->setPosition(0,-300);
     background_items[i].getSprite()->setScale(3.85,4.25);
   }

   return true;
}

bool Menu::initScore(sf::RenderWindow& window)
{
  if(!main_font.loadFromFile("Data/Fonts/RosesareFF0000.ttf"))
  {
    std::cout << "an error has occurred whilst trying to load the font\n";
  }

  score_text.setFont(main_font);
  score_text.setPosition(window.getSize().x - 200, 30);
  score_text.setFillColor(sf::Color(255,255,255,255));
  score_text.setCharacterSize(30);
  score_text.setString("SCORE: 0");

  return true;
}

void Menu::updateScore(int score)
{
  score_text.setString("SCORE: " + std::to_string(score));
}

void Menu::pauseScreen(sf::RenderWindow& window)
{
  window.draw(pause_screen);
  window.draw(pause_text);
}

bool Menu::menuSelection(sf::RenderWindow& window, int menu_option)
{
  if(menu_option == 0)
  {
    //colour changes
    menu_option_play.setFillColor(sf::Color(255,255,255,255));
    menu_option_controls.setFillColor(sf::Color(170,170,170,255));
    menu_option_quit.setFillColor(sf::Color(170,170,170,255));

    //string changes
    menu_option_play.setString(">> PLAY <<");
    menu_option_controls.setString("HOW TO PLAY");
    menu_option_quit.setString("QUIT");

    //ensures the position is still centered
    menu_option_play.setPosition(
      window.getSize().x /2 - menu_option_play.getGlobalBounds().width /2,300);
    menu_option_controls.setPosition(
      window.getSize().x /2 - menu_option_controls.getGlobalBounds().width /2,400);
    menu_option_quit.setPosition(
      window.getSize().x /2 - menu_option_quit.getGlobalBounds().width /2,500);
  }
  else if(menu_option == 1)
  {
    menu_option_play.setFillColor(sf::Color(170,170,170,255));
    menu_option_controls.setFillColor(sf::Color(255,255,255,255));
    menu_option_quit.setFillColor(sf::Color(170,170,170,255));

    menu_option_play.setString("PLAY");
    menu_option_controls.setString(">> HOW TO PLAY <<");
    menu_option_quit.setString("QUIT");

    menu_option_play.setPosition(
      window.getSize().x /2 - menu_option_play.getGlobalBounds().width /2,300);
    menu_option_controls.setPosition(
      window.getSize().x /2 - menu_option_controls.getGlobalBounds().width /2,400);
    menu_option_quit.setPosition(
      window.getSize().x /2 - menu_option_quit.getGlobalBounds().width /2,500);
  }

  else if(menu_option == 2)
  {
    menu_option_play.setFillColor(sf::Color(170,170,170,255));
    menu_option_controls.setFillColor(sf::Color(170,170,170,255));
    menu_option_quit.setFillColor(sf::Color(255,255,255,255));

    menu_option_play.setString("PLAY");
    menu_option_controls.setString("HOW TO PLAY");
    menu_option_quit.setString(">> QUIT <<");

    menu_option_play.setPosition(
      window.getSize().x /2 - menu_option_play.getGlobalBounds().width /2,300);
    menu_option_controls.setPosition(
      window.getSize().x /2 - menu_option_controls.getGlobalBounds().width /2,400);
    menu_option_quit.setPosition(
      window.getSize().x /2 - menu_option_quit.getGlobalBounds().width /2,500);
  }

}

void Menu::renderMenuElements(sf::RenderWindow& window, int state)
{

  switch(state)
  {
    case 0:
      //start menu
      for(int i = 0; i < no_of_background_elements; i++)
      {
        window.draw(*background_items[i].getSprite());
      }

      window.draw(title);
      window.draw(menu_option_play);
      window.draw(menu_option_controls);
      window.draw(menu_option_quit);
      break;

    case 1:
      //tutorial
      window.draw(tutorial_screen);
      break;

    case 2:
      //game loop
      for(int i = 0; i < no_of_background_elements; i++)
      {
        window.draw(*background_items[i].getSprite());
      }

      window.draw(score_text);
      break;

    case 3:
      //pause menu
      for(int i = 0; i < no_of_background_elements; i++)
      {
        window.draw(*background_items[i].getSprite());
      }
      break;

    case 4:
      //game over
      for(int i = 0; i < no_of_background_elements; i++)
      {
        window.draw(*background_items[i].getSprite());
      }
      window.draw(game_over_text);
      window.draw(game_complete_button_prompt);
      window.draw(end_score_text);
      break;

    case 5:
      //game won
      for(int i = 0; i < no_of_background_elements; i++)
      {
        window.draw(*background_items[i].getSprite());
      }
      window.draw(game_won_text);
      window.draw(game_complete_button_prompt);
      break;
  }
}