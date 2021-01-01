#include "food.h"
// mayby the second value of random w is one to much for the screen
// and therefore sometimes no value can be seen??
Food::Food(std::size_t &grid_width, std::size_t &grid_height)
    :   engine(dev()),
        random_w(0, static_cast<int>(grid_width)),
        random_h(0, static_cast<int>(grid_height)) {
}

void Food::PlaceFood(Snake &snake){
    int x, y;
    while(true){
        x = random_w(engine);
        y = random_w(engine);

        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake.SnakeCell(x, y)) {
            food.x = x;
            food.y = y;
            assignRndEffect();
            return;
        }
    }
}

void Food::executeEffect(float &speedEffect){
    switch (effect)
    {
    case FoodEffect::speedUp:
        speedEffect = 2.0;
        break;
    
    case FoodEffect::slowDown:
        speedEffect = 0.5;
        break;

    case FoodEffect::nothing:
        speedEffect = 1.0;
        break;
    }
}



void Food::assignRndEffect(){
    // -1 because enum starts counting at 0
    int nbrOfEffects = static_cast<int>(FoodEffect::count) - 1;
    std::uniform_int_distribution<size_t> randomEnum(0, nbrOfEffects);
    effect = static_cast<FoodEffect>(randomEnum(engine));
}
