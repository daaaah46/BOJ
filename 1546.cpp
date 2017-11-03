#include <iostream>
#include <algorithm>
using namespace std;
double m[1001];
int main() {
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}
	sort(m, m + M);
	double sum = 0;
	for (int i = 0; i < M ; i++) {
		sum +=  m[i] / m[M-1] * 100 ;
	}
	printf("%.2f", sum/M); // cout.precision은 어떻게 써야하지...?ㅠㅠ
}
