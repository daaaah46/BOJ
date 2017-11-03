#include <iostream>
using namespace std;
int main() {
	int m[3];
	cin >> m[0] >> m[1] >> m[2];
	//Selection Sort
	for (int i = 0; i < 2; i++) {
		int tmp = i;
		for (int j = i + 1; j < 3; j++) {
			if (m[j] <= m[tmp]) tmp = j;
		}
		swap(m[i], m[tmp]);
	}
	cout << m[1] << endl;
}
