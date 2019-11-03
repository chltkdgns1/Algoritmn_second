#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v, e;
bool arr[201];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		arr[a] = 1;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= 2 * n; i++) {
		if (!arr[i]) e.push_back(i);
	}
	int board = -1, a = v.size(), b = e.size();
	int cnt = 0;
	while (a && b) {
		if (!(cnt % 2)) {
			bool ch = 0;
			for (int i = 0; i < v.size(); i++) {
				if (board < v[i]) {
					board = v[i],v[i] = -1;
					ch = 1,a--;
					break;
				}
			}
			if (!ch) {
				board = 0, cnt++;
				continue;
			}
		}
		else {
			bool ch = 0;
			for (int i = 0; i < e.size(); i++) {
				if (board < e[i]) {
					board = e[i], e[i] = -1;
					ch = 1,b--;
					break;
				}
			}
			if (!ch) {
				board = 0, cnt++;
				continue;
			}
		}
		cnt++;
	}
	cout << b << " " << a << "\n";
}