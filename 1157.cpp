#include <iostream>
#include <string>
using namespace std;
int m[26];
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		char ch = str.at(i);
		if (ch >= 'A' && ch <= 'Z') {
			m[ch - 'A']++;
		}
		else if (ch >= 'a' && ch <= 'z') {
			m[ch - 'a']++;
		}
	}

	bool flag = false;
	int max = 0;
	int mindex = 0;
	for (int i = 0; i < 26; i++) {
		if (max < m[i]) {
			max = m[i];
			mindex = i;
			flag = false;
		}
		else if (max == m[i]) {
			flag = true;
		}
	}

	if (flag) {
		cout << "?" << endl;
	}
	else {
		cout << (char)(mindex + 'A') << endl;
	}
}
