#include<stdio.h>
#include "Bakery.h"
#include "Postoffice.h"
#include "Doctor.h"
#include "Police.h"

void main() {
	Bakery bakery;
	Postoffice post;
	Doctor doctor;
	Police police;

	puts("�p����");
	bakery.accept( doctor );
	puts("�X�֋�");
	post.accept( doctor );
	puts("");
	puts("�p����");
	bakery.accept( police );
	puts("�X�֋�");
	post.accept( police );
}