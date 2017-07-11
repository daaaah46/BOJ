#include <iostream>
#include <string>
using namespace std;
class Queue {
	int q[10000], first, last;
public:
	Queue() {
		first = 0;
		last = 0;
	};
	
	void push(int number) {
		q[last++] = number;
	}

	int pop() {
		if (!empty()) {
			return q[first++];
		}
		else {
			return -1;
		}
	}

	int size() {
		return last-first;
	}

	int empty() {
		if (first == last) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int front() {
		if (!empty()) {
			return q[first];
		}
		else {
			return -1;
		}
	}

	int back() {
		if (!empty()) {
			return q[last-1];
		}
		else {
			return -1;
		}
	}
};

int main() {
	int n, number;
	string op;
	Queue q;
	cin >> n;
	while(n--){
		cin >> op;
		if (op == "push") {
			cin >> number;
			q.push(number);
		}
		else if (op == "pop") {
			cout << q.pop() << endl;
		}
		else if (op == "size") {
			cout << q.size() << endl;
		}
		else if (op == "empty") {
			if (q.empty() == 1) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (op == "front") {
			cout << q.front() << endl;
		}
		else if (op == "back") {
			cout << q.back() << endl;
		}
	}
}
