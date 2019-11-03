#include <iostream>
#include <string.h>
using namespace std;

int xpos = 2, ypos = 2;
char arr[5][62] =
{
	"..#...#...*...#...#...*...#...#...*...#...#...*...#...#...*..",
	".#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.",
	"#.X.#.X.*.X.*.X.#.X.*.X.*.X.#.X.*.X.*.X.#.X.*.X.*.X.#.X.*.X.*",
	".#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.",
	"..#...#...*...#...#...*...#...#...*...#...#...*...#...#...*..",
};
char str[15];
int main() {
	cin >> str;
	for (int i = 0; i < strlen(str); i++) {
		arr[ypos][xpos] = str[i];
		xpos += 4;
	}
	if (strlen(str) % 3 != 0) arr[ypos][xpos - 2] = '#';
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i <= xpos - 2; i++) {
			cout << arr[j][i];
		}
		cout << endl;
	}
	system("pause");
}