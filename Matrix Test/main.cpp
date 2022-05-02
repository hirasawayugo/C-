#include <stdio.h>
#include <math.h>
#include "Matrix33.h"
#include "Calculator.h"
#include "Vector2D.h"

int main() {
	Vector2D vec1 = Vector2D(1, 0);
	Vector2D vec2 = Vector2D(0, 1);

	double innerProdct = vec1.Dot(vec2);

	printf("内積:%0.1f \n", innerProdct);
}