#include "A.h"
#include "B.h"

void main()
{
	A a;
	B b;
	a.AddChild(b);

	a.ShowChild();
}