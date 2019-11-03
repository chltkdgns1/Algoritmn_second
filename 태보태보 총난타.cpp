#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') c = 1;
		if (!c && s[i] == '@') a++;
		if (c && s[i] == '@') b++;
	}
	cout << a << " " << b << "\n";
}