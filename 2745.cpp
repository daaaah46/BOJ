#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	string N;
	long B, sum = 0;
	cin >> N >> B;
	for (int i = N.size()-1; i >= 0; i--) {
		char ch = N.at(i);
		int n;
		if (ch >= '0' && ch <='9') {
			n = (int)(ch - '0');
		}
		else {
			n = (int)(ch - 'A') + 10;
		}
		sum += pow(B, N.size()-i-1)*n;
	}
	cout << sum << endl;
}
