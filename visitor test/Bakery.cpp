#include <stdio.h>
#include "Bakery.h"

Bakery::Bakery()
{
}

Bakery::~Bakery()
{
}

void Bakery::accept(Visitor& iVisitor)
{
	printf("‚¢‚ç‚Á‚µ‚á‚¢‚Ü‚¹\n");
	iVisitor.visit( *this );
}
