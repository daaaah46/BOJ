#include <iostream>
#include <string>
using namespace std;
string str[3] = { "ascending", "descending", "mixed" };
int main() {
	int a[8];
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
	
	int s = -1;
	for (int i = 0; i < 7; i++) {
		int n = a[i] - a[i + 1];
		switch (s){
		case 0:
			if (n > 0) {
				s = 2;
			}
			break;
		case 1:
			if (n < 0) {
				s = 2;
			}
			break;
		case 2:
			break;
		default:
			if (n < 0) {
				s = 0;
			}
			else {
				s = 1;
			}
			break;
		}
	}
	cout << str[s] << endl;
}
