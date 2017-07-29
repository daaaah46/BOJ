/* 
  자바로 구현한 코드 다시 C++로 작성
*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool check[1001] = { false };
bool graph[1001][1001] = { false } ;
//인접행렬
void dfs(int n) {
	check[n] = true;
	cout << n << " ";
	for (int i = 1; i < sizeof(graph[n]); i++) {
		if (graph[n][i] && check[i] == false)
			dfs(i);
	}
}

void bfs(int n) {
	memset(check, false, sizeof(check));
	queue<int> q;
	q.push(n);
	check[n] = true;
	while (!q.empty()) {
		int v = q.front();
		cout << v << " ";
		for (int i = 0; i < sizeof(graph[v]); i++) {
			if (graph[v][i] && check[i] == false) {
				q.push(i);
				check[i] = true; //중요!
			}
		}
		q.pop();
	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	//인접행렬
	for (int i = 0; i < m; i++) {
		int v,e;
		cin >> v >> e;
		graph[v][e] = graph[e][v] = true;
	}
	dfs(start);
	cout << endl;
	bfs(start);
	cout << endl;
}
