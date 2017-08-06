#include<iostream>
#include<string>
using namespace std;
int main() {
	int n, sum, num;
	string str;
	cin >> n;
	while (n-- > 0) {
		cin >> str;
		sum = 0, num = 0;
		for (int i = 0; i < str.length(); i++) {
			char ch = str.at(i);
			if (ch == 'O') {
				sum += ++num;
			}
			else if (ch=='X'){
				num = 0;
			}
		}
		cout << sum << endl;
	}
}
