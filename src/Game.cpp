
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
  if(platform_texture != nullptr)
  {
    delete platform_texture;
    platform_texture = nullptr;
  }

  if(crystal_texture != nullptr)
  {
    delete crystal_texture;
    crystal_texture = nullptr;
  }
}

bool Game::init()
{
  //game begins on the start menu
  state = GameState::START_MENU;
  //player starts off static
  player_direction = Direction::STATIC;
  player.setState("IDLE");

  //menu inits
  menu_elements.initMenu(window);
  menu_elements.initMenuBackground(window);
  menu_elements.initTutorial(window);
  menu_elements.initPauseScreen(window);
  menu_elements.initScore(window);
  menu_elements.initGameOver(window);
  menu_elements.initGameWon(window);

  //all other inits
  player.initPlayer(window);
  player.initHealth(window);
  enemy_handler.initialiseEnemies();

  initPlatforms();
  initCrystals();
  return true;
}

bool Game::initPlatforms()
{
  platform_texture = new sf::Texture;
  ground.initialiseSprite(*platform_texture, "Data/Images/Platforms/ground-platform.png");
  ground.getSprite()->setPosition(0, window.getSize().y - 50);
  ground.getSprite()->setScale(1.55,1.55);

  platform_texture = new sf::Texture;
  platforms[0].initialiseSprite(*platform_texture, "Data/Images/Platforms/standard-platform.png");
  platforms[0].getSprite()->setPosition(325, 535);
  platforms[0].getSprite()->setScale(1,1);

  platform_texture = new sf::Texture;
  platforms[1].initialiseSprite(*platform_texture, "Data/Images/Platforms/platform-tall-side.png");
  platforms[1].getSprite()->setPosition(500, 375);
  platforms[1].getSprite()->setScale(1.2,1.5);

  platform_texture = new sf::Texture;
  platforms[2].initialiseSprite(*platform_texture, "Data/Images/Platforms/platform-tall-top.png");
  platforms[2].getSprite()->setPosition(500, 375);
  platforms[2].getSprite()->setScale(1.4,1.2);

  platform_texture = new sf::Texture;
  platforms[3].initialiseSprite(*platform_texture, "Data/Images/Platforms/standard-platform.png");
  platforms[3].getSprite()->setPosition(150, 415);
  platforms[3].getSprite()->setScale(1,1.1);

  platform_texture = new sf::Texture;
  platforms[4].initialiseSprite(*platform_texture, "Data/Images/Platforms/standard-platform.png");
  platforms[4].getSprite()->setPosition(950, 535);
  platforms[4].getSprite()->setScale(1,1);

  platform_texture = new sf::Texture;
  platforms[5].initialiseSprite(*platform_texture, "Data/Images/Platforms/standard-platform.png");
  platforms[5].getSprite()->setPosition(200, 135);
  platforms[5].getSprite()->setScale(1.75,1.2);

  platform_texture = new sf::Texture;
  platforms[6].initialiseSprite(*platform_texture, "Data/Images/Platforms/standard-platform.png");
  platforms[6].getSprite()->setPosition(600, 200);
  platforms[6].getSprite()->setScale(1.3,1.0);

  platform_texture = new sf::Texture;
  platforms[7].initialiseSprite(*platform_texture, "Data/Images/Platforms/standard-platform.png");
  platforms[7].getSprite()->setPosition(930, 275);
  platforms[7].getSprite()->setScale(1.2,1);

  return true;
}

