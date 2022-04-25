#include <stdio.h>
#include "Matrix33.h"

int main() {
	Matrix33* mn33 = new Matrix33();
	Matrix33* np33 = new Matrix33();

	int np33[3][3] = { {10,20,30},{40,50,60},{70,80,90} };
	int mn44[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} };
	int np44[4][4] = { {10,20,30,40},{50,60,70,80},{90,100,110,120}, {130,140,150,160} };
	int mn[3][2] = { {1,2},{3,4},{5,6} };
	int np[2][4] = { {10,20,30,40},{50,60,70,80} };
	
	float mnX[3] = { 1,2,3 };
	float mnY[3] = { 4,5,6 };
	float mnZ[3] = { 7,8,9 };
	float npX[3] = { 10,20,30 };
	float npY[3] = { 40,50,60 };
	float npZ[3] = { 70,80,90 };


	mn33->setValue( mnX, mnY, mnZ );
	np33->setValue(npX, npY, npZ);

	Matrix33 mult33 = mn33 * np33;

}