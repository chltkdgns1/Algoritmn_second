#include <iostream>
using namespace std;

int vic[6], same[6], lose[6], res[4];
void dfs(int t,int a,int b) {
	if (a == 6) {
		res[t] = 1;
		return;
	}
	if (b == 6) dfs(t, a + 1, a + 2);
	else {
		vic[a]--, lose[b]--;
		if (vic[a] >= 0 && lose[b] >= 0) dfs(t, a, b + 1);
		vic[a]++, lose[b]++;
		same[a]--, same[b]--;
		if (same[a] >= 0 && same[b] >= 0) dfs(t, a, b + 1);
		same[a]++, same[b]++;
		lose[a]--, vic[b]--;
		if (lose[a] >= 0 && vic[b] >= 0) dfs(t, a, b + 1);
		lose[a]++, vic[b]++;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 4; i++) {
		bool flag = 0;
		for (int k = 0; k < 6; k++) {
			cin >> vic[k] >> same[k] >> lose[k];
			if (vic[k] + same[k] + lose[k] != 5) flag = 1;
		}
		if (flag) continue;
		dfs(i, 0, 1);
	}
	for (int i = 0; i < 4; i++) cout << res[i] << " ";
}