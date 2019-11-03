#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, Max = 0, high = 0; cin >> n;
	int d = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		if (Max < a) Max = a,d = 1;
		else if (Max == a) d++;
	}
	int res, a = 0,b = 0,c = 0;
	for (int i = 0; i < n - 1 ; i++) {
		high = max(high, v[i]);
		if (high == Max) {
			if (v[i] == Max) d--;
			if (!d) b++;
			else c++;
		}
		else a++;
	}
	if (a > b) cout << "B" << "\n";
	else if (a == b) cout << "X" << "\n";
	else cout << "R" << "\n";
}