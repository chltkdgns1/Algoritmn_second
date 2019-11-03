#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001], d[100001];
int find(int x) {
	if (d[x] == x) return x;
	return d[x] = find(d[x]);
}
void unionContry(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	d[b] = a;
	arr[a] += arr[b];
	arr[b] = 0;
}
void warContry(int a, int b) {
	a = find(a);
	b = find(b);
	if (arr[a] < arr[b]) arr[b] -= arr[a], arr[a] = 0, d[a] = b;
	else if (arr[a] > arr[b]) arr[a] -= arr[b], arr[b] = 0, d[b] = a;
	else arr[b] = 0, arr[a] = 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[i + 1] = a;
		d[i + 1] = i + 1;
	}
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) unionContry(b, c);
		else if(a == 2) warContry(b, c);
	}
	int cnt = 0; 
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		if (arr[i]) {
			cnt++;
			v.push_back(arr[i]);
		}
	}
	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}