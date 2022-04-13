#pragma once
//エネミーの飛ぶ性質

#include "EnemyDecorator.h"

class FlyEnemyDecorator:public EnemyDecorator
{
public:
    FlyEnemyDecorator(Enemy* component);
    virtual void move() override;
private:
    FlyEnemyDecorator();
    FlyEnemyDecorator(const FlyEnemyDecorator& rhs);
    FlyEnemyDecorator& operator=(const FlyEnemyDecorator& rhs);
};

