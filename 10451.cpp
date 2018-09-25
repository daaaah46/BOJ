#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001];
bool check[1001];
void dfs(int v){ // c = color
    check[v] = true; //check = true;
    if(check[a[v]] == false){
        dfs(a[v]);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            check[i] = false;
        }
        
        for(int i = 1; i <= n; i++){
            int k;
            scanf("%d", &k);
            a[i] = k;
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
}
