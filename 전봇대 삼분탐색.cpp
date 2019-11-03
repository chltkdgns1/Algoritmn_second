#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, arr[100001];
ll min1 = 1e18;
ll calc(ll mid) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(i*mid - arr[i]);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll s = 0, e = 1e9, l, r;
	while (s + 3 <= e) {
		int l = (s * 2 + e) / 3;
		int r = (s + e * 2) / 3;
		ll l_c = calc(l);
		ll r_c = calc(r);
		if (l_c < r_c) e = r;
		else s = l;
	}
	for (int i = s; i <= e; i++) {
		min1 = min(min1, calc(i));
	}
	cout << min1 << "\n";
}