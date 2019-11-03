#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a,b;
	cin >> a >> b;
	string t;
	while (a) {
		if (a % b >= 0 && a % b <= 9) t += a % b + 48;
		else t += a % b + 55;
		a /= b;
	}
	reverse(t.begin(), t.end());
	cout << t << "\n";
}