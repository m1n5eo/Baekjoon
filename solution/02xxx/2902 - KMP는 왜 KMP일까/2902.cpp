#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[111];
    scanf("%s", str);
    int len = strlen(str);
    printf("%c", str[0]);
    for(int i = 1; i < len; i++) {
        if(str[i] == '-') printf("%c", str[i+1]);
    }
}
