
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "Enemy.h"
#include "GameObject.h"
#include "Menu.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:

  //game state enum set up to easily control which play state the game is currently in
  enum class GameState
  {
    START_MENU,
    TUTORIAL,
    GAME_PLAY,
    PAUSE,
    GAME_LOSE,
    GAME_WIN
  };

  enum class Direction
  {
    LEFT,
    RIGHT,
    STATIC
  };

  Game(sf::RenderWindow& window);
  ~Game();

  //init functions
  bool init();
  bool initPlatforms();
  bool initCrystals();

  //collision checkers
  bool collisionCheckPlatform();
  bool collisionCheckWall();
  bool collisionCheck(sf::Sprite*, sf::Sprite*);
  //collider contains all of the collision checks required
  void collider();

  //game loop functions
  bool restart();
  bool checkForGameWon();
  void flipEnemy();

  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

 private:
  sf::RenderWindow& window;

  //textures
  sf::Texture player_texture;
  sf::Texture* platform_texture = nullptr;
  sf::Texture* crystal_texture = nullptr;

  //enum initialisation
  GameState state;
  Direction player_direction;
  Direction direction_facing = Direction::RIGHT;

  //any objects created
  Menu menu_elements;
  Player player;
  GameObject ground;
  GameObject platforms[8];
  GameObject crystals[5];
  Enemy enemy_handler;

  //booleans handled in the menus
  int menu_option = 0;
  int score = 0;

  //boolean values
  bool is_moving = false;
  bool to_the_right = true;
  bool taking_damage = false;

  bool tooth_w1_to_right = false;
  bool tooth_w2_to_right = false;
  bool trash_m_to_right = false;

  //jump controls whether the player is in the process of jumping in update,
  //whereas in air controls whether the player can press the jump key in key press
  bool in_air = false;
  bool jump = false;

  //speed controllers
  float jump_distance = -18;
  float player_speed = 400;
  float trash_monster_speed = 400;
  float tooth_walker_speed = 100;

  //controlling the sprite being reversed
  float tooth_w1_flip = 1.8;
  float tooth_w2_flip = 1.8;
  float trash_m_flip = 1.8;

  //string values
  std::string previous_state;
};

#endif // PLATFORMER_GAME_H
