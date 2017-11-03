#include <iostream>
using namespace std;
double m[1001];
int main() {
	int C, N;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> m[i];
			sum += m[i];
		}
		int avg = (sum) / N;
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (m[i] > avg) count++;
		}
		printf("%.3f", (double)count / N * 100);
		cout << "%" << endl; //.....
	}
}
