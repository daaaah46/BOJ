#include <iostream>
using namespace std;
int main() {
	char str[101];
	cin >> str;
	int i = 0;
	while(str[i] != '\0') {
		cout << str[i];
		i++;
		if (i % 10 == 0) {
			cout << endl;
		}
	}
}
