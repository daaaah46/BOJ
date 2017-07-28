#include <iostream>
using namespace std;
int main() {
	int n, sum=0;
	char m[101];
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		int n = (int)(m[i] - '0');
		sum += n;
	}
	cout << sum << endl;
}
