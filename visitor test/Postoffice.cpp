#include <stdio.h>
#include "Postoffice.h"

Postoffice::Postoffice()
{
}

Postoffice::~Postoffice()
{
}

void Postoffice::accept(Visitor& iVisitor)
{
	printf("今日はどのようなご用件でしょうか\n");
	iVisitor.visit(*this);
}
