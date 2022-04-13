#include <stdio.h>
#include "SwimEnemyDecorator.h"

SwimEnemyDecorator::SwimEnemyDecorator(Enemy* component) : EnemyDecorator(component) {

}

void SwimEnemyDecorator::move() {
    mComponent->move();
    printf("‰j‚°‚Ü‚·.\n");
}