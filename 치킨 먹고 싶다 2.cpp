#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, t;
		int e = 0, f = 0;
		cin >> a >> b >> c >> d;
		t = b / a * d;
		(t % c) == 0 ? e = t / c : e = t / c + 1;
		t -= e;
		printf("%d\n", ((t - c) % (c - d) > 0) ? (t - c) / (c - d) + 2  : (t - c) / (c - d) + 1 );
	}
}