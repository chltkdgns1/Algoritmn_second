#include <iostream>
#include <string.h>
using namespace std;
char K[5000001];
int main() {
	long long N, J = 1, Num, Sum = 0, Res = 0;
	cin >> N >> K;
	for (int i = N - 1; i >= 0; i--) {
		if (K[i] >= '0' && K[i] <= '9') {
			Num = K[i] - '0';
			Sum += J * Num;
			J *= 10;
		}
		if (i == 0 || K[i] <'0' || K[i] >'9') {
			if (Sum <= 999999) {
				Res += Sum;
				Sum = 0;
				J = 1;
			}
		}
	}
	cout << Res << endl;
}