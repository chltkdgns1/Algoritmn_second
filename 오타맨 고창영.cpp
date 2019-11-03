#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string s;
		cin >> a >> s;
		for (int i = 0; i < s.length(); i++) {
			if (i == a - 1) continue;
			cout << s[i];
		}
		cout << "\n";
	}
}