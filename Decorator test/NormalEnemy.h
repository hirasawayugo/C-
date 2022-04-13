#pragma once

//�x�[�X��Enemy����ł��������ȓG�I�u�W�F�N�g

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

