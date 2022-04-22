#include <stdio.h>
#include "Matrix.h"

int main() {
	Matrix mat;
	int mn22[2][2] = { {1,2},{3,4} };
	int np22[2][2] = { {10,20},{30,40} };
	int mn33[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int np33[3][3] = { {10,20,30},{40,50,60},{70,80,90} };
	int mn44[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} };
	int np44[4][4] = { {10,20,30,40},{50,60,70,80},{90,100,110,120}, {130,140,150,160} };
	int mn[3][2] = { {1,2},{3,4},{5,6} };
	int np[2][4] = { {10,20,30,40},{50,60,70,80} };

	int **value22 = mat.mult22(mn22, np22);
	int **value33 = mat.mult33(mn33, np33);
	int **value44 = mat.mult44(mn44, np44);
	int **value   = mat.mult(mn, np);

	puts("2*2");
	for (int i = 0; i < 2; i++ ) {
		for (int j = 0; j < 2; j++ ) {
			printf("%d, ",value22[i][j]);
		}
		printf("\n");
	}
	//3*3
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += mn33[i][k] * np33[k][j];
			}
			value33[i][j] = sum;
		}
	}
	puts("3*3");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d, ", value33[i][j]);
		}
		printf("\n");
	}
	//4*4
	puts("4*4");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d, ", value44[i][j]);
		}
		printf("\n");
	}
	//mn*np(32*24)
	puts("mn*np(32*24)");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d, ", value[i][j]);
		}
		printf("\n");
	}
}