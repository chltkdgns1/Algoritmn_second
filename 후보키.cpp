#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

vector <string> v[20];
vector <vector<string>> t;
int d[(1 << 8)];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// 6 4

	int a, b; cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			string c; cin >> c;
			v[i].push_back(c);
		}
	}
	for (int i = 1; i <= (1 << b) - 1; i++) { // 64
		for (int z = 0; z < a - 1; z++) { // 20 
			bool ch = 0;
			for (int w = z + 1; w < a; w++) { // 20
				int c = 0, d = 0;
				for (int k = 0; k < b; k++) {
					if (i & (1 << k)) {
						c++;
						if (v[z][k] == v[w][k]) d++;
					}
				}

				if (c == d) {
					ch = 1;
					break;
				}
			}
			if (ch) {
				d[i] = -1;
				break;
			}
		}
	}

	int cnt = 0;
	vector <int> q;
	for (int i = 1; i <= (1 << b) - 1; i++) {
		if (!d[i]) q.push_back(i);
	}
	
	for (auto a : q) {
		for (int k = 1; k <= (1 << b) - 1; k++) {
			if ((a & k) == a && a != k) {
				cout << k << "\n";
				d[k] = -1;
			}
		}
	}
	for (int i = 1; i <= (1 << b) - 1; i++) {
		if (!d[i]) cnt++;
	}
	cout << cnt << "\n";
	system("pause");
}