#include <iostream>
#include <queue>
using namespace std;
int map[17][17];
class Data {
public:
	int a,b,c,d, dir; // dir ¿∫ πÊ«‚
	Data(int a,int b,int c,int d,int dir) :a(a),b(b),c(c),d(d),dir(dir){}
};
int n;
void bfs() {
	queue <Data> q;
	q.push(Data(0, 0, 0, 1, 1)); // a b c d dir 
	int cnt = 0;
	while (!q.empty()) {
		Data d = q.front();
		q.pop();
		if (d.c == n - 1 && d.d == n - 1) {
			cnt++;
			continue;
		}
		switch (d.dir) {
		case 1: 
			if (d.d + 1 < n  && !map[d.a][d.d + 1]) q.push(Data(d.a, d.b + 1, d.c, d.d + 1,1));
			if (d.d + 1 < n && d.a + 1 < n && !map[d.a][d.d + 1] && !map[d.a + 1][d.d + 1] && !map[d.a + 1][d.d])
				q.push(Data(d.a, d.b + 1, d.c + 1, d.d + 1, 3));
			break;
		case 2:
			if (d.c + 1 < n && !map[d.c + 1][d.d]) q.push(Data(d.a + 1, d.b, d.c + 1, d.d, 2));
			if (d.c + 1 < n && d.d + 1 < n && !map[d.c + 1][d.d] && !map[d.c][d.d + 1] && !map[d.c + 1][d.d + 1])
				q.push(Data(d.a + 1, d.b, d.c + 1, d.d + 1, 3));
			break;
		case 3:
			if (d.d + 1 < n && !map[d.c][d.d + 1]) q.push(Data(d.a + 1, d.b + 1, d.c, d.d + 1, 1));
			if (d.c + 1 < n && !map[d.c + 1][d.d]) q.push(Data(d.a + 1, d.b + 1, d.c + 1, d.d, 2));
			if (d.c + 1 < n && d.d + 1 < n && !map[d.c + 1][d.d + 1] && !map[d.c + 1][d.d] && !map[d.c][d.d + 1])
				q.push(Data(d.a + 1, d.b + 1, d.c + 1, d.d + 1, 3));
			break;
		}
	}
	cout << cnt << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
		}
	}
	bfs();
}