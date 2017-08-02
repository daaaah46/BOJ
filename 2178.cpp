#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int n, m; // m : 가로, n : 세로
int map[101][101];
int check[101][101];
int xd[] = { 0, -1, 0, 1 };
int yd[] = { 1, 0, -1, 0 };
void bfs() {
	queue<pair<int, int>> q;
	check[0][0] = 1;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int dx = x + xd[i];
			int dy = y + yd[i];
			if (dx > -1 && dx <n && dy > -1 && dy < m) {
				if (map[dx][dy] == 1 && check[dx][dy] == 0) {
					check[dx][dy] = check[x][y] + 1;
					q.push(make_pair(dx, dy));
				}
			}
		}
		q.pop();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();

	cout << check[n - 1][m - 1] << endl;
}
