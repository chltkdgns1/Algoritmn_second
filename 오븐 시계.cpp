#include <iostream>
using namespace std;int main() {int a, b, c;cin >> a >> b >> c;b += c;a += b / 60;if (a >= 24) a = a % 24;b = b % 60;cout << a << " " << b << endl;}