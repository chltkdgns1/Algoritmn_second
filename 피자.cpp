#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "1/2") a++;
		else if (s == "1/4") b++;
		else if (s == "3/4") c++;
	}
	int t = 0;
	t += c;
	b = b - c <= 0 ? 0 : b - c;
	t += a / 2;
	a %= 2;
	if (a == 1) 	b -= 2;
	t += (b / 4);
	b %= 4;
	t += b == 0 ? 0 : 1;
	cout << t << "\n";
}