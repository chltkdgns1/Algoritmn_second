#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	string t; 
	while (n) {
		if (n % m >= 0 && n%m <= 9) t += n % m + 48;
		else t += n % m + 55;
		n /= m;
	}
	reverse(t.begin(), t.end());
	cout << t << "\n";
}