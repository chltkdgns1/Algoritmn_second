#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, total = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; 
		v.push_back(a);
	}
	ll left=0, right = 2000000000, mid, res = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int t = 0;
		if (!mid) break;
		for (int i = 0; i < v.size(); i++) t += (v[i] / mid);
		if (m <= t) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (!mid) { cout << 0 << "\n"; return 0;}
	ll t = 0;
	for (int i = 0; i < v.size(); i++) {
		t += v[i];
	}
	cout << t - m * res << "\n";
}
