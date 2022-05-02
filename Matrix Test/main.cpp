#include <stdio.h>
#include <math.h>
#include "Matrix33.h"
#include "Calculator.h"
#include "Vector2D.h"

int main() {
	Vector2D vec1 = Vector2D(1, 0);
	Vector2D vec2 = Vector2D(0, 1);

	double crossProdct = vec1.Cross(vec2);
	printf("外積:%0.1f \n", crossProdct);

	Matrix33 mat;
	mat.Move(vec2);
	Vector2D moveVec = mat * vec1;
	printf("移動座標: X:%0.1f Y:%0.1f\n", moveVec.x, moveVec.y);
}