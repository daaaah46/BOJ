#include <iostream>
#include <string>
using namespace std;
int main() {
	string oct[8] = { "000","001","010","011","100","101","110","111" };
	string s,v;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int a = s.at(i)-'0';
		v += oct[a];
	}
	int n = 0;
	if (s != "0") {
		while (v.at(n) == '0')
			n++;
		v = v.substr(n);
		cout << v << endl;
	}
	else {
		cout << "0" << endl;
	}
}
