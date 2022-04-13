#pragma once
#include "Enemy.h"

//Decorator�N���X�̃x�[�X
//Enemy�̃x�[�X�̏��(Enemy�̉σf�[�^�̂ݕێ�)
//Enemy�̐����������ƂɂȂ�iEnemy���p�����Ă��邽�߁j

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