#include<iostream>
using namespace std;
void main() {
	int i = 0; char a[100];
	cin >> a;
	while (a[i++] != '\0');
	cout << --i;
}
