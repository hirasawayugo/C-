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
	printf("�����͂ǂ̂悤�Ȃ��p���ł��傤��\n");
	iVisitor.visit(*this);
}
