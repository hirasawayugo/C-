#include <stdio.h>


void hello() {
	printf("����ɂ���\n");
}

void bye() {
	printf("���悤�Ȃ�\n");
}


void main() {
	void(* answer)(void) = NULL;

	//����ɂ���
	answer = hello;
	answer();
	puts("");
	//���悤�Ȃ�
	answer = bye;
	answer();
}