// 작년에는 마지막 테케에서 실패했는데, 이번엔 맞았다. 작년보다 알고리즘 실력이 늘은 것 같다..굿
#include <iostream>
using namespace std;
int map[51][51]; // 0은 미청소, 1은 벽, 2는 청소한 곳
int N, M;
int xd[4] = {-1, 0, 1, 0};
int yd[4] = {0, 1, 0, -1};
int main(){
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    int x = r, y = c;
    while(true){ // 조건절 명시!!!!
        map[x][y] = 2; //현재 위치를 청소한다.
        bool flag = false; // 네 방향 중 어디론가 움직일 수 있나?
        for(int i = 0; i < 4; i++){ // 왼쪽부터 한 방향씩 탐색한다.
            d = (d + 3) % 4;
            int xrot = x + xd[d];
            int yrot = y + yd[d];
            if(map[xrot][yrot] == 0){ // 0 이면 다음으로 가면 되니까!!!
                x = xrot;
                y = yrot;
                flag = true;
                break;
            }
        }
        
        if(!flag){ // 네 방향이 모두 청소가 되어있는 경우?
            // 바라보는 방향을 유지한 채로 뒤로 간다.
            int direct = (d + 2) % 4; // 반대 방향을 찾아냄
            int xrot = x + xd[direct];
            int yrot = y + yd[direct];
            if(map[xrot][yrot] == 1){ // 후진 조차 되지 않음
                break;
            }else {
                x = xrot;// 이동
                y = yrot;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 2){
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}
