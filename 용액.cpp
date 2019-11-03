#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <int> v, e;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a < 0) v.push_back(a);
		else e.push_back(a);
	}
	if (v.empty()) {
		cout << e[0] << " " << e[1];
		return 0;
	}
	else if (e.empty()) {
		cout << v[v.size() - 2] << " " << v[v.size() - 1];
		return 0;
	}
	int a, b, c=987654321;
	for (int i = 0; i < v.size(); i++) {
		int d = lower_bound(e.begin(), e.end(), -v[i]) - e.begin();
		if (d == 0) {
			int x = abs(v[i] + e[d]);
			if (x < c) {
				c = x;
				a = v[i], b = e[d];
			}
		}
		else if (d >= e.size()) {
			int y = abs(v[i] + e[d - 1]);
			if (y < c) {
				c = y;
				a = v[i], b = e[d - 1];
			}
		}
		else {
			int x = abs(v[i] + e[d]);
			int y = abs(v[i] + e[d - 1]);
			if (x < y && x < c) {
				c = x;
				a = v[i], b = e[d];
			}
			else if (x >= y && y < c) {
				c = y;
				a = v[i], b = e[d - 1];
			}
		}
	}
	cout << a << " " << b << "\n";
}