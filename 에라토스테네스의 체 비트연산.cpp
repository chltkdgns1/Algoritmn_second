#include <iostream>
#include <string>
#define MAX 100000000
using namespace std;

unsigned char bit[MAX / 7 + 1];

bool isPrime(int s) {
	return bit[s >> 3] & (1 << (s & 7));
}

void isNotPrime(int s) {
	bit[s >> 3] &= ~(1 << (s & 7));
} 

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;

	memset(bit, 255, sizeof(bit));
	isNotPrime(0), isNotPrime(1);

	for (int i = 2; i*i <= n; i++) {
		if (isPrime(i)) {
			for (int k = i * i; k <= n; k += i) {
				isNotPrime(k);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) cout << i << " ";
	}
	cout << "\n";
}