#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

void makeStar(string &t, vector <pair<string, int>> &var_execute, vector <pair<string, int>>  &v,int index);
// * ����
void insertStr(string &s, vector <pair<string, int>>  &v); // ��ū ����
void Link(ofstream &output,ifstream &input); // ���� �Լ��� ȣ���ϴ� �Լ�
void linkInclude(string &s); // include ��ũ
void linkDefi(string &s); // define ��ũ

class FuncData {
public:
	string s; // �Լ��� �̸�
	int d[10]; // �Լ��� �Ķ���͵�
		// �Լ��� �Ķ���͵��� �迭�� �����ϴ� ������
		// �� �Ķ���Ͱ� var Ű���带 ������ 1 �ƴϸ� 0 �� ���� �����ϴ�.
		// �̷��� �ϴ� ������ ���� �Լ� ���ǽ� int d(var int a,int b);
		// �̷����� ���ǰ� �����ϰ� ���� ȣ��ÿ� 
		// d(&a,b) �� ����� ���̱� �����Դϴ�.
	FuncData() { memset(d, 0, sizeof(d)); }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ofstream output;
	ifstream input;

	input.open("swap.c"); // ���� ����
	output.open("result.c");//��� ���� ����

	Link(output, input); // ��Ŀ
}

void linkInclude(string &s) {
	ifstream input;
	vector <pair<string, int>> e;
	insertStr(s, e);
	for (int i = 0; i < e.size(); i++) {
		string t; int index = 0, size = 0;
		if (e[i].first == "#" && e[i + 1].first == "include") {
			t = e[i + 3].first + e[i + 4].first + e[i + 5].first;
			// ©���� ��ū���� �����մϴ�. 
			// ��� ���뿡 . �� ���ֱ� ������ 3���� ��ū�� �����մϴ�.
			index = e[i].second;
			size = e[i + 6].second + e[i + 6].first.length();
			// �׸��� ������ ���ڿ��� ������ ������ ���մϴ�.
		}
		if (!t.empty()) {
			// t �� ���� ������� �ʴٸ� ��� ������ �����ɷ� �� �� �ֽ��ϴ�.
			string w; char c;
			input.open(t); // ����� �����ϰ�
			while ((c = input.get()) != EOF) w += c;
			// ������ ��������� ������ �����ɴϴ�.
			linkInclude(w); 
			// ����Լ��� ���ؼ� ��� �ȿ� �ٸ� ��� ������ �ҷ��ɴϴ�.
			s.erase(index, size - index);
			// ���س��� ������ �����մϴ�. ��) #include "head.h"
			s.insert(index, w);
			// �߰��մϴ�.
			t.clear();
			input.close();
		}
	}
}

void linkDefi(string &s){

	vector <pair<string, string>> defi;
	vector <pair<string, int>> v;

	insertStr(s, v);
	bool check[1000];
	memset(check, 0, sizeof(check));

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == "#" && v[i + 1].first == "define") {
			check[i + 2] = 1;
			if (i + 4 < v.size() && v[i + 4].first == ".") {
				// define �� ��� �Է¹޴� ���� �Ҽ����� �� �ֱ� ������
				defi.push_back({ v[i + 2].first,v[i + 3].first + v[i + 4].first + v[i + 5].first});
				// .�� �����Ѵٸ� 3���� ��ū���� �����ݴϴ�.
			}
			else {
				defi.push_back({ v[i + 2].first,v[i + 3].first});
				// �װ� �ƴ϶�� �ϳ��� ��ū�����ε� ����մϴ�.
			}
		}
		else {// define�� �� ���� �����ϰ� ������ ������ �ٲ��־�� �մϴ�.
			for (int k = 0; k < defi.size(); k++) {
				if (v[i].first == defi[k].first && !check[i]) {
					s.erase(v[i].second, v[i].first.length());
					s.insert(v[i].second, defi[k].second);
					int d = defi[k].second.length() - v[i].first.length();
					v[i].first = defi[k].second;
					for (int z = i + 1; z < v.size(); z++) v[z].second += d;
				}
			}
		}
	}
}

void insertStr(string &s, vector <pair<string, int>> &v) { // ��ū�� �����մϴ�.
	string a;
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] >= 48 && s[i] <= 57) ||
			(s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) { // ���ڳ� ������ ��� �����ݴϴ�.
			if (a.empty()) index = i;
			a += s[i];
		}
		else if (s.length() - 1 == i && !a.empty()) v.push_back({ a,index }); // ���ڿ��� �������� vector �� �־��ݴϴ�.
		else if (s[i] == '(' || s[i] == ')' || s[i] == ',' ||
			s[i] == ';' || s[i] == '.' || s[i] == '[' || s[i] == ']'
			|| s[i] == '=' || s[i] == '{' || s[i] == '}' || s[i] == '#' || s[i] == '"'
			|| s[i] == '+' || s[i] == '-') {
			// ��쿡 ���߾� vector �� �־��ݴϴ�. 
			string e;  e += s[i];
			if (!a.empty()) {
				v.push_back({ a,index });
			}
			v.push_back({ e,i });
			a.clear();
		}
		else {
			if (!a.empty()) {
				v.push_back({ a,index });
				a.clear();
			}
		}
	}
}

