#include <stdio.h>

int factorial(int n);
double gcd(int m, int n);

main() {
	int result =factorial(8);
	printf("%d\n", result);

	double result1 = gcd(36,20);
	printf("%f", result1);
}

//최대 공약수
double gcd(int m, int n) {
	if (m < n) {
		int tmp = m;
		m = n;
		n = tmp;
	}
	if (m % n == 0)
		return n;
	else
		return gcd(n, m % n);
}

int factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}