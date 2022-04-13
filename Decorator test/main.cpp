#include <stdio.h>
#include"Enemy.h"
#include"NormalEnemy.h"
#include"FlyEnemyDecorator.h"
#include"SwimEnemyDecorator.h"

void main() {
	Enemy* enemy = new NormalEnemy( 10, 1 );
	Enemy* flyEnemy = new FlyEnemyDecorator( enemy );
	Enemy* flyAndSwimEnemy = new SwimEnemyDecorator(flyEnemy);


	puts("�������Ă��Ȃ�Enemy");
	enemy->move();
	puts("");

	puts("��ׂ�Enemy");
	flyEnemy->move();
	puts("");

	puts("��ׂ�,�j����Enemy");
	flyAndSwimEnemy->move();
}