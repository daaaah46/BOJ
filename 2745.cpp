#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	string N;
	long B, sum = 0;
	cin >> N >> B;
	for (int i = 0; i < N.length(); i++) {
		char ch = N.at(i);
		int n;
		if (ch >= '0' && ch <='9') {
			n = (int)(ch - '0');
		}
		else {
			n = (int)(ch - 'A') + 10;
		}
		sum = sum * B + n;
	}
	cout << sum << endl;
}
