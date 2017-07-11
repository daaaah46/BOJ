#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string str) {
	stack<char> s;
	int i;
	for (i = 0; i<str.length(); i++) {
		if (str.at(i) == '(') {
			s.push(str.at(i));
		}
		if (str.at(i) == ')') {
			if (s.size() > 0) {
				s.pop();
			}
			else {
				break;
			}
		}
	}
	if (s.size() == 0 & i == str.length()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int num;
	cin >> num;
	while (num-->0) {
		string str;
		cin >> str;
		if (isValid(str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
