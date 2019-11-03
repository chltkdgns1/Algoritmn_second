#include <iostream>
using namespace std;
bool die[5001];
int a[5001], idx;
int main() {
	int n, m;
	cin >> n >> m;
	int go = 0, cnt = 0;
	if (n == 1) {
		cout << "<" << 1 << ">";
		return 0;
	}
	while (1) {
		bool br = 0;
		for (int i = 1; i <= n; i++) {
			if (!die[i]) go++;
			if (go == m) {
				die[i] = true;
				a[idx++] = i; cnt++; go = 0;
				if (cnt == n) { br = 1; break; }
			}
 		}
		if (br) break;
	}
	for (int i = 0; i < idx; i++) {
		if (!i) cout << "<" << a[i] << ", ";
		else if (i == idx - 1) cout << a[i] << ">";
		else cout << a[i] << ", ";
	}
}