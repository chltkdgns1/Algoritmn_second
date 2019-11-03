#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v, r;
int arr[1000001];
int brr[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		arr[a]++;
	}
	for (int i = n - 1; i >= 0; i--) {
		bool ch = 0;
		if (brr[v[i]] == 987654321) {
			r.push_back(-1);
			continue;
		}
		if (brr[v[i]] > i) {
			r.push_back(v[brr[v[i]]]);
			continue;
		}
		for (int k = i + 1; k < n; k++) {
			if (arr[v[i]] < arr[v[k]]) {
				ch = 1;
				r.push_back(v[k]);
				brr[v[i]] = k;
				break;
			}
		}
		if (!ch) {
			brr[v[i]] = 987654321;
			r.push_back(-1);
		}
	}
	for (int i = n - 1; i >= 0; i--) cout << r[i] << " ";
}