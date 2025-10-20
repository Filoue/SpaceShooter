#pragma once
#include "Enemy.h"

class EnemyManager :
    public Enemy, public sf::Drawable, public sf::Transformable, public Motor
{
private:
    std::vector<Enemy> enemyList_;
    Motor motor_;

public:

protected:
   // void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

