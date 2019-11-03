#include <iostream>
#include <string>
using namespace std;
string d;
int n;
char s[3] = { '1','2','3' };
int lenCheck(int x1, int len) {
	for (int i = 0; i < len; i++) {
		if (i + x1 + len >= d.length()) {
			return true;
		}
		if (d[i + x1] != d[i + x1 + len]) {
			return true;
		}
	}
	return false;
}
bool check() {
	for (int j = 1; j < d.length(); j++) {
		for (int i = 0; i < d.length() ; i++) {
			if (!lenCheck(i, j)) return false;
		}
	}
	return true;
}
void dfs(int index,int cnt) {
	if (cnt == n) {
		cout << d << "\n";
		exit(0);
	}
	for (int i = 0; i < 3; i++) {
		d += s[i];
		if (check() == true) dfs(index + 1, cnt + 1);
		d.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0,0);
}