#include <stdio.h>
#include"Enemy.h"
#include"NormalEnemy.h"
#include"FlyEnemyDecorator.h"
#include"SwimEnemyDecorator.h"

void main() {
	Enemy* enemy = new NormalEnemy( 10, 1 );
	Enemy* flyEnemy = new FlyEnemyDecorator( enemy );
	Enemy* flyAndSwimEnemy = new SwimEnemyDecorator(flyEnemy);


	puts("何もつけていないEnemy");
	enemy->move();
	puts("");

	puts("飛べるEnemy");
	flyEnemy->move();
	puts("");

	puts("飛べる,泳げるEnemy");
	flyAndSwimEnemy->move();
}