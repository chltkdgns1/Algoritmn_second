#include <iostream>
using namespace std;
int fibonachi2(int n) {
	int a = 0, b = 1, c = 0, cnt = 1;
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		while (1) {
			c = a + b;
			a = b %  1000000000;
			b = c %  1000000000;
			cnt++;
			if (cnt == n) {
				return b;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	if (n < 0) {
		if (n % 2 == 0) {
			cout << "-1" << endl;
			cout << fibonachi2(-n) << endl;
		}
		else {
			cout << "1" << endl;
			cout << fibonachi2(-n) << endl;
		}
	}
	else if(n > 0){
		cout << "1" << endl;
		cout << fibonachi2(n) << endl;
	}
	else {
		cout << "0" << endl;
		cout << fibonachi2(n) << endl;
	}
	system("pause");
}

/*
int dp[1000001];

int fibonachi(int n) {
	if (dp[n] != 0) return dp[n];
	if (n == 0) return 0;
	else if (n == 1) return 1;
	cout << (fibonachi(n - 1) + fibonachi(n - 2)) % 1000000000 << endl;
	return dp[n] = (fibonachi(n - 1) + fibonachi(n - 2)) % 1000000000;
}

*/