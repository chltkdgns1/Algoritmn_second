#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int act[4]; //동작[k]를 하는데 걸리는 시간 :  act[k]
	int status[8]; //나올 수 있는 모든 경우의 수에 해당하는 걸리는 시간.
	int n, m;
	int res = 0;
	cin >> n >> m;act[0] = n;act[1] = int(n / 2);act[2] = n - act[1];act[3] = (n + 2) / 3;status[0] = 0;status[1] = act[0];status[2] = act[1];status[3] = act[2];status[4] = act[3];status[5] = act[3] + act[0];status[6] = act[3] + act[1];status[7] = act[3] + act[2];
	if (m == 0)
		res = 1;
	else {	if (n < 3) {if (n == 1)	if (m >= 1)	res = 2;if (n == 2)if (m >= 2)	res = 4;else if (m == 1)	res = 3;}else {for (int i = 0; i < 8; i++) {	if (m >= status[i])		res++;	}}}cout << res << endl;	return 0;}