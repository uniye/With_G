#include <stdio.h>

int factorial(int n);
double gcd(int m, int n);
int len(char* word);
void sp(char* word);
void bsp(char* word);
void ipb(int a);

main() {
	int result =factorial(8);
	printf("%d\n", result);

	double result1 = gcd(36,20);
	printf("%.2f\n", result1);

	int result2 = len("one");
	printf("%d\n", result2);

	sp("ILoveChoco");
	printf("\n");

	bsp("ILoveChoco");
	printf("\n");

	ipb(135);
	printf("\n");

}

//int 2진수 출력
void ipb(int a) {
	int share = a / 2;
	int remainder = a % 2;
	if (share <= 1)
		printf("%d", share);
	else
		ipb(share);
	printf("%d", remainder);
	
}

//문자열 길이
int len(char *word) {
	if (*word == '\0')
		return 0;
	else
		return 1 + len(word + 1);
}

//문자열 프린트
void sp(char * word) {
	if (*word == '\0')
		return;
	else {
		printf("%c",word[0]);
		return sp(word+1);
	}	
}

//거꾸로문자열 프린트
void bsp(char* word) {
	if (*word == '\0')
		printf("");
	else {
		bsp(word + 1);
		printf("%c", word[0]);
	}
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