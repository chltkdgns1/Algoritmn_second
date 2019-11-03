#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set <int> s;
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
		cout << *itr << " ";
	}
}