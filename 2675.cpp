#include <iostream>
#include <string>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			char a = str.at(i);
			for (int i = 0; i < n; i++) {
				cout << a;
			}
		}
		cout << endl;
	}
}
