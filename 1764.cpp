#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	set<string> s1,s2;
	set<string>::iterator it;
	int N, M;
	string name;
	cin >> N >> M;
	//듣도 못한 사람 입력
	for (int i = 0; i < (N); i++) {
		cin >> name;
		s1.insert(name);
	}
	//듣도 못한 사람에 있다면 s2에 입력
	for (int i = 0; i < M; i++){
		cin >> name;
		it = s1.find(name);
		if (it != s1.end())
			s2.insert(name);
	}
	cout << s2.size() << endl;
	for (it = s2.begin(); it != s2.end(); it++) {
		cout << *it << endl;
	}
}
