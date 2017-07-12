#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	int i = 0;
	while(getline(cin, str)) {
		int a[4] = { 0,0,0,0 };
		while (str[i] != '\0') {
			if (str[i] >= 'a' && str[i] <= 'z') { a[0]++; }
			else if (str[i] >= 'A' && str[i] <= 'Z') { a[1]++;}
			else if (str[i] >= '0' && str[i] <= '9') { a[2]++;}
			else if (str[i] == ' ') { a[3]++;}
			i++;
		}
		for (int j = 0; j < 4;j++) cout << a[j] << ' ';
		cout << endl;
		i = 0;
	}
}
