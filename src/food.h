#ifndef FOOD_H
#define FOOD_H

#include <random>
//#include <vector>

#include "SDL.h"
#include "snake.h"

class Food {
 public:
  SDL_Point food;

  Food(std::size_t &grid_width, std::size_t &grid_height);
  void PlaceFood(Snake &snake);
  void executeEffect(float &snakeSpeed);

 private:
  enum class FoodEffect { slowDown, speedUp, nothing, count};
  
  void assignEffect();

  FoodEffect effect;
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif