#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 14;
const int MOD = 9901;
int N, M;

int cache[MAX*MAX][1 << MAX];
int tiling(int board, int bit){
	if (board == N * M && bit == 0)
		return 1;
	if (board >= N * M)
		return 0;
	int &result = cache[board][bit];
	if (result != -1)
		return result;
	result = 0;
	if (bit & 1)
		result = tiling(board + 1, (bit >> 1));
	else{
		result = tiling(board + 1, (bit >> 1) | (1 << (M - 1)));
		if ((board % M) != (M - 1) && (bit & 2) == 0)
			result += tiling(board + 2, bit >> 2);
	}
	return result %= MOD;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	cout << tiling(0, 0) << "\n";
}