#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s,tmp;
		cin >> s;
		int t = 0;
		for (int i = 0; i < 3; i++) t += (s[i] - 65)*pow(26, 2 - i);
		for (int i = 4; i < s.length(); i++) tmp += s[i];
		if (abs(stoi(tmp) - t) <= 100) cout << "nice" << "\n";
		else cout << "not nice" << "\n";
	}
}