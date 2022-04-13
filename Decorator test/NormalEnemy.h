#pragma once

//ベースのEnemyからできた純粋な敵オブジェクト

#include "Enemy.h"

class NormalEnemy : public Enemy {
public:
    NormalEnemy(const int& life, const int& power);
    virtual void move() override;
private:
    NormalEnemy();
    NormalEnemy(const NormalEnemy& rhs);
    NormalEnemy& operator=(const NormalEnemy& rhs);
};

