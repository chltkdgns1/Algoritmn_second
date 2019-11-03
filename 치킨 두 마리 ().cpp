#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c; cin >> a >> b >> c;
	if (!c || (a + b) / c >= 2) {
		cout << a + b - 2 * c;
	}
	else cout << a + b << "\n";
}