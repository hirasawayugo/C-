#include <stdio.h>
#include <math.h>
#include "Matrix33.h"
#include "Vector2D.h"

int main() {
	Vector2D vec1 = Vector2D(0, 0);
	Vector2D vec2 = Vector2D(1, 1);
	//2点の距離を求める(三平方の定理)= √(x1-x2)²+ (y1-y2)²
	//斜辺(距離)
	float diff = sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));

	printf("%lf", diff);
}