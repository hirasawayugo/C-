#include <stdio.h>
#include "Matrix33.h"

int main() {
	Matrix33* mat33 = new Matrix33();
	int mn22[2][2] = { {1,2},{3,4} };
	int np22[2][2] = { {10,20},{30,40} };
	int mn33[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int np33[3][3] = { {10,20,30},{40,50,60},{70,80,90} };
	int mn44[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} };
	int np44[4][4] = { {10,20,30,40},{50,60,70,80},{90,100,110,120}, {130,140,150,160} };
	int mn[3][2] = { {1,2},{3,4},{5,6} };
	int np[2][4] = { {10,20,30,40},{50,60,70,80} };
	
	float x[3] = { 1,0,0 };
	float y[3] = { 0,1,0 };
	float z[3] = { 0,0,1 };

	mat33->setValue( x, y, z );

}