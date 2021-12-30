#include <bits/stdc++.h>
using namespace std;

char str[600001];

int main() {
    stack<char> fronttext, backtext;
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        fronttext.push(str[i]);
        str[i] = 0;
    }

    int n;
    char ch, addch;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %c", &ch);
        if(ch == 'L') {
            if(fronttext.empty()) continue;
            backtext.push(fronttext.top());
            fronttext.pop();
        }
        else if(ch == 'D') {
            if(backtext.empty()) continue;
            fronttext.push(backtext.top());
            backtext.pop();
        }
        else if(ch == 'B') {
            if(fronttext.empty()) continue;
            fronttext.pop();
        }
        else if(ch == 'P') {
            scanf(" %c", &addch);
            fronttext.push(addch);
        }
    }
    int frontsize = fronttext.size(), backsize = backtext.size();
    for(int i = frontsize-1; i >= 0; i--) {
        str[i] = fronttext.top();
        fronttext.pop();
    }
    for(int i = frontsize; i < frontsize+backsize; i++) {
        str[i] = backtext.top();
        backtext.pop();
    }
    printf("%s", str);
}
