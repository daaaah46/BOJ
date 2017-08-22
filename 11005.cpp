#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	long N;
	int B;
	string value;
	cin >> N >> B;
	while (N > 0) {
		int n = N % B;
		char ch;
		if (n >= 10) {
			ch = (n - 10) + 'A';
		}
		else {
			ch = n + '0';
		}
		N = N / B;
		value += ch;
	}
	reverse(value.begin(), value.end());
	cout << value << endl;
}
