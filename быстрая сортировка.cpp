#include <iostream>
#include <ctime>
using namespace std;
void move_to_left(int* array, int begin, int end) {
	int t = array[begin];
	for (int i = begin; i < end; i++) {
		array[i] = array[i + 1];
	}
	array[end] = t;
}void move_to_right(int* array, int begin, int end) {
	int t = array[end];
	for (int i = end; i > begin; i--) {
		array[i] = array[i - 1];
	}
	array[begin] = t;
}int ay() {
	return rand() % 10;
}void write(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}void qsort(int* mas, int begin, int end) {
	if (begin + 1 >= end) {
		return;
	}
	int mid = (begin + end) / 2;
	for (int i = begin; i < end; i++) {
		if (mas[i] > mas[mid] && i < mid) {
			move_to_left(mas, i, mid);
			mid--;
			i--;
		}
		if (mas[i]<mas[mid] && i>mid) {
			move_to_right(mas, mid, i);
			mid++;
		}
	}
	qsort(mas, begin, mid);
	qsort(mas, mid, end);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int const n = 10;
	int a[n], i;
	for (i = 0; i < n; i++) {
		a[i] = ay();
	}
	write(a, n);
	qsort(a, 0, n);
	write(a, n);
}

