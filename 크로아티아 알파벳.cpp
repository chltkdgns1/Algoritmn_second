#include <iostream>
#include <string>
using namespace std;

string e[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == s.length() - 1) cnt++;
		else {
			for (int k = 0; k < 8; k++) {
				bool ch = 0;
				int d = 0;
				for (; d < e[k].length(); d++) {
					if (e[k][d] != s[i + d]) {
						ch = 1; break;
					}
				}
				if (!ch) {
					i += d - 1;
					break;
				}
			}
			cnt++;
		}
	}
	cout << cnt << "\n";
}