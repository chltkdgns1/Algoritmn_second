#include <iostream>
using namespace std;
typedef long long ll;

void solve(ll n) {
	if (!n) return;
	solve(n / 2);
	cout << n % 2;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	solve(n);
}