#pragma once
//�G�l�~�[�̔�Ԑ���

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

