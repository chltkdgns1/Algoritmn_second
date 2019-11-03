#include <iostream>
#include <vector>
#include <algorithm>
typedef double dle;
using namespace std;
bool check(vector <pair<dle,dle>> &s,dle w) {
	dle temp = 0.0;
	for (int i = 0; i < s.size(); i++) {
		dle x = s[i].first, y = s[i].second;
		if (!i) {
			if (x != 0.0) return false;
			temp = y;
		}
		else {
			if (temp >= x) temp = y;
			else return false;
		}
		if (i == s.size() - 1 && temp != w) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		vector <pair<dle, dle>> v, e;
		int a, b;
		dle c;
		cin >> a >> b >> c;
		if (!a && !b && c == 0.0) break;
		for (int i = 0; i < a; i++) { // °¡·Î·Î
			dle d,x =0,y=0; cin >> d;
			x = d - c/2, y = d + c/2;
			if (d - c/2 < 0) x = 0.0;
			if (d + c/2 > 75.0) y = 75.0;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < b; i++) { // ¼¼·Î ÀÜµð ±ðÀÌ
			dle d, x = 0, y = 0; cin >> d;
			x = d - c/2, y = d + c/2;
			if (d - c/2 < 0) x = 0.0;
			if (d + c/2 > 100.0) y = 100.0;
			e.push_back({ x,y });
		}
		sort(e.begin(), e.end());
		if (check(v, 75.0) && check(e, 100.0)) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}