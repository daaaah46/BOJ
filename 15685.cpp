// 엉뚱한데서 삽질... x와 y 좌표 조심..ㅎ..
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n;
int xd[4] = {1, 0, -1, 0};
int yd[4] = {0, -1, 0, 1};
int m[101][101];
int main(){
    cin >> n;
     // x, y = 시작점, d = 시작방향, g = 세대
    while(n-- > 0){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> v;
        v.push_back(d);
        for(int i = 1; i <= g; i++){
            int l = v.size();
            for(int j = l - 1; j >= 0; j--){
                int s = (v.at(j) + 1) % 4;
                v.push_back(s);
            }
        }
        
        // 탐색 고고
        m[y][x] = 1;
        for(int i = 0; i < v.size(); i++){
            int rot = v.at(i);
            int xrot = x + xd[rot], yrot = y + yd[rot];
            m[yrot][xrot] = 1;
            x = xrot; y = yrot;
        }
        
        v.clear();
    }
    
    int value = 0;
    // 1인애들 모조리 검사
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(m[i][j] == 1){
                if(i + 1 > 101 || j + 1 > 101) continue;
                if(m[i+1][j] == 1 && m[i][j+1] == 1 && m[i+1][j+1] == 1){
                    value++;
                }
            }
        }
    }
    cout << value << endl;
}
