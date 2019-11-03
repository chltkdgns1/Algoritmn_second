#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v, r, e;
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
	for (int i = 0; i < v.size(); i++) {
		e.push_back(arr[v[i]]);
	}
	for (int i = 0; i < n; i++) {
		bool ch = 0;
		if (brr[v[i]] > i) {
			cout << v[brr[v[i]]] << " ";
			continue;
		}
		if (brr[v[i]] == 987654321) {
			cout << -1 << " ";
			continue;
		}
		for (int k = i + 1; k < n; k++) {
			if (arr[v[i]] < e[k]) {
				ch = 1;
				cout << v[k] << " ";
				brr[v[i]] = k;
				break;
			}
		}
		if (!ch) {
			brr[v[i]] = 987654321;
			cout << -1 << " ";
		}
	}
	system("pause");
}