bool Game::initCrystals()
{
  //blue
  crystal_texture = new sf::Texture;
  crystals[0].initialiseSprite(*crystal_texture, "Data/Images/Crystal_Animation (5colors)/Crystal_Animation/Blue/blue_crystal_0000.png");
  crystals[0].getSprite()->setTexture(*crystal_texture);
  crystals[0].getSprite()->setPosition(330,55);
  crystals[0].getSprite()->setScale(1,1);
  crystals[0].setVisibility(true);

  //green
  crystal_texture = new sf::Texture;
  crystals[1].initialiseSprite(*crystal_texture, "Data/Images/Crystal_Animation (5colors)/Crystal_Animation/Green/green_crystal_0000.png");
  crystals[1].getSprite()->setTexture(*crystal_texture);
  crystals[1].getSprite()->setPosition(980,150);
  crystals[1].getSprite()->setScale(1,1);
  crystals[1].setVisibility(true);

  //pink
  crystal_texture = new sf::Texture;
  crystals[2].initialiseSprite(*crystal_texture, "Data/Images/Crystal_Animation (5colors)/Crystal_Animation/Pink/pink_crystal_0000.png");
  crystals[2].getSprite()->setTexture(*crystal_texture);
  crystals[2].getSprite()->setPosition(400,240);
  crystals[2].getSprite()->setScale(1,1);
  crystals[2].setVisibility(true);

  //purple
  crystal_texture = new sf::Texture;
  crystals[3].initialiseSprite(*crystal_texture, "Data/Images/Crystal_Animation (5colors)/Crystal_Animation/Purple/purple_crystal_0000.png");
  crystals[3].getSprite()->setTexture(*crystal_texture);
  crystals[3].getSprite()->setPosition(50,320);
  crystals[3].getSprite()->setScale(1,1);
  crystals[3].setVisibility(true);

  //red
  crystal_texture = new sf::Texture;
  crystals[4].initialiseSprite(*crystal_texture, "Data/Images/Crystal_Animation (5colors)/Crystal_Animation/Red/red_crystal_0000.png");
  crystals[4].getSprite()->setTexture(*crystal_texture);
  crystals[4].getSprite()->setPosition(620,600);
  crystals[4].getSprite()->setScale(1,1);
  crystals[4].setVisibility(true);

  return true;
}

bool Game::collisionCheckPlatform()
{
  //cycle through platform array to check for collisions
  for(int i = 0; i < 8; i ++)
  {
    if( player.getPlayer()->getPosition().y + player.getPlayer()->getGlobalBounds().height >= platforms[i].getSprite()->getPosition().y &&
        player.getPlayer()->getPosition().y + player.getPlayer()->getGlobalBounds().height <= platforms[i].getSprite()->getPosition().y + platforms[i].getSprite()->getGlobalBounds().height &&
        player.getPlayer()->getPosition().x >= platforms[i].getSprite()->getPosition().x &&
        player.getPlayer()->getPosition().x + player.getPlayer()->getGlobalBounds().width <= platforms[i].getSprite()->getPosition().x + platforms[i].getSprite()->getGlobalBounds().width &&
        direction_facing == Direction::RIGHT)
    {
      return true;
    }
    else if( player.getPlayer()->getPosition().y + player.getPlayer()->getGlobalBounds().height >= platforms[i].getSprite()->getPosition().y &&
             player.getPlayer()->getPosition().y + player.getPlayer()->getGlobalBounds().height <= platforms[i].getSprite()->getPosition().y + platforms[i].getSprite()->getGlobalBounds().height &&
             player.getPlayer()->getPosition().x - player.getPlayer()->getGlobalBounds().width >= platforms[i].getSprite()->getPosition().x &&
             player.getPlayer()->getPosition().x <= platforms[i].getSprite()->getPosition().x + platforms[i].getSprite()->getGlobalBounds().width &&
             direction_facing == Direction::LEFT)
    {
      return true;
    }
  }

  //collisions with the ground
  if(player.getPlayer()->getPosition().y >= window.getSize().y - 115)
  {
    return true;
  }
}

bool Game::collisionCheckWall()
{
  if(direction_facing == Direction::RIGHT)
  {
    if( player.getPlayer()->getPosition().x >= 0 &&
        player.getPlayer()->getPosition().x + player.getPlayer()->getGlobalBounds().width <= window.getSize().x)
    {
      return true;
    }
    else
    {
      player.setState("IDLE");
      player_direction = Direction::STATIC;
      std::cout << "out of bounds";

      return false;
    }
  }
  else if(direction_facing == Direction::LEFT)
  {
    if( player.getPlayer()->getPosition().x - player.getPlayer()->getGlobalBounds().width >= 0 &&
        player.getPlayer()->getPosition().x <= window.getSize().x)
    {
      return true;
    }
    else
    {
      player.setState("IDLE");
      player_direction = Direction::STATIC;
      std::cout << "out of bounds";
      return false;
    }
  }
}

