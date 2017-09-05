#include <stdio.h>
#include <algorithm>
using namespace std;
int m[1000001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &m[i]);
	sort(m, m + n);
	for (int i = 0; i < n; i++)
		printf("%d\n", m[i]);
}
