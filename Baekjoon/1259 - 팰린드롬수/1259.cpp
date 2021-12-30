#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, numSave, numReverse = 0;
    scanf("%d", &num);
    while(num != 0) {
        numSave = num;
        while(num != 0) {
            numReverse = numReverse*10+num%10;
            num /= 10;
        }
        if(numSave == numReverse) printf("yes\n");
        else printf("no\n");
        scanf("%d", &num);
        numReverse = 0;
    }
}
