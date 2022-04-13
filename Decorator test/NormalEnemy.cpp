#include <stdio.h>
#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(const int& life, const int& power) : Enemy(life, power) {

}

void NormalEnemy::move() {
    printf("•à‚«‚Ü‚·\n");
}