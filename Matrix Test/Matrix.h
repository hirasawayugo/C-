#pragma once

class Matrix
{
public:
	Matrix();
	virtual ~Matrix();
public:
	int **mult22(int mn[2][2], int np[2][2]);
	int **mult33(int mn[3][3], int np[3][3]);
	int **mult44(int mn[4][4], int np[4][4]);
	int **mult(int mn[3][2], int np[2][4]);

};

