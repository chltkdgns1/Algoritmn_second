#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int test_case;
	int m, n, x, y;
	int cnt = 0;
	int k = 0;
	int k_ = 0;
	int start_x = 1, start_y = 1;
	int temp;
	int temp_;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> m >> n >> x >> y;
		if (m - n > 0) temp = m - n , k_ = m;
		else temp = n - m, k_ = n;
		temp_ = temp;
		while (1) {
			if (x == y) {
				break;
			}
			else if (k_ - temp <= abs(x - y)) {
				k -= k_;
				temp -= temp_;
				break;
			}
			k += k_;
			temp += temp_;
		}
		if (m - n > 0) start_x = k_,start_y = temp;
		else start_x = temp, start_y = k_;
		while (1) {
			if (start_x == m && start_y == n) {
				cout << "-1" << endl;
				break;
			}
			if (start_x == x && start_y == y) {
				cout << k << endl;
				break;
			}
			start_x++;
			if (start_x == m + 1) start_x = 1;
			start_y++;
			if (start_y == n + 1) start_y = 1;
			k++;
		}
		k_ = 0;
		temp = 0;
		temp_ = 0;
		start_x = 1;
		start_y = 1;
		k = 0;
	}
	system("pause");
}


/*
int main() {
	int test_case;
	int m, n, x, y;
	int cnt = 0;
	int k = 1;
	int start_x = 1, start_y = 1;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> m >> n >> x >> y;
		while (1) {
			cout << start_x << " " << start_y << endl;
			if (start_x == m && start_y == n) {
				cout << "-1" << endl;
				break;
			}
			if (start_x == x && start_y == y) {
				cout << k << endl;
				break;
			}
			start_x++;
			if (start_x == m + 1) start_x = 1;
			start_y++;
			if (start_y == n + 1) start_y = 1;
			k++;
		}
		start_x = 1;
		start_y = 1;
		k = 1;
	}
	system("pause");
}*/