#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int map[51][51];
bool check[51][51] = { false };
int x_direct[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int y_direct[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int ans[50] = { 0 };

void bfs(int i, int j, int w, int h) {
	queue<pair<int, int>> q;
	check[i][j] = true;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		pair<int, int> v = q.front();
		int x = v.first;
		int y = v.second;
		for (int i = 0; i < 8; i++) {
			int xd = x + x_direct[i];
			int yd = y + y_direct[i];
			if ((xd > -1 && xd < h) && (yd > -1 && yd < w)) {
				if (map[xd][yd] == 1 && check[xd][yd] == false) {
					check[xd][yd] = true;
					q.push(make_pair(xd, yd));
				}
			}
		}
		q.pop();
	}
}

int main() {
	int w = -1, h = -1, m, sum=0, i=0;
	while (true) {
		cin >> w >> h;
		
		if (w == 0 && h == 0) break; //반복문 빠져나갈 조건

		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		sum = 0;
		
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++) {
				cin >> m;
				map[i][j] = m;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					bfs(i, j, w, h);
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
}
