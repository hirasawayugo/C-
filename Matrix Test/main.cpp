#include <stdio.h>
#include "Matrix33.h"
#include "Matrix.h"

int main() {
	Matrix33 mn33;
	Matrix33 np33;

	int mn44[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} };
	int np44[4][4] = { {10,20,30,40},{50,60,70,80},{90,100,110,120}, {130,140,150,160} };
	float mn32[3][2] = { {1,2},{3,4},{5,6} };
	int np24[2][4] = { {10,20,30,40},{50,60,70,80} };
	
	float mnX[3] = { 1,2,3 };
	float mnY[3] = { 4,5,6 };
	float mnZ[3] = { 7,8,9 };
	float npX[3] = { 10,20,30 };
	float npY[3] = { 40,50,60 };
	float npZ[3] = { 70,80,90 };

	printf("行列mn   %4.1f, %4.1f, %4.1f\n", mnX[0], mnX[1], mnX[2]);
	printf("         %4.1f, %4.1f, %4.1f\n", mnY[0], mnY[1], mnY[2]);
	printf("         %4.1f, %4.1f, %4.1f\n", mnZ[0], mnZ[1], mnZ[2]);
	printf("                 ×　　　　 \n");
	printf("行列np   %4.1f, %4.1f, %4.1f\n", npX[0], npX[1], npX[2]);
	printf("         %4.1f, %4.1f, %4.1f\n", npY[0], npY[1], npY[2]);
	printf("         %4.1f, %4.1f, %4.1f\n", npZ[0], npZ[1], npZ[2]);
	printf("                 ||　　　　 \n");
	mn33.setValue( mnX, mnY, mnZ );
	np33.setValue(npX, npY, npZ);

	Matrix* mn = new Matrix();

	Matrix33 mult33 = mn33 * np33;
	float (*value)[3] = mult33.getValue();

	printf("        %4.1f,  %4.1f,  %4.1f\n", value[0][0], value[0][1], value[0][2]);
	printf("        %4.1f,  %4.1f,  %4.1f\n", value[1][0], value[1][1], value[1][2]);
	printf("       %4.1f, %4.1f, %4.1f\n", value[2][0], value[2][1], value[2][2]);

}