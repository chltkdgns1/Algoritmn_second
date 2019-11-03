#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	int b;
	cin >> s >> b;
	int t = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] >= 48 && s[i] <= 57) t += (s[i] - 48)*pow(b, len - 1 - i);
		else t += (s[i] - 55) * pow(b, len - 1 - i);
	}
	cout << t << "\n";
}