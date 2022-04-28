#include <stdio.h>
#include <math.h>
#include "Calculator.h"
#include "Vector2D.h"

int main() {
	Vector2D vec1 = Vector2D(0, 0);
	Vector2D vec2 = Vector2D(1, 1);
	Calculator calc;

	float diff = calc.dist(vec1, vec2);

	printf("%lf", diff);
}