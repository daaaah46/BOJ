#include<iostream>
#include<string>
using namespace std;
int main() {
	string n,v;
	cin >> n;
	if (n.size()%3 == 1) {
		n = "00" + n;
	}
	else if (n.size()%3 == 2) {
		n = "0" + n;
	}
	for (int i = 0; i<n.size(); i += 3) {
		int a = (((n[i] - '0') * 4) + ((n[i + 1] - '0') * 2) + ((n[i + 2] - '0') * 1));
		cout << a;
	}
	cout << endl;
}
