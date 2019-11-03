#include <iostream>
#include <queue>
using namespace std;

char map[65][65];
int n;
queue <char> q;
void go(int s,int e,int x,int y) { // 4,0 8,4
	if (s == x && e == y ) {
		q.push(map[e][s]);
		return;
	}
	bool a = 0, b = 0;
	for (int i = e; i <= y; i++) {
		for (int k = s; k <= x; k++) {
			if (map[i][k] == '0') a = 1;
			if (map[i][k] == '1') b = 1;
			if (a && b) {
				q.push('(');
				go(s, e,  (x + s) / 2, (y +e) / 2);
				go((x + s) / 2 + 1, e ,  x,  (y + e) / 2);
				go(s, (e + y) / 2 + 1,(x + s) / 2,  y);
				go((x + s)/ 2 + 1, (e + y) / 2 + 1,  x,  y);
				q.push(')');
				return;
			}
		}
	}
	if (!a && b) q.push('1');
	if (a && !b) q.push('0');
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];
	go(0,0,n - 1,n - 1);
	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
}