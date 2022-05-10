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

	printf("A�̎q���B��\n");
	a->ShowChildren();
	printf("\n");
	printf("D�̎q���B��\n");
	d->ShowChildren();
	return 0;
}