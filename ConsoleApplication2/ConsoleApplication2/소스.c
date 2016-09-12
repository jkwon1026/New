#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#define RAND_MAX 0x7fff
#pragma warning(disable:4996) 

double getRandomNumber(const double min, const double max);
bool isInsideCircle(const double x, const double y);

void main() {
	FILE *of = fopen("circle.txt", "w");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++) {
		double x = getRandomNumber(0, 1);
		double y = getRandomNumber(0, 1);


		if (isInsideCircle(x, y))
			fprintf(of, "%f \t %f\n", x, y);


	}
	fclose(of);
}


double getRandomNumber(const double min, const double max) {
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}

bool isInsideCircle(const double x, const double y) {
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f > 0.0) return false;
	else return true;

}