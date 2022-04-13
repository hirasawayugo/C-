#include <stdio.h>
#include"Enemy.h"
#include"NormalEnemy.h"
#include"FlyEnemyDecorator.h"
#include"SwimEnemyDecorator.h"

void main() {
	Enemy* enemy = new NormalEnemy( 10, 1 );
	Enemy* flyEnemy = new FlyEnemyDecorator( enemy );
	Enemy* flyAndSwimEnemy = new SwimEnemyDecorator(flyEnemy);


	puts("‰½‚à‚Â‚¯‚Ä‚¢‚È‚¢Enemy");
	enemy->move();
	puts("");

	puts("”ò‚×‚éEnemy");
	flyEnemy->move();
	puts("");

	puts("”ò‚×‚é,‰j‚°‚éEnemy");
	flyAndSwimEnemy->move();
}