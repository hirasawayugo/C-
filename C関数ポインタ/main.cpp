#include <stdio.h>


void hello() {
	printf("‚±‚ñ‚É‚¿‚Í\n");
}

void bye() {
	printf("‚³‚æ‚¤‚È‚ç\n");
}


void main() {
	void(* answer)(void) = NULL;

	//‚±‚ñ‚É‚¿‚Í
	answer = hello;
	answer();
	puts("");
	//‚³‚æ‚¤‚È‚ç
	answer = bye;
	answer();
}