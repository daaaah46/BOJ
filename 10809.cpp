#include<iostream>
using namespace std;
void main() {
	char str[100];
	int a[26] = {-1,-1,-1,-1,-1,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1}, i = 0;
	cin >> str;
	while (str[i] != '\0') {
		if (a[str[i] - 'a'] == -1) {a[str[i] - 'a'] = i++;}
		else { i++; continue; }
	}
	for (int i = 0; i < 26; i++) { cout << a[i] << ' '; }
}
