#include <stdio.h>
#include <math.h>
#include "Matrix33.h"
#include "Calculator.h"
#include "Vector2D.h"

int main() {
	Vector2D vec1 = Vector2D(1, 0);
	Vector2D vec2 = Vector2D(0, 1);
	printf("初期座標: X:%0.1f Y:%0.1f\n", vec1.x, vec1.y);

	Matrix33 mat;
	mat.Move(vec2);
	Vector2D moveVec = mat * vec1;
	printf("移動座標: X:%0.1f Y:%0.1f\n", moveVec.x, moveVec.y);

	double radian = 90 * 3.14 / 180;
	mat.Rotate(radian);
	Vector2D rotateVec = mat * vec1;
	printf("回転+移動座標: X:%0.1f Y:%0.1f\n", rotateVec.x, rotateVec.y);
}