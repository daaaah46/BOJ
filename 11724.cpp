#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int v){
    check[v] = true;
    for(int i = 0; i < a[v].size(); i++){
        int next = a[v][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    
    for(int i = 0;i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(check[i] == false){
            count++;
            dfs(i);
        }
    }
    cout << count << endl;
}
