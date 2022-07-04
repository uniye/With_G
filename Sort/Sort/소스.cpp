#include <iostream>
using namespace std;

void selectionSort(int a[], int n);
void sw(int a[], int m_index, int c_index);
void bubbleSort(int a[], int n);
void insertionSort(int a[], int n);


int main() {
	const int size = 10;
	int a[size] = {10,2,1,5,6,4,3,7,8,9};
	
	//selectionSort(a,size);
	//bubbleSort(a, size);
	insertionSort(a, size);


	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
void sw(int a[], int s, int w) {
	int temp = a[s];
	a[s] = a[w];
	a[w] = temp;
}

//��������
void selectionSort(int a[], int n) { //�ð� ���⵵�� O(n^2)�� �ſ� ��ȿ����
	for (int i = 0; i < n ; i++) {
		int min = i;
		for (int j = i + 1; j < n ; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		sw(a,min,i);
	}
}

//���� ����
void bubbleSort(int a[], int n) {//�ð� ���⵵�� O(n^2)�� �ſ� ��ȿ����
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (a[j - 1] > a[j])
				sw(a,j, j - 1);
		}
	}
}

//��������
void insertionSort(int a[], int n) { //�ּ��� ���� O(n)������ �־��� ���� O(n^2)���� �Է� �ڷᰡ ������ �ƴ� ��츸 ���
	int j;
	for (int i = 1; i < n; i++) {
		int key = a[i];
		for (j = i - 1; j >= 0 && a[j] > key; j--)
			a[j + 1] = a[j];
		a[j + 1] = key;
	}
}