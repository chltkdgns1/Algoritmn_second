#include <iostream>
typedef long long ll;
using namespace std;

ll uclid(ll a, ll b) {
	if (!(a % b)) return b;
	uclid(b, a%b);
}
int main() {
	ll a, b,c;
	cin >> a >> b;
    c =  uclid(a, b);
	cout << c << "\n";
	cout <<a / c * b / c * c << "\n";
}