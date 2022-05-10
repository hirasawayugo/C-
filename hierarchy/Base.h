#pragma once
#include <list>

class Base
{
public:
	Base();
	virtual ~Base();
public:
	void AddChild( Base* base );
	void ShowChildren();
public:
	virtual void Log() {};
protected:
	std::list<Base*> children;
};