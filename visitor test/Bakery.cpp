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
	printf("��������Ⴂ�܂�");
	iVisitor.visit( *this );
}
