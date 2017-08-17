#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long n1, long long n2) {
	long long a = n1, b = n2, r;
	while (b != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	long long A, B;
	cin >> A >> B;
	long long n = gcd(A, B);
	while (n-- > 0) {
		cout << "1";
	}
	cout << endl;
}
