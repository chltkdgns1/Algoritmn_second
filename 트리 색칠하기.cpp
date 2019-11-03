#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
vector <int> v[100001];

int dp[100001][18], d;
static char buf[65536];
static inline char getch()
{
	static int p = 65536;
	if (p == 65536)
	{
		fread(buf, 1, 65536, stdin);
		p = 0;
	}
	return buf[p++];
}
static inline void get(int &r)
{
	register int t;
	r = getch() & 15;
	while ((t = getch()) > 40) r = r * 10 + (t & 15);
}

int dfs(int par, int s, int ch) {
	int &ref = dp[s][ch];
	if (ref) return ref;
	ref = ch;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (par == y) continue;
		int res = 987654321;
		for (int i = 1; i <= d; i++) {
			if (ch == i) continue;
			res = min(res, dfs(s, y, i));
		}
		ref += res;
	}
	return ref;
}
int main() {
	int n; get(n);
	d = log2(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; get(a), get(b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int res = 987654321;
	for (int i = 1; i <= d; i++) {
		res = min(res, dfs(-1, 1, i));
	}
	cout << res << "\n";
}