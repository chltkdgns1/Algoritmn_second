#include <iostream>
#include <algorithm>
using namespace std;
long long newclelid(long long a, long long b) {
	if (a % b == 0) return b;
	newclelid(b, a%b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long a, b, t1, t2, n;
	cin >> a >> b;
	t1 = max(a, b);
	t2 = min(a, b);
	n = newclelid(t1, t2);
	for (int i = 0; i < n; i++) cout << 1;
}