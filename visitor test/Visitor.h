#pragma once

class ShopBase;

class Visitor
{
public:
	Visitor();
	virtual ~Visitor( );
public:
	virtual void visit(ShopBase& visitor) {};

};