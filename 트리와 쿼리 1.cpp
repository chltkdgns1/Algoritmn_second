#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector <int> v[100001];
vector <int> tree(400001);
int deep[100001], par[100001][18];
int st[100001], e[100001], label;
int arr[100001], brr[100001];

map <pair<int, int>, int> q;

void dfs(int s, int deeps,int p) {
	deep[s] = deeps;
	if (p != -1) st[q[{p, s}]] = ++label;	
	for (auto a : v[s]) {
		if (!deep[a]) {
			par[a][0] = s;
			dfs(a, deeps + 1,s);
		}
	}
	e[q[{p, s}]] = label;
}

int init(int s, int e, int node) {
	if (s == e) return tree[node] = brr[s];
	int m = (s + e) / 2;
	return tree[node] = min(init(s, m, 2 * node), init(m + 1, e, 2 * node + 1));
}

int update(int s, int e, int node, int data, int index) {
	if (e < index || index < s) return tree[node];
	if (s == e) return tree[node] = data;
	int m = (s + e) / 2;
	return tree[node] = min(update(s, m, node * 2, data, index), update(m + 1, e, node * 2 + 1, data, index));
}

int qurey(int s, int e, int node, int l, int r) {
	if (e < l || r < s) return 987654321;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return min(qurey(s, m, node * 2, l, r), qurey(m + 1, e, node * 2 + 1, l, r));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a, b, c;
	for (int i = 1; i < n ; i++) {
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		arr[i] = c; 
		q[{b, c}] = i, q[{c, b}] = i;
	}
	dfs(1, 1 , -1);
	for (int i = 1; i < n; i++) brr[st[i]] = arr[i];
	init(1, n - 1, 1);
	for (int k = 0; k <= 17; k++) {
		for (int i = 1; i <= n; i++) {
			int p = par[k][i];
			par[k][i + 1] = par[p][k];
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, n - 1, 1, c, st[b]);	
		else {
			int x = b, y = c;
			if (deep[b] > deep[c]) swap(b, c); // c 가 b 보다 깊어짐			
			for (int i = 17; i >= 0; i--) {
				if (deep[c] - deep[b] >= (1 << i)) c = par[c][i];
			}
			bool flag = 0;
			if(b != c){
				for (int i = 17; i >= 0; i--) {
					if (par[b][i] != par[c][i] && par[b][i] ) {
						b = par[b][i]; 
						c = par[c][i];
					}
				}
				b = par[b][0];
				flag = 1;
			}

			int d = st[q[{par[x][0], x}]];
			int w = st[q[{par[y][0], y}]];

			for (auto a : v[b]) { // 루트를 기점으로 모든 방향을 꺼내든다
				if (deep[b] < deep[a]) {
					int v = st[q[{b, a}]];
					int u = e[q[{ b, a }]];
					int xx = -1, yy = -1;
					if (flag && v <= d && d <= u) xx = qurey(1, n - 1, 1, v, d);
					if (v <= w && w <= u) yy = qurey(1, n - 1, 1, v, w);
					if (xx != -1 && y != -1) {
						cout << min(xx, yy) << "\n";
						break;
					}
					if (!flag && yy != -1) {
						cout << yy << "\n";
						break;
					}
				}
			}

			// b 는 두 구간의 루트가 연결되는 루트가 됨
			// 따라서 루트를 기준으로 st 값이을 기준으로 그 값보다 크면서 e[] 보다 작다면 쿼리를 실행

			
		}
	}
	system("pause");
}