#include <iostream>
using namespace std;
int num[2];
int fibonacci(int n) {
	if (n == 0) {
		num[0]++;
	}
	else if (n == 1) {
		num[1]++;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		fibonacci(n);
		cout << num[0] << " " << num[1] << endl;
		num[0] = 0, num[1] = 0;
	}
}
