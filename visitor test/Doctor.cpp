#include <stdio.h>
#include "Doctor.h"

Doctor::Doctor()
{
}

Doctor::~Doctor()
{
}

void Doctor::visit(ShopBase& shop)
{
	printf("(医者)が入店しました\n");
}
