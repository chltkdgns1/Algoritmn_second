#include <iostream>
using namespace std;

int number;
int call;
int result1 = 0;
int result2 = 0;

int main() {
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> call;
		result1 += 10 * (call / 30 + 1);
		result2 += 15 * (call / 60 + 1);
	}
	if (result1 > result2) cout << "M " << result2 << endl;
	else if (result1 < result2) cout << "Y " << result1 << endl;
	else if(result1 == result2) cout << "Y M " << result1 << endl;
}