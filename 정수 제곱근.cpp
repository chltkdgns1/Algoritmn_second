#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
const int INF = 1e9;
int main() {
	long long n;
	cin >> n;
	ll l = 0,r = INF * 4ll,ans = 0;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (1ull * m * m >= n) {
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans;
}