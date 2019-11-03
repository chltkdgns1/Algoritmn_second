#include <iostream>
#include <map>
using namespace std;

map <long long, long long> m;
int main() {
	long long s,e;
	int n , cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		m.insert(make_pair(e, s));
	}
	map <long long, long long>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter == m.begin()) {
			s = iter->second;
			e = iter->first;
			cnt++;
		}
		else {
			if (iter->second >= e) {
				s = iter->second;
				e = iter->first;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}