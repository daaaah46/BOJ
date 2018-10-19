// 백트래킹 써서 시간 초과는 안났으나... 그냥 백트래킹은 알고리즘 자체를 외우는 게 좋은 듯 하다.
#include <iostream>
using namespace std;
int N, M, H;
int m[31][11]; // 이 부분을 놓쳐서 계속 틀렸다고 나옴... 바보
int minimum = 123456789;
bool isladder(int i, int j){
    if(m[i][j] == 1){ // 현재 위치에 사다리가 있다면 놓을 수 없음
        return false;
    }else if(m[i][j] == 0){
        if(m[i][j-1] == 1 || m[i][j+1] == 1){ // 오른쪽, 왼쪽 검사해서 사다리 있으면 안됨
            return false;
        }
    }
    return true;
}

// 사다리 타기
bool cal(){
    for(int l = 1; l <= N; l++){
        int j = l;
        for(int i = 1; i <= H; i++ ){
            if(m[i][j] == 1){ // 현재 위치에서 오른쪽으로 이동할 수 있다.
                j = j + 1; // 오른쪽으로 이동
            }else if(m[i][j-1] == 1){ // 오른쪽으로 이동할 수 없기 때문에 왼쪽으로 이동할 수 있는 지 본다.
                j = j - 1; // 왼쪽으로 이동
            }
        }
        // 사다리의 결과는 j가 가지고 있다.
        if(l == j){
            continue;
        }else {
            return false;
        }
    }
    return true;
}

void dfs(int x, int y, int count){
    if(cal()){
        if(minimum > count){
            minimum = count;
        }
    }
    
    if(count == 3){
        return;
    }

    for(int i = x; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(isladder(i, j)){
                m[i][j] = 1;
                dfs(i, j, count + 1);
                m[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        m[x][y] = 1;
    }
    
    dfs(1, 1, 0);
    if(minimum > 3){
        cout << -1 << endl;
    }else{
        cout << minimum << endl;
    }
}
