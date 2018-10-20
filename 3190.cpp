#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int N, K, L;
int m[102][102];
int xd[4] = {0, 1, 0, -1};
int yd[4] = {1, 0, -1, 0};
// 끝남 판별
deque<pair<int, int>> dq; // 뱀 몸통 좌표
vector<pair<int, char>> v;
int main(){
    cin >> N;
    cin >> K;
    
    for(int i = 0; i < K; i++){ // 1부터 받음을 잊지마라
        int row, col;
        cin >> row >> col;
        m[row][col] = 1;
    }
    
    cin >> L;
    for(int i = 0; i < L; i++){
        int time;
        char d;
        cin >> time >> d;
        v.push_back(make_pair(time, d));
    }
    
    int T = 0;
    int dir = 0; // 시작은 오른쪽!
    dq.push_back(make_pair(1, 1));
    int vec_idx = 0;
    while(true){
        pair<int, int> snake = dq.front(); // 뱀의 머리를 가꼬온다.
        int x = snake.first; int y = snake.second;
        int xnext = x + xd[dir];
        int ynext = y + yd[dir];
        T++;

        if(xnext < 1 || xnext > N || ynext < 1 || ynext > N) {
            break;
        }
        // 만약에 몸통 중에 한 군데랑 만나버린다면 나간다.
        bool flag = false;
        for(int i = 0; i < dq.size(); i++){
            pair<int, int> cursnake = dq.at(i);
            if(cursnake.first == xnext && cursnake.second == ynext){ // 만약에 만난다?
                flag = true;
            }
        }
        
        if(flag){
            break;
        }

        if(m[xnext][ynext] == 1){ // 사과가 있으면 덱에 넣는다.
            m[xnext][ynext] = 0; // 사과 먹었으니 없애야지
        }else if(m[xnext][ynext] == 0){
            dq.pop_back(); // 사과 없으면 꼬리자르기
        }
        // 머리를 진행하자
        dq.push_front(make_pair(xnext, ynext));
        
        // 다음 타임? 이번 타임?에 움직인다면 dir을 바꿔줘야겠찌..? => 나머지 연산자 잊지마
        if(vec_idx < L && v[vec_idx].first == T){
            char dchar = v[vec_idx].second;
            if(dchar == 'D'){
                dir = (dir + 1) % 4;
            }else if(dchar == 'L'){
                dir = (dir + 3) % 4; // 진짜 멍청이 같았던게.. 이 부분 처리를 마이너스를 해서 틀림... 바보냐
            }
            vec_idx++;
        }

    }
    cout << T << endl;
}
