#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s; int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') cnt++;
	}
	cout << cnt + 1 << "\n";
}