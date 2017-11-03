#include <iostream>
#include <string>
using namespace std;
int MONTH[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string DAY[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
int main() {
	int m, d;
	cin >> m >> d;
	int v = 0;
	for (int i = 0; i < m-1; i++) {
		v += MONTH[i];
	}
	v += d;
	v = v % 7;
	cout << DAY[v] << endl;
}
