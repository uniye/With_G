#include<iostream>
#define SIZE 20
using namespace std;
void shellsort(int[], int);
void intervalSort(int[], int , int , int );
void show(int[],int);
void radixsort(int[], int);
int getMax(int[], int);
void countSort(int[], int, int);


int main() {
	int a[SIZE] = { 12,5,16,9,15,10,8,13,2,7,17,18,11,4,19,6,3,1,14,20 };
	
	//shellsort(a, SIZE);
	radixsort(a, SIZE);
	//show(a, SIZE);
	return 0;
}
void show(int a[],int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void radixsort(int a[], int n) {//O(dn)
	int m = getMax(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(a, exp,n);
	}
}
void countSort(int a[] , int exp, int n) {
	int output[SIZE] = {};
	int count[10] = {0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < n; i++) {
		count[(a[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (int i = 0; i <n; i++) {
		a[i] = output[i];
	}
}
int getMax(int a[], int n) {
	int mx = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > mx) {
			mx = a[i];
		}
	}
	return mx;
}


void shellsort(int a[], int n) {//최선의 경우: O(N), 최악의 경우: O(N^2), 평균적인 경우: O(N^(1.3, 1.5))
	int interval = n;
	while (interval > 1) {
		interval = 1 + interval / 3;
		for (int i = 0; i < interval; i++) {
			intervalSort(a, i, interval, n);
		}
	}
}
void intervalSort(int a[], int i, int interval, int n) {//서브리스트를 삽입 정렬로 정렬
	int j = i + interval;
	while (j < n) {
		int temp = a[j];
		int k = j;
		bool move = true;
		while (move) {
			if (a[k - interval] <= temp) {
				move = false;
			}
			else {
				a[k] = a[k - interval];
				k = k - interval;
				if (k == i)
					move = false;
			}
		}
		a[k] = temp;
		j = j + interval;
	}

}