#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		map <int, string> m;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int a; string s;
			cin >> a >> s;
			m[a] = s;
		}
		map <int,string>::iterator it = m.end();
		it--;
		cout << (*it).second << "\n";
	}
}