void Link(ofstream &output, ifstream &input) {
	
	string s;
	vector <pair<string, int>> v, var_execute;
	vector <string> var;
	vector <FuncData> func;

	char c;
	bool check[1000];
	memset(check, 0, sizeof(check));
	while ((c = input.get()) != EOF) s += c;


	linkInclude(s); // ������� �ҷ����°� ���� ���� ���� �� ������ ��� ���ο� var �� 
	// ���� �� �ֱ� �����Դϴ�.
	linkDefi(s); // �� ���� define ���� �� ������ ���� ���������� define ó���� ����� �ϱ�
	// �����Դϴ�.
	insertStr(s, v);

	for (int i = 0; i < v.size(); i++) {
		//////// �Լ� ó��
		if (v[i].first == "(") {
			if (v[i - 1].first != "if" && v[i - 1].first != "for" &&
				v[i - 1].first != "while" && v[i - 1].first != "switch") {
				// () �տ� if for while switch ���� �� �� �ֱ� ������ �̷� ���� �����մϴ�.
				if (v[i - 2].first == "void" || v[i - 2].first == "int" || v[i - 2].first == "char" ||
					v[i - 2].first == "float" || v[i - 2].first == "double") {
					// �׸��� �Լ��� �տ� �ڷ����� �� ��쿡 �Լ��� �˴ϴ�.
					// ���� ���� �ڷ��� ���� �߰����� �ڷ����� �ְ� ������ �ڷ����� ���ö�����
					// vector �� ����־� �����ַ��� �ߴµ� ���α׷��� �ʹ� Ŀ�� �� ���Ƽ� ������ ����־����ϴ�.
					FuncData d; 
					d.s = v[i - 1].first; // �Լ��� �̸�
					int cnt = 0;
					for (int k = i + 1; v[k].first != ")"; k++) {
						if (v[k].first == ",") cnt++;
						else {
							if (v[k].first == "var") d.d[cnt] = 1;  
							// var Ű���尡 ������ ��쿡 �ش� �Ķ���� �迭�� ���� 1�� ������ݴϴ�.
						}
					}
					func.push_back(d);
				}
				else {  
					for (int k = 0; k < func.size(); k++) {
						if (v[i - 1].first == func[k].s) {  // ��ϵ� �Լ��� ���� �� �� ȣ������ ���
							int st = i + 1 , cnt = 0; 
							for (int z = 0; z < 10; z++) { // �Լ��� �Ķ���Ͷ� ���մϴ�.
								if (func[k].d[z]) {  // ���� �Ķ���Ͱ� var Ű���带 ���� ���
									bool br = 0;
									for (int x = 0; x < var.size(); x++) {
										if (var[x] == v[st + z + cnt].first) { 
											// var �� �� �������� ��Ƴ� var vector �� ���մϴ�.
											// �̰��� �ϴ� ������ ȣ��ÿ�
											// var int a => int *a �̹Ƿ�
											// swap(int *a,int *b) ����
											// swap(a,&b) �� ������ ���� �����Դϴ�.
											// ���� & �� ���� �ʿ䰡 �����ϴ�.
											check[st + z + cnt] = 1;
											// ���߿� *�� ���� �� �ֱ� ������ üũ�صӴϴ�.
											br = 1; break;
										}
										// ���� ���� �ʿ䰡 �����ϴ�.
									}
									if (br) {
										cnt++; continue;
									}
									string q; q = "&" + v[st + z + cnt].first;
									s.erase(v[st + z + cnt].second, v[st + z + cnt].first.length());
									s.insert(v[st + z + cnt].second, q);
									for (int k = st + z ; k < v.size(); k++) v[k].second++;
								}
								cnt++;
							}
							break; // c���� �Լ� �����ε��� �ȵǱ� ������
							// �� ���;��� break �մϴ�.
						}
					}
				}
			}
		}

		////// 
		////// var ó��

		else if (v[i].first == "var") { // var �� ���
			s.erase(v[i].second, 4); // var �� 3������ �����̽��ٸ� �߰��Ͽ� 4�� �����մϴ�.
			for (int k = i + 1; k < v.size(); k++) v[k].second -= 4;
			var.push_back(v[i + 2].first);
		}

		else if (v[i].first == "}") { 
			// } �� ��� �ش� �Լ��� ����� ���̱� ������ 
			// var �� �����մϴ�.
			var.clear(); // ���� �� var �� �ʱ�ȭ�����ν� ���ο� �Լ� ���ο��� var �� �����մϴ�.
			// �̷��� �ϴ� ������ ��� �Լ����� var ���� ������ �̸��� a �϶�
			// �ٸ� �Լ����� �� ������ �������� * �� ���� �� �ֱ� ������ 
			// } �� �����ؼ� �ʱ�ȭ���ݴϴ�.
			makeStar(s, var_execute,v,i);
			var_execute.clear();
		}
		else {
			for (int k = 0; k < var.size(); k++) { 
				if (v[i].first == var[k] && !check[i]) {
					var_execute.push_back({ v[i].first,v[i].second });
				}
			}
		}
	}
	cout << s << "\n";
	output << s << "\n";
	input.close();
	output.close();
	system("pause");
}


void makeStar(string &s, vector <pair<string, int>> &ex, vector <pair<string, int>>  &v,int index) {
	for (int k = 0; k < ex.size(); k++) {
		string q; q = "*" + ex[k].first;
		// ���� �߰����ݴϴ�.
		s.erase(ex[k].second, ex[k].first.length());
		s.insert(ex[k].second, q);
		for (int z = k + 1; z < ex.size(); z++) ex[z].second++;
		for (int z = index + 1; z < v.size(); z++) v[z].second++;
	}
}