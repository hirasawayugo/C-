#pragma once

class Visitor;

class ShopBase
{
public:
	ShopBase();
	virtual ~ShopBase();
public:
	virtual void accept( Visitor &iVisiter) = 0;
};