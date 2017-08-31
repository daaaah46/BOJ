#include <iostream>
using namespace std;
int main() {
	int n, s = 1;
	cin >> n;
	while (n > 0) {
		s = s * n;
		n--;
	}
	cout << s << endl;
}
