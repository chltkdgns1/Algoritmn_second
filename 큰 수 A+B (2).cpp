#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void sameline(string &a, string &b) {
	if (a.length() < b.length()) swap(a, b);
	string t; 
	for (int i = 0; i < a.length() - b.length();i++) t += '0';
	b.insert(0, t);
}
string cal(string &a, string &b) {
	string res;
	int up = 0; // 더해서 10이 넘는 경우
	for (int i = a.length() - 1; i >= 0; i--) {
		int x = a[i] - 48, y = b[i] - 48;
		res += (x + y + up) % 10 + 48;
		up =  (up + x + y) / 10;
	}
	if (up) res += (up + 48);
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b; cin >> a >> b;
	sameline(a, b);
	cout << cal(a, b) << "\n";
}