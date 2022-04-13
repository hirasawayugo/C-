#pragma once
#include "Enemy.h"

//Decoratorクラスのベース
//Enemyのベースの状態(Enemyの可変データのみ保持)
//Enemyの性質を持つことになる（Enemyを継承しているため）

class EnemyDecorator : public Enemy {
public:
    EnemyDecorator(Enemy* component);
    virtual ~EnemyDecorator() {}
protected:
    Enemy* mComponent;
private:
    EnemyDecorator();
    EnemyDecorator(const EnemyDecorator& rhs);
    EnemyDecorator& operator=(const EnemyDecorator& rhs);
};