#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		map <string, int> m;
		int n;
		cin >> n;
		map <string, int>::iterator iter;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			iter = m.find(b);
			if (iter != m.end()) (*iter).second++;
			else m.insert({ b,1 });
		}
		long long total = 1;
		for (iter = m.begin(); iter != m.end(); iter++) {
			total *= ((*iter).second + 1);
		}
		cout << total - 1<< "\n";
	}
}