#include <iostream>
#include <algorithm>
typedef double d;
using namespace std;

bool go(d x1, d y1, d x2, d y2 ,d xpos) {
	d y = (y2 - y1) / (x2 - x1) * (xpos - x1) + y1;
	int t_y = y;
	if ((y - (double)t_y) == 0) return true;
	return false;
}
int main() {
	int n, m, k;
	int key_cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= 50; j++) {
			if (i != m && j != n) {
				int cnt = 0;
				int x1 = min(n, j);
				int x2 = max(n, j);
				for (int k = x1; k <= x2; k++) {
					if (go(n, m, j, i, k)) cnt++;
				}
				if (cnt == k) {
					cout << j << " " << i << "\n";
					key_cnt++;
				}
			}
		}
	}
	cout << key_cnt << "\n";
	system("pause");
}