bool Game::collisionCheck(sf::Sprite* player, sf::Sprite* object)
{
  if (
    player->getPosition().x <= object->getPosition().x + object->getGlobalBounds().width &&
    player->getPosition().x + player->getGlobalBounds().width >= object->getPosition().x  &&
    player->getPosition().y <= object->getPosition().y + object->getGlobalBounds().height &&
    player->getPosition().y + player->getGlobalBounds().height >= object->getPosition().y)
  {
    return true;
  }
}

void Game::collider()
{
  //enemy collisions
  if( collisionCheck(player.getPlayer(), enemy_handler.getEnemyByName("TRASH_MONSTER"))  ||
      collisionCheck(player.getPlayer(), enemy_handler.getEnemyByName("TOOTH_WALKER_1")) ||
      collisionCheck(player.getPlayer(), enemy_handler.getEnemyByName("TOOTH_WALKER_2")))
  {
    if(!taking_damage && player.getLives() >= 0)
    {
      //player cannot take damage if they are currently in the process of taking damage
      player.setLives(player.getLives() - 1);

      if(player.getLives() > 0)
      {
        player.setState("DAMAGE");
        taking_damage = true;
      }
      else
      {
        //death case
        player.setState("DEATH");
      }
    }
  }

  for(int i = 0; i < 5; i ++)
  {
    if(collisionCheck(player.getPlayer(), crystals[i].getSprite()) && crystals[i].getVisibility())
    {
      //collision has happened with crystal
      score ++;
      crystals[i].setVisibility(false);
      menu_elements.updateScore(score);
    }
  }

  //platform collisions- if in the process of a jump it will check if there is a platform below it
  if(jump)
  {
    player.jump(window, previous_state, jump_distance, to_the_right);
    jump_distance ++;
    if(collisionCheckPlatform())
    {
      jump = false;
      in_air = false;
      jump_distance = -18;
      //update the animation
      player.setState("IDLE");
    }
  }
  else
  {
    //if the player is not on a platform they feel gravity
    if(!collisionCheckPlatform())
    {
      //player is falling as they are not connected to a platform
      player.getPlayer()->setPosition(player.getPlayer()->getPosition().x,player.getPlayer()->getPosition().y + 8);
    }
  }
}

bool Game::restart()
{
  //everything that must be reset upon the
  //player reset to stationary
  player.setState("IDLE");
  player.setLives(5);
  player.initPlayer(window);
  player_direction = Direction::STATIC;
  direction_facing = Direction::RIGHT;

  //reset all boolean functions
  is_moving = false;
  to_the_right = true;
  taking_damage = false;

  tooth_w1_to_right = false;
  tooth_w2_to_right = false;
  trash_m_to_right = false;

  in_air = false;
  jump = false;

  for(int i =0; i < 5; i++)
  {
    crystals[i].setVisibility(true);
  }

  score = 0;

  menu_elements.initMenuBackground(window);
  //resets the enemies
  enemy_handler.initialiseEnemies();
  menu_elements.updateScore(score);
  return true;
}

bool Game::checkForGameWon()
{
  for(int i = 0; i < 5; i++)
  {
    if(crystals[i].getVisibility())
    {
      return true;
    }
  }
}

