#include <stdio.h>
#include <math.h>

int main() {
	float f = sqrt(2);
	double d = sqrt(2);
	float c = sqrt(2);

	printf("Å„2 = %0.20f\n", f);
	printf("Å„2 = %0.20f\n", d);
	printf("f == d = %d\n", f == d);
	printf("f == c = %d\n", f == c);
	return 0;
}