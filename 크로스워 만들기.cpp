#include <iostream>
#include <string.h>
using namespace std;

char arr[30][30];
int main() {
	char a[30], b[30];
	cin >> a >> b;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) arr[i][j] = '.';
	}
	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			if (a[i] == b[j]) {
				// i �� ���� i ��° ���η� �վ���ϴ� B
				// j ���� j ��° ���η� �վ�� �ϴ� A
				for (int k = 0; k < strlen(a); k++) {
					arr[j][k] = a[k];
				}
				for (int k = 0; k < strlen(b); k++) {
					arr[k][i] = b[k];
				}
				for (int i = 0; i < strlen(b); i++) {
					for (int j = 0; j < strlen(a); j++) {
						cout << arr[i][j];
					}
					cout << endl;
				}
				system("pause");
				return 0;
			}
		}
	}
}