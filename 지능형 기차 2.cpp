#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x = 0, res = 0;
	for (int i = 0; i < 10; i++) {
		int a, b; cin >> a >> b;
		x += (b - a);
		res < x ? res = x : 0;
	}
	cout << res << "\n";
}