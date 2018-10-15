#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m[21][21];
bool team[21]; // 스타트 팀인 경우는 true, 링크 팀인 경우 false
int n;
vector<int> v;
void cal(){
    int startsum = 0;
    int linksum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(team[i] == true && team[j] == true){
               startsum += m[i][j];
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(team[i] == false && team[j] == false){
                linksum += m[i][j];
            }
        }
    }
    v.push_back(abs(startsum - linksum));
}

void dfs(int start, int count){
    team[start] = true;
    if(count == n / 2) { // 반만 돌려도 ok
        cal();
        return;
    }
    
    for(int i = start + 1; i < n; i++){
        if(!team[i]){
            dfs(i, count + 1);
            team[i] = false;
        }
    }
    team[start] = false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++){
        dfs(i, 1);
    }
    
    sort(v.begin(), v.end());
    cout << v.at(0) << endl;
}
