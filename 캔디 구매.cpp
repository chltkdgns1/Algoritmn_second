#include <iostream>
#include <math.h>
using namespace std;int main() {int n, k, cnt = 1;cin >> n >> k;while (n) {	if (cnt == k) {if (n % 10 >= 5) {	n = (n / 10 + 1) * pow(10, cnt);	}else n = (n / 10) * pow(10, cnt);	break;}n = n / 10;cnt++;}cout << n << endl;}