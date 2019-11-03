#include <iostream>
using namespace std;
int uclid(int a, int b) {
	if (!(a%b)) return b;
	uclid(b, a%b);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int d = uclid(a, b);
		cout << a / d * b / d * d << " " << d << "\n";
	}
}