#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
string name, condition;
int main(){
    int n;
    cin >> n;
    map<string, int, greater<string>> m;
    for(int i = 0; i < n; i++){
        cin >> name >> condition;
        if(condition[0] == 'e'){
            m[name] = 1;
        } else {
            m[name] = 0;
        }
    }

    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        if((*iter).second == 1)
            cout << (*iter).first << '\n'; // endl로 하면 시간초과 난다....
}
