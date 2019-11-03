#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	while (n--) {
		vector <int> v;
		for (int k = 0; k < 5; k++) {
			int a; cin >> a; v.push_back(a);
		}
		sort(v.begin(), v.end());
		if (v[3] - v[1] >= 4) cout << "KIN" << "\n";
		else cout << v[1] + v[2] + v[3] << "\n";
	}
}