#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int check[1001][1001];
int xd[] = {0, -1, 0, 1};
int yd[] = {1, 0, -1, 0};
int m, n;
void bfs(int i, int j) {
	queue< pair<int, int> > q;
	int d = 0;
	check[i][j] = d;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int dx = x + xd[i], dy = y + yd[i];
			if ((dx > -1 && dx < m) && (dy > -1 && dy < n)) {
				if (map[dx][dy] == 0 && (check[dx][dy] == -1 || check[dx][dy] > check[x][y]+1)) { //중요
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
	for(int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			check[i][j] = -1;
		}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (map[i][j] == 1 && check[i][j] == -1) {
				bfs(i, j);
			}
		}
	}

	bool ok = true;
	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == -1 && map[i][j] == 0) ok = false;
			if (check[i][j] > max) max = check[i][j];
		}
	}

	if (ok) {
		cout << max << endl;
	}
	else {
		cout << -1 << endl;
	}
}
