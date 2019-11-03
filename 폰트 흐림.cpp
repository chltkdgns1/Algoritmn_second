#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) cout << char(s[i] + 32);
		if (s[i] >= 97 && s[i] <= 122) cout << char(s[i] - 32);
	}
}