#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int map[25][25]; // 지도
bool check[25][25] = { false };  // 방문한 것을 담을 배열 1 : 방문, 0 : 방문X
int x_direct[4] = {0,-1,0,1};
int y_direct[4] = { -1,0,1,0};
int g_num = 0; //단지 갯수
int n;
vector<int> v;
void bfs(int i, int j) {
	int h_num = 1; // 집 갯수
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	while (!q.empty()) {
		pair<int, int> v = q.front();
		//cout << v.first << ',' << v.second << endl;
		int x = v.first;
		int y = v.second;
		for (int i = 0; i < 4; i++) {
			int xd = x + x_direct[i];
			int yd = y+ y_direct[i];
			if((xd < n && xd >-1) && yd <n && yd > -1)
				if (map[xd][yd] == 1 && check[xd][yd] == false) {
					q.push(make_pair(xd, yd));
					check[xd][yd] = true;
					h_num++;
				}
		}
		q.pop();
	}
	v.push_back(h_num);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				bfs(i, j);
				g_num++;
			}
		}
	}
	
	cout << g_num << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
