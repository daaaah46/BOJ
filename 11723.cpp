#include <stdio.h>
using namespace std;
int main() {
	int m, num;
	int s = 0;
	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		char str[10];
		scanf("%s", str);
		if(str[0] == 'a' && str[1] == 'l')
			s = (1 << 20) - 1;
		else if (str[1]== 'm')
			s = 0;
		else{
			scanf("%d", &num);
			if(str[1] == 'd') s |= (1 << --num);
			else if(str[1] == 'e') s &= (~(1 << --num));
			else if (str[1] == 'h') {
				if (s & (1 << --num)) {
					printf("1\n");
				}
				else {
					printf("0\n");
				}
			}
			else {
				s ^= (1 << --num);
			}
		}
	}
}
