#include <stdio.h>
#include "Police.h"

Police::Police()
{
}

Police::~Police()
{
}

void Police::visit(Bakery& bakery)
{
	printf("(警察)パンを一つください");
}

void Police::visit(Postoffice& postoffice)
{
	printf("(警察)手紙をお願いします");
}
