/* es01 좀 헷갈림 ㅠㅠ*/
#include <stdio.h>
bool broken[10]; // 0 ~ 9
// 누르려고 하는 숫자에 망가진 버튼이 없어야 한다. 리턴값은 눌러야 하는 숫자의 갯수 = 길이 리턴
int possible(int n){
    int len = 0;
    // 0의 경우 판단이 불가능 하기 때문에, 따로 계산
    if(n == 0){
        if(broken[0]) return 0;
        else return 1;
    }
    // 각자리(뒤부터)를 돌면서 누를 수 있는 지 아닌지 본다.
    while (n > 0){
        if(broken[n % 10]) return 0;
        len += 1; // 만약에 망가져있지 않으면 자리수 추가!
        n /= 10; // 다음 자리 수를 본다.
    }
    return len;
}

int main(){
    int n = 0; //  이동하려는 채널
    int m = 0; // 고장난 버튼의 갯수
    
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        broken[x] = true;
    }
    
    // 100 근처의 수라면, +나 -를 눌러서 이동하는 게 더 빠를 수도 있다. 그러니까 일단 차이 값 계산
    int ans = n - 100;
    if (ans < 0) ans = -ans;
    
    // 이동할 채널 c를 정한다
    for(int i = 0; i <= 1000000 ; i++){
        int c = i; //현재 채널
        int len = possible(c);
        // 만약 len의 값이 0이라면, 더이상 누를 수 있는 숫자가 없는 것이기 때문에 0보다 큰 경우에만 계산한다.
        if (len > 0){
            int press = c - n; // 이 경우에는 숫자를 누르지 않고 +나 -를 눌러서 갈 수 있는 경우이다
            if (press < 0) {
                press = -press; // 현재 값이 더 큰 것이기 때문에 +를 눌러서 가는 경우
            }
            if (ans > len + press){
                ans = len + press;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
