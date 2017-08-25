#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >> n;
	while (n.size() % 3) {
		n = "0" + n;
	}
	for (int i = 0; i<n.size(); i += 3) {
		cout <<(((n[i] - '0') * 4) + ((n[i + 1] - '0') * 2) + ((n[i + 2] - '0') * 1));
	}
	cout << endl;
}
