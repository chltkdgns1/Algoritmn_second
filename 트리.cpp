#include <iostream>
#include <vector>
using namespace std;

vector <int> v(200001);

bool find(int x, int y) {
	if (v[x] == x) return false;
	if (v[x] == y) return true;
	else return find(v[x],y);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++) {
		int a; cin >> a;
		v[i + 1] = a;
	}
	for (int i = 0; i < n - 1 + m; i++) {
		int a, b, c;
		cin >> a;
		if (!a) {
			cin >> b;
			v[b] = 0;
		}
		else {
			cin >> b >> c;
			if (find(b, c) == false) cout << "NO" << "\n";
			else cout << "YES" << "\n";
		}
	}
	system("pause");
}