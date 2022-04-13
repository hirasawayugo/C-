#include <stdio.h>
#include "EnemyDecorator.h"

EnemyDecorator::EnemyDecorator(Enemy* component) : Enemy(
    component->getLife(),
    component->getPower()
), mComponent(component) {

}