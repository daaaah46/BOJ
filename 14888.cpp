#include <iostream>
using namespace std;
int op[4]; // 0: + , 1: -, 2: *, 3: /
int num[11];
int mx = -1000000000, mn = 1000000000; // 설정할 때 잘해줘야 된다. 아니면 틀림
int n;
void dfs(int idx, int val){
    if(idx == n){
        if(mx < val){
            mx = val;
        }
        if(mn > val){
            mn = val;
        }
        return;
    }
    
    if(op[0] > 0){
        op[0]--;
        dfs(idx + 1, val + num[idx]);
        op[0]++; // 갔다 왔으니... 다시 돌려줘야지
    }
    if(op[1] > 0){
        op[1]--;
        dfs(idx + 1, val - num[idx]);
        op[1]++; // 갔다 왔으니... 다시 돌려줘야지
    }
    if(op[2] > 0){
        op[2]--;
        dfs(idx + 1, val * num[idx]);
        op[2]++; // 갔다 왔으니... 다시 돌려줘야지
    }
    if(op[3] > 0){
        op[3]--;
        dfs(idx + 1, val / num[idx]);
        op[3]++; // 갔다 왔으니... 다시 돌려줘야지
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    
    for(int i = 0; i < 4; i++){
        scanf("%d", &op[i]);
    }

    dfs(1, num[0]);
    cout << mx << endl;
    cout << mn << endl;
    return 0;
}
