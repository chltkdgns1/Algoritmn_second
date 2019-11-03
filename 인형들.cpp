#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

typedef long double doble;
typedef long long ll;

ll dp1[501], dp2[501];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		if (i == 1) dp1[i] = a, dp2[i] = a * a;
		else dp1[i] = dp1[i - 1] + a, dp2[i] = dp2[i - 1] + a * a;
	}

	cout << fixed << setprecision(6);
	doble res = 1e18;
	for (int i = 1; i <= n; i++) {
		for (int k = i + m - 1; k <= n; k++) {
			ll q = dp1[k] - dp1[i - 1];
			ll w = dp2[k] - dp2[i - 1];
			doble t = doble(q) / (k - i + 1); // »ê¼ú Æò±Õ
			doble e = doble(w - 2 * q * t + (k - i + 1) * t * t)/ (k - i + 1); 
			doble z = sqrt(e);
			if (res > z) res = z;
		}
	}
	cout << res << "\n";
}