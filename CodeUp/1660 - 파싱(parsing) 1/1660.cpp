#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[111];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == ',') printf(" ");
        else printf("%c", str[i]);
    }
    printf(" ");
}