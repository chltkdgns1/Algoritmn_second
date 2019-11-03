#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	int s = 0, c = 0;
	for (int i = 0; i < a; i++) {
		int x; cin >> x;
		if (c < x) c = x;
	}
	s += c, c = 0;
	for (int i = 0; i < b; i++) {
		int x; cin >> x;
		if (c < x) c = x;
	}
	s += c;
	cout << s << "\n";
}