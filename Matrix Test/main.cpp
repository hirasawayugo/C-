#include <stdio.h>
#include <math.h>
#include "Calculator.h"
#include "Vector2D.h"

int main() {
	Vector2D vec1 = Vector2D(3, 4);
	Vector2D vec2 = Vector2D(2, 6);

	Vector2D addVec = vec1 + vec2;

	printf("X:%lf, Y:%lf ", addVec.x, addVec.y);
}