#include <stdio.h>
#include "Ground.h"
#include "Material.h"

void main() {
	Ground* grass = new Ground( 0 );
	Ground* rock = new Ground( 1 );
	Ground* soil = new Ground( 2 );

	const char* mate_0_name = grass->getMaterial()->getName();
	const char* mate_1_name = rock->getMaterial()->getName();
	const char* mate_2_name = soil->getMaterial()->getName();

	printf("�n��0�̍ގ���%s	\n", mate_0_name);
	printf("�n��1�̍ގ���%s \n", mate_1_name);
	printf("�n��2�̍ގ���%s \n", mate_2_name);
}