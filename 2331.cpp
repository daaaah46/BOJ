#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int m[10000];

int createnext(int s,int p) {
	int num, tnum;
	num = 0, tnum = 1;
	string n = to_string(s);
	for (int i = 0; i<n.length(); i++) {
		int v = (int)(n.at(i) - '0');
		tnum = 1;
		for (int j = 0; j < p; j++) {
			tnum *= v;
		}
		num = num + tnum;
	}
	return num;
}

int main() {
	int p, index=-1, i=0;
	string n;
	cin >> n >> p;
	m[0] = atoi(n.c_str());
	while(true){
		int next = createnext(m[i++], p);
		m[i] = next;
		for (int j = 0; j < i; j++) {
			if (m[j] == next){
				index = j;
				break;
			}
		}
		if (index != -1)
			break;
	}
	cout << index << endl;
}
