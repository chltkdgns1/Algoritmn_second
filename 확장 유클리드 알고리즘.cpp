#include <iostream>
typedef long long ll;
using namespace std;

ll a, b;
void extended_gcd(ll x, ll y) {
	ll s1 = 1, s2 = 0, t1 = 0, t2 = 1, r1 = a, r2 = b,q;

	while (r2 != 0) {
		q = r1 / r2;
		r2 = r1 - q * r2;
		r1 = r2;
		s2 = s1 - q * s2;
		s1 = s2;
		t2 = t1 - q * t2;
		t1 = t2;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

}