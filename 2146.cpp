#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<queue>
using namespace std;
int map[101][101];
int check[101][101];
int dist[101][101];
int xr[] = { 0, -1, 0, 1 }; // x_rotation
int yr[] = { 1, 0, -1, 0 }; // y_rotation
int n, short_distance;
void group_bfs(int i, int j, int group) {
	queue<pair<int, int>> q;
	check[i][j] = group;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int xd = x + xr[i];
			int yd = y + yr[i];
			if (xd > -1 && xd < n && yd > -1 && yd < n){
				if (map[xd][yd] == 1 & check[xd][yd] == 0) {
					check[xd][yd] = group;
					q.push(make_pair(xd, yd));
				}
			}	
		}
		q.pop();
	}
}

void dist_bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int xd = x + xr[i], yd = y + yr[i];
			if (xd > -1 && xd < n && yd > -1 && yd < n) {
				if (dist[xd][yd] == -1) {
					dist[xd][yd] = dist[x][y] + 1;
					q.push(make_pair(xd, yd));
				}
			}
		}
		q.pop();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int group = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				group++;
				group_bfs(i, j, group);
			}
		}
	}

	short_distance = -1;
	for (int k = 1; k <= group; k++) {
		queue<pair<int,int>> q;
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(check[i][j] == k){ //해당 번째 그룹넘버일 경우
					q.push(make_pair(i, j));
					dist[i][j] = 0;
				}
			}
		}

		dist_bfs(q);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && check[i][j] != k) { //섬에 해당하는 값들 끼리 비교
					if (short_distance > dist[i][j] -1 || short_distance == -1) {
						short_distance = dist[i][j] -1 ;
					}
				}
			}
		}
	}
	cout << short_distance<< endl;
}
