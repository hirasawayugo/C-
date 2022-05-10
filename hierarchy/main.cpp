#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "Base.h"

int main()
{
	A* a = new A;
	B* b = new B;
	C* c = new C;
	D* d = new D;

	a->AddChild(b);
	b->AddChild(c);
	c->AddChild(d);

	printf("A�̎q���B��\n");
	a->ShowChildren();
	printf("B�̎q���B��\n");
	b->ShowChildren();
	printf("C�̎q���B��\n");
	c->ShowChildren();
	printf("D�̎q���B��\n");
	d->ShowChildren();
	return 0;
}