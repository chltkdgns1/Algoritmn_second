#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

ll init(vector <ll> &v, vector <ll> &tree, int node, int start, int end) {
	if (start == end) tree[node] = v[start];
	else {
		tree[node] = init(v, tree, node * 2, start, (start + end) / 2) +
			init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
	return tree[node];
}

ll sum(vector <ll> &tree, int node, int left, int right, int start, int end) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(tree, node * 2, left, right, start, (start + end) / 2) +
		sum(tree, node * 2 + 1, left, right, (start + end) / 2 + 1, end);
}


void update(vector <ll> &tree, int node, ll data, int index, int start, int end) {
	if (start > index || end < index) return;
	tree[node] += data;
	if (start != end) {
		update(tree, node * 2, data, index, start, (start + end) / 2);
		update(tree, node * 2 + 1, data, index, (start + end) / 2 + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n;
	int h = log2(n);
	vector <ll> tree((1 << (h + 1))), v;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int start = 0, end = n - 1;
}