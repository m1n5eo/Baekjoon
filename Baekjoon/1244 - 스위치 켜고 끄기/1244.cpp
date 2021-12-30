#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, switchValue[111], student, gen, num;
    int startnum, endnum;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &switchValue[i]);
    scanf("%d", &student);
    for(int i = 0; i < student; i++) {
        scanf("%d %d", &gen, &num);
        if(gen == 1) {          // 남학생
            for(int i = num; i <= n; i+=num) switchValue[i] = 1-switchValue[i];
        }
        else if(gen == 2) {     // 여학생
            startnum = num, endnum = num;
            while(startnum != 1 && endnum != n) {
                if(switchValue[startnum-1] != switchValue[endnum+1]) break;
                startnum--; endnum++;
            }
            for(int k = startnum; k <= endnum; k++) switchValue[k] = 1-switchValue[k];
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", switchValue[i]);
        if(!(i%20)) printf("\n");
    }
}
