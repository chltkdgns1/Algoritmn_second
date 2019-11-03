#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	set <string> s;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (b == "enter") s.insert(a);
		else if (b == "leave") s.erase(s.find(a));
	}
	set <string>::iterator iter;
	vector <string> v;
	for (iter = s.begin(); iter != s.end(); iter++) {
		v.push_back(*iter);
	}
	for (int i = v.size() - 1; i>= 0; i--) cout << v[i] << "\n";
}