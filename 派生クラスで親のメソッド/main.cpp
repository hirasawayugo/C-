#include <stdio.h>
#include "Parent.h"
#include "Child.h"

int main() {
	Parent* parent = new Parent();
	Child* child = new Child();

	puts("(�e)");
	parent->walk();
	puts("\n(�q)");
	child->walk();

	return 0;
}
