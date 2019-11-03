#include <iostream>
using namespace std;
int PickUp();
void Left();
void Right();
void Go(int number);
void CleanQue();

int *array_;
int *array_case;
int total_cnt = 0;
int n;
int main() {
	int case_;
	cin >> n;
	cin >> case_;
	array_ = new int[n];
	array_case = new int[n];
	for (int i = 0; i < n; i++) {
		array_[i] = i + 1;
	}
	for (int i = 0; i < case_; i++) {
		cin >> array_case[i];
	}
	for (int i = 0; i < case_; i++) {
		Go(array_case[i]);
	}
	cout << total_cnt << endl;
	//system("pause");
}

void Go(int number) {
	for (int i = 0; i < n; i++) {
		if (array_[i] == number) {
			if (i == 0 ) {
				PickUp();
				CleanQue();
				return;
			}
			else if (i <= n / 2 ) {
				for (int j = 0; j < i; j++) {	
					Left();
					total_cnt++;
				}
				PickUp();
				CleanQue();
				return;
			}
			else if(i > n/2){
				for (int j = 0; j < n - i; j++) {
					Right();
					total_cnt++;
				}
				PickUp();
				CleanQue();
				return;
			}
		}
	}
}

void CleanQue() {
	for (int i = 0; i < n; i++) {
		array_[i] = array_[i + 1];
	}
	array_[n - 1] = 0;
	n --;
}

int PickUp() {
	int index = array_[0];
	array_[0] = 0;
	return index;
}

void Left() {
	int temp = array_[0];
	for (int i = 0; i < n - 1 ; i++) {
		array_[i] = array_[i + 1];
	}
	array_[n - 1] = temp;
}

void Right() {
	int temp = array_[0];
	for (int i = n - 1; i > 0; i--) {
		if (i == n - 1) {
			array_[0] = array_[n - 1];
			continue;
		}
		array_[i + 1] = array_[i];
	}
	array_[1] = temp;
}
