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

	printf("Aの子供達は\n");
	a->ShowChildren();
	printf("Bの子供達は\n");
	b->ShowChildren();
	printf("Cの子供達は\n");
	c->ShowChildren();
	printf("Dの子供達は\n");
	d->ShowChildren();
	return 0;
}