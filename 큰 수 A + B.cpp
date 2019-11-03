#include <iostream>
#include <string.h>
using namespace std;
char a[10000];
char b[10000];
char temp_arr[10000];
char c[10001];
void sameLen() {
	int a_len = strlen(a), b_len = strlen(b);
	if (a_len> b_len) {
		for (int i = 0; i < b_len; i++) temp_arr[i] = b[i];
		for (int i = 0; i < a_len - b_len; i++) b[i] = '0';
		for (int i = a_len - b_len; i < a_len; i++) b[i] = temp_arr[i - a_len + b_len];
	}
	else {
		for (int i = 0; i < a_len; i++) temp_arr[i] = a[i];
		for (int i = 0; i < b_len - a_len; i++) a[i] = '0';
		for (int i = b_len - a_len; i < b_len; i++) a[i] = temp_arr[i - b_len + a_len];
	}
}
void sumAB() {
	int a_n, b_n, sum = 0;
	for (int i = strlen(a) - 1; i >= 0; i--) {
		a_n = a[i] - 48;
		b_n = b[i] - 48;
		sum += a_n + b_n;
		c[i + 1] = sum % 10 + 48;
		sum /= 10;
	}
	if (sum != 0) c[0] = sum + 48;
}
int main() {
	cin >> a >> b;
	sameLen();
	sumAB();
	for (int i = 0; i<strlen(a) + 1; i++) {
		if (c[i] != 0) cout << c[i];
	}
	cout << endl;
	system("pause");
}