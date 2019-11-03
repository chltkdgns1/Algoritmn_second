#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	double a, b, c; 
	while (cin >> a >> b >> c) {
		int cnt = 0;
		while (a <= c) {
			a = a * b / 100 + a;
			cnt++;
		}
		cout << cnt << "\n";
	}
}