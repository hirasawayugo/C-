#include <stdio.h>
#include <math.h>
#include "Matrix33.h"
#include "Calculator.h"
#include "Vector2D.h"

int main() {
	Vector2D origin = Vector2D(0, 0);
	Vector2D vec = Vector2D(1, 0);
	Calculator calc = Calculator();
	Matrix33 mat;
	printf("初期座標 X:%0.2f, Y:%0.2f\n",vec.x, vec.y);
	printf("初期角度:%0.1f\n ",calc.angle(origin, vec) *180 / 3.14);

	float angle = 90;
	//度数をラジアンに変換
	angle *= 3.14 / 180;
	//ベクトル１あたりの回転値を求める
	mat.rotate(angle);
	//座標（ベクトル）を掛けて回転させる
	mat * vec;

	printf("座標 X:%0.2f, Y:%0.2f\n", vec.x, vec.y);
	printf("角度:%0.1f \n", calc.angle(origin, vec) * 180 / 3.14);
}