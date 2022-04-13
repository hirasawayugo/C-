#include "Enemy.h"

Enemy::Enemy(const int& life, const int& power) : mLife(life), mPower(power) {

}

int Enemy::getLife() const {
    return mLife;
}

int Enemy::getPower() const {
    return mPower;
}