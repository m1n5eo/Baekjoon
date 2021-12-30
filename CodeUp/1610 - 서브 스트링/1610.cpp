#include <bits/stdc++.h>
using namespace std;

char mysubstr(char *str, int start, int count) {
    return str[count];
}

int main() {
    int start, len;
    char str[100];
    scanf("%s", str);
    scanf("%d %d", &start, &len);
    for(int i = start; i < start+len; i++) {
        printf("%c", mysubstr(str, start, i));
    }
}