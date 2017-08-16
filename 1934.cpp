#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int n1, int n2) {
	int m = min(n1, n2);
	int g = 1;
	for (int i = 1; i <= m; i++) {
		if (n1%i == 0 && n2%i == 0) {
			g = i;
		}
	}
	return g;
}
int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n1, n2, g;
		cin >> n1 >> n2;
		g = gcd(n1, n2);
		cout << g * (n1 / g) * (n2 / g) << endl;
	}
}
