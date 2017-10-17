/*
	이것이 진정한 막코딩 ㅎ....
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int originmap[9][9];
int map[9][9];
int bfsmap[9][9];
bool visited[9][9];
bool wallvisited[9][9];
int xrot[4] = { 0,-1,0,1 };
int yrot[4] = { -1,0,1,0 };
int n, m;
int max_value = 0;
vector< pair <int, int> > virus;
void bfs() {
	queue< pair<int, int> > q;
	for (int i = 0; i < virus.size(); i++) {
		int x = virus.at(i).first;
		int y = virus.at(i).second;
		q.push(make_pair(x, y));
		
		while (!q.empty()) {
			int px = q.front().first;
			int py = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xd = px + xrot[i];
				int yd = py + yrot[i];
				if (xd < 1 || xd > n || yd < 1 || yd > m) continue;
				if (bfsmap[xd][yd] == 0) {
					bfsmap[xd][yd] = 2;
					q.push(make_pair(xd, yd));
				}
			}
		}
	}
}

void initmap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = originmap[i][j];
		}
	}
}

void countmax() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (bfsmap[i][j] == 0) count++;
		}
	}
	if (max_value < count) {
		max_value = count;
	}
}

void wallvisit() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			wallvisited[i][j] = false;
		}
	}
}

void copymap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bfsmap[i][j] = map[i][j];
		}
	}
}

void dfs(int x, int y,int s) {
	map[x][y] = 1;
	wallvisited[x][y] = true;

	if (s == 3) {
		copymap();
		bfs();
		countmax();
		map[x][y] = 0;
		wallvisited[x][y] = false;
		return;
	}

	for (int i = x; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0 && wallvisited[i][j] == false) {
				dfs(i, j, s+1);
			}
		}
	}
	map[x][y] = 0;
	wallvisited[x][y] = false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int v; 	cin >> v;
			map[i][j] = v;
			originmap[i][j] = v;
			if (v == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				dfs(i, j, 1);
			}
		}
	}
	cout << max_value << endl;
}
