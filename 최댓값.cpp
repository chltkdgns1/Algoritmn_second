#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a = 0, b = 0;
	for (int i = 0; i < 9; i++) {
		int c; cin >> c;
		if (a < c) a = c, b = i;
	}
	cout << a << "\n" << b + 1 << "\n";
}