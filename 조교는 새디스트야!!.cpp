#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, c = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a != i) c++;
	}
	cout << c << "\n";
}