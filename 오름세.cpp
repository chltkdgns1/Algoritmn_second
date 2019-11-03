#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; 
	while (cin >> n) {
		vector <int> e,v;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		int cnt = 0;
		e.push_back(-987654321);
		for (int i = 0; i < v.size(); i++) {
			if (e.back() < v[i]) {
				cnt++;
				e.push_back(v[i]);
			}
			else e[lower_bound(e.begin(), e.end(), v[i]) - e.begin()] = v[i];
		}
		cout << cnt << "\n";
	}
}