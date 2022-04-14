#pragma once
#include "Visitor.h"

class ShopBase
{
public:
	ShopBase();
	virtual ~ShopBase();
public:
	virtual void accept( Visitor &iVisiter) = 0;
};