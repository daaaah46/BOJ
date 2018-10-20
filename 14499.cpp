// 이런문제는... 절레..
#include <iostream>
using namespace std;
int N, M;
int m[21][21];
int dice[7]; // 1 ~ 7
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main(){
    cin >> N >> M;
    int x, y, K;
    cin >> x >> y >> K;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int n;
            cin >> n;
            m[i][j] = n;
        }
    }
    
    for(int i = 0; i < K; i++){
        int n;
        cin >> n;
        int temp = dice[1];
        int xd = x + dx[n-1];
        int yd = y + dy[n-1];
        
        if(xd < 0 || xd >= N || yd < 0 || yd >= M){ // 범위 체크 잘하자..제발...
            continue;
        }
        
        switch (n) {
            case 1: // 동쪽
                dice[1] = dice[4];
                dice[4] = dice[6];
                dice[6] = dice[3];
                dice[3] = temp;
                break;
            case 2: // 서쪽
                dice[1] = dice[3];
                dice[3] = dice[6];
                dice[6] = dice[4];
                dice[4] = temp;
                break;
            case 3: // 북쪽
                dice[1] = dice[5];
                dice[5] = dice[6];
                dice[6] = dice[2];
                dice[2] = temp;
                break;
            case 4: // 남쪽
                dice[1] = dice[2];
                dice[2] = dice[6];
                dice[6] = dice[5];
                dice[5] = temp;
                break;
        }

        if(m[xd][yd] == 0){ // 0이면
            m[xd][yd] = dice[6];
        }else {
            dice[6] = m[xd][yd]; // 밑의 수 바꿔줌
            m[xd][yd] = 0;
        }
        
        cout << dice[1] << endl;
        x = xd;
        y = yd;
    }
}
