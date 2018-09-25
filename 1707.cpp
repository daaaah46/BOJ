#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[20001];
int check[20001];
void dfs(int v, int c){ // c = color
    check[v] = c;
    for(int i = 0; i < a[v].size(); i++){
        int next = a[v][i];
        if(check[next] == 0){
            dfs(next, 3-c);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int v, e;
        scanf("%d %d", &v, &e);
        
        for(int i = 1 ;i <= v; i++ ){
            a[i].clear();
            check[i] = 0;
        }
        
        for(int i = 0 ; i < e; i++){
            int u1, u2;
            scanf("%d %d", &u1, &u2);
            a[u1].push_back(u2);
            a[u2].push_back(u1);
        }
        
        for(int i = 1; i <= v; i++){
            if(check[i] == 0){
                dfs(i, 1);
            }
        }
        
        bool flag = true;
        for(int i = 1; i <= v; i++){
            for(int j = 0; j < a[i].size(); j++){
                if(check[a[i][j]] == check[i]){
                    flag = false;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
