#include <iostream>
using namespace std;

void selectionSort(int a[], int n);
void sw(int a[], int m_index, int c_index);
void bubbleSort(int a[], int n);
void insertionSort(int a[], int n);
void mergeSort(int a[], int first, int last);
void merge(int a[], int first, int mid, int last);
void quickSort(int a[], int left, int right);
int partition(int a[], int m, int n);
void heapSort(int a[], int size);
void heapify(int a[], int h, int m);

int main() {
	const int size = 10;
	int a[size] = {10,2,1,5,6,4,3,7,8,9};
	int a1[size] = {0,10,2,1,5,6,4,3,7,8 };
	//selectionSort(a,size);
	//bubbleSort(a, size);
	//insertionSort(a, size);
	//mergeSort(a, 0, size-1);
	//quickSort(a,0,size-1);
	heapSort(a1,size);
	for (int i = 0; i < 10; i++) {
		cout << a1[i] << " ";
	}

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

//������
void heapSort(int a[], int size) { //�ð����⵵�� O(nlogn)�̴�.
	int n = size - 1;
	for (int i = n / 2; i >= 1; i = i - 1) {
		heapify(a, i, n);
	}
	for (int i = n - 1; i >= 1; i = i - 1) {
		sw(a,1,i+1);
		heapify(a, 1, i);
	}
}

void heapify(int a[], int h, int m) {
	int root = a[h];
	int j = 0;
	for (j = 2 * h; j <= m; j = 2 * j) {
		if (j < m) {
			if (a[j] < a[j + 1])
				j = j + 1;
		}
		if (root >= a[j])
			break;
		else
			a[j / 2] = a[j];
	}
	a[j / 2] = root;
}



//�պ�����
void mergeSort(int a[], int first, int last) { //�ð����⵵�� O(nlogn)�̴�.
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(a, first, mid);
		mergeSort(a, mid + 1, last);
		merge(a,first,mid,last);
	}
	 
}

void merge(int a[], int first, int mid, int last) {
	int *sorted = new int[last-first+1];
	int i, j, k;
	i = first;		
	j = mid + 1;	
	k = 0;			
	while (i <= mid && j <= last){
		if (a[i] <= a[j]) sorted[k++] = a[i++];
		else sorted[k++] = a[j++];
	}
	if (i > mid)
		while (j <= last) sorted[k++] = a[j++];
	else
		while (i <= mid) sorted[k++] = a[i++];
	for (i = first, k = 0; i <= last; i++, k++) a[i] = sorted[k];
	delete[] sorted;
}

//��������: ��յ� ����
void quickSort(int a[], int left, int right) {//�־��� ��� O(n^2) ������ ��� O(nlogn)
	if (left < right) {
		int  p= partition(a, left, right); 
		quickSort(a, left, p - 1); 
		quickSort(a, p + 1, right); 
	}
}

int partition(int a[], int m, int n) {
	int temp;
	int middle = (m + n) / 2;
	int pivot = a[middle];
	a[middle] = a[m];
	a[m] = pivot;
	int p = m;
	for (int k = m + 1; k <= n; k++) {
		if (a[k] < pivot) {
			p = p + 1;
			sw(a,p,k);
		}
	}
	sw(a,m,p);
	return p;
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