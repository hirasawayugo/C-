#include <stdio.h>


void hello() {
	printf("こんにちは\n");
}

void bye() {
	printf("さようなら\n");
}


void main() {
	void(* answer)(void) = NULL;

	//こんにちは
	answer = hello;
	answer();
	puts("");
	//さようなら
	answer = bye;
	answer();
}