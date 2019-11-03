#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, score, big_score=0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		if (big_score < score) big_score = score;
		sum += score;
	}
	cout << (sum / (big_score ) *100) / n << endl;
	cin.tie(NULL);
	//system("pause");
}