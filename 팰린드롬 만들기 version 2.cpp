#include <iostream>
#include <string>
using namespace std;
bool check(string s) {
	int st = 0, end = s.length() - 1;
	while (st <= end) {
		if (s[st] != s[end]) return false;
		st++, end--;
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	if (check(s)) {
		cout << s.length() << "\n";
		return 0;
	}
	for (int i = 0; i < s.length(); i++) {
		string t = s,add;
		for (int k = i; k >= 0; k--) add += s[k];
		t += add;
		if (check(t)) {
			cout << t.length() << "\n";
			break;
		}
	}
}

// ababbaba 이게 가장 길지