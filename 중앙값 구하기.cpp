#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt = 0;
		vector <int> v, e;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			v.push_back(a);
			if (i % 2) {
				sort(v.begin(), v.end());
				e.push_back(v[i / 2]);
				cnt++;
			}
		}
		cout << cnt << "\n";
		for (int i = 0; i < e.size(); i++) {
			cout << e[i] << " ";
		}
		cout << "\n";
	}
}