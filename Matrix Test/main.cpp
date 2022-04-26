#include <stdio.h>
#include "Matrix33.h"
#include "Matrix44.h"

int main() {
	Matrix33 mn33;
	Matrix33 np33;
	Matrix44 mn44;
	Matrix44 np44;
	
	float mnX3[3] = { 1,2,3 };
	float mnY3[3] = { 4,5,6 };
	float mnZ3[3] = { 7,8,9 };
	float npX3[3] = { 10,20,30 };
	float npY3[3] = { 40,50,60 };
	float npZ3[3] = { 70,80,90 };
	mn33.setValue( mnX3, mnY3, mnZ3 );
	np33.setValue(npX3, npY3, npZ3);

	Matrix33 mult33 = mn33 * np33;
	float (*value33)[3] = mult33.getValue();

	float mnX4[4] = { 1, 2, 3, 4 };
	float mnY4[4] = { 5, 6, 7, 8 };
	float mnZ4[4] = { 9,10,11,12 };
	float mnW4[4] = { 13,14,15,16 };
	float npX4[4] = { 10, 20, 30, 40 };
	float npY4[4] = { 50, 60, 70, 80 };
	float npZ4[4] = { 90,100,110,120 };
	float npW4[4] = { 130,140,150,160 };
	mn44.setValue(mnX4, mnY4, mnZ4, mnW4);
	np44.setValue(npX4, npY4, npZ4, npW4);

	Matrix44 mult44 = mn44 * np44;
	float(*value44)[4] = mult44.getValue();

	printf("3 * 3\n");
	printf("çsóÒmn33   %4.1f, %4.1f, %4.1f\n", mnX3[0], mnX3[1], mnX3[2]);
	printf("           %4.1f, %4.1f, %4.1f\n", mnY3[0], mnY3[1], mnY3[2]);
	printf("           %4.1f, %4.1f, %4.1f\n", mnZ3[0], mnZ3[1], mnZ3[2]);
	printf("                   Å~\n");
	printf("çsóÒnp33   %4.1f, %4.1f, %4.1f\n", npX3[0], npX3[1], npX3[2]);
	printf("           %4.1f, %4.1f, %4.1f\n", npY3[0], npY3[1], npY3[2]);
	printf("           %4.1f, %4.1f, %4.1f\n", npZ3[0], npZ3[1], npZ3[2]);
	printf("                   ||\n");
	printf("          %4.1f,  %4.1f,  %4.1f\n", value33[0][0], value33[0][1], value33[0][2]);
	printf("          %4.1f,  %4.1f,  %4.1f\n", value33[1][0], value33[1][1], value33[1][2]);
	printf("         %4.1f, %4.1f, %4.1f\n", value33[2][0], value33[2][1], value33[2][2]);

	printf("4 * 4\n");
	printf("çsóÒmn44   %4.1f, %4.1f, %4.1f, %4.1f\n", mnX4[0], mnX4[1], mnX4[2], mnX4[3]);
	printf("           %4.1f, %4.1f, %4.1f, %4.1f\n", mnY4[0], mnY4[1], mnY4[2], mnY4[3]);
	printf("           %4.1f, %4.1f, %4.1f, %4.1f\n", mnZ4[0], mnZ4[1], mnZ4[2], mnZ4[3]);
	printf("           %4.1f, %4.1f, %4.1f, %4.1f\n", mnW4[0], mnW4[1], mnW4[2], mnW4[3]);
	printf("                      Å~\n");
	printf("çsóÒnp44   %4.1f,  %4.1f,  %4.1f,  %4.1f\n", npX4[0], npX4[1], npX4[2], npX4[3]);
	printf("           %4.1f,  %4.1f,  %4.1f,  %4.1f\n", npY4[0], npY4[1], npY4[2], npY4[3]);
	printf("           %4.1f, %4.1f, %4.1f, %4.1f\n", npZ4[0], npZ4[1], npZ4[2], npZ4[3]);
	printf("          %4.1f, %4.1f, %4.1f, %4.1f\n", npW4[0], npW4[1], npW4[2], npW4[3]);
	printf("                      ||\n");
	printf("          %4.1f, %4.1f, %4.1f, %4.1f\n", value44[0][0], value44[0][1], value44[0][2], value44[0][3]);
	printf("         %4.1f, %4.1f, %4.1f, %4.1f\n", value44[1][0], value44[1][1], value44[1][2], value44[1][3]);
	printf("         %4.1f, %4.1f, %4.1f, %4.1f\n", value44[2][0], value44[2][1], value44[2][2], value44[2][3]);
	printf("         %4.1f, %4.1f, %4.1f, %4.1f\n", value44[3][0], value44[3][1], value44[3][2], value44[3][3]);

}