/* to_string...!! */
#include <iostream>
#include <string>
using namespace std;
int m[10] = { 0 };
int main() {
	int A, B, C;
	string str;
	cin >> A >> B >> C;
	long long num = A*B*C;
	str = to_string(num);
	for (int i = 0; i < str.length(); i++) {
		char ch = str.at(i);
		m[ch - '0']++;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << m[i] << endl;
	}
}
