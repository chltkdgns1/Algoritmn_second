#include <iostream>
using namespace std;

int LowW(int w, int g);
int GSum(int *g, int length);
int QuickSort(int first_left, int first_right, int *numbers);

int main() {
	int w;
	int people;
	int sum;
	cin >> w >> people;

	int *g = new int[people];
	for (int i = 0; i < people; i++) {
		cin >> g[i];
		if (g[i] > w) {
			return 0;
		}
	}
	QuickSort(0, people - 1, g);
	sum = GSum(g, people);
}

int LowW(int w, int g) {
	return (w - g)*(w - g);
}

int GSum(int *g,int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum = sum + g[i];
	}
	return sum;
}

int QuickSort(int first_left, int first_right, int *numbers) { // 치킨 거리 순위
	if (first_left >= first_right) {
		return 0;
	}
	int left = first_left;
	int right = first_right;
	int temp;
	int temp2;
	for (int i = left; i <= right; i++) {
		if (numbers[left] > numbers[i]) {
			if (i - left == 1) {
				temp = numbers[left];
				numbers[left] = numbers[i];
				numbers[i] = temp;
				left = i;
			}
			else {
				temp = numbers[left];
				temp2 = numbers[left + 1];
				numbers[left] = numbers[i];
				numbers[left + 1] = temp;
				numbers[i] = temp2;
				left = left + 1;
			}
		}
	}
	QuickSort(first_left, left - 1, numbers);
	QuickSort(left + 1, first_right, numbers);
}

