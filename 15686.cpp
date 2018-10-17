#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int m[51][51];
bool selchick[14]; // 0은 폐업, 1은 안폐업
vector<pair<int, int>> house;
vector<pair<int, int>> chick;
vector<int> value;

int shdown(){
    vector<int> v;
    int sum = 0;
    // 각 집에서 치킨집 까지의 최솟값
    for(int i = 0; i < house.size(); i++){
        int housex = house.at(i).first; int housey = house.at(i).second;
        int minvalue = 123456789;
        for(int j = 0; j < chick.size(); j++){
            if(selchick[j]){
                int chickx = chick.at(j).first; int chicky = chick.at(j).second;
                minvalue = min(minvalue, (abs(chickx - housex) + abs(chicky - housey)));
            }
        }
        v.push_back(minvalue);
    }
    
    for(int i = 0; i < v.size(); i++){
        sum += v.at(i);
    }
    return sum;
}

void selectchicken(int idx, int count){
    selchick[idx] = true;
    if(count == M){
        return;
    }
    
    // 골랐으니 실행을 시켜보자
    value.push_back(shdown());
    
    for(int i = idx + 1; i < chick.size(); i++){
        selectchicken(i, count + 1);
        selchick[i] = false;
    }
    selchick[idx] = false;
}


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int d;
            scanf("%d", &d);
            if(d == 1) { house.push_back(make_pair(i, j)); }
            if(d == 2) { chick.push_back(make_pair(i, j)); }
            m[i][j] = d;
        }
    }
    
    for(int i = 0; i < chick.size(); i++){
        selectchicken(i, 0);
    }
    sort(value.begin(), value.end());
    cout << value.at(0) << endl;
}
