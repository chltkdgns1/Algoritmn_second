#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int t = 0, max = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (v.empty()) v.push_back(a);
		else {
			if (v.back() < a) {
				t += a - v.back();
				max < t ? max = t : 0;
			}
			else if (v.back() >= a) t = 0;
			v.push_back(a);
		}
	}
	cout << max << "\n";
}