#include <iostream>
using namespace std;
int GCD(int a, int b) {
	cout << "b : " << b << endl;
	if (a%b == 0)
		return b;
	return GCD(b, a%b);
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	cout << M - GCD(N, M) << "\n";
	system("pause");
	return 0;
}