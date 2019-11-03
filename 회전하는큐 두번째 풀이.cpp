#include <iostream>
using namespace std;
void Go();
void PickUp();
void Left();
void Right();

int n, case_, total_cnt = 0,start=0;
int *array_;
int main() {
	cin >> n>>case_;
	array_ = new int[case_ + 1];
	for (int i = 0; i < case_; i++) {
		cin >> array_[i];
	}
	for (int i = 0; i < case_; i++) {
		Go();
	}
	cout << total_cnt << endl;
	system("pause");
}

void Go() {
	if (array_[start] == 1) {
		PickUp();
		return;
	}
	while(array_[start] <= n / 2 ) {
		if (array_[start] == 1) {
			PickUp();
			return;
		}
		Left();
	}
	while (array_[start] > n / 2) {
		if (array_[start] == 1) {
			PickUp();
			return;
		}
		Right();
	}
}

void PickUp() {
	n--;
	start++;
	for (int i = start; i < case_; i++) {
		array_[i]--;
	}
}

void Left() {
	for (int i = start; i < case_; i++) {
		array_[i]--;
		if (array_[i] == 0) {
			array_[i] = n;
		}
	}
	total_cnt++;
}

void Right() {
	for (int i = start; i < case_; i++) {
		array_[i]++;
		if (array_[i] == n + 1) {
			array_[i] = 1;
		}
	}
	total_cnt++;
}