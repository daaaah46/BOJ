#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	set<string> s;
	set<string>::reverse_iterator it;
	string str, name;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> str;
		if (str == "enter") { //enter인 경우
			s.insert(name);
		}
		else {	//leave인 경우
			s.erase(name);
		}
	}
	for (it = s.rbegin(); it !=s.rend(); it++)	{
		cout << *it << endl;
	}
}
