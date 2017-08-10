#include<iostream>
using namespace std;
int d[100001];
int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	while (n-- > 0) {
		int m;
		cin >> m;
		for (int i = 4; i <= m; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[m] << endl;
	}
}
