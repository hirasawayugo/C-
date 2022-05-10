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
	a->AddChild(c);
	d->AddChild(a);

	printf("Aの子供達は\n");
	a->ShowChildren();
	printf("\n");
	printf("Dの子供達は\n");
	d->ShowChildren();
	return 0;
}