#include <bits/stdc++.h>
using namespace std;

int main() {
    int k[27]; /// -96
    char ch[101];
    scanf("%s", ch);
    int len = strlen(ch);
    for(int i = 0; i < 27; i++) k[i] = -1;
    for(int i = 0; i < len; i++) {
        if(k[ch[i]-96] == -1) {
            k[ch[i]-96] = i;
        }
    }
    for(int i = 1; i <= 26; i++) printf("%d ", k[i]);
}
