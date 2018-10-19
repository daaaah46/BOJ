#include <iostream>
using namespace std;
long long m[1000001];
int main(){
    long long N, B, C;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long ai;
        cin >> ai;
        m[i] = ai;
    }
    
    cin >> B >> C;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        m[i] -= B;
        ans++;
        if(m[i] > 0) ans += m[i] / C;
        if(m[i] % C > 0) ans++;
    }
    cout << ans << endl;
}
