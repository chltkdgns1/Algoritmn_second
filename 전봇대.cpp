#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int arr[100001], n;
ll calDistance(ll mid) {
	ll res = 0;
	for (int i = 0; i < n; i++) res += abs((i*mid) - arr[i]);
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll left = 1, right = 1e9;
	ll costL, costR;
	while (left + 3 <= right) {
		ll l = (left * 2 + right) / 3;
		ll r = (left + 2 * right) / 3;
		costL = calDistance(l);
		costR = calDistance(r);
		if (costL < costR) right = r;
		else  left = l;
	}
	ll min1 = 1e18;
	cout << left << " " << right << "\n";
	for (int i = left; i <= right; i++) {
		min1 = min(min1, calDistance(i));
	}
	cout << min1 << "\n";
}