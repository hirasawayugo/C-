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
	printf("ç°ì˙ÇÕÇ«ÇÃÇÊÇ§Ç»Ç≤ópåèÇ≈ÇµÇÂÇ§Ç©\n");
	iVisitor.visit(*this);
}
