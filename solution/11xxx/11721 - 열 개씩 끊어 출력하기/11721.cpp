#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[111];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
        if(!((i+1)%10)) printf("\n");
    }
}
