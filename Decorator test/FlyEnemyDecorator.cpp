#include <stdio.h>
#include "FlyEnemyDecorator.h"

FlyEnemyDecorator::FlyEnemyDecorator(Enemy* component) : EnemyDecorator(component) {

}

void FlyEnemyDecorator::move() {
    mComponent->move();
    printf("”ò‚Ñ‚Ü‚·\n");
}
