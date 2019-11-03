#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	list <char> d;
	list <char>::iterator it;
	cin >> s;
	for (int i = 0; i < s.length(); i++) d.push_back(s[i]);
	it = d.end();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a;
		if (a == 'P') {
			cin >> b;
			if (it == d.begin()) d.push_front(b);
			else if (it == d.end()) {
				d.push_back(b);
				it = d.end();
			}
			else {
				it = d.insert(it, b);
				it++;
			}
		}
		if (a == 'L') if(it != d.begin()) it--;
		if (a == 'D') if(it != d.end()) it++;
		if (a == 'B') {
			if (it != d.begin()) {
				it--;it = d.erase(it);
			}
		}
	}
	for (auto a : d) cout << a;
}