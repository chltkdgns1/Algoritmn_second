#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int dis = 0, mul = 0;
	int a = 0, b = 0;
	for (int i = 1; i < v.size(); i++) {
		if (i == 1) {
			dis = v[i] - v[i - 1];
			mul = v[i] / v[i - 1];
		}
		else {
			if (v[i] - v[i - 1] == dis) a++;
			else if (v[i] / v[i - 1] == mul) b++;
		}
	}
	if (a == v.size() - 2) {
		cout << v[v.size() - 1] + dis << "\n";
	}
	else if (b == v.size() - 2) {
		cout << v[v.size() - 1] * mul << "\n";
	}
}