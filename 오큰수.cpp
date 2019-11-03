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
	}
	for (int i = 0; i < n; i--) {
		bool ch = 0;
		if (brr[v[i]]) {
			cout << brr[v[i]] << " ";
			continue;
		}
		for (int k = i + 1; k < n; k++) {
			if (v[i] < v[k]) {
				ch = 1;
				brr[v[i]] = v[k];
				cout << v[k] << " ";
				break;
			}
		}
		if (!ch) {
			brr[v[i]] = -1;
			cout << -1 << " ";
		}
	}
	system("pause")
}