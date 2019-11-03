#include <iostream>
using namespace std;
int solve(int sign) {
	int n;
	if (sign == 0)
		return;
	else
		return solve(sign - 1);

}
int main() {
	int n;
	int a;
	int arr[12];
	int i = 0;
	int sign;
	int dec[4] = {0}; //+-*/
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	for (int i = 0; i < 4; i++) 
		cin >> dec[i];
	for (int i = 0; i < 4; i++) {
		solve(dec[i]);
	}
	system("pause");
	return 0;
}