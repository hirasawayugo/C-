#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "Calculator.h"


int main()
{
	Calculator calc;
	A* a = new A;
	B* b = new B;
	C* c = new C;
	D* d = new D;

	a->AddChild(b);
	b->AddChild(c);
	c->AddChild(d);

	a->Foward(Vector2D(1, 1));
	b->Foward(Vector2D(1, 0));
	c->Foward(Vector2D(0, 1));
	c->Rotate(calc.Radians(180));
	d->Foward(Vector2D(1, 1));

	printf("A�̍��W\n");
	a->Log();
	printf("B�̍��W\n");
	b->Log();
	printf("C�̍��W\n");
	c->Log();
	printf("D�̍��W\n");
	d->Log();

	return 0;
}