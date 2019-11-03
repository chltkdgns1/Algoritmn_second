#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum, n;
vector <int> v;

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

int trevel(int s) {
	if (s >= v.size()) return 0;
	int a = trevel(s * 2), b = trevel(s * 2 + 1);

	int t = max(a, b);
	if (a > b) v[s * 2 + 1] += a - b;
	else if (a < b)v[s * 2] += b - a;
	return v[s] + t;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	get(n);
	v.push_back(-1), v.push_back(0);
	for (int i = 0; i < (1 << n + 1) - 2; i++){
		int a; get(a);
		v.push_back(a);
	}
	trevel(1);
	for (int i = 2; i < v.size(); i++) sum += v[i];
	cout << sum << "\n";
}