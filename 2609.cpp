#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int n1, int n2) {
	int g;
	int m = min(n1, n2); //두 수 중 작은 수 이상으로는 더이상 연산할 필요 X
	for (int i = 1; i <= m; i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			g = i;
		}
	}
	return g;
}

int lcm(int n1, int n2,int gcd) {
	return gcd * (n1 / gcd) * (n2 / gcd);
}

int main() {
	int n1, n2, g;
	cin >> n1 >> n2;
	g = gcd(n1, n2);
	cout << g << endl;
	cout << lcm(n1, n2, g) << endl;
}
