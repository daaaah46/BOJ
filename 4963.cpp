#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[51][51];
bool visit[51][51];
int xd[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int yd[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int w, h;
vector<int> v;
void bfs(int i, int j){
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int xrot = x + xd[i];
            int yrot = y + yd[i];
            if(xrot >= 0 && xrot < h && yrot >= 0 && yrot < w){
                if(map[xrot][yrot] == 1 && !visit[xrot][yrot]){
                    visit[xrot][yrot] = true;
                    q.push(make_pair(xrot, yrot));
                }
            }
        }
    }
}

int main(){
    while(true){
        scanf("%d %d", &w, &h);
        
        if(w == 0 && h == 0)
            break;
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                scanf("%d", &map[i][j]);
                visit[i][j] = false;
            }
        }
        
        int g = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] == 1 && visit[i][j] == false){
                    bfs(i, j);
                    g++;
                }
            }
        }
        cout << g << endl;
    }
}