void Game::flipEnemy()
{
  if(enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getPosition().x > 580 ||
     enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getPosition().x < 200)
  {
    tooth_w1_flip *= -1;
    if(tooth_w1_to_right)
    {
      enemy_handler.getEnemyByName("TOOTH_WALKER_1")->setPosition( enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getPosition().x -  enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getGlobalBounds().width,  enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getPosition().y);
    }
    else
    {
      enemy_handler.getEnemyByName("TOOTH_WALKER_1")->setPosition( enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getPosition().x +  enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getGlobalBounds().width,  enemy_handler.getEnemyByName("TOOTH_WALKER_1")->getPosition().y);
    }
    enemy_handler.getEnemyByName("TOOTH_WALKER_1")->setScale(tooth_w1_flip, 1.8);
    tooth_w1_to_right = !tooth_w1_to_right;
  }

  if(enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getPosition().x > 900 ||
      enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getPosition().x < 450)
  {
    tooth_w2_flip *= -1;
    if(tooth_w2_to_right)
    {
      enemy_handler.getEnemyByName("TOOTH_WALKER_2")->setPosition( enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getPosition().x -  enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getGlobalBounds().width,  enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getPosition().y);
    }
    else
    {
      enemy_handler.getEnemyByName("TOOTH_WALKER_2")->setPosition( enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getPosition().x +  enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getGlobalBounds().width,  enemy_handler.getEnemyByName("TOOTH_WALKER_2")->getPosition().y);
    }
    enemy_handler.getEnemyByName("TOOTH_WALKER_2")->setScale(tooth_w2_flip, 1.8);
    tooth_w2_to_right = !tooth_w2_to_right;
  }

  if(enemy_handler.getEnemyByName("TRASH_MONSTER")->getPosition().x > 900 ||
      enemy_handler.getEnemyByName("TRASH_MONSTER")->getPosition().x < 50)
  {
    trash_m_flip *= -1;
    if(trash_m_to_right)
    {
      enemy_handler.getEnemyByName("TRASH_MONSTER")->setPosition( enemy_handler.getEnemyByName("TRASH_MONSTER")->getPosition().x -  enemy_handler.getEnemyByName("TRASH_MONSTER")->getGlobalBounds().width,  enemy_handler.getEnemyByName("TRASH_MONSTER")->getPosition().y);
    }
    else
    {
      enemy_handler.getEnemyByName("TRASH_MONSTER")->setPosition( enemy_handler.getEnemyByName("TRASH_MONSTER")->getPosition().x +  enemy_handler.getEnemyByName("TRASH_MONSTER")->getGlobalBounds().width,  enemy_handler.getEnemyByName("TRASH_MONSTER")->getPosition().y);
    }
    enemy_handler.getEnemyByName("TRASH_MONSTER")->setScale(trash_m_flip, 1.8);
    trash_m_to_right = !trash_m_to_right;
  }
}

void Game::update(float dt)
{
  switch (state)
  {
    case GameState::GAME_PLAY:
      collider();

      //animations
      player.animatePlayer(window);
      enemy_handler.animator();
      if(player_direction == Direction::RIGHT || player_direction == Direction::LEFT && player.getLives() > 0)
      {
          //the lives greater than zero is to ensure the player doesnt move even when dead
          GameObject::horizontalMovement(window, player.getPlayer(), to_the_right, player_speed, dt);
          //this forces the player into static when they reach a boundary
          collisionCheckWall();
      }

      //enemy movement
      GameObject::horizontalMovement(window, enemy_handler.getEnemyByName("TOOTH_WALKER_1"), tooth_w1_to_right, tooth_walker_speed, dt);
      GameObject::horizontalMovement(window, enemy_handler.getEnemyByName("TOOTH_WALKER_2"), tooth_w2_to_right, tooth_walker_speed, dt);
      GameObject::horizontalMovement(window, enemy_handler.getEnemyByName("TRASH_MONSTER"), trash_m_to_right, trash_monster_speed, dt);
      flipEnemy();

      //damage cooldown checker
      if(taking_damage)
      {
        //create a clock and measure if 3 seconds have passed to stop the player from instantly dying
        static sf::Clock damage_cooldown;
        if(damage_cooldown.getElapsedTime().asSeconds() >= 3)
        {
          taking_damage = false;
          damage_cooldown.restart();
        }
      }

      if(!checkForGameWon())
      {
        //if this returns false then there are no crystals on screen therefore the game has been won
        state = GameState::GAME_WIN;
      }

      if(player.getLives() <= 0)
      {
        static sf::Clock death_clock;
        if(death_clock.getElapsedTime().asSeconds() >= 1.7)
        {
          //plays the player death animation and then proceeds to game lose screen
          menu_elements.initDisplayedScore(score, window);
          state = GameState::GAME_LOSE;
        }
      }
      break;
  }
}

