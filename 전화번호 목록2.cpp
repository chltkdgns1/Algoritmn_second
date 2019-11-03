#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string phone;
		set <string> s;
		for (int i = 0; i < n; i++) {
			cin >> phone;
			s.insert(phone);
		}
		int br = 0 ,sr = 0;
		for (set <string>::iterator iter = s.begin(); iter != s.end(); iter++) {
			for (set <string>::iterator iter2 = iter; iter2 != s.end(); iter2++) {
				if ((*iter) != (*iter2)) {
					int cnt = 0;
					for (int i = 0; i < (*iter).length(); i++) {
						if ((*iter)[i] == (*iter2)[i]) cnt++;
						else {	sr = 1;	break;}
					}
					if (sr) {sr = 0;break;}
					if (cnt == (*iter).length()) {
						cout << "NO" << "\n";
						br = 1;
						break;
					}
				}
			}
			if (br) break;
		}
		if (br == 0) cout << "YES" << "\n";
	}
}