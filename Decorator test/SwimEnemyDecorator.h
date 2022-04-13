#pragma once
//�G�l�~�[�̉j������

#include "EnemyDecorator.h"

class SwimEnemyDecorator : public EnemyDecorator {
public:
    SwimEnemyDecorator(Enemy* component);
    virtual void move() override;
private:
    SwimEnemyDecorator();
    SwimEnemyDecorator(const SwimEnemyDecorator& rhs);
    SwimEnemyDecorator& operator=(const SwimEnemyDecorator& rhs);
};