void Game::render()
{
  //the menu will update depending on the game state handled in the separate menu class
  menu_elements.renderMenuElements(window, int(state));

  //everything else is called in the separate menu render in the menu class
  if(state == GameState::GAME_PLAY || state == GameState::PAUSE)
  {
    //the background changes to grey
    menu_elements.initGreyBackground(window);

    //platforms
    for(int i = 0; i < 8; i++)
    {
      window.draw(*platforms[i].getSprite());
    }
    window.draw(*ground.getSprite());
    window.draw(*player.getPlayer());

    player.displayLives(window, player.getLives());
    for(int i = 0; i < 5; i ++)
    {
      if(crystals[i].getVisibility())
      {
        window.draw(*crystals[i].getSprite());
      }
    }

    enemy_handler.renderEnemies(window);

    if(state == GameState::PAUSE)
    {
      menu_elements.pauseScreen(window);
      player_direction = Direction::STATIC;
    }
  }
}

void Game::keyPressed(sf::Event event)
{
  switch(state)
  {
    case GameState::START_MENU:
      if(event.key.code == sf::Keyboard::Up)
      {
        if(menu_option == 0)
        {
          menu_option = 2;
        }
        else
        {
          menu_option --;
        }
        menu_elements.menuSelection(window, menu_option);
      }
      if(event.key.code == sf::Keyboard::Down)
      {
        if(menu_option == 2)
        {
          menu_option = 0;
        }
        else
        {
          menu_option ++;
        }
        menu_elements.menuSelection(window, menu_option);
      }

      if(event.key.code == sf::Keyboard::Enter)
      {
        if(menu_option == 0)
        {
          //if they have the option to play selected then the game begins
          state = GameState::GAME_PLAY;
        }
        else if(menu_option == 1)
        {
          state = GameState::TUTORIAL;
        }
        else if(menu_option == 2)
        {
          //otherwise they have selected quit
          window.close();
        }
      }
      break;

    case GameState::TUTORIAL:
      if(event.key.code == sf::Keyboard::Escape)
      {
        state = GameState::START_MENU;
      }
      break;

    case GameState::GAME_PLAY:
      if(event.key.code == sf::Keyboard::A)
      {
          // is moving to ensure that the state and animation are only set up once
          if (!is_moving)
          {
            player_direction = Direction::LEFT;
            player.setState("WALK");
            to_the_right = false;

            // if the player is facing the other direction they need flipping
            if (direction_facing == Direction::RIGHT)
            {
              player.flipPlayer(to_the_right);
            }
          }
          is_moving = true;
      }
      else if(event.key.code == sf::Keyboard::D)
      {
          if (!is_moving)
          {
            player_direction = Direction::RIGHT;
            player.setState("WALK");
            to_the_right = true;

            // checks if the player needs flipping
            if (direction_facing == Direction::LEFT)
            {
              player.flipPlayer(to_the_right);
            }
          }
          is_moving = true;
      }

      if(event.key.code == sf::Keyboard::Space)
      {
        if(!in_air)
        {
          if(player_direction == Direction::LEFT || player_direction == Direction::RIGHT)
          {
            previous_state = "WALK";
          }
          else if(player_direction == Direction::STATIC)
          {
            previous_state = "IDLE";
          }
          player.setState("JUMP");
          in_air = true;
          jump = true;
        }
      }

      if(event.key.code == sf::Keyboard::Escape)
      {
        state = GameState::PAUSE;
      }
      break;

    case GameState::PAUSE:
      if(event.key.code == sf::Keyboard::Escape)
      {
        state = GameState::GAME_PLAY;
        player.setState("IDLE");
        is_moving = false;
      }
      break;

    case GameState::GAME_LOSE:
      if(event.key.code == sf::Keyboard::Enter)
      {
        restart();
        state = GameState::START_MENU;
      }
      if(event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
      break;

    case GameState::GAME_WIN:
      if(event.key.code == sf::Keyboard::Enter)
      {
        restart();
        state = GameState::START_MENU;
      }
      if(event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
      break;
  }
}

void Game::keyReleased(sf::Event event)
{
  switch(state)
  {
    case GameState::GAME_PLAY:
      if(event.key.code == sf::Keyboard::A)
      {
        player_direction = Direction::STATIC;
        player.setState("IDLE");
        is_moving = false;
        direction_facing = Direction::LEFT;
      }
      if(event.key.code == sf::Keyboard::D)
      {
        player_direction = Direction::STATIC;
        player.setState("IDLE");
        is_moving = false;
        //records what way the player is facing
        direction_facing = Direction::RIGHT;
      }
  }
}