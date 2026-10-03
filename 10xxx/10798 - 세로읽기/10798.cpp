#include <bits/stdc++.h>
using namespace std;

int len[5];
char ch[5][22];

int main() {
    for(int i = 0; i < 5; i++) {
        scanf("%s", &ch[i]);
        len[i] = strlen(ch[i]);
    }

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 5; j++) {
            if(ch[j][i] != NULL) printf("%c", ch[j][i]);
        }
    }
}
