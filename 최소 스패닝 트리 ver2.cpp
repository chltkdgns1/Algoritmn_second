#include <iostream>
#include <algorithm>
using namespace std;

class Data {
public:
	int a , b, d; // a�� ���� ���� b �� ����� ����, d �� ����ġ
};

Data d[100001]; 
int root[10001];

bool cmp(const Data&a, const Data&b) {
	return a.d < b.d; // ����ġ�� ����
}

int find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = find(root[x]);
	}
}
bool Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	root[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) root[i] = i;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[i].a = a, d[i].b = b, d[i].d = c;
	}
	sort(d , d + k, cmp); // ���� 1���� n���� ����

	long long t = 0; 
	for (int i = 0; i < k; i++) {
		if (!Union(d[i].a, d[i].b)) continue;
		else t += d[i].d;
	}
	cout << t << "\n";
	system("pause");
}