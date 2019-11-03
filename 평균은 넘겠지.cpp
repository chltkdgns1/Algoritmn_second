#include <iostream>
using namespace std;

int main() {
	int test_case, n;
	int temp = 0;
	int array[1001];
	int cnt = 0;
	double aver;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> array[j];
			temp += array[j];
		}
		aver = (double)temp / n;
		temp = 0;
		for (int j = 0; j < n; j++) {
			if ((double)array[j] > aver) {
				cnt++;
			}
			array[j] = 0;
		}
		printf("%.3lf", ((double)cnt / n) * 100);
		cout << "%\n";
		cnt = 0;
	}
}