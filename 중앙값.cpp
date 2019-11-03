#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll dp[250001],d[5001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	d[1] = 0;
	for (int i = 2; i <= 5000; i++) {
		d[i] = d[i - 1] + i - 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (!i) dp[i] = v[i];
		else dp[i] = dp[i - 1] + v[i];
	}
	ll res = 0;
	for (int i = k - 1; i < n; i++) {
		if (i == k - 1) {
			if (dp[i] == v[i - k + 1] * k + d[k]) {
				res += v[(2*i - k + 1) / 2];
			}
		}
		else {
			if (dp[i] - dp[i - k] == v[i - k + 1] * k + d[k]) {
				res += v[(2 * i - k + 1) / 2];
			}
		}
	}
	cout << res << "\n";
}