#include <iostream>
using namespace std;

int main() {
	int n, m_o, k_o;
	int m_x, k_x;
	int total = 0;
	cin >> n >> m_o >> k_o;
	if (1 <= n && n <= 1000000 && 0 <= m_o && m_o <= n && 0 <= k_o && k_o <= n) {
		m_x = n - m_o;
		k_x = n - k_o;
		if (m_o > k_o) {
			total += k_o;
		}
		else if (m_o == k_o) {
			total += k_o;
		}
		else if (m_o < k_o) {
			total += m_o;
		}
		if (m_x > k_x) {
			total += k_x;
		}
		else if (m_x == k_x) {
			total += k_x;
		}
		else if (m_x < k_x) {
			total += m_x;
		}
	}
	cout << total << endl;
	//system("pause");
}

/*
엔 개의 카드가 존재하고 엔 개의 카드에는 앞 면에  o x 가 존재
한다. 따라서 4개의 카드가 있을 때 4개에는 오 엑스가 적혀잇다
두번 째 입력 엠은 엠개의 카드에 오가 적혀잇을 때 나머지 엑스
의 개수는 n - m 이다 
뒷면에 오 엑스를 적으려고 한다. 오의 개수는 케이개 
오가 적히지 않을 개수는 n - k 개가 된다

앞면과 뒷면이 일치하는 카드의 최대개수를 구하는 프로그램 작성

*/