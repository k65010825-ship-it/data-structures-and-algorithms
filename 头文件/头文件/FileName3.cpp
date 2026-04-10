#include"operations.h"
int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d\n", add(a, b));
	double c, d;
	scanf_s("%lf %lf", &c, &d);
	printf("%lf\n", average(c, d));
	return 0;
}