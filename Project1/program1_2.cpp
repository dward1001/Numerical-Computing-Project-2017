#include "my_solver.h"

extern double (*_F)(double);
extern double (*_FP)(double);

/*********************************************
  Secant Method
**********************************************/
void program1_2(FILE *fp)
{
	double x0, x1;
	double temp;
	int n;

	fprintf(fp, " n              xn1                  |f(xn1)|\n");
	scanf("%lf %lf", &x0, &x1);

	for(n=0; ;n++) {
		fprintf(fp, "%2d  %20.18e  %12.10e\n", n, x1, fabs(_F(x1)));

		if(fabs(_F(x1))<DELTA || n>=Nmax || fabs(x1-x0)<EPSILON) break;

		temp = x0;
		x0 = x1;
		x1 = x0 - _F(x0)*(x0-temp)/(_F(x0)-_F(temp));
	}
	printf("%2d  %20.18e  %12.10e\n", n, x1, fabs(_F(x1)));
}