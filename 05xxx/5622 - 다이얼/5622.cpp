#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch[22], dial[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    scanf("%s", ch);
    int len = strlen(ch), second = 0;
    for(int i = 0; i < len; i++) {
        second += dial[ch[i]-65];
    }
    printf("%d", second);
}
