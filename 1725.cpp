#include<iostream>
#include <stack>
using namespace std;
long h[100001];
int main() {
	int n, height=0, width=0,area=0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		while (!s.empty() && (h[s.top()] > h[i])) {
			height = h[s.top()];				
			s.pop();								
			if (s.empty()) {							
				width = i;						
			}
			else {
				width = (i-s.top()-1);//width = right-left+1, right = (i-1), left = s.top+1
			}
			int temparea = width * height;
			if (temparea > area) {
				area = temparea;
			}
		}
		s.push(i);	//넣는다.
	}

	int rightindex = s.top();
	while (!s.empty()) {
		width = rightindex - s.top() + 1;
		height = h[s.top()]; 
		int temparea = width * height;
		if (temparea > area) {
			area = temparea;
		}
		s.pop();
	}
	cout << area << endl;
}
