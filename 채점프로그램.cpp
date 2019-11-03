#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream a("output1.txt");
	ifstream b("output2.txt");

	string aa[101], bb[101];
	int i = 0;
	while (!a.eof()) {
		a >> aa[i];
		i++;
	}
	i = 0;
	while (!b.eof()) {
		b >> bb[i];
		i++;
	}

	for (int k = 0; k < i; k++) {
		if (aa[k] != bb[k]) {
			cout << k + 1 << "\n";
			cout << "내 정답 " << aa[k] << "\n";
			cout << "정해  : "<< bb[k] << "\n";
		}
	}

	system("pause");
}