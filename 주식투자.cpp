#include <iostream>
using namespace std;

int main() {
	int n,t;
	int data = 0;
	int d_case;
	int total_data = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> d_case;
				if (data < d_case) data = d_case;
			}
			total_data += data;
			data = 0;
		}
		cout << total_data << endl;
		total_data = 0;
	}
}