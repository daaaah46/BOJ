#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}


//////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
    int x, y;
};
bool cmp(const Point &a, const Point &b){
    if(a.x < b.x) return true;
    else if (a.x == b.x){
        if(a.y < b.y){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<Point> a(n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++){
        printf("%d %d\n", a[i].x, a[i].y);
    }
}
