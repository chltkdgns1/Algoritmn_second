#include <iostream>
using namespace std;

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
}