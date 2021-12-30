#include <stdio.h>
#include <algorithm>

using namespace std;



int main() {
    int n1, n2, m1, m2, t;
    scanf("%d %d %d %d", &n1, &n2, &m1, &m2);
    
    if(n1 > n2) swap(n1, n2);
    if(m1 > m2) swap(m1, m2);
    
    for(int i = n1; i <= n2; i++) {
        if((i == m1 || i == m2) && n2 < m2) {
            printf("cross");
            return 0;
        }
    }
    
    for(int i = m1; i <= m2; i++) {
        if((i == n1 || i == n2) && m2 < n2) {
            printf("cross");
            return 0;
        }
    }
    printf("not cross");
}