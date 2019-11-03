#include <iostream>
#include <vector>
using namespace std;
class par {
public:
	int d[3];
};
vector <int> v;
int sig(int a) {
	if (!a) return 0;
	else if (a < 0) return 1;
	else return 2;
}
par init(int s, int e, int node,vector <par> &tree) {
	if (s == e) {
		tree[node].d[sig(v[s])]++;
		return tree[node];
	}
	int m = (s + e) / 2;
	par d = init(s, m, node * 2,tree), c = init(m + 1, e, node * 2 + 1,tree);
	for (int i = 0; i < 3; i++) tree[node].d[i] = d.d[i] + c.d[i];
	return tree[node];
}
void ch(int s, int e, int node, int index,int d, vector <par> &tree) {
	if (e < index || index < s) return;
	tree[node].d[sig(v[index])]--;
	tree[node].d[sig(d)]++;
	if (s == e) return;
	int m = (s + e) / 2;
	ch(s, m, node * 2, index,d,tree), ch(m + 1,e, node * 2 + 1, index,d,tree);
}
int query(int s, int e, int node, int le, int ri, vector <par> &tree) {
	if (ri < s || e < le) return 987654321;
	if (le <= s && e <= ri) {
		if (tree[node].d[0]) return 0;
		if (!(tree[node].d[1] % 2)) return 1;
		else return -1;
	}
	int m = (s + e) / 2;
	int a = query(s, m, node * 2, le, ri, tree), b = query(m + 1, e, node * 2 + 1, le, ri, tree);
	if (a == 987654321) return b;
	else if (b == 987654321) return a;
	else return a * b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, a;
	while (cin >> n >> k) {
		vector <par> tree(400000);
		for (int i = 0; i < n; i++) {
			cin >> a; v.push_back(a);
		}
		init(0, n - 1, 1,tree);
		char a; int b, c;
		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c;
			if (a == 'C') {		
				if (sig(v[b - 1]) == sig(c)) continue;
				else ch(0, n - 1, 1, b - 1,c,tree);
				v[b - 1] = c;			
			}
			else {
				int d = query(0, n - 1, 1, b - 1, c - 1,tree);
				if (!d) cout << 0;
				else if (d > 0) cout << "+";
				else cout << "-";
			}
		}
		v.clear();
		cout << "\n";
	}
}