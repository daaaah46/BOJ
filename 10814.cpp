#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
    int age;
    string name;
};

bool cmp (const Person & a, const Person &b){
    return a.age < b.age;
}

int main(){
    int n;
    scanf("%d", &n);
    
    vector<Person> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].age >> a[i].name;
    }
    stable_sort(a.begin(),a.end(), cmp);
    
    for(int i = 0; i < n; i++){
        cout << a[i].age << ' ' << a[i].name << endl;
    }
}
