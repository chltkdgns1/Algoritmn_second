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
�� ���� ī�尡 �����ϰ� �� ���� ī�忡�� �� �鿡  o x �� ����
�Ѵ�. ���� 4���� ī�尡 ���� �� 4������ �� ������ �����մ�
�ι� ° �Է� ���� ������ ī�忡 ���� �������� �� ������ ����
�� ������ n - m �̴� 
�޸鿡 �� ������ �������� �Ѵ�. ���� ������ ���̰� 
���� ������ ���� ������ n - k ���� �ȴ�

�ո�� �޸��� ��ġ�ϴ� ī���� �ִ밳���� ���ϴ� ���α׷� �ۼ�

*/