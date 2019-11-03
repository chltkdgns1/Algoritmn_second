#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

void makeStar(string &t, vector <pair<string, int>> &var_execute, vector <pair<string, int>>  &v,int index);
// * 생성
void insertStr(string &s, vector <pair<string, int>>  &v); // 토큰 생성
void Link(ofstream &output,ifstream &input); // 각각 함수들 호출하는 함수
void linkInclude(string &s); // include 링크
void linkDefi(string &s); // define 링크

class FuncData {
public:
	string s; // 함수의 이름
	int d[10]; // 함수의 파라미터들
		// 함수의 파라미터들을 배열로 저장하는 이유는
		// 각 파라미터가 var 키워드를 갖으면 1 아니면 0 의 값을 갖습니다.
		// 이렇게 하는 이유는 실제 함수 정의시 int d(var int a,int b);
		// 이런식의 정의가 가능하고 실제 호출시에 
		// d(&a,b) 의 방식을 보이기 때문입니다.
	FuncData() { memset(d, 0, sizeof(d)); }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ofstream output;
	ifstream input;

	input.open("swap.c"); // 파일 오픈
	output.open("result.c");//결과 파일 오픈

	Link(output, input); // 링커
}

void linkInclude(string &s) {
	ifstream input;
	vector <pair<string, int>> e;
	insertStr(s, e);
	for (int i = 0; i < e.size(); i++) {
		string t; int index = 0, size = 0;
		if (e[i].first == "#" && e[i + 1].first == "include") {
			t = e[i + 3].first + e[i + 4].first + e[i + 5].first;
			// 짤려진 토큰들을 조합합니다. 
			// 헤더 내용에 . 이 들어가있기 때문에 3개의 토큰을 조합합니다.
			index = e[i].second;
			size = e[i + 6].second + e[i + 6].first.length();
			// 그리고 생성된 문자열을 삭제할 범위를 구합니다.
		}
		if (!t.empty()) {
			// t 의 값이 비어있지 않다면 헤더 내용을 갖은걸로 볼 수 있습니다.
			string w; char c;
			input.open(t); // 헤더를 오픈하고
			while ((c = input.get()) != EOF) w += c;
			// 오픈한 헤더파일의 내용을 가져옵니다.
			linkInclude(w); 
			// 재귀함수를 통해서 헤더 안에 다른 헤더 파일을 불러옵니다.
			s.erase(index, size - index);
			// 구해놓은 범위를 제거합니다. 예) #include "head.h"
			s.insert(index, w);
			// 추가합니다.
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
				// define 의 경우 입력받는 값이 소수점일 수 있기 때문에
				defi.push_back({ v[i + 2].first,v[i + 3].first + v[i + 4].first + v[i + 5].first});
				// .을 포함한다면 3개의 토큰들을 합쳐줍니다.
			}
			else {
				defi.push_back({ v[i + 2].first,v[i + 3].first});
				// 그게 아니라면 하나의 토큰만으로도 충분합니다.
			}
		}
		else {// define을 한 것을 제외하고 나머지 값들을 바꿔주어야 합니다.
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

void insertStr(string &s, vector <pair<string, int>> &v) { // 토큰을 생성합니다.
	string a;
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] >= 48 && s[i] <= 57) ||
			(s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) { // 문자나 숫자일 경우 더해줍니다.
			if (a.empty()) index = i;
			a += s[i];
		}
		else if (s.length() - 1 == i && !a.empty()) v.push_back({ a,index }); // 문자열이 끝날때도 vector 에 넣어줍니다.
		else if (s[i] == '(' || s[i] == ')' || s[i] == ',' ||
			s[i] == ';' || s[i] == '.' || s[i] == '[' || s[i] == ']'
			|| s[i] == '=' || s[i] == '{' || s[i] == '}' || s[i] == '#' || s[i] == '"'
			|| s[i] == '+' || s[i] == '-') {
			// 경우에 맞추어 vector 에 넣어줍니다. 
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


	linkInclude(s); // 헤더파일 불러오는게 가장 먼저 선행 그 이유는 헤더 내부에 var 가 
	// 있을 수 있기 때문입니다.
	linkDefi(s); // 그 다음 define 진행 그 이유는 위와 마찬가지로 define 처리를 해줘야 하기
	// 때문입니다.
	insertStr(s, v);

	for (int i = 0; i < v.size(); i++) {
		//////// 함수 처리
		if (v[i].first == "(") {
			if (v[i - 1].first != "if" && v[i - 1].first != "for" &&
				v[i - 1].first != "while" && v[i - 1].first != "switch") {
				// () 앞에 if for while switch 등이 올 수 있기 때문에 이럴 경우는 배제합니다.
				if (v[i - 2].first == "void" || v[i - 2].first == "int" || v[i - 2].first == "char" ||
					v[i - 2].first == "float" || v[i - 2].first == "double") {
					// 그리고 함수명 앞에 자료형이 올 경우에 함수가 됩니다.
					// 물론 위의 자료형 말고 추가적인 자료형이 있고 실제로 자료형이 나올때마다
					// vector 에 집어넣어 비교해주려고 했는데 프로그램이 너무 커질 것 같아서 적당히 잡아주었습니다.
					FuncData d; 
					d.s = v[i - 1].first; // 함수의 이름
					int cnt = 0;
					for (int k = i + 1; v[k].first != ")"; k++) {
						if (v[k].first == ",") cnt++;
						else {
							if (v[k].first == "var") d.d[cnt] = 1;  
							// var 키워드가 존재할 경우에 해당 파라미터 배열의 값을 1로 만들어줍니다.
						}
					}
					func.push_back(d);
				}
				else {  
					for (int k = 0; k < func.size(); k++) {
						if (v[i - 1].first == func[k].s) {  // 등록된 함수와 같을 때 즉 호출했을 경우
							int st = i + 1 , cnt = 0; 
							for (int z = 0; z < 10; z++) { // 함수의 파라미터랑 비교합니다.
								if (func[k].d[z]) {  // 만약 파라미터가 var 키워드를 갖는 경우
									bool br = 0;
									for (int x = 0; x < var.size(); x++) {
										if (var[x] == v[st + z + cnt].first) { 
											// var 가 들어간 변수명을 모아논 var vector 와 비교합니다.
											// 이것을 하는 이유는 호출시에
											// var int a => int *a 이므로
											// swap(int *a,int *b) 에서
											// swap(a,&b) 의 형식을 갖기 때문입니다.
											// 따라서 & 를 붙일 필요가 없습니다.
											check[st + z + cnt] = 1;
											// 나중에 *이 붙을 수 있기 때문에 체크해둡니다.
											br = 1; break;
										}
										// 굳이 붙일 필요가 없습니다.
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
							break; // c언어는 함수 오버로딩이 안되기 때문에
							// 더 볼것없이 break 합니다.
						}
					}
				}
			}
		}

		////// 
		////// var 처리

		else if (v[i].first == "var") { // var 일 경우
			s.erase(v[i].second, 4); // var 는 3개지만 스페이스바를 추가하여 4개 제거합니다.
			for (int k = i + 1; k < v.size(); k++) v[k].second -= 4;
			var.push_back(v[i + 2].first);
		}

		else if (v[i].first == "}") { 
			// } 일 경우 해당 함수가 종료된 것이기 때문에 
			// var 를 적용합니다.
			var.clear(); // 적용 후 var 를 초기화함으로써 새로운 함수 내부에서 var 를 적용합니다.
			// 이렇게 하는 이유는 어느 함수에서 var 변수 생성시 이름이 a 일때
			// 다른 함수에서 그 변수를 이유없이 * 를 붙일 수 있기 때문에 
			// } 로 구분해서 초기화해줍니다.
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
		// 별을 추가해줍니다.
		s.erase(ex[k].second, ex[k].first.length());
		s.insert(ex[k].second, q);
		for (int z = k + 1; z < ex.size(); z++) ex[z].second++;
		for (int z = index + 1; z < v.size(); z++) v[z].second++;
	}
}