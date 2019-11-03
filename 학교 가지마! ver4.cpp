#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define IN 10001
#define mp make_pair
#define pi pair<int,int>
#define X first
#define Y second

vector<pi> v[20005];

int n, m, S, E;
int p[105][105];
char c[105];

int xx[] = { 1,0,-1,0 };
int yy[] = { 0,1,0,-1 };

int via[20005];

bool can() {
	queue<int> q;
	bool ck[20005] = { 0 };
	q.push(S); ck[S] = 1;

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (k == E)return 1;

		for (int j = 0; j < v[k].size(); j++) {
			int i = v[k][j].X;
			int f = v[k][j].Y;
			if (f && !ck[i]) {
				via[i] = k;
				ck[i] = 1;
				q.push(i);
			}
		}
	}return 0;
}

int main() {
	int i, j, k = 0, x, y;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", c + 1);
		for (j = 1; j <= m; j++) {
			if (c[j] == '#')continue;
			p[i][j] = ++k;
			if (c[j] == 'K')S = k, y = i, x = j;
			if (c[j] == 'H')E = k + IN;
		}
	}
	for (i = 0; i < 4; i++)if (p[y + yy[i]][x + xx[i]] == E - IN)return printf("-1"), 0;
	for (i = 1; i <= n; i++)for (j = 1; j <= m; j++) {
		if (p[i][j] == 0)continue;
		v[p[i][j]].push_back(mp(p[i][j] + IN, 0));
		v[p[i][j] + IN].push_back(mp(p[i][j], 1));
		for (k = 0; k < 4; k++) {
			x = j + xx[k];
			y = i + yy[k];
			x = p[y][x];
			y = p[i][j];
			if (x == 0)continue;
			v[y].push_back(mp(x + IN, 1));
			v[x + IN].push_back(mp(y, 0));
			v[x].push_back(mp(y + IN, 1));
			v[y + IN].push_back(mp(x, 0));
		}
	}
	int rst = 0, s, e;
	while (can()) {
		rst++;
		s = e = E;
		while (e != S) {
			s = via[e];
			for (j = 0; j < v[s].size(); j++)if (v[s][j].X == e)v[s][j].Y--;
			for (j = 0; j < v[e].size(); j++)if (v[e][j].X == s)v[e][j].Y++;
			e = s;
		}
	}
	printf("%d", rst);
}