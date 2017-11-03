#include <iostream>
using namespace std;
double m[1001];
int main() {
	int n, tmp = -1, sum = 0;
	cin >> n;
	while (tmp != n) {
		sum++;
		int pone, ptwo, ntwo, t;
		if (sum == 1) tmp = n;
		pone = tmp / 10;
		ptwo = tmp % 10;
		t = pone + ptwo;
		if (t >= 10) {
			ntwo = t % 10;
		}
		else {
			ntwo = t;
		}
		tmp = ptwo * 10 + ntwo;
	}
	cout << sum << endl;
}
