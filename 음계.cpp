#include <iostream>
using namespace std;

int main() {
	int array[8];
	int cnt_p = 0;
	int cnt_m = 0;
	for (int i = 0; i < 8; i++) cin >> array[i];
	for (int i = 0; i < 7; i++) {
		if (array[i] - array[i + 1] == -1 && i != 7) {
			cnt_p++;
			cnt_m = 0;
			continue;
		}
		else if (array[i] - array[i + 1] == 1 && i != 7) {
			cnt_m++;
			cnt_p = 0;
			continue;
		}
		cnt_p = 0;
		cnt_m = 0;
	}
	if (cnt_p == 7) {
		cout << "ascending" << endl;
		return 0;
	}
	if (cnt_m == 7) {
		cout << "descending" << endl;
		return 0;
	}
	cout << "mixed" << endl;
}