#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (!a && !b && !c && !d) break;
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		cout << c - b << " " << d - a << "\n";
	}
}