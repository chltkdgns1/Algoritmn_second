#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
pair<int, string> arr[3];
string e[3] = { "Adrian","Bruno","Goran" };
string st(string a) {
	string t = a;
	while (a.length() < n) a += t;
	return a;
}
bool cmp(pair<int, string> &a, pair <int, string> &b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	string s,a,b,c; cin >> s;
	a = "ABC", b = "BABC", c = "CCAABB";
	a = st(a), b = st(b), c = st(c);
	for (int i = 0; i < 3; i++) arr[i].second = e[i];
	for (int i = 0; i < n; i++) {
		if (s[i] == a[i]) arr[0].first++;
		if (s[i] == b[i]) arr[1].first++;
		if (s[i] == c[i]) arr[2].first++;
	}
	sort(arr, arr + 3, cmp);
	int max = arr[0].first;
	cout << max << "\n";
	for (int i = 0; i < 3; i++) {
		if (max == arr[i].first) cout << arr[i].second << "\n";
	}
}