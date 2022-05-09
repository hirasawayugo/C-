#include <list>

class Base
{
public:
	Base();
	virtual ~Base();
public:
	void AddChild( Base base );
	void ShowChild();
protected:
	virtual void Log() {};
protected:
	std::list<Base> children;
};