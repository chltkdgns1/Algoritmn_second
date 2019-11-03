#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll sum(vector <int> &v) {
	ll s = 0;
	for (int i = 0; i < v.size(); i++) {
		s += v[i];
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << sum(v) << "\n";
}