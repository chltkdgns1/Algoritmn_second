#include <iostream>
using namespace std;
int arr[1000000];
int main() {
	int i = 0;
	while (cin>>arr[i]) {
		i++;
	}
	for (int j = 0; j < i - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout<<"Good"<<endl;
}