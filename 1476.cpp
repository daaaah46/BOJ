/* es */
#include <stdio.h>
int main(){
    int a[3];
    int E = 15, S = 28, M = 19, e = 1, s = 1, m = 1, v = 0;
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    
    for (int i = 1; i <= E * S * M; i++){
        if(a[0] == e && a[1] == s && a[2] == m){
            v = i;
            break;
        }
        e++; s++; m++;
        if (e > E) e = 1;
        if (s > S) s = 1;
        if (m > M) m = 1;
    }
    printf("%d\n" , v);
    return 0;
}
