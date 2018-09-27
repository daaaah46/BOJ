#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
    string name;
    int korean;
    int english;
    int math;
};

bool cmp (const Person &a, const Person &b){
    if(a.korean > b.korean){
        return true;
    }else if(a.korean == b.korean){
        if(a.english < b.english) return true;
        else if (a.english == b.english){
            if(a.math > b.math) return true;
            else if (a.math == b.math){
                return a.name < b.name;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    
    vector<Person> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].korean >> a[i].english >> a[i].math;
    }
    
    sort(a.begin(), a.end(), cmp);
    
    for(int i = 0; i < n; i++){
        cout << a[i].name << '\n'; // endl로 하면 시간초과 뜸
    }
    return 0;
}
