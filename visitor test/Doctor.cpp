#include <stdio.h>
#include "Doctor.h"

Doctor::Doctor()
{
}

Doctor::~Doctor()
{
}

void Doctor::visit(Bakery& bakery)
{
	printf("(医者)パンを一つください");
}

void Doctor::visit(Postoffice& postoffice)
{
	printf("(医者)手紙をお願いします");
}
