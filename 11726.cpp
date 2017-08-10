#include<iostream>
using namespace std;
int d[1001];
int main() {
	int n;
	cin >> n;
	d[1] = 1, d[2] = 2;
	for (int i = 3; i <= n; i++) {
		int v = d[i - 1] + d[i - 2];
		d[i] = v % 10007;
	}
	cout << d[n] << endl;
}
