#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		int cnt = 1, max = 0;
		char d;
		for (int k = 0; k < s.length(); k++) {
			if (!k) d = s[k];
			else {
				if (d == s[k]) cnt++;
				else {
					if (max < cnt) max = cnt;
					cnt = 1, d = s[k];
				}
			}
		}
		if (max < cnt) max = cnt;
		cout << max << "\n";
	}
}