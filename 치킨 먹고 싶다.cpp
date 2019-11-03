#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d, t;
		ll e = 0, f = 0;
		cin >> a >> b >> c >> d;
		t = b / a * d; 
		e = t / c;
		while (t / c) {
			cout << t << "\n";
			f += t / c; 
			int q = t / c * d;
			t = t % c + q;
		}
		cout << f - e << "\n";
	}
	system("pause");
}