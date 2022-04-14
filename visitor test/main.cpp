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

	puts("ƒpƒ“‰®");
	bakery.accept( doctor );
	puts("—X•Ö‹Ç");
	post.accept( doctor );
	puts("");
	puts("ƒpƒ“‰®");
	bakery.accept( police );
	puts("—X•Ö‹Ç");
	post.accept( police );
}