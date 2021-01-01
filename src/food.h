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
  void executeEffect(float &speedEffect);
  void checkEffectDuration();

 private:
 // possible effects extra food or less food??
  enum class FoodEffect { slowDown, speedUp, nothing, count};
  
  void assignRndEffect();

  FoodEffect effect;
  //save last effect and execute reverse effect
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif