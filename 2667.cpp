#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[26][26];
int visit[26][26];
int xd[4] = {0, 0, 1, -1};
int yd[4] = {1, -1, 0, 0};
int n;
vector<int> v;
void bfs(int i, int j, int g){
    int gnum = 1;
    visit[i][j] = g;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xrot = x + xd[i];
            int yrot = y + yd[i];
            if(xrot >= 0 && xrot < n && yrot >= 0 && yrot < n){
                if(map[xrot][yrot] == 1 && !visit[xrot][yrot]){
                    visit[xrot][yrot] = g;
                    q.push(make_pair(xrot, yrot));
                    gnum++;
                }
            }
        }
    }
    
    v.push_back(gnum);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    int g = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                bfs(i, j, ++g);
            }
        }
    }
    cout << g << endl;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}
