#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector <int> v;
int main() {
	int n, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	sort(v.begin(), v.end());
	do {
		int t = 0;
		for (int i = 0; i < n - 1; i++) {
			t += abs(v[i] - v[i + 1]);
		}
		if (t > m) m = t;
	} while (next_permutation(v.begin(), v.end()));
	cout << m << "\